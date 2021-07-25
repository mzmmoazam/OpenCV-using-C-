#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace cv;



int main() {

	// HiST PARAM START

	int histSize = 256;
	float range[] = { 0, 256 }; //the upper boundary is exclusive
	const float* histRange = { range };
	bool uniform = true, accumulate = false;

	// PARAM END

	Mat_<Vec3b> img = imread("moi_kashmir_2.jpg"), img_channels[3],overlay;

	Mat histogram[3];
	

	split(img,img_channels);


	// Compute histogram
	for (int channel = 0; channel < 3 ; channel++)
		calcHist(&img_channels[channel], 1, 0, Mat(), histogram[channel], 1, &histSize, &histRange, uniform, accumulate);

	//int hist_width = img.cols/10, hist_height = img.rows/10;

	//if (hist_width < hist_height) {
	//	// switch height and width
	//	int temp = hist_height;
	//	hist_height = hist_width, hist_width = temp;
	//}

	int hist_width = img.cols, hist_height = img.rows;

	int bin_width = cvRound((double)hist_width / histSize);


	// normalise histogram
	for (int channel = 0; channel < 3; channel++)
		normalize(histogram[channel], histogram[channel], 0, hist_height, NORM_MINMAX, -1, Mat());

	// For Transparency
	double alpha = 0.4;  // defining opacity value, 0 means fully transparent, 1 means fully opaque

	img.copyTo(overlay);  // copying the source image to overlay matrix, we'll be drawing shapes on overlay matrix and we'll blend it with original image



	for (int bin = 1; bin < histSize; bin++)
		for (int channel = 0; channel < 3; channel++)
			line(overlay, Point(bin_width * (bin - 1), hist_height - cvRound(histogram[channel].at<float>(bin - 1))),
				Point(bin_width * (bin), hist_height - cvRound(histogram[channel].at<float>(bin))),
				Scalar(channel == 0 ? 255 : 0, channel == 1 ? 255 : 0,channel == 2 ? 255 : 0),
				2, 8, 0);
	
	addWeighted(overlay, alpha, img, 1 - alpha, 0, img);  // blending the overlay (with alpha opacity) with the source image (with 1-alpha opacity)

	imshow("Source image", img);
	waitKey();

	return 0;
}

