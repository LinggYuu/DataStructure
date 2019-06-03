//树
//
//n个结点构成的有限集合
//n=0时，称为空树
//对于任一棵非空树(n>0),它具备性质
//数中有一个叫根root的特殊节点用r表示
//其余结点可分为m(m>0)个互不相交的有限集T1,T2...Tm
//其中每个集合本身又是一棵树，称为原来数的字数(SubTree)
//
//
//子树不相交
//除根结点外，每个节点有且仅有一个父节点
//一棵N个结点的树有N-1条边


//树的表示

//儿子兄弟表示法





//二叉树
//子树有左右之分
//二叉树T:一个有穷的结点集合
//	这个集合可以为空
//	若不为空，则它由根节点和称为其左子树TL和右子树TR的两个不相交 
//	的二叉树组成
//有五种基本形态  


//一个二叉树第i层的最大结点数为2^(i-1), i>=1
//深度为k的二叉树 有 最大总结点数为：2^k -1,k>=1


//对任何非空二叉树T,若n0表示叶结点的个数 、n2是度为2的非叶结点个数，
//那么二者满足关系n0=n2+1



//先序----根，左子树，右子树
//中序----左子树，根，右子树 
//后序----左子树，右子树，根
//层次----从上到下，从左到右


//二叉树的存储结构

//顺序存储结构


//完全二叉树：按从上至下，从左往右顺序存储n个结点的
//完全二叉树的结点父子关系
//非根结点(序号i>1)的父结点的序号是  取整(i/2)
//结点(序号为i)的左孩子结点的序号是2i(2i<=n,否则没有左孩子)
//结点(序号为i)的右孩子结点的序号是2i+1(2i+1 <= n, 否则没有右孩子)

//一般二叉树
//也可以采用这种结构，但会造成空间浪费



//链表存储
#include<stdio.h>
#include<stdlib.h>
#define ElementType int
typedef struct TreeNode *BinTree;//结构指针
typedef BinTree Position;
struct TreeNode 
{
	ElementType Data;
	BinTree Left;
	BinTree	Right;
};


//先序遍历
//过程：
//	访问 根结点
//	先序遍历其左子树
//	先序遍历其右子树
//有遍历

void PreOrderTraversal(BinTree BT)
{
	if (BT) 
	{
		printf("%d", BT->Data);
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
	}
}


//中序
void InOrderTraversal(BinTree BT)
{
	if (BT)
	{
		InOrderTraversal(BT->Left);
		printf("%d", BT->Data);
		InOrderTraversal(BT->Right);
	}
}


//后序
void PostOrderTraversal(BinTree BT)
{
	if (BT)
	{
		PostOrderTraversal(BT->Left);
		printf("%d", BT->Data);
		PostOrderTraversal(BT->Right);
	}
}

//二叉树非递归遍历
//中序遍历非递归遍历算法
//基本思路：堆栈
//
//遇到一个结点，就把它压栈，并去遍历它 的左子树
//当左子树遍历结束后，从栈顶弹出这个结点并访问它
//然后 按 其右指针再去中序遍历该结点的右子树
void InOrderTraversal(BinTree BT)
{
	BinTree T = BT;
	Stack S = CreateStack(MaxSize);//创建并初始化堆栈S
	while (T || !IsEmpty(S)) 
	{
		while (T)//一直向左并将沿途结点压入栈
		{
			Push(S, T);//结点入栈
			T = T->Left;
		}
		if (!IsEmpty(S)) 
		{
			T = Pop(S);//结点出栈
			printf("%d", T->Data);//访问（打印）结点
			T = T->Right;//转向右子树
		}
	}

}

//先序遍历非递归(路径和中序是一样的)


//将printf放到Push前


 
//层序遍历



未完待续