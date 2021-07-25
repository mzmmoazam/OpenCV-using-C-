
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "ArrOfImages.h"
#include "createMatObj.h"
#include "ReadAndSaveImages.h"


using namespace std;
using namespace psrs;

int main() {

	Mat M = createMatObj(Scalar(0, 0, 255),2,2);

	cout << "M = " << endl << " " << M << endl << endl;

	ImageArray();

	Mat_<Vec3b> img = imread("C:/Users/mzm/Desktop/Wallpapers/python-programming-wallpaper.jpg", IMREAD_GRAYSCALE),framedImg;

	displayImage(img);

	redFrame(img, framedImg, 10);

	displayImage(framedImg);



	waitKey();

	return 0;
}

