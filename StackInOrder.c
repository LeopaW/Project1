#include<stdio.h>
#include<stdlib.h>
#include"all.h"

//��ջ
void Push(Stack1 PrtS, ElementType item) {
	if (PrtS->Top == MaxSize - 1) {
		printf("��ջ��"); return;
	}
	else {
		PrtS->Data[++(PrtS->Top)] = item;
		return;
	}
}
//��ջ
ElementType Pop(Stack1 PtrS) {
	if (PtrS->Top == -1) {
		printf("��ջ��");
		return 0;
	}
	else {
		return (PtrS->Data[(PtrS->Top)--]);
	}
}