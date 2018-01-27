#include "lexer.ih"

void Lexer::findRect(vector<vector<Point> >& squares)
{
	int thresh = 50, N = 11; //where do we keep this?

	squares.clear();

    Mat img_filtered = filterNoise();    //need to downscale and then filter

 

    Mat gray0(d_inputImage.size(), CV_8U); //?
    Mat gray; //?


    vector<vector<Point>> contours;
    // find squares in every color plane of the image
    for (int c = 0; c < 3; c++) //needs to be int for the mixChannels
    {
        int ch[] = {c, 0};
        mixChannels(&img_filtered, 1, &gray0, 1, ch, 1);

        // try several threshold levels
        for( int l = 0; l < N; l++ )
        {
            // hack: use Canny instead of zero threshold level.
            // Canny helps to catch squares with gradient shading
            if( l == 0 )
            {
                // apply Canny. Take the upper threshold from slider
                // and set the lower to 0 (which forces edges merging)
                Canny(gray0, gray, 0, thresh, 5);
                // dilate canny output to remove potential
                // holes between edge segments
                dilate(gray, gray, Mat(), Point(-1,-1));
            }
            else
            {
                // apply threshold if l!=0:
                //     tgray(x,y) = gray(x,y) < (l+1)*255/N ? 255 : 0
                gray = gray0 >= (l+1)*255/N;
            }

            // find contours and store them all as a list
            findContours(gray, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);

            // test each contour
            testContours(contours,squares);
        }
    }
}