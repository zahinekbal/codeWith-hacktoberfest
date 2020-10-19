#include<iostream>
using namespace std;
void tower(int n,char *source,char *helper, char *destination)
{
    //base case
    if(n==0)
       {
           return;
       }
    tower(n-1,source,destination,helper);  // We will put n-1 disks in helper with the help of destination
    cout<<"taking "<<n<<"th disk from "<<source<<" to "<<destination<<endl;  // taking disk from source to destination
    tower(n-1,helper,source,destination);   // We want to put these n-1 disks from helper to destination with the help of source
}
int main()
{
    int n;
    cout<<"Enter Number of disks"<<endl;
    cin>>n;
    char source[10]="T1",helper[10]="T2",destination[10]="T3";
    tower(n,source,helper,destination);
}
