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
	cv::Mat out2_Mat_single;
	Canny(srcMat_single, out2_Mat_single,20,60);

	int height = srcMat.rows; //����
	int width = srcMat.cols; //ÿ��Ԫ�ص���Ԫ������
	for (int j = 0; j<height; j++)
	{
		for (int i = 0; i<width; i++)
		{
			//-----------------��ʼ����ÿ������-----------------
		//	Canny(i,j,);

			//-------------�������ش���------------------------
		} //���д������
	}
	imshow("src", srcMat_single);
	imshow("out2", out2_Mat_single);
	//�ȴ��û�����
	waitKey(0);
	return 0;
}
