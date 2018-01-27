#include "lexer.ih"

Lexer::~Lexer()
{
	delete d_api;
}