#include"all.h"
/*
冒泡排序
*/

void Bubble_Sort(ElementType A[], int N) {
	int i,P,flag;
	for (P = N - 1; P >= 0; P--) {
		flag = 0;
		for (i = 0; i < p; i++) {
			if (A[i] > A[i + 1]) {
				Swap(A[i], A[i + 1]);
				flag = 1;
			}
		}
		if (flag == 0)break;
	}
}

/*
插入排序
*/
void Insertion_Sort(ElementType A[], int N) {
	int P,i;
	for (P = 1; P < N; P++) {
		int Tmp = A[P]; //取出下一个数
		for (i = P; i > 0 && A[i - 1] > Tmp; i--) {
			A[i] = A[i - 1];//找到比Tmp小的那一位
		}
		A[i] = Tmp;//i-1比tmp小，所以i就是他的位置
	}
}
//插入排序和冒泡排序都是简单排序，每一次交换两个相邻元素正好消去一个逆序对
//逆序对：对于下表i<j，如果A[i]>A[j]，则称(i,j)是一对逆序对(inversion)

/*
希尔排序(by Donald Shell)
*/
void Shell_sort(ElementType A[], int N) {
	int D, i,Tmp,P;
	for (D = N / 2; D > 0; D /= 2) { //希尔增量序列
		for (P = D; P < N; P++) {
			Tmp = A[P];
			for (i = P; i >= D && A[i - D] > Tmp; i -= D)
				A[i] = A[i - D];
			A[i] = Tmp;
		}
	}
}
/*
选择排序
*/
void Selection_Sort(ElementType A[], int N) {
	for (int i = 0; i < N; i++) {
		int MinPosition = SccanForMin(A, i, N - 1);//从A[i]到A[N-1]中找最小元
		Swap(A[i], A[MinPosition]);//将未排序部分的最小元换到有序部分的最后位置
	}
}
/*
堆排序
不好的方法
void Heap_Sort(ElementType A[], int N) {
	BuildHeap(A);
	int i;
	int *TmpA;
	for (i = 0; i < N; i++)
		TmpA[i] = DeleteMin(A);
	for (i = 0; i < N; i++)
		A[i] = TmpA[i];
}
*/
void Heap_Sort(ElementType A[], int N) {
	int i,N;
	for (i = N / 2; i >= 0; i--)//BuildHeap
		PercDown(A, i, N);//i对应结点位置，N对应当前堆有多少个元素
	for (i = N - 1; i > 0; i--) {
		Swap(&A[0], &A[i]);//DeleteMax
		PercDown(A, 0, i);
	}

}
/*
归并排序
*/
//L=左边起始位置，R=右边起始位置，RightEnd=右边终点位置
void  Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd) {
	int LeftEnd = R - 1;//左边重点位置，假设左右两列挨着
	int Tmp = L;//存放结果的数组的起始位置
	int i;
	int NumElements = RightEnd - L + 1;
	while (L <= LeftEnd && R <= RightEnd) {
		if (A[L] <= A[R]) TmpA[Tmp++] = A[L++];
		else TmpA[Tmp++] = A[R++];
	}
	while (L <= LeftEnd)
		TmpA[Tmp++] = A[L++];
	while (R <= LeftEnd)
		TmpA[Tmp++] = A[R++];
	for (i = 0; i < NumElements; i++, RightEnd--) {
		A[RightEnd] = TmpA[RightEnd];
	}
}


/*
递归算法
*/
//L指的是最Left的，RightEnd指的是最右边    稳定的算法
void MSort(ElementType A[], ElementType TmpA[], int L, int RightEnd) {
	int Center;//记录中间的位置
	if (L<RightEnd) {
		Center = (L + RightEnd) / 2;
		Msort(A,TmpA, L, Center);
		Msort(A, TmpA, Center+1, RightEnd);
		Merge(A, TmpA, L,Center+1,RightEnd);
	}
}
//递归统一函数接口
void Merge_sort(ElementType A[], int N) {
	ElementType* TmpA;
	TmpA = malloc(N * sizeof(ElementType));
	if (TmpA != NULL) {
		MSort(A, TmpA, 0, N - 1);
		free(TmpA);
	}
	else Error("空间不足");
}

/*
非递归算法
*/
void Merge_pass(ElementType A[], ElementType TmpA[], int N, int length) {//length=当前有序子列的长度
	int i,j;
	for (i = 0; i <= N - 2 * length; i += 2 * length)  //到剩下最后两个或一个length
		Merge1(A, TmpA, i, i + length, i + 2 * length - 1);//和Merge不同，最后有序的放到TmpA中
	if (i + length < N)//归并最后2个子列
		Merge1(A, TmpA, i, i + length, N - 1);
	else //只剩下一个子列
		for (j = i; j < N; j++)TmpA[j] = A[j];
}

//非递归统一接口  稳定的
void Merge_pass_sort(ElementType A[], int N) {
	int length = 1; //初始化子序列长度
	ElementType* TmpA;
	TmpA = malloc(N * sizeof(ElementType));
	if (TmpA != NULL) {
		while (length < N) {
			Merge_pass(A, TmpA, N, length);
			length *= 2;
			Merge_pass(TmpA, A, N, length);
			length *= 2;
		}
		free(TmpA);
	}
	else Error("空间不足");
}
/*
快速排序
*/
/*分而治之
void Quicksort(ElementType A[], int N) {
	if(N<2) return;
	pivot = 从A[]中选一个主元;
	将S = {A[]/pivot}分成两个独立子集;
	A1 = {a∈S|a<=pivot}和
	A2 = {a∈S|a>=pivot};
	a[] = Quicksort(A1,N1)∪
				{pivot}∪
		  Quicksort(A2,N2);
}
*/
//选主元
ElementType Median3(ElementType A[], int Left, int Right) {
	int Center = (Left + Right) / 2;
	if (A[Left] > A[Center])
		Swap(&A[Left], &A[Center]);
	if (A[Left] > A[Right])
		Swap(&A[Left], &A[Right]);
	if (A[Center] > A[Right])
		Swap(&A[Center], &A[Right]);
	Swap(&A[Center], &A[Right - 1]);
	return A[Right - 1];
}
//当递归的数据规模充分小，则停止递归，直接调用简单算法。
void Quicksort(ElementType A[], int Left, int Right) {
	int Cutoff;
	if (Cutoff <= Right - Left) {
	int Pivot = Median3(A, Left, Right);
	int i = Left;
	int j = Right - 1;
	for (;;) {
		while (A[++i] < Pivot) {}
		while (A[--i] > Pivot) {}
		if (i < j)
			Swap(&A[i], &A[j]);
		else break;
	}
	Swap(&A[i], &A[Right - 1]);
	Quicksort(A, Left, i - 1);
	Quicksort(A, i+1, Right);
	}
	Insertion_Sort(A + Left, Right - Left + 1);
}
void Quick_Sort(ElementType A[], int N) {
	Quicksort(A, 0, N - 1);
}

/*
桶排序
void BUcket_Sort(ElementType A[],int N){
	count[]初始化;
	while(读入一个学生成绩grade)
		将该生插入count[grade]链表;
	for(i=0;i<M;i++){
		if(count[i])
			输出整个count[i]链表;0
	}
}
基数排序
*/