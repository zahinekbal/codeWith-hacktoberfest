/**
 * @file STLsort.cpp
 * @author Shantanu Mane (@RndmCodeGuy20) (shantanu.mane.200@outlook.com)
 * @brief Simple sorting program using standard STL sort.
 * @version  1.0.12
 * @date 2021-10-10
 * 
 * @copyright Copyright (c) 2021
 * 
 * @ref 1. Let Us C - Yashwant Kanetkar
 *      2. Programming in ANSI C - E. Balagurusamy -> Test Project Appendix IV
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);

	sort(arr, arr + n);

	cout << "\nArray after sorting using "
			"default sort is : \n";
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";

	return 0;
}
