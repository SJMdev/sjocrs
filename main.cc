#include "sjocrs.ih"
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <Magick++.h> 

//not necessary:
#include <string>
#include <vector>

//opencv:
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;

using namespace Magick;

using namespace cv;

int main(int argc, char **argv)
{
	//instantiate lexer
	// Lexer lexer;


	//--------------------OPENCV-------------------------------

	Mat img_rgb = imread("images/kruidvat/no32norm.jpg");
	Mat img_gray;

    cvtColor(img_rgb,img_gray,CV_RGB2GRAY); //greyscaling


    imshow("InputImage",img_rgb);
    waitKey(0);

    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    
    Mat canny_output;
    int thresh = 100;
    Canny( img_gray, canny_output, thresh, thresh*2, 3);
    namedWindow("Canny",WINDOW_NORMAL);
    resizeWindow("Canny",600,600);
    imshow("Canny",canny_output);
    waitKey(0);
 //    drawStuff();


	//--------------------IMAGEMAGICK-------------------------------


	InitializeMagick(*argv);

	// Construct the image object. Separating image construction from the 
  	// the read operation ensures that a failure to read the image file 
  	// doesn't render the image object useless. 
	Image image;
	image.read( "images/kruidvat/no32norm.jpg" );;

	//wat doet dit?
	image.compressType(JPEGCompression);

	//helpt dit?
	// image.sharpen(3);

	image.write("images/kruidvat/no32norm.tif");



    //--------------------TESSERACT-------------

	tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();


	//open input image with leptonica library
	  if (api->Init(NULL, "nld")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }

    //only use alphanumeric!

    api->SetVariable("tessedit_char_whitelist","abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ");


	Pix *tiffImage = pixRead("images/kruidvat/no32norm.tif");

    api->SetImage(tiffImage);

    //--------------BINARIZATION------------------
    // api->SetImage(api->GetThresholdedImage());



    //output text
    string outText = api->GetUTF8Text();
    cout << outText;
    //-------------------------------------------------


	// destroy used object, release memory:

	api->End();
    pixDestroy(&tiffImage);

}
