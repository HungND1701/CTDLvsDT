// tim cac doan khong xep chong len nhau trong trục Ox
// ko toi uu
#include <stdio.h>
typedef struct daumut
{
    int x;
    int y;
}xy;
int mark[6],i=0,Sn=0;
xy S[100],L[6];
int kiemtra(int * mark){
    int reval=0;
    for(int i=0;i<6;i++ ){
        if(mark[i]==0) reval=1;
    }
    return reval;
}
int feasible(xy * S, xy a){
    if(Sn==0){
       return 1;
    }else {
        for(int j=0;j<Sn;j++){
            if(S[j].y>a.x && a.y>S[j].x) return 0;
        }
    }
    return 1;
}
void push(xy* S, xy a){
    S[Sn].x=a.x;
    S[Sn].y=a.y;
    Sn++;
}
xy * Grendy1(){
    while(kiemtra(mark)!=0){
       mark[i]=1;
       if(feasible(S,L[i])!=0){
           push(S,L[i]);
       }
       i++;
    }
    return S;
}
int main(){
    for(int i=0;i<6;i++){
        mark[i]=0;
    }
    L[0].x=0;
    L[0].y=10;
    L[1].x=3;
    L[1].y=7;
    L[2].x=6;
    L[2].y=14;
    L[3].x=9;
    L[3].y=11;
    L[4].x=12;
    L[4].y=15;
    L[5].x=17;
    L[5].y=19;
    Grendy1();
    for(int i=0;i<Sn;i++){
        printf("%d %d\n",S[i].x,S[i].y);
    }
    return 0;
}