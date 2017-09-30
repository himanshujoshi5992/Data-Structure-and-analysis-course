#include <stdio.h>
#include <stdlib.h>

struct node
{
  char data;
  struct node* left;
  struct node* right;
};
 
/* Prototypes for utility functions */
int search(char arr[], int strt, int end, char value);
struct node* newNode(char data);
 
/* Recursive function to construct binary of size len from
   Inorder traversal in[] and Preorder traversal pre[].  Initial values
   of inStrt and inEnd should be 0 and len -1.  The function doesn't
   do any error checking for cases where inorder and preorder
   do not form a tree */

struct node* buildTree(char in[], char pre[], int inStrt, int inEnd)
{
  static int preIndex = 0;
 
  if(inStrt > inEnd)
     return NULL;
 
  /* Pick current node from Preorder traversal using preIndex
    and increment preIndex */
  struct node *tNode = newNode(pre[preIndex++]);
 
  /* If this node has no children then return */
  if(inStrt == inEnd)
    return tNode;
 
  /* Else find the index of this node in Inorder traversal */
  int inIndex = search(in, inStrt, inEnd, tNode->data);
 
  /* Using index in Inorder traversal, construct left and
     right subtress */
  tNode->left = buildTree(in, pre, inStrt, inIndex-1);
  tNode->right = buildTree(in, pre, inIndex+1, inEnd);
 
  return tNode;
}
 

int search(char arr[], int strt, int end, char value)
{
	int i;
	for(i = strt; i <= end; i++)
	{
	if(arr[i] == value)
		return i;
	}
}

struct node* newNode(char data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

void printInorder(struct node* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left);

	/* then print the data of node */
	printf("%c ", node->data);

	/* now recur on right child */
	printInorder(node->right);
}

void printPreorder(struct node* node) {
	if(node == NULL)
		return;
	printf("%c ",node->data);
	printPreorder(node->left);
	printPreorder(node->right);
}

void printPostorder(struct node* node) {
	if(node == NULL)
		return;
	printPostorder(node->left);
	printPostorder(node->right);
	printf("%c ", node->data);
}
void printLevelorder(struct node* node) {
	insert(node);
	while(queueNotEmpty()) {
		insert(node->left);
		insert(node->right);
		
	}
}
void main() {
	/*
	int preorder[100],inorder[100];
	int n;
	scanf("%d", &n);
	for(int i = 0;i < n;i++) 
		scanf("%d", &preorder[i]);
	for(int i = 0;i < n;i++) 
		scanf("%d", &inorder[i]);
	*/
	char in[] = {'D', 'B', 'E', 'A', 'F', 'C','I','G','J','H'};
	char pre[] = {'A', 'B', 'D', 'E', 'C', 'F','G','I','H','J'};
	int len = sizeof(in)/sizeof(in[0]);
	struct node *root = buildTree(in, pre, 0, len - 1);
	printf("Inorder traversal of the constructed tree is: ");
	printInorder(root); printf("\n");
	printf("Preorder traversal of the constructed tree is: ");
	printPreorder(root); printf("\n");
	printf("Postorder traversal of the constructed tree is: ");
	printPostorder(root); printf("\n");
	printf("Levelorder traversal of the constructed tree is: ");
	printLevelorder(root);
}