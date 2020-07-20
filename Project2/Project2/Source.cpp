#include "Binary_Search_Tree.h"
#include "Binary_Tree.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Morse_Tree.h"
#include <algorithm>
#include <sstream>
#include "Functions.h"
#include "Test_Cases.h"

using namespace std;

int main() {

	// map which stores the codes for letters
	map<string, string> letters_map_enc; 
	vector<Morse_Letter> morse_vec;  
	// see Functions.h
	read_file_to_vec(morse_vec, "morse.txt", letters_map_enc); 
	// Build Morse_tree out of filled vector from file
	Morse_Tree morse_tree(morse_vec, letters_map_enc);

	string result = morse_tree.code_from_letter("e");
	
	//--------------------------------------------------------------//
	// Input custom strings to by changing the variable below		//
	
	string user_string = "I ate a big red candle";

	//--------------------------------------------------------------//
	
	Test_All(user_string, morse_tree);
	
	cin.get();
	return 0;
}