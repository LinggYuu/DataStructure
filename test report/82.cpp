#include <iostream>
using namespace std;

#define MVNum 100	//顶点最多100个
#define MAXQSIZE 100	//队列最长100

typedef  int AType;
typedef char VType;
bool visited[MVNum];//判断是否访问了的一个数组


typedef struct {//定义队列类型
	AType *base;	//初始化
	int front;	//头指针
	int rear;	//尾指针
}sqQueue;

void InitQueue(sqQueue &Q) {//初始化一个队列
	Q.base = new AType[MAXQSIZE];
	if (!Q.base)
		exit(1);
	Q.front = Q.rear = 0;
}

void EnQueue(sqQueue &Q, AType e) {//入队
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;//往后挪一个位置
}


void DeQueue(sqQueue &Q, AType &u) {//出队
	u = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;//往后挪一个位置
}

bool QueueEmpty(sqQueue Q) {//判断是否为空
	if (Q.rear == Q.front)
		return true;
	return false;
}


typedef struct arcNode //定义一个链表，边,横向
{
	int adjvex;//位置
	struct arcNode *nextarc;
}ArcNode;

typedef struct vNode //定义一个结构类型，里面有数据且套了一个结构体，单元格
{
	VType data;
	ArcNode *firstarc;
}VNode, AdjList[MVNum];

typedef struct //一个邻接表类型
{
	AdjList vertices;
	int vexnum, arcnum;//顶点与边
}ALGraph;



//给v定位
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
	cout << "输入顶点数和边数，空格隔开";
	cin >> G.vexnum >> G.arcnum;
	cout << endl;

	cout << "输入点名称" << endl;
	for (i = 0; i < G.vexnum; i++)
	{
		cout << "输入" << i << "位置的点名称";
		cin >> G.vertices[i].data;	//输入顶点 的值
		G.vertices[i].firstarc = NULL;//初始化表头结点
	}
	cout << endl;

	cout << "输入构成边的两个点" << endl;
	for (k = 0; k < G.arcnum; k++)
	{
		VType v1, v2;
		int i, j;
		cout << "输入第" << k + 1 << "条边的顶点" << endl;
		cin >> v1 >> v2;
		i = LocateVex(G, v1);//定位 
		j = LocateVex(G, v2);//定位

		ArcNode *p1 = new ArcNode;
		p1->adjvex = j;//
		p1->nextarc = G.vertices[i].firstarc;//将p1插到头部
		G.vertices[i].firstarc = p1;//将p1设为新的头


		ArcNode *p2 = new ArcNode;
		p2->adjvex = i;//
		p2->nextarc = G.vertices[j].firstarc;//将p2插到头部
		G.vertices[j].firstarc = p2;//将p1设为新的头

	}

}

//深度优先遍历
//void DFS(ALGraph G, int v)
//{
//	cout << G.vertices[v].data << "   ";//输出，相当于访问了
//	visited[v] = true;//标志了访问了
//	ArcNode *p = G.vertices[v].firstarc;
//	while (p != NULL)
//	{
//		int w = p->adjvex;	//表明w的身份--v的邻接点
//		if (!visited[w])//若w未被访问过
//		{
//			DFS(G, w);//递归
//		}
//		p = p->nextarc;
//	}
//}
void BFS(ALGraph G, int v) 
{
	sqQueue Q;
	AType u;
	AType w;
	cout << G.vertices[v].data << " ";//输出，相当于访问了
	visited[v] = true;//标志了访问了
	InitQueue(Q);      //辅助队列Q初始化，置空         
	EnQueue(Q, v);//将v入队
	while(!QueueEmpty(Q)) 
	{
		DeQueue(Q, u);
		ArcNode *p = G.vertices[u].firstarc;
		for (p= G.vertices[u].firstarc;p!=NULL;p=p->nextarc)// 周边的点
		{
			w = p->adjvex;
			if (visited[w] == false) 
			{
				cout<<G.vertices[w].data << " ";
				visited[w] = true;
				EnQueue(Q, w);
				
			}
		}
	
	}
}

int main() {
	int i, a;
	ALGraph G;
	CreateG(G);
	cout << endl;
	cout << "无向图G已创建" << endl << endl;

	cout << "输入遍历起始点：";
	VType q;
	cin >> q;

	for (i = 0; i < G.vexnum; ++i) {
		if (q == G.vertices[i].data)
			break;
	}
	cout << endl;
	while (i >= G.vexnum) {
		cout << "不存在该点,重新输入 " << endl;
		cin >> q;
		for (i = 0; i < G.vexnum; ++i) {
			if (q == G.vertices[i].data)
				break;
		}
	}
	cout << "广度优先遍历结果" << endl;
	BFS(G, i);

	cout << endl;
	cin >> a;
	return 0;
}