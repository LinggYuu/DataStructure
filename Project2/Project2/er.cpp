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
//Ӧ�ö�ջʵ�ֺ�׺���ʽ��ֵ�������̣�
//�����Ҷ����׺ ���ʽ�ĸ���
//����������ջ
//��������Ӷ�ջ�е����ʵ������������������㲢�������ջ
//����ջ���ϵ�Ԫ�ؾ��ǽ��
//
//
//��׺���ʽ��ֵ
//����׺���ʽת��Ϊ��׺���ʽ��Ȼ����ֵ
//2+9/3-5
//293/+5-
//���������˳�򲻱�
//�������˳�����ı�
//	��Ҫ�洢�ȴ��е��������
//	Ҫ����ǰ���������ȴ��е����һ�����űȽϡ��������Ͻ�������
//	
//	��� 2 9
//	���� + /
//	3
//
//������ʱ����һ��
//
//��׺���ʽ���ת��Ϊ��׺���ʽ
//��ͷ��β��ȡ��׺���ʽ��ÿ�����󣬶Բ�ͬ���󰴲�ͬ���������
//1��������ֱ�����
//2�����ţ�ѹ���ջ
//3�����ţ���ջ��������������������֪�����������ţ���ջ���������
//4�������
//	�����ȼ�����ջ�������ʱ������ѹջ
//	�����ȼ�С�ڵ���ջ�������ʱ����ջ�������������������ٱȽ��µ�ջ���������
//	ֱ�������������ջ����������ȼ�Ϊֹ(��� ),Ȼ�󽫸������ѹջ
//5������������ϣ���Ѷ�ջ�д����������һ�����


//��ջ����Ӧ�ã�
//�������ü��ݹ�ʵ��
//�����������
//�����㷨
//������

