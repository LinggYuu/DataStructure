//����
//Queue������һ������Լ�������Ա�
//�����ɾ��������ֻ����һ�˲��룬������һ��ɾ��
//���ݲ��룺�����(AddQ)
//����ɾ����������(DeleteQ)
//�Ƚ��ȳ�(FIFO)

//����ΪMaxSize�Ķ���Q��Queue������Ԫ��item��ElementType


//˳��洢ʵ��
//���е�˳��洢 ��һ��һά�����һ����¼����ͷԪ��λ�õı���front
//�Լ���¼����βԪ��λ�õı���rear���



#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
#define ERROR -2
#define MaxSize 100000 //�洢����Ԫ�ص�������
struct QNode 
{
	ElementType Data[MaxSize];
	int rear;
	int front;
};
typedef struct QNode *Queue;


//ѭ������

//�����

//void AddQ(Queue Ptrq, ElementType item)
//{
//	if ((Ptrq->rear + 1) % MaxSize == Ptrq->front)
//	{
//		printf("������");
//		return;
//	}
//	Ptrq->rear = (Ptrq->rear + 1) % MaxSize;
//	Ptrq->Data[Ptrq->rear] = item;
//}
//
////������
//ElementType DeleteQ(Queue Ptrq)
//{
//	if (Ptrq->front == Ptrq->rear)
//	{
//		printf("���п�");
//		return ERROR;
//	}
//	else
//	{
//		Ptrq->front = (Ptrq->front + 1) % MaxSize;
//		return Ptrq->Data[Ptrq->front];
//	}
//}



//������ʽ�洢ʵ��

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



//����ͷ������ʽ���г��Ӳ���

ElementType DeleteQ(Queue PtrQ)
{
	struct Node *FrontCell;
	ElementType FrontElem;

	if (PtrQ->front == NULL)
	{
		printf("���п�");
		return ERROR;
	}
	FrontCell = PtrQ->front;
	if (PtrQ->front == PtrQ->rear)
		PtrQ->front = PtrQ->rear = NULL;//��ֻ��һ��Ԫ��ʱ��ɾ�������λ��Ϊ��
	else
		PtrQ->front = PtrQ->front->Next;
	FrontElem = FrontCell->Data;
	free(FrontCell);//�ͷű�ɾ�����ռ�
	return FrontElem;

}

