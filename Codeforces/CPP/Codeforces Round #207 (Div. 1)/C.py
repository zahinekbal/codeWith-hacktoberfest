# Tags: Combinatorics, Constructive Algorithms, Greedy, Implementation

a = [0] * 5
tot, ans = 0, 0
 
input()
for x in list(map(int, input().split())):
  a[x] += 1
  tot += x
 
if tot < 3 or tot == 5:
  exit(print(-1))
 
mn = min(a[1], a[2])
a[1] -= mn
a[2] -= mn
a[3] += mn
ans += mn
 
if a[1]:
  add = a[1] // 3
  a[1] %= 3
  a[3] += add
  ans += 2 * add
  ans += 1 if a[1] == 1 and a[3] else 2 if a[1] else 0
 
if a[2]:
  add = a[2] // 3
  a[2] %= 3
  a[3] += 2 * add
  ans += 2 * add
  ans += 1 if a[2] == 1 and a[4] else 2 if a[2] else 0
 
print(ans)