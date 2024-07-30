#include "rotatingbuffer.h"
template<typename T>
Rotatingbuffer<T>::Rotatingbuffer(int sz):size(sz) {
	buffer = new T[size];
	readIndex = 0;
	writeIndex = 0;
	numberOfElementsInBuffer = 0;
}
template<typename T>
Rotatingbuffer<T>::~Rotatingbuffer() {
	delete[]buffer;
}
template<typename T>
void Rotatingbuffer<T>::push(const T& value) {
	string s = "The buffer is full.";
	if (numberOfElementsInBuffer == size)
		throw s;
	numberOfElementsInBuffer++;
	buffer[writeIndex] = value;
	writeIndex++;
	if (writeIndex == size)
		writeIndex = 0;
}
template<typename T>
T Rotatingbuffer<T>::pop() {
	string s = "The buffer is empty.";
	if (numberOfElementsInBuffer == 0)
		throw s;
	numberOfElementsInBuffer--;
	int temp = readIndex;
	readIndex++;
	if (readIndex == size)
		readIndex = 0;
	return buffer[temp];
}
