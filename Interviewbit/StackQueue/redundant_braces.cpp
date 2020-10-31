//Ques link: https://www.interviewbit.com/problems/redundant-braces/
/*Given a string A denoting an expression. It contains the following operators ’+’, ‘-‘, ‘*’, ‘/’.

Chech whether A has redundant braces or not.

Return 1 if A has redundant braces, else return 0.

Note: A will be always a valid expression.

Input Format

The only argument given is string A.
Output Format

Return 1 if string has redundant braces, else return 0.

EXAMPLE: 
Input 1:
    A = "((a + b))"
Output 1:
    1
    Explanation 1:
        ((a + b)) has redundant braces so answer will be 1.

Input 2:
    A = "(a + (a + b))"
Output 2:
    0
    Explanation 2:
        (a + (a + b)) doesn't have have any redundant braces so answer will be 0.
*/

int Solution::braces(string st)
{

    stack<char> s;
    bool flag = true;
    for (auto &ch : st)
    {

        if (ch == ')') // on encounter of a '(', check for a valid expression till we get ')'
        {
            char p = s.top();
            s.pop();
            flag = true;
            while (p != '(')
            {
                if (p == '+' || p == '*' || p == '/' || p == '-')// if we encounter an operator, then there is an expression, hence no redundant braces
                    flag = false;

                p = s.top();
                s.pop();
            }

            if (flag)// if we encounter no operatore i.e. we have redundant braces 
                return 1;
        }
        else

            s.push(ch); //push other characters in stack
    }

    return 0;
}
