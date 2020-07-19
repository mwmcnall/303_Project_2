#ifndef TEST_CASES_H
#define TEST_CASES_H

#include "Functions.h"

using namespace std;


void Encode_Test1(map <string, string> encode_map)
{	// Test 1: lyrics from Weird Al Yankovich's 'Albuqurque'
	encode_string("I said to my mom\nI said, \"Hey, mom, what's up with all the sauerkraut?\"\nAnd my dear, sweet mother She just looked at me like a cow looks at an oncoming train\nAnd she leaned right down next to me\nAnd she said \"It\'s good for you!\"", encode_map);
	cout << endl;
}


void Encode_Test2(map <string, string> encode_map)
{	// Test 2: 3 sentences each containing the 26 unique characters of English alphabet
	encode_string("The quick brown fox jumps over the lazy dog\npack my box with five dozen liquor jugs\njackdaws love my big sphinx of quartz", encode_map);
	cout << endl;
}


void Encode_Test3(map <string, string> encode_map)
{	// Test 3: excerpt from Edgar Allen Poe's 'Eldorado'
	encode_string("Gaily bedight\nA gallant knight\nIn sunshine and in shadow\nHad journeyed long\nSinging a song\nIn search of Eldorado", encode_map);;
	cout << endl;
}


void Decode_Test1(map <string, string> decode_map)
{	// Test 1: 90's pop culture reference for your everyday millenial
	decode_string(".__ .... . ._. .  .. _.  _ .... .  .__ ___ ._. ._.. _..  .. ...  _._. ._ ._. __ . _.  ... ._ _. _.. .. . __. ___", decode_map);
	cout << endl;
}


void Decode_Test2(map <string, string> decode_map)
{	// Test 2: Famous line from one of Anthony Hopkins' best known roles
	decode_string("._  _._. . _. ... .._ ...  _ ._ _._ . ._.  ___ _. _._. .  _ ._. .. . _..  _ ___  _ . ... _  __ .\n..  ._ _ .  .... .. ...  ._.. .. ..._ . ._.  .__ .. _ ....  ... ___ __ .  .._. ._ ..._ ._  _... . ._ _. ...  ._ _. _..  ._  _. .. _._. .  _._. .... .. ._ _. _ ..", decode_map);
	cout << endl;
}


void Decode_Test3(map <string, string> decode_map)
{	// Test 3: Indeed, we are now in Missouri.
	decode_string("..  ..._ .  ._  .._. . . ._.. .. _. __.  .__ .  ._. .  _. ___ _  .. _.  _._ ._ _. ... ._ ...  ._ _. _.__  __ ___ ._. .", decode_map);
	cout << endl;
}


void Encode_Decode_Test(string user_string, map <string, string> encode_map, map <string, string> decode_map)
{	// encodes input string then decodes back to show user if translation worked correctly both ways
	cout << "_____________________________" << endl << endl;
	cout << "  Translation accuracy test" << endl << endl;
	cout << "(encodes a string into morse" << endl;
	cout << "    and decodes it back)" << endl;
	cout << "_____________________________" << endl << endl;
	cout << "Test string:\n--------------" << endl << user_string << endl << endl;

	user_string = encoder(user_string, encode_map);
	cout << "Encoded Message:\n--------------" << endl << user_string << endl << endl;

	user_string = decoder(user_string, decode_map);
	cout << "Decoded\n--------------" << endl << user_string << endl << endl;
}


void Test_All(string user_string, map <string, string> decode_map, map <string, string> encode_map)
{	// tests 9 cases, including 2 file reads and 7 different translations
	cout << "_____________________________" << endl << endl << "         Test Cases:" << endl << "_____________________________" << endl << endl;
	
	encode_from_file("text_to_encode.txt", encode_map);
	cout << endl;
	decode_from_file("text_to_decode.txt", decode_map);
	
	Encode_Test1(encode_map);
	Encode_Test2(encode_map);
	Encode_Test3(encode_map);

	Decode_Test1(decode_map);
	Decode_Test2(decode_map);
	Decode_Test3(decode_map);

	Encode_Decode_Test(user_string, encode_map, decode_map); // call function using input from source.cpp
}
#endif