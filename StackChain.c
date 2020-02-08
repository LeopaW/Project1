#include"all.h"
Stack2 CreateStack() {
	Stack2 S;
	S = (Stack2)malloc(sizeof(struct SNode2));
	S->Next = NULL;
	return S;
}

int IsEmpty(Stack2 S) {
	return (S->Next == NULL);
}

void Push(ElementType item, Stack2 S) {
	Stack2 TmpCell;
	TmpCell = (Stack2)malloc(sizeof(struct SNode2));
	TmpCell->Data = item;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
}

ElementType Pop(Stack2 S) {
	Stack2 FirstCell;
	ElementType TopData;
	if (IsEmpty(S)) {
		printf("¶ÑÕ»¿Õ"); return NULL;
	}
	else {
		FirstCell = S->Next;
		S->Next = FirstCell->Next;
		TopData = FirstCell->Data;
		free(FirstCell);
		return TopData;

	}
}
