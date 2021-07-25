#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <vector>

static int image_no = 1;

using namespace cv;
using namespace std;

void displayImage(Mat_<Vec3b> image) {
	namedWindow(to_string(image_no), WINDOW_AUTOSIZE);
	imshow(to_string(image_no++), image);
}



void redFrame(Mat_<Vec3b> in, Mat_<Vec3b>& out, int size) {
	out.create(in.rows + 2*size, in.cols + 2*size);
	out = Vec3b(0,0,255);
	for (int i = 0; i < in.rows; i++)
		for (int j = 0; j < in.cols; j++)
			out(i + size, j + size) = in(i, j);


}




int main()
{
	Mat_<Vec3b> img = imread("C:/Users/mzm/Desktop/Wallpapers/python-programming-wallpaper.jpg", IMREAD_GRAYSCALE);
	Mat_<Vec3b> framedImg;

	displayImage(img);


	redFrame(img, framedImg, 10);

	displayImage(framedImg);


	imwrite("redframe_channel.jpg", framedImg);


	waitKey();

	return 0;
}

