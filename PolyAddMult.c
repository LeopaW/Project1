#include<stdio.h>
#include<stdlib.h>
/*
	����ʽ�ĳ˷���ӷ�
*/
typedef struct PolyNode* Polynomial;
struct PolyNode {
	int coef;
	int expon;
	Polynomial link;
};
void Attach(int c, int e, Polynomial* pRear);
void PrintPoly(Polynomial P);
Polynomial ReadPoly();
Polynomial Add(Polynomial P1, Polynomial P2);
Polynomial Mult(Polynomial P1, Polynomial P2);
/*int main() {
	printf("start");
	Polynomial P1, P2, PP, PS;
	//�������ʽ1
	P1 = ReadPoly();
	//�������ʽ2
	P2 = ReadPoly();
	//�˷����㲢���
	PP = Mult(P1, P2);
	PrintPoly(PP);
	//�ӷ����㲢���
	PS = Add(P1, P2);
	PrintPoly(PS);
	return 0;
}*/
Polynomial ReadPoly() {
	Polynomial P, Rear, t;
	int N,c,e;
	scanf_s("%d",&N);
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;
	while (N--) {
		scanf_s("%d %d",&c,&e);
		Attach(c,e,&Rear);
	}
	t = P;
	P = P->link;
	free(t);
	return P;
}



void Attach(int c, int e, Polynomial *pRear) {
	Polynomial P;

	P = (Polynomial)malloc(sizeof(struct PolyNode)); 
	P->coef = c;
	P->expon = e;
	P->link = NULL;
	(*pRear)->link = P;
	*pRear = P;
}

Polynomial Add(Polynomial P1, Polynomial P2) {
	Polynomial t1, t2,P,Rear,temp;
	int sum;
	t1 = P1;
	t2 = P2;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;
	while (t1 && t2) {
		if (t1->expon == t2->expon) {
			sum = t1->coef + t1->coef;
			if (sum != 0)Attach(sum, P1->coef, &Rear);
			t1 = P1->link;
			t2 = P2->link;
		}
		else if (t1->expon > t2->expon) {
			Attach(t1->coef, t1->expon, &Rear);
			t1 = t1->link;
		}
		else {
			Attach(t2->coef, t2->expon, &Rear);
			t2 = t2->link;
		}
	}
	while (t1) {
		Attach(t1->coef, t1->expon, &Rear);
		t1 = t1->link;
	}
	while (t2) {
		Attach(t2->coef, t2->expon, &Rear);
		t2 = t2->link;
	}
	temp = P;
	P = P->link;
	free(temp);
	return P;
}

Polynomial Mult(Polynomial P1, Polynomial P2) {
	Polynomial P, Rear, t1, t2, t;
	int c, e;

	if (!P1 || !P2)return NULL;

	t1 = P1;
	t2 = P2;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;
	while (t2) {		//����P1�ĵ�һ�����P2,�õ�P
		Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
		t2 = t2->link;
	}
	t1 = t1->link;
	while (t1) {
		t2 = P2;
		Rear = P;
		while (t2) {
			e = t1->expon + t2->expon;
			c = t1->coef * t2->coef;
			while (Rear->link && Rear->link->expon > e) {
				Rear = Rear->link;
			}
			if (Rear->link && Rear->link->expon == e) {
				if (Rear->link->coef + c != 0) {
					Rear->link->coef += c;
				}
				else {
					t = Rear->link;
					Rear->link = t->link;
					free(t);
				}
			}
			else {
				t = (Polynomial)malloc(sizeof(struct PolyNode));
				t->coef = c;
				t->expon = e;
				t->link = Rear->link;
				Rear->link = t;
				Rear = Rear->link;
			}
			t2 = t2->link;
		}
		t1 = t1->link;
	}
	t2 = P;
	P = P->link;
	free(t2);
	return P;
}

void PrintPoly(Polynomial P) {
	//�������ʽ
	int flag = 0;
	if (!P) {
		printf("0 0\n");
		return;
	}
	while (P) {
		if (!flag) {
			flag = 1;
		}
		else {
			printf(" ");
		}
		printf("%d %d", P->coef, P->expon);
		P = P->link;
	}
	printf("\n");
}

