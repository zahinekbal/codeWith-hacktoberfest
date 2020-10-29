//Ques link:https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/
/*Problem Description

Given a string A denoting a stream of lowercase alphabets. You have to make new string B.

B is formed such that we have to find first non-repeating character each time a character is inserted to the stream and append it at the end to B. If no non-repeating character is found then append '#' at the end of B.



Problem Constraints
1 <= length of the string <= 100000



Input Format
The only argument given is string A.Output Format
Return a string B after processing the stream of lowercase alphabets A.



Example Input
Input 1:

 A = "abadbc"
Input 2:

 A = "abcabc"
Example Output
Output 1:

 "aabbdd"
Output 2:

 "aaabc#"
*/

string Solution::solve(string arr)
{

    queue<char> s;
    s.push(arr[0]);
    string st = ""; // answer string

    unordered_map<char, int> mp;

    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
        s.push(arr[i]);
        while (!s.empty())
        {
            if (mp[s.front()] == 1)// if frequency of front of queue is 1
            {
                st += s.front(); //add it to string
                break;
            }
            else
            {
                s.pop();//keep poping till freuency of s.front() == 1
            }
        }
        if (s.empty())
            st += '#'; //if no non repeating charchter, add '#'
    }

    return st;
}
