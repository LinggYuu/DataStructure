#include<iostream>
using namespace std;

#define Maxsize 100

typedef struct 
{
	int key;
}ElemType;			//���ڹؼ���ƥ��

typedef struct 
{
	ElemType *R;
	int length;
}SSTable;

int InitSSable(SSTable &L)//��ʼ�� 
{
	L.R = new ElemType[Maxsize];
	if (!L.R) 
	{
		cout << "��ʼ��ʧ��";
		return 0;
	}
	L.length = 0;
	return 1;

}

int Insert(SSTable &L) //1 2 3 4 5 6..
{
	int i,j = 1;
	for (i = 1; i < Maxsize; i++) //����һ��
	{
		L.R[i].key = j;
		L.length++;//����ȡ1��length��Ϊhighֵ
		j++;
	
	}
	return 1;

}

int Search(SSTable ST, int key) 
{
	int low = 1, high = ST.length;
	int mid;
	while (low <= high) 
	{
		mid = (low + high) / 2;
		if (ST.R[mid].key == key) 
			{ return mid; }
		else if (ST.R[mid].key > key) 
		{
			high = mid - 1;//ȡ�����һ��
		}
		else
		{
			low = mid + 1;//ȡ�ұ���һ��
		}
	}
	return 0;

}

void Iffind(int result, int key)//�ж��Ƿ��ҵ�
{
	if (result == 0)
		cout << "û�ҵ�" << key << endl;
	else
		cout << "�ҵ���" << key << ",λ��Ϊ" << result << endl;
	return;
}

void main()
{	
	int a;
	SSTable ST;
	InitSSable(ST);
	Insert(ST);
	int key1 = 50, key2 = 101;
	int result;
	result = Search(ST, key1);
	Iffind(result, key1);
	result = Search(ST, key2);
	Iffind(result, key2);
	cin >> a;
}