#pragma once

// generrating sqesuqence with saving prev data... 
// so first time it's 0, 1, 2, 


class GenerateSequence {
	int current = 0;

public:
	int operator () () { return current++;  }
};