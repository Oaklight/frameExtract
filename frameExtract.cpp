// #include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
// #include "opencv2/highgui/highgui.hpp"
// #include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <string>
#include <cstdio>

using namespace cv;
using namespace std;

vector<Mat*> framesBuffer;

int main(int argc, char** argv) {
    if(argc != 3){
        printf("\nUsage: ./frameExtract [Path/to/input/video] [Path/to/output/folder]\n\n");
        return -1;
    }

    VideoCapture cap(argv[1]); // open the video camera no. 0

    if (!cap.isOpened()) { printf("ERROR INITIALIZING VIDEO CAPTURE\n" ); return -1; }// if not success, exit program

    int total_frames = cap.get(CV_CAP_PROP_FRAME_COUNT);
    printf("\ntotal frames: %d\nPlease enter cut interval: \n",total_frames);
    int interval;
    scanf("%d", &interval);
    for (int i = 0; i < total_frames; ++i) {
        Mat inputFrame;
        if (!cap.read(inputFrame)) { printf("ERROR READING FRAME or finished\n" ); break; }
        else if ( !(i%interval) && inputFrame.cols != 0 && inputFrame.rows != 0 ) {
            char buffer [50];
            sprintf (buffer, "%ld_%d.jpg", time(NULL), i);
            string tmp(buffer);
            string strPath = argv[2] + tmp;
            cout << strPath << endl;
            imwrite(strPath, inputFrame);
        }
    }

    return 0;

}
