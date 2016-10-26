#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv/ml.h>

#include <QImage>

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;


int main( int argc, const char** argv )
{
	VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    Mat edges;
    namedWindow("edges",1);
    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        cvtColor(frame, edges, CV_BGR2GRAY);
        GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        Canny(edges, edges, 0, 30, 3);
        imshow("edges", edges);

        if(waitKey(30) >= 0) break;
    }


/*
    Mat img = imread("/Users/jani/Desktop/Screen Shot 2016-10-21 at 15.54.01.png");

    QImage imgIn = QImage((uchar*) img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);

	namedWindow( "Display window" );// Create a window for display.
    imshow( "Display window", img );                   // Show our image inside it.
*/
    waitKey(0);

    return 0;
}
