#include "lexer.ih"

Lexer::Lexer()
: 
	d_api(new tesseract::TessBaseAPI())
{
	//TODO: pass argv?
	Magick::InitializeMagick(""); //InitializeMagick(*argv)
}
