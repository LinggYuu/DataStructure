#include<iostream>
using namespace std;
//�ڽӱ�ķ�ʽ�˷ѿռ�
#define MVNum 100  //������༸��
typedef  char VType;//������������
typedef  int  Atype;//Ȩֵ����
bool visited[MVNum];

typedef struct 
{
	VType vexs[MVNum];//װ����
	Atype arcs[MVNum][MVNum];
	int vexnum, arcnum;//��ǰ�������ͱ���
}Graph;


int FirstAdjVex(Graph G, int v);
int NextAdjVex(Graph G, int v, int w);

int LocateVex(Graph G, VType v)//ȷ����v��G�е�λ��
{
	for (int i = 0; i < G.vexnum; i++)
	{	if (G.vexs[i] == v)
			return i;
	}
	return -1;
}


void CreateG(Graph &G)//���ڽӾ��󴴽�����ͼG
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


//�������
void DFS(Graph G, int v)
{
	int w;
	cout << G.vexs[v] << "  ";
	visited[v] = true;//�����ѷ��ʹ�
	for (w = 0; w < G.vexnum; w++)//����
	{
		if ((G.arcs[v][w] != 0) && (visited[w] == false))
			DFS(G, w);//�ݹ�,��������ִ��һ������
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
int NextAdjVex(Graph G , int v , int w){
	int i;
	for(i = w ; i < G.vexnum ; ++i){
		if(G.arcs[v][i] == 1 && visited[i] == false)
			return i;
	}
	return -1;
}


int main()
{
	int a;
	Graph G;
	CreateG(G);
	cout << "�Ѵ�������ͼG "<< endl;
	cout << "���������ʼ��";
	VType q;
	cin >> q;

	int i;
	for (i = 0; i < G.vexnum; ++i) {
		if (q == G.vexs[i])
			break;
	}//��λ��

	cout << endl;
	
	while (i >= G.vexnum) {//�Ҳ���ʱ��ѭ��
		cout << "�����ڸõ�" << endl;
		cout << "��������";
		cin >> q;
		for (i = 0; i < G.vexnum; ++i) {
			if (q == G.vexs[i])
				break;
		}
	}
	cout << "������ȱ��������" << endl;
	DFS(G, i);

	cout << endl;
	
	cin >> a;//��ֱֹ����������
	return 0;
}