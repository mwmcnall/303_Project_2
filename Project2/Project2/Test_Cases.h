#ifndef TEST_CASES_H
#define TEST_CASES_H

#include "Functions.h"

using namespace std;


void Decode_Test1(map <string, string> decode_map)
{
	decode_string("_.. ._. .. _. _._  __ ___", decode_map);
	cout << endl;
}

void Decode_Test2(map <string, string> decode_map)
{
	cout << endl;
}

void Decode_Test3(map <string, string> decode_map)
{
	
	cout << endl;
}

void Encode_Test1(map <string, string> encode_map)
{
	encode_string("I said to my mom/I said, Hey, mom, what's up with all the sauerkraut?/And my dear, sweet mother She just looked at me like a cow looks at an oncoming train/And she leaned right down next to me/And she said Its good for you", decode_map);
	cout << endl;
}

void Encode_Test2(map <string, string> encode_map)
{
	encode_string("The quick brown fox jumps over the lazy dog\npack my box with five dozen liquor jugs\njackdaws love my big sphinx of quartz", encode_map);
	cout << endl;
}

void Encode_Test3(map <string, string> encode_map)
{
	cout << "Test";
	cout << endl;
}

void Test_All(map <string, string> decode_map, map <string, string> encode_map)
{
	cout << "The big test:" << endl << "_____________________________" << endl;
	
	Decode_Test1(decode_map);
	Decode_Test2(decode_map);
	Decode_Test3(decode_map);
	Encode_Test1(encode_map);
	Encode_Test2(encode_map);
	Encode_Test3(encode_map);
}
#endif