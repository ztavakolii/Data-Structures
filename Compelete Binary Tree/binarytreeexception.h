#pragma once
#include <exception>
#include <iostream>
#ifndef BINARYTREEEXCEPTION_H
#define BINARYTREEEXCEPTION_H
class Binarytree_Exception :public std::out_of_range, std::invalid_argument {
public:
	Binarytree_Exception(int code):out_of_range("\nThere is no subtree with this root."),invalid_argument("\nThe string is invalid.") {
		if (code == 1 || code == 2)
			Binarytree_Exception::code = code;
		else std::cerr << std::invalid_argument("\nInvalid code!").what();
	}
	void what() {
		if (code == 1)
			std::cerr << out_of_range::what() << std::endl;
		else if (code == 2)
			std::cerr << invalid_argument::what() << std::endl;
	}
private:
	int code;// the code 1 for out_of_range error and the code 2 for invalid_argument error
};
#endif

