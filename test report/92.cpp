#include<iostream>
using namespace std;

typedef struct ElemType
{
	char key;

}ElemType;

typedef struct BSTNode
{
	ElemType Data;
	BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

BSTree Search(BSTree T, char key)
{
	if ((!T) || key == T->Data.key)
	{
		return T;
	}
	else if (T->Data.key > key)
	{
		return	Search(T->lchild, key);//�з��ص���return
	}
	else
	{
		return	Search(T->rchild, key);
	}

}

void Insert(BSTree &T, ElemType e) //Tǰ��&��ϣ���������غ�ı��Դ���
{
	if (!T)
	{
		BSTree S = new BSTNode;
		S->Data = e;
		S->lchild = S->rchild = NULL;
		T = S;//SΪ�¸�
	}
	else if (e.key < T->Data.key)
	{
		Insert(T->lchild, e);
	}
	else
	{
		Insert(T->rchild, e);
	}
}

void CreateBST(BSTree &T)
{
	T = NULL;
	ElemType e;
	cin >> e.key;
	while (e.key != '#')
	{
		Insert(T, e);
		cin >> e.key;
	}
}


void Delete(BSTree &T, char key)
{
	BSTree p = T;
	BSTree f = NULL;
	BSTree q= NULL;
	BSTree s;

	while (p)
	{
		if (p->Data.key == key)
		{
			break;
		}
		f = p;
		if (p->Data.key > key)
		{
			p = p->rchild;
		}
		else
		{
			p = p->rchild;
		}
	}
	if (!p)
		return;

	if ((p->lchild) && (p->rchild))
	{
		q = p;
		s = p->lchild;
		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		p->Data = s->Data;
		if (q != p)
		{
			q->rchild = s->lchild;
		}
		else
			q->lchild = s->lchild;
		delete s;
	}
	else
	{
		if (!p->rchild)
		{
			q = p;
			p = p->lchild;
		}
		else if (!p->lchild)
		{
			q = p;
			p = p->rchild;
		}

		if (!f)
			T = p;
		else if (q == f->lchild)
			f->lchild = p;
		else
			f->rchild = p;
		delete q;
	}
}

void InOrderTraverse(BSTree &T)//����
{
	if (T)
	{
		InOrderTraverse(T->lchild);
		cout << T->Data.key;
		InOrderTraverse(T->rchild);
	}
}

int main()
{
	int a;
	BSTree T;
	char key;
	cout << "����ֵ,�ûس�����,��#�Ž��� " << endl;
	CreateBST(T);
	cout << "����������Ϊ:" << endl;
	InOrderTraverse(T);
	cout << endl;

	cout << "��������ҵ�ֵ" << endl;
	cin >> key;
	BSTree result = Search(T, key);

	while (!result)
	{
		cout << "û�ҵ�,��������" << endl;
		cin >> key;
		result = Search(T, key);
	}
	cout << "�ҵ���" << key << endl;
	cout << "�������ɾ�����ַ�" << endl;
	cin >> key;
	Delete(T,key);
	cout << "��ǰ����������Ϊ" << endl;
	InOrderTraverse(T);
	cin >> a;
}