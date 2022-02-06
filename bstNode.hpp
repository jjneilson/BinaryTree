/*
 * bstNode.hpp
 *
 *  Created on: Oct 19, 2021
 *      Author: jackneilson
 */

#ifndef bstNode_HPP_
#define bstNode_HPP_

#include "Student.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

class bstNode {
	friend class bst;
	bstNode *parent;
	bstNode *left;
	bstNode *right;
	int height;
	Student *student;

public:
	bstNode();
	bstNode(string f, string l, int n, string j);
	void printNode();
	~bstNode();

};


#endif /* bstNode_HPP_ */
