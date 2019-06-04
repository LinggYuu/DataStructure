#include<iostream>
using namespace std;

#define MVNum 100        //顶点最多
#define MAXQSIZE 100	//队列最长

typedef  char VType;//顶点数据类型
typedef  int  Atype;//权值类型
bool visited[MVNum];


typedef struct
{
	VType vexs[MVNum];//装顶点
	Atype arcs[MVNum][MVNum];
	int vexnum, arcnum;//当前顶点数和边数
}Graph;


typedef struct {//定义队列类型
	Atype *base;	//初始化
	int front;	//头指针
	int rear;	//尾指针
}sqQueue;

void InitQueue(sqQueue &Q) {//初始化一个队列
	Q.base = new Atype[MAXQSIZE];
	if (!Q.base)
		exit(1);
	Q.front = Q.rear = 0;
}

void EnQueue(sqQueue &Q, Atype e) {//入队
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;//往后挪一个位置
}


void DeQueue(sqQueue &Q, Atype &u) {//出队
	u = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;//往后挪一个位置
}

bool QueueEmpty(sqQueue Q) {//判断是否为空
	if (Q.rear == Q.front)
		return true;
	return false;
}



int LocateVex(Graph G, VType v)//确定点v在G中的位置，和1一样
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vexs[i] == v)
			return i;
	}
	return -1;
}

void CreateG(Graph &G)//用邻接矩阵创建无向图G，和1一样
{
	int i, j, k;
	cout << "输入总顶点数和总边数，用空格隔开 ";
	cin >> G.vexnum >> G.arcnum;
	cout << endl << endl;
	cout << "输入点的名称(char类型)" << endl;

	for (i = 0; i < G.vexnum; i++)
	{
		cout << "在 " << i << "位置的点名称:";
		cin >> G.vexs[i];
	}
	cout << endl;

	for (i = 0; i < G.vexnum; i++)//构造了一个矩阵，里面全是0
	{
		for (j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = 0;
	}
	cout << "输入构成边的两个顶点" << endl;
	for (k = 0; k < G.arcnum; k++)
	{
		VType v1, v2;//两个点
		cout << "输入第" << k + 1 << "条边两边的点";//存时从0开始
		cin >> v1 >> v2;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);//找到两个点在矩阵中的具体位置
		G.arcs[j][i] = G.arcs[i][j] = 1;//1代表有边
	}

}

//返回v的第一个邻接点
int FirstAdjVex(Graph G, int v) {

	int i;
	for (i = 0; i < G.vexnum; ++i) {
		if (G.arcs[v][i] == 1 && visited[i] == false)
			return i;
	}
	return -1;
}

//返回v,w那条边的下一个有边的点
int NextAdjVex(Graph G, int v, int w) {
	int i;
	for (i = w; i < G.vexnum; ++i) {
		if (G.arcs[v][i] == 1 && visited[i] == false)
			return i;
	}
	return -1;
}

//广度优先遍历
void BFS(Graph G, int v)
{
	sqQueue Q;
	Atype u;
	Atype w;

	cout << G.vexs[v] << "   ";
	visited[v] = true;
	InitQueue(Q);      //辅助队列Q初始化，置空         
	EnQueue(Q, v);//将v入队
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
	cout << "已创建无向图G" << endl;

	cout << "输入遍历起始点";
	VType q;
	cin >> q;

	int i;
	for (i = 0; i < G.vexnum; i++) {
		if (q == G.vexs[i])
			break;
	}
	cout << endl;
	while (i >= G.vexnum) {
		cout << "不存在该点" << endl;
		cout << "重新输入";
		cin >> q;
		for (i = 0; i < G.vexnum; ++i) {
			if (q == G.vexs[i])
				break;
		}
	}
	cout << "广度优先遍历结果：" << endl;
	BFS(G, i);

	cout << endl;
	cin >> a;
	return 0;
}