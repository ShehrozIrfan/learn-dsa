/***************************************************************************
 *
 * In this problem, we are required to check for balanced parantheses check
 * When we say parentheses, we mean pairs of (), {} and []
 * For balancing of parentheses, the last opened one should be closed first
 * For example, (), {}, [], {() ()}, [{()}()] are balanced
 * However, [(]), {[()} are not balanced
 *
 ****************************************************************************/

#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

stack<char> S;

bool pairsWithTop(char x)
{
	if (S.top() == '(' && x == ')')
		return true;
	else if (S.top() == '[' && x == ']')
		return true;
	else if (S.top() == '{' && x == '}')
		return true;
	else
		return false;
}

bool balancedParantheses(char exp[])
{
	int n = strlen(exp);
	for (int i = 0; i < n; i++)
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
		{
			S.push(exp[i]);
		}
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (S.empty() || !pairsWithTop(exp[i]))
			{
				return false;
			}
			else
			{
				S.pop();
			}
		}
	}
	return (S.empty()) ? true : false;
}

int main()
{
	char exp[101];
	cin >> exp;
	if (balancedParantheses(exp))
		cout << "Balanced\n";
	else
		cout << "Imbalanced\n";
	return 0;
}
