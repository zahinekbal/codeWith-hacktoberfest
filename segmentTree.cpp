//CPP implementation of segment tree(We are going to use an array in order to build the tree)

#include <iostream>
using namespace std;

void buildTree(int *arr,int *tree,int l,int r,int treeNode){
    //base case
    if(l==r){
        tree[treeNode] = arr[l];
        return;
    }

    int mid = (l + r)/2;
    buildTree(arr,tree,l,mid,2*treeNode);
    buildTree(arr,tree,mid+1,r,2*treeNode+1);

    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];


}

void updateTree(int *arr,int *tree,int l,int r,int treeNode,int index,int value){
    //base case
    if(l==r){
        tree[treeNode] = value;
        arr[index] = value;
        return;
    }

    int mid = (l+r)/2;
    if(index>mid){
        updateTree(arr,tree,mid+1,r,2*treeNode+1,index,value);
    }
    else{
        updateTree(arr,tree,l,mid,2*treeNode,index,value);
    }
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

int query(int * tree,int l,int r,int treeNode,int ql,int qr){


    //Out of range indexes
    if(l>qr || r<ql){
        return 0;
    }

    //In range indexes 
    if(l>=ql && r<=qr){
        return tree[treeNode];
    }

    //paritialyy between the ranges
    int mid = (l+r)/2;
    int ans1 = query(tree,l,mid,2*treeNode,ql,qr);
    int ans2 = query(tree,mid+1,r,2*treeNode+1,ql,qr);

    return ans1 + ans2;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int *tree = new int[10];//2 * size

    buildTree(arr,tree,0,4,1);
    
    for(int i=1;i<10;i++){
        cout<<tree[i]<<"\n";
    }
    cout<<"\n";

    updateTree(arr,tree,0,4,1,3,10);

    for(int i=1;i<10;i++){
        cout<<tree[i]<<"\n";
    }
    cout<<"\n";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<"\n";
    }
    cout<<"\n";

    cout<<query(tree,0,4,1,2,4)<<"\n";

    return 0;
}
