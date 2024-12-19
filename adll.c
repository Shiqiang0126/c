// 数组 实现 双向链表测试 adll.c
// 产生一个双向链表，向内插入随机数，保持链表value的有序排列
// 链表类型：Sigle linked list// Double linked list//Circlar linked list//Circlar double linked list

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct NODE {
      int alc; // node allocated flag; 0 = free; 1 = allocated;
      int plink;//prev link
      int value;
      int nlink;//next link
} Node;

#define FALSE     0
#define TRUE      1
#define MAXNODE   40

Node m[MAXNODE]; // 链表可用空间，下标 0 不用，保留给NULL

void cdll_print_all();

int init_m(){
      int i;
      for (i=0;i<MAXNODE;i++){
            m[i].alc = m[i].plink = m[i].nlink = m[i].value = 0;
      }
      cdll_print_all();
}

int cdll_new(int init_value){ // 创建新的链表节点
      int new = 1;

      printf("find:"); // debug:开始查找
      for ( new = 1; m[new].alc != 0 && new < MAXNODE; new ++)
            printf("%d%c ", new, m[new].alc == 0 ? ' ' : '*' ); // debug:从头向后查找空节点
      printf("%d%c\n",new,m[new].alc==0?' ':'*'); // debug:查找过程
      if ( m[new].alc == 0 ) { // 找空节点成功
            m[new].alc = 1; // 占用
            m[new].nlink = m[new].plink = 0; // 0 = NULL
            m[new].value = init_value;
      } else {
            new = 0; // 不成功
      }
      return new;
}

void cdll_free_node(int current){ // 释放一个节点

      if( m[current].plink != 0 ) m[m[current].plink].nlink = m[current].nlink;
      if( m[current].nlink != 0 ) m[m[current].nlink].plink = m[current].plink;
      m[current].alc = 0;
}

void cdll_free_all(int current){ // 释放整个链表
      int ff;

      while( m[current].plink != 0) current = m[current].plink;
      while( current != 0){
            ff = current;
            current = m[current].nlink;
            cdll_free_node(ff);
      }
}

int cdll_insert( int current, int new_value ) { // 插入到当前节点之前
      int new;

      new = cdll_new( new_value );
      if( new != 0 ){
            m[new].nlink = current;
            m[new].plink = m[current].plink;
            m[current].plink = new;
            if (m[new].plink != 0) m[m[new].plink].nlink = new;
      }
      return new;     
}

int cdll_append( int current, int new_value){ // 插入当前位置之后
      int new;

      new = cdll_new( new_value);
      if(new != 0){
            m[new].plink = current;
            m[new].nlink = m[current].nlink;
            m[current].nlink = new;
            if (m[new].nlink != 0) m[m[new].nlink].plink = new;
      }
      return new;
}

void cdll_print(int current){ // 给与任意节点，从头打印整个链表（遍历）
      int work = current;

      while( m[work].plink != 0 ) work = m[work].plink; // 去到表头节点
      while( work != 0 ){
            printf("C:%02d P:%02d N:%02d V:%d\n", work, m[work].plink, m[work].nlink, m[work].value); //这个是打印节点“地址值”
            work = m[work].nlink;
      }
      printf("\n");
}

void cdll_print_all(){
      int i;
      printf("\n");
      for(i = 0; i <= MAXNODE; i++){
            printf("M[%02d]%c: P=%02d N=%02d V=%d\n", i, m[i].alc==0 ? ' ':'*',m[i].plink,m[i].nlink,m[i].value);
      }
      printf("\n");
}

int main(){
      int rt, rt1, rt2;
      int i;

      srand((unsigned)time(NULL));
      init_m();
      // exit(0);

      rt = cdll_new(rand()); // 这一段，随机数插入头部
      if (rt != 0){ // 成功初始化链表
            for( i = 0; i < 8; i++){ // 插8个节点
                  rt = cdll_insert(rt, rand());
            }
      }
      rt1 = rt;
      cdll_print_all();
      cdll_print(rt1);
      //exit(0);

      rt = cdll_new(rand()); // 这一段，随机数插入末尾
      if (rt != 0){
            int kp;
            for( i = 0; i < 10; i++){
                  kp = rt;
                  while( m[kp].nlink != 0) kp = m[kp].nlink;
                  cdll_append(kp, rand());
            }
      }
      rt2 = rt;
      cdll_print_all();
      cdll_print(rt);
      cdll_free_all(rt1);
      cdll_print_all();
      // exit(0);
      
      rt = cdll_new(RAND_MAX / 2); // 链表头用随机数的中位数，后面有序插入
      if (rt != 0){
            int new_val;
            int cur;
            for(i = 0; i<12; i++){
                  new_val = rand();
                  
                  if (new_val <= m[rt].value){
                        rt = cdll_insert(rt, new_val); // 小于原链表头，插入前面
                  } else {
                        cur = rt;
                        while ( 1 )
                              if( m[cur].nlink == 0 ) {
                                    cdll_append(cur, new_val); // 到末尾了，直接插入
                                    break;
                              } else if ( m[cur].value < new_val && new_val <= m[m[cur].nlink].value) {
                                    cdll_append(cur, new_val); // 合适位置，插入
                                    break;
                              } else  {
                                    cur = m[cur].nlink; // 也不是末尾，也不是合适位置，就向后走
                              }
                  }
            }
      }
      cdll_print(rt);
      cdll_print_all();
      cdll_free_all(rt);
      cdll_print_all();
      cdll_free_all(rt2);
}