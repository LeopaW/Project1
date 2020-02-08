#ifndef  __ALL_H_
#define __ALL_H_
#include<stdio.h> 
#include<stdlib.h>
#define ElementType int  //´ý¶¨Îªint
#define MaxSize 10

//¶þ²æÊ÷Á´±í´æ´¢
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


//¶ÑÁ´±í´æ´¢
typedef struct SNode2* Stack2;
struct SNode2 {
	Stack2 Next;
	ElementType Data;
};
Stack2 CreateStack();
int IsEmpty(Stack2 S);
void Push(ElementType item, Stack2 S);
ElementType Pop(Stack2 S);


//¶ÑË³Ðò´æ´¢
typedef struct SNode1* Stack1;
struct SNode1 {
	int Top;
	ElementType Data[MaxSize];
};
void Push(Stack1 PrtS, ElementType item);
ElementType Pop(Stack1 PtrS);


//¶ÓÁÐË³Ðò
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


//¶ÓÁÐÁ´±í
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
#endif