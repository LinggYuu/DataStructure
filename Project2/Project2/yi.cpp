//堆栈
//算术表达式5+6/2-3*4
//5+6/2-3*4=5+3-3*4=8-3*4=8-12=-4
//由两类对象构成的
//运算数，如2、3、4
//运算符号，如＋-*/
//不同的运算符号优先级不一样

//中缀表达式：运算符号位于两个运算数之间。如a+b*c-d/e
//后缀表达式：运算符号位于两个运算数之后。如abc*+de/-
//62/3-42*+ =?
//62/=3
//33-=0
//42*=8
//08+=8
//对象6；对象2
//对象/；对象3
//对象-；对象4
//对象2；对象*
//对象+；Pop8  
//T(N)=O(N)

//堆栈的抽象数据类型描述
//堆栈(stack):具有一定操作约束的线性表
//只在一端(栈顶，Top)做插入、删除
//插入数据：入栈(Push)
//删除数据：出栈(Pop)
//后入先出：Last In First Out(LIFO)

//类型名：Stack
//数据对象集：一个有0个或多个元素的有穷线性表
//操作集：长度为MaxSize的堆栈S∈Stack，堆栈元素item∈ElementType
//Push Pop可以穿插交替进行；


//栈的顺序存储实现
//栈的顺序存储结构通常由一个一维数组和一个记录栈顶元素位置的变量组成。
#include<stdio.h>
#define MaxSize	100	//<储存数据元素的最大个数>
#define ElementType int
typedef struct SNode *Stack;
struct SNode 
{
	ElementType Data[MaxSize];
	int Top;
};

//入栈
void Push(Stack PtrS, ElementType item)
{
	if (PtrS->Top == MaxSize - 1) 
	{
		printf("堆栈满");
		return;
	}
	else 
	{	
		PtrS->Top++;
		PtrS->Data[PtrS->Top] = item;
		return;
	}
}