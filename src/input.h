#pragma once

#include <fstream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

class Input
{
public:
    explicit Input(std::string &input_path); 
    bool EndOfFile();                        
    bool GetImageFrame(cv::Mat &frame);      
    ~Input();

protected:
    bool end_of_file_;                    
    cv::VideoCapture cap_;                
};
