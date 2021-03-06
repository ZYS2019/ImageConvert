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
	int Plane(const cv::Mat src,const int plane, cv::Mat &dst);
	int I(const cv::Mat src, cv::Mat &dst);

	Mat src;
	src = imread("C:/Users/SZJ/Desktop/1.jpg", 1);
	Mat hsi_img(src.rows, src.cols, CV_8UC3);
	Mat ifw_img(src.rows, src.cols, CV_8UC1);
	Mat rgb_img(src.rows, src.cols, CV_8UC3);
	Mat bc(src.rows, src.cols, CV_8UC1);
	Mat intensity;


	int resVal = Plane(src, 1, bc);
	resVal = I(bc, intensity);

	bc = imread("C:/Users/SZJ/Desktop/1.jpg", 1);
	//Mat hsiimread(src.rows, src.cols, CV_8UC3);  
	//Mat H(src.rows, src.cols, CV_8UC1);
	//Mat S(src.rows, src.cols, CV_8UC1);
	//Mat I(src.rows, src.cols, CV_8UC1);
	//std::vector<Mat> channels;

	//int a = HSI(src, hsi_img);
	//imwrite("C:/Users/SZJ/Desktop/hsi.jpg", hsi_img);        //保存利用BGR2HSV转换得到的hsi图像
	//hsiimread = imread("C:/Users/SZJ/Desktop/hsi.jpg", 1);     //读入存储的hsi图像，看h通道的取值范围

	//int b = RGB(hsi_img, rgb_img);
	
	/*
	//--------------------看hsi格式图像H通道分量---------------
	split(hsiimread, channels);
	H = channels.at(0);
	S = channels.at(1);
	I = channels.at(2);

	if (hsiimread.channels() == 3)
	{
		imshow("hsiimread", hsiimread);
	}
	//imshow("H", H);
	//imshow("S", S);
	//imshow("I", I);
	//cout << "h:" << H << endl;       //输出H的值发现H通道的取值范围为0-180
	*/

	int runmode = 7;
	if (runmode == 1)
	{
		int resVal = IFromRGBW(src, 0.333, 0.333, 0.333, ifw_img);	
	}
	else if (runmode == 0)
	{
		int resVal = HSI(src, hsi_img);
	}
	else if (runmode == 2)
	{
		int resVal=Plane(hsi_img,1, bc);
	}
	else if (runmode == 3) {
		int resVal = RGB(hsi_img, rgb_img);
	}

	//cout << "channels:" << bc.channels() << endl;
	imshow("I", intensity);
	imshow("SRC", bc);
	//imshow("HSI", hsi_img);
	//imshow("RGB", rgb_img);
	//imshow("原图", src);
	//imshow("b通道", bc);
	
	/*
	cout << "dims:" <<a.dims << endl;
	cout << "rows:" << img.rows << endl;
	cout << "cols:" << img.cols << endl;
	
	
	cout << "depth:" << img.depth() << endl;
	cout << "elemSize:" << img.elemSize() << endl;
	cout << "elemSize1:" << img.elemSize1() << endl;
	*/
	waitKey(0);
	//system("pause");
	return 0;

}

int I(const cv::Mat src, cv::Mat &dst)
{
	if (src.type() == CV_8UC1)
	{
		src.copyTo(dst);
	}
	return 0;
}


int Plane(const cv::Mat src, const int plane, cv::Mat &dst)
{
	if (src.channels() == 3)
	{
		std::vector<Mat> channels;
		split(src, channels);
		if (plane == 0) {
			dst = channels.at(0);
		}
		else if (plane == 1) {
			dst = channels.at(1);
		}
		else if (plane == 2) {
			dst = channels.at(2);
		}
	}
	else {
		return 1;
	}
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
