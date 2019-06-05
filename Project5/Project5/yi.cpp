#include<stdio.h>
#include<stdlib.h>

typedef  int ElementType;//可以是任意类型 


//void X_Sort(ElementType A[], int N) 


//前提
//大多数情况，讨论从小到大整数排序
//N是正整数
//只讨论基于比较的排序(<>=有定义)
//只讨论内部排序
//稳定性:任意两个相等的数据，排序前后的相对位置不发生改变
//没有一种排序是任何情况下都表现最好的





//冒泡排序

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
		if (flag == 0) { break; }//未做交换时，直接跳出了
	}

}






//插入排序
void Insertion_Sort(ElementType A[], int N)
{	
	int i, P,Tmp;
	for (P = 1; P < N; P++) 
	{
		Tmp = A[P];//把值拿到手中
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

//时间复杂度下界
//对于下标i < j, 如果A[i]>A[j],则称(i,j)是一对nixudui(inversion)
//问题:序列{34,8,64,51,32,21}中有多少逆序对？
//	(34,8)(34,21)(64,51)(64,32)(64,21)(51,32)(51,21)(32,21)
//	9个
//	就是冒泡或插入排序的交换次数
	//交换2个相邻元素正好消去1个逆序对

//若果序列基本有序，则插入排序简单高效 


//定理:任意N个不同元素组成的序列平均具有N(N-1)/4个逆序对

//定理:任何仅以交换相邻两元素来排序的算法，其平均时间复杂度为Ω(N^2)





//希尔排序

5间隔