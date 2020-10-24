// Tags: Implementation, math, number theory

#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
    int xi,yi,xf,yf,x,y;
    cin>>xi>>yi>>xf>>yf>>x>>y;
    bool ok=(abs(yf-yi)%y||abs(xf-xi)%x);
    if(ok)return puts("NO");
    puts((abs(yf-yi)/y)%2==(abs(xf-xi)/x)%2?"YES":"NO");
    return 0;
}
