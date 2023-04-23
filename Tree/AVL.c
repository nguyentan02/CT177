#include<stdio.h>
#include<malloc.h>
typedef int KeyType;
struct Node {
	KeyType Key;
	int Height;
	struct Node *Left;
	struct Node *Right;
};
typedef struct Node * AVLTree;

int getHeight(AVLTree N) {
  	if (N == NULL) return -1;
  	return N->Height ;
}

void printNLR(AVLTree T){
    printf("(%d - %d); ", T->Key, T->Height);
	if(T->Left != NULL) printNLR(T->Left);
	if(T->Right != NULL) printNLR(T->Right);
}
//duyet tien tu
void printLRN(AVLTree T){
	if(T->Left != NULL) printLRN(T->Left);
	if(T->Right != NULL) printLRN(T->Right);
	printf("(%d - %d); ", T->Key, T->Height);
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

int getBalance(AVLTree N) {
  	if (N == NULL) return 0;
  	return getHeight(N->Left) - getHeight(N->Right);
}

AVLTree rightRotate(AVLTree T) {
  	AVLTree x = T->Left;
  	AVLTree y = x->Right;

	T->Left = y;
  	x->Right = T;
  
  	T->Height = max(getHeight(T->Left), getHeight(T->Right)) + 1;
  	x->Height = max(getHeight(x->Left), getHeight(x->Right)) + 1;

  	return x;
}

AVLTree leftRotate(AVLTree T){
	AVLTree x = T->Right;
	AVLTree y = x->Left;
	
	T->Right = y;
	x->Left = T;
	
	T->Height = max(getHeight(T->Left), getHeight(T->Right)) + 1;
  	x->Height = max(getHeight(x->Left), getHeight(x->Right)) + 1;
  	
  	return x;
}

AVLTree leftrightRotate(AVLTree T){
	AVLTree x = T->Left;
	T->Left = leftRotate(x);
	
	AVLTree y = rightRotate(T);
	
	return y;
}

AVLTree rightleftRotate(AVLTree T){
	AVLTree x = T->Right;
	T->Right = rightRotate(x);
	
	AVLTree y = leftRotate(T);
	
	return y;
}

AVLTree newNode(KeyType x){
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  	node->Key = x;
  	node->Left = NULL;
  	node->Right = NULL;
  	node->Height = 0;
  	return node;
}

AVLTree insertNode(KeyType x, AVLTree T){
	
	if(T == NULL) return newNode(x);
	if(x > T->Key) T->Right = insertNode(x, T->Right);
	else if(x < T->Key) T->Left = insertNode(x, T->Left);
	else return T;
	
	T->Height = max(getHeight(T->Left), getHeight(T->Right)) + 1;
	
	int balance = getBalance(T);
	
	if (balance > 1 && x < T->Left->Key) return rightRotate(T);
	
	if (balance < -1 && x > T->Right->Key) return leftRotate(T);
	
	if (balance > 1 && x > T->Left->Key) return leftrightRotate(T);
	
	if (balance < -1 && x < T->Right->Key) return rightleftRotate(T);
	
	return T;
}

AVLTree search(KeyType x, AVLTree Root){
	if (Root == NULL) return NULL;
	else if (Root->Key == x) return Root;
	else if (Root->Key < x) return search(x,Root->Right);
	else return search(x,Root->Left);
}

void printHeight(int height, AVLTree Root){
	if(Root == NULL) return ;
	else if(Root->Height == height) printf("%d ", Root->Key);
	else if(Root->Height > height) {
		printHeight(height, Root->Left);
		printHeight(height, Root->Right);
	}
	else return ;
}

int isAVL(AVLTree T){
	if(T == NULL) return 1;
	else if(getBalance(T) <= 1 && getBalance(T) >= -1) return 1;
	else return 0;
}

void printLeaves(AVLTree T){
	if(T == NULL) return ;
	else if(T->Left == NULL && T->Right == NULL) printf("%d ", T->Key);
	else {
		printLeaves(T->Left);
		printLeaves(T->Right);
	}
}

AVLTree minValueNode(AVLTree node) {
  	AVLTree current = node;

  	while (current->Left != NULL)
    	current = current->Left;
  	return current;
}

AVLTree deleteNode(KeyType key, AVLTree root) {
 
  	if (root == NULL) return root;

  	if (key < root->Key) root->Left = deleteNode(key, root->Left);

  	else if (key > root->Key) root->Right = deleteNode(key, root->Right);

  	else {
    	if((root->Left == NULL) || (root->Right == NULL)) {
    		
      		AVLTree temp = root->Left ? root->Left : root->Right;

      		if(temp == NULL) {
        		temp = root;
        		root = NULL;
      		} 
			else root = temp;
			
      	free(temp);
      	
    	} 
		else {
     		AVLTree temp = minValueNode(root->Right);

      		root->Key = temp->Key;

      		root->Right = deleteNode(temp->Key, root->Right);
    	}
  	}

  	if (root == NULL) return root;

  	root->Height = 1 + max(getHeight(root->Left), getHeight(root->Right));

  	int balance = getBalance(root);
  	
  	if(balance > 1 && getBalance(root->Left) >= 0) return rightRotate(root);

  	if(balance > 1 && getBalance(root->Left) < 0) return leftrightRotate(root);

  	if(balance < -1 && getBalance(root->Right) <= 0) return leftRotate(root);

  	if(balance < -1 && getBalance(root->Right) > 0) return rightleftRotate(root);

  	return root;
}
