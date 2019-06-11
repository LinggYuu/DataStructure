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
		return	Search(T->lchild, key);//有返回的有return
	}
	else
	{
		return	Search(T->rchild, key);
	}

}

void Insert(BSTree &T, ElemType e) //T前带&，希望函数返回后改变仍存在
{
	if (!T)
	{
		BSTree S = new BSTNode;
		S->Data = e;
		S->lchild = S->rchild = NULL;
		T = S;//S为新根
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

void InOrderTraverse(BSTree &T)//中序
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
	cout << "输入值,用回车区分,以#号结束 " << endl;
	CreateBST(T);
	cout << "中序遍历结果为:" << endl;
	InOrderTraverse(T);
	cout << endl;

	cout << "输入待查找的值" << endl;
	cin >> key;
	BSTree result = Search(T, key);

	while (!result)
	{
		cout << "没找到,重新输入" << endl;
		cin >> key;
		result = Search(T, key);
	}
	cout << "找到了" << key << endl;
	cout << "请输入待删除的字符" << endl;
	cin >> key;
	Delete(T,key);
	cout << "当前中序遍历结果为" << endl;
	InOrderTraverse(T);
	cin >> a;
}