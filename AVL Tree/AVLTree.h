#ifndef AVLTREE_H
#define AVLTREE_H
#include <algorithm>
#include <vector>
#include <iostream>


template<typename T, typename U> // T = typename of key       U = typename of value
class Entry {

public:
    T key;
    U value;
    Entry<T,U>* leftChild;
    Entry<T, U>* rightChild;
    int height;
};


template<typename T, typename U> // T = typename of key       U = typename of value
class AVLTree {

public:
 
    Entry<T, U>* getRoot() {
        return root;
    }

    int height(Entry<T, U>* e) {
        if (e == nullptr)
            return -1;
        else return e->height;
    }

    Entry<T, U>* makeNewEntry(T key, U value) {
        Entry<T, U>* newEntry = new Entry<T, U>();
        newEntry->key = key;
        newEntry->value = value;
        newEntry->leftChild = nullptr;
        newEntry->rightChild = nullptr;
        newEntry->height = 0;

        return newEntry;
    }

    Entry<T, U>* rightRotate(Entry<T, U>* y) {
        Entry<T, U>* x = y->leftChild;
        Entry<T, U>* z = x->rightChild;
        x->rightChild = y;
        y->leftChild = z;
        y->height = std::max(height(y->leftChild), height(y->rightChild)) + 1;
        x->height = std::max(height(x->leftChild), height(x->rightChild)) + 1;

        return x;
    }

  
    Entry<T, U>* leftRotate(Entry<T, U>* x) {
        Entry<T, U>* y = x->rightChild;
        Entry<T, U>* z = y->leftChild;
        y->leftChild = x;
        x->rightChild = z;
        y->height = std::max(height(y->leftChild), height(y->rightChild)) + 1;
        x->height = std::max(height(x->leftChild), height(x->rightChild)) + 1;

        return y;
    }

  
    int getBalanceFactor(Entry<T, U>* e) {
        if (e == nullptr)
            return 0;
        else return height(e->leftChild) - height(e->rightChild);
    }

 
    Entry<T, U>* insert(Entry<T, U>* entry, T key, U value) {
        if (entry == nullptr)
            return makeNewEntry(key, value);

        if (key < entry->key)
            entry->leftChild = insert(entry->leftChild, key, value);

        else if (key > entry->key)
            entry->rightChild = insert(entry->rightChild, key, value);

        else return entry;

        entry->height = std::max(height(entry->leftChild), height(entry->rightChild)) + 1;

        int bf = getBalanceFactor(entry);

        if (bf > 1 && key < entry->leftChild->key)
            return rightRotate(entry);

        else if (bf<-1 && key>entry->rightChild->key)
            return leftRotate(entry);

        else if (bf > 1 && key > entry->leftChild->key) {
            entry->leftChild = leftRotate(entry->leftChild);
            return rightRotate(entry);
        }

        else if (bf < -1 && key < entry->rightChild->key) {
            entry->rightChild = rightRotate(entry->rightChild);
            return leftRotate(entry);
        }

        else return entry;
    }

 
    std::vector<Entry<T, U>> inOrder(Entry<T, U>* e) {
        if (e != nullptr) {
            std::vector<Entry<T, U>> leftVec = inOrder(e->leftChild);
            leftVec.push_back(*e);
            std::vector<Entry<T, U>> rightVec = inOrder(e->rightChild);
            std::vector<Entry<T, U>> result;
            std::merge(leftVec.begin(), leftVec.end(), rightVec.begin(), rightVec.end(), result.begin());
            return result;
        }
    }


private:
    Entry<T, U>* root;

};

#endif // AVLTREE_H