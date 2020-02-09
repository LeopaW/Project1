#include"all.h"
//���Ŷ������ֳƹ�������
/*
��Ȩ·������(WPL)�����������n��Ҷ�ӽ�㣬
ÿ��Ҷ�ӽ�����ȨֵWk,
�Ӹ���㵽ÿ��Ҷ�ӽ��ĳ���Ϊlk,
��ÿ��Ҷ�ӽ��Ĵ�Ȩ·������֮�;��ǣ�
WPL=(k=1��n)���wk*lk;
*/
/*
	�����������ص㣺
	û�ж�Ϊ1�Ľ�㣻
	n��Ҷ�ӽ��Ĺ�����������2n-1��㣻
	���������������Ҷ�ӽڵ�������������������ǹ���������
	��ͬһ��Ȩֵ{w1,w2,......,wn}���Ƿ���ڲ�ͬ�������Ź�������  �ǿ��Դ��ڵġ���
*/
typedef struct TreeNode2* HuffmanTree;
struct TreeNode2{
	HuffmanTree Left, Right;
	int Weight;
};
HuffmanTree Huffman(MinHeap H) {
	//����H->Size��Ȩֵ�Ѿ�����H->Elements[]->Weight��
	int i; 
	HuffmanTree T;
	BuildMinHeap(H);
	for (i = 1; i < H->Size; i++) {
		T = malloc(sizeof(struct TreeNode2));
		T->Left = DeleteMin(H); //����С����ɾ��һ����㣬��Ϊ��T�����ӽ��
		T->Right = DeleteMin(H); //����С����ɾ��һ����㣬��Ϊ��T�����ӽ��
		T->Weight = T->Left->Weight + T->Right->Weight;//������Ȩֵ
		Insert(H, T);//����T������С��
	}
	T = DeleteMin(H);
	return T;
}

