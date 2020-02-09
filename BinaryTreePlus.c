#include"all.h"

//二叉树表示
//结构数组表示二叉树：静态链表.
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1  //为了区分NULL，0不能表示为空

struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
}T1[MaxTree],T2[MaxTree];

int main() {

	Tree R1, R2;
	//建二叉树1
	R1 = BuildTree(T1);
	//建二叉树2
	R2 = BuildTree(T2);
	//判别是否同构并输出
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
				T[i].Left = cl - '0'; //字符得到整数
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
	二叉搜索树(BST，Binary Search Tree)
	也称二叉排序树或二叉查找树
	二叉搜索树：一颗二叉树，可以为空；如果不为空，满足以下性质：
	1.非空左子树的所有键值小于其根结点的键值。
	2.非空右子树的所有键值大于其根结点的键值。
	3.左，右子树都是二叉搜索树。
*/

//尾递归
Position Find(ElementType X, BinTree BST) {
	if (!BST)return NULL;
	if (X > BST->Data)
		return Find(X, BST->Right);
	else if (X < BST->Data)
		return Find(X, BST->Left);
	else
		return BST;
}

//迭代函数
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
	if (!BST) printf("要删除的元素未找到");
	else if (X < BST->Data)
		BST->Left = Delete(X, BST->Left);
	else if (X > BST->Data)
		BST->Right = Delete(X, BST->Right);
	else//找到要删除的结点
		if (BST->Left && BST->Right) { //被删除的结点有左右两个结点.
			Tmp = FindMin(BST->Right);//在右子树中找到最小的元素填充删除结点
			BST->Data = Tmp->Data;
			BST->Right = Delete(BST->Data, BST->Right);//在删除结点的右子树中删除最小元素
		}
		else { //被删除结点有一个或无子结点
			Tmp = BST;
			if (!BST->Left)	//有右孩子或无子节点
				BST = BST->Right;
			else if (!BST->Right)//有左孩子或无子结点
				BST = BST->Left;
			free(Tmp);
		}
	return BST;
}
/*
	平衡二叉树：空树，或者任一结点左、右子树高度差的绝对值不超过1，即|BF(T)|<=1
	平衡因子（Balance Factor，简称BF）:BF(T)=hL-hR;
	其中hL和hR分别为T的左、右子树的高度
*/



