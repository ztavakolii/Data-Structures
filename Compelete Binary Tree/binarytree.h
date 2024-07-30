#pragma once


#include <vector>
#include <string>
#include <iostream>
#ifndef BINARYTREE_H
#define BINARYTREE_H
template <typename T>
class Binarytree {
public:
	void insert(const T& leaf);
	T eraseBack();
	void erase(const T& value);
	void traverseRLString(std::string traverseString)const;
	void traversePreOrder(int rootIndex)const;
	void traverseInOrder(int rootIndex)const;
	void traversePostOrder(int rootIndex)const;
	void sortTree();
	void printTree()const;
private:
	std::vector<T>tree;
};
#endif

