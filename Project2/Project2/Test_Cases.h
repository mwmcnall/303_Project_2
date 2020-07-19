#ifndef TEST_CASES_H
#define TEST_CASES_H

#include "Functions.h"

using namespace std;


void Encode_Test1(map <string, string> encode_map)
{
	encode_string("I said to my mom\nI said, \"Hey, mom, what's up with all the sauerkraut?\"\nAnd my dear, sweet mother She just looked at me like a cow looks at an oncoming train\nAnd she leaned right down next to me\nAnd she said \"It\'s good for you!\"", encode_map);
	cout << endl;
}

void Encode_Test2(map <string, string> encode_map)
{
	encode_string("The quick brown fox jumps over the lazy dog\npack my box with five dozen liquor jugs\njackdaws love my big sphinx of quartz", encode_map);
	cout << endl;
}

void Encode_Test3(map <string, string> encode_map)
{
	encode_string("Gaily bedight\nA gallant knight\nIn sunshine and in shadow\nHad journeyed long\nSinging a song\nIn search of Eldorado", encode_map);;
	cout << endl;
}

void Decode_Test1(map <string, string> decode_map)
{
	decode_string("_.. ._. .. _. _._  __ ___ ._. .  ___ ..._ ._ ._.. _ .. _. .\n_... .. _ _._. ....", decode_map);
	cout << endl;
}

void Decode_Test2(map <string, string> decode_map)
{
	decode_string("._  _._. . _. ... .._ ...  _ ._ _._ . ._.  ___ _. _._. .  _ ._. .. . _..  _ ___  _ . ... _  __ .\n..  ._ _ .  .... .. ...  ._.. .. ..._ . ._.  .__ .. _ ....  ... ___ __ .  .._. ._ ..._ ._  _... . ._ _. ...  ._ _. _..  ._  _. .. _._. .  _._. .... .. ._ _. _ ..", decode_map);
	cout << endl;
}

void Decode_Test3(map <string, string> decode_map)
{
	decode_string("..  ..._ .  ._  .._. . . ._.. .. _. __.  .__ .  ._. .  _. ___ _  .. _.  _._ ._ _. ... ._ ...  ._ _. _.__  __ ___ ._. .", decode_map);
	cout << endl;
}

void Encode_Decode_Test(map <string, string> encode_map, map <string, string> decode_map)
{
	string user_string = "I ate a big red candle.";

	cout << "Question: How accurate is the encoder/decoder?" << endl << endl;
	cout << "Test string: " << user_string << endl;

	user_string = encode_string_short(user_string, encode_map);
	cout << "Encoded:     " << user_string << endl;

	user_string = decode_string_short(user_string, decode_map);
	cout << "Decoded:     " << user_string << endl << endl;
}

void Test_All(map <string, string> decode_map, map <string, string> encode_map)
{
	cout << "_____________________________" << endl << endl << "         Test Cases:" << endl << "_____________________________" << endl << endl;
	
	Encode_Test1(encode_map);
	Encode_Test2(encode_map);
	Encode_Test3(encode_map);

	Decode_Test1(decode_map);
	Decode_Test2(decode_map);
	Decode_Test3(decode_map);

	Encode_Decode_Test(encode_map, decode_map);
}
#endif