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


template<class Container, class T = Container::value_type>

void print(const Container &collection) {
	copy(collection.begin(), collection.end(), ostream_iterator<T>(cout, " "));
	cout << endl;
}

/*
// is it Capital letter or not!
bool my_isuppercase(char c) {
	return (c);

}
*/

// writign predicat 

bool isVowel(char c) {
	// return c == 'a' || c == 'b'... chtobi vse ne pisat'

	static const string vowels = "aeiouy";
	return vowels.find(tolower(c)) != string::npos; // tolower - prevratit' v malen'kuju 
	
	// sozdadim static chobi ispol'zovat' ee v funcii ona ne umret s vixodom programi
}



int main() {

	// accumulate -- sums all the elements in the container
	// generate -- filling container by numbers from generator
	// sums all the string called concatenate

	vector<int> ints = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12  };
	vector<string> strings = { "Hello", ", ", "world", "!" };

	cout << "Sum =" << accumulate (ints.begin(), ints.end(), 0) << endl; // 0 + first element, + second and so on.. for multiplying better put 1.


	// conctenate() - neizmenjaemij, bez dannyx same as Rolldice and GenerateSeq
	cout << "Concate = " << accumulate(strings.begin(), strings.end(), " "s, Concatenate()) << endl; // Concatenate() - is just one time object noname

	generate(ints.begin(), ints.end(), Rolldice()); // same as Concatenate temporary noname object

	print(ints); // copy gives numbers to ostream_iterator as int with to_show as cout 

	cout << "\n" << endl;

	generate(ints.begin(), ints.end(), GenerateSequence());
	print(ints);

	cout << "\n" << endl;

	// find - is looking for element in colleciton // kind of useless, because we're looking for actual rules, "like find all elements that meets certain criterias"
	// find_if is the one that looks for certain criteria

	//	find_if(strings.begin(), strings.end(), Containsubstring("or"));
	// find will return link not actual thing

	find_if(strings.begin(), strings.end(), Containsubstring("or"));
	auto found = find_if(strings.begin(), strings.end(), [](const string &word) {return word.find("or") != string::npos; });
	

	// checking if find found just anything... so show end! that you suka made it
	if (found == strings.end())
		cout << "Not found! bitches bitches bitches";
	else
		cout << "Found: bitches bitches bitches " << *found << endl; // *found -razimenovanie iteratora!!! found

	cout << "\n" << endl;

	auto last = remove(ints.begin(), ints.end(), 2); // 1 - remove deletes 1 -element - adding auto because vector returns ITERATOR
	




	print(ints);

	cout << "\n" << endl;
	ints.erase(last, ints.end());

	cout << "\n" << endl;
	print(ints);




	string word = "Hello";

	cout << "\n" << endl;

	if (all_of(word.begin(), word.end(), isupper)) // isupper predicat  t.e. ukazatel' na funciju
		cout << "All Capitals" << endl;
	else
		cout << "not all capitals" << endl;

	cout << "\n" << endl;

	if (any_of (word.begin(), word.end(), isupper)) // isupper predicat  t.e. ukazatel' na funciju
		cout << "Some Capitals" << endl;
	else
		cout << "no capitals at ALL" << endl;

	cout << "\n" << endl;
	
	cout << "lower= " << count_if(word.begin(), word.end(), islower) << endl;
	cout << "vowel= " << count_if(word.begin(), word.end(), isVowel) << endl;






	// [] (const string &x, const string &y) { return x + y; }) sozdat' ODNORAZOVUJU FUNCIU s takim dannymi i s takimi parametrami
	// use of ljamda is good, because you can do all at the same line as you needed no need to go to the beginning or class
	// [ zaxvaty ] (int x, int y) - parametry, ---->bool (type of return), {return ....is body or telo of ljamda }


	cout << "Sum =" << accumulate(ints.begin(), ints.end(), 1, [] (int x, int y) {return x*y; }) << endl;
																			
	cout << "Concate = " << accumulate(strings.begin(), strings.end(), " "s, [] (const string &x, const string &y) { return x + y; }) << endl;

	generate(ints.begin(), ints.end(), [] { return rand() % 6 + 1; }); // same as Concatenate temporary noname object

	print(ints); // copy gives numbers to ostream_iterator as int with to_show as cout 

	cout << "\n" << endl;


	// for generateSequences we will need zaxvaty ili Closure ili Zamykanija [] so before that we need to arrange zone of closure [ ]
	
	int next = 1;
	generate(ints.begin(), ints.end(), [&next] {return next++; } );
	print(ints);

	cout << "\n" << endl;


	cout << word.max_size() << endl;

	// for each do something special
	for_each(ints.begin(), ints.end(), [](int n) { cout << n*2 << ' ';  }); 

	for_each(word.begin(), word.end(), [](char &c) { c = toupper(c);  }); 
	cout << word << endl;

	print(word);

	// transform colleciton: and each element replace with something, working with functor and lambda
	vector<string> intsAsNumbers;
	// back_inserter () - kuda dobavljat' v konec, eto object, kotoryi
	// rules of conversion from "int" to "string"
	transform(ints.begin(), ints.end(), back_inserter(intsAsNumbers), [](int n) {return '"' + to_string(n) + '"';  }); // return to_string.. zapisivaet v back_inserter
	// returning iterator pointing at na sledujushhuu poziciju za strokoi... so pointing at the end of the string +1. 
	
	print(intsAsNumbers);

	// removing all unique elements


	string::iterator newEnd = unique(word.begin(), word.end());
	//word.erase(newEnd, word.end());
	cout << word << endl;
}