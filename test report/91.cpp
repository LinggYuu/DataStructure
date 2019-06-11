#include<iostream>
using namespace std;

#define Maxsize 100

typedef struct 
{
	int key;
}ElemType;			//用于关键字匹配

typedef struct 
{
	ElemType *R;
	int length;
}SSTable;

int InitSSable(SSTable &L)//初始化 
{
	L.R = new ElemType[Maxsize];
	if (!L.R) 
	{
		cout << "初始化失败";
		return 0;
	}
	L.length = 0;
	return 1;

}

int Insert(SSTable &L) //1 2 3 4 5 6..
{
	int i,j = 1;
	for (i = 1; i < Maxsize; i++) //空了一个
	{
		L.R[i].key = j;
		L.length++;//用于取1到length，为high值
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
			high = mid - 1;//取左边那一块
		}
		else
		{
			low = mid + 1;//取右边那一块
		}
	}
	return 0;

}

void Iffind(int result, int key)//判断是否找到
{
	if (result == 0)
		cout << "没找到" << key << endl;
	else
		cout << "找到了" << key << ",位置为" << result << endl;
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