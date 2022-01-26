#include<stdio.h>

void insertionSort(int A[],int N){
    for(int k=1;k<N;k++){
        int last=A[k];
        int j=k;
        while(j>0&&A[j-1]>last){
            A[j]=A[j-1];
            j--;
        }
        A[j]=last;
    }
}

int main(){
    int A[]={5,7,3,8,1,2,9,4,6};
    int n = sizeof(A)/sizeof(int);
    insertionSort(A,n);
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    return 0;
}