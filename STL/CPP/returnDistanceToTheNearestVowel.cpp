/*
    Problem statement : Write a function that takes in a string and for each character, returns the distance to the nearest vowel. If the character is a vowel itself, return 0.
    Probelm Link : https://edabit.com/challenge/neXwYQ5y7RSxkNfTe
*/

#include <iostream>
#include <cstdlib>
using namespace std;

//This function returns the closest vowel's distance from given index 
int findMinDistance(int* vowelpos, int vowelcount, int key){
    //this variable will store the minimum distance
    int minimum;
    //this array will store minimum distances from all the vowels
    int *minarray;
    minarray = (int *)malloc(vowelcount*sizeof(int));
    
    for(int i = 0;i<vowelcount;i++){
        //Finding Minimum distance from every vowel
        *(minarray+i) = abs(*(vowelpos+i)-key);

        //Assigning first value as the minimum distance
        if(i==0) minimum = *(minarray);
        
        //If some distance is smaller than minimum distance then assigning is as the minimum distance 
        else if(*(minarray+i)<minimum) minimum = *(minarray+i);

        if(minimum==1) break; 
        //distance will not get lower than 1, so that will be the best distance
    }
    return minimum;
}

//This function returns the array containing the disatnces of each charachter from nearest vowel
int* distanceToNearestVowel(std::string str){
    int len = str.length();
    
    //Creating an array that will contain all the distances
    int* returnList;
    returnList = (int *)malloc(len*sizeof(int));
    //Initializing every value to 1(Just for start)
    for(int i =0;i<len;i++)
        *(returnList+i) = 1;
    
    //For keeping track of the vowels
    int vowelcount = 0;
    
    //Initializing all the vowels' self distances as 0
    for(int i=0;i<len;i++){
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u'){
            *(returnList+i) = 0;
            vowelcount++;
        }
    }
    
    //Creating an array that knows positions of all the vowels in the main array
    int* vowelpos;
    vowelpos = (int *)malloc(vowelcount*sizeof(int));
    int temp = 0;
    for(int i=0;i<len;i++)
        if(*(returnList+i)==0) *(vowelpos + temp++) = i; 
    
    //Creating Final Array
    for(int i=0;i<len;i++)
        if(*(returnList+i) != 0) *(returnList+i) = findMinDistance(vowelpos,vowelcount,i); // findMinDistance function gives minimum distance from the nearest vowel
    
    //returning pointer to the first element of the result array
    return returnList;
}

int main()
{   
    //input
    std::string val = "abcdabcd";
    
    //printing result
    int *ret; 
    ret = distanceToNearestVowel(val);
    for(int i=0;i<val.length();i++)
        cout<< *(ret+i) << " ";
    
    return 0;
}