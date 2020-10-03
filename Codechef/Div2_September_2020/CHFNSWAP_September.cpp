#include<bits/stdc++.h>
using namespace std;
void fastscan(long long &num)
{
    num=0;
    int c;
    c=getchar_unlocked();
    for(;c>47&&c<58;c=getchar_unlocked())
    {
        num=num*10+c-48;
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long t;
	fastscan(t);
    for(int i=0;i<t;i++)
    {
        long long n,a,b,c,d,ct=0,s=0;
        fastscan(n);
        if(((n*(n+1))/2)%2==1) cout<<"0\n";
        else if(n==3||n==4) cout<<"2\n";
        else
        {
            a=(n*(n+1))/4;
            b= (-1 + (sqrt(1+4*2*a)))/2;
            c=(b*(b+1))/2;
            d=a-c;
            //cout<<a<<","<<c<<"\n";
            if(a==c)
            {
                c=n-b;
                b=b-1;
                b=(b*(b+1))/2;
                c=(c*(c+1))/2;
                cout<<b+c<<"\n";
            }
            else
            {
                s=d;
                if(n-b>d)
                ct+=d;
                else
                ct+=n-b;
                for(int j=b;j>=1;j--)
                {
                    s=s+j;
                    if(s<n) ct=ct+n-s;
                    if(s>=n) break;
                }
                cout<<ct<<"\n";
            }
        }
    }
    
}
