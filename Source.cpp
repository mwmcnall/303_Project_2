#include "Binary_Search_Tree.h"
#include "Binary_Tree.h"
#include<iostream>
#include<vector>
#include<string>
#include <fstream>
#include "Morse_Tree.h"
#include <algorithm>
#include <sstream>
#include "Functions.h"

using namespace std;

<<<<<<< HEAD


=======
int get_val(string code) {
	string result_str = "";
	int result = 0;
	for (int i = 0; i < code.size(); ++i) {
		if (code[i] == '.') result_str += '1';
		else if (code[i] == '_') result_str += '2';
		else break;
	}
	stringstream res_stream(result_str);
	res_stream >> result;
	return result;
}
>>>>>>> ea741d83787f70d0189ebed67428504d70a814d5

int main() {

	map<string, string> letters_map_enc, letters_map_dec; // maps for encoding and decoding
	vector<Morse_Letter> morse_vec;  
	read_file_to_vec(morse_vec, "morse.txt", letters_map_enc, letters_map_dec); // see Functions.h

	/*for (vector<Morse_Letter>::iterator i = morse_vec.begin(); i != morse_vec.end(); ++i) {
		cout << i->letter << ' ' << i->code << ' ' << letters_map_enc[i->letter] << letters_map_dec[i->code] << endl;
	}*/

	encode_string("abcdef\nghijkl\nmnopqrs\ntuvwxyz", letters_map_enc);
	cout << endl;
	decode_string("_.. ._. .. _. _._  __ ___ ._. .  ___ ..._ ._ ._.. _ .. _. .\n_... .. _ _._. ....", letters_map_dec);
	cout << endl;
	encode_from_file("text to encode.txt", letters_map_enc);
	cout << endl;
	decode_from_file("text to decode.txt", letters_map_dec);


	//Morse_Tree x(morse_vec);


	/*string temp, temp_char, temp_code;
	int temp_int;
	while (getline(input, temp)) {
		temp_char = temp[0];
		temp_code = temp.substr(1, string::npos);
		temp_int = get_val(temp_code);
		cout << temp_char << ' ' << temp_int << endl ;
		
	}
	

<<<<<<< HEAD
	//Test vector, we will need to programagically create something similar
=======
	// Test vector, we will need to programagically create something similar
>>>>>>> ea741d83787f70d0189ebed67428504d70a814d5
	vector<Morse_Letter> morse_letters = { 
		{"a", "._"},
		{"b", "_..."},
		{"c", "_._."},
		{"d", "_.."},
		{"e", "."},
		{"f", ".._."},
		{"g", "__."},
		{"h", "...."},
		{"i", ".."},
		{"j", ".___"},
		{"k", "_._"},
		{"l", "._.."},
		{"m", "__"},
		{"n", "_."},
		{"o", "___"},
		{"p", ".__."},
		{"q", "__._"},
		{"r", "._."},
		{"s", "..."},
		{"t", "_"},
		{"u", ".._"},
		{"v", "..._"},
		{"w", ".__"},
		{"x", "_.._"},
		{"y", "_.__"},
		{"z", "__.."}
<<<<<<< HEAD
	};
	

	Morse_Tree morse_tree(morse_letters);*/
	cin.get();
=======
	}*/;
	
	//Morse_Tree morse_tree(morse_letters);
	input_file.close();

	cin.get();

>>>>>>> ea741d83787f70d0189ebed67428504d70a814d5
	return 0;
}

