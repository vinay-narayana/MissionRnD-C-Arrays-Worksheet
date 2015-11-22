/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K) {
	if (len <= 0 || students == NULL || K <= 0)
		return NULL;
	if (K > len)
		K = len;
	int i;
	int j;
	int min;
	struct student **ans = (struct student **) malloc(sizeof(struct student *) * K);
	for (i = 0; i < K; i++)
		ans[i] = (struct student *) malloc(sizeof(struct student) * K);
	for (i = 0; i < K; i++) {
		*ans[i] = students[i];
	}
	for (i = K; i < len; i++) {
		min = 0;
		for (j = 1; j < K; j++) {
			if (ans[min]->score > ans[j]->score) {
				min = j;
			}
		}
		if (students[i].score > ans[min]->score) {
			*ans[min] = students[i];
		}
	}
	return ans;
}