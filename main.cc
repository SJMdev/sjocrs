#include "sjocrs.ih"
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <Magick++.h> 
//not necessary:
#include <string>
#include <vector>

using namespace std;

using namespace Magick;


int main(int argc, char **argv)
{
	//instantiate lexer

	Lexer lexer;

	tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();

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


	//open input image with leptonica library
	  if (api->Init(NULL, "nld")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }

    //only use alphanumeric!

    api->SetVariable("tessedit_char_whitelist","abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    //------------------------------------------------
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



	// std::string test = "test.txt";

	// lexer.scan(test);



}