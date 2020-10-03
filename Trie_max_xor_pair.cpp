//Given an array of integers, we have to find two elements whose XOR is maximum.
//This is a famous question solved using trie data structure which comes under category of advanced data structure
#include <iostream>
using namespace std;
struct Node
{
   Node *left, *right;
   // Constructor. Set left and right to NULL
   Node():left(NULL),right(NULL){}
};
// Create a trie from the values in the array
void insertValueInTrie(Node* r, unsigned int x)
{
   unsigned int N = sizeof(unsigned int) * 8;
   for(int i=N-1; i>=0; i--)
   {
      unsigned int bitValue = (x & (1<<i)); // Get i'th Bit of x
      if(bitValue != 0)
      {
         if(r->right == NULL)
            r->right = new Node();
         r = r->right;
      }
      else
      {
         if(r->left == NULL)
            r->left = new Node();
         r = r->left;
      }
   }
}
// Find Max XOR of x in the tree rooted at r.
unsigned int findMaxXOR(Node* r, unsigned int x, int bitPos)
{
   if(r == NULL || bitPos < 0)
      return 0;
   if(bitPos == 0)
   {
      if( (x & (1<<bitPos)) == 1)
         return (r->left == NULL) ? 0 : 1;
      else
         return (r->right == NULL) ? 0 : 1;
   }
   unsigned int bitVal = 0;
   unsigned int number = 0;
   if( (x & (1<<bitPos)) != 0)
   {
      if(r->left == NULL)
      {
         number = findMaxXOR(r->right, x, bitPos-1);
         bitVal = 0;
      }
      else
      {
         number = findMaxXOR(r->left, x, bitPos-1);
         bitVal = 1;
      }
   }
   else
   {
      if(r->right == NULL)
      {
         number = findMaxXOR(r->left, x, bitPos-1);
         bitVal = 0;
      }
      else
      {
         number = findMaxXOR(r->right, x, bitPos-1);
         bitVal = 1;
      }
   }
   if(bitVal == 0)
      number = number & ~(1<<bitPos); // Resetting bitPos
   else
      number = number | (1<<bitPos); // Setting bitPos
   return number;
}
void printMaxXORTrie(unsigned int * arr, int n)
{
   // ROOT NODE
   Node* r = new Node();
   int maxXOR = 0;
   for(int i=0; i<n; i++)
   {
      unsigned int t = findMaxXOR(r, arr[i], (sizeof(unsigned int)*8)-1 );
      if(t > maxXOR)
         maxXOR = t;
      insertValueInTrie(r, arr[i]);
   }
   cout<<"MAX XOR VALUES : "<<maxXOR<<endl;
}
int main()
{
   unsigned int arr[] = {12, 15, 5, 7, 1, 9, 8, 6, 10, 13};
   printMaxXORTrie(arr, 10);
}