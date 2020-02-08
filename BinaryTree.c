#include"all.h"
//�������ı���
/*
�������
�������̣�
1.���ʸ��ڵ�
2.���������������
3.���������������
*/
void PreOrderTraversal(BinTree BT) {
	if (BT) {
		printf("%d", BT->Data);
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
	}
}
/*
�������
�������̣�
1.���������������
2.���ʸ��ڵ�
3.���������������
*/
void InOrderTraversal(BinTree BT) {
	if (BT) {
		PreOrderTraversal(BT->Left);
		printf("%d", BT->Data);
		PreOrderTraversal(BT->Right);
	}
}
/*
�������
�������̣�
1.���������������
2.���������������
3.���ʸ��ڵ�
*/
void PostOrderTraversal(BinTree BT) {
	if (BT) {
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
		printf("%d", BT->Data);
	}
}

// �������ķǵݹ����
// ��������ǵݹ�����㷨 
// ����˼·��ʹ�ö�ջ
/*
	����һ����㣬�Ͱ���ѹջ��������������������.
	������������������,��ջ����������ڵ㲢������.
	Ȼ������ָ����ȥ��������ýڵ��������.
*/
void InOrderTraversalPlus(BinTree BT) {
	BinTree T = BT;
	Stack2 S = CreatStack(MaxSize);
	while (T || !IsEmpty(S)) {
		while (T) {   //һֱ���󲢽���;���ѹ���ջ
			Push(S, T);
			T = T->Left;
		}
		if (!IsEmpty(S)) {
			T = Pop(S);  //��㵯����ջ
			printf("%5d", T->Data);  //��ӡ���
			T = T->Right; //ת��������
		}
	}
}

//�������
/*
	����������̣��ȸ������ӣ�Ȼ��
	1.�Ӷ�����ȡ��һ��Ԫ�أ�
	2.���ʸ�Ԫ����ָ��㣻
	3.����Ԫ����ָ�������Һ��ӽ��ǿգ��������Һ��ӵ�ָ��˳�����.
*/
void LevelOrderTraversal(BinTree BT) {
	Queue1 Q;
	BinTree T;
	if (!BT) return;
	Q = CreatQueue(MaxSize);
	AddQ(Q, BT);   //�����ElementTypeΪBinTree
	while (!isEmptyQ(Q)) {
		T = DeleteQ(Q);
		printf("%d\n", T->Data);
		if (T->Left)AddQ(Q, T->Left);
		if (T->Right)AddQ(Q, T->Right);
	}
}

//���ӣ����������������������Ҷ�ӽ��.
void PreOrderPrintLeaves(BinTree BT) {
	if (BT) {
		if (!BT->Left && !BT->Right) {
			printf("%d", BT->Data);
		}
		PreOrderPrintLeaves(BT->Left);
		PreOrderPrintLeaves(BT->Right);
	}
}
//���ӣ���������ĸ߶�
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


