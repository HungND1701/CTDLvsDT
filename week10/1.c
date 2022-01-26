#include<stdio.h>
int main(){
    int a,b,c,count=0;
    for( a=0;a<=2;a++){
        for(b=0;b<=6;b++){
            for( c=0;c<=13;c++){
                if(a*5+b*2+c==13) count++;
            }
        }
    }
    printf("%d",count);
    return 0;
}