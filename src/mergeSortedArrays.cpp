/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

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

int compareTwoDates(char *date1, char *date2)
{
	int indicator[8] = { 6, 7, 8, 9, 3, 4, 0, 1 };
	int index;
	for (index = 0; index < 8; index++)
	{
		if (date1[indicator[index]] > date2[indicator[index]])
			return 1;
		else if (date1[indicator[index]] < date2[indicator[index]])
			return 0;
	}
	return 0;
}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) 
{
	struct transaction *result;
	int AIndex = 0, BIndex = 0, RIndex = 0;
	result = (struct transaction *)malloc((ALen + BLen)*sizeof(struct transaction));
	if (A == NULL || B == NULL)
		return NULL;
	else
	{
		while (AIndex < ALen&&BIndex < BLen)
		{
			if (!compareTwoDates(A[AIndex].date, B[BIndex].date))
			{
				result[RIndex] = A[AIndex];
				RIndex++;
				AIndex++;
			}
			else
			{
				result[RIndex] = B[BIndex];
				RIndex++;
				BIndex++;
			}
		}
		if (AIndex < ALen)
		{
			while (AIndex < ALen)
			{
				result[RIndex] = A[AIndex];
				RIndex++;
				AIndex++;
			}
		}
		if (BIndex < BLen)
		{
			while (BIndex < BLen)
			{
				result[RIndex] = B[BIndex];
				RIndex++;
				BIndex++;
			}
		}
	}
	return result;
}