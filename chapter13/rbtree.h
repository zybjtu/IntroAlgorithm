/*
 * =====================================================================================
 *
 *       Filename:  rbtree.h
 *
 *       Description:  the implementation of red black tree, using double linked method
 *
 *       Version:  1.0
 *       Created:  12/01/14 13:41:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *       Author:  zhangyi
 *       Organization:  org.zhangyi.com
 *
 * =====================================================================================
 */

#ifndef RBTree_H 
#define RBTree_H 

#include <iostream>
#include "../lib/nocopyable.h"

#ifndef NULL
#define NULL 0
#endif

template<typename T>
class RBTree;

template<typename T>
class Node {
public:
    enum Color {black = 0, red = 1};
    friend RBTree<T>; 
    Node();
    Node(const T& val, Node* left, Node* right, Node* parent, Color color);
    ~Node();
private:
    T data_;
    Node* left_;
    Node* right_;
    Node* parent_;
    Color color_;
};

template<typename T>
Node<T>::Node() :
    left_(NULL), right_(NULL), parent_(NULL) { 
}

template<typename T>
Node<T>::Node(const T& val, Node* left, Node* right, Node* parent, Color color) :
    data_(val), left_(left), right_(right),  parent_(parent), color_(color){}
template<typename T>
Node<T>::~Node(){}

// the node has parent_ attribute, so I don't want to inherit the binarysearchtree
// only implement the insert and delete method, for RBTree is a binarysearchtree essentially
template<typename T>
class RBTree : NoCopyable<T> {
public:
    RBTree(const T& val);
    RBTree& Insert(const T& val);
    RBTree& Delete(const T& val);
private:
    Node<T>* root_;
};
#endif

template
