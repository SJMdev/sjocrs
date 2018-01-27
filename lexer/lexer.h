#ifndef INCLUDED_LEXER_
#define INCLUDED_LEXER_
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <Magick++.h> 
#include <string>


class Lexer
{
	tesseract::TessBaseAPI *d_api;
	Image d_image;
	std::string d_filename;


    public:
    	Lexer();
    	void read(std::string filename);
    	void sharpen(size_t intensity);
    	void toTIF();
    private:

};
        
#endif
