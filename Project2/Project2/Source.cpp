#include "Binary_Search_Tree.h"
#include "Binary_Tree.h"
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {

	/*
	First element in the vector acts as the head of the tree

	Then it follows this pattern:
		Left, Right, Root
		To build out the tree
	*/
	vector<string> full_expression{ 
		// 'Null' head node, I couldn't figure out how to have a blank head node on a binary tree
		// so I just used a replaecment character
		"0",
		// Dot tree, full left hand side of the tree
		"e", "i", "s", "h", "NULL", "NULL", "v", "NULL", "NULL",
		"u", "f", "NULL", "NULL", "NULL", "a", "r", "l", "NULL", "NULL", "NULL", "w", "p",
		"NULL", "NULL", "j", "NULL", "NULL", 
		// Dash tree, full right hand side of the tree
		"t", "n", "d", "b", "NULL", "NULL", "x", "NULL", "NULL",
		"k", "c", "NULL", "NULL", "y", "NULL", "NULL", "m", "g", "z", "NULL", "NULL", "q", "NULL", "NULL",
		"o", "NULL", "NULL"
	};

	// Would it be easier to just have two binary trees to search?
	vector<string> dot_exression{ "e",
		"i", "s", "h", "NULL", "NULL", "v", "NULL", "NULL",
		"u", "f", "NULL", "NULL", "NULL", "a", "r", "l", "NULL", "NULL", "NULL", "w", "p",
		"NULL", "NULL", "j", "NULL", "NULL" };
	vector<string> dash_expression{
		"t", "n", "d", "b", "NULL", "NULL", "x", "NULL", "NULL",
		"k", "c", "NULL", "NULL", "y", "NULL", "NULL", "m", "g", "z", "NULL", "NULL", "q", "NULL", "NULL",
		"o", "NULL", "NULL"
		};

	Binary_Tree<string> dot_tree;
	dot_tree.read_tree(dot_exression);
	int dot_height = dot_tree.height();

	Binary_Tree<string> dash_tree;
	dash_tree.read_tree(dash_expression);
	int dash_height = dash_tree.height();

	Binary_Tree<string> morse_tree;
	morse_tree.read_tree(full_expression);

	// Idk how this works yet, just playing around with it
	Binary_Search_Tree<string> test_search;
	test_search.read_tree(full_expression);

	return 0;
}

