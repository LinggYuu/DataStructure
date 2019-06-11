#include <iostream>
#include<iomanip>
using namespace std;

#define N 10
struct studscore
{
	char name[10];
	int score;
};


void BInsertSort(studscore sc[N + 1]) //�۰�����㷨
{

	int i, j, high, low, mid;
	for (i = 2; i <= N; ++i) {
		sc[0] = sc[i];       // ��sc[i]�浽sc[0]
		low = 1;   high = i - 1;
		while (low <= high) {    // ����midֵ
			mid = (low + high) / 2;                       
			if (sc[0].score < sc[mid].score) high = mid - 1;
			else  low = mid + 1;                
		}
		for (j = i - 1; j >= high + 1; --j) {
			sc[j + 1] = sc[j];
		}
		sc[high + 1] = sc[0]; 
	}
} 

int main()
{
	int end;
	char a[10];
	int b, i;
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
	BInsertSort(sc);
	for (i = 1; i <= N; i++) {
		cout << setw(10) << sc[i].name << setw(6) << sc[i].score << endl;
	}
	cin >> end;
}

