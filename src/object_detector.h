#pragma once

#include <fstream>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

class ObjectDetector
{
    const int inpWidth = 640; 
    const int inpHeight = 640;
    const float conf_threshold = 0.5; 
    const float nms_threshold = 0.5; 

public:
    ObjectDetector() = delete;
    ObjectDetector(std::string &model_config, std::string &model_weights, std::string &classes_file); 
    ObjectDetector(const ObjectDetector &other);            //copy constructor
    ObjectDetector &operator=(const ObjectDetector &other); //copy asignment operator
    ObjectDetector(ObjectDetector &&other);                 //move constructor
    ObjectDetector &operator=(ObjectDetector &&other);
    ~ObjectDetector() {}                                    //destruction
    cv::Mat DetectObjects(cv::Mat &frame);

private:
    void GetOutputLayerNames();
    void Get4DBlob(cv::Mat &frame, cv::Mat &blob);
    void PostProcess(cv::Mat &frame, const std::vector<cv::Mat> &outs);
    void DrawPred(int classId, float conf, int left, int top, int right, int bottom, cv::Mat &frame);
    void ReadClassesFromFile();

    static std::vector<std::string> output_layer_names_;
    static std::vector<std::string> classes_;

    cv::dnn::Net net_;
    std::string model_config_{""};
    std::string model_weights_{""};
    std::string classes_file_{""};
};