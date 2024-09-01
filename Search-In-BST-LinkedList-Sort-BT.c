// PRAVEENA ANAND [CH.SC.U4CSE234044]

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *left, *right;
} bst;

bst *create(int data)
{
	bst *newnode = (bst *)malloc(sizeof(bst));
	newnode -> data = data;
	newnode -> right = NULL;
	newnode -> left = NULL;
	
	return newnode;
}

bst *insert(bst *root, int data)
{
	if 	(root == NULL)
		root = create(data);
		
	else if (data < root -> data)
		root -> left = insert(root -> left, data);
		
	else if (data > root -> data)
		root -> right = insert(root -> right, data);
		
	return root;
}

bst *search(bst *root, int key)
{
	if (root == NULL || root -> data == key)
		return root;
		
	else if (key < root -> data)
		return search(root -> left, key);
		
	else if (key > root -> data)
		return search(root -> right, key);
}

void inorder(bst *root)
{
	if (root == NULL)
		return;
		
	inorder(root -> left);
	printf("%d\t", root -> data);
	inorder(root -> right);
}

int main()
{
	int ch;
	
	bst *root = NULL;
	do
	{
		int data;
		printf("Enter the Data : ");
		scanf("%d", &data);
		root = insert(root, data);
		
		printf("Do you want to add more nodes (0/1) : ");
		scanf("%d", &ch);
	}
	while (ch);
	
	int key;
	
	printf("Enter the Key : ");
	scanf("%d", &key);
	
	if (search(root, key))
		printf("%d is present!\n", key);
	
	else
		printf("%d is not present!\n", key);
		
	printf("The Inorder Traversal is : \n");
	inorder(root);
	
	return 0;	
}
