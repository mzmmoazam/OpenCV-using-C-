#include <opencv2/opencv.hpp>
#include <vector>


#define BLUE Scalar(255,0,0)
#define GREEN Scalar(0,255,0)
#define RED Scalar(0,0,255)
#define MAGENTA Scalar(255,0,255)
#define YELLOW Scalar(0,255,255)
#define CYAN Scalar(255,255,0)
#define BLACK Scalar(0,0,0)
#define WHITE Scalar(255,255,255)
static int image_no = 0;

using namespace std;
using namespace cv;

class MultiDrawing
{
private:
	Scalar curColor;
	vector<Mat> images;
	int thickness;
	int lineType;


public:

	MultiDrawing(Scalar _curColor = RED, int _thickness = 2, int _lineType = LINE_AA) {
		curColor = _curColor, thickness = _thickness, lineType = _lineType;
	}

	void AddImage(const  char filename[])
	{
		images.push_back(imread(filename));
	}

	void SetCurrentColor(Scalar color) {
		curColor = color;
	}

	void SetThickness(int _thickness) {
		thickness = _thickness;
	}

	void SetLineType(int _lineType) {
		lineType = _lineType;
	}

	const Scalar GetCurrentColor() const {
		return curColor;
	}

	const int GetThickness() const {
		return thickness;
	}

	const int GetLineType() const {
		return lineType;
	}
	

	void DrawRectangle(Point start, Point end) {

		for (int i = 0; i < images.size(); i++)
			rectangle(images[i],
				start,
				end,
				curColor,
				thickness,
				lineType);
	}

	void DrawLine(Point start, Point end) {
		for (int i = 0; i < images.size(); i++)
			line(images[i],
				start,
				end,
				curColor,
				thickness,
				lineType);
	}

	void DrawText(const char text[], Point location, int fontFace = FONT_HERSHEY_COMPLEX, double fontScale = 3) {

		for (int i = 0; i < images.size(); i++)
			putText(
				images[i],
				text,
				location,
				fontFace,
				fontScale,
				curColor,
				thickness,
				lineType
			);

	}

	void DisplayAllImages() {

		for (int i = 0; i < images.size(); i++)
			imshow(to_string(image_no++), images[i]);

	}

	void RemoveAllImages() {
		images.clear();
	}
};

/*
int main(void)
{
	MultiDrawing obj;

	obj.AddImage("download.jpg");
	obj.AddImage("C:/Users/mzm/Desktop/Wallpapers/python-programming-wallpaper.jpg");
	obj.AddImage("C:/Users/mzm/Desktop/Wallpapers/02207_venividivenice_1920x1080.jpg");

	obj.SetCurrentColor(BLUE);
	obj.DrawRectangle(Point(10, 10), Point(200, 200));
	obj.DrawLine(Point(10, 10), Point(200, 200));

	obj.SetCurrentColor(GREEN);
	obj.DrawText("Toto n’aime pas la soupe", Point(15, 150));

	obj.DisplayAllImages();

	obj.RemoveAllImages();

	waitKey();
	return 0;
}
*/