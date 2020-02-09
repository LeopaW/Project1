#include"all.h"

//��������ʾ
//�ṹ�����ʾ����������̬����.
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1  //Ϊ������NULL��0���ܱ�ʾΪ��

struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
}T1[MaxTree],T2[MaxTree];

int main() {

	Tree R1, R2;
	//��������1
	R1 = BuildTree(T1);
	//��������2
	R2 = BuildTree(T2);
	//�б��Ƿ�ͬ�������
	//if(Isomerphic(R1,R2)) printf("Yes\n");
	//else printf("No\n");

	return 0;
}

Tree BuildTree(struct TreeNode T[]) {
	int N,i;
	Tree Root;
	int check[MaxTree];
	char cl, cr;
	scanf("%d\n", &N);
	if (N) {
		for (i = 0; i < N; i++)check[i] = 0;
		for (i = 0; i < N; i++) {
			scanf("%c %c %c", &T[i].Element, &cl, &cr);
			if (cl != '-') {
				T[i].Left = cl - '0'; //�ַ��õ�����
				check[T[i].Left] = 1;
			}
			else
				T[i].Left = Null;
			if (cr != '-') {
				T[i].Right = cr - '0';
				check[T[i].Right] = 1;
			}
			else
				T[i].Right = Null;
		}
		for (i = 0; i < N; i++)if (!check[i])break;
		Root = i;
	}
	return Root;
}

int Isomorphic(Tree R1, Tree R2) {
	if ((R1 == Null) && (R2 == Null))
		return 1;
	if (((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null)))
		return 0;
	if (T1[R1].Element != T2[R2].Element)
		return 0;
	if ((T1[R1].Left == Null) && (T2[R2].Left == Null))
		return Isomorphic(T1[R1].Right, T2[R2].Right);
	if (((T1[R1].Left != Null) && (T2[R2].Left != Null)) && ((T1[T1[R1].Left].Element) == (T2[T2[R2].Left].Element)))
		return (Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right));
	else
		return (Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Left, T2[R2].Right));
}



/*
	����������(BST��Binary Search Tree)
	Ҳ�ƶ�������������������
	������������һ�Ŷ�����������Ϊ�գ������Ϊ�գ������������ʣ�
	1.�ǿ������������м�ֵС��������ļ�ֵ��
	2.�ǿ������������м�ֵ����������ļ�ֵ��
	3.�����������Ƕ�����������
*/

//β�ݹ�
Position Find(ElementType X, BinTree BST) {
	if (!BST)return NULL;
	if (X > BST->Data)
		return Find(X, BST->Right);
	else if (X < BST->Data)
		return Find(X, BST->Left);
	else
		return BST;
}

//��������
Position IterFind(ElementType X, BinTree BST) {
	while (BST) {
		if (X > BST->Data)
			BST = BST->Right;
		else if (X < BST->Data)
			BST = BST->Left;
		else 
			return BST;
	}
	return NULL;
}

Position FindMin(BinTree BST) {
	if (!BST)return NULL;
	else if (!BST->Left)
		return BST;
	else return FindMin(BST->Left);
}

Position FindMax(BinTree BST) {
	/*
	if (!BST)return NULL;
	else if (!BST->Right)
		return BST;
	else return FindMax(BST->Right);
	*/
	if (BST)
		while (BST->Right) BST = BST->Right;
	return BST;
}

BinTree Insert(ElementType X, BinTree BST) {
	if (!BST) {
		BST = malloc(sizeof(struct TreeNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else {
		if (X < BST->Data)
			BST->Left = Insert(X, BST->Left);
		else if (X > BST->Data)
			BST->Right = Insert(X, BST->Right);
	}
	return BST;
}

BinTree Delete(ElementType X, BinTree BST) {
	Position Tmp;
	if (!BST) printf("Ҫɾ����Ԫ��δ�ҵ�");
	else if (X < BST->Data)
		BST->Left = Delete(X, BST->Left);
	else if (X > BST->Data)
		BST->Right = Delete(X, BST->Right);
	else//�ҵ�Ҫɾ���Ľ��
		if (BST->Left && BST->Right) { //��ɾ���Ľ���������������.
			Tmp = FindMin(BST->Right);//�����������ҵ���С��Ԫ�����ɾ�����
			BST->Data = Tmp->Data;
			BST->Right = Delete(BST->Data, BST->Right);//��ɾ��������������ɾ����СԪ��
		}
		else { //��ɾ�������һ�������ӽ��
			Tmp = BST;
			if (!BST->Left)	//���Һ��ӻ����ӽڵ�
				BST = BST->Right;
			else if (!BST->Right)//�����ӻ����ӽ��
				BST = BST->Left;
			free(Tmp);
		}
	return BST;
}
/*
	ƽ���������������������һ������������߶Ȳ�ľ���ֵ������1����|BF(T)|<=1
	ƽ�����ӣ�Balance Factor�����BF��:BF(T)=hL-hR;
	����hL��hR�ֱ�ΪT�����������ĸ߶�
*/



