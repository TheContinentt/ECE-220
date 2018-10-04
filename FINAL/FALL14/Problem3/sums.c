#include <stdio.h>
#include "vector.h"
#include "tree.h"

// FUNCTION DEFINITIONS
void findPathRecursive(node * root, int expectedSum, int currentSum, vector * path);
void findPath(node * root, int expectedSum);


// Don't change the main function
int main(int argc, char * argv[])
{
    if (argc < 1)
    {
        printf("Not enough arguments\n");
        return -1;
    }

    node * root = create_tree(argv[1]);
    int sum;
    printf("Please enter a sum: ");
    scanf("%d", &sum);

    findPath(root, sum);
    delete_tree(root);
}

// Recursive helper function for printing paths within a tree
// that add up to an expected sum
void findPathRecursive(node * root, int expectedSum, int currentSum, vector * path)
{
    // YOUR CODE HERE
	/*if (root == NULL)
		return;
	if (currentSum == expectedSum)
	{
		path->contents[path->back] = root->value;
		return;
	}
	else if (currentSum > expectedSum)
	{
		path->contents[path->back-1] = 0;
		return;
	}
	else
	{
		findPathRecursive(root->left, expectedSum, currentSum, path);
	}*/
}

// Finds and prints all paths within a tree that add to an expected sum
void findPath(node * root, int expectedSum)
{
    // YOUR CODE HERE
	/*vector * Store = new vector;
	vectorInit(Store);
	int base = root->value;
	pushBack(Store, base);
	findPathRecursive(root, expectedSum, base, Store);*/
	//printf("%d\n", Store->contents[Store->back+2]);
	//printf("%d\n", Store->back);
}
