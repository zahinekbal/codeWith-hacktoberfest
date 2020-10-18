#include<iostream>
#include<list>
using namespace std;
class node{
public:
int d,p,t;
bool operator < (node n)
{
if(p<n.p)
return 1;
else
return 0;
}
};

int main()
{
int d,p,t,i,profit,min,n;
list<node> lst;
node pt;
cout<<"Enter no of entries
";
cin>>n;
for(i=0;i<n;i++)
{
cout<<"enter data(p,d,t)
";
cin>>p>>d>>t;
pt.d=d;
pt.p=p;
pt.t=t;
lst.push_back(pt);
}
int maxd=0;
lst.sort();
lst.reverse();
cout<<"
sorted list
";
list <node> :: iterator itr=lst.begin();
while(itr!=lst.end()){
pt=*itr;
if(maxd<pt.d) maxd=pt.d;
cout<<pt.p<<endl<<pt.d<<endl<<pt.t<<endl<<endl;
itr++;
}
//cout<<" max deadline "<<maxd<<endl;
itr=lst.begin();
profit=0;
while(itr!=lst.end())
{

  pt=*itr;

 if(pt.d>=pt.t)
min=pt.t;
else
min=pt.d;

if(maxd>=min)
            profit+=min*pt.p;
            else
            profit+=maxd*pt.p;
            itr++;maxd=maxd-min;

}
cout<<"profit is : "<<profit<<endl;
return 0;
}
