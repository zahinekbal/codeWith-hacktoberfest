//Solid rectangular star pattern:
//Number of rows: 3
//Number of columns: 5

//* * * * *
//* * * * *
//* * * * *
//Program to print solid rectangular star pattern
import java.util.*;

public class Main 

{ 

static void solid_rectangle(int n, int m)

{

int i, j;

for (i = 1; i <= n; i++)

{

for (j = 1; j <= m; j++)

{

System.out.print(“*”);

}

System.out.print(“n”);

}



}

public static void main (String args[])

{ 

int rows, columns;

Scanner sc = new Scanner(System.in);

System.out.print(“nEnter the number of rows : “);

rows = sc.nextInt();

System.out.print(“nEnter the number of columns : “);

columns = sc.nextInt();

System.out.print(“n”);

solid_rectangle(rows, columns);

} 

}

