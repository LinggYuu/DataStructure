//��
//
//n����㹹�ɵ����޼���
//n=0ʱ����Ϊ����
//������һ�÷ǿ���(n>0),���߱�����
//������һ���и�root������ڵ���r��ʾ
//������ɷ�Ϊm(m>0)�������ཻ�����޼�T1,T2...Tm
//����ÿ�����ϱ�������һ��������Ϊԭ����������(SubTree)
//
//
//�������ཻ
//��������⣬ÿ���ڵ����ҽ���һ�����ڵ�
//һ��N����������N-1����


//���ı�ʾ

//�����ֵܱ�ʾ��





//������
//����������֮��
//������T:һ������Ľ�㼯��
//	������Ͽ���Ϊ��
//	����Ϊ�գ������ɸ��ڵ�ͳ�Ϊ��������TL��������TR���������ཻ 
//	�Ķ��������
//�����ֻ�����̬  


//һ����������i����������Ϊ2^(i-1), i>=1
//���Ϊk�Ķ����� �� ����ܽ����Ϊ��2^k -1,k>=1


//���κηǿն�����T,��n0��ʾҶ���ĸ��� ��n2�Ƕ�Ϊ2�ķ�Ҷ��������
//��ô���������ϵn0=n2+1



//����----������������������
//����----������������������ 
//����----������������������
//���----���ϵ��£�������


//�������Ĵ洢�ṹ

//˳��洢�ṹ


//��ȫ�����������������£���������˳��洢n������
//��ȫ�������Ľ�㸸�ӹ�ϵ
//�Ǹ����(���i>1)�ĸ����������  ȡ��(i/2)
//���(���Ϊi)�����ӽ��������2i(2i<=n,����û������)
//���(���Ϊi)���Һ��ӽ��������2i+1(2i+1 <= n, ����û���Һ���)

//һ�������
//Ҳ���Բ������ֽṹ��������ɿռ��˷�



//����洢
#include<stdio.h>
#include<stdlib.h>
#define ElementType int
typedef struct TreeNode *BinTree;//�ṹָ��
typedef BinTree Position;
struct TreeNode 
{
	ElementType Data;
	BinTree Left;
	BinTree	Right;
};


//�������
//���̣�
//	���� �����
//	���������������
//	���������������
//�б���

void PreOrderTraversal(BinTree BT)
{
	if (BT) 
	{
		printf("%d", BT->Data);
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
	}
}


//����
void InOrderTraversal(BinTree BT)
{
	if (BT)
	{
		InOrderTraversal(BT->Left);
		printf("%d", BT->Data);
		InOrderTraversal(BT->Right);
	}
}


//����
void PostOrderTraversal(BinTree BT)
{
	if (BT)
	{
		PostOrderTraversal(BT->Left);
		printf("%d", BT->Data);
		PostOrderTraversal(BT->Right);
	}
}

//�������ǵݹ����
//��������ǵݹ�����㷨
//����˼·����ջ
//
//����һ����㣬�Ͱ���ѹջ����ȥ������ ��������
//�����������������󣬴�ջ�����������㲢������
//Ȼ�� �� ����ָ����ȥ��������ý���������
void InOrderTraversal(BinTree BT)
{
	BinTree T = BT;
	Stack S = CreateStack(MaxSize);//��������ʼ����ջS
	while (T || !IsEmpty(S)) 
	{
		while (T)//һֱ���󲢽���;���ѹ��ջ
		{
			Push(S, T);//�����ջ
			T = T->Left;
		}
		if (!IsEmpty(S)) 
		{
			T = Pop(S);//����ջ
			printf("%d", T->Data);//���ʣ���ӡ�����
			T = T->Right;//ת��������
		}
	}

}

//��������ǵݹ�(·����������һ����)


//��printf�ŵ�Pushǰ


 
//�������



δ�����