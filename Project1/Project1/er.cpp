//���Ա���ʽ�洢ʵ��
//��Ҫ���߼������ڵ�����Ԫ��������Ҳ���� ��ͨ��������������Ԫ��֮����߼���ϵ
//����ɾ������Ҫ�ƶ�����Ԫ�أ�ֻ��Ҫ�޸���
#include<stdio.h>
#define ElementType int
typedef struct LNode *List;
struct LNode
{
	ElementType Data;
	List Next;
};

struct LNode L;
List Ptrl;      //���÷�ʽ

//���
int Length(List Ptrl)
{
	List p = Ptrl;//pָ���ĵ�һ���ڵ�,(di 0 ge)
	int j = 0;
	//List p=Ptrl->Next;
	//int j=1;
	while (p)
	{
		p = p->Next;
		j++;   //��ǰpָ����ǵ�j���ڵ�
	}
	return j;//ͷ�ڵ�Ҳ��һ��Ӧ��
}//ʱ������O(n)

//����
//(1)����Ų��� ��K��
List FindKth(int K, List Ptrl)
{
	List p = Ptrl->Next;
	int i = 1;
	while (p != NULL && i < K)
	{
		p = p->Next;
		i++;
	}
	if (i == K)return p;
	else return NULL;
}
//(2)��ֵ����
List Find(ElementType X, List Ptrl)
{
	List p = Ptrl;
	while (p != NULL && p->Data != X)
		p = p->Next;
	return p;
}//ʱ������O(n)

//����(�ڵ�i-1(1<=i<=n+1)���������һ��ֵΪX���½��)
//�����½�㣬sָ��
//�ҵ�����ĵ�i-1����㣬��pָ��
//�޸�ָ�룬������(p֮������½����s)

List Insert(ElementType X, List Ptrl)
{	
	List p, s;
	if ( i == 1)
	{
		s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = Ptrl;
		return s;
	}
	p = FindKth(i - 1, Ptrl);		//�ҵ�i-1�����
	if (p == NULL)
	{
		printf("������");
		return NULL;
	}
	else
	{
		s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = p->Next;	//���ڵ�i-1�����ĺ���
		p->Next = s;
		return Ptrl;
	}

}

//ɾ��(ɾ������ĵ�i(1<=i<=n)��λ���ϵĽ��)
List Delete(int i, List Ptrl)
{
	List p, s;
	if (i == 1)
	{
		s = Ptrl;
		if (Ptrl != NULL) Ptrl = Ptrl->Next;
		else return NULL;
		free(s);
		return Ptrl;
	}
	p = FindKth(i - 1, Ptrl);
	if (p = NULL)
		{
			printf("%d����㲻����",i - 1);	return NULL;
		}
	else if (p->Next = NULL)
	{
		printf("%d����㲻����", i);		return NULL;
	}
	else
	{
		s = p->Next;
			p->Next = s->Next;
		free(s);
		return Ptrl;
	}

}