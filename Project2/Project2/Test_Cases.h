#ifndef TEST_CASES_H
#define TEST_CASES_H

#include "Functions.h"

using namespace std;

void Encode_Test1(Morse_Tree& morse_tree)
{	// Test 1: lyrics from Weird Al Yankovich's 'Albuqurque'
	encode_string("I said to my mom\nI said, \"Hey, mom, what's up with all the sauerkraut?\""
		"\nAnd my dear, sweet mother She just looked at me like a cow looks at an oncoming train\n"
		"And she leaned right down next to me\nAnd she said \"It\'s good for you!\"", morse_tree);
	cout << endl;
}


void Encode_Test2(Morse_Tree& morse_tree)
{	// Test 2: 3 sentences each containing the 26 unique characters of English alphabet
	encode_string("The quick brown fox jumps over the lazy dog\n"
		"pack my box with five dozen liquor jugs\n"
		"jackdaws love my big sphinx of quartz", morse_tree);
	cout << endl;
}


void Encode_Test3(Morse_Tree& morse_tree)
{	// Test 3: excerpt from Edgar Allen Poe's 'Eldorado'
	encode_string("Gaily bedight\nA gallant knight\nIn sunshine and in shadow\n"
		"Had journeyed long\nSinging a song\nIn search of Eldorado", morse_tree);;
	cout << endl;
}


void Decode_Test1(Morse_Tree& morse_tree)
{	// Test 1: 90's pop culture reference for your everyday millenial
	decode_string(".__ .... . ._. .  .. _.  _ .... .  .__ ___ ._. ._.. _..  "
		".. ...  _._. ._ ._. __ . _.  ... ._ _. _.. .. . __. ___", morse_tree);
	cout << endl;
}


void Decode_Test2(Morse_Tree& morse_tree)
{	// Test 2: Famous line from one of Anthony Hopkins' best known roles
	decode_string("._  _._. . _. ... .._ ...  _ ._ _._ . ._.  ___ _. _._. .  "
		"_ ._. .. . _..  _ ___  _ . ... _  __ .\n"
		"..  ._ _ .  .... .. ...  ._.. .. ..._ . ._.  .__ .. _ ....  ... ___ "
		"__ .  .._. ._ ..._ ._  _... . ._ _. ...  ._ _. _..  ._  _. .. _._. .  "
		"_._. .... .. ._ _. _ ..", morse_tree);
	cout << endl;
}


void Decode_Test3(Morse_Tree& morse_tree)
{	// Test 3: Indeed, we are now in Missouri.
	decode_string("..  ..._ .  ._  .._. . . ._.. .. _. __.  .__ .  ._. .  _. "
		"___ _  .. _.  _._ ._ _. ... ._ ...  ._ _. _.__  __ ___ ._. .", morse_tree);
	cout << endl;
}


void Encode_Decode_Test(string user_string, Morse_Tree& morse_tree)
{	// encodes input string then decodes back to show user if translation worked correctly both ways
	cout << "_____________________________" << endl << endl;
	cout << "  Translation accuracy test" << endl << endl;
	cout << "(encodes a string into morse" << endl;
	cout << "    and decodes it back)" << endl;
	cout << "_____________________________" << endl << endl;
	cout << "Test string:\n--------------" << endl << user_string << endl << endl;

	user_string = encoder(user_string, morse_tree);
	cout << "Encoded Message:\n--------------" << endl << user_string << endl << endl;

	user_string = decoder(user_string, morse_tree);
	cout << "Decoded\n--------------" << endl << user_string << endl << endl;
}


void Test_All(string user_string, Morse_Tree& morse_tree)
{	// tests 9 cases, including 2 file reads and 7 different translations
	cout << "_____________________________" << endl << endl << "         "
		"Test Cases:" << endl << "_____________________________" << endl << endl;
	
	encode_from_file("text_to_encode.txt", morse_tree);
	cout << endl;
	decode_from_file("text_to_decode.txt", morse_tree);
	
	Encode_Test1(morse_tree);
	Encode_Test2(morse_tree);
	Encode_Test3(morse_tree);

	Decode_Test1(morse_tree);
	Decode_Test2(morse_tree);
	Decode_Test3(morse_tree);

	// call function using input from source.cpp
	Encode_Decode_Test(user_string, morse_tree); 
}
#endif