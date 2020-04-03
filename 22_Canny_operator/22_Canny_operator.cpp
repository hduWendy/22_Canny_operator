// 22_Canny_operator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	//读取本地的一张图片.
	cv::Mat srcMat = imread("C:/Users/lenovo/Desktop/推文/1.jpg",0);
	std::vector<cv::Mat> channels;
	cv::split(srcMat, channels);
	cv::Mat srcMat_single = channels.at(0);
	cv::Mat out1_Mat_single,out2_Mat_single;
	Canny(srcMat_single, out2_Mat_single,20,60);

	cv::Mat edgeX_Mat;
	cv::Mat edgeY_Mat;
	cv::Mat edgeX_Mat_out;
	cv::Mat edgeY_Mat_out;
	double scale = 0.5;

	Sobel(srcMat_single, edgeX_Mat, CV_16SC1, 1, 0, 3);
	convertScaleAbs(edgeX_Mat, edgeX_Mat_out);
	Sobel(srcMat_single, edgeY_Mat, CV_16SC1, 0, 1, 3);
	convertScaleAbs(edgeY_Mat, edgeY_Mat_out);

	Canny(edgeX_Mat, edgeY_Mat, out1_Mat_single, 20, 60);

	imshow("src", srcMat_single);
	imshow("out1", out1_Mat_single);
	imshow("out2", out2_Mat_single);
	//等待用户按键
	waitKey(0);
	return 0;
}
