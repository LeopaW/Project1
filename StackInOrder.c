#include<stdio.h>
#include<stdlib.h>
#include"all.h"

//ÈëÕ»
void Push(Stack1 PrtS, ElementType item) {
	if (PrtS->Top == MaxSize - 1) {
		printf("¶ÑÕ»Âú"); return;
	}
	else {
		PrtS->Data[++(PrtS->Top)] = item;
		return;
	}
}
//³öÕ»
ElementType Pop(Stack1 PtrS) {
	if (PtrS->Top == -1) {
		printf("¶ÑÕ»¿Õ");
		return 0;
	}
	else {
		return (PtrS->Data[(PtrS->Top)--]);
	}
}