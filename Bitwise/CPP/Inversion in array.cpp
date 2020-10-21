#include <iostream>
using namespace std;
long long merge(long long a[],int l,int mid,int r,int temp[]){
    int le[mid],re[mid];
  int i=l,j=mid,k=l;
long long count=0;
while(i<mid&&j<=r){
    if(a[i]<=a[j])
    temp[k++]=a[i++];
    else{
        temp[k++]=a[j++];
        count+=mid-i;
        
    }
}
while(i<mid)
temp[k++]=a[i++];
while(j<=r)
  temp[k++]=a[j++];
  for(int i=l;i<=r;i++)
  a[i]=temp[i];



   return count; 
    
}
long long mergeSort(long long a[],int l,int r,int temp[]){
    long long count=0;
    if(l<r)
    {   int mid=(l+r)/2;
        count+=mergeSort(a,l,mid,temp);
        count+=mergeSort(a,mid+1,r,temp);
        count+=merge(a,l,mid+1,r,temp);
    }
    return count;
    
}



int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    long long a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int temp[n];
	  cout<<mergeSort(a,0,n-1,temp)<<"\n";
	}
	return 0;
}
