/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

#include <iostream>

int findSingleOccurenceNumber(int *A, int len)
{
	if (A == NULL)
		return -1;
	int index;
	int appear_one_time = 0, appear_two_times = 0, not_three;
	for (index = 0; index < len; index++)
	{
		appear_two_times |= appear_one_time & A[index];
		appear_one_time ^= A[index];
		not_three = ~(appear_one_time&appear_two_times);
		appear_one_time &= not_three;
		appear_two_times &= not_three;
	}
	return appear_one_time;
}