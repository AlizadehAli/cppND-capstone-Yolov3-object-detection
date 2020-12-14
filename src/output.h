#pragma once

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <fstream>
#include <sstream>
#include <iostream>

class Output {
public:
    Output(){}; //constructor
    Output(std::string &output_path); 
    void WriteFrame(cv::Mat &frame); 
    ~Output(){};

protected:
    std::string output_path_{""}; 
};
