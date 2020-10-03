#if 1
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <iterator>
#include <list>
#include <string.h>
#include <fstream>
#include <set>
using namespace std;

char getinput()
{
	char in[] = "3 3 1 2 3 3 1 1 1";
	static int i = 0;
	return in[i++];
}

typedef unsigned long long int ULL;
typedef long long int LL;

#ifndef ONLINE_JUDGE
#define gchar getinput()
#else
#define gchar getchar_unlocked()
#endif


int fastread()
{
	register char c = 0;
	while (c < 33)
		c = gchar;

	int sign = 1;
	if (c == '-')
	{
		sign = -1;
		c = gchar;
	}
	int a = 0;
	while (c > 33)
	{
		a = a * 10 + c - '0';
		c = gchar;
	}
	a *= sign;
	return a;
}


int a[100002];
int main(int argc, char* argv[])
{
	int t, n, i, c;
	t = fastread();
	while (t--)
	{
		n = fastread();
		for (i = 0; i < n; ++i)
		{
			a[i] = fastread();
		}

		sort(a, a + n);
		
		i = 0;
		while ((i < n) && (a[i] == 0))
		{
			++i;
		}

		if (i == n)
		{
			printf("0\n");
			continue;
		}

		c = 1;
		for (i = i+1; i < n; ++i)
		{
			if (a[i - 1] != a[i])
			{
				++c;
			}
		}
		printf("%d\n", c);
	}

	return 0;
}

#endif