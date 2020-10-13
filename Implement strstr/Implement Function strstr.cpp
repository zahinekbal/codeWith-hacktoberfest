/*Probem Statement: 
Input:
s = HowdyDevelopers, x = Develop
Output: 5 
Explanation: Develop is present as substring
in HowdyDevelopers from index 5 (0 based
indexing).
*/

#include<bits/stdc++.h>
using namespace std;
int strstr(string, string)
int main()
{
	int t;//t test cases
	cin>>t;
	while(t--)
	{
		string a;
		string b;
		cin>>a;
		cin>>b;
		cout<<strstr(a,b)<<endl;
	}
}
/* The function should return position where the target string 
   matches the string str*/
int strstr(string s, string x)
{
     //Your code here
     char c=x[0];
     int i, j, count, count1;
     int n1=s.length();
     int n2=x.length();
     for(i=0; i<n1; i++)
     {
         if(c==s[i])
         {
             count1=i;
             count=count1;
             i++;
             for(j=1; j<n2; j++)
             {
                 if(x[j]==s[i])
                 {
                 i++;
                 count++;
                 }
                 else
                 break;
                 
             }
             if(count-count1+1==n2)
             break;
             
         }
         else
         continue;
     }
     if(count-count1+1==n2)
     return count1;
     else
     return -1;
}