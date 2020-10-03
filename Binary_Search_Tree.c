#include<stdio.h>
#include<stdlib.h>

/*
Node structure for binary tree.
Info : value at that node.
count : number of nodes of same value.
lchild : left child pointer
rchild : right child pointer
*/

struct btnode{
	int info;
	int count;
	struct btnode *lchild,*rchild;
};

typedef struct btnode BTNODE;

/*
Different type of utility function for binary tree.
*/

BTNODE *insert(BTNODE *root,int x);
BTNODE *delete(BTNODE *root,int x);
BTNODE *minval(BTNODE *root);
void predisplay(BTNODE *root);
void indisplay(BTNODE *root);
void postdisplay(BTNODE *root);
int countnode(BTNODE *root);
int countleaf(BTNODE *root);
int countnonleaf(BTNODE *root);
int checkstrict(BTNODE *root,int ch);

int main()
{
	BTNODE *root=NULL;
	int ch;
	printf("1.Insert in Tree\n");
	printf("2.Delete an element\n");
	printf("3.Display Preorder Traversal\n");
	printf("4.Display Inorder Traversal\n");
	printf("5.Display Postorder Traversal\n");
	printf("6.Count number of nodes\n");
	printf("7.Number of leaf node\n");
	printf("8.Number of non-leaf node\n");
	printf("9.Check Strict Binary tree or not\n");
	printf("10.Exit\n");
	while(1)
	{
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter number you want to insert : ");
				scanf("%d",&ch);
				root = insert(root,ch);
				break;
			case 2:
				printf("enter number you want to delete : ");
				scanf("%d",&ch);
				root = delete(root,ch);
				break;
			case 3:
				display(root);
				printf("\n");
				break;
			case 4:
				indisplay(root);
				printf("\n");
				break;
			case 5:
				postdisplay(root);
				printf("\n");
				break;
			case 6:
				printf("Number of nodes = %d\n",countnode(root));
				break;
			case 7:
				printf("Number of leaf node = %d\n",countleaf(root));
				break;
			case 8:
				printf("Number of non-leaf node = %d\n",countnonleaf(root));
				break;
			case 9:
				ch=1;
				if(checkstrict(root,ch))
				printf("A Strict Binary Tree\n");
				else
				printf("Not a Strict Binary Tree\n");
				break;
			case 10:
				exit(1);
		}
	}
	return 0;
}

/*
Insert a node of particular value x in binary search tree.
If already exists, count will be incremented.
*/
BTNODE *insert(BTNODE *root,int x)
{
	if(root==NULL)
	{
		root = (BTNODE *)malloc(sizeof(BTNODE));
		root->info = x;
		(root->count)++;
		root->lchild  = root->rchild = NULL;
		return root;
	}
	else if(root->info > x)
	{
		root->lchild = insert(root->lchild,x);
	}
	else if(root->info < x)
	{
		root->rchild = insert(root->rchild,x);
	}
	else
	(root->count)++;
	return root;
}

/*
Delete a particular node from binary search tree.
if count is greater than 1, count will be decremented.
*/
BTNODE *delete(BTNODE *root,int x)
{
	if(root==NULL)
	return NULL;
	else if(root->info > x)
	root->lchild = delete(root->lchild,x);
	else if(root->info < x)
	root->rchild = delete(root->rchild,x);
	else{
		  if(root->count > 1)
		  (root->count)--;
		  else if(root->lchild==NULL)
		  {
		  	BTNODE *temp = root->rchild;
		  	free(root);
		  	return temp;
		  }
		  else if(root->rchild==NULL)
		  {
		  	BTNODE *temp = root->lchild;
		  	free(root);
		  	return temp;
		  }
		  else
		  {
		  	BTNODE *temp = minval(root->rchild);
		  	root->info = temp->info;
		  	root->rchild = delete(root->rchild,temp->info);
		  }
	}
	return root;
}

/*
Find minimum value node given root node.
*/
BTNODE *minval(BTNODE *root)
{
	if(root->lchild==NULL)
	return root;
	return minval(root->lchild);
}

/*
Preorder traversal of binary search tree.
*/
void predisplay(BTNODE *root)
{
	if(root!=NULL)
	{
		int i=0;
		while(i<(root->count)){
		printf("%d  ",root->info);
		i++;
	}
		predisplay(root->lchild);
		predisplay(root->rchild);
	}
}

/*
Inorder traversal of binary search tree.
*/
void indisplay(BTNODE *root)
{
	if(root!=NULL)
	{
		int i=0;
		indisplay(root->lchild);
		while(i<(root->count)){
		printf("%d  ",root->info);
		i++;
	}
	    indisplay(root->rchild);
	}
}

/*
Postorder traversal of binary search tree.
*/
void postdisplay(BTNODE *root)
{
	if(root!=NULL)
	{
		int i=0;
		postdisplay(root->lchild);
		postdisplay(root->rchild);
		while(i<(root->count))
		{
			printf("%d  ",root->info);
			i++;
		}
	}
}

/*
Count number of nodes in binary search tree.
*/
int countnode(BTNODE *root)
{
	if(root==NULL)
	return 0;
	return (1+countnode(root->lchild)+countnode(root->rchild));
}

/*
Count number of leaf nodes in binary search tree.
*/
int countleaf(BTNODE *root)
{
	if(root==NULL)
	return 0;
	if(root->lchild==NULL && root->rchild==NULL)
	return 1;
	return (countleaf(root->lchild)+countleaf(root->rchild));
}

/*
Count number of non-leaf nodes in binary search tree.
*/
int countnonleaf(BTNODE *root)
{
	if(root==NULL)
	return 0;
	if(root->lchild==NULL && root->rchild==NULL)
	return 0;
	return (1+countnonleaf(root->lchild)+countnonleaf(root->rchild));
}

/*
Check if given binary search tree is strict or not.
*/
int checkstrict(BTNODE *root,int ch)
{
	if(root==NULL)
	return ;
	if(root->lchild==NULL && root->rchild!=NULL)
	ch=0;
	if(root->lchild!=NULL && root->rchild==NULL)
	ch=0;
	 checkstrict(root->lchild,ch);
	 checkstrict(root->rchild,ch);
	 return ch;
}
