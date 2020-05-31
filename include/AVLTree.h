#pragma once
#ifndef _AVL_H_
#define _AVL_H_

#include <iostream>

using std::size_t;
using std::ostream;

template <typename ValType>
class AVLTree
{
private:
	struct Node
	{
		ValType data;
		size_t key, height;
		Node* left;
		Node* right;

		Node(ValType your_data, size_t your_key) : data(your_data), key(your_key), height(1), left(NULL), right(NULL) {}
		Node(size_t your_key) : key(your_key), height(1), left(NULL), right(NULL) {}
		
	};

	Node* top;

	size_t Height(Node* subtree) { return (subtree == NULL) ? 0 : subtree->height; }
	int BalanceFactor(Node* subtree) { return Height(subtree->right) - Height(subtree->left); }
	void Recalc(Node* subtree);

	Node* LeftRotation(Node* subtree);
	Node* RightRotation(Node* subtree);
	Node* Balance(Node* subtree);
	Node* FindMin(Node* subtree) { return (subtree->left == NULL) ? subtree : FindMin(subtree->left); }
	Node* DelMin(Node* subtree);
	Node* Search(Node* subtree, size_t key);
	Node* Ins(Node* subtree, ValType data, size_t key);
	Node* Del(Node* subtree, size_t key);
	void Erase(Node*& subtree);

public:

	AVLTree() : top(NULL) {}
	AVLTree(const AVLTree& tree); //For better times to come... :D
	~AVLTree() { Clean(); }

	ValType Find(size_t key);
	void Insert(ValType data, size_t key) { top = Ins(top, data, key); }
	void Delete(size_t key) { top = Del(top, key); }
	void Clean() { Erase(top); }
	bool Empty() { return top == NULL; }
	size_t GetHeight() { return Height(top); }

	friend ostream& operator<<(ostream& out, AVLTree<ValType>& tree); //Same...
};


template<typename ValType>
inline void AVLTree<ValType>::Recalc(Node* subtree)
{
	size_t h_left = Height(subtree->left), h_right = Height(subtree->right);

	subtree->height = ((h_left > h_right) ? h_left : h_right) + 1;
}

template<typename ValType>
typename inline AVLTree<ValType>::Node* AVLTree<ValType>::LeftRotation(Node* subtree)
{
	Node* subsubtree = subtree->right; //subsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsubsub(sub)... Error: Not enough mana ¯\_(ツ)_/¯

	subtree->right = subsubtree->left;
	subsubtree->left = subtree;

	Recalc(subtree);
	Recalc(subsubtree);

	return subsubtree;
}

template<typename ValType>
typename inline AVLTree<ValType>::Node* AVLTree<ValType>::RightRotation(Node* subtree)
{
	Node* subsubtree = subtree->left;

	subtree->left = subsubtree->right;
	subsubtree->right = subtree;

	Recalc(subtree);
	Recalc(subsubtree);

	return subsubtree;
}

template<typename ValType>
typename inline AVLTree<ValType>::Node* AVLTree<ValType>::Balance(Node* subtree)
{
	Recalc(subtree);

	if (BalanceFactor(subtree) == -2)
	{
		if (BalanceFactor(subtree->right) < 0)
			subtree->right = RightRotation(subtree->right);

		subtree = LeftRotation(subtree);
	}
	else if (BalanceFactor(subtree) == -2)
	{
		if (BalanceFactor(subtree->left) > 0)
			subtree->left = LeftRotation(subtree->left);

		subtree = RightRotation(subtree);
	}


	return subtree;
}

template<typename ValType>
typename inline AVLTree<ValType>::Node* AVLTree<ValType>::DelMin(Node* subtree)
{
	if (subtree->left == NULL)
		return subtree->right;

	subtree->left = DelMin(subtree->left);

	return Balance(subtree);
}

template<typename ValType>
typename inline AVLTree<ValType>::Node* AVLTree<ValType>::Search(Node* subtree, size_t key)
{
	while (subtree != NULL)
	{
		if (key < subtree->key)
			subtree = subtree->left;
		else if (key > subtree->key)
			subtree = subtree->right;
		else
			return subtree;
	}

	throw "Error: the node with the specified key doesn't exist";
}

template<typename ValType>
typename inline AVLTree<ValType>::Node* AVLTree<ValType>::Ins(Node* subtree, ValType data, size_t key)
{
	if (subtree == NULL)
		return new Node(data, key);

	if (key < subtree->key)
		subtree->left = Ins(subtree->left, data, key);
	else
		subtree->right = Ins(subtree->right, data, key);

	return Balance(subtree);
}

template<typename ValType>
typename inline AVLTree<ValType>::Node* AVLTree<ValType>::Del(Node* subtree, size_t key)
{
	if (subtree == NULL)
		return NULL;

	if (key < subtree->key)
		subtree->left = Del(subtree->left, key);
	else if (key > subtree->key)
		subtree->right = Del(subtree->right, key);
	else
	{
		Node* subsubtree_left = subtree->left;
		Node* subsubtree_right = subtree->right;

		delete subtree;
		if (subsubtree_right == NULL)
			return subsubtree_left;

		Node* rightmin = FindMin(subsubtree_right);
		rightmin->right = DelMin(subsubtree_right);
		rightmin->left = subsubtree_left;

		return Balance(rightmin);
	}


	return Balance(subtree);
}

template<typename ValType>
inline void AVLTree<ValType>::Erase(Node*& subtree)
{
	if (subtree == NULL)
		return;

	if (subtree->left)
		Erase(subtree->left);
	if (subtree->right)
		Erase(subtree->right);
	delete subtree;
	subtree = NULL;
}

template<typename ValType>
inline ValType AVLTree<ValType>::Find(size_t key)
{
	Node* target = Search(top, key);
	return target->data;
}

#endif // !_AVL_H_