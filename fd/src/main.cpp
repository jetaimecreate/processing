#include <opencv2/opencv.hpp>
#include "image_processor.h"

int main() {
    ProcessFile("/home/zqm/fd/dataset_任务一/experiment1.csv", imageDatas);
    for (const auto& imageData : imageDatas) {
    std::string filename = "/home/zqm/fd/dataset_任务一/" + imageData.img_name;
    std::string filename_out = "/home/zqm/fd/dataset_任务一/终/" + imageData.img_name;
    cv::Mat inputImage = cv::imread(filename, cv::IMREAD_COLOR);
    if (inputImage.empty()) {
        std::cerr << "Error: Could not read image file." << std::endl;
        return -1;
    }

    // Create output images
    cv::Mat translatedImage, rotatedImage, scaledImage,outputImage;
    int new_width = inputImage.cols;
    int new_height= inputImage.rows;
    int interpolation;
    if((imageData.interpolation.compare("NEAREST")) == 0)
    {interpolation=cv::INTER_NEAREST;}
    else if((imageData.interpolation.compare("LINEAR")) == 0)
    {interpolation=cv::INTER_LINEAR;}
    if (imageData.img_scale.size() < 4) {
        new_width = std::stof(imageData.img_scale) * inputImage.cols;
        new_height = std::stof(imageData.img_scale) * inputImage.rows;
    }
    else{
        std::string width, height;
        std::stringstream a;
        a.str(imageData.img_scale);
        std::getline(a, width, ',');
        std::getline(a, height, ',');
        width.erase(0,1);
        height.pop_back();
        //new_width = std::stoi(width);
        //new_height = std::stoi(height);
        
        std::cout << width <<std::endl;
        

    }
    
    
    //cutImage(inputImage,outputImage);
    //cv::imshow("fenli",outputImage);
    scaleImage(inputImage,scaledImage,new_width, new_height,interpolation);  
    translateImage(scaledImage, translatedImage,imageData.img_Horizontal,imageData.img_Vertical); // Translate by (50, 50)
    rotateImage(translatedImage, rotatedImage,imageData.Rotation_angle,imageData.Rotation_center);        // Rotate by 30 degrees
    //fillBlackWithWhite(scaledImage);
    //cv::imshow("Scaled Image", scaledImage);
    cv::imwrite(filename_out, rotatedImage);}
    
    // Wait for a key press
    cv::waitKey(0);

    return 0;
}
/*
*/