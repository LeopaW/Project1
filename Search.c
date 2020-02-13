#include"all.h"
/*
���ҵı��ʣ���֪������λ��
	�����Ŷ���ȫ�򡢰���
	ֱ�ӡ����������λ�ã�ɢ��

ɢ�в��ҷ����������������
	����λ��:����ɢ�к���ȷ���ؼ��ʴ洢λ�ã�
	�����ͻ:Ӧ��ĳ�ֲ��Խ������ؼ���λ����ͬ������
ʱ�临�Ӷȼ����ǳ�����O(1)��������ʱ���������ģ�޹�

װ�����ӣ�Loading Factor������ɢ�б�ռ��СΪm,�������Ԫ�ظ�����n,��Ʀ�=n/mΪɢ�б��װ������

��ɢ�У�Hashing�����Ļ���˼���ǣ�
��1)�Թؼ���KeyΪ�Ա�����ͨ��һ��ȷ���ĺ���h��ɢ�к��������������Ӧ�ĺ���ֵh��key������Ϊ���ݶ���Ĵ洢��ַ��
��2�����ܲ�ͬ�Ĺؼ��ֻ�ӳ�䵽ͬһ��ɢ�е�ַ���Ѹ��㣬����h(keyi)=h(keyj),��Ϊ����ͻ��Collision������
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
�����ͻ�ķ���
����λ�ã����ŵ�ַ��
ͬһλ�õĳ�ͻ������֯��һ������ַ��
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
		Error("ɢ�б�̫С");
		return NULL��
	}
	H = (HashTable)malloc(sizeof(struct HashTbl));
	if(H==NULL){
		FatalError("�ռ����");
	}
	H->TableSize = NextPrime(TableSize);
	H->TheCells = (Cell*)malloc(sizeof(Cell)*H->TableSize);
	if(H->TheCells == NULL)
	FatalError("�ռ����");
	for(i = 0;i < H->TableSize; i++)
	 H->TheCells[i].Info = Empty;
	return H;
}


Position Find(ElementType Key, HashTable H) {//ƽ�����
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
�ڿ��ŵ�ַɢ�б��У�ɾ������Ҫ��С�ġ�ͨ��ֻ�ܡ�����ɾ����������Ҫ����һi����ɾ����ǣ�Deleted)����
����������ɾ�������Ա����ʱ���ᡱ����������ռ�������´β���ʱ���á�

��ɢ�У�Rehashing��
��ɢ�б�Ԫ��̫�ࣨ��װ�����Ӧ�̫��ʱ������Ч�ʻ��½���
	ʵ�����װ������һ��ȡ0.5<=��<=0.85
��װ�����ӹ���ʱ������ķ����Ǽӱ�����ɢ�б�������̽���"��ɢ�У�Rehashing��"

�������ӷ���Separate Chaining��
����Ӧλ���ϳ�ͻ�����йؼ��ִ洢��ͬһ����������

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
	Pos = Hash(Key,H->TableSize);//��ʼɢ��λ��
	P = H->TheLists[Pos].Next;  //�������ͷ
	while (P!=NULL&&strcmp(P->Element,Key))
		P=P->Next;
	return P;
}



*/