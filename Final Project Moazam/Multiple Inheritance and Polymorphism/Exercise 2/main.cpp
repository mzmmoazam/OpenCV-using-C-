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

// using virtual functions
void globalProcess(Base & imageProcessing, Mat& imageToProcess)
{
	imageProcessing.compute(imageToProcess);
}



int main() {

	// This is the main program


	// read an image
	Mat source = imread("images/moi_kashmir.jpg", IMREAD_GRAYSCALE);
	const string _str = "After applying operation : ";

	imshow("original",source);


	// init BlurFiltering, EdgeDetector 

	BlurFiltering blurfiltering;

	EdgeDetector edgeDetector(source, SOBEL);


	// Set blur process and compute

	blurfiltering.setOpenCVProcessName(GAUSSIAN);

	//blurfiltering.compute(source); // Lazy processing 

	globalProcess(blurfiltering, source); // using virtual functions

	// view the result

	namedWindow(_str + blurfiltering.getOpenCVProcessName(), WINDOW_AUTOSIZE);

	imshow(_str + blurfiltering.getOpenCVProcessName(), source);
	

	// Compute Edge filtering 

	edgeDetector.compute(source);

	// View edge filtering results using the edgeDetector object

	namedWindow(_str + edgeDetector.getOpenCVProcessName(), WINDOW_AUTOSIZE);
	
	imshow(_str + edgeDetector.getOpenCVProcessName(), edgeDetector);


	// View edge filtering results using the source 

	imshow("source_end",source);

	waitKey();

	return 0;
}