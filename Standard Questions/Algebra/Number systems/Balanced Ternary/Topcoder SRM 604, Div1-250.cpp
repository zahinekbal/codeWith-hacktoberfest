/*
 * File: Topcoder SRM 604, Div1-250
 * Algorithm: Balanced Ternary
 * Created Date: Saturday August 8th 2020
 * Author: preetam rane
 */


#inlcude <bits/stdc++.h>

using namespace std;

class PowerOfThreeEasy {
  public:
    string ableToGet(int x, int y);
};

string PowerOfThreeEasy::ableToGet(int x, int y)
{
  vector <int> TheSet;
  long long d, sum;
  int i, j;

  if (x == 0 && y == 0) return "Possible";

  d = 1;
  sum = 0;

  do {
    TheSet.push_back(d);
    sum += d;
    d *= 3;
  } while (sum < x + y);


  if (sum != x + y) return "Impossible";


  for (i = 0; i < (1 << TheSet.size()); i++) {
    sum = 0;
    for (j = 0; j < TheSet.size(); j++) {
      if (i & (1 << j)) sum += TheSet[j];
    }
    if (sum == x) return "Possible";
  }

  return "Impossible";
}

