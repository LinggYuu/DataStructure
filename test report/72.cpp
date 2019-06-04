#include<iostream>
using namespace std;

#define MVNum 100        //�������
#define MAXQSIZE 100	//�����

typedef  char VType;//������������
typedef  int  Atype;//Ȩֵ����
bool visited[MVNum];


typedef struct
{
	VType vexs[MVNum];//װ����
	Atype arcs[MVNum][MVNum];
	int vexnum, arcnum;//��ǰ�������ͱ���
}Graph;


typedef struct {//�����������
	Atype *base;	//��ʼ��
	int front;	//ͷָ��
	int rear;	//βָ��
}sqQueue;

void InitQueue(sqQueue &Q) {//��ʼ��һ������
	Q.base = new Atype[MAXQSIZE];
	if (!Q.base)
		exit(1);
	Q.front = Q.rear = 0;
}

void EnQueue(sqQueue &Q, Atype e) {//���
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;//����Ųһ��λ��
}


void DeQueue(sqQueue &Q, Atype &u) {//����
	u = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;//����Ųһ��λ��
}

bool QueueEmpty(sqQueue Q) {//�ж��Ƿ�Ϊ��
	if (Q.rear == Q.front)
		return true;
	return false;
}



int LocateVex(Graph G, VType v)//ȷ����v��G�е�λ�ã���1һ��
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vexs[i] == v)
			return i;
	}
	return -1;
}

void CreateG(Graph &G)//���ڽӾ��󴴽�����ͼG����1һ��
{
	int i, j, k;
	cout << "�����ܶ��������ܱ������ÿո���� ";
	cin >> G.vexnum >> G.arcnum;
	cout << endl << endl;
	cout << "����������(char����)" << endl;

	for (i = 0; i < G.vexnum; i++)
	{
		cout << "�� " << i << "λ�õĵ�����:";
		cin >> G.vexs[i];
	}
	cout << endl;

	for (i = 0; i < G.vexnum; i++)//������һ����������ȫ��0
	{
		for (j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = 0;
	}
	cout << "���빹�ɱߵ���������" << endl;
	for (k = 0; k < G.arcnum; k++)
	{
		VType v1, v2;//������
		cout << "�����" << k + 1 << "�������ߵĵ�";//��ʱ��0��ʼ
		cin >> v1 >> v2;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);//�ҵ��������ھ����еľ���λ��
		G.arcs[j][i] = G.arcs[i][j] = 1;//1�����б�
	}

}

//����v�ĵ�һ���ڽӵ�
int FirstAdjVex(Graph G, int v) {

	int i;
	for (i = 0; i < G.vexnum; ++i) {
		if (G.arcs[v][i] == 1 && visited[i] == false)
			return i;
	}
	return -1;
}

//����v,w�����ߵ���һ���бߵĵ�
int NextAdjVex(Graph G, int v, int w) {
	int i;
	for (i = w; i < G.vexnum; ++i) {
		if (G.arcs[v][i] == 1 && visited[i] == false)
			return i;
	}
	return -1;
}

//������ȱ���
void BFS(Graph G, int v)
{
	sqQueue Q;
	Atype u;
	Atype w;

	cout << G.vexs[v] << "   ";
	visited[v] = true;
	InitQueue(Q);      //��������Q��ʼ�����ÿ�         
	EnQueue(Q, v);//��v���
	while (!QueueEmpty(Q))
	{
		DeQueue(Q, u);
		for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
		{
			if (visited[w] == false)
			{
				cout << G.vexs[w] << "  ";
				visited[w] = true;
				EnQueue(Q, w);
			}
		}
	}
}



int main() {
	int a;
	Graph G;
	CreateG(G);
	cout << endl;
	cout << "�Ѵ�������ͼG" << endl;

	cout << "���������ʼ��";
	VType q;
	cin >> q;

	int i;
	for (i = 0; i < G.vexnum; i++) {
		if (q == G.vexs[i])
			break;
	}
	cout << endl;
	while (i >= G.vexnum) {
		cout << "�����ڸõ�" << endl;
		cout << "��������";
		cin >> q;
		for (i = 0; i < G.vexnum; ++i) {
			if (q == G.vexs[i])
				break;
		}
	}
	cout << "������ȱ��������" << endl;
	BFS(G, i);

	cout << endl;
	cin >> a;
	return 0;
}