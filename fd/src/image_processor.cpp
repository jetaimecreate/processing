#include "image_processor.h"
#include <opencv2/imgproc.hpp>
using namespace std;
std::vector<ImageData> imageDatas;
void translateImage(cv::Mat& inputImage, cv::Mat& outputImage, int dx, int dy) {
    cv::Mat M = (cv::Mat_<double>(2,3) << 1, 0, dx, 0, 1, dy);
    cv::warpAffine(inputImage, outputImage, M, inputImage.size(),1,0,cv::Scalar(255,255,255));
}

void rotateImage(cv::Mat& inputImage, cv::Mat& outputImage, double angle,string Rotation_center) {
    double centerx,centery;
    if((Rotation_center.compare("center")) == 0){centerx=inputImage.cols/2;centery=inputImage.rows/2;}
    else if((Rotation_center.compare("origin")) == 0){centerx=0;centery=0;}
    cv::Point2f center(centerx, centery);
    cv::Mat M = cv::getRotationMatrix2D(center, angle, 1.0);
    cv::warpAffine(inputImage, outputImage, M, inputImage.size(),1,0,cv::Scalar(255,255,255));
}

void scaleImage(cv::Mat& inputImage, cv::Mat& outputImage,int new_width,int new_height,int interpolation) {
    cv::resize(inputImage, outputImage, cv::Size(new_width,new_height),interpolation );
}
/*
 void cutImage(cv::Mat& inputImage,cv::Mat& outputImage) {
    cv::Mat grayImage;
    cv::cvtColor(inputImage, grayImage, cv::COLOR_BGR2GRAY);
    cv::threshold(grayImage, outputImage, 155, 255, cv::THRESH_BINARY);
    cv::bitwise_not(outputImage,outputImage);
    cv::cvtColor(outputImage,outputImage, cv::COLOR_GRAY2BGR);
    cv::bitwise_and(outputImage,inputImage,outputImage);
}
void fillBlackWithWhite(cv::Mat& inputImage) {
    cv::Mat grayImage;
    cv::cvtColor(inputImage, grayImage, cv::COLOR_BGR2GRAY);
    cv::Mat binaryImage;
    vector<vector<cv::Point>> contours;
    vector<cv::Vec4i> hierarchy;
    findContours(binaryImage, contours, hierarchy,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_SIMPLE);
    double maxArea = -1;
    int maxContourIdx = -1;
    for (size_t i = 0; i < contours.size(); ++i) {
        double area = cv::contourArea(contours[i]);
        if (area > maxArea) {
            maxArea = area;
            maxContourIdx = i;
        }
    }
    cv::Mat resultImage =cv::Mat::zeros(inputImage.size(), CV_8UC3);
    cv::drawContours(resultImage, contours, maxContourIdx, cv::Scalar(0, 255, 0),cv::FILLED,cv::LINE_8);
    cv::threshold(grayImage,binaryImage, 1, 255, cv::THRESH_BINARY); // 使用阈值1将非黑色部分设置为白色
    cv::bitwise_not(binaryImage, binaryImage);
    inputImage.setTo(cv::Scalar(255, 255, 255), binaryImage);
}

    */

    
    
    
    