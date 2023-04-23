#include <stdio.h>
#include <malloc.h> 
typedef int ElementType;
struct Node {
    ElementType Element;
    struct Node* Next;
};
typedef struct Node* Position;
typedef Position List;


//kh?i t?o m?t danh sách r?ng
void makenullList(List *L){
    (*L) = (struct Node*)malloc(sizeof(struct Node));
    (*L)->Next = NULL;
} 


//ph?n t? x có t?n t?i trong danh sách các s? nguyên hay không
ElementType member(ElementType X, List L){
	Position P = L;
	while (P->Next != NULL){
		if(P->Next->Element == X) return 1;
		P = P->Next;
	}
	return 0;
}


//hàm tr? v? v? trí d?u tiên
Position first(List L){
    return L;
}


//ki?m tra danh sách có r?ng không
int emptyList(List L){
    return (L->Next == NULL);
}


//v? trí ph?n t? cu?i cùng
Position endList(List L){
    Position P = L;
    while (P->Next != NULL){
        P = P->Next;
    }
    return P;
}


//v? trí ph?n t? k? ti?p
Position next(Position P,List L){
    return (P->Next);
}


//chèn ph?n t? x vào d?u danh sách
void addFirst(ElementType X, List *pL){
	Position T;
    T = (struct Node*)malloc(sizeof(struct Node));
	T->Element = X;
	T->Next = (*pL)->Next;
	(*pL)->Next = T;	
}


//Nh?p các các ph?n t? c?a m?t t?p h?p t? bàn phím
List readSet(){
	List L;
	ElementType n, i, x;
	makenullList(&L);
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &x);
		if(member(x, L) == 0) addFirst(x, &L);
	}
	return L;
}


//tr? v? v? trí ph?n t? tru?c P
Position previous(Position P,List L){
    if(P == first(L))
        return NULL;
    else{
        Position T = first(L);
            while(T->Next != P)
                T = T->Next;
    	return T;
    }
}


// l?y n?i dung ph?n t? t?i v? trí P trong danh sách
ElementType retrieve(Position P,List L){
    return P->Next->Element;
}


//tìm v? trí xu?t hi?n d?u tiên c?a x trong danh sách
Position locate(ElementType X, List L){
    Position P = L;
    ElementType found = 0;
    while ((P->Next != NULL)&&(found == 0)){
        if ((P->Next->Element) == X)
            found = 1;
        else P = P->Next;
    }
    return P;
}


//xen ph?n t? x vào v? trí p trong danh sách
void insertList(ElementType X,Position P, List *L){
    Position T;
    T = (struct Node*)malloc(sizeof(struct Node));
    T->Element = X;
    T->Next = P->Next;
    P->Next = T;
}


//Cho phép xóa ph?n t? ? v? trí p trong danh sách
void deleteList(Position P,List *L){
    Position Temp;
    if(P->Next != NULL){
        Temp = P->Next;
        P->Next = Temp->Next;
        free(Temp);
    } 
	else printf("\nLoi! Danh sach rong khong the xoa");
}


//nh?p danh sách t? bàn phím
void readList(List *L){
    ElementType i, n, X;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&X);
        insertList(X,endList(*L),L);
    }
}
		

//nh?p danh sách t? bàn phím mà gia tr? không trùng nhau
void Nhap(List *L){
	makenullList(&*L);
	int n, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		int j;
		scanf("%d", &j);
		if(member(j, *L) == 0){
			addFirst(j, &*L);
		}
	}
}


//in danh sách ra màn hình
void printList(List L){
    Position P;
    P=first(L);
    while(P != endList(L)){           
        printf("%d\t",retrieve(P,L));
        P = P->Next;
    }
    printf("\n");
}


//tính t?ng t?t c? ph?n t? trong danh sách
ElementType sumList(List L){
	Position P = first(L), E = endList(L);
	ElementType S = 0;
	while(P != E){
		S = S + retrieve(P, L);
		P = next(P, L); 
	}
}


//tính trung bình c?ng giá tr? các ph?n t? trong danh sách
float getAvg(List L){
	Position P = L;
	float S = 0, i = 0;
	if(P->Next == NULL) S = -10000;
	else {
		while(P->Next != NULL){
			S = S + P->Next->Element;
			P = P->Next; 
			i++;
		}
		S = S/i;
	}
	return S;
}


