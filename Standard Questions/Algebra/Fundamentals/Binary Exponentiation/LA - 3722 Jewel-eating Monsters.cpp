/*
 * File: LA - 3722 Jewel-eating Monsters
 * Algorithm: Binary Exponentiation
 * Created Date: Tuesday July 21st 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;


int main() {
  int a, x, y, m;
  while (cin >> a >> x >> y >> m) {
    if (a == 0 && x == 0 && y == 0 &&  m == 0) break;
    int gold = a;
    for (int i = 0; i < y; i ++) {
     if (gold - 1 == 0)  {
       gold = m;
     }
     else gold = ((gold - 1) * x) % m;
    }
    cout << gold <<endl;
  }
}
