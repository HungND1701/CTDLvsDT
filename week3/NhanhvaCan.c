#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int distance[4][4]= {{0,4,1,3},
                     {4,0,2,1},
                     {1,2,0,5},
                     {3,1,5,0}};
int marked[4],result[5],f;
int in[6][MAX];
int f_min,distance_min=1;
int j=0;
void process(){
    if(f+distance[result[3]][result[0]]<f_min){
        f_min=f+distance[result[3]][result[0]];
    }
}
void Ghinho(){
    result[4]=0;
    for(int i=0;i<=4;i++){
        in[i][j]=result[i];
    }
    in[5][j]=f_min;
    j++;
}
void TRY(int k){
    for(int i=0;i<=3;i++){
        if(marked[i]==0){
            result[k]=i;
            f=f+distance[result[k-1]][result[k]];
            marked[i]=1;
            if(k==3){
                process();
                Ghinho();
            }else{
                int g=f+distance_min*(4-k);
                if(g<f_min) TRY(k+1);
            }
            marked[i]=0;
            f=f-distance[result[k-1]][result[k]];
        }
    }
}
void main(){
    f_min=9999999;
    for(int i=0;i<=3;i++){
        marked[i]=0;
    }
    result[0]=0;marked[0]=1;
    TRY(1);
    for(int i=0;i<j;i++)
    if(in[5][i]==f_min) {
        for(int x=0;x<=5;x++){
            printf("%d ",in[x][i]);
        }
        printf("\n");
    }
    
}