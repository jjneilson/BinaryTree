/*
 * bst.cpp
 *
 *  Created on: Oct 19, 2021
 *      Author: jackneilson
 */
#include "bst.hpp"

bst::bst() {  // empty constructor
	root = NULL;
}

bst::bst(string f, string l, int n, string j) { // constructor that forms the root
	root = new bstNode(f, l, n, j);
}

bool bst::insert(string f, string l, int n, string j) {
	if (root == NULL) {
		root = new bstNode(f, l, n, j);
		setHeight(root);
		return true;
	} else {
		bstNode *temp = root;
		while (temp != NULL) {
			if (l < temp->student->last) { //go left in tree
				if (temp->left == NULL) {
					temp->left = new bstNode(f, l, n, j);
					temp->left->parent = temp;
					setHeight(root);
					return true;
				} else {
					temp = temp->left;
				}
			} else if (l > temp->student->last) { // go right in tree
				if (temp->right == NULL) {
					temp->right = new bstNode(f, l, n, j);
					temp->right->parent = temp;
					setHeight(root);
					return true;
				} else {
					temp = temp->right;
				}
			} else
				return false; //cant insert data as its already present in tree
		}
	}
	return false;
}

bstNode* bst::find(string l, string f) {
	bstNode *temp = root;
	while (temp != NULL) {
		if (l == temp->student->last) {
			return temp;
		} else if (l < temp->student->last) {
			temp = temp->left;
		} else {
			temp = temp->right;
		}
	}
	return NULL;
}

void bst::printTreeIO(bstNode *n) {
	if (n != NULL) {
		if (n->left != NULL) {
			printTreeIO(n->left);
		}
		n->printNode();
		if (n->right != NULL) {
			printTreeIO(n->right);
		}
	}

}

void bst::printTreePre(bstNode *n) {
	if (n != NULL) {
		n->printNode();
		if (n->left != NULL) {
			printTreePre(n->left);
		}
		if (n->right != NULL) {
			printTreePre(n->right);
		}
	}
}

void bst::printTreePost(bstNode *n) {
	if (n != NULL) {
		if (n->left != NULL) {
			printTreePost(n->left);
		}
		if (n->right != NULL) {
			printTreePost(n->right);
		}
		n->printNode();
	}
}

bstNode* bst::remove(string l, string f) {
	bstNode *temp = find(l, f);
	if (temp->left == NULL && temp->right == NULL) {
		return removeNoKids(temp);
	} else if (temp->left != NULL && temp->right == NULL) {
		return removeOneKid(temp, true);
	} else if (temp->right != NULL && temp->left == NULL) {
		return removeOneKid(temp, false);
	} else {
		bstNode *n = temp->right;
		while (n->left != NULL) { //finding the rightmost node of the left child
			n = n->left;
		}
		if (n->right != NULL) {
			removeOneKid(n, false);
		} else {
			removeNoKids(n);
		}
		n->parent = temp->parent;
		temp->parent = n;
		n->left = temp->left;
		n->right = temp;
		temp->left = NULL;
		return removeOneKid(temp, false);
	}
	return NULL;
}

bstNode* bst::removeNoKids(bstNode *n) {
	bstNode *tmp = n;
	if (tmp->parent->left == tmp) {
		tmp->parent->left = NULL;
	} else {
		tmp->parent->right = NULL;
	}
	setHeight(n->parent);
	return n;
}

bstNode* bst::removeOneKid(bstNode *n, bool leftFlag) {
	bstNode *temp=NULL;
	if (leftFlag) {
		temp=n->left;
		if (n->parent->student->last > n->student->last) {
			n->parent->left = temp;
			temp->parent = n->parent;
		} else {
			n->parent->right = temp;
			temp->parent = n->parent;
		}
		//n->parent = NULL;
		n->left = NULL;
	} else {
		temp=n->right;
		if (n->parent->student->last > n->student->last) {
			n->parent->left = temp;
			temp->parent = n->parent;
		} else {
			n->parent->right = temp;
			temp->parent = n->parent;
		}
		//n->parent = NULL;
		n->right = NULL;
	}
	setHeight(n->parent);
	return n;
}

void bst::setHeight(bstNode *n) {
	n->height = 1;
	if (n != root) {
		if (n->left == NULL && n->right == NULL) {
			n->height = 1;
			setHeight(n->parent);
		} else if (n->left != NULL && n->right == NULL) {
			n->height = 1 + n->left->height;
			setHeight(n->parent);
		} else if (n->right != NULL && n->left == NULL) {
			n->height = 1 + n->right->height;
			setHeight(n->parent);
		} else {
			if (n->right->height < n->left->height) {
				n->height = 1 + n->left->height;
				setHeight(n->parent);
			} else {
				n->height = 1 + n->right->height;
				setHeight(n->parent);
			}
		}
	} else {
		if (n->left == NULL && n->right == NULL) {
			n->height = 1;
		} else if (n->left != NULL && n->right == NULL) {
			n->height = 1 + n->left->height;
		} else if (n->right != NULL && n->left == NULL) {
			n->height = 1 + n->right->height;
		} else {
			if (n->right->height < n->left->height) {
				n->height = 1 + n->left->height;
			} else {
				n->height = 1 + n->right->height;
			}
		}
	}

}

void bst::clearTree() {  	//clears out an old tree
//This calls the recursive clearTree with the root node
	if (root == NULL) {
		cout << "Tree already empty" << endl;
	} else {
		cout << endl << "Clearing Tree:" << endl;
		clearTree(root);
		root = NULL;
	}
}

void bst::clearTree(bstNode *tmp) {
	if (tmp == NULL) {
		return;
	} else {
		clearTree(tmp->left);
		clearTree(tmp->right);
		tmp->printNode();
		delete (tmp);
	}
}

/*Note: the following three functions’ sole job is to call printTreeIO(BstNode *t),printTreePre(BstNode *t), and printTreePost(BstNode *t) while printint out which
 Function is being called.
 YOU MUST STILL WRITE THE RECURSIVE VERSION OF THESE FUNCTIONS!!!*/

void bst::printTreeIO() { // Just the start – you must write the recursive version
	if (root == NULL) {
		cout << "Empty Tree" << endl;
	} else {
		cout << endl << "Printing In Order:" << endl;
		printTreeIO(root);
	}
}

void bst::printTreePre() {
	if (root == NULL) {
		cout << "Empty Tree" << endl;
	} else {
		cout << endl << "Printing PreOrder:" << endl;
		printTreePre(root);
	}
}

void bst::printTreePost() {
	if (root == NULL) {
		cout << "Empty Tree" << endl;
	} else {
		cout << endl << "Printing PostOrder:" << endl;
		printTreePost(root);
	}
}
