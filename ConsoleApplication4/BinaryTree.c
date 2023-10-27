#include "BinaryTree.h"

struct BinaryTree* CreateBinaryTree()
{
	struct BinaryTree* tree = malloc(sizeof(struct BinaryTree));
	tree->count = 0;
	tree->root = NULL;
	return tree;
}

void FreeBinaryTree(struct BinaryTree* tree)
{
	///
}

struct BinaryTreeNode* InsertBinaryTree(struct BinaryTree* tree, int data)
{
	struct BinaryTreeNode* node = malloc(sizeof(struct BinaryTreeNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	if (tree->root == NULL)
	{
		tree->root = node;
		tree->count++;
		return;
	}

	struct BinaryTreeNode* current = tree->root;
	while (data != current->data)
	{
		if (data < current->data)
		{
			if (current->left == NULL)
			{
				current->left = node;
				tree->count++;
				return node;
			}
			current = current->left;
		}
		else
		{
			if (current->right == NULL)
			{
				current->right = node;
				tree->count++;
				return node;
			}
			current = current->right;
		}
	}

	free(node);
	return NULL;
}

struct BinaryTreeNode* BinaryTreeMin(struct BinaryTree* tree)
{
	if (tree->root == NULL)
		return NULL;

	struct BinaryTreeNode* current = tree->root;
	while (current->left != NULL)
		current = current->left;

	return current;
}

struct BinaryTreeNode* BinaryTreeMax(struct BinaryTree* tree)
{
	if (tree->root == NULL)
		return NULL;

	struct BinaryTreeNode* current = tree->root;
	while (current->right != NULL)
		current = current->right;

	return current;
}

void InOrderTraversal(struct BinaryTreeNode* node)
{
	if (node != NULL)
	{
		InOrderTraversal(node->left);
		printf("%d ", node->data);
		InOrderTraversal(node->right);
	}
}

void PrintBinarySortedTree(struct BinaryTree* tree)
{
	if (tree->root == NULL)
		return;

	InOrderTraversal(tree->root);
	printf("\n");
}

struct BinaryTreeNode* BinaryTreeSearch(struct BinaryTreeNode* node, int data)
{
	if (node == NULL)
		return NULL;

	if (data == node->data)
		return node;

	if (data < node->data)
		return BinaryTreeSearch(node->left, data);

	return BinaryTreeSearch(node->right, data);
}
