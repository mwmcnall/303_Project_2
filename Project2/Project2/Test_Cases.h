#ifndef TEST_CASES_H
#define TEST_CASES_H

#include "Functions.h"

using namespace std;


void Encode_Test1(map <string, string> encode_map)
{
	encode_string("I said to my mom\nI said, Hey, mom, what's up with all the sauerkraut?\nAnd my dear, sweet mother She just looked at me like a cow looks at an oncoming train\nAnd she leaned right down next to me\nAnd she said Its good for you", encode_map);
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

void Decode_Test1(map <string, string> decode_map)
{
	decode_string("_.. ._. .. _. _._  __ ___ ._. .  ___ ..._ ._ ._.. _ .. _. .\n_... .. _ _._. ....", decode_map);
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

void Test_All(map <string, string> decode_map, map <string, string> encode_map)
{
	cout << "Test Cases:" << endl << "_____________________________" << endl << endl;
	
	Encode_Test1(encode_map);
	Encode_Test2(encode_map);
	Encode_Test3(encode_map);

	Decode_Test1(decode_map);
	Decode_Test2(decode_map);
	Decode_Test3(decode_map);
}
#endif