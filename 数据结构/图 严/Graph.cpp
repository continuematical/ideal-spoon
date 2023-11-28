#include<bits/stdc++.h>
using namespace std;

//ͼ���ڽӱ�洢
const int MAX_VERTEX_NUM=20;
typedef int InfoType;
typedef int VertexType;//������Ϣ 
typedef int Status;

const int OK=1;

bool DFSVisited[MAX_VERTEX_NUM];
bool BFSVisited[MAX_VERTEX_NUM];

//�� 
typedef struct ArcNode{
	int adjvex;//�û�ָ��Ķ�����Ϣ 
	struct ArcNode* nextarc;
	InfoType* info;//ָ��û������Ϣ��ָ�� 
}ArcNode; 

//����
typedef struct VNode{
	VertexType data;//������Ϣ
	ArcNode* firstarc;//ָ���һ�������ö���Ļ� 
}Adjust[MAX_VERTEX_NUM], VNode;

//ͼ
typedef struct{
	Adjust vertices;
	int vexnum, arcnum;///ͼ�ĵ�ǰ�������ͱ���
	int kind;//ͼ�������־ 
}ALGraph;

//���G������Ӧ���㣬�򷵻�����ͼ�е�λ�� 
int LocateVex(ALGraph& G, VertexType data){
	for(int i=0;i<G.vexnum;i++)
		if(G.vertices[i].data==data)
			return i;
	return -1;
}

Status CreateGraph(ALGraph& G){
	printf("������ڵ���Ŀ�ͱ���Ŀ��\n");
	cin>>G.vexnum>>G.arcnum;
	printf("�����붥����Ϣ��\n");
	for(int i=0;i<G.vexnum;i++){
		cin>>G.vertices[i].data;
		G.vertices[i].firstarc=NULL;
	}
	printf("���������Ϣ��\n");
	for(int i=0;i<G.arcnum;i++){
		VertexType v1,v2;cin>>v1>>v2;
		int pi=LocateVex(G, v1);
		int pj=LocateVex(G, v2);
		//Ȼ���������ͷ��
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

//����½ڵ�
Status InsertVex(ALGraph& G, VertexType& v){
	G.vertices[G.vexnum].data=v;
	printf("�������붥�������Ľڵ�������\n");
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

//ɾ���ڵ�
Status DeleteVex(ALGraph& G, VertexType& v){
	
}

//��ӱ�
//�ڽڵ�v�ͽڵ�w֮����ӱ� 
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

//ɾ����
//ɾ���ڵ�v�ͽڵ�w֮��ı�
Status DeleteArc(ALGraph& G, VertexType& v, VertexType& w){
	int i=LocateVex(G, v);
	int j=LocateVex(G, w);
	//�ڵ�v 
	ArcNode* p=G.vertices[i].firstarc;
	ArcNode* pre=p;
	while(p->nextarc && p->adjvex!=w){
		pre=p;p=p->nextarc;
	}
	pre->nextarc=p->nextarc;
	delete p;
	//�ڵ�w 
	p=G.vertices[j].firstarc;
	pre=p;
	while(p->nextarc && p->adjvex!=v){
		pre=p;p=p->nextarc;
	}
	pre->nextarc=p->nextarc;
	delete p;
	return OK;
} 

//�����������
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

//�����������
void BFSTraverse(ALGraph& G){
	
} 
