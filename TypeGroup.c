#include"all.h"
//������������ʾ����
typedef struct {
	ElementType Data;
	int Parent;
}SetType;

int Find(SetType S[], ElementType X) {
	/*
		������S�в���ֵΪX��Ԫ�������ļ���
		MaxSize��ȫ�ֱ�����Ϊ����S����󳤶�
	*/
	int i;
	for (i = 0; i < MaxSize && S[i].Data != X; i++);
	if (i >= MaxSize)return -1;//δ�ҵ�X������-1
	for (; S[i].Parent >= 0; i = S[i].Parent);
	return i;//�ҵ�X������飬�����������������S�е��±ꡣ
}
