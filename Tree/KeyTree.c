#include<stdio.h>
#include<malloc.h>
//#include<string.h>

typedef int KeyType;
struct Node{
	KeyType Key;
	struct Node *Left, *Right;
};
typedef struct Node* Tree;

//t�m ki?m kh�a x trong c�y t�m ki?m nh? ph�n
Tree search(KeyType x,Tree Root){
	if (Root == NULL) return NULL;
	else if (Root->Key == x) return Root;
	else if (Root->Key < x) return search(x,Root->Right);
	else return search(x,Root->Left);
}

//th�m kh�a X v�o c�y t�m ki?m nh? ph�n
void insertNode(KeyType x, Tree *pT){
	if((*pT) == NULL){
		(*pT) = (struct Node*)malloc(sizeof(struct Node));
		(*pT)->Key = x;
		(*pT)->Left = NULL;
		(*pT)->Right = NULL;
	} 
	else if((*pT)->Key == x) printf("Da ton tai khoa x");
	else if((*pT)->Key > x) insertNode(x,&(*pT)->Left);
	else insertNode(x,&(*pT)->Right);
}

//xoa khoa x trong cay T
KeyType deleteMin(Tree *pT){
	KeyType k;
	if((*pT)->Left == NULL){
		
		k = (*pT)->Key;
		
		(*pT) = (*pT)->Right;
		
		return k;
	}
	
	else return deleteMin(&(*pT)->Left);
}

void deleteNode(KeyType x, Tree *pT){
	if((*pT)!=NULL) {
		
		if(x <(*pT)->Key) deleteNode(x,&(*pT)->Left);
		
		else if(x >(*pT)->Key) deleteNode(x,&(*pT)->Right);
		
		else if(((*pT)->Left==NULL) && ((*pT)->Right==NULL)) (*pT)=NULL; 
		
		else if((*pT)->Left==NULL) (*pT) = (*pT)->Right;
		
		else if((*pT)->Right==NULL) (*pT) = (*pT)->Left;
		
		else (*pT)->Key = deleteMin(&(*pT)->Right);
	}	
}

//liet ke cac gia tri khoa tren duong di tim kiem khoa X
void printPath(int x,Tree root){
	if (root == NULL) printf("-> Khong thay");
	else if (root->Key == x) printf("%d -> Tim thay", root->Key);
	else if (root->Key < x){
		printf("%d ", root->Key);
		printPath(x,root->Right);
	}		
	else {
		printf("%d ", root->Key);
		printPath(x,root->Left);
	}	
}

//h�m duy?t tien t? c�y t�m ki?m nh? ph�n T
void preOrder(Tree T){
	printf("%d ", T->Key);
	if(T->Left != NULL) preOrder(T->Left);
	if(T->Right != NULL) preOrder(T->Right);
}

//duy?t h?u t? c�y t�m ki?m nh? ph�n T
void posOrder(Tree T){
	if(T->Left != NULL) posOrder(T->Left);
	if(T->Right != NULL) posOrder(T->Right);
	printf("%d ", T->Key);
}

//h�m duy?t trung t? c�y t�m ki?m nh? ph�n T
void inOrder(Tree T){
	if(T->Left != NULL) inOrder(T->Left);
	printf("%d ", T->Key);
	if(T->Right != NULL) inOrder(T->Right);
}

// kiem tra cay goc co rong khong
int isEmpty(Tree T){
	return T == NULL ;
}

//t�m ki?m n�t anh em ru?t ph?i c?a n�t c� kh�a x trong c�y t�m ki?m nh? ph�n
Tree rightSibling(int X, Tree T){
	Tree P = T, pt = NULL;
	while(P != NULL){
		if(P->Key == X) {
			if(pt != P) return pt;
			else return NULL;
		}
		pt = P->Right;
		if(P->Key > X) P = P->Left;
		else P = P->Right;
	}
	return NULL;	
}

//t�m ki?m n�t cha c?a n�t c� kh�a x trong c�y t�m ki?m nh? ph�n
Tree getParent(int x, Tree T){
	Tree P = T, parent = NULL;
	while(P != NULL){
		if(P->Key == x) return parent;
		parent = P;
		if(P->Key > x) P = P->Left;
		else P = P->Right;
	}
	return NULL;
}

//t�nh chi?u cao c?a n�t c� kh�a x trong c�y T
int hNode(int X, Tree T){
    if(T == NULL) return -1;
	if(T->Key == X){
	    if(T->Left == NULL && T->Right == NULL) return 0;
	    int l = 0, r = 0;
	    if(T->Left != NULL) l = hNode(T->Left->Key, T-> Left);
	    if(T->Right != NULL) r = hNode(T->Right->Key, T->Right);
	    return l > r ? l + 1 : r + 1;
	}
	else if(T->Key < X) return hNode(X, T->Right);
	else return hNode(X, T->Left);
}

//kh?i t?o v� tr? v? m?t c�y r?ng
Tree initTree(){
    Tree T = NULL;
    return T;
}

//t�nh chi?u cao c�y T
int getHeight(Tree T){
	if(T == NULL) return -1;
	int l = 0, r = 0;
	if(T->Left != NULL) l = 1 + getHeight(T-> Left);
	if(T->Right != NULL) r = 1 +  getHeight(T->Right);
	return l > r ? l: r;
}

//n�t d?ng sau n�t c� kh�a x trong c�y TKNP trong ph�p duy?t trung t?
Tree getMin(Tree T){
	if(T==NULL) return NULL;
	if(T->Left == NULL) return T;
	return getMin(T->Left);
}

Tree getNext(KeyType x, Tree T){
	Tree P = T, pt = NULL;
	while(P != NULL){
		if(P->Key == x){
			if(T->Right == NULL) return pt;
			else return getMin(P->Right);
		}
		else if(P->Key > x){
			pt = P;
			P =P->Left;
		}
		else P = P->Right;
	}
	return NULL;
}

//n�t d?ng tru?c n�t c� kh�a x cho tru?c trong ph�p duy?t trung t?
Tree getMax(Tree T){
	if(T == NULL) return NULL;
	if(T->Right == NULL) return T;
	return getMax(T->Right);
}

Tree getPrevious(KeyType x, Tree T){
	Tree P = T, pt = NULL;
	while(P != NULL){
		if(P->Key == x){
			if(P->Left == NULL) return pt;
			else return getMax(P->Left);
		}
		else if(P->Key < x){
			pt = P;
			P = P->Right;
		}
		else P= P->Left;
	}
	return NULL;
}
