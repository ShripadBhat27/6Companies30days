// C++ program to find a missing number in a
// string of consecutive numbers without any
// separator.
#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 6;

// gets the integer at position i with length m,
// returns it or -1, if none
int getValue(const string& str, int i, int m)
{
	if (i + m > str.length())
		return -1;

	// Find value at index i and length m.
	int value = 0;
	for (int j = 0; j < m; j++)
	{
		int c = str[i + j] - '0';
		if (c < 0 || c > 9)
			return -1;
		value = value * 10 + c;
	}
	return value;
}

// Returns value of missing number
int findMissingNumber(const string& str)
{
	// Try all lengths for first number
	for (int m=1; m<=MAX_DIGITS; ++m)
	{
		// Get value of first number with current
		// length/
		int n = getValue(str, 0, m);
		if (n == -1)
		break;

		// To store missing number of current length
		int missingNo = -1;

		// To indicate whether the sequence failed
		// anywhere for current length.
		bool fail = false;

		// Find subsequent numbers with previous number as n
		for (int i=m; i!=str.length(); i += 1 + log10l(n))
		{
			// If we haven't yet found the missing number
			// for current length. Next number is n+2. Note
			// that we use Log10 as (n+2) may have more
			// length than n.
			if ((missingNo == -1) &&
				(getValue(str, i, 1+log10l(n+2)) == n+2))
			{
				missingNo = n + 1;
				n += 2;
			}

			// If next value is (n+1)
			else if (getValue(str, i, 1+log10l(n+1)) == n+1)
				n++;

			else
			{
				fail = true;
				break;
			}
		}

		if (!fail)
		return missingNo;
	}
	return -1; // not found or no missing number
}

// Driver code
int main()
{
	cout << findMissingNumber("99101102");
	cout<< "\n"<<findMissingNumber("596597598600601602");
	return 0;
}
