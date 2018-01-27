#include "lexer.ih"

Mat Lexer::filterNoise()
{	
    // down-scale and upscale the image to filter out the noise
	Mat img_filtered;
    Mat img_downscaled;
    pyrDown(d_inputImage, img_downscaled, Size(d_inputImage.cols/2, d_inputImage.rows/2));

    pyrUp(img_downscaled, img_filtered, d_inputImage.size());

    return img_filtered; //return by reference impossible?
}
