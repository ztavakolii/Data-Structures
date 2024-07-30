#include "binarytree.h"
#include "binarytreeexception.h"
#include <algorithm>
#include <vector>
using namespace std;
template<typename T>
void Binarytree<T>::insert(const T& leaf) {
	tree.push_back(leaf);
}
template<typename T>
T Binarytree<T>::eraseBack() {
	T erased = tree[tree.size() - 1];
	try {
		tree.pop_back();
	}
	catch (...) {
		cerr << "The binary tree is empty." << endl;
	}
	return erased;
}
template<typename T>
void Binarytree<T>::erase(const T& value) {
	int i;
	for (i = 0; i < tree.size(); i++)
		if (tree[i] == value) {
			auto it = tree.begin() + i;
			tree.erase(it);
			break;
		}
	if (i == tree.size())
		cout << "The desired element not found." << endl;
	tree.shrink_to_fit();
}
template<typename T>
void Binarytree<T>::traverseRLString(string traverseString)const {
	int height = std::floor(std::log2l(tree.size()));
	for (int i = 0; i < traverseString.length(); i++)
		if (traverseString[i] != 'R' && traverseString[i] != 'L'
			&& traverseString[i] != 'r' && traverseString[i] != 'l')
			throw Binarytree_Exception(2);//********  exception  ****
	if (traverseString.length() > height)
		throw Binarytree_Exception(2);//********  exception  ****
	int index = 0;
	cout << tree[index] << ", ";
	for (int i = 0; i < traverseString.length(); i++) {
		if (traverseString[i] == 'R' || traverseString[i] == 'r') {
			index = 2 * index + 2;
			if (index < tree.size())
				cout << tree[index] << ", ";
			else throw Binarytree_Exception(2);//********  exception  ****
		}
		else if (traverseString[i] == 'L' || traverseString[i] == 'l') {
			index = 2 * index + 1;
			if (index < tree.size())
				cout << tree[index] << ", ";
			else throw Binarytree_Exception(2);//********  exception  ****
		}
	}
}
template<typename T>
void Binarytree<T>::sortTree() {
	std::sort(tree.begin(), tree.end());
}
template <typename T>
void Binarytree<T>::printTree()const {
	long int height = std::floor(std::log2l(tree.size()));
	for (int i = 0; i <= height; i++) {
		int end = pow(2, i + 1) - 1;
		for (int j = pow(2, i) - 1; j < end; j++)
			if (j < tree.size())
				cout << tree[j] << " ";
			else break;
		cout << endl;
	}
}
template<typename T>
void Binarytree<T>::traversePreOrder(int rootIndex)const {
	if (rootIndex < 0 || rootIndex >= tree.size())
		throw Binarytree_Exception(1);//********  exception  ****
	cout << tree[rootIndex] << ", ";
	if (2 * rootIndex + 1 < tree.size())
		traversePreOrder(2 * rootIndex + 1);
	if (2 * rootIndex + 2 < tree.size())
		traversePreOrder(2 * rootIndex + 2);
}
template<typename T>
void Binarytree<T>::traverseInOrder(int rootIndex)const {
	if (rootIndex < 0 || rootIndex >= tree.size())
		throw Binarytree_Exception(1);//********  exception  ****
	if (2 * rootIndex + 1 < tree.size())
		traverseInOrder(2 * rootIndex + 1);
	cout << tree[rootIndex] << ", ";
	if (2 * rootIndex + 2 < tree.size())
		traverseInOrder(2 * rootIndex + 2);
}
template<typename T>
void Binarytree<T>::traversePostOrder(int rootIndex)const {
	if (rootIndex < 0 || rootIndex >= tree.size())
		throw Binarytree_Exception(1);//********  exception  ****
	if (2 * rootIndex + 1 < tree.size())
		traversePostOrder(2 * rootIndex + 1);
	if (2 * rootIndex + 2 < tree.size())
		traversePostOrder(2 * rootIndex + 2);
	cout << tree[rootIndex] << ", ";
}