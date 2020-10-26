'''

Chef has invested his savings into N coins (numbered 1 through N). For each valid i, the i-th coin has value Ai.
Chef does not want to know how much money he has, so he remembers the mean value of the coins instead of the sum of their values.

A waiter from Chef's restaurant plans to steal exactly one of Chef's coins, but he does not want Chef to know about this, so he can only steal a coin if the arithmetic mean of all remaining coins is the same as the original arithmetic mean of all coins. Since the waiter is not good at mathematics, can you help him complete his plan?

You have to determine whether it is possible to steal some coin and if it is possible, choose the coin the waiter should steal. If there are multiple coins that can be stolen, choose the one with the smallest number.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N. The second line contains N space-separated integers A1,A2,…,AN. Output For each test case, print a single line. If the waiter cannot steal any coin, this line should contain the string "Impossible" (without quotes). Otherwise, it should contain the number of the coin he should steal.

Constraints

2≤N≤105
1≤Ai≤109 for each valid i
Subtasks

Subtask #1 (30 points):
2≤N≤103
1≤Ai≤103 for each valid i
A1+A2+…+AN≤109
Subtask #2 (70 points): original constraints

Example Input
3
5
1 2 3 4 5
4
5 4 3 6
10
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
Example Output
3
Impossible
1
Explanation
Example case 1: Stealing the third coin does not change the mean. Initially, it is (1+2+3+4+5)/5=3 and after stealing this coin, it is still (1+2+4+5)/4=3.

Example case 2: It is not possible to steal any coin without changing the mean.

Example case 3: The mean is always 109, both initially and after removing any coin, so each coin can be stolen. In that case, we should choose the first coin. 

'''


def sum1(list1):
    total = 0
    for ele in range(0, len(list1)): 
        total = total + list1[ele]
    return total
t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    r = sum1(l)/n
    if sum1(l)-(n-1)*r in l:
        print(l.index(sum1(l)-(n-1)*r)+1)
    else:
            print("Impossible")
