#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

//#define DEBUG

class VideoHistogram {

private:

	VideoCapture cap;
	Mat selected_frame, resized_frame,channelMergeFrame;
	int frame_timing;
	Mat frame;
	Mat rgb_channels[3], hsv_channels[3], lab_channels[3];
	Mat hsvImg, labImg;
	Mat histogram[9], hist_frame;

	// hist param
	int histSize = 256;
	float range[2] = { 0, 256 }; //the upper boundary is exclusive
	const float* histRange = { range };
	bool uniform = true, accumulate = false;


	void _convert_and_split() {

		cv::resize(selected_frame, resized_frame, cv::Size(), 0.33, 0.33); // 1/3 of original image

		split(resized_frame, rgb_channels);

		cvtColor(resized_frame, hsvImg, COLOR_BGR2HSV);

		split(hsvImg, hsv_channels);
	
		cvtColor(resized_frame, labImg, COLOR_BGR2Lab);

		split(labImg, lab_channels);
		
	}

	void _merge() {

		Mat temp [3];
		hconcat(rgb_channels, 3, temp[0]);
		hconcat(hsv_channels, 3, temp[1]);
		hconcat(lab_channels, 3, temp[2]);

		vconcat(temp, 3, channelMergeFrame);
			
	}


	void _computeHistogram(Mat img[], Mat& out, int histIndex) {
		// computes histograms and merge into one mat (out) vertically

		for (int channel = 0; channel < 3; channel++)
			calcHist(&img[channel], 1, 0, Mat(), histogram[channel + histIndex], 1, &histSize, &histRange, uniform, accumulate);

		int hist_width = img[0].cols, hist_height = img[0].rows;

		int bin_width = cvRound((double)hist_width / histSize);


		// normalise histogram
		for (int channel = 0; channel < 3; channel++)
			normalize(histogram[channel + histIndex], histogram[channel + histIndex], 0, hist_height, NORM_MINMAX, -1, Mat());


		for (int bin = 1; bin < histSize; bin++)
			for (int channel = 0; channel < 3; channel++)
				line(img[channel], Point(bin_width * (bin - 1), hist_height - cvRound(histogram[channel + histIndex].at<float>(bin - 1))),
					Point(bin_width * (bin), hist_height - cvRound(histogram[channel + histIndex].at<float>(bin))),
					Scalar(0, 0, 0),
					2, 8, 0);


		hconcat(img, 3, out);

	}

public:

	VideoHistogram(const string filename) {

		cap.open(filename);
		frame_timing = 0;

		#ifdef DEBUG
		// Check if camera opened successfully
		if (!cap.isOpened()) {
			cout << "Error opening video stream or file" << endl;
			return -1;
		}
		#endif
	}

	

	void setFrameTime(int hours = 0, int mins = 0, int secs = 0, int millisec = 0) {
		frame_timing = millisec + (secs + mins * 60 + hours * 60 * 60) * 1000; // get in milliseconds
	}

	void displayFrame() {
		
		cap.set(CAP_PROP_POS_MSEC, frame_timing);
		cap >> selected_frame;

		imshow("frame at " + to_string(frame_timing) + " milliseconds", selected_frame);

		imwrite("selected_frame.jpg",selected_frame);

		display_channels();

	}


	void display_channels() {
		
		_convert_and_split();

		_merge();

		imshow("3*3 Images - channels ", channelMergeFrame);

		imwrite("channelMergeFrame.jpg", channelMergeFrame);

	}


	void display_histograms() {
		

		Mat temp[3];

		_computeHistogram(rgb_channels, temp[0], 0); // computes histograms and merge into temp[0] vertically 
		_computeHistogram(hsv_channels, temp[1], 3);
		_computeHistogram(lab_channels, temp[2], 6);

		vconcat(temp, 3, hist_frame);

		imshow("hist frame", hist_frame);
		imwrite("hist_frame.jpg", hist_frame);

	}

	void playVideo() {

		while (1) {
		
			// Capture frame-by-frame
			cap >> frame;

			// If the frame is empty, break immediately
			if (frame.empty())
				break;

			// Display the resulting frame
			imshow("Frame", frame);


			// Press  ESC on keyboard to exit
			char c = (char)waitKey(25);
			if (c == 27)
				break;
		}
	}
};





int main() {

	// I just have renamed the file that you had uploaded on Teams
	VideoHistogram obj("rename.mp4");

	//obj.playVideo();

	obj.setFrameTime(0, 2, 20);

	obj.displayFrame();

	obj.display_channels();
	obj.display_histograms();

	waitKey();
	return 0;
}

