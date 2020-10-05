/*
 * File: SGU 106
 * Algorithm: Linear Diophantine Equation
 * Created Date: Thursday July 23rd 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

void shift_solution(int & x, int & y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

int find_all_solutions(int a, int b, int c, int x1, int x2, int y1, int y2) {
    int x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (x1 - x) / b);
    if (x < x1)
        shift_solution(x, y, a, b, sign_b);
    if (x > x2)
        return 0;
    int lx1 = x;

    shift_solution(x, y, a, b, (x2 - x) / b);
    if (x > x2)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution(x, y, a, b, -(y1 - y) / a);
    if (y < y1)
        shift_solution(x, y, a, b, -sign_a);
    if (y > y2)
        return 0;
    int lx2 = x;

    shift_solution(x, y, a, b, -(y2 - y) / a);
    if (y > y2)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}

int main(){
    int a,b,c,x1,x2,y1,y2;
    while(cin>>a>>b>>c>>x1>>x2>>y1>>y2){
        c = -c;
        if(!a && !b)
            cout<<(c?0:(x2-x1+1)*(y2-y1+1))<<endl;
        else if(!a)
            cout<<((c%b == 0) && y1 <= (c/b) && (c/b) <= y2 ? (x2-x1+1):0)<<endl;
        else if(!b)
            cout<<((c%a == 0) && x1 <= (c/a) && (c/a) <= x2 ? (y2-y1+1):0)<<endl;
        else
            cout<<find_all_solutions(a,b,c,x1,x2,y1,y2)<<endl;
    }
    return 0;
}
