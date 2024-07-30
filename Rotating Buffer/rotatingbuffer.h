#pragma once
#include <iostream>
#include <string>
using namespace std;
#ifndef ROTATINGBUFFET_H
#define ROTATINGBUFFER_H
template<typename T>
class Rotatingbuffer {
public:
	Rotatingbuffer(int sz);
	~Rotatingbuffer();
	void push(const T&);
	T pop();
private:
const int size;
T* buffer;
int readIndex;
int writeIndex;
int numberOfElementsInBuffer;
};
#endif