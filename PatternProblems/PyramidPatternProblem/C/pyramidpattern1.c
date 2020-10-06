/* C program to print solid rectangle star pattern */
//Solid rectangular star pattern:
//Number of rows: 3
//Number of columns: 5

//* * * * *
//* * * * *
//* * * * *
//Program to print solid rectangular star pattern
#include <stdio.h>
void solid_rectangle(int n, int m)

{

int i, j;

for (i = 1; i <= n; i++)

{

for (j = 1; j <= m; j++)

{

printf(“*”);

}

printf(“n”);

}

}

int main()

{

int rows, columns;

printf(“nEnter the number of rows : “);

scanf(“%d”, &rows);

printf(“nEnter the number of columns : “);

scanf(“%d”, &columns);

printf(“n”);

solid_rectangle(rows, columns);

return 0;

}

