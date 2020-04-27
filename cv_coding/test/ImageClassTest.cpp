#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Image.cpp"
#include <opencv2/opencv.hpp>

TEST(imageLoadTest, shouldEqual) {
    Image img;
    img.loadImage("../download.jpeg");
    img.convert2D();
    ASSERT_EQ(img.imageLoadCheck(), true);
}

TEST(pixelValTest, shouldEqual) {
    Image img;
    img.loadImage("../download.jpeg");
    img.convert2D();
    cv::Mat orig_img = cv::imread("../download.jpeg", 0);
    // std::cout << img.getPixelat1D(54,6) << " " << 
    // img.getPixelat2D(54,6) << "\n";
    ASSERT_EQ(orig_img.at<uchar>(54,6), img.getPixelat2D(54,6));
}

TEST(checkSize, shouldEqual) {
    Image img;
    img.loadImage("../download.jpeg");
    img.convert2D();
    // std::cout << img.getPixelat1D(54,6) << " " << 
    // img.getPixelat2D(54,6) << "\n";
    cv::Mat orig_img = cv::imread("../download.jpeg", 0);
    int size = orig_img.cols*orig_img.rows;
    ASSERT_EQ(img.getHeight()*img.getWidth(), size);
}

// TEST(filterTest, shouldEqual) {
//     Image img;
//     img.loadImage("../download.jpeg");
//     img.convert2D();
//     // std::cout << img.getPixelat1D(54,6) << " " << 
//     cv::Mat ret_img = img.optimizedBoxFilter(img.image1d, 3, 3, img.getHeight(), img.getWidth());
    
//     int ret = img.showImage(ret_img);
//     cv::Mat out = img.getImage();
//     cv::boxFilter(out, out, -1, cv::Size(3, 3), cv::Point(-1, -1), true);
//     img.showImage(out);
//     ASSERT_EQ(ret , 0);

// }

// TEST(summedTableTest, shouldEqual) {
//     Image img;
//     img.loadImage("../download.jpeg");
//     img.convert2D();
//     int pixelSumOrig = img.getPixelat2D(0, 0) + img.getPixelat2D(0, 1) 
//                        + img.getPixelat2D(1, 0) + img.getPixelat2D(1, 1);
//     // int p2 = img.getPixelat2D(0, 1) + img.getPixelat2D(0, 0);
//     cv::Mat ret_img = img.summedAreaTable(img.image1d, img.getHeight(), img.getWidth());
//     ASSERT_EQ(ret_img.at<float>(1, 1) , pixelSumOrig);

// }


TEST(sobelTest, shouldEqual) {
    Image img;
    img.loadImage("../download.jpeg");
    img.convert2D();
    cv::Mat ret_img = img.applySobel(img.image1d, img.getHeight(), img.getWidth(), 0);
    cv::Mat sobel;
    cv::Sobel(img.getImage(), sobel, -1, 0, 1);
    double minVal; 
    double maxVal; 
    cv::Point minLoc; 
    cv::Point maxLoc;

    minMaxLoc(ret_img, &minVal, &maxVal, &minLoc, &maxLoc );

    cout << "min val ret_img: " << minVal << endl;
    cout << "max val ret_img:" << maxVal << endl;


    minMaxLoc(sobel, &minVal, &maxVal, &minLoc, &maxLoc );

    cout << "min val sobel: " << minVal << endl;
    cout << "max val sobel:" << maxVal << endl;
    cout << sobel.type() << "\n";
    int ret_val = img.showImage(ret_img);
    img.showImage(sobel);
    ASSERT_EQ(ret_val , 0);
}




// TEST(convertFrom1DTest, shouldEqual) {
//     Image img;
//     img.loadImage("../download.jpeg");
//     img.convert2D();
//     // std::cout << img.getPixelat1D(54,6) << " " << 
//     cv::Mat ret_img = img.convert1D(img.image1d,\
//                         img.getHeight(), img.getWidth());
//     // cv::Mat ret_img = img.applyBoxFilter(img.image1d, 3, 3);
    
//     int ret = img.showImage(ret_img);
//     cv::Mat out = img.getImage();
//     cv::boxFilter(out, out, -1, cv::Size(3, 3), cv::Point(-1, -1), true);
//     img.showImage(out);
//     // ASSERT_EQ(out , ret_img);

// }
