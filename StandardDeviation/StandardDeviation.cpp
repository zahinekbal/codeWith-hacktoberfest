// ***************************
// Calculate the standard deviation given N integers
// ***************************

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

double calculateStandardDeviation(vector<int> arr)
{
    //Calculate the mean
    double mean = 0;
    for(int i=0;i<arr.size();i++)
    {
        mean += arr[i];
    }
    mean = mean/arr.size();

    double variance = 0;
    for(int j=0;j<arr.size();j++)
    {
        variance += pow((arr[j] - mean),2);
    }

    double standardDeviation = 0;
    standardDeviation = sqrt(variance/arr.size());
    return standardDeviation;
}

int main() {
    int size;
    cin >> size;
    vector<int> arr;
    int x;
    while(cin >> x)
    {
        arr.push_back(x);
    }

    cout << fixed << setprecision(1) << calculateStandardDeviation(arr) << endl;

    return 0;
}