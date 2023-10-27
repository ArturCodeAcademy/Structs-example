#pragma once

#include <stdlib.h>

struct BinaryTreeNode
{
	int data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
};

struct BinaryTree
{
	int count;
	struct BinaryTreeNode* root;
};

struct BinaryTree* CreateBinaryTree();
void FreeBinaryTree(struct BinaryTree* tree);
struct BinaryTreeNode* InsertBinaryTree(struct BinaryTree* tree, int data);
void PrintBinarySortedTree(struct BinaryTree* tree);
struct BinaryTreeNode* BinaryTreeMin(struct BinaryTree* tree);
struct BinaryTreeNode* BinaryTreeMax(struct BinaryTree* tree);
struct BinaryTreeNode* BinaryTreeSearch(struct BinaryTreeNode* node, int data);