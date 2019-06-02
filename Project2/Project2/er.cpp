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