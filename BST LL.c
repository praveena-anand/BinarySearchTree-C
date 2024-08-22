// PRAVEENA ANAND [CH.SC.U4CSE23044]

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *left, *right;
} node;

node *create()
{
	node *newnode;
	
	newnode = (node *)malloc(sizeof(node));
	
	if (newnode == NULL)
	{
		printf("Memory Allocation Failed!\n");
		exit(1);
	}
	
	int x;
	
	printf("Enter the Data : ");
	scanf("%d", &x);
	
	if (x == -1)
		return 0;
		
	newnode -> data = x;
	
	printf("Left Child of %d : ", x);
	newnode -> left = create();
	
	printf("Right Child of %d : ", x);
	newnode -> right = create();
	
	return newnode;	
}

node *search(node *root, int key)
{
	if (root == NULL)
		return NULL;
		
	else if (key == root -> data)
		return root;
		
	else if (key < root -> data)
		return search(root -> left, key);
		
	else if (key > root -> data)
		return search(root -> right, key);
}

int main()
{
	node *root = create();
	
	int key;
	printf("Enter the Key : ");
	scanf("%d", &key);
	
	int result = search(root, key);
	
	if (result != NULL)
		printf("%d Found!\n", key);
		
	else
		printf("%d Not Found!\n", key);
		
	return 0;
}
