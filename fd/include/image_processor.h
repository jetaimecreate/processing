#ifndef IMAGE_PROCESSOR_HPP
#define IMAGE_PROCESSOR_HPP

#include <opencv2/core.hpp>
#include <string>
struct ImageData {
    std::string img_name;
    std::string img_scale;
    std::string interpolation;
    int img_Horizontal;
    int img_Vertical;
    std::string Rotation_center;
    int Rotation_angle;
};
extern std::vector<ImageData> imageDatas;

void Image_Data();
void translateImage(cv::Mat& inputImage, cv::Mat& outputImage, int dx, int dy);
void rotateImage(cv::Mat& inputImage, cv::Mat& outputImage, double angle,std::string Rotation_center);
void scaleImage(cv::Mat& inputImage, cv::Mat& outputImage, int new_width, int new_height,int interpolation);
//void cutImage(cv::Mat& inputImage,cv::Mat& outputImage);
//void fillBlackWithWhite(cv::Mat& inputImage);
// IMAGE_PROCESSOR_HPP
std::string trim(const std::string& str);
std::vector<std::string> splitCSVLine(const std::string& line);
int ProcessFile(const std::string& filename, std::vector<ImageData>& img_transforms);
#endif 