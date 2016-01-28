#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

// Strings define
String face_cascade_name = "/home/cer/faceRecognization_opencv/database/haarcascades/haarcascade_frontalface_alt.xml";
String eyes_cascade_name = "/home/cer/faceRecognization_opencv/database/haarcascades/haarcascade_eye_tree_eyeglasses.xml";
String save_directory = "/home/cer/faceRecognization_opencv/database/test_mod/cropedImage.jpg";
string window_name = "Capture - Face detection";

//Cascade classifier
CascadeClassifier face_cascade;

RNG rng(12345);

int main( int argc, char** argv )
{
	//Check cascade file
	if( !face_cascade.load( face_cascade_name ) ){
		printf("--(!)Error loading\n");
		return -1;
	}

	//Load the image fom argument
	char* imageName = argv[1];
	Mat image;
	image = imread( imageName, 1 );

	//Check image file
	if( argc != 2 || !image.data )
	{
	  printf( " No image data \n " );
	  return -1;
	}

	//Detect the face and cut it
	if( !image.empty() ){
		std::vector<Rect> faces;
		Mat frame_gray;
		Mat cropedImage;

		cvtColor( image, frame_gray, CV_BGR2GRAY );
		equalizeHist( frame_gray, frame_gray );

		face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );

		for( size_t i = 0; i < faces.size(); i++ )
		{
		cropedImage = frame_gray(Rect(faces[i].x,faces[i].y,faces[i].width,faces[i].height));

		imwrite( save_directory, cropedImage );
		}
		imshow( window_name, cropedImage );
		waitKey(0);
	}
	else{
		printf(" --(!) No captured image -- Break!");
	}
  return 0;
}
