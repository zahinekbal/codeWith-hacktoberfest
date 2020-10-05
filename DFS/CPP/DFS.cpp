// recursive implementation of DFS  of an Undirected Graph in C++

#include<bits/stdc++.h>
using namespace std;
// function to perform dfs...
void dfs(vector<int> v[100],int* vis,int start)
{
  vis[start]=1;
  cout<<start<<" ";// print vertex
  for(int i=0;i<v[start].size();i++) // traverse all vertices attached to start depthwise...
  {
    if(!vis[v[start][i]])
      dfs(v,vis,v[start][i]);
  }
}
int main()
{
  // Graph creation using adjacency list.....
  vector<int> v[100];
  int i,j,n;
  cout<<"Enter the number edges present"<<endl;
  cin>>n;
  cout<<"Enter the edges"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>i>>j; // undirected edge between i and j
    v[i].push_back(j);
    v[j].push_back(i);

  }
  int vis[n+1]; // to keep track of visited vertices
  for(int i=0;i<=n;i++)
    vis[i]=0;
  for(int i=0;i<=n;i++)
  {
    if(vis[i]==0) // in case having more than 1 component
    {
      dfs(v,vis,i);
    }
  }


}
