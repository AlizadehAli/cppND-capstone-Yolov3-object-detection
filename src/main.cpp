// help is taken from:
// https://github.com/opencv/opencv/blob/master/samples/dnn/object_detection.cpp
#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>

#include "buffer.h"
#include "input.h"
#include "object_detector.h"
#include "output.h"

const cv::String keys =
    "{help h usage ? | | Usage examples: \n\t\t./object_etector --image=../input_data/img.jpg}"
    "{input i        |<none>| Input image. }";

Buffer<cv::Mat> frame_buffer;
std::string image_out = "../det_output/out.jpg";
std::string config_path{"../weights/yolov3.cfg"};
std::string weights_path{"../weights/yolov3.weights"};
std::string classes_path{"../weights/coco.names"};

int main(int argc, char **argv)
{
        
    cv::CommandLineParser parser(argc, argv, keys);
    parser.about("Use this script to run object detection using OpenCV.");

    if (parser.has("help")) 
    {
        parser.printMessage();
        return 0;
    }

    if (parser.has("input")) 
    {
        std::string input = parser.get<std::string>("input");
        std::ifstream input_stream(input);
        if (!input_stream) 
        {
            std::cout << "Invalid image path! \n";
            return 0;
        }
        std::unique_ptr<Input> capture = std::make_unique<Input>(input);
        cv::Mat frame;
        if (parser.has("input")) 
        {
            capture->GetImageFrame(frame);
        }
        std::unique_ptr<ObjectDetector> detector = std::make_unique<ObjectDetector>(config_path, weights_path, classes_path);
        cv::Mat detected_frame = detector->DetectObjects(frame);
        std::unique_ptr<Output> output = std::make_unique<Output>(image_out);
        output->WriteFrame(detected_frame);
        static const std::string kWinName = "Deep learning object detection in OpenCV";
        namedWindow(kWinName, cv::WINDOW_NORMAL);
        imshow(kWinName, frame);
        cv::waitKey(3000);
        cv::destroyAllWindows();

        std::cout << "Output image is saved as: " << image_out << std::endl;
    }

    else {
        std::cout << "Invalid Input Parameters\n";
    }
}