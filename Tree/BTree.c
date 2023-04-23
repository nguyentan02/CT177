#include <stdio.h>
#include <malloc.h>
typedef int DataType;
struct Node {
	DataType Data;
	struct Node *Left, *Right;
};
typedef struct Node* Tree;

//Tao danh sach rong
void makenullTree(Tree *pT){ 
	(*pT) = NULL; 
}

//kiem tra rong
int emptyTree(Tree T){
	return T == NULL;
}

//xac dinh con Left
Tree leftChild(Tree n){
	if(n != NULL) return n->Left;
	else return NULL;
}

//xac dinh con Right
Tree rightChild(Tree n){
	if (n != NULL) return n->Right;
	else return NULL;
}

//kiem tra nut co phai l� n�t l� 
int isLeaf(Tree n){
	if(n != NULL)
	return(leftChild(n) == NULL)&&(rightChild(n) == NULL);
	else return 0;
} 

//duyet tien tu
void preOrder(Tree T){
	printf("%c ",T->Data);
	if (leftChild(T) != NULL) preOrder(leftChild(T));
	if(rightChild(T) != NULL) preOrder(rightChild(T));
}

//duyet trung tu
void inOrder(Tree T){
	if (leftChild(T) != NULL)inOrder(leftChild(T));
	printf("%c ",T->Data);
	if(rightChild(T) != NULL) inOrder(rightChild(T));
}

//duyet hau tu
void posOrder(Tree T){
	if(leftChild(T) != NULL) posOrder(leftChild(T));
	if(rightChild(T) != NULL) posOrder(rightChild(T));
	printf("%c ", T->Data);
}

//xac dinh so nut cua cay
int nb_nodes(Tree T){
	if(emptyTree(T)) return 0;
	else return 1 + nb_nodes(leftChild(T))+ nb_nodes(rightChild(T));
}

//tao cay moi tu 2 cay co san
/*Tree createTree(DataType v,Tree l,Tree r){ 
	Tree N;
	N= (struct TNode*)malloc(sizeof(struct TNode));
	N->Data=v;
	N->Left=l;
	N->Right=r;
	return N;
}*/

//T?o m?t n�t c� d? li?u l�
Tree createNode(DataType x){
	Tree n = (struct Node*)malloc(sizeof(struct Node));
	n->Data = x;
	n->Left = NULL;
	n->Right = NULL;
	return n;
}

//hi?n th? t?t c? c�c du?ng di (t? n�t g?c d?n n�t l�) v� c� d? d�i du?ng di b?ng m?t gi� tr? cho tru?c
void printArray(int path[], int len){
	int i;
 	for(i=0;i<len;i++)
    	printf("%d",path[i]);
    printf("\n");
}
void printAllPaths(Tree T, int path[], int len, int pathlen){
	if(T == NULL) return ;
	path[len] = T->Data;
	len++;
	if(T->Left == NULL && T->Right == NULL){
		if(pathlen == len - 1) printArray(path, len);
	}
	else {
		printAllPaths(T->Left, path, len, pathlen);
		printAllPaths(T->Right, path, len, pathlen);
	}
}

//x�c d?nh xem x c� l� gi� tr? c?a m?t n�t trong c�y nh? ph�n hay kh�ng.
Tree findElement(DataType x, Tree T){
	if(T == NULL) return NULL;
	if(T->Data == x) return T;
	else {
		if(findElement(x, T->Left) != NULL) return findElement(x, T->Left);
		return findElement(x, T->Right );
	}	
}

//chuy?n d?i m?t c�y nh? ph�n sang c�y ph?n chi?u c?a n�
Tree convertTree(Tree T){
    if(T == NULL) return NULL;
    Tree M;
    M = (struct Node*)malloc(sizeof(struct Node));
    M->Data = T->Data;
    M->Left = convertTree(T->Right);
    M->Right = convertTree(T->Left);
    return M;
}

//ki?m tra xem hai c�y c� l� ph?n chi?u c?a nhau hay kh�ng
int isMirrors(Tree T, Tree M){
  if (T == NULL || M == NULL) return T == NULL && M == NULL;
  return T->Data == M->Data && isMirrors(T->Left, M->Right) && isMirrors(T->Right, M->Left);
}

//d?m s? n�t c� d? hai con
int getFullNodes(Tree root){
	if(root == NULL) return 0; 
	if(root != NULL) {
		if(root->Left == NULL) return getFullNodes(root->Right);
		else if(root->Right == NULL) return getFullNodes(root->Left);
	}	
	return 1 + getFullNodes(root->Right) + getFullNodes(root->Left);
}

//t�m gi� tr? l?n nh?t trong c�y nh? ph�n
DataType max3(DataType a, DataType b, DataType c){
	DataType max = a > b ? a : b;
	return max > c ? max : c;
}

DataType findMax(Tree T){
	if(T == NULL) return 0;
	return max3(T->Data, findMax(T->Left), findMax(T->Right));
}

//d?ng m?t c�y nh? ph�n t? c�c bi?u th?c duy?t ti?n t? v� trung t?
int findIndex(DataType x, char in[], int star, int end){
    int i=star;
    while (i<=end){
         if (x==in[i])
             return i;
         else
             i++;
   }
   return i;
}
int preIndex = 0;
/*Tree createTree(DataType pre[], DataType in[], int start, int end) {
	Tree N = NULL;
	if(start <= end){
		N = (struct Node*)malloc(sizeof(struct Node));
		N->Data = pre[preIndex];
		preIndex++;
		if(start == end) {
			N->Left = NULL;
			N->Right = NULL;
		} else {
			int inIndex = findIndex(N->Data, in, start, end);
			N->Left = createTree(pre, in, start, inIndex - 1);
			N->Right = createTree(pre, in, inIndex + 1, end);
		}
	}
	return N;
}*/







