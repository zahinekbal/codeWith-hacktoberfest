define MAX_SIZE 1010001
using namespace std;
int mat[MAX_SIZE] = { 0 };

int main()
{
int Mnumber, Qtimes, Nsize,i,j;

cin >> Mnumber >> Qtimes >> Nsize;
int temp1,temp2;

for (i = 0; i < Nsize; ++i)
{
cin >> temp1;
mat[temp1]++;
for (j = 1; j <= Qtimes; ++j)
{
temp2 = temp1 + (j*Mnumber);
mat[temp2]++;
temp2 = temp1 - (j*Mnumber);
if(temp2>0)
mat[temp2]++;
}
}

temp2 = 0;
for (i = 0; i < MAX_SIZE; ++i)
{
temp2 = max(temp2, mat[i]);
}
cout << temp2 << endl;
return 0;
}
