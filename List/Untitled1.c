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
Position first(List L){
	return 1;
}
Position End(List L){
	return L.Last+1;
}
Position Next(Position P,List L){
	return P+1; 
}
Position Previous(Position P,List L){
	return P-1; 
}


ElementType Retrieve(Position P,List L){
	return L.Elements[P-1];
}

//Xac dinh vi tri cua phan tu x trong list

Position locate(ElementType X,List L){
	Position P = 1;
	int Found = 0;
	while(P<=L.Last  && !Found)
		if(L.Elements[P-1]==X) Found=1;
		else P++;
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
void removeAll(int x, List *pL){
	Position P = 1;
	delete_List(x,P,pL);
	
}
int main(){
List L;
int i;
L.Last=0;
for(i=0;i<5;i++)
{    L.Elements[i] = 2*i;}
L.Elements[i] = 8;
L.Last=6;
removeAll(8,&L);
for(i=0;i<L.Last;i++)
{    printf("%d ",L.Elements[i]);}
}

