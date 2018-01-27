#include "lexer.ih"
//sharpen can use values 0,1,2,3.

void Lexer::sharpen(size_t intensity)
{
	d_image.sharpen(intensity);
}