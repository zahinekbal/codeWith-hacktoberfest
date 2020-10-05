#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int ele;
    vector <int> v;
    int x;
    cin>>x;
    for(int i=0;i<x;i++)
    {
        cin>>ele;
        v.push_back(ele);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    return 0;

}
