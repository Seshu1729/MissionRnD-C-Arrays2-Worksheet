/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction 
{
	int amount;
	char date[11];
	char description[20];
};

int compare(char *date1, char *date2)
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

int countGreaterNumbers(struct transaction *Arr, int len, char *date) 
{
	int index = 0;
	while (index < len)
	{
		if (compare(Arr[index].date, date))
			return len-index;
		index++;
	}
	return 0;
}
