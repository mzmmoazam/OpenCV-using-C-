#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include<iterator> 


#define BLUE Vec3b(255,0,0)
#define GREEN Vec3b(0,255,0)
#define RED Vec3b(0,0,255)
#define MAGENTA Vec3b(255,0,255)
#define YELLOW Vec3b(0,255,255)
#define CYAN Vec3b(255,255,0)
#define BLACK Vec3b(0,0,0)
#define WHITE Vec3b(255,255,255)


using namespace cv;
using namespace std;

class psrs {

private:
	static int image_no;
	vector<Vec3b> colors;
	vector<Mat_<Vec3b>> images;
	vector<Vec3b>::iterator ptr;
	vector<Mat_<Vec3b>>::iterator ptr2;
	Mat_<Vec3b> image;
	Mat_<Vec3b> framedImg;

public:

	psrs() {
		colors = { RED ,BLACK, BLUE, GREEN, YELLOW, CYAN,WHITE, MAGENTA };
	}


	const Mat_<Vec3b> createMatObj(Vec3b scalar, int rows = 500, int columns = 750) const {
		Mat_<Vec3b> temp(rows, columns, scalar);
		return temp;
	}

	void displayImage() const {
		namedWindow(to_string(image_no), WINDOW_AUTOSIZE);
		imshow(to_string(image_no++), image);
	}

	void displayImage(const Mat_<Vec3b>& image) const {
		namedWindow(to_string(image_no), WINDOW_AUTOSIZE);
		imshow(to_string(image_no++), image);
	}

	void ImageArray() {

		for (ptr = colors.begin(); ptr < colors.end(); ptr++)
			images.push_back(createMatObj(*ptr));

		for (ptr2 = images.begin(); ptr2 < images.end(); ptr2++)
			displayImage(*ptr2);
	}

	void readImage(const char * filename) {
		image = imread(filename);
	}



	void addRedFrame(int size) {

		framedImg.create(image.rows + 2*size, image.cols + 2*size);
		framedImg = Vec3b(0,0,255);
 		for (int i = 0; i < image.rows; i++)
			for (int j = 0; j < image.cols; j++)
				framedImg(i + size,j + size) = image(i, j);

		displayImage(framedImg);

	}

};

int psrs:: image_no = 1;



int main() {
	
	psrs obj;

	Mat_<Vec3b> M = obj.createMatObj(RED,2,2);


	cout << "(2 * 2 , RED colour) M => " << endl << " " << M << endl << endl;


	obj.ImageArray();

	obj.readImage("download.jpg"); 

	obj.displayImage();

	obj.addRedFrame(10);


	waitKey();


	return 0;
}


