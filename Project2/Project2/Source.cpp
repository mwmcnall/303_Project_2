#include "Binary_Search_Tree.h"
#include "Binary_Tree.h"
#include<iostream>
#include<vector>
#include<string>
#include <fstream>
#include "Morse_Tree.h"
#include <algorithm>
#include <sstream>

using namespace std;




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



int main() {

	ifstream input_file("morse.txt");
	vector<Morse_Letter> morse_vec;
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

	for (vector<Morse_Letter>::iterator i = morse_vec.begin(); i != morse_vec.end(); ++i) {
		cout << i->letter << ' ' << i->code << ' ' << i->code_value << endl;
	}

	//Morse_Tree x(morse_vec);


	/*string temp, temp_char, temp_code;
	int temp_int;
	while (getline(input, temp)) {
		temp_char = temp[0];
		temp_code = temp.substr(1, string::npos);
		temp_int = get_val(temp_code);
		cout << temp_char << ' ' << temp_int << endl ;
		
	}


	// Test vector, we will need to programagically create something similar
	vector<Morse_Letter> morse_letters = { 
		{"a", ".-"},
		{"b", "-..."},
		{"c", "-.-."},
		{"d", "-.."},
		{"e", "."},
		{"f", "..-."},
		{"g", "--."},
		{"h", "...."},
		{"i", ".."},
		{"j", ".---"},
		{"k", "-.-"},
		{"l", ".-.."},
		{"m", "--"},
		{"n", "-."},
		{"o", "---"},
		{"p", ".--."},
		{"q", "--.-"},
		{"r", ".-."},
		{"s", "..."},
		{"t", "-"},
		{"u", "..-"},
		{"v", "...-"},
		{"w", ".--"},
		{"x", "-..-"},
		{"y", "-.--"},
		{"z", "--.."}
	}*/;
	

	//Morse_Tree morse_tree(morse_letters);
	input_file.close();
	return 0;
}

