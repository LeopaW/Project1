#include"all.h"

//����˳��
void AddQ(Queue1 PtrQ, ElementType item) {
	if(((PtrQ->rear + 1) % MaxSize) == PtrQ->front) {
		printf("������");
		return;
	}
	PtrQ->rear = (PtrQ->rear + 1) % MaxSize;
	PtrQ->Data[PtrQ->rear] = item;
}

ElementType DeleteQ(Queue1 PtrQ) {
	if (PtrQ->front == PtrQ->rear) {
		printf("���п�");
		return 0;  //ElementType��0�������
	}
	else {
		PtrQ->front = (PtrQ->front + 1) % MaxSize;
		return PtrQ->Data[PtrQ->front];
	}
}

Queue1 CreatQueue(int Max) {
	Queue1 Q;
	Q = (Queue1)malloc(sizeof(struct QNode1));
	return Q;
}

int isEmptyQ(Queue1 PtrQ) {
	return (PtrQ->front == PtrQ->rear);
}

//��������
ElementType DeleteQ(Queue2 PtrQ) {
	struct Node* FrontCell;
	ElementType FrontElem;
	if (PtrQ->front == NULL) {
		printf("���п�"); return 0;
	}
	FrontCell = PtrQ->front;
	if (PtrQ->front == PtrQ->rear)
		PtrQ->front = PtrQ->rear = NULL;
	else
		PtrQ->front = PtrQ->front->Next;
	FrontElem = FrontCell->Data;
	free(FrontCell);
	return FrontElem;
}

