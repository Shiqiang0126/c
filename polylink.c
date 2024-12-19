/* list.c  single link list test
*/
#include <stdio.h>
#include <stdlib.h>

#include "list.h"
//----------
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Polynomial;
typedef PtrToNode Position;

Polynomial NewPoly( Polynomial Poly ); //建新多项式链表，空表头
void DeleteNode( Position Ptr, Polynomial Poly ); //合并同类项后， Coeff == 0，则删去节点
void DeletePoly( Polynomial Poly); //多项式链表全部释放，保留表头
Position AdvanceNode( Position Ptr, Polynomial Poly );//查找前驱节点，并返回指针
void OrdInsert( int E, int C, Polynomial Poly );// 节点expo，Coeff，按降序插入 Poly，并且合并同类项

void AddPoly( Polynomial Poly1, Polynomial Poly2, Polynomial PolySum);// 两个poly相加，结果放入Sum
void MultPoly( Polynomial Poly1, Polynomial Poly2, Polynomial PolyProd);// 两个poly相乘，结果放入Prod

int PrintPoly( Polynomial Poly );// 数学方式打印多项式
int printNode( Position Ptr );// 打印节点信息
int printSll( Polynomial Poly );// 按节点方式打印整个多项式列表


struct Node{
    int Coefficient; // 系数
    int Exponent; // 次方
    PtrToNode Next;
};
//--------

void FatalError(char *msg){
    fprintf(stdout, "FatalError:%s\n", msg);
    exit(EXIT_FAILURE);
}

Polynomial NewPolyNode(int Coefficient, int Exponent ){ //实际就是申请新节点，第一次申请就是header
    if (( Poly = malloc(sizeof(struct Node))) == NULL ) FatalError("No memory space");
    Poly->Exponent = Exponent;
    Poly->Coefficient = Coefficient;
    Poly->Next = NULL;
}

int DeleteNode( Position Ptr, Polynomial Poly ){ // 删去Ptr所指节点，不允许是Header
    Position adv;

    if( Ptr == Poly ) return -1; // 不能删去头结点，返回-1表示出错；
    adv = AdvanceNode( Ptr, Poly );// 前驱节点；
    adv->Next = Ptr->Next;
    free(Ptr);
    rerurn 0;
}

void DeletePoly( Polynomial Poly){//多项式链表全部释放，保留表头, 没有用DeleteNode是为了效率
    Polynomial temp;
    while(Poly->Next != NULL){
        temp = Poly->Next
        Poly->Next = Poly->Next->Next;
        free(temp);
    }
}

Position AdvanceNode( Position Ptr, Polynomial Poly ){//查找前驱节点，并返回指针
    while(Poly->Next != Ptr) Poly = Poly->Next;
    return Poly;
}

void OrdInsert( int C, int E, Polynomial Poly ){// 节点expo，Coeff，按降序插入 Poly，并且合并同类项
    Polynomial new, cur;

    new = NewPolyNode( C, E );
    for( cur = Poly; cur->Next != NULL && cur->Next->Exponent > new->Exponent; cur = cur->Next )
            ; // cur 后驱大于 待插入，则cur向后移动
    if( cur->Next == NULL || cur->Next->Exponent < new->Exponent){ // 不会访问NULL指针
        // 或者末尾，或者大于待插入，说明不是同类项，直接插；
        new->Next = cur->Next; 
        cur->Next = new;
    } else { // 到这里就是cur 和 new 的 exp 相等了，合并同类型，并释放new
        cur->Next->Coefficient += new->Coefficient;
        free(new);
    }
}
// -------  

int printNode( Position P ){
    // for easy read, ptr 保留四位
    if( P != NULL)
        printf("Node(0x%04x): Data=%d, Next=(0x%04x)\n", (long)P % 0x10000, P->Element, (long)P->Next % 0x10000);
}

int printSll( List L ){
    while(L != NULL){
        printNode( L );
        L = L->Next;
    }
}


void DeleteList( List L){
    // 删除表内节点，保留表头
    Position P;

    P = L->Next;
    L->Next = NULL; // 头不删，封闭
    while( P != NULL){
        L = P->Next;
        free(P);
        P = L;
    }
}