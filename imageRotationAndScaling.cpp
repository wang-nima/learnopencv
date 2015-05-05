#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;

Mat imgOriginal;
int iAngle = 0;
int scale = 100;
int iImageHieght;
int iImageWidth;
const char* pzRotatedImage = "New Image";

void rotate(int, void*) {
	Mat matRotation = getRotationMatrix2D( Point(iImageWidth, iImageHieght), iAngle , scale/100.0 );
	Mat imgRotated;
	warpAffine( imgOriginal, imgRotated, matRotation, imgOriginal.size() );
	imshow( pzRotatedImage, imgRotated );
}

int main( int argc, char** argv )
{
	// Load the image
	imgOriginal = imread( "MyPic.JPG", 1 );
	
	 //show the original image
	const char* pzOriginalImage = "Original Image";
	namedWindow( pzOriginalImage, CV_WINDOW_AUTOSIZE );
	iImageHieght = imgOriginal.rows / 2;
	iImageWidth = imgOriginal.cols / 2;
	imshow( pzOriginalImage, imgOriginal );
	
	namedWindow( pzRotatedImage, CV_WINDOW_AUTOSIZE );
	
	createTrackbar("Angle", pzRotatedImage, &iAngle, 360, rotate);
	createTrackbar("Scale", pzRotatedImage, &scale, 100, rotate);
	

	// Rotate the image

	// wait esc for exit
	waitKey(0);
	return 0;
}
