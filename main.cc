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
	string filename = "images/kruidvat/test.jpg";

	Lexer lexer;

	lexer.read(filename);

	vector<vector<Point>> rects;

	lexer.findRect(rects);

	lexer.drawRect(rects);

}
