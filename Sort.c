#include"all.h"
/*
ð������
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
��������
*/
void Insertion_Sort(ElementType A[], int N) {
	int P,i;
	for (P = 1; P < N; P++) {
		int Tmp = A[P]; //ȡ����һ����
		for (i = P; i > 0 && A[i - 1] > Tmp; i--) {
			A[i] = A[i - 1];//�ҵ���TmpС����һλ
		}
		A[i] = Tmp;//i-1��tmpС������i��������λ��
	}
}
//���������ð�������Ǽ�����ÿһ�ν�����������Ԫ��������ȥһ�������
//����ԣ������±�i<j�����A[i]>A[j]�����(i,j)��һ�������(inversion)

/*
ϣ������(by Donald Shell)
*/
void Shell_sort(ElementType A[], int N) {
	int D, i,Tmp,P;
	for (D = N / 2; D > 0; D /= 2) { //ϣ����������
		for (P = D; P < N; P++) {
			Tmp = A[P];
			for (i = P; i >= D && A[i - D] > Tmp; i -= D)
				A[i] = A[i - D];
			A[i] = Tmp;
		}
	}
}
/*
ѡ������
*/
void Selection_Sort(ElementType A[], int N) {
	for (int i = 0; i < N; i++) {
		int MinPosition = SccanForMin(A, i, N - 1);//��A[i]��A[N-1]������СԪ
		Swap(A[i], A[MinPosition]);//��δ���򲿷ֵ���СԪ�������򲿷ֵ����λ��
	}
}
/*
������
���õķ���
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
		PercDown(A, i, N);//i��Ӧ���λ�ã�N��Ӧ��ǰ���ж��ٸ�Ԫ��
	for (i = N - 1; i > 0; i--) {
		Swap(&A[0], &A[i]);//DeleteMax
		PercDown(A, 0, i);
	}

}
/*
�鲢����
*/
//L=�����ʼλ�ã�R=�ұ���ʼλ�ã�RightEnd=�ұ��յ�λ��
void  Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd) {
	int LeftEnd = R - 1;//����ص�λ�ã������������а���
	int Tmp = L;//��Ž�����������ʼλ��
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
�ݹ��㷨
*/
//Lָ������Left�ģ�RightEndָ�������ұ�    �ȶ����㷨
void MSort(ElementType A[], ElementType TmpA[], int L, int RightEnd) {
	int Center;//��¼�м��λ��
	if (L<RightEnd) {
		Center = (L + RightEnd) / 2;
		Msort(A,TmpA, L, Center);
		Msort(A, TmpA, Center+1, RightEnd);
		Merge(A, TmpA, L,Center+1,RightEnd);
	}
}
//�ݹ�ͳһ�����ӿ�
void Merge_sort(ElementType A[], int N) {
	ElementType* TmpA;
	TmpA = malloc(N * sizeof(ElementType));
	if (TmpA != NULL) {
		MSort(A, TmpA, 0, N - 1);
		free(TmpA);
	}
	else Error("�ռ䲻��");
}

/*
�ǵݹ��㷨
*/
void Merge_pass(ElementType A[], ElementType TmpA[], int N, int length) {//length=��ǰ�������еĳ���
	int i,j;
	for (i = 0; i <= N - 2 * length; i += 2 * length)  //��ʣ�����������һ��length
		Merge1(A, TmpA, i, i + length, i + 2 * length - 1);//��Merge��ͬ���������ķŵ�TmpA��
	if (i + length < N)//�鲢���2������
		Merge1(A, TmpA, i, i + length, N - 1);
	else //ֻʣ��һ������
		for (j = i; j < N; j++)TmpA[j] = A[j];
}

//�ǵݹ�ͳһ�ӿ�  �ȶ���
void Merge_pass_sort(ElementType A[], int N) {
	int length = 1; //��ʼ�������г���
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
	else Error("�ռ䲻��");
}
/*
��������
*/
/*�ֶ���֮
void Quicksort(ElementType A[], int N) {
	if(N<2) return;
	pivot = ��A[]��ѡһ����Ԫ;
	��S = {A[]/pivot}�ֳ����������Ӽ�;
	A1 = {a��S|a<=pivot}��
	A2 = {a��S|a>=pivot};
	a[] = Quicksort(A1,N1)��
				{pivot}��
		  Quicksort(A2,N2);
}
*/
//ѡ��Ԫ
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
//���ݹ�����ݹ�ģ���С����ֹͣ�ݹ飬ֱ�ӵ��ü��㷨��
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
Ͱ����
void BUcket_Sort(ElementType A[],int N){
	count[]��ʼ��;
	while(����һ��ѧ���ɼ�grade)
		����������count[grade]����;
	for(i=0;i<M;i++){
		if(count[i])
			�������count[i]����;0
	}
}
��������
*/