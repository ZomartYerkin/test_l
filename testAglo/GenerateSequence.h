#pragma once

// generrating sqesuqence with saving prev data... 
// so first time it's 0, 1, 2, 


class GenerateSequence {
	int current = 1; // changed from 0 to 1 for multiplying

public:
	int operator () () { return current++;  }
};