#include "lexer.ih"

void Lexer::showContours()
{
	Mat d_gray;

	cvtColor(d_inputImage,d_gray,CV_RGB2GRAY); //convert to grayscale

	vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    
    Mat canny_output;
    int thresh = 100;
    Canny( d_gray, canny_output, thresh, thresh*2, 3);
    namedWindow("Canny",WINDOW_NORMAL);
    resizeWindow("Canny",600,600);
    imshow("Canny",canny_output);
    waitKey(0);
}