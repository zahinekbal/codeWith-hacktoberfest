#include <iostream>
#include <string>
#include<vector>
#include <algorithm>
#include <math.h>
#include <map>
#include<set>
#include <forward_list>
using namespace std;


int partition(int *arr,int low ,int high){
    int pivot=arr[high];
    int i=low-1;
    int temp=0;
    int temp2=0;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
                i=i+1;
                //swap between arr[j]  &&arr[i]
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
        }
        
    }
    //swap the arr[i+1]  && arr[high]
    temp2=arr[high];
    arr[high]=arr[i+1];
    arr[i+1]=temp2;
    return i+1;
}


void quicksort(int *a,int low,int high){
    if(low<high){
    int pivot=partition(a,low,high);
    quicksort(a,low,pivot-1);
    quicksort(a,pivot+1,high);
    }

}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quicksort(a,0,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}