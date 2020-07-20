#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Binary_Search_Tree.h"
#include "Binary_Tree.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Morse_Tree.h"
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

const string& NEW_LINE = "\n";

//Reads text from the morse file into a vector
void read_file_to_vec(vector<Morse_Letter>& morse_vec, string file_name)
{  
	ifstream input_file(file_name);
	string temp, temp_char, temp_code;

	while (getline((input_file), temp)) {
		temp_char = temp[0];
		temp_code = temp.substr(1, string::npos);
		Morse_Letter letter(temp_char, temp_code);
		morse_vec.push_back(letter);
	}
	input_file.close();
}

// Overload of above function that also creates two maps for encoding and decoding.
void read_file_to_vec(vector<Morse_Letter>& morse_vec, string file_name,
	map<string, string>& letters_map_enc)
{
	ifstream input_file(file_name);
	string temp, temp_char, temp_code;

	while (getline((input_file), temp)) {
		temp_char = temp[0];
		temp_code = temp.substr(1, string::npos);
		letters_map_enc[temp_char] = temp_code;
		Morse_Letter letter(temp_char, temp_code);
		morse_vec.push_back(letter);
	}
	input_file.close();
}

string encoder(string dec_text, Morse_Tree& morse_tree) {
	string enc_text = "", temp = "";
	for (char letter : dec_text) {
		if (letter == '\n') {
			enc_text.append(NEW_LINE);
		}
		else if (letter == ' ') 
			enc_text.append(" ");
		else {
			enc_text.append(morse_tree.code_from_letter(string(1, tolower(letter))));
			enc_text.append(" ");
		}
	}
	return enc_text;
}

// Returns a vector of words from a string based on a delimiter
vector<string> split(const string& s, char delimiter) {
	vector<string> tokens;
	string token;
	istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter))
		tokens.push_back(token);
	return tokens;
}

string decoder(string enc_text, Morse_Tree& morse_tree) {
	vector<string> code_letters = split(enc_text, ' ');
	string dec_text = "";
	int new_line_pos = 0;

	for (string code_letter : code_letters) {
		new_line_pos = code_letter.find(NEW_LINE);
		// If newline is found in code_letter
		if (new_line_pos > 0) {
			vector<string> new_line_split = split(code_letter, '\n');
			// enc_text ends in a \n
			if (new_line_split.size() == 1) {
				dec_text.append(morse_tree.letter_from_code(new_line_split[0]));
				dec_text.append(NEW_LINE);
				break;
			}
			dec_text.append(morse_tree.letter_from_code(new_line_split[0]));
			dec_text.append(NEW_LINE);
			dec_text.append(morse_tree.letter_from_code(new_line_split[1]));
		}
		else if (code_letter == "")
			dec_text.append(" ");
		else
			dec_text.append(morse_tree.letter_from_code(code_letter));
	}

	return dec_text;
}

// prints an encoded message from an input string
void encode_string(string dec_text, Morse_Tree& morse_tree) {  

	cout << "Decoded Message:\n--------------" << endl;
	cout << dec_text << endl << "\nEncoded Message:\n--------------" << endl;
	cout << encoder(dec_text, morse_tree) << endl << endl;
}

// prints a decoded message from an input string
void decode_string(string enc_text, Morse_Tree& morse_tree) {

	cout << "Encoded Message:\n--------------" << endl;
	cout << enc_text << endl << "\nDecoded Message:\n--------------" << endl;
	cout << decoder(enc_text, morse_tree) << endl << endl;
}

// prints an encoded message from an input file
void encode_from_file(string file_name, Morse_Tree& morse_tree) {
	ifstream input(file_name);
	string dec_text = "", enc_text = "", temp = "";

	cout << "Decoded Message From File:\n--------------" << endl;

	while (getline(input, temp)) {
		dec_text.append(temp);
		dec_text.append("\n");
	}
	cout << dec_text << endl << "Encoded Message:\n--------------" << endl;
	cout << encoder(dec_text, morse_tree) << endl << endl;
	input.close();
}

// prints a decoded message from an input file
void decode_from_file(string file_name, Morse_Tree& morse_tree) {
	ifstream input(file_name);
	string dec_text = "", enc_text = "", temp = "", temp_code = "";

	cout << "Encoded Message From File:\n--------------" << endl;

	while (getline(input, temp)) {
		enc_text.append(temp);
		enc_text.append("\n");
	}

	cout << enc_text << endl << "Decoded Message:\n--------------" << endl;
	cout << decoder(enc_text, morse_tree) << endl << endl;
	input.close();
}

#endif