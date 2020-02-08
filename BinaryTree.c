#include"all.h"
//二叉树的遍历
/*
先序遍历
遍历过程：
1.访问根节点
2.先序遍历其左子树
3.先序遍历其右子树
*/
void PreOrderTraversal(BinTree BT) {
	if (BT) {
		printf("%d", BT->Data);
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
	}
}
/*
中序遍历
遍历过程：
1.先序遍历其左子树
2.访问根节点
3.先序遍历其右子树
*/
void InOrderTraversal(BinTree BT) {
	if (BT) {
		PreOrderTraversal(BT->Left);
		printf("%d", BT->Data);
		PreOrderTraversal(BT->Right);
	}
}
/*
后序遍历
遍历过程：
1.先序遍历其左子树
2.先序遍历其右子树
3.访问根节点
*/
void PostOrderTraversal(BinTree BT) {
	if (BT) {
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
		printf("%d", BT->Data);
	}
}

// 二叉树的非递归遍历
// 中序遍历非递归遍历算法 
// 基本思路：使用堆栈
/*
	遇到一个结点，就把它压栈，并区遍历它的左子树.
	当左子树遍历结束后,从栈顶弹出这个节点并访问它.
	然后按其右指针再去中序遍历该节点的右子树.
*/
void InOrderTraversalPlus(BinTree BT) {
	BinTree T = BT;
	Stack2 S = CreatStack(MaxSize);
	while (T || !IsEmpty(S)) {
		while (T) {   //一直向左并将沿途结点压入堆栈
			Push(S, T);
			T = T->Left;
		}
		if (!IsEmpty(S)) {
			T = Pop(S);  //结点弹出堆栈
			printf("%5d", T->Data);  //打印结点
			T = T->Right; //转向右子树
		}
	}
}

//层序遍历
/*
	层序基本过程：先根结点入队，然后：
	1.从队列中取出一个元素；
	2.访问该元素所指结点；
	3.若该元素所指结点的左右孩子结点非空，则将其左右孩子的指针顺序入队.
*/
void LevelOrderTraversal(BinTree BT) {
	Queue1 Q;
	BinTree T;
	if (!BT) return;
	Q = CreatQueue(MaxSize);
	AddQ(Q, BT);   //这里的ElementType为BinTree
	while (!isEmptyQ(Q)) {
		T = DeleteQ(Q);
		printf("%d\n", T->Data);
		if (T->Left)AddQ(Q, T->Left);
		if (T->Right)AddQ(Q, T->Right);
	}
}

//例子：遍历二叉树输出二叉树的叶子结点.
void PreOrderPrintLeaves(BinTree BT) {
	if (BT) {
		if (!BT->Left && !BT->Right) {
			printf("%d", BT->Data);
		}
		PreOrderPrintLeaves(BT->Left);
		PreOrderPrintLeaves(BT->Right);
	}
}
//例子：求二叉树的高度
int PostOrderGetHeight(BinTree BT) {
	int HL, HR, MaxH;
	if (BT) {
		HL = PostOrderGetHeight(BT->Left);
		HR = PostOrderGetHeight(BT->Right);
		MaxH = (HL > HR) ? HL : HR;
		return (MaxH + 1);
	}
	else
		return 0;
}


