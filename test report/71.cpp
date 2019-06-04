#include<iostream>
using namespace std;
//邻接表的方式浪费空间
#define MVNum 100  //顶点最多几个
typedef  char VType;//顶点数据类型
typedef  int  Atype;//权值类型
bool visited[MVNum];

typedef struct 
{
	VType vexs[MVNum];//装顶点
	Atype arcs[MVNum][MVNum];
	int vexnum, arcnum;//当前顶点数和边数
}Graph;


int FirstAdjVex(Graph G, int v);
int NextAdjVex(Graph G, int v, int w);

int LocateVex(Graph G, VType v)//确定点v在G中的位置
{
	for (int i = 0; i < G.vexnum; i++)
	{	if (G.vexs[i] == v)
			return i;
	}
	return -1;
}


void CreateG(Graph &G)//用邻接矩阵创建无向图G
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


//深度优先
void DFS(Graph G, int v)
{
	int w;
	cout << G.vexs[v] << "  ";
	visited[v] = true;//代表已访问过
	for (w = 0; w < G.vexnum; w++)//遍历
	{
		if ((G.arcs[v][w] != 0) && (visited[w] == false))
			DFS(G, w);//递归,换个点再执行一遍上述
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
	cout << "已创建无向图G "<< endl;
	cout << "输入遍历起始点";
	VType q;
	cin >> q;

	int i;
	for (i = 0; i < G.vexnum; ++i) {
		if (q == G.vexs[i])
			break;
	}//找位置

	cout << endl;
	
	while (i >= G.vexnum) {//找不到时的循环
		cout << "不存在该点" << endl;
		cout << "重新输入";
		cin >> q;
		for (i = 0; i < G.vexnum; ++i) {
			if (q == G.vexs[i])
				break;
		}
	}
	cout << "深度优先遍历结果：" << endl;
	DFS(G, i);

	cout << endl;
	
	cin >> a;//防止直接跳出程序
	return 0;
}