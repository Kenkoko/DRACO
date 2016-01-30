#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

String face_cascade_name = "/home/cer/faceRecognization_opencv/database/haarcascades/haarcascade_frontalface_alt.xml";
char* image_name;
char* save_to;
string window_name = "Capture - Face detection";

std::vector<Rect> faces;
Mat image;
Mat gray_img;
Mat cropped_img;

CascadeClassifier face_cascade;

RNG rng(12345);

int main( int argc, char** argv )
{
	if( argc != 3 ){
		printf( "Usage: ./haar_detect <image> <file name to save to>\n " );
		return -1;
	}
	
	//Check cascade file
	if( !face_cascade.load( face_cascade_name ) ){
		printf("ERROR: Cannot load cascade file\n");
		return -1;
	}

	//Load the image fom argument
	image_name = argv[1];
	save_to = argv[2];
	image = imread( image_name, 1 );

	//Check image file
	if( !image.data || image.empty() ){
		printf( "No image data or image empty\n " );
		return -1;
	}

	//Convert to grayscale
	cvtColor( image, gray_img, CV_BGR2GRAY );
	equalizeHist( gray_img, gray_img );

	//Detect the face
	face_cascade.detectMultiScale( gray_img, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );

	if ( !faces.size() ){
		return 2;
	}
	else{
		//Cut each face and save to the new place
		for( size_t i = 0; i < faces.size(); i++ ){
			char* save_to_numbered = save_to;
			strcat(save_to_numbered, (const char*)i);	
			cropped_img = gray_img(Rect(faces[i].x,faces[i].y,faces[i].width,faces[i].height));
			imwrite( save_to_numbered, cropped_img );
		}
	}

	//Show the face, comment if want to run quietly
	//The window is closed after any keystroke
	imshow( window_name, cropped_img );
	waitKey(0);

	printf("Cropped image saved to %s.\n",save_to);
	
	return 0;
}
