# 303_Project_2
	
# Actionable Goals
	- A template for how the Binary_Tree should be created is within Source.cpp
		- Determine how to programatically create a Binary_Search_Tree by reading in the morse.txt
	- Create a Binary Search Tree where the left node represents the dot character, and the right node represents the dash character
	- Create a function that can decode a Binary_Search_Tree by taking in a string of dots and dashes
	- Create a function that can encode a string of letters into dots and dashes

# Project Goals:
	- Store each letter of the alphabet in a node of binary tree of depth 4
	- Root is at depth 0 and stores no letter
		- First left node stores letter e (dot)
		- First right node stores letter t (dash)
		- Dots go left, dash goes right
	- Write a function that builds a morse code binary tree based off the file morse.txt
	- System should be able to decode a message using the morse tree that you built
		- -** --* results in "dg"
		- Delimiter between symbols is a single space
	- System can encode a message
		- "ac" = *- -*-*
	- May use a binary search tree or a map to store the codes for the letters

# Facts and Assumptions
	- May assume that the character delimiters are simply spaces
	- You may assume the string has one word only
	- Can use Binary_Tree source
	- Can just call decode and encode from the main function, no need for getting input from the user or a menu-based system