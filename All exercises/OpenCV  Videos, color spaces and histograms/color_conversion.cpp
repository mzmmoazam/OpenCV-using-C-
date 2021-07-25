#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace cv;



int main() {

	Mat_<Vec3b> bgrImg = imread("moi_kashmir.jpg"),bgr_split [3],hsvImg, hsv_split [3], labImg, lab_split [3];


	split(bgrImg, bgr_split);//split source  

	imwrite("img_blue.png", bgr_split[0]); //blue channel
	imwrite("img_green.png", bgr_split[1]); //green channel
	imwrite("img_red.png", bgr_split[2]); //red channel

	for (int i = 0; i < 3; i++)
		imshow(to_string(i+1),bgr_split[i]);
	
	cvtColor(bgrImg, hsvImg, COLOR_BGR2HSV);

	split(hsvImg, hsv_split);//split source  

	imwrite("img_H.png", hsv_split[0]); //H channel
	imwrite("img_S.png", hsv_split[1]); //S channel
	imwrite("img_V.png", hsv_split[2]); //V channel

	for (int i = 0; i < 3; i++)
		imshow(to_string(i + 4), hsv_split[i]);

	cvtColor(bgrImg, labImg, COLOR_BGR2Lab);

	split(labImg, lab_split);//split source  

	imwrite("img_L.png", lab_split[0]); //L channel
	imwrite("img_A.png", lab_split[1]); //A channel
	imwrite("img_B.png", lab_split[2]); //B channel

	for (int i = 0; i < 3; i++)
		imshow(to_string(i + 7), lab_split[i]);

	waitKey();

	return 0;
}
