//堆栈链式存储实现
//栈的链式存储结构实际是个单链表，叫链栈。插入和删除只能在链栈的栈顶进行
//栈顶指针Top应该在链表的头部
#include<stdio.h>
#include<stdlib.h>
#define ElementType int
typedef struct SNode 
{
	ElementType Data;
	struct SNode *Next;
} *Stack;

//堆栈初始化(建立空栈)
Stack CreateStack()
{
	Stack S;//S是指针
	S = (Stack)malloc(sizeof(struct SNode));//S指向一块指定大小的地址
	S->Next = NULL;
	return S;
}

//判断是否为空
int IsEmpty(Stack  S)
{
	return(S->Next == NULL);
}

void Push(ElementType item, Stack S)
{
	struct SNode *TmpCell;
	TmpCell = (Stack)malloc(sizeof(struct SNode));
	TmpCell->Data= item;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;//TmpCell是个指针，地址

}
ElementType Pop(Stack S)
{
	struct SNode *FirstCell;
	ElementType TopElem;
	if (IsEmpty(S)) 
	{
		printf("空");
		return NULL;
	}
	else 
	{
		FirstCell = S->Next;
		S->Next = FirstCell->Next;
		TopElem = FirstCell->Data;
		free(FirstCell);
		return TopElem;

	}


}

//堆栈应用
//应用堆栈实现后缀表达式求值基本过程：
//从左到右读入后缀 表达式的各项
//运算数：入栈
//运算符：从堆栈中弹出适当数量的运算数，计算并将结果入栈
//最后堆栈顶上的元素就是结果
//
//
//中缀表达式求值
//将中缀表达式转换为后缀表达式，然后求值
//2+9/3-5
//293/+5-
//运算数相对顺序不变
//运算符号顺序发生改变
//	需要存储等待中的运算符号
//	要将当前运算符号与等待中的最后一个符号比较】不能马上进行运算
//	
//	输出 2 9
//	记下 + /
//	3
//
//有括号时复杂一点
//
//中缀表达式如何转换为后缀表达式
//从头到尾读取中缀表达式的每个对象，对不同对象按不同的情况处理
//1运算数：直接输出
//2左括号：压入堆栈
//3右括号：将栈顶的运算符弹出并输出，知道遇到左括号（出栈，不输出）
//4运算符：
//	若优先级大于栈顶运算符时，把它压栈
//	若优先级小于等于栈顶运算符时，将栈顶运算符弹出并输出：再比较新的栈顶运算符，
//	直到该运算符大于栈顶运算符优先级为止(或空 ),然后将该运算符压栈
//5若各对象处理完毕，则把堆栈中存留的运算符一并输出


//堆栈其他应用：
//函数调用及递归实现
//深度优先搜索
//回溯算法
//。。。

