// Sap xep tron 
#include<stdio.h>
#define MAX 100
typedef int DataType;
DataType TA[MAX] ; 
void Merge(DataType A[],int L, int M,int R)
{
    int i=L,j=M+1;
    for(int k=L;k<=R;k++){
        if(i>M){TA[k]=A[j];j++;}
        else if(j>R){TA[k]=A[i];i++;}
        else{
            if(A[i]<A[j]){
                TA[k]=A[i];i++;
            }
            else{
                TA[k]=A[j];j++;
            }
        }
    }
    for(int k=L;k<=R;k++) A[k]=TA[k];
}
void Merge_Sort (DataType A[],int first,int last){
    if(first<last)
    {
        int mid=(last+first)/2;
        Merge_Sort(A, first,mid);
        Merge_Sort(A,mid+1,last);
        Merge(A,first,mid,last);
    }
}
int main(){
    DataType A[]={5,7,3,8,1,2,9,4,6};
    int N=sizeof(A)/sizeof(DataType);
    Merge_Sort(A,0,N-1);
    for(int i=0;i<N;i++){
        printf("%d ",TA[i]);
    }
    printf("\n");
    return 0;
}