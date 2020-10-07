#include<iostream>
#include<unordered_map>  // header required to use unordered_map container.
#include<algorithm>
using namespace std;

int main()
	{
		int n; cin>>n;
		int A[n], max_freq=0;
	// declaration for unordered map of <int,int> type,i.e both key-value should be integer.
		unordered_map<int,int> umap;
		for(int i=0;i<n;i++)
				{
					cin>>A[i];
					umap[A[i]]++;  // incrementing count of unique keys in map.
				}
				
	// iterating in map
	  for(auto it : umap) // auto keyword is used to define an iterator.
	  	{
	     // it.first accesses key and it.second gives corresponding value.  		
	  		cout<<it.first<<"->"<<it.second<<"\n";
	  		if(it.second>max_freq)
	  			max_freq=it.second;
	  	}
	  	cout<<"Maximum files added by any contributor= "<<max_freq<<"\n";	
	  return 0;			
	}

	//  Note: unordered_map as name denotes prints its content in any random order.

	  // contributed by @Abhinav Pathak.