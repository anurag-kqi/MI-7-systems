/* program of postorder traversal of tree*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};

/* creat new node*/
struct node* newNode (int data)
{
/*allocate memory to new node*/
struct node* node = (struct node*)malloc(sizeof(struct node));
/*assign data to new node*/
node->data = data;
/*initialize left and right children as NULL*/
node->left = NULL;
node->right = NULL;
return(node);
}

void printPostorder(struct node* node)
{
 /*print nodes according to postorder traversal*/
  if (node == NULL)
  return;
  /*left subtree*/
  printPostorder(node->left);
  /*right subtree*/
  printPostorder(node->right);
  /*node*/
  printf("%d", node->data);
}

int
main()
{
/*create root*/
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  printf("\nPostorder traversal of binary tree is \n");
  printPostorder(root);
  getchar();
  return 0;
}
