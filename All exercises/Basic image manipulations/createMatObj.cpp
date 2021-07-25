
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


Mat createMatObj(int rows,int columns,int details, Scalar scalar) {
	Mat temp(rows, columns, details, scalar);
	return temp;
}


int main()
{
	Mat M = createMatObj(4, 4, CV_32FC3, Scalar(0, 0, 255));
	cout << "M = " << endl << " " << M << endl << endl;

	namedWindow("image", WINDOW_AUTOSIZE);
	imshow("image", M);
	waitKey();

	return 0;
}

