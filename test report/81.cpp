#include <iostream>
using namespace std;

#define MVNum 100	//�������100��
typedef char VType;
bool visited[MVNum];//�ж��Ƿ�����˵�һ������

typedef struct arcNode //����һ��������,����
{
	int adjvex;
	struct arcNode *nextarc;
}ArcNode;

typedef struct vNode //����һ���ṹ���ͣ�����������������һ���ṹ�壬��Ԫ��
{
	VType data;
	ArcNode *firstarc;
}VNode,AdjList[MVNum];

typedef struct //һ���ڽӱ�����
{
	AdjList vertices;
	int vexnum, arcnum;//�������
}ALGraph;



//��v��λ
int LocateVex(ALGraph G, VType v) {

	for (int i = 0; i < G.vexnum; ++i)
	{
		if (G.vertices[i].data == v)
			return i;
	}
	return -1;
}


void CreateG(ALGraph &G)
{
	int i, k;
	cout << "���붥�����ͱ������ո����";
	cin >> G.vexnum >> G.arcnum;
	cout << endl;
	
	cout << "���������" << endl;
	for (i = 0; i < G.vexnum; i++) 
	{
		cout << "����" << i << "λ�õĵ�����";
		cin >> G.vertices[i].data;	//���붥�� ��ֵ
		G.vertices[i].firstarc = NULL;//��ʼ����ͷ���
	}
	cout << endl;

	cout << "���빹�ɱߵ�������" << endl;
	for (k = 0; k < G.arcnum; k++) 
	{
		VType v1, v2;
		int i, j;
		cout << "�����" << k + 1 << "���ߵĶ���" << endl;
		cin >> v1 >> v2;
		i = LocateVex(G, v1);//��λ 
		j = LocateVex(G, v2);//��λ
		
		ArcNode *p1 = new ArcNode;
		p1->adjvex = j;//
		p1->nextarc = G.vertices[i].firstarc;//��p1�嵽ͷ��
		G.vertices[i].firstarc = p1;//��p1��Ϊ�µ�ͷ


		ArcNode *p2 = new ArcNode;
		p2->adjvex = i;//
		p2->nextarc = G.vertices[j].firstarc;//��p2�嵽ͷ��
		G.vertices[j].firstarc = p2;//��p1��Ϊ�µ�ͷ
	
	}

}

//������ȱ���
void DFS(ALGraph G, int v) 
{
	cout << G.vertices[v].data << "   ";//������൱�ڷ�����
	visited[v] = true;//��־�˷�����
	ArcNode *p = G.vertices[v].firstarc;
	while (p != NULL) 
	{
		int w = p->adjvex;	//����w�����--v���ڽӵ�
		if (!visited[w])//��wδ�����ʹ�
		{
			DFS(G, w);//�ݹ�
		}
		p = p->nextarc;
	}
}


int main() {
	int i,a;
	ALGraph G;
	CreateG(G);
	cout << endl;
	cout << "����ͼG�Ѵ���" << endl << endl;

	cout << "���������ʼ�㣺";
	VType q;
	cin >> q;

	for (i = 0; i < G.vexnum; ++i) {
		if (q == G.vertices[i].data)
			break;
	}//�ҵ�q��λ��
	cout << endl;
	while (i >= G.vexnum) {
		cout << "�����ڸõ�,�������� " << endl;
		cin >> q;
		for (i = 0; i < G.vexnum; ++i) {
			if (q == G.vertices[i].data)
				break;
		}
	}
	cout << "������ȱ������" << endl;
	DFS(G, i);

	cout << endl;
	cin >> a;
	return 0;
}