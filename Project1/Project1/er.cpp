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