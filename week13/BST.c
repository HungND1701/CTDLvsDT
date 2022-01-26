#include<stdio.h>
#include<stdlib.h>
typedef struct BST_Node
{
    int key;
    struct BST_Node * leftPtr;
    struct BST_Node * rightPtr;
} TreeNode;

TreeNode * makeTreeNode(int N){
    TreeNode * newNodePtr = NULL;
    newNodePtr = (TreeNode * )malloc(sizeof(TreeNode));
    if(newNodePtr==NULL){
        fprintf(stderr,"Out of memory\n");
        exit(1);
    }
    else{
        newNodePtr->key=N;
        newNodePtr->leftPtr=NULL;
        newNodePtr->rightPtr=NULL;
        return newNodePtr;
    }
}

TreeNode * find_min(TreeNode * T ){
    TreeNode *P=T;
    if(P==NULL) return NULL;
    else{
        while (P->leftPtr!=NULL)
        {
            P=P->leftPtr;
        }
    }
    return P;
}

TreeNode * find_max(TreeNode * T){
    if(T==NULL) return NULL;
    else{
        while (T->rightPtr!=NULL)
        {
            T=T->rightPtr;
        }
    }
    return T;
}

TreeNode * search(TreeNode * nodePtr, int target){
    if(nodePtr != NULL){
        if(target< nodePtr->key){
            nodePtr= search(nodePtr->leftPtr, target);
        }
        else if(target> nodePtr->key){
            nodePtr = search(nodePtr->rightPtr, target);
        }
    }
    return nodePtr;
}
TreeNode * insert(TreeNode * nodePtr, int item){
    if(nodePtr == NULL){
        nodePtr = makeTreeNode(item);
    } else if(item < nodePtr->key){
        nodePtr->leftPtr = insert(nodePtr->leftPtr, item);
    }
    else if(item > nodePtr->key){
        nodePtr->rightPtr= insert(nodePtr->rightPtr, item);
    }
    return nodePtr;
}

TreeNode* delete(TreeNode * T , int x){
    TreeNode*tmp ;
    
    if(T==NULL) printf("Not found\n");
    else if (x < T->key) T->leftPtr= delete(T->leftPtr, x);
    else if (x> T->key) T->rightPtr= delete(T->rightPtr, x);
    else 
        if(T->leftPtr && T->rightPtr){
            tmp= find_min(T->rightPtr);
            T->key= tmp->key;
            T->rightPtr= delete(T->rightPtr, T->key);
        }
        else{
            tmp=T;
            if(T->leftPtr=NULL){
                T=T->rightPtr;
            }
            else if(T->rightPtr==NULL) T=T->leftPtr;
            printf("\nDeleted Node %d\n",tmp->key);
            free(tmp);
        }
        return T;
    
}
void InOder(TreeNode * T){
    if(T!=NULL){
        InOder(T->leftPtr);
        printf("%d ",T->key);
        InOder(T->rightPtr);
    }
}
int main(){
    int A[]={40, 30, 65, 25, 35, 50, 10, 28, 33, 34};
    int n = sizeof(A)/sizeof(int);
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    TreeNode * Goc=NULL;
    for(int i=0;i<n;i++){
        Goc=insert(Goc,A[i]);
    }
    InOder(Goc);
    TreeNode* min= find_min(Goc->leftPtr->rightPtr);
    printf("\n%d ",min->key);
    TreeNode* max= find_max(Goc->leftPtr->rightPtr);
    printf("\n%d ",max->key);
    TreeNode * nodesearch = search(Goc, 10);
    printf("\n%d ", nodesearch->key);
    delete(Goc,10);
    InOder(Goc);
    return 0 ;
}