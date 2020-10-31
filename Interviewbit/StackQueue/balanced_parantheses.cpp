//Ques link : https://www.interviewbit.com/problems/balanced-parantheses/

/*Problem Description

Given a string A consisting only of '(' and ')'.

You need to find whether parantheses in A is balanced or not ,if it is balanced then return 1 else return 0.



Problem Constraints
1 <= |A| <= 105



Input Format
First argument is an string A.
Output Format
Return 1 if parantheses in string are balanced else return 0.



Example Input
Input 1:

 A = "(()())"
Input 2:

 A = "(()"


Example Output
Output 1:
1

Output 2:

 0
*/

int Solution::solve(string A)
{

    stack<char> s; //stack to check balanced pairs
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == '(')
            s.push(A[i]); //push in case of '('
        if (A[i] == ')')
        {
            if (s.empty() || s.top() != '(') //if stack is empty or there are no corresponding opening parantheses,return 0 
                return 0;
            else
                s.pop(); //pop the opening parentheses, to check for other pairs
        }
    }
    if (!s.empty())// if there remains a single opening parentheses without any closing parantheses, return false
        return 0;
    return 1;
}
