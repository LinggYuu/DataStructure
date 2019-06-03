//队列
//Queue：具有一定操作约束的线性表
//插入和删除操作：只能在一端插入，而在另一端删除
//数据插入：入队列(AddQ)
//数据删除：出队列(DeleteQ)
//先进先出(FIFO)

//长度为MaxSize的队列Q∈Queue，队列元素item∈ElementType


//顺序存储实现
//队列的顺序存储 由一个一维数组和一个记录队列头元素位置的变量front
//以及记录队列尾元素位置的变量rear组成



#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
#define ERROR -2
#define MaxSize 100000 //存储数据元素的最大个数
struct QNode 
{
	ElementType Data[MaxSize];
	int rear;
	int front;
};
typedef struct QNode *Queue;


//循环队列

//入队列

//void AddQ(Queue Ptrq, ElementType item)
//{
//	if ((Ptrq->rear + 1) % MaxSize == Ptrq->front)
//	{
//		printf("队列满");
//		return;
//	}
//	Ptrq->rear = (Ptrq->rear + 1) % MaxSize;
//	Ptrq->Data[Ptrq->rear] = item;
//}
//
////出队列
//ElementType DeleteQ(Queue Ptrq)
//{
//	if (Ptrq->front == Ptrq->rear)
//	{
//		printf("队列空");
//		return ERROR;
//	}
//	else
//	{
//		Ptrq->front = (Ptrq->front + 1) % MaxSize;
//		return Ptrq->Data[Ptrq->front];
//	}
//}



//队列链式存储实现

struct Node 
{
	ElementType Data;
	struct Node *Next;
};
struct QNode 
{
	struct Node *rear;
	struct Node *front;
};
typedef struct QNode *Queue;
Queue PtrQ;



//不带头结点的链式队列出队操作

ElementType DeleteQ(Queue PtrQ)
{
	struct Node *FrontCell;
	ElementType FrontElem;

	if (PtrQ->front == NULL)
	{
		printf("队列空");
		return ERROR;
	}
	FrontCell = PtrQ->front;
	if (PtrQ->front == PtrQ->rear)
		PtrQ->front = PtrQ->rear = NULL;//当只有一个元素时，删除后队列位置为空
	else
		PtrQ->front = PtrQ->front->Next;
	FrontElem = FrontCell->Data;
	free(FrontCell);//释放被删除结点空间
	return FrontElem;

}

