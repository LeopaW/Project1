#include"all.h"
/*
查找的本质：已知对象找位置
	有序安排对象：全序、半序
	直接“算出”对象位置：散列

散列查找法的两项基本工作：
	计算位置:构造散列函数确定关键词存储位置；
	解决冲突:应用某种策略解决多个关键词位置相同的问题
时间复杂度几乎是常量：O(1)，即查找时间与问题规模无关

装填因子（Loading Factor）：设散列表空间大小为m,填入表中元素个数是n,则称α=n/m为散列表的装填因子

“散列（Hashing）”的基本思想是：
（1)以关键字Key为自变量，通过一个确定的函数h（散列函数），计算出对应的函数值h（key），作为数据对象的存储地址。
（2）可能不同的关键字会映射到同一个散列地址撒谎给你，即和h(keyi)=h(keyj),称为“冲突（Collision）”。
*/

/*
Index Hash(const char *Key,int TableSize){
	unsigned int h = 0;
	while(*Key!='\0')
		h = (h<<5)+*Key++;
	return h%TableSize;
}
*/

/*
处理冲突的方法
换个位置：开放地址法
同一位置的冲突对象组织在一起：链地址法
*/
/*
typedef struct HashTbl* HashTable;
struct HashTbl {
	int TableSize;
	Cell* TheCells;
}H;

HashTable InitializeTable(int TableSize){
	HashTable H;
	int i;
	if(TableSize < MinTableSize){
		Error("散列表太小");
		return NULL；
	}
	H = (HashTable)malloc(sizeof(struct HashTbl));
	if(H==NULL){
		FatalError("空间溢出");
	}
	H->TableSize = NextPrime(TableSize);
	H->TheCells = (Cell*)malloc(sizeof(Cell)*H->TableSize);
	if(H->TheCells == NULL)
	FatalError("空间溢出");
	for(i = 0;i < H->TableSize; i++)
	 H->TheCells[i].Info = Empty;
	return H;
}


Position Find(ElementType Key, HashTable H) {//平方检测
	Position CurrentPos, NewPos;
	int CNum;
	CNum = 0;
	NewPos = CurrentPos = Hash(Key, H->TableSize);
	while (H->TheCells[NewPos].Info != Empty && H->TheCells[NewPos].Element != Key) {
		if (++CNum % 2) {
			NewPos = CurrentPos + (CNum + 1) / 2 * (CNum + 1) / 2;
			while (NewPos >= H->TableSize)
				NewPos -= H->TableSize;
		}
		else {
			NewPos = CurrentPos - CNum / 2 * CNum / 2;
			while (NewPos < 0)
				NewPos += H->TableSize;
		}
	}
}

void Insert(ElementType Key,HashTable H){
	Position Pos;
	Pos = Find(Key,H);
	if(H->TheCells[Pos].Info != Legitimate){
		H->TheCell[Pos].Info = Legitimate;
		H->TheCell[Pos].Element =Key;
	}
}
在开放地址散列表中，删除操作要很小心。通常只能”懒惰删除“，即需要增加一i个”删除标记（Deleted)“，
而不是真正删除它。以便查找时不会”断链“。其空间可以在下次插入时重用。

在散列（Rehashing）
当散列表元素太多（即装填因子α太大）时，查找效率会下降；
	实用最大装填因子一般取0.5<=α<=0.85
当装填因子过大时，解决的方法是加倍扩大散列表，这个过程叫做"在散列（Rehashing）"

分离链接发（Separate Chaining）
将相应位置上冲突的所有关键字存储在同一个单链表中

typedef struct ListNode *Position,*List;
struct ListNode{
	ElementType Element;
	Position Next;
}
typedef struct HashTbl *HashTable;
struct HashTbl{
	int TableSize;
	List TheLists;
};
Position Find(ElementType Key,HashTable H){
	Position P;
	int Pos;
	Pos = Hash(Key,H->TableSize);//初始散列位置
	P = H->TheLists[Pos].Next;  //获得链表头
	while (P!=NULL&&strcmp(P->Element,Key))
		P=P->Next;
	return P;
}



*/