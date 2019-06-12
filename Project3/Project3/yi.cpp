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
//�����������ĺ�������:��ά��������Ի�
//�ӽ����������Ҷ��ӽ��
//��������Ӻ��Ҷ��ӽ����δ���
//	��Ҫһ���洢�ṹ������ʱ�����ʵĽ��
//	�洢�ṹ:ջ������


//����ʵ��:
//�����Ӹ���㿪ʼ�����Ƚ��������ӣ�Ȼ��ʼִ��ѭ��:
//	�����ӡ����ʸý�㡢�����Ҷ������

void LevelOrderTraversal(BinTree BT) 
{
	Queue Q;
	BinTree T;
	if (!BT)
		return;
	Q = CreatQueue(Maxsize);
	AddQ(Q, BT);
	while (!IsEmptyQ(Q)) 
	{
		T = DeleteQ(Q);
		printf("%d\n", T->Data);
		if (T->Left)
			AddQ(Q, T->Left);
		if (T->Right)
			AddQ(Q, T->Right);
	}
}






����������
���ҴӸ���㿪ʼ�������Ϊ�գ�����NULL
���������ǿգ�������ؼ��ֺ�X���бȽϣ������в�ͬ����
	��XС�ڸ�����ֵ��ֻ��Ҫ�������м�������
	��X���ڸ����ļ�ֵ�����������н��м�������
	�����߱ȽϽ����ȣ�������ɣ�����ָ��˽���ָ��

Position Find(ElementType X, Bin BST)
{
	if (!BST)
		return NULL;
	if (X > BST->Data)
		return Find(X, BST->rchild);
	else if (X < BST->Data)
	{
		return Find(X, BST->lchild);
	}
	else
		return BST;
}

�ǵݹ�
Position IFind(ElementType X, BinTree BST) 
{
	while (BST) 
	{
		if (X > BST->Data)
			BST = BST->rchild;
		else if (X < BST->Data)
			BST = BST->lchild;
		else
			return BST;
	}
	return NULL;
}


//�����ֵ
Position FindMax(BinTree) 
{
	if (!BST)
		return NULL;
	else if (!BST->rchild)
		return BST;
	else
		return FindMax(BST->rchild);
}

Position FindMAX(BinTree BST)
{
	if (BST) 
	{
		while (BST->rchild)
		{
			BST = BST->rchild;
		}
	}
}



�����������Ĳ���

BinTree Insert(ElementType X, BinTree BST) 
{
	if (!BST) 
	{
		BST = malloc(sizeof(struct TreeNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else if (X < BST->Data) 
	{
		return Insert(X, BST->Left);
	}
	else if (X > BST->Data) 
	{
		return Insert(X, BST->Right);
	}
	return BST;

}



������������ɾ��

1.Ҫɾ������Ҷ���:
ֱ��ɾ���������޸��丸���ָ��---��ΪNULL

2.Ҫɾ���Ľ����һ������:
	���丸����ָ��ָ��Ҫɾ�����ĺ��ӽ��

3.Ҫɾ���Ľ����������������:
	����һ����������ɾ�����:����������СԪ�ػ������������Ԫ��

BinTree Delete(ElementType X, BinTree BST)//����BST��ɾ��X
{
	Position Tmp;
	if (!BST)
	{
		printf("Ҫɾ����Ԫ��δ�ҵ�");
	}
	else if (X < BST->Data)
	{
		BST->Left = Delete(X, BST->Left);//����������ɾ��X��Ȼ������������
	}
	else if (X > BST->Data)
	{
		BST->Right = Delete(X, BST->Right);
	}
	else if (BST->Left && BST->Right)
	{
		Tmp = FindMin(BST->Right);
		BST->Data = Tmp->Data;
		BST->Right = Delete(BST->Data, BST->Right);
	}
	else
	{
		Tmp = BST;
		if(!BST->Left)
			BST = BST->Right;
		else if (!BST->Right)
			BST = BST->Left;
		free(Tmp);
	}
	return BST;

}