//��ջ��ʽ�洢ʵ��
//ջ����ʽ�洢�ṹʵ���Ǹ�����������ջ�������ɾ��ֻ������ջ��ջ������
//ջ��ָ��TopӦ���������ͷ��
#include<stdio.h>
#include<stdlib.h>
#define ElementType int
typedef struct SNode 
{
	ElementType Data;
	struct SNode *Next;
} *Stack;

//��ջ��ʼ��(������ջ)
Stack CreateStack()
{
	Stack S;//S��ָ��
	S = (Stack)malloc(sizeof(struct SNode));//Sָ��һ��ָ����С�ĵ�ַ
	S->Next = NULL;
	return S;
}

//�ж��Ƿ�Ϊ��
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
	S->Next = TmpCell;//TmpCell�Ǹ�ָ�룬��ַ

}
ElementType Pop(Stack S)
{
	struct SNode *FirstCell;
	ElementType TopElem;
	if (IsEmpty(S)) 
	{
		printf("��");
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

//��ջӦ��