#include "binary_trees.h"

/**
 * tree_is_perfect - Checks if a binary tree is perfect.
 * A perfect binary tree has the same number of levels,
 * and each node has either 2 children or no children.
 * @tree: Pointer to the root node of the tree.
 * Return: 0 if the tree is not perfect.
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (tree->left && tree->right)
	{
		left = 1 + tree_is_perfect(tree->left);
		right = 1 + tree_is_perfect(tree->right);
		if (right == left && right != 0 && left != 0)
			return (right);
		return (0);
	}
	else if (!tree->left && !tree->right)
		return (1);
	return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree.
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int result = 0;

	if (tree == NULL)
		return (0);
	
	result = tree_is_perfect(tree);
	
	if (result != 0)
		return (1);
	
	return (0);
}
