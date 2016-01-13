/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction 
{
	int amount;
	char date[11];
	char description[20];
};

int isEqual(char *original, char *expected)
{
	while (*original&&*expected)
	{
		if (*original != *expected)
			return 0;
		original++;
		expected++;
	}
	if (!(*original || *expected))
		return 1;
	else
		return 0;
}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) 
{
	struct transaction *result = NULL;
	int i, j, RLen = 0;
	for (i = 0; i < ALen && A!=NULL; i++)
	{
		for (j = i; j < BLen && B!=NULL; j++)
		{
			if (isEqual(A[i].date, B[j].date))
			{
				RLen++;
				result = (struct transaction *)realloc(result, RLen*sizeof(struct transaction));
				result[RLen - 1] = A[i];
			}
		}
	}
	return result;
}