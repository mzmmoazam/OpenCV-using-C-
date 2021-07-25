#pragma once
// EdgeDetector v0.1

#include <opencv2\opencv.hpp>
#include "base.h"

using namespace std;
using namespace cv;

// psrs namespace declaration
namespace psrs {

	class EdgeDetector : public Mat, public Base{
	// EdgeDetector inheriting from Mat and base


	private:
		// constants used in various edge detectors
		const int lowThreshold = 50;
		const int ratio = 3;
		const int kernel_size = 3;
		const int scale = 1, delta = 0;


	public:

		// default const
		EdgeDetector() : Base(EdgeDetect) {}

		// param const
		EdgeDetector(const Mat& src, EdgeDetectors process = CANNY) : Mat(src), Base(process, EdgeDetect) {}

		// function to run various edge detectors when Mat object is given
		void compute(Mat& input) {

			// temp var
			Mat temp, tmpx, tmpy;

			switch (process)
			{

			case CANNY:
				Canny(input, input, lowThreshold, lowThreshold * ratio, kernel_size);

			case LAPLACIAN:
				Laplacian(input, temp, CV_16S, kernel_size, scale, delta);
				convertScaleAbs(temp, temp);
				

			case SOBEL:
				Sobel(input, tmpx, CV_16S, 1, 0);
				Sobel(input, tmpy, CV_16S, 0, 1);
				convertScaleAbs(tmpx, tmpx);
				convertScaleAbs(tmpy, tmpy);
				addWeighted(tmpx, 0.5, tmpy, 0.5, 0, input);
			}
		}

		// function to run various edge detectors on self
		void compute() {
			try {
				Mat input = *this;
				compute(input);
			}
			// Possible error of not providing an image (Mat object not being created) at init
			// to be rectified in the next iteration (exercises) more decently
			catch (...) {
				cout << "Please provide an image" << endl;
			}
		}

	};


}

