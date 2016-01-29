/**
Copyright [2016] [Hoi "Nagas" Nguyen]

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>
//#include <limits.h>
//#include <unistd.h>

using namespace std;
using namespace cv;

char* image_name;
char* save_to;
string window_name = "Capture - Face detection";
const char* relative_path = "/database/haarcascades/haarcascade_frontalface_alt.xml";

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
	char* cascades_path;
	cascades_path = std::getenv("DRACO_PATH") ;
        std::cout << "Your PATH is: " << cascades_path << '\n';
	strcat (cascades_path , relative_path);
        std::cout << "Your NEW PATH is: " << cascades_path << '\n';
	if( !face_cascade.load( cascades_path ) ){
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

	//Cut each face and save to the new place
	for( size_t i = 0; i < faces.size(); i++ ){
		cropped_img = gray_img(Rect(faces[i].x,faces[i].y,faces[i].width,faces[i].height));
		imwrite( save_to, cropped_img );
	}

	//Show the face, comment if want to run quietly
	//The window is closed after any keystroke
	//imshow( "LALA", cropped_img );
	//waitKey(0);

	printf("Cropped image saved to %s.\n",save_to);
	
	return 0;
}