//n?i ph?n t? x vào trong danh sách
void append(ElementType X,List *L){
	insertList(X,endList(*L), &*L);
}


//Tính t?p h?p hi?u c?a 2 t?p h?p bi?u di?n b?i 2 danh sách L1, L2;
List difference(List L1, List L2){
	Position pL;
	makenullList(&pL);
	while(L1->Next != NULL){
		if(member(L1->Next->Element, L2) == 0){
			insertList(L1->Next->Element, endList(pL), &pL);
		}
	L1 = L1->Next;
	}
	return pL;
}


//tìm t?p hop h?p c?a 2 t?p h?p bi?u di?n b?i 2 danh sách L1, L2
List unionSet(List L1, List L2){
	Position(L);
	makenullList(&L);
	L = L1;
	while (L2->Next != NULL){
		if(member(L2->Next->Element, L) == 0){
			append(L2->Next->Element, &L);
		}
		L2 = L2->Next;
	}
	return L;
}


//Tính t?p h?p giao c?a 2 t?p h?p bi?u di?n b?i 2 danh sách L1, L2
List intersection(List L1, List L2){
	Position pL;
	makenullList(&pL);
	while(L1->Next != NULL){
		if(member(L1->Next->Element, L2) == 1){
			insertList(L1->Next->Element, endList(pL), &pL);
		}
	L1 = L1->Next;
	}
	return pL;
}


//Xóa ph?n t? d?u tiên có giá tr? là x trong danh sách
void erase(ElementType X, List *pL){
	if(locate(X, *pL)->Next == NULL) printf("Not found 5000\n");
	else deleteList(locate(X, *pL), &(*pL));
}


//xóa t?t c? ph?n t? có giá tr? x trong danh sách d?c các s? nguyên
void removeAll(ElementType X, List *pL){
	while(locate(X, *pL)->Next != NULL ){
		deleteList(locate(X, *pL), &*pL);
	}
}


//li?t kê t?t c? các ph?n t? là s? ch?n trong danh sách
void copyEvenNumbers(List L, List *pL){
	makenullList(&*pL);
	while(L->Next != NULL){
		if(L->Next->Element % 2 ==0){
			append(L->Next->Element, &*pL);
		}
		L = L->Next;
	}
}


//li?t kê t?t c? các ph?n t? là s? l? trong danh sách
void printOddNumbers(List L){
	while(L->Next != NULL){
		if(L->Next->Element % 2 != 0){
			printf("%d ", L->Next->Element);
		}
		L = L->Next;
	}
}


//s?p x?p danh sách tang d?n
void sort(List *pL){
	Position i, j;
	for(i = *pL; i->Next != NULL; i = i->Next){
		for(j = *pL; j->Next != NULL; j = j->Next){
			if(i->Next->Element < j->Next->Element){
				ElementType temp = i->Next->Element;
				i->Next->Element = j->Next->Element;
				j->Next->Element = temp;
			}
		}
	}
	
}


//các ph?n t? trong danh sách n?u trùng nhau thì ch? gi? l?i 1 ph?n t?, các ph?n t? khác b? xóa b?
void normalize(List *L){
	Position P = *L;
	while (P->Next != NULL){
		Position Q = P->Next;
		while(Q->Next != NULL){
			if(P->Next->Element == Q->Next->Element){
				deleteList(Q, &*L);
			} else {
				Q = Q->Next;
			}
		}
		P = P->Next;
	}		
}


//chép toàn b? các s? ch?n trong danh sách L1 sang danh sách k?t qu?
//void copyEvenNumbers(List L, List *pL){
//	makenullList(&*pL);
//	while(L->Next != NULL){
//		if(L->Next->Element % 2 ==0){
//			append(L->Next->Element, &*pL);
//		}
//		L = L->Next;
//	}
//}
int main(){
	List L,L1;
	readSet(&L);
	readSet(&L1);
	sort(&L);
	sort(&L1);
	printList(L);
	printList(L1);
//	difference(L,L1);
}
