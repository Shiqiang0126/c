/*
** 插入到一个有序的单链表。函数的参数是一个指向链表第一个节点的指针以及需要插入的值。
Sigle linked list// Double linked list//Circlar linked list//Circlar double linked list
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


typedef struct NODE {
      struct NODE *link;
      int value;
} Node;


#define    FALSE     0
#define    TRUE      1


Node *sll_insert( Node *current, int new_value ) { // 插入到当前位置（目前只允许插入头部位置，中间位置会‘断链’）
      Node   *new;


      new = (Node *)malloc( sizeof( Node ) );
      if( new != NULL ){
            new->value = new_value;
            new->link = current;
      }
      return new;     
}


Node *sll_append( Node *current, int new_value){ // 插入当前位置之后
      Node *new;


      new = (Node *)malloc( sizeof( Node));
      if(new != NULL){
            new->value = new_value;
            new->link = current->link;
            current->link = new;
      }
      return new;
}


int sll_print( Node *current){ // 打印整个链表（遍历）
      Node *work = current;
      int i=0;
      while( work != NULL ){
            //printf("#%p:%d ", work, work->value); //这个是打印节点“地址值”
            printf("#%d:%d ", i, work->value);
            work = work->link;
            i++;
      }
      printf("\n");
}


Node *sll_new(int init_value){ // 创建新的链表节点
      Node *new;


      new = (Node *)malloc( sizeof(Node));
      if(new != NULL){
            new->link = NULL;
            new->value = init_value;
      }
      return new;
}


int sll_free(Node *current){ // 释放整个链表
      Node *ff;


      while(current != NULL){
            ff = current;
            current = current->link;
            free(ff);
      }


}


int main(){
      Node *rt;
      int i;
      srand((unsigned)time(NULL));


      rt = sll_new(0); // 这一段，随机数插入头部
      sll_print(rt);
      if (rt != NULL){
            for( i = 0; i < 10; i++){
                  rt = sll_insert(rt, rand());
                  sll_print(rt);
            }
      }
      sll_free(rt);


      printf("\n");


      rt = sll_new(0); // 这一段，随机数插入末尾
      sll_print(rt);
      if (rt != NULL){
            Node *kp;
            for( i = 0; i < 10; i++){
                  kp = rt;
                  while( kp->link != NULL) kp = kp->link;
                  sll_append(kp, rand());
                  sll_print(rt);
            }
      }
      sll_free(rt);


      printf("\n");
      
      rt = sll_new(RAND_MAX / 2); // 链表头用随机数的中位数，后面有序插入
      sll_print(rt);
      if (rt != NULL){
            int new_val;
            Node *kp;
            for(i = 0; i<10; i++){
                  new_val = rand();
                  if (new_val <= rt->value){
                        rt = sll_insert(rt, new_val); // 小于原链表头，插入前面
                  } else {
                        kp = rt;
                        while ( 1 )
                              if( kp->link == NULL ) {
                                    sll_append(kp, new_val); // 到末尾了，直接插入
                                    break;
                              } else if ( kp->value < new_val && new_val <= kp->link->value) {
                                    sll_append(kp, new_val); // 合适位置，插入
                                    break;
                              } else  {
                                    kp = kp->link; // 也不是末尾，也不是合适位置，就向后走
                              }
                  }
                  sll_print(rt);
            }
      }
      sll_free(rt);


      rt = sll_new(RAND_MAX / 2); // 好像和前一段一样，忘了要改什么了
      sll_print(rt);
      if (rt != NULL){
            int new_val;
            Node *kp;
            for(i = 0; i<10; i++){
                  new_val = rand();
                  if (new_val <= rt->value) {
                        rt = sll_insert(rt, new_val);
                  } else {
                        kp = rt;
                        while ( 1 )
                              if( kp->link == NULL ) {
                                    sll_append(kp, new_val);
                                    break;
                              } else if ( kp->value < new_val && new_val <= kp->link->value) {
                                    sll_append(kp, new_val);
                                    break;
                              } else  {
                                    kp = kp->link;
                              }
                  }
                  sll_print(rt);
            }
      }
      sll_free(rt);
}