#include<stdio.h>
#include<stdlib.h>

typedef  int ElementType;//�������������� 


//void X_Sort(ElementType A[], int N) 


//ǰ��
//�������������۴�С������������
//N��������
//ֻ���ۻ��ڱȽϵ�����(<>=�ж���)
//ֻ�����ڲ�����
//�ȶ���:����������ȵ����ݣ�����ǰ������λ�ò������ı�
//û��һ���������κ�����¶�������õ�





//ð������

void swap(ElementType a[], int i, int j) 
{

}
void Bubble_Sort(ElementType A[], int N)
{
	int i, j, flag;
	for (i = N - 1; i > 0; i--) 
	{
		flag = 0;
		for (j = 0; j < i; j++) 
		{
			if (A[j] > A[j + 1])
			{
				swap(A, i, j);
				flag = 1;
			}
		}
		if (flag == 0) { break; }//δ������ʱ��ֱ��������
	}

}






//��������
void Insertion_Sort(ElementType A[], int N)
{	
	int i, P,Tmp;
	for (P = 1; P < N; P++) 
	{
		Tmp = A[P];//��ֵ�õ�����
		for (i = P; i > 0; i--)
		{
			if (A[i - 1] > Tmp) 
			{
				A[i] = A[i - 1];
			}
		}
		A[i] = Tmp;
	}

}

//ʱ�临�Ӷ��½�
//�����±�i < j, ���A[i]>A[j],���(i,j)��һ��nixudui(inversion)
//����:����{34,8,64,51,32,21}���ж�������ԣ�
//	(34,8)(34,21)(64,51)(64,32)(64,21)(51,32)(51,21)(32,21)
//	9��
//	����ð�ݻ��������Ľ�������
	//����2������Ԫ��������ȥ1�������

//�������л����������������򵥸�Ч 


//����:����N����ͬԪ����ɵ�����ƽ������N(N-1)/4�������

//����:�κν��Խ���������Ԫ����������㷨����ƽ��ʱ�临�Ӷ�Ϊ��(N^2)





//ϣ������

//81 94 11 96 12 35 17 95 28 58 41 75 15
//
//5���
//81 35 41--35 41 81
//94 17 75--17 75 94
//11 95 15--11 15 95
//96 28 -- 28 96
//12 58 -- 12 58
//35 17 11 28  12 41 75 15 96 58 81 94 95
//
//3���
//28 12 11 35 15 41 58 17 94 75 81 96 95
//
//1���
//11 12 15 17 28 35 41 58 75 81 94 95 96
//
//������������DM>D(M-1)>...>D1=1
//��ÿ��Dk����Dk-������� (k=M,M-1 ,...1)
//
//����һ�μ������ʱ�������һ�ε��������
//
//DM=ȡ��(N/2),
//DK=ȡ��(D(k+1)/2)

void shell_sort(ElementType A[], int N) 
{
	int D, i,Tmp,P;
	for (D = N / 2; D > 0; D /= 2) 
	{
		for (P = D; P < N; P++) 
		{
			Tmp = A[P];
			for (i = P; i >= D; i = i - D)
			{
				if (A[i - D] > Tmp)
				{
					A[i] = A[i - D];
				}
			}
			A[i] = Tmp;
		}
	
	
	
	}


}

//Hibbard�������л����һ��
//Dk=2^k -1






//ѡ������
void Selection_sort(ElementType A[], int N) 
{
	int i,minpos,j;
	for (i = 0; i < N-1; i++) 
	{
		minpos = i;
		for (j = i + 1; j < N; j++) 
		{
			if (A[j] < A[minpos]) 
			{
				minpos = j;
			}
		}
		A[i] = A[minpos];
	
	}


}


//������ ---ѡ������ĸĽ�



void BuildHeap(ElementType A[]) {}

//�㷨1

void Heap_sort(ElementType A[], int N) 
{
	BuildHeap(A);//��һ���������һ����С��
	for (int i = 0; i < N; i++) 
	{
		TmpA[i] = DeleteMin[A];
	}
	for (int i = 0; i < N; i++) 
	{
		A[i] = TmpA[i];
	}
	
}


//�㷨2
void Heap_Sort(ElementType A[], int N)
{
	for (i = N / 2; i >= 0; i--) 
	{
		PercDown(A, i, N);
	}
	for (i = N - 1; i > 0; i--) 
	{
		swap(A, 0, i);
		PercDown(A, 0, i);
	}
}