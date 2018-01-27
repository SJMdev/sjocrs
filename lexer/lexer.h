#ifndef INCLUDED_LEXER_
#define INCLUDED_LEXER_

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

#include <Magick++.h> 

#include <string>
#include <vector>

using namespace cv;

using namespace Magick;

using namespace std;//remove this


class Lexer
{
	Mat d_inputImage;
    Mat d_outputImage;

	std::string d_filename;


    public:
    	Lexer();
    	
    	~Lexer();
    	void read(std::string filename);
    	void sharpen(size_t intensity);
    	void toTIF();

        void findRect(vector<vector<Point> >& squares);

        void drawRect(const vector<vector<Point> >& squares);


        void showContours();

    private:
        //helper functions for findRect
        double angle(Point pt1, Point pt2, Point pt0);
        
        Mat filterNoise();

        void testContours(vector<vector<Point> > &contours,
                          vector<vector<Point> >& squares);



};
     
double inline Lexer::angle(Point pt1, Point pt2, Point pt0)
{
    double dx1 = pt1.x - pt0.x;
    double dy1 = pt1.y - pt0.y;
    double dx2 = pt2.x - pt0.x;
    double dy2 = pt2.y - pt0.y;
    return (dx1*dx2 + dy1*dy2)/
           sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
}   
#endif
