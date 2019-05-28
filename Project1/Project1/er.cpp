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