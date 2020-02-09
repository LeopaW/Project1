#include"all.h"
//最优二叉树又称哈夫曼树
/*
带权路径长度(WPL)：设二叉树有n个叶子结点，
每个叶子结点带有权值Wk,
从根结点到每个叶子结点的长度为lk,
则每个叶子结点的带权路径长度之和就是：
WPL=(k=1到n)求和wk*lk;
*/
/*
	哈夫曼树的特点：
	没有度为1的结点；
	n个叶子结点的哈夫曼树共有2n-1结点；
	哈夫曼树的任意非叶子节点的左右子树交换后仍是哈夫曼树；
	堆同一组权值{w1,w2,......,wn}，是否存在不同构的两颗哈夫曼树  是可以存在的。。
*/
typedef struct TreeNode2* HuffmanTree;
struct TreeNode2{
	HuffmanTree Left, Right;
	int Weight;
};
HuffmanTree Huffman(MinHeap H) {
	//假设H->Size个权值已经存在H->Elements[]->Weight里
	int i; 
	HuffmanTree T;
	BuildMinHeap(H);
	for (i = 1; i < H->Size; i++) {
		T = malloc(sizeof(struct TreeNode2));
		T->Left = DeleteMin(H); //从最小堆中删除一个结点，最为新T的左子结点
		T->Right = DeleteMin(H); //从最小堆中删除一个结点，最为新T的右子结点
		T->Weight = T->Left->Weight + T->Right->Weight;//计算新权值
		Insert(H, T);//将新T插入最小堆
	}
	T = DeleteMin(H);
	return T;
}

