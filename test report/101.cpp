#include <iostream>
#include<iomanip>
using namespace std;

#define N 10
struct studscore
{
	char name[10];
	int score;
};


int Partition(studscore sc[N + 1], int low, int high)
{

	int pivotkey;
	sc[0] = sc[low];
	pivotkey = sc[low].score;
	while (low < high) {
		while (low < high && sc[high].score >= pivotkey)
		{
			high--;
		}
		sc[low] = sc[high];
		while (low < high && sc[low].score <= pivotkey)
		{
			low++;
		}
		sc[high] = sc[low];
	}
	sc[low] = sc[0];
	return low;
}


void QSort(studscore sc[N + 1], int low, int high)//��������
{

	int p;
	if (low < high)
	{
		p = Partition(sc, low, high);
		QSort(sc, low, p - 1);
		QSort(sc, p + 1, high);
	}
}


int main()
{
	int end;
	char a[10];
	int b,i;
	studscore sc[N + 1];
	cout << "������" << N << "��ѧ�����������ɼ���" << endl;
	for (int i = 1; i <= N; i++) 
	{
		cin >> a >> b;
		for (int j = 0; j < 10; j++) 
		{
			sc[i].name[j] = a[j];
		}
		sc[i].score = b;
	}
	cout << "�������" << N << "��ѧ���������Ӹߵ�������" << endl;
	QSort(sc,1,N);
	for (i = 1; i <= N; i++) {
		cout << setw(10) << sc[i].name << setw(6) << sc[i].score << endl;
	}
	cin >> end;
}


