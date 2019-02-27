#include<opencv.hpp>
#include<iostream>
#include<string>

using namespace std;
using namespace cv;
int main()
{
	int IFromRGBW(const cv::Mat src, const float RW, const float GW, const float BW,cv::Mat dst);
	int HSI(const cv::Mat src, cv::Mat dst);
	int RGB(const cv::Mat src, cv::Mat dst);

	Mat src;
	src = imread("C:/Users/SZJ/Desktop/1.jpg", 1);
	Mat hsi_img(src.rows, src.cols, CV_8UC3);
	Mat ifw_img(src.rows, src.cols, CV_8UC1);
	Mat rgb_img(src.rows, src.cols, CV_8UC3);


	int a = HSI(src, hsi_img);
	int b = RGB(hsi_img, rgb_img);

	int runmode = 3;
	if (runmode == 1)
	{
		int resVal = IFromRGBW(src, 0.333, 0.333, 0.333, ifw_img);	
	}
	if (runmode == 0)
	{
		int resVal = HSI(src, hsi_img);
	}

	//imshow("I", ifw_img);
	imshow("HSI", hsi_img);
	imshow("RGB", rgb_img);
	imshow("原图", src);
	
	/*
	cout << "dims:" <<a.dims << endl;
	cout << "rows:" << img.rows << endl;
	cout << "cols:" << img.cols << endl;
	cout << "channels:" << img.channels() << endl;
	
	cout << "depth:" << img.depth() << endl;
	cout << "elemSize:" << img.elemSize() << endl;
	cout << "elemSize1:" << img.elemSize1() << endl;
	*/
	waitKey(0);
	system("pause");
	return 0;

}

int IFromRGBW(const cv::Mat src, const float RW, const float GW, const float BW,cv::Mat dst)
{
	if (src.type() == CV_8UC3)
	{
		Mat srcMat;
		src.copyTo(srcMat);

		int rows = src.rows;          //行数
		int cols = src.cols;          //列数

		for (int i = 0; i < rows; i++)          //行循环
		{
			uchar * dstdata = dst.ptr<uchar>(i);       //获取dst每行的首地址
			uchar *srcMatdata = srcMat.ptr<uchar>(i);  //获取srcMat每行的首地址

			for (int j = 0; j < cols; j++)          //列循环
			{
				dstdata[j] = srcMatdata[3 * j] * BW + srcMatdata[3 * j + 1] * GW + srcMatdata[3 * j + 2] * RW;
			}
		}
	}
	else {
		return 1;
	}
	return 0;
}

int HSI(const cv::Mat src, cv::Mat dst)
{
	cvtColor(src, dst, COLOR_BGR2HSV);
	return 0;
}
int RGB(const cv::Mat src, cv::Mat dst)
{
	cvtColor(src, dst, COLOR_HSV2BGR);
	return 0;
}