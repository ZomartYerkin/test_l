#pragma once
#include <string>

using std::string;

// workign on one string
// return true, if "entering" strings contains "substring"


class Containsubstring {
	
	string m_substring;

public:
	Containsubstring(const string &substring) : m_substring(substring) { } // m_substring copied from (substring)

	bool operator () (const string &mainString) const
	{
		// find -checking both Capital letters and small ones --------> we will need to change all letters to small letters!
		return mainString.find(m_substring) != string::npos; // npos - in class string shows if there is nothing found! shows all 111111, or -1 or negative position
	}
};