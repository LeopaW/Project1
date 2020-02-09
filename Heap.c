#include"all.h"
#define MaxData 100 
int IsFull(MaxHeap H) {
    return (H->Size == H->Capacity);
}

int IsEmpty(MaxHeap H) {
    return (H->Size == 0);
}

MaxHeap Create(int MaxSizeH) {
    MaxHeap H = malloc(sizeof(struct HeapStruct));
    H->Elements = malloc((MaxSizeH + 1) * sizeof(ElementType));
    H->Size = 0;
    H->Capacity = MaxSizeH;
    H->Elements[0] = MaxData;
    //���塰�ڱ���Ϊ���ڶ������п���Ԫ�ص�ֵ�������Ժ�������.
    return H;
}

void Insert(MaxHeap H, ElementType item) {
    //��Ԫ��item��������H,����H->Elements[0]�Ѿ�����Ϊ�ڱ���
    int i;
    if (IsFull(H)) {
        printf("��������");
        return;
    }
    i = ++H->Size;
    for (; H->Elements[i / 2] < item; i /= 2)
        H->Elements[i] = H->Elements[i / 2];
    H->Elements[i] = item;
}


ElementType DeleteMax(MaxHeap H) {
    //������H��ȡ����ֵ����Ԫ�أ���ɾ��һ�����.
    int Parent, Child;
    ElementType MaxItem, temp;
    if (IsEmpty(H)) {
        printf("������Ϊ��");
        return;
    }
    MaxItem = H->Elements[1];//ȡ����������ֵ
    temp = H->Elements[H->Size--];
    for (Parent = 1; Parent * 2 <= H->Size; Parent = Child) {
        Child = Parent * 2;
        if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1]))
            Child++;  //��Childָ�������ӽ��Ľϴ��ߡ�
        if (temp >= H->Elements[Child])break;
        else
            H->Elements[Parent] = H->Elements[Child];
    }
    H->Elements[Parent] = temp;
    return MaxItem;
}
