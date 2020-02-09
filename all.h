#ifndef  __ALL_H_
#define __ALL_H_
#include<stdio.h> 
#include<stdlib.h>
#define ElementType int  //待定为int
#define MaxSize 10

//二叉树链表存储
typedef struct TreeNode* BinTree;
typedef BinTree Position;
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};
void PreOrderTraversal(BinTree BT);
void InOrderTraversal(BinTree BT);
void PostOrderTraversal(BinTree BT);
void InOrderTraversalPlus(BinTree BT);


//堆链表存储
typedef struct SNode2* Stack2;
struct SNode2 {
	Stack2 Next;
	ElementType Data;
};
Stack2 CreateStack();
int IsEmpty(Stack2 S);
void Push(ElementType item, Stack2 S);
ElementType Pop(Stack2 S);


//堆顺序存储
typedef struct SNode1* Stack1;
struct SNode1 {
	int Top;
	ElementType Data[MaxSize];
};
void Push(Stack1 PrtS, ElementType item);
ElementType Pop(Stack1 PtrS);


//队列顺序
typedef struct QNode1* Queue1;
struct QNode1 {
	int rear;
	int front;
	ElementType Data[MaxSize];
};
Queue1 CreatQueue(int Max);
void AddQ(Queue1 PtrQ, ElementType item);
ElementType DeleteQ(Queue1 PtrQ);
int isEmptyQ(Queue1 PtrQ);


//队列链表
typedef struct QNode2* Queue2;
struct Node {
	ElementType Data;
	struct Node* Next;
};
struct QNode2 {
	struct Node* rear;
	struct Node* front;
};
Queue2 PtrQ;

ElementType DeleteQ(Queue2 PtrQ);

//堆
typedef struct HeapStruct* MaxHeap;
struct HeapStruct {
	ElementType* Elements;
	int Size;		//堆当前元素个数
	int Capacity;  //堆最大容量
};

typedef struct HeapStruct2* MinHeap;
struct HeapStruct2 {
	ElementType* Elements;
	int Size;		//堆当前元素个数
	int Capacity;  //堆最大容量
};


#endif