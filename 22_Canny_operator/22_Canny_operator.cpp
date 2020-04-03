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
	cv::Mat out2_Mat_single;
	Canny(srcMat_single, out2_Mat_single,20,60);

	int height = srcMat.rows; //行数
	int width = srcMat.cols; //每行元素的总元素数量
	for (int j = 0; j<height; j++)
	{
		for (int i = 0; i<width; i++)
		{
			//-----------------开始处理每个像素-----------------
		//	Canny(i,j,);

			//-------------结束像素处理------------------------
		} //单行处理结束
	}
	imshow("src", srcMat_single);
	imshow("out2", out2_Mat_single);
	//等待用户按键
	waitKey(0);
	return 0;
}
