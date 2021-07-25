#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

namespace psrs {

	Mat createMatObj(Scalar scalar, int rows = 500, int columns = 750, int details = CV_32FC3) {
		Mat temp(rows, columns, details, scalar);
		return temp;
	}
}
