//Tower of Hanoi using Recursion

#include<stdio.h>
void TOH(int n,char a,char b,char c){
    
    TOH(n - 1, a, c, b);
    printf("Move A disc from %c to %c",a,c);
    TOH(n - 1, b, a, c);
}

int main(){
    int n;
    char a, b, c;
    printf("enter no of disc = ");
    scanf("%d", &n);
    TOH(n, a, b, c);
}