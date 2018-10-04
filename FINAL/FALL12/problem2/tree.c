#include <stdlib.h>
#include "tree.h"

/* Counte the number of negative values stored in a tree */
int countNegatives(struct node* root)
{
   /* Implement Me */
	if (root == NULL)
	{
		return 0;
	}
	else if (root->data < 0)
	{
		return 1 + countNegatives(root->left) + countNegatives(root->right);
	}
	else
	{
		return countNegatives(root->left) + countNegatives(root->right);
	}
   return 0;
}
