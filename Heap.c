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
    //定义“哨兵”为大于堆中所有可能元素的值，便于以后更快操作.
    return H;
}

void Insert(MaxHeap H, ElementType item) {
    //将元素item插入最大堆H,其中H->Elements[0]已经定义为哨兵。
    int i;
    if (IsFull(H)) {
        printf("最大堆已满");
        return;
    }
    i = ++H->Size;
    for (; H->Elements[i / 2] < item; i /= 2)
        H->Elements[i] = H->Elements[i / 2];
    H->Elements[i] = item;
}


ElementType DeleteMax(MaxHeap H) {
    //从最大堆H中取出键值最大的元素，并删除一个结点.
    int Parent, Child;
    ElementType MaxItem, temp;
    if (IsEmpty(H)) {
        printf("最大堆已为空");
        return;
    }
    MaxItem = H->Elements[1];//取出根结点最大值
    temp = H->Elements[H->Size--];
    for (Parent = 1; Parent * 2 <= H->Size; Parent = Child) {
        Child = Parent * 2;
        if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1]))
            Child++;  //让Child指向左右子结点的较大者。
        if (temp >= H->Elements[Child])break;
        else
            H->Elements[Parent] = H->Elements[Child];
    }
    H->Elements[Parent] = temp;
    return MaxItem;
}
