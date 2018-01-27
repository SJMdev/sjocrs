#include "lexer.ih"

void Lexer::read(string filename)
{
	//TODO: infer filetype?
	d_image.read(filename);

	//remove file extension from string? for TIF?
	d_filename = filename;

}