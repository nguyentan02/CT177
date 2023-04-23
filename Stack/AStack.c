#include<stdio.h>
#include <string.h>
#define SoPhanTu 100
typedef float ElementType;
typedef struct {
	ElementType DuLieu[SoPhanTu]; 
	int Dinh; 
}Stack;

//Tao danh sach rong
void makenullStack(Stack *S){
	S->Dinh = SoPhanTu;
}

//Kiem tra ngan xep rong
int emptyStack(Stack S){
	return S.Dinh == SoPhanTu;
}

//Kiem tra ngan xap day
int fullStack(Stack S){
	return S.Dinh == 0;
}

//Gia tri dinh stack
ElementType top(Stack S){
	return S.DuLieu[S.Dinh];
}

//Xoa phan tu tai dinh Stack
void pop(Stack *S){
	S->Dinh++;
}

//Them phan tu X vao stack
void push(ElementType X, Stack *S){
	if(fullStack(*S)) {
		printf("Stack day");
	} else {
		S->Dinh--;
		S->DuLieu[S->Dinh] = X;
	}
}

//tính giá tr? c?a m?t bi?u th?c h?u t?
float tinh(char X, float a, float b){
	float kq;
	switch(X){
		case '+':
			kq = a + b;
			break;
		case '-':
			kq = a - b;
			break;
		case '*':
			kq = a * b;
			break;
		case '/':
			kq = a / b;
			break;
	}
	return kq;
}
float chuoi(char *st){
	int i, n = strlen(st) - 1;
	Stack S;
	makenullStack(&S);
	for(i = 0; i < n; i++){
		float tren, duoi;
		if(st[i] != ' '){			
			if(st[i] >= '0' && st[i] <= '9'){		
				push((st[i] - 48), &S);		
			} else {			
				tren = top(S);
				pop(&S);	
				duoi = top(S);
				pop(&S);
				push(tinh(st[i], duoi, tren), &S);	
			}
		}	
	}
	return top(S);
}
 int main(){
	char s[256];
	fgets(s, 256, stdin);
	s[strlen(s)] = '\0';
	printf("%.2f", chuoi(s));

	return 0;
 }

