#pragma once
#include <stdlib.h>

// functor-generator 
// not taking any data, but returning some data
// ( ) proshe vernut' celie chisla -> int

class Rolldice {
public:
	int operator () () const { return rand() % 6 + 1;  }
};