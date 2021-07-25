#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <vector>

#pragma once
using namespace cv;
using namespace std;

namespace psrs {

	void redFrame(Mat_<Vec3b> in, Mat_<Vec3b>& out, int size) {
		out.create(in.rows + 2 * size, in.cols + 2 * size);
		out = Vec3b(0, 0, 255);
		for (int i = 0; i < in.rows; i++)
			for (int j = 0; j < in.cols; j++)
				out(i + size, j + size) = in(i, j);

	}

}