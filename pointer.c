//
//  pointer.c
//  
//
//  Created by Libaiming on 16/5/14.
//  Mainly talk about the Pointer in C .
//

#include "pointer.h"
int main(void){
    char *addr;
    char ku = 't';
    unsigned long val,kal;//unsigned long型の変数は32ビット(4バイト)の数値を格納します。通常のlong型と違い、負の数は扱えません。値の範囲は0から4,294,967,295(2の32乗 - 1)です。
   
    printf("--------step1:\n");
    printf("val = %lx\n",val);
    if (addr == NULL) {
        printf("Pointer(addr) is NULL\n");
    }else{
        printf("Pointer(addr)  is NOT NULL\n");
        printf("the stuff in Pointer(addr) is %p \n",addr);//ポインタのアドレス
    }
    
    
    //ポインタにむりやりアドレスを格納
    addr = (char *)0xdeadbeafaaa;
    val = (unsigned long)addr;
    printf("--------step2:\n");
    printf("addr（ポインタに強制にアドレス代入）= %p\n",addr);
    printf("val（アドレスをlongに代入） = %lx\n",val);
    
    //ポインタにデータ(char型)代入の例１
    addr = &ku;
    printf("--------step3:\n");
    printf("*addr = %c\n",*addr);
    
    //ポインタにデータ(char型)代入の例２
    *addr = ku;
    printf("--------step4:\n");
    printf("*addr = %c\n",*addr);
    
    //ポインタに真面目にアドレスを格納
    kal = (unsigned long)&addr;
    printf("--------step5:\n");
    printf("kal = %lx\n",kal);
    
    //ポインタにデータ(char型)代入の例3
    char *addr_ = &ku;
    printf("--------step6:\n");
    printf("*addr_ = %c\n",*addr_);
    
    //ポインタのポインタ
    char **pp,*p,n ;
    n = 'A';
    p = &n;
    pp = &p;
    printf("--------step6:\n");
    printf("pp = %p = &p\n",pp);
    printf("p = %p = &n\n",p);
    printf("&pp = %p\n",&pp);
    
    
    
    return 0;
}