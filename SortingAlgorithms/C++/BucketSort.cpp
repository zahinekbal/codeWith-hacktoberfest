#include<bits/stdc++.h>
using namespace std;
void temp_sort(vector<int>&arr,int n,int val)
{
    vector<vector<int>>buckets(11);
    int place=pow(10,val);
    for(int i=0;i<n;i++)
    {
        int digit =(arr[i]%place)/(place/10);
        buckets[digit].push_back(arr[i]);
    }
    int j=0;
    vector<int>c;
    for(int i=0;i<=10;i++)
    {
        for(int k=0;k<buckets[i].size();k++)
        {
            c.push_back(buckets[i][k]);
        }
    }
    arr=c;
}
void bucket_sort(vector<int>&arr,int n)
{
    int max_ele=arr[0];
    for(int i=0;i<n;i++){
        max_ele=max(max_ele,arr[i]);
    }
    int times=ceil(log10(max_ele));
    for(int i=1;i<=times;i++){
        temp_sort(arr,n,i);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bucket_sort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}