//线性表链式存储实现
//不要求逻辑上相邻的两个元素物理上也相邻 ；通过链建立起数据元素之间的逻辑关系
//插入删除不需要移动数据元素，只需要修改链
#include<stdio.h>
#define ElementType int
typedef struct LNode *List;
struct LNode
{
	ElementType Data;
	List Next;
};

struct LNode L;
List Ptrl;      //引用方式

//求表长
int Length(List Ptrl)
{
	List p = Ptrl;//p指向表的第一个节点,(di 0 ge)
	int j = 0;
	//List p=Ptrl->Next;
	//int j=1;
	while (p)
	{
		p = p->Next;
		j++;   //当前p指向的是第j个节点
	}
	return j;//头节点也算一个应该
}//时间性能O(n)

//查找
//(1)按序号查找 第K个
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
//(2)按值查找
List Find(ElementType X, List Ptrl)
{
	List p = Ptrl;
	while (p != NULL && p->Data != X)
		p = p->Next;
	return p;
}//时间性能O(n)

//插入(在第i-1(1<=i<=n+1)个结点后插入一个值为X的新结点)
//构造新结点，s指向
//找到链表的第i-1个结点，用p指向
//修改指针，插入结点(p之后插入新结点是s)

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
	p = FindKth(i - 1, Ptrl);		//找第i-1个结点
	if (p == NULL)
	{
		printf("参数错");
		return NULL;
	}
	else
	{
		s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = p->Next;	//插在第i-1个结点的后面
		p->Next = s;
		return Ptrl;
	}

}

//删除(删除链表的第i(1<=i<=n)个位置上的结点)
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
			printf("%d个结点不存在",i - 1);	return NULL;
		}
	else if (p->Next = NULL)
	{
		printf("%d个结点不存在", i);		return NULL;
	}
	else
	{
		s = p->Next;
			p->Next = s->Next;
		free(s);
		return Ptrl;
	}

}