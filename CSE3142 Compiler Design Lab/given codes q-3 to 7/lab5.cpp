#include <iostream>
#include <cstring>
using namespace std;

// A utility function to check if a given character is operand
bool isOperand(char c) { return (c >= '0' && c <= '9' || c >= 'a' && c <= 'z'); }

// utility function to find value of and operand
int value(char c) { return (c - '0'); }

// This function evaluates simple expressions. It returns -1 if the
// given expression is invalid.
int evaluate(char *exp)
{
	// Base Case: Given expression is empty
	if (*exp == '\0') return -1;

	// The first character must be an operand, find its value
	int res = value(exp[0]);

	// Traverse the remaining characters in pairs
	for (int i = 1; exp[i]; i ++)
	{
		// The next character must be an operator, and
		// next to next an operand
		char opr = exp[i], opd = exp[i+1];

		// If next to next character is not an operand
		if (!isOperand(exp[i]) && !isOperand(exp[i+1]) ) return -1;

	}
	return res;
}

// Driver program to test above function
int main()
{
	string expression;
	cout << "Enter an Expression:";
	cin>> expression;

	int n = expression.length();
     // declaring character array
    char expr[n];

    // copying the contents of the
    // string to char array
    strcpy(expr, expression.c_str());


	int res = evaluate(expr);
	(res == -1)? cout << "Invalid\n":
				cout << "Valid" << endl;

	return 0;
}
