#include<stdio.h>

void SWAP(int A[],int a,int b){
    int temp= A[a];
    A[a]=A[b];
    A[b]=temp;
}
void Max_Heapifly(int A[],int i,int n){
    int left = i*2+1;
    int right = i*2+2;
    int largest;
    if(left<n && A[left]>A[i]) largest=left;
    else largest= i;
    if(right<n && A[right]>A[largest]) largest= right;
    if(largest != i) {
        SWAP(A,i,largest);
        Max_Heapifly(A,largest,n);
    }
}
void Build_Max_Heap(int A[],int n){
    for(int i=n/2-1;i>=0;i--){
        Max_Heapifly(A,i,n);
    }
}
void HeapSort(int A[],int n){
    Build_Max_Heap(A,n);
    for(int i=n-1;i>=1;i--){
        SWAP(A,0,i);
        Max_Heapifly(A,0,i);
    }
}

int main(){
    int A[]={7,4,3,1,2};
    int n =sizeof(A)/sizeof(int);
    printf("%d\n",n);
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    HeapSort(A,n);
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    
    return 0;
}