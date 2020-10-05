/*
 * File: UVA - 12775 - Gift Dilemma
 * Algorithm: Extended Euclidean Algorithm
 * Created Date: Thursday July 23rd 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;


long long gcd(long long a, long long b, long long &x, long long &y) {
if (a == 0) {
    x = 0;
    y = 1;
    return b;
}

long long x1, y1;
long long g = gcd(b % a, a, x1, y1);
x = y1 - (b / a) * x1;
y = x1;
return g;
}

void shift_solution(long long ag, long long bg, long long offset, long long &x, long long &y) {
x += bg * offset;
y -= ag * offset;
}

long long find_all_solutions(long long a, long long b, long long d, long long g, long long x, long long y) {
if (d % g) return 0;
long long xmin = 0;
long long xmax = d / a;
long long ymin = 0;
long long ymax = d / b;

long long mult = d / g;
x *= mult;
y *= mult;

a = a / g;
b = b / g;

shift_solution(a, b, (xmin - x) / b, x, y);
if (x < xmin)
    shift_solution(a, b, 1, x, y);
if (x > xmax)
    return 0;
long long lx1 = x;

shift_solution(a, b, (xmax - x) / b, x, y);
if (x > xmax)
    shift_solution(a, b, -1, x, y);
long long rx1 = x;

shift_solution(a, b, -(ymin - y) / a, x, y);
if (y < ymin)
    shift_solution(a, b, -1, x, y);
if (y > ymax)
    return 0;
long long lx2 = x;

shift_solution(a, b, -(ymax - y), x, y);
if (y > ymax)
    shift_solution(a, b, 1, x, y);
long long rx2 = x;

if (lx2 > rx2) {
    long long temp = lx2;
    lx2 = rx2;
    rx2 = temp;
}

long long lx = lx1 > lx2 ? lx1 : lx2;
long long rx = rx1 < rx2 ? rx1 : rx2;

return lx > rx ? 0 : (rx - lx) / b + 1;
}

long long count_solutions(long long a, long long b, long long c, long long p) {
long long x0, y0;
long long g = gcd(a, b, x0, y0);

long long x, y;
long long g1 = gcd(g, c, x, y);

long long x1, y1;
long long g2 = gcd(c, b, x1, y1);
long long x2, y2;
long long g3 = gcd(c, a, x2, y2);
long long res = 0;

if (p % g1) {
    return res;
}

long long z = 0;
while (z <= p) {
    long long d = p - z;
    if (d < a && d < b) {
    if (p % c == 0) {
        res++;
    }
    break;
    } else if (d % g != 0) {

    }
    else if (d < b){
    res += find_all_solutions(c, a, d, g3, x2, y2);
    break;
    }
    else if (d < a) {
    res += find_all_solutions(c, b, d, g2, x1, y1);
    break;
    }
    else {
    res += find_all_solutions(a, b, d, g, x0, y0);
    }

    z += c;
}

return res;
}

int main() {
long long T;
cin >> T;

for(long long i = 1; i <= T; i++) {
    long long a, b, c, p;
    cin >> a >> b >> c >> p;

    if (a > b) {
    long long temp = b;
    b = a;
    a = temp;
    }
    if (b > c) {
    long long temp = c;
    c = b;
    b = temp;
    }
    cout << "Case " << i << ": " << count_solutions(a, b, c, p) << endl;
}

return 0;
}
