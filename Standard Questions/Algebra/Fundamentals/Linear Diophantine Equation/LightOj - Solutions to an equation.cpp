/*
 * File: LightOj - Solutions to an equation
 * Algorithm: Linear Diophantine Equation
 * Created Date: Friday July 24th 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>
#define LL long long

using namespace std;
 
 
LL exgcd(LL a, LL b, LL &x, LL &y)
{
    LL d = a;
    if(b == 0)
    {
        x = 1;
        y = 0;
    }
    else
    {
        d = exgcd(b, a % b, y, x);
        y -= (a / b)*x;
    }
    return d;
}
 
int main()
{
    int T;
    int cnt = 0;
    cin >> T;
    while(T--)
    {
        LL a, b, c, x1, x2, y1, y2;
        scanf("%lld%lld%lld", &a, &b, &c);
        scanf("%lld%lld%lld%lld",&x1, &x2, &y1, &y2);
        c = -c;
        if(a < 0)
        {
            a = -a;
            swap(x1, x2);
            x1 = -x1;
            x2 = -x2;
        }
        if(b < 0)
        {
            b = -b;
            swap(y1, y2);
            y1 = -y1;
            y2 = -y2;
        }
        printf("Case %d: ", ++cnt);
        LL x0 = 0 , y0 = 0;
 
 
 
        LL g = exgcd(a, b, x0, y0);
        if(g!=0 && c % g != 0)
        {
            printf("0\n");
            continue;
        }
        if(a == 0 && b == 0)
        {
            if(!c)
                printf("%lld\n", (x2 - x1 + 1) * (y2 - y1 + 1));
            else printf("0\n");
            continue;
 
        }
        if(a == 0)
        {
            if(c / b >= y1 && c/b <= y2)
                printf("%lld\n", x2 - x1 + 1);
            else printf("0\n");
            continue;
        }
        if(b == 0)
        {
            if(c / a >= x1 && c / a <= x2)
                printf("%lld\n", y2 - y1 + 1);
            else printf("0\n");
            continue;
 
        }
 
        x0 = x0 * c / g;
        y0 = y0 * c / g;
        a /= g;
        b /= g;
        LL l = ceil((double)(x1 - x0)/(double)(b));
        LL r = floor((double)(x2 - x0)/(double)(b));
        LL w = ceil((double)(y0 - y2)/(double)(a));
        LL e = floor((double)(y0 - y1)/(double)(a));
        LL q = max(l, w);
        LL p = min(r, e);
        if(p < q)
            printf("0\n");
        else printf("%lld\n", p - q + 1);
    }
    return 0;
}
