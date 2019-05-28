#include <stdio.h>
#define ElementType int
#define MAXSIZE 1000
//线性表顺序存储实现

typedef struct LNode *List;
struct LNode {
	ElementType Data[MAXSIZE];
	int Last;

};

struct LNode L;
List Ptrl;
//访问下标为i的元素：L.Data[i]或 Ptrl->Data[i]
//线性表的长度：L.last+1或Ptrl->Last+1


//初始化
List MakeEmpty()
{
	List Ptrl;
	Ptrl = (List)malloc(sizeof(struct LNode));
	Ptrl->Last = -1;
	return Ptrl;

}

//查找,平均比较次数为(n+1)/2，平均时间性能为O(n)
int Find(ElementType X, List  Ptrl)
{
	int i = 0;
	while (i <= Ptrl->Last && Ptrl->Data[i] != X)
		i++;
	if (i > Ptrl->Last)
		return  -1;//没找到返回-1
	else return i;//找到返回的是存储位置

}

//插入操作(第i（1<=i<=n+1）个位置上插入一个值为X的新元素)
void Insert(ElementType X, int i, List Ptrl)
{
	int i, j;
	if (Ptrl->Last == MAXSIZE - 1)
	{
		printf("man");
		return;
	}
	if (i < 1 || i > Ptrl->Last + 2)// 可以插在第Maxsize +1的位置
	{
		printf("weizhi bu he fa");
		return;
	}
	for (j = Ptrl->Last; j >= i - 1; j--)
	{
		Ptrl->Data[j + 1] = Ptrl->Data[j];//将ai到an倒序向后移动
	}
	Ptrl->Data[i - 1] = X;//新元素插入
	Ptrl->Last++;//Last仍指向最后元素
	return;
} //平均移动次数n/2，平均时间性能为O(n)



//删除(删除表的第i(1<=i<=n)个位置上的元素)
void Delete(int i, List Ptrl)
{
	int j;
	if (i<1 || i>Ptrl->Last + 1) //检查空表以及删除位置的合法性
	{
		printf("不存在第%d个元素", i);
		return;
	}
	for (j = i; j <= Ptrl->Last; j++)
	{
		Ptrl->Data[j - 1] = Ptrl->Data[j];//ai+1 ~ an顺序向前移动
	}
	//for(j = i-1;j < Ptrl->Last;j++){Ptrl->Data[j]=Ptrl->Data[j+1];}
	Ptrl->Last--;
	return;

}