/* Devin Lepur
   Red ID: 825148526
   CS-496
   Prof Kraft
*/

// BinarySearchTree.h: Header file for BinaryBinarySearchTree.cpp
// The only way to insert data in a tree is with the insert function, thus 
// satisfying the BST rule giving it a well behaved ordering to the type T.
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream> // for std::cout
namespace BST_NS
{
	template<class T>
	class BinarySearchTree; //forward declaration
	template<class T>
	class TreeNode {
	public:
		TreeNode() : data(NULL), leftLink(NULL), rightLink(NULL) {}
		TreeNode(T theData, TreeNode<T>* left, TreeNode<T>* right)
			: data(theData), leftLink(left), rightLink(right) {}
		friend class BinarySearchTree<T>;
	private:
		T data;
		TreeNode<T>* leftLink;
		TreeNode<T>* rightLink;
	};
	// supply the pre and post conditions for each method
	template<class T>
	class BinarySearchTree {
	private:
		TreeNode<T>* root;
		int tree_size;
	public:
		// default ctor
		BinarySearchTree() : root(NULL), tree_size(0) {}
		// copy ctor
		BinarySearchTree(const BinarySearchTree& other);
		// virtual dtor
		virtual ~BinarySearchTree();
		// insert an item to the tree
		void insert(T item);
		// insert an item to the tree
		TreeNode<T>* insert(TreeNode<T>* node, T item);
		// remove an item from the tree
		void remove(T item);
		TreeNode<T>* remove(TreeNode<T>* node, T item);
		// check if an item exists in the tree
		bool inTree(T item) const;
		// overloading assignment operator
		BinarySearchTree& operator=(const BinarySearchTree other);
		// empty the tree
		void makeEmpty();
		// pre-order traversal (prints to stdout)
		void preOrderShow() const;
		void preOrderShow(TreeNode<T>* node) const;
		// in-order traversal (prints to stdout)
		void inOrderShow() const;
		void inOrderShow(TreeNode<T>* node) const;

		// post-order traversal (prints to stdout)
		void postOrderShow() const;
		void postOrderShow(TreeNode<T>* node) const;
		// return size of tree
		int size() const;
		// return height of tree
		int height();
		int height(TreeNode<T>* node);
		bool sameTree(TreeNode<T>* origNode, TreeNode<T>* otherNode);
	};
} // BST_NS 
#endif