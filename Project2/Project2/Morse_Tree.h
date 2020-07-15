#ifndef MORSE_TREE_H
#define MORSE_TREE_H

#pragma once
#include "Binary_Search_Tree.h"
#include <string>
#include <ostream>
#include <math.h>

const int INDEX_NOT_FOUND = -1;
const std::string EMPTY = "";
// Number of rows / height of a binary tree, represented by number of digits with a starting 1
// Used instead of constants to allow for flexible further scaling of Morse_Tree
// This implementation ASSUMES we know the height of binary tree
const int HEIGHT_CODE_VALUE = 1000;

// Struct that contains the letter and morse code
struct Morse_Letter
{
	std::string letter;
	std::string code;
	
	// Strategic int representation of morse code for inorder comparisons
	int code_value = HEIGHT_CODE_VALUE;

	// Constructor
	Morse_Letter(std::string letter, std::string code/*, int value*/) {
		this->letter = letter;
		this->code = code;
		// Negative means left hand side of tree, otherwise positive
		if (code.at(0) == '.')
			code_value *= -1;
		if (code.length() > 1) {
			int counter = 100;
			for (char l : code.substr(1)) {
				// '.' represents left node so subtract counter
				if (l == '.')
					code_value -= counter;
				// '_' represents right node so add counter
				else
					code_value += counter;
				counter /= 10;
			}
		}
	}

	bool operator<(const Morse_Letter& other) const {
		if (this->code_value < other.code_value)
			return true;
		return false;
	}

	bool operator>(const Morse_Letter& other) const {
		if (this->code_value > other.code_value)
			return true;
		return false;
	}

	// Overwrite output operator, needed because of the to_string() method to be
	// able to print a tree
	friend std::ostream& operator<<(std::ostream& os, const Morse_Letter& m_l) {
		os << m_l.letter << " : " << m_l.code;
		return os;
	}
};

class Morse_Tree :
	public Binary_Search_Tree<Morse_Letter>
{
public:
	// Does not have empty constructor, should only be created with Morse_Letter vector
	Morse_Tree(std::vector<Morse_Letter> morse_vec);

private:

	Binary_Search_Tree<Morse_Letter> dash_tree;
	Binary_Search_Tree<Morse_Letter> dot_tree;

	std::vector<Morse_Letter> morse_insertion_order(std::vector<Morse_Letter> morse_vec);

};

#endif