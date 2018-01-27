#include "lexer.ih"

void Lexer::drawRect(const vector<vector<Point> >& squares)
{
    for( size_t i = 0; i < squares.size(); i++ )
    {
        const Point* p = &squares[i][0];
        int n = (int)squares[i].size();
        polylines(d_inputImage, &p, &n, 1, true, Scalar(0,255,0), 3, LINE_AA);
    }

    namedWindow("rectangles",WINDOW_NORMAL);
    resizeWindow("rectangles",600,600);
    imshow("rectangles",d_inputImage);
    waitKey(0);
}