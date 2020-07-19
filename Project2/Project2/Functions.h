#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Binary_Search_Tree.h"
#include "Binary_Tree.h"
#include<iostream>
#include<vector>
#include<string>
#include <fstream>
#include "Morse_Tree.h"
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;


void read_file_to_vec(vector<Morse_Letter>& morse_vec, string file_name) {  //Reads text from the morse file into a vector
	ifstream input_file(file_name);
	//vector<string> string_vec;
	string temp, temp_char, temp_code;
	//int temp_int;
	while (getline((input_file), temp)) {

		temp_char = temp[0];
		temp_code = temp.substr(1, string::npos);
		//temp_int = get_val(temp_code);
		Morse_Letter letter(temp_char, temp_code/*, temp_int*/);
		morse_vec.push_back(letter);
	}
	input_file.close();
}


void read_file_to_vec(vector<Morse_Letter>& morse_vec, string file_name, map<string, string>& letters_map_enc, map<string, string>& letters_map_dec) { // Also creates two maps for encoding and decoding.
	ifstream input_file(file_name);
	//vector<string> string_vec;
	string temp, temp_char, temp_code;
	//int temp_int;
	while (getline((input_file), temp)) {

		temp_char = temp[0];
		temp_code = temp.substr(1, string::npos);
		//temp_int = get_val(temp_code);
		letters_map_enc[temp_char] = temp_code;
		letters_map_dec[temp_code] = temp_char;
		Morse_Letter letter(temp_char, temp_code/*, temp_int*/);
		morse_vec.push_back(letter);
	}
	input_file.close();
}


string encoder(string dec_text, map<string, string> letters_map_enc) 
{	// returns encoded string, does not print by itself
	// useful for debugging
	string enc_text = "", temp = "";
	for (int i = 0; i < dec_text.size(); ++i) {
		char temp_char = dec_text[i];
		if (temp_char == '\n') {
			enc_text.append("\n");
		}
		else if (temp_char == ' ') enc_text.append(" ");
		else {
			string temp_string(1, tolower(temp_char));
			enc_text.append(letters_map_enc[temp_string]);
			enc_text.append(" ");
		}
	}
	return enc_text;
}


string decoder(string enc_text, map<string, string> letters_map_dec) 
{	// returns decoded string, does not print by itself
	// useful for debugging
	string dec_text = "", temp = "", temp_code = "";
	for (int i = 0; i < enc_text.size(); ++i) 
	{
		char temp_char = enc_text[i];
		if (temp_char == '\n') 
		{
			dec_text.append(letters_map_dec[temp_code]);
			dec_text.append("\n");
			temp_code = "";
		}

		else if (temp_char == ' ') {
			if (enc_text[i + 1] == ' ') {
				dec_text.append(letters_map_dec[temp_code]);
				dec_text.append(" ");
			}
			else {
				dec_text.append(letters_map_dec[temp_code]);
			}
			temp_code = "";
		}

		else {
			string temp_string(1, temp_char);
			temp_code.append(temp_string);
		}
	}
	dec_text.append(letters_map_dec[temp_code]);
	return dec_text;
}


void encode_string(string dec_text, map<string, string> letters_map_enc) {  // prints an encoded message from an input string

	cout << "Decoded Message:\n--------------" << endl;
	cout << dec_text << endl << "\nEncoded Message:\n--------------" << endl;
	cout << encoder(dec_text, letters_map_enc) << endl << endl;
}


void decode_string(string enc_text, map<string, string> letters_map_dec) {  // prints a decoded message from an input string

	cout << "Encoded Message:\n--------------" << endl;
	cout << enc_text << endl << "\nDecoded Message:\n--------------" << endl;
	cout << decoder(enc_text, letters_map_dec) << endl << endl;
}


void encode_from_file(string file_name, map<string, string> letters_map_enc) {  // prints an encoded message from an input file
	ifstream input(file_name);
	string dec_text = "", enc_text = "", temp = "";

	cout << "Decoded Message From File:\n--------------" << endl;

	while (getline(input, temp)) {
		dec_text.append(temp);
		dec_text.append("\n");
	}
	cout << dec_text << endl << "Encoded Message:\n--------------" << endl;
	cout << encoder(dec_text, letters_map_enc) << endl << endl;
	input.close();
}


void decode_from_file(string file_name, map<string, string> letters_map_dec) { // prints a decoded message from an input file
	ifstream input(file_name);
	string dec_text = "", enc_text = "", temp = "", temp_code = "";

	cout << "Encoded Message From File:\n--------------" << endl;

	while (getline(input, temp)) {
		enc_text.append(temp);
		enc_text.append("\n");
	}

	cout << enc_text << endl << "Decoded Message:\n--------------" << endl;
	cout << decoder(enc_text, letters_map_dec) << endl << endl;
	input.close();
}


#endif