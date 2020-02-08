#include<stdio.h>
#include<stdlib.h>
#define ElementType int
#define MAXSIZE 20
/*
	¶þ·Ö²éÕÒ
*/
typedef struct LNode* List;
struct LNode {
	ElementType Element[MAXSIZE];
	int Length;
};
int BinarySearch(List Tbl, ElementType K) {
	int left, right, mid, NotFound = -1;
	left = 1;
	right = Tbl->Length;
	while (left <= right) {
		mid = (left + right) / 2;
		if (K < Tbl->Element[mid]) right = mid - 1;
		else if (K < Tbl->Element[mid]) left = mid + 1;
		else return mid;
	}
	return NotFound;
}