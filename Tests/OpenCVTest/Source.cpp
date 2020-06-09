#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	//Show Image
	Mat img = imread("lena.jpg");
	if (img.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return -1;
	}
	namedWindow("image", WINDOW_NORMAL);
	imshow("image", img);
	waitKey(0);
	destroyWindow("image");

	//Create frame with color;

	Mat image(600, 800, CV_8UC3, Scalar(100, 250, 30));
	String windowName = "Window with Blank Image";
	namedWindow(windowName);
	imshow(windowName, image);
	waitKey(0);
	destroyWindow(windowName);
	//Play Video

	//cap(0) passes as parameter the integrated webcam of a computer in this case my laptop!
	VideoCapture cap(0);

	if (cap.isOpened() == false)
	{
		cout << "Cannot open the video file" << endl;
		cin.get(); //wait for any key press
		return -1;
	}
	double dWidth = cap.get(CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
	double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

	cout << "Resolution of the video : " << dWidth << " x " << dHeight << endl;

	double fps = cap.get(CAP_PROP_FPS);
	cout << "Frames per second " << fps << endl;

	String window_name = "Video";
	
	namedWindow(window_name, WINDOW_NORMAL);

	while (true) 
	{
		Mat frame;
		bool bSucces = cap.read(frame);
		if (bSucces == false)
		{
			cout << "Video camera is disconnected" << endl;
			cin.get();
			break;
		}
		imshow(window_name, frame);
		/*
		* wait for1- ms until key is pressed
		* If Esc is pressed breaks the while loop
		* If the any other key is pressed, continue the loop 
		* If any key is not pressed withing 10 ms, continue the loop
		*/
		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Stoppig the video" << endl;
			break;
		}
	}
	return 0;
}
