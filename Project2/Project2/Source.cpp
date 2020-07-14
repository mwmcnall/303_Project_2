#include "Binary_Search_Tree.h"
#include "Binary_Tree.h"
#include<iostream>
#include<vector>
#include<string>

#include "Morse_Tree.h"
#include <algorithm>

using namespace std;

int main() {

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
	};
	
	Morse_Tree morse_tree(morse_letters);

	return 0;
}

