#include "lexer.ih"

Lexer::Lexer()
{
	//TODO: pass argv?
	Magick::InitializeMagick(""); //InitializeMagick(*argv)(?)
}
