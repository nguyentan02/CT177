#include<stdio.h>
#define Max_Length 100
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements[Max_Length];
	Position Last;
}List;

void makenullList(List *pL){
	pL->Last=0;
}
int Empty_List(List L){
	return L.Last == 0;
}
Position firstList(List L){
	return 1;
}
Position endList(List L){
	return L.Last+1;
}
Position next(Position P,List L){
	return P+1; 
}
Position Previous(Position P,List L){
	return P-1; 
}


ElementType retrieve(Position P,List L){
	return L.Elements[P-1];
}

//Xac dinh vi tri cua phan tu x trong list

Position locate(ElementType X,List L){
	Position P = 1;
	int Found = 0;
	while(P<=L.Last  && !Found){
		

		if(L.Elements[P-1]==X) Found=1;
		else P++;
	}
		return P;
}

//Xen phan tu X 

void Insert_List(ElementType X,Position P,List *L){
	if(L->Last==Max_Length)
	 printf("Danh sach day !\n");
	else if( P<1 || P>L->Last+1)
		printf("Vi tri khong hop le!\n");
		else {
			Position Q;
			for(Q=L->Last;Q>=P;Q--)
			L->Elements[Q]=L->Elements[Q-1];
			L->Last++;
			L->Elements[P-1]=X;
		
		}
}
//Xoa phan tu tai P

void delete_List(ElementType X,Position P,List *L){
		if(L->Last==0)
	 printf("Danh sach day !\n");
	else if( P<1 || P>L->Last)
		printf("Vi tri khong hop le!\n");
		else{
				Position Q;
			for(Q=P;Q<=L->Last-1;Q++)
			L->Elements[Q-1]=L->Elements[Q];
			L->Last--;
			 
		}
}
int member(int x,List L){
    int  i = 0;
	while (i < L.Last){
		if (L.Elements[i] == x) return 1;
		i++;
	}
	return 0;
}
void insertSet(int x,List *pL){
    pL->Elements[pL->Last]= x;
    pL->Last++;
}
void difference(List L1,List L2,List *pL){
	makenullList(pL);
	int i;
	for(i=0;i<L1.Last;i++)
	if(member(L1.Elements[i],L2) == 0)
		insertSet(L1.Elements[i],pL);
}
void intersection(List L1,List L2,List *pL){
	makenullList(pL);
	int i;
	for(i=0;i<L1.Last;i++)
	if(member(L1.Elements[i],L2) != 0)
		insertSet(L1.Elements[i],pL);
}
void removeAll(int x, List *pL){
	Position P = 1;
	delete_List(x,P,pL);
}
void erase(ElementType x, List *pL){
	deleteList(locate(x, *pL), &*pL);	
}
void readSet(List *pL){
	makenullList(&*pL);
	ElementType n, i, x;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &x);
		if(member(x, *pL) == 0) insertSet(x, &*pL);
	}
}

void printOddNumbers(List L){
	ElementType i = 0;
	for(i = 0; i < L.Last; i++){
		if(L.Elements[i] % 2 != 0 ) printf("%d ", L.Elements[i]);
	}
}
void printList(List L){
    Position P = firstList(L);
    while(P != endList(L)){
        printf("%d ",retrieve(P,L));
        P = next(P,L);
    }
    printf("\n");
}
void sort(List *L){
    Position Q,P;
	for(P=0;P<=L->Last-1;P++){
	    for(Q=P+1;Q<=L->Last-1;Q++){
	        if(L->Elements[P] >L->Elements[Q]){
	            int temp = L->Elements[P];
	            L->Elements[P] = L->Elements[Q];
	            L->Elements[Q] = temp;
	        }
	    }
	}
}
int main(){
	List L;
	readSet(&L);
	removeAll(2,*L);
	printList(L);
}

