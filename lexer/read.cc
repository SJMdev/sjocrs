#include "lexer.ih"

void Lexer::read(string filename)
{
	//TODO: infer filetype?
	d_inputImage = imread(filename);	
}