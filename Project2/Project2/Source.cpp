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

	map<string, string> letters_map_enc, letters_map_dec; // maps for encoding and decoding
	vector<Morse_Letter> morse_vec;  
	read_file_to_vec(morse_vec, "morse.txt", letters_map_enc, letters_map_dec); // see Functions.h
	
	//--------------------------------------------------------------//
	// Input custom strings to by changing the variable below		//
	
	string user_string = "I ate a big red candle";

	//--------------------------------------------------------------//
	
	Test_All(user_string, letters_map_dec, letters_map_enc);

	cin.get();
	return 0;
}