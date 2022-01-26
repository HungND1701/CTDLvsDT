#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int arr[9][9]={{0,6,0,0,2,0,0,0,0},
               {0,0,0,0,0,0,9,5,7},
               {0,1,8,4,0,0,0,0,3},
               {4,5,2,0,9,8,0,0,0},
               {0,3,0,0,0,5,0,9,0},
               {0,0,7,3,0,0,0,0,1},
               {0,2,4,0,0,0,6,0,8},
               {0,0,9,7,6,0,0,0,0},
               {5,0,0,0,0,1,0,4,0}};
bool kiemtra(int r, int c, int v){
    for(int i = 0; i <= 8; i++)
         if(arr[i][c] == v) return false;
    for(int j = 0; j <= 8; j++)
         if(arr[r][j] == v) return false;
    int I = r/3;
    int J = c/3;
    int i = r - 3*I;
    int j = c - 3*J;
    for(int i1 = 0; i1 <= i-1; i1++)
        for(int j1 = 0; j1 <= 2; j1++)
            if(arr[3*I+i1][3*J+j1] == v) return false;
    for(int j1 = 0; j1 <= j-1; j1++)
        if(arr[3*I+i][3*J+j1] == v) return false;
    return true;
}
void result(){
     for(int i=0;i<9;i++){
         for(int j=0;j<9;j++){
             printf("%d ",arr[i][j]);
         }
         printf("\n");
     }
}     
void sodoku(int i,int j){
   if(arr[i][j]==0){
    for(int v=1;v<=9;v++){
        if(kiemtra(i,j,v)){
            arr[i][j]=v;
            if(i==8&&j==8) result();  
            else {if(j==8) sodoku(i+1,0);
                  else sodoku(i,j+1);
                  }
            arr[i][j]=0;
        }
    }    
   }else{
       if(i==8&&j==8) result();  
        else {if(j==8) sodoku(i+1,0);
              else sodoku(i,j+1);
             }
   } 
}       
int main(){
    printf("******SODOKU******\n");
    
    sodoku(0,0);
    
}