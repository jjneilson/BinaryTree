/*
 * bstNode.cpp
 *
 *  Created on: Oct 19, 2021
 *      Author: jackneilson
 */

#include "bstNode.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

	bstNode::bstNode(){
		student = NULL;
		parent = NULL;
		left = NULL;
		right = NULL;
		height = 0;
	}

	bstNode::bstNode(string f,string l,int n,string j){
		student = new Student(f,l,n,j);
		parent = NULL;
		left = NULL;
		right = NULL;
		height = 1;
	}

	void bstNode::printNode(){
		cout << "Height of Node: " << height << endl;
		cout << "Name: " << student->first << " " << student->last << endl;
		cout << "Joke: " << student->joke << endl;
		cout << "Favorite Number: " << student->fav_num << endl;
	}

	bstNode::~bstNode(){
		delete student;
	}
