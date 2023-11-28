#include<bits/stdc++.h>
using namespace std;

//图的邻接表存储
const int MAX_VERTEX_NUM=20;
typedef int InfoType;
typedef int VertexType;//顶线信息 
typedef int Status;

const int OK=1;

bool DFSVisited[MAX_VERTEX_NUM];
bool BFSVisited[MAX_VERTEX_NUM];

//边 
typedef struct ArcNode{
	int adjvex;//该弧指向的定点信息 
	struct ArcNode* nextarc;
	InfoType* info;//指向该弧相关信息的指针 
}ArcNode; 

//顶点
typedef struct VNode{
	VertexType data;//定点信息
	ArcNode* firstarc;//指向第一条依附该顶点的弧 
}Adjust[MAX_VERTEX_NUM], VNode;

//图
typedef struct{
	Adjust vertices;
	int vexnum, arcnum;///图的当前顶点数和边数
	int kind;//图的种类标志 
}ALGraph;

//如果G存在相应顶点，则返回它在图中的位置 
int LocateVex(ALGraph& G, VertexType data){
	for(int i=0;i<G.vexnum;i++)
		if(G.vertices[i].data==data)
			return i;
	return -1;
}

Status CreateGraph(ALGraph& G){
	printf("请输入节点数目和边数目：\n");
	cin>>G.vexnum>>G.arcnum;
	printf("请输入顶点信息：\n");
	for(int i=0;i<G.vexnum;i++){
		cin>>G.vertices[i].data;
		G.vertices[i].firstarc=NULL;
	}
	printf("请输入边信息：\n");
	for(int i=0;i<G.arcnum;i++){
		VertexType v1,v2;cin>>v1>>v2;
		int pi=LocateVex(G, v1);
		int pj=LocateVex(G, v2);
		//然后插入链表头部
		ArcNode* p1=new ArcNode(); 
		p1->adjvex=pj;
		p1->nextarc=G.vertices[pi].firstarc;
		G.vertices[i].firstarc=p1;
		
		ArcNode* p2=new ArcNode(); 
		p2->adjvex=pi;
		p2->nextarc=G.vertices[pj].firstarc;
		G.vertices[pj].firstarc=p2;
	}
	return OK;
} 

//添加新节点
Status InsertVex(ALGraph& G, VertexType& v){
	G.vertices[G.vexnum].data=v;
	printf("请输入与顶点相连的节点数量：\n");
	int number;cin>>number;
	for(int i=0;i<number;i++){
		VertexType j;cin>>j;
		int pj=LocateVex(G, j);
		
		ArcNode* p1=new ArcNode();
		p1->adjvex=G.vexnum;
		p1->nextarc=G.vertices[pj].firstarc;
		G.vertices[pj].firstarc=p1;
		
		ArcNode* p2=new ArcNode();
		p2->adjvex=pj;
		p2->nextarc=G.vertices[G.vexnum].firstarc;
		G.vertices[G.vexnum].firstarc=p2;
	}
	G.vexnum++;
	return OK;
} 

//删除节点
Status DeleteVex(ALGraph& G, VertexType& v){
	
}

//添加边
//在节点v和节点w之间添加边 
Status InsertArc(ALGraph& G, VertexType& v, VertexType& w){
	int i=LocateVex(G, v);
	int j=LocateVex(G, w);
	
	ArcNode* pi=new ArcNode();
	pi->adjvex=j;
	pi->nextarc=G.vertices[i].firstarc;
	G.vertices[i].firstarc=pi;
	
	ArcNode* pj=new ArcNode();
	pj->adjvex=i;
	pj->nextarc=G.vertices[j].firstarc;
	G.vertices[j].firstarc=pj;
	return OK;
} 

//删除边
//删除节点v和节点w之间的边
Status DeleteArc(ALGraph& G, VertexType& v, VertexType& w){
	int i=LocateVex(G, v);
	int j=LocateVex(G, w);
	//节点v 
	ArcNode* p=G.vertices[i].firstarc;
	ArcNode* pre=p;
	while(p->nextarc && p->adjvex!=w){
		pre=p;p=p->nextarc;
	}
	pre->nextarc=p->nextarc;
	delete p;
	//节点w 
	p=G.vertices[j].firstarc;
	pre=p;
	while(p->nextarc && p->adjvex!=v){
		pre=p;p=p->nextarc;
	}
	pre->nextarc=p->nextarc;
	delete p;
	return OK;
} 

//深度优先搜索
void DFS(ALGraph& G, int i){
	DFSVisited[i]=true;
	cout<<G.vertices[i].data<<" ";
	ArcNode* p=G.vertices[i].firstarc;
	while(p){
		if(!DFSVisited[p->adjvex])
			DFS(G, p->adjvex);
		p=p->nextarc;
	}
} 

void DFSTraverse(ALGraph& G){
	for(int i=0;i<G.vexnum;i++)
		DFSVisited[i]=false;
	for(int i=0;i<G.vexnum;i++)
		if(!DFSVisited[i])
			DFS(G, i);
}

//广度优先搜索
void BFSTraverse(ALGraph& G){
	
} 
