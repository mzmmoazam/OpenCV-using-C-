#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include<iterator> 
#include "createMatObj.h"

using namespace cv;
using namespace std;

namespace psrs {

#define BLUE Scalar(255,0,0)
#define GREEN Scalar(0,255,0)
#define RED Scalar(0,0,255)
#define MAGENTA Scalar(255,0,255)
#define YELLOW Scalar(0,255,255)
#define CYAN Scalar(255,255,0)
#define BLACK Scalar(0,0,0)
#define WHITE Scalar(255,255,255)

	static int image_no = 1;



	void displayImage(Mat image) {
		namedWindow(to_string(image_no), WINDOW_AUTOSIZE);
		imshow(to_string(image_no++), image);
	}

	void ImageArray() {

		vector<Scalar> colors = { RED ,BLACK, BLUE, GREEN, YELLOW, CYAN,WHITE, MAGENTA };

		vector<Mat> images;
		vector<Scalar>::iterator ptr;

		for (ptr = colors.begin(); ptr < colors.end(); ptr++)
			images.push_back(createMatObj(*ptr));

		//transform(colors.begin(),colors.end(),images.begin(),createMatObj);

		for_each(images.begin(), images.end(), displayImage);

	}
}