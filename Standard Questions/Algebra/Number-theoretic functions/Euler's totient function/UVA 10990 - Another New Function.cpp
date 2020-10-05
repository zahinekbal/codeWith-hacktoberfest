/*
 * File: UVA 10990 - Another New Function
 * Algorithm: Euler's totient function
 * Created Date: Saturday August 1st 2020
 * Author: preetam rane
 */


#include <bits/stdc++.h>

using namespace std;

#define UPPERBOUND 2000100

vector<int> totient(UPPERBOUND);
vector<int> depth(UPPERBOUND, -1);

int depth_dp(int n) {
    if (depth[n] != -1)
        return depth[n];
    return depth[n] = depth_dp(totient[n]) + 1;
}

void Euler_totient() {
    for (int i = 0; i < UPPERBOUND; i++)
        totient[i] = i;

    for (int i = 2; i < UPPERBOUND; i++)
        if (totient[i] == i) {
            for (int j = i; j < UPPERBOUND; j += i)
                totient[j] -= totient[j] / i;
        }
}

int main(){
    Euler_totient();

    depth[0] = depth[1] = 0;
    for (int i = 1; i < UPPERBOUND; i++)
        depth_dp(i); 

    vector<int> sum(UPPERBOUND);
    sum[0] = 0;
    for (int i = 1; i < UPPERBOUND; i++)
        sum[i] = sum[i - 1] + depth[i];
    int N;
    scanf("%d", &N);
    while (N--) {
        int m, n;
        scanf("%d %d", &m, &n);
        printf("%d\n", sum[n] - sum[m - 1]);
    }
	return 0;
}
