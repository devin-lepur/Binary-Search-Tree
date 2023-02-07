/* Devin Lepur
   Red ID: 825148526
   CS-496
   Prof Kraft
*/

#ifndef BINARY_SEARCH_TREE_CPP
#include "BinarySearchTree.h"
#include <iostream>
using namespace BST_NS;

//Overloaded insert, recursive
//Pre-condition: BST is made
template <class T>
void BinarySearchTree<T>::insert(T item) {
	if (root == NULL) {
		root = new TreeNode<T>(item, NULL, NULL);
		tree_size++;
		return;
	}
	root = insert(root, item);
}

//Overloaded insert, recursive
//Pre-condition: BST is made
template <class T>
TreeNode<T>* BinarySearchTree<T>::insert(TreeNode<T>* node, T item) {
	if (node == NULL) {
		tree_size++;
		return new TreeNode<T>(item, NULL, NULL);
	}
	if (item < node->data) {
		node->leftLink = insert(node->leftLink, item);
	}
	else {
		node->rightLink = insert(node->rightLink, item);
	}
	return node;
}

//pre: BST exists
//post: BST is empty
// virtual dtor
template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
	makeEmpty();
}


//pre: BST exists
//post: item, if in BST, is removed
template <class T>
void BinarySearchTree<T>::remove(T item) {
	root = remove(root, item);
	tree_size--;
}

//pre: BST exists
//post: item, if in BST, is removed
template <class T>
TreeNode<T>* BinarySearchTree<T>::remove(TreeNode<T>* node, T item) {
	if (!node)
		return node;

	if (item > node->data)
	{
		node->rightLink = remove(node->rightLink, item);
		return node;
	}
	else if (item < node->data)
	{
		node->leftLink = remove(node->leftLink, item);
		return node;
	}
	else 
	{
		if (!node->leftLink)
		{
			TreeNode<T>* temp = node->rightLink;
			delete(node);
			return temp;
		}
		else if (!node->rightLink)
		{
			TreeNode<T>* temp = node->leftLink;
			delete(node);
			return temp;
		}
		else
		{
			TreeNode<T>* curr = node->rightLink;
			TreeNode<T>* left = node->leftLink;
			TreeNode<T>* right = node->rightLink;
			TreeNode<T>* succ_parent = NULL;
			delete(node);
			while (curr->leftLink != NULL)
			{
				succ_parent = curr;
				curr = curr->leftLink;
			}
			if (succ_parent != NULL)
			{
				succ_parent->leftLink = curr->rightLink;
				curr->rightLink = right;
			}
			curr->leftLink = left;
			return curr;
		}

	}
}


//pre: BST exists
// post: two BSTs exist w same elements
// copy ctor
template <class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& other) {
	return;
}
//pre: BST exists
// post: bool returned if item is in tree
// check if an item exists in the tree
template <class T>
bool BinarySearchTree<T>::inTree(T item) const{
	bool notFound = true;
	TreeNode<T>* currNode = root;
	while (notFound) {
		if (currNode == NULL) {
			return false;
		}
		if (item < currNode->data) {
			currNode = currNode->leftLink;
			continue;
		}
		if (item > currNode->data) {
			currNode = currNode->rightLink;
			continue;
		}
		if (item == currNode->data) {
			return true;
		}
	}
}

//pre: BST exits
//second BST exits
//overloading assignment operator
template <class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree other) {
	return(sameTree(root, other.root));
}

template <class T>
bool BinarySearchTree<T>::sameTree(TreeNode<T>* origNode, TreeNode<T>* otherNode) {
	if (origNode == NULL && otherNode == NULL) {
		return true;
	}
	if (origNode != NULL && otherNode != NULL) {
		return (origNode->data == otherNode->data && sameTree(origNode->leftLink, otherNode->leftLink) && sameTree(origNode->rightLink, otherNode->rightLink));
	}
	return false;
}

//BST exists
// post: BST is empty
// empty the tree
template <class T>
void BinarySearchTree<T>::makeEmpty() {
	while (tree_size > 0) {
		remove(root->data);
	}
}

//BST exists
// post: BST elements are printed in pre order
// pre-order traversal (prints to stdout)
template <class T>
void BinarySearchTree<T>::preOrderShow() const{
	preOrderShow(root);
}
//BST exists
// post: BST elements are printed in pre order
template <class T>
void BinarySearchTree<T>::preOrderShow(TreeNode<T>* node) const{
	if (node == NULL) {
		return;
	}
	std::cout << node->data << " ";
	preOrderShow(node->leftLink);
	preOrderShow(node->rightLink);
}

//BST exists
// post: BST elements are printed in order
// in-order traversal (prints to stdout)
template <class T>
void BinarySearchTree<T>::inOrderShow() const {
	inOrderShow(root);
}

//BST exists
// post: BST elements are printed in order
//Overloaded inOrderShow
template <class T>
void BinarySearchTree<T>::inOrderShow(TreeNode<T>* node) const {
	if (node == NULL) {
		return;
	}
	inOrderShow(node->leftLink);
	std::cout << node->data << " ";
	inOrderShow(node->rightLink);
}

//BST exists
// post: BST elements are printed in post order
// post-order traversal (prints to stdout)
template <class T>
void BinarySearchTree<T>::postOrderShow() const{
	postOrderShow(root);
}
//BST exists
// post: BST elements are printed in post order
template <class T>
void BinarySearchTree<T>::postOrderShow(TreeNode<T>* node) const {
	if (node == NULL) {
		return;
	}
	postOrderShow(node->leftLink);
	postOrderShow(node->rightLink);
	std::cout << node->data << " ";
}

//pre:: BST exists
// post: size of tree is returned
// return size of tree
template <class T>
int BinarySearchTree<T>::size() const{
	return tree_size;
}

//pre: BST exists
// post: height of tree is returned
// return height of tree
template <class T>
int BinarySearchTree<T>::height() {
	return(height(root));
}

//pre: BST exists
//post: height of tree is returned
template <class T>
int BinarySearchTree<T>::height(TreeNode<T>* node) {
	if (node == NULL) {
		return 0;
	}
	int leftHeight = height(node->leftLink);
	int rightHeight = height(node->rightLink);

	if (leftHeight > rightHeight) {
		return(leftHeight + 1);
	}
	else {
		return(rightHeight + 1);
	}
}

#endif