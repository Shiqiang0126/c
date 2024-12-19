// 双向链表测试 dll.c
// 产生一个双向链表，向内插入随机数，保持链表value的有序排列
// 链表类型：Sigle linked list// Double linked list//Circlar linked list//Circlar double linked list

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct NODE {
      struct NODE *plink;//prev link
      int value;
      struct NODE *nlink;//next link
} Node;

#define    FALSE     0
#define    TRUE      1

Node *dll_insert( Node *current, int new_value ) { // 插入到当前节点之前
      Node   *new;

      new = (Node *)malloc( sizeof( Node ) );
      if( new != NULL ){
            new->value = new_value;
            new->nlink = current;
            new->plink = current->plink;
            current->plink = new;
            if (new->plink != NULL) new->plink->nlink = new;
      }
      return new;     
}

Node *dll_append( Node *current, int new_value){ // 插入当前位置之后
      Node *new;

      new = (Node *)malloc( sizeof( Node));
      if(new != NULL){
            new->value = new_value;
            new->plink = current;
            new->nlink = current->nlink;
            current->nlink = new;
            if (new->nlink != NULL) new->nlink->plink = new;
      }
      return new;
}

int dll_print( Node *current){ // 给与任意节点，从头打印整个链表（遍历）
      Node *work = current;
      int i=0;

      while( work->plink != NULL ) work = work->plink; // 去到表头节点
      while( work != NULL ){
            printf("C:%p P:%p V:%d N:%p\n", work, work->plink, work->value, work->nlink); //这个是打印节点“地址值”
            //printf("#%d:%d ", i, work->value);
            work = work->nlink;
            i++;
      }
      printf("\n");
}


Node *dll_new(int init_value){ // 创建新的链表节点
      Node *new;

      new = (Node *)malloc( sizeof(Node));
      if(new != NULL){
            new->nlink = new->plink = NULL;
            new->value = init_value;
      }
      return new;
}


int dll_free(Node *current){ // 释放整个链表
      Node *ff;

      while( current->plink != NULL) current = current->plink;
      while(current != NULL){
            ff = current;
            current = current->nlink;
            free(ff);
      }
}


int main(){
      Node *rt;
      int i;
      srand((unsigned)time(NULL));


      rt = dll_new(rand()); // 这一段，随机数插入头部
      dll_print(rt);
      if (rt != NULL){ // 成功初始化链表
            for( i = 0; i < 10; i++){ // 插10个节点
                  rt = dll_insert(rt, rand());
                  // dll_print(rt);
            }
      }
      dll_print(rt);
      dll_free(rt);

      rt = dll_new(rand()); // 这一段，随机数插入末尾
      dll_print(rt);
      if (rt != NULL){
            Node *kp;
            for( i = 0; i < 10; i++){
                  kp = rt;
                  while( kp->nlink != NULL) kp = kp->nlink;
                  dll_append(kp, rand());
                  // dll_print(rt);
            }
      }
      dll_print(rt);
      dll_free(rt);
      
      rt = dll_new(RAND_MAX / 2); // 链表头用随机数的中位数，后面有序插入
      dll_print(rt);
      if (rt != NULL){
            int new_val;
            Node *cur;
            for(i = 0; i<10; i++){
                  new_val = rand();
                  
                  if (new_val <= rt->value){
                        rt = dll_insert(rt, new_val); // 小于原链表头，插入前面
                  } else {
                        cur = rt;
                        while ( 1 )
                              if( cur->nlink == NULL ) {
                                    dll_append(cur, new_val); // 到末尾了，直接插入
                                    break;
                              } else if ( cur->value < new_val && new_val <= cur->nlink->value) {
                                    dll_append(cur, new_val); // 合适位置，插入
                                    break;
                              } else  {
                                    cur = cur->nlink; // 也不是末尾，也不是合适位置，就向后走
                              }
                  }
                  // dll_print(rt);
            }
      }
      dll_print(rt);
      dll_free(rt);
}