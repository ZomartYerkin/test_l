#pragma once


#include <string>
using std::string;


// functor is the one connecting 2 strings
// string + string = new string
// functor is sometimes called "verb"

class Concatenate {
public:
	string operator () (const string &left, const string &right) const
	{
		return left + right; 
	}

};