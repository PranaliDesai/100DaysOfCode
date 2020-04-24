#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;

class Image {
protected:
    cv::Mat image2d;
    bool loadCheck;
public:
    Image();
    Image(int _height, int _width);
    vector<int> image1d;
    int width, height;
    void loadImage(string path);
    int showImage(cv::Mat _image2d);
    void convert2D();
    cv::Mat convert1D(vector<int> image, int height, int width);
    void checkLoad();
    bool imageLoadCheck();
    int getWidth();
    int getHeight();
    cv::Mat getImage();
    double getPixelat1D(int x, int y);
    double getPixelat2D(int x, int y);
    cv::Mat summedAreaTable(const std::vector<int> image1d, int img_height, int img_width);
    cv::Mat applyBoxFilter(const std::vector<int> &image1d, int ker_width, int ker_height);
    cv::Mat optimizedBoxFilter(const std::vector<int> image1d, int ker_height, int ker_width,
                                int img_height, int img_width);
};

// void Image::checkLoad() 
Image::Image() {
    width = 0;
    height = 0;
    // image
    image1d = {};
    loadCheck = true;
}

Image::Image(int _height, int _width) {
    width = _width;
    height = _height;
    // image
    image1d.resize(width*height);
    loadCheck = true;
}

void Image::loadImage(string path) {
    image2d = cv::imread(path, 0);
    if (image2d.data == NULL) {
        loadCheck = false;
    }
}

void Image::convert2D() {
    for (int i = 0; i < image2d.rows; i++) {
        for (int j = 0; j < image2d.cols; j++) {
            image1d.emplace_back(image2d.at<uchar>(i, j));
        }
    }
    width = image2d.cols;
    height = image2d.rows;
}

// x is row index and y is column indexed
double Image::getPixelat1D(int x, int y) {
    return image1d[y + x*width];
}

int Image::getWidth() {
    return width;
}

int Image::getHeight() {
    return height;
}

// x is row index and y is column indexed
double Image::getPixelat2D(int x, int y) {
    return image2d.at<uchar>(x, y);
}

bool Image::imageLoadCheck() {
    // bool ret_val = loadCheck;
    return loadCheck;
}

int Image::showImage(cv::Mat _image2d) {
    cv::namedWindow("Display Window", CV_WINDOW_AUTOSIZE);
    cv::imshow("Display Window", _image2d);
    cv::waitKey(0);
    return 0;
} 

cv::Mat Image::getImage() {
    return image2d;
}

cv::Mat Image::convert1D(std::vector<int> image, int height, int width) {
    cv::Mat ret_image(cv::Size(height, width), CV_8UC1);
    cout << "comes in here\n";
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // cout << i << " " << j << "\n";
            ret_image.at<uchar>(j, i) = image[j + i*width];
        }
    }
    return ret_image;
}
cv::Mat Image::applyBoxFilter(const std::vector<int> &image1d,\
                        int ker_height, int ker_width) {
    // Create a new Image of the reduced size 
    int new_h = height - ker_height/2;
    int new_w = width - ker_width/2;
    Image ret_image(new_h, new_w);
    // First iterate over all possible I(x, y)
    for (int i = ker_height/2; i < height - ker_height/2; i++) {
        for (int j = ker_width/2; j < width - ker_width/2; j++) {
            // Now iterate over the kernel to get a sum
            int sum = 0;

            for (int m = i - ker_height/2; m < (i - ker_height/2) + ker_height; m++) {
                for (int l = j - ker_height/2; l < (j - ker_height/2) + ker_height; l++) {
                    sum += getPixelat1D(m, l);
                }
            }

            ret_image.image1d[(j - ker_width/2) + (i-ker_width/2)*width] = sum/(ker_height*ker_width);
        }
    }

    cv::Mat ret_cv_image = convert1D(ret_image.image1d, new_h, new_w);
    // showImage(ret_image1);
    return ret_cv_image;
}

cv::Mat Image::summedAreaTable(const vector<int> image1d, 
                                int img_height, int img_width) {
    // The idea is to create a summed area table with the 
    // 1d image only
    // First initialize the matrix with first column and row values
    cv::Mat ret_image(img_height, img_width, CV_64F);
    ret_image.at<float>(0, 0) = getPixelat1D(0, 0);
    for (int i = 1; i < img_width; i++) {
        ret_image.at<float>(0, i) = ret_image.at<float>(0, i - 1) 
                                    + getPixelat1D(0, i);
    }
    for (int i = 1; i < img_height; i++) {
        ret_image.at<float>(i, 0) = ret_image.at<float>(i - 1, 0) +
                                    getPixelat1D(i, 0);
    }
    // ret_image has now been initialized for dp
    for (int i = 1;i < img_height; i++) {
        for (int j = 1;j < img_width; j++) {
            ret_image.at<float>(i, j) = ret_image.at<float>(i, j-1) + ret_image.at<float>(i-1, j) 
                                        + getPixelat1D(i, j) - ret_image.at<float>(i-1, j-1);
        }
    }
    return ret_image;
}

cv::Mat Image::optimizedBoxFilter(const vector<int> image1d, int ker_height, int ker_width, 
                                    int img_height, int img_width) {
    cv::Mat summed_image = summedAreaTable(image1d, img_height, img_width);
    cv::Mat ret_image(img_height, img_width, CV_8U);
    for (int i = ker_height/2; i < img_height - ker_height/2; i++) {
        // int ker_sum = 0;
        for (int j = ker_height/2; j < img_width - ker_width/2; j++) {
            int ker_sum = summed_image.at<float>(i + ker_height/2, j + ker_width/2) +
                            summed_image.at<float>(i - ker_height/2, j - ker_width/2) - 
                            summed_image.at<float>(i - ker_height/2, j + ker_width/2) -
                            summed_image.at<float>(i + ker_height/2, j - ker_width/2);
            ret_image.at<uchar>(i, j) = ker_sum/(ker_height*ker_width);
            // cout << summed_image.at<float>(i + img_height/2, j + img_width/2) << "\n";
        }
    }
    return ret_image;
}