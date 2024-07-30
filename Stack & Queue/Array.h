

#pragma once
#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>
using namespace std;

template <class T>
class Array {
private:
    struct Node {
        T data;
        Node* next;
        Node(T data) : data(data), next(nullptr) {}
    };

    Node* head;
    int size;
    int maxSize;

public:
   
    Array(int maxSize) : head(nullptr), size(0), maxSize(maxSize) {
        reserve(maxSize);
    }

 
    void reserve(int size) {
        head = new Node(0);
        Node* node = head;
        for (int i = 1; i < size; i++) {
            node->next = new Node(0);
            node = node->next;
        }
        this->size = size;
    }

    
    void insert(T data, int index) {
        if (index >= 0 && index <= size && size < maxSize) {
            Node* newNode = new Node(data);
            if (index == 0) {
                newNode->next = head;
                head = newNode;
            }
            else {
                Node* prevNode = head;
                for (int i = 1; i < index; i++) {
                    prevNode = prevNode->next;
                }
                newNode->next = prevNode->next;
                prevNode->next = newNode;
            }
            size++;
        }
    }

  
    T remove(int index) {
        Node* node;
        T data;
        if (index == 0) {
            node = head;
            head = head->next;
            data = node->data;
            delete node;
        }
        else {
            node = head;
            for (int i = 1; i < index; i++) {
                node = node->next;
            }
            Node* temp = node->next;
            node->next = temp->next;
            data = temp->data;
            delete temp;
        }
        size--;
        return data;
    }

    
    int search(int start, int end, T key) {
        Node* node = head;
        for (int i = 0; i < start; i++)
            node = node->next;
        for (int i = start; i != end; i++) {
            if (i == maxSize) {
                i = 0;
                node = head;
            }
            if (node->data == key)
                return i;
            node = node->next;
        }
        return -1;
    }


    T& operator[](int index) {
        if (index >= 0 && index < size) {
            Node* node = head;
            for (int i = 0; i < index; i++) {
                node = node->next;
            }
            return node->data;
        }
        throw std::out_of_range("Index out of range");
    }

   
    T operator[](int index)const {
        if (index >= 0 && index < size) {
            Node* node = head;
            for (int i = 0; i < index; i++) {
                node = node->next;
            }
            return node->data;
        }
        throw std::out_of_range("Index out of range");
    }

  
    void clear() {
        Node* node = head;
        while (node != nullptr) {
            Node* nextNode = node->next;
            delete node;
            node = nextNode;
        }
        head = nullptr;
        size = 0;
    }


    int getSize() {
        return size;
    }

    ~Array() {
        clear();
    }
};
#endif

