#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

bool isBalanced(string s)
{
    stack<char> ans;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(' ||s[i] == '{' || s[i] == '[')
        {
            ans.push(s[i]);
        }
        else
        {
            if(ans.empty())
            {
                return false;
            }
            else
            {
                if(ans.top() == '(' && s[i] == ')')
                {
                    ans.pop();
                }
                else if(ans.top() == '{' && s[i] == '}')
                {
                    ans.pop();
                }
                else if(ans.top() == '[' && s[i] == ']')
                {
                    ans.pop();
                }
                else
                {
                    return false;
                }
            }

        }

    }

    if(ans.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    string s;
    cin >> s;
    while (s != "-1")
    {
        if(isBalanced(s))
        {
            cout << "Parentheses are balanced" << endl;
        }
        else
        {
            cout << "Parentheses are not balanced" << endl;
        }
        cin >> s;
    }

}
