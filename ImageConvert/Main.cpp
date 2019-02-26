#include<opencv.hpp>
#include<iostream>
#include<string>

using namespace std;
using namespace cv;
int main()
{
	Mat a;
	Mat img;
	a = imread("C:/Users/SZJ/Desktop/2_10.jpg", 1);
	cvtColor(a, img, COLOR_BGR2HLS);
	//imshow("ԭͼ", a);
	//imshow("HSI", b);
	//waitKey(6000);

	//cout << img << endl;

	cout << "dims:" <<a.dims << endl;
	cout << "rows:" << img.rows << endl;
	cout << "cols:" << img.cols << endl;
	cout << "channels:" << img.channels() << endl;
	cout << "type:" << img.type() << endl;
	cout << "depth:" << img.depth() << endl;
	cout << "elemSize:" << img.elemSize() << endl;
	cout << "elemSize1:" << img.elemSize1() << endl;

	system("pause");
	return 1;

}
