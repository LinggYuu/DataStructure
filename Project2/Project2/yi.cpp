//��ջ
//�������ʽ5+6/2-3*4
//5+6/2-3*4=5+3-3*4=8-3*4=8-12=-4
//��������󹹳ɵ�
//����������2��3��4
//������ţ��磫-*/
//��ͬ������������ȼ���һ��

//��׺���ʽ���������λ������������֮�䡣��a+b*c-d/e
//��׺���ʽ���������λ������������֮����abc*+de/-
//62/3-42*+ =?
//62/=3
//33-=0
//42*=8
//08+=8
//����6������2
//����/������3
//����-������4
//����2������*
//����+��Pop8  
//T(N)=O(N)

//��ջ�ĳ���������������
//��ջ(stack):����һ������Լ�������Ա�
//ֻ��һ��(ջ����Top)�����롢ɾ��
//�������ݣ���ջ(Push)
//ɾ�����ݣ���ջ(Pop)
//�����ȳ���Last In First Out(LIFO)

//��������Stack
//���ݶ��󼯣�һ����0������Ԫ�ص��������Ա�
//������������ΪMaxSize�Ķ�ջS��Stack����ջԪ��item��ElementType
//Push Pop���Դ��彻����У�


//ջ��˳��洢ʵ��
//ջ��˳��洢�ṹͨ����һ��һά�����һ����¼ջ��Ԫ��λ�õı�����ɡ�
#include<stdio.h>
#define MaxSize	100	//<��������Ԫ�ص�������><��������һ��λ�ã�MaxSize-1>
#define ElementType int
#define ERROR -2
typedef struct SNode *Stack;
struct SNode 
{
	ElementType Data[MaxSize];
	int Top;
};

//��ջ
void Push(Stack PtrS, ElementType item)
{
	if (PtrS->Top == MaxSize - 1) 
	{
		printf("��ջ��");
		return;
	}
	else 
	{	
		PtrS->Top++;
		PtrS->Data[PtrS->Top] = item;
		return;
	}
}

//��ջ
ElementType  Pop(Stack PtrS)
{
	if (PtrS->Top == -1)//-1�����
	{
		printf("��ջ�� ");
		return ERROR;
	}
	else
	{
		return(PtrS->Data[PtrS->Top]);
		PtrS->Top--;
	}
}  
//�����������ռ�
//����ʹ����ջ�ֱ��������ͷ��ʼ���м�������������ջ��ջ��ָ������ʱ����ʾ����ջ�����ˡ�

struct DStack 
{
	ElementType Data[MaxSize];
	int Top1;//��ջ1��ջ��ָ��
	int Top2;//��ջ2��ջ��ָ�� 
}S;
//S.Top1 = -1;
//S.Top2 = MaxSize;

void Push(struct DStack  *PtrS, ElementType item, int Tag)
{
	if (PtrS->Top2 - PtrS->Top1 == 1)
	{
		printf("��ջ��");
		return;
	}
	if (Tag == 1)//�Ե�һ����ջ���в���
	{
		PtrS->Data[++(PtrS->Top1)] = item;
	}
	else //�Եڶ�����ջ���в���
	{
		PtrS->Data[--(PtrS->Top2)] = item;
	}
}

ElementType Pop(struct DStack *PtrS, int Tag)
{
	if (Tag == 1)
	{
		if (PtrS->Top1 == -1)
		{
			printf("��ջ1��");
			return  NULL;
		}
		else
		{
			return PtrS->Data[(PtrS->Top1)--];
		}
	}
	else
	{
		if (PtrS->Top2 == MaxSize) 
		{
			printf("��ջ2�� ");
			return NULL;
		}
		else
		{
			return PtrS->Data[(PtrS->Top2)++];
		}
	}
}