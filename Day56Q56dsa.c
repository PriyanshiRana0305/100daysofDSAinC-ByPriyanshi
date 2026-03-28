#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left,*right;
};

struct Node* newNode(int data){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->data=data;
    n->left=n->right=NULL;
    return n;
}

int isMirror(struct Node* a, struct Node* b){
    if(a==NULL && b==NULL) return 1;
    if(a==NULL || b==NULL) return 0;
    if(a->data!=b->data) return 0;
    return isMirror(a->left,b->right) && isMirror(a->right,b->left);
}

int main(){
    int n;
    scanf("%d",&n);
    if(n==0){printf("YES");return 0;}

    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    struct Node* nodes[n];
    for(int i=0;i<n;i++){
        if(arr[i]==-1) nodes[i]=NULL;
        else nodes[i]=newNode(arr[i]);
    }

    for(int i=0;i<n;i++){
        if(nodes[i]!=NULL){
            int l=2*i+1,r=2*i+2;
            if(l<n) nodes[i]->left=nodes[l];
            if(r<n) nodes[i]->right=nodes[r];
        }
    }

    struct Node* root=nodes[0];

    if(isMirror(root,root)) printf("YES");
    else printf("NO");

    return 0;
}