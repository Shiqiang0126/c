/* qu8.c  8 queen question */
#include <stdio.h>
#define NCOL 8

int s[NCOL]; // 棋盘局，s[y] = x，无效不用，因此不用初始化
int scount = 0; // 方案计数

int good(int x, int y){ // x y 处落子是否ok 
    for (int j=0; j < y; j++) // 只判断之前的行是否碰撞
    	// s[j]就是j行的x，分别判断x碰撞、backslash碰撞、slash碰撞
        if(s[j] == x || s[j]-j == x-y || s[j]+j == x+y ) 
        	return 0; // not good! 
    return 1; // good
}

int print_sov(){ // 无需传递参数，都在全局变量s中
    extern int scount; // 有了新的解，计数 i 是全局变量；
    int x, y;
    for (y = 0; y < NCOL; y++){
        for (x = 0; x < NCOL; x++)
            printf("%c ", x == s[y]? 'X': '.'); 
        printf("\n");
    }
    printf("Solve #:%d\n\n", ++scount);
}

int sov(int y){
    for ( int x = 0; x < NCOL; x++ )
        if ( good(x,y) ){ // 测试落子位置是否OK
            s[y] = x; // 落子
            if (y < NCOL-1) // 可以，但不是最后一行，继续解决下面的
               sov( y + 1); 
            else  // 是最后一行，x有效就是得到一个解，计数，打印
               print_sov(); 
    	}	
}

int main(){
	sov(0);
	return 0;
}