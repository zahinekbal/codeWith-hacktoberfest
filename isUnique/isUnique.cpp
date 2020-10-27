#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cout<<"Enter a string\n";
	cin>>str;
	int flag=0;
	vector<bool> freq(128,false);
	for(int i=0;i<str.length();i++)
	{
		int val = str[i];
		if(freq[val]==true)
		{
			flag = 1;
			break;
		}
		freq[val] = true;
	}

	if(flag == 1)
		cout<<"Not unique\n";
	else
		cout<<"Unique\n";
}