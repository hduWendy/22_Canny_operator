// 22_Canny_operator.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	//��ȡ���ص�һ��ͼƬ.
	cv::Mat srcMat = imread("C:/Users/lenovo/Desktop/����/1.jpg",0);
	std::vector<cv::Mat> channels;
	cv::split(srcMat, channels);
	cv::Mat srcMat_single = channels.at(0);
	cv::Mat out1_Mat_single,out2_Mat_single;
	Canny(srcMat_single, out2_Mat_single,20,60);

	cv::Mat hsvMat;
	cv::Mat edgeX_Mat;
	cv::Mat edgeY_Mat;
	cv::Mat edgeX_Mat_out;
	cv::Mat edgeY_Mat_out;
	double scale = 0.5;

	Size ResImgSiz = Size(srcMat.cols*scale, srcMat.rows*scale);
	Mat rFrame = Mat(ResImgSiz, srcMat.type());
	resize(srcMat, rFrame, ResImgSiz, INTER_LINEAR);

	cvtColor(rFrame, hsvMat, COLOR_BGR2HSV);

	Sobel(rFrame, edgeX_Mat, CV_16SC1, 1, 0, 3);
	convertScaleAbs(edgeX_Mat, edgeX_Mat_out);
	Sobel(rFrame, edgeY_Mat, CV_16SC1, 0, 1, 3);
	convertScaleAbs(edgeY_Mat, edgeY_Mat_out);

	Canny(edgeX_Mat, edgeY_Mat, out1_Mat_single, 20, 60);

	imshow("src", srcMat_single);
	imshow("out1", out1_Mat_single);
	imshow("out2", out2_Mat_single);
	//�ȴ��û�����
	waitKey(0);
	return 0;
}
