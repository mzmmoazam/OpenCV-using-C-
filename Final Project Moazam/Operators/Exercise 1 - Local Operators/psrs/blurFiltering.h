#pragma once
// BlurFiltering v0.1

#include <opencv2\opencv.hpp>
#include "base.h"

using namespace std;
using namespace cv;

// psrs namespace declaration
namespace psrs {

	class BlurFiltering : public Mat, public Base {
	// Blur Filtering inheriting from Mat and Base


	private:
		// const used in blur filters
		const int sigma = 3;
		const int ksize = (sigma * 5) | 1;


	public:

		// default constructor
		BlurFiltering() : Base(BlurFilter) {}

		// param constructor
		BlurFiltering(const Mat& src, BlurFilters process = MEAN) : Mat(src), Base(process, BlurFilter) {}


		// function for computation of Blur Filters
		void compute(Mat& input) {

			switch (process)
			{

			case MEAN:
				blur(input, input, Size(3, 3));

			case GAUSSIAN:
				GaussianBlur(input, input, Size(3, 3), 0);

			case MEDIAN:
				medianBlur(input, input, ksize);

			}
		}

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


		virtual void operator=(Mat& src) {
			src.copyTo(*this);
		};

		virtual const Mat operator[](const Rect& roi) {
			Mat& temp = *this;
			return temp(roi);
		};

		virtual const Vec3b operator()(int i, int j) {
			return this->at<Vec3b>(i, j);
		};

	};

}



