

#pragma once
#include "Array.h"

#ifndef QUEUE_H
#define QUEUE_H
template<class T>
class Queue {
public:

	Queue(int maxSize) :queue(maxSize + 1), maxSize(maxSize), size(0), front(1), rear(1) {}
	

	void enqueue(T data) {
		if (front == rear + 1)
			throw "Queue is full";
		queue[rear] = data;
		rear++;
		if (rear == maxSize + 1)
			rear = 0;
		size++;
	}

	
	T dequeue() {
		if (front == rear)
			throw "Queue is empty";
		T data = queue[front];
		front++;
		if (front == maxSize + 1)
			front = 0;
		size--;
		return data;
	}

	
	int getSize() {
		return size;
	}

	
	T& search(T key) {
		int index = queue.search(front, rear, key);
		if (index != -1)
			return queue[index];
		else throw "not found";
	}

private:
	int front;
	int rear;
	int size;
	int maxSize;
	Array<T>queue;
};
#endif

