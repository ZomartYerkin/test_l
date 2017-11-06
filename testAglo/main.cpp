#include "Concatenate.h"
#include "GenerateSequence.h"
#include "Rolldice.h"
#include "Containsubstring.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>


using namespace std;

int main() {

	// accumulate -- sums all the elements in the container
	// generate -- filling container by numbers from generator
	// sums all the string called concatenate

	vector<int> ints = { 1, 2, 3, 4 };
	vector<string> strings = { "Hello", ", ", "world", "!" };

	cout << "Sum =" << accumulate (ints.begin(), ints.end(), 0) << endl; // 0 + first element, + second and so on.. for multiplying better put 1.


	// conctenate() - neizmenjaemij, bez dannyx same as Rolldice and GenerateSeq
	cout << "Concate = " << accumulate(strings.begin(), strings.end(), " "s, Concatenate()) << endl; // Concatenate() - is just one time object noname

	generate(ints.begin(), ints.end(), Rolldice()); // same as Concatenate temporary noname object

	copy(ints.begin(), ints.end(), ostream_iterator<int>(cout, " ")); // copy gives numbers to ostream_iterator as int with to_show as cout 

	cout << "\n" << endl;

	generate(ints.begin(), ints.end(), GenerateSequence());
	copy(ints.begin(), ints.end(), ostream_iterator<int>(cout, " "));

	cout << "\n" << endl;

	// find - is looking for element in colleciton // kind of useless, because we're looking for actual rules, "like find all elements that meets certain criterias"
	// find_if is the one that looks for certain criteria

	find_if(strings.begin(), strings.end(), Containsubstring("or"));
	// find will return link not actual thing

	auto found = find_if(strings.begin(), strings.end(), Containsubstring("or"));

	// checking if find found just anything... so show end! that you suka made it
	if (found == strings.end())
		cout << "Not found!";
	else
		cout << "Found: " << *found << endl; // *found -razimenovanie iteratora!!! found

	cout << "\n" << endl;
}