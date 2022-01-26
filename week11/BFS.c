// 303 sach ctdl vs gt
#include<stdio.h> 
#include<stdlib.h>
#define oo 1000
enum  color {white, gray , black};
int v=9; // so dinh
int color[9];
int d[9]; // khoang cach tu s den v 
int pi[9]; // dinh di truoc v trong duong di ngan nhat tu s den v
              // a b c d e f j h i 
int Adj[9][9]= {(1,1,0,0,0,1,0,0,0),
               ( 0,1,1,0,0,0,1,0,0),
                (0,0,1,0,0,0,0,1,0),
                (0,0,1,1,1,0,0,1,0),
                (0,0,0,0,1,0,0,0,0),
                (0,0,0,0,1,1,0,0,1),
                (1,0,0,0,0,0,1,0,0),
                (0,0,0,0,0,0,1,1,1),
                (0,0,0,0,0,0,1,0,1)};
int ptr=0;
void queueStruct(int Q[]){
    for(int i=0;i<v;i++) Q[i]=-1;
}
int IsEmpty(int Q[]){
    return Q[0]==-1;
}
void enqueue(int Q[], int s){
    Q[ptr]=s;
    ptr++;
}
int dequeue(int Q[]){
    int tmp= Q[0];
    for(int i=0;i<ptr;i++){
        Q[i]=Q[i+1];
        ptr--;
    }
    return tmp;
}
void BFS_Visit(int s){
    /*for(int u=0;u<v;u++){
        color[u]=white;
        d[u]= oo;
        pi[u]=-1;
    }*/
    color[s]= gray;
    d[s]= 0 ;
    pi[s]=-1;
    int Q[v];
    queueStruct(Q);
    enqueue(Q,s);
    while(!IsEmpty(Q)){
        int u= dequeue(Q);
        for(int i=0; i<v;i++){
            if(i!=u && Adj[u][i]==1 && color[i]==white){
                color[i]=gray;
                d[i]=d[u]+1;
                pi[i]=u;
                enqueue(Q,i);
            }
        }
        printf("%d ",u);
        color[u]=black;
    }
}
void BFS(){
    for(int u=0;u<v;u++){
        color[u]=white;
        pi[u]=-1;
    }
    for(int u=0;u<v;u++){
        if(color[u]==white) BFS_Visit(u);
    }
}
int main(){
    BFS();
    return 0;
}