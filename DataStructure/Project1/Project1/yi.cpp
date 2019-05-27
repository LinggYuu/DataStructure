#include <stdio.h>
#define ElementType int
#define MAXSIZE 1000
//���Ա�˳��洢ʵ��

typedef struct LNode *List;
struct LNode {
	ElementType Data[MAXSIZE];
	int Last;

};

struct LNode L;
List Ptrl;
//�����±�Ϊi��Ԫ�أ�L.Data[i]�� Ptrl->Data[i]
//���Ա�ĳ��ȣ�L.last+1��Ptrl->Last+1


//��ʼ��
List MakeEmpty()
{
	List Ptrl;
	Ptrl = (List) malloc (sizeof(struct LNode));
	Ptrl->Last = -1;
	return Ptrl;

}

//����,ƽ���Ƚϴ���Ϊ(n+1)/2��ƽ��ʱ������ΪO(n)
int Find(ElementType X, List  Ptrl)
{
	int i = 0;
	while (i <= Ptrl->Last && Ptrl->Data[i] != X)
		i++;
	if (i > Ptrl->Last)
		return  -1;//û�ҵ�����-1
	else return i;//�ҵ����ص��Ǵ洢λ��

}

//�������
void Insert(ElementType X, int i, List Ptrl)
{
	int i, j;
	if (Ptrl->Last == MAXSIZE - 1) 
	{
		printf("man");
		return;
	}
	if (i < 1 || Ptrl->Last + 2) 
	{
		printf("weizhi bu he fa");
		return;
	}
	for (j = Ptrl->Last; j >= i - 1; j--) 
	{
		Ptrl->Data[j + 1] = Ptrl->Data[j];//��ai��an��������ƶ�
	}
	Ptrl->Data[i - 1] = X;//��Ԫ�ز���
	Ptrl->Last++;//Last��ָ�����Ԫ��
	return;
}