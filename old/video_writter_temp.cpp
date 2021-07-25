#include "opencv2/opencv.hpp"
#include <iostream>
#include <time.h>

using namespace std;
using namespace cv;


//# define VIEW_FRAME

/*

uncomment the define VIEW_FRAME, to calculate fps when viweing frame

Since if block is compile time, performace will be not effected

*/


int main() {

    // Create a VideoCapture object and open the input file
    // If the input is the web camera, pass 0 instead of the video file name
    VideoCapture cap("rename.mp4");

    // Check if camera opened successfully
    if (!cap.isOpened()) {
        cout << "Error opening video stream or file" << endl;
        return -1;
    }

    Mat frame;

    int frameCounter = 0, frameLimit = 99; // 100 frame (0 - 99)

    // Start and end times
    time_t starttime, endtime;

    while (1) {
        
        if (!frameCounter) {
            // Start time
            time(&starttime);
        }

        // Capture frame-by-frame
        cap >> frame;

        // If the frame is empty, break immediately
        if (frame.empty())
            break;

        #ifdef VIEW_FRAME

        //if VIEW_FRAME is defined
        //show frame and calculate fps 
        //else vice versa

        // Display the resulting frame
        imshow("Frame", frame);

        #endif

        frameCounter++;

        if (frameCounter == frameLimit) {
            // End Time
            time(&endtime);
            frameCounter = 0;

            cout << "Frames per second fps : " << frameLimit / difftime(endtime, starttime) << endl;
        }


        // Press  ESC on keyboard to exit
        char c = (char)waitKey(25);
        if (c == 27)
            break;
    }

    // When everything done, release the video capture object
    cap.release();

    // Closes all the frames
    destroyAllWindows();

    return 0;
}



/*

After comparing the speed with and without displaying the frames we notice that the fps is low when we read and display the frame

Reason : IO operations are quite expensive

Conclusion : Prefetch frames and then display (using buffer or other techniques)

*/