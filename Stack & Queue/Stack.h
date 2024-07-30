

#pragma once
#include "Array.h"
#ifndef STACK_H
#define STACK_H
template<class T>
class Stack {
public:

	Stack(int maxSize) :stack(maxSize), top(-1), maxSize(maxSize),size(0) {}

	void push(T data) {
		if (top == maxSize - 1)
			throw out_of_range("Stack overflow");
		top++;
		stack[top] = data;
		size++;
	}

	T pop() {
		if (top == -1)
			throw out_of_range("Stack underflow");
		T data = stack[top];
		top--;
		size--;
		return data;
	}

	T& search(const T& key) {
		int index = stack.search(0, top + 1, key);
		if (index != -1)
			return stack[index];
		else throw "not found";
	}

	int getSize() {
		return size;
	}

private:
	int top;
	int size;
	int maxSize;
	Array<T> stack;

};
#endif

