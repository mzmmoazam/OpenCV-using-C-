#include <iostream>
#include <opencv2\opencv.hpp>
#include <cstring>

// import custom header files

# include "psrs/edgeDetector.h"
# include "psrs/blurFiltering.h"
# include "psrs/base.h"

using namespace std;
using namespace cv;
using namespace psrs;



int main() {

	// This is the main program

	// read an image
	Mat source = imread("images/moi_kashmir.jpg", IMREAD_GRAYSCALE);
	const string _str = "After applying operation : ";

	imshow("original",source);

	// init BlurFiltering, EdgeDetector 

	BlurFiltering blurfiltering;

	EdgeDetector edgeDetector;

	// Set blur process and compute

	blurfiltering.setOpenCVProcessName(GAUSSIAN);
	edgeDetector.setOpenCVProcessName(SOBEL);

	source >> edgeDetector >> blurfiltering;
	cout <<  (Base&)blurfiltering; // display the text �Gaussian� in the console. 
	
	// View edge filtering results using the source 
	imshow(_str + "edgeDetector", edgeDetector);
	imshow(_str + "blurfiltering", blurfiltering);

	imshow("source_end",blurfiltering);

	waitKey();

	return 0;
}