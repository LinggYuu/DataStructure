#include <iostream>
using namespace std;

#define MVNum 100	//顶点最多100个
typedef char VType;
bool visited[MVNum];//判断是否访问了的一个数组

typedef struct arcNode //定义一个链表，边,横向
{
	int adjvex;
	struct arcNode *nextarc;
}ArcNode;

typedef struct vNode //定义一个结构类型，里面有数据且套了一个结构体，单元格
{
	VType data;
	ArcNode *firstarc;
}VNode,AdjList[MVNum];

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
void DFS(ALGraph G, int v) 
{
	cout << G.vertices[v].data << "   ";//输出，相当于访问了
	visited[v] = true;//标志了访问了
	ArcNode *p = G.vertices[v].firstarc;
	while (p != NULL) 
	{
		int w = p->adjvex;	//表明w的身份--v的邻接点
		if (!visited[w])//若w未被访问过
		{
			DFS(G, w);//递归
		}
		p = p->nextarc;
	}
}


int main() {
	int i,a;
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
	}//找到q的位置
	cout << endl;
	while (i >= G.vexnum) {
		cout << "不存在该点,重新输入 " << endl;
		cin >> q;
		for (i = 0; i < G.vexnum; ++i) {
			if (q == G.vertices[i].data)
				break;
		}
	}
	cout << "深度优先遍历结果" << endl;
	DFS(G, i);

	cout << endl;
	cin >> a;
	return 0;
}