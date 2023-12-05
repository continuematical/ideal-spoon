#include<bits/stdc++.h>
using namespace std;

//ͼ���ڽӱ�洢
const int MAX_VERTEX_NUM=20;
typedef int InfoType;
typedef int VertexType;//������Ϣ 
typedef int Status;

const int OK=1;
const int ERROR=-1;

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
	return ERROR;
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
		InsertArc(G, v1, v2);
	}
	return OK;
} 

//����½ڵ�
Status InsertVex(ALGraph& G, VertexType& v){
	G.vertices[G.vexnum].data=v;
	G.vertices[G.vexnum++].firstarc=NULL;
	printf("�������붥�������Ľڵ�������\n");
	int number;cin>>number;
	for(int i=0;i<number;i++){
		VertexType j;cin>>j;
		InsertArc(G, v, j);
	}
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
	while(p->nextarc && p->adjvex!=j){
		pre=p;p=p->nextarc;
	}
	if(pre==p)	G.vertices[i].firstarc=p->nextarc;
	else	pre->nextarc=p->nextarc;
	delete p;
	//�ڵ�w 
	p=G.vertices[j].firstarc;
	pre=p;
	while(p->nextarc && p->adjvex!=i){
		pre=p;p=p->nextarc;
	}
	if(pre==p)	G.vertices[j].firstarc=p->nextarc;
	else	pre->nextarc=p->nextarc;
	delete p;
	return OK;
} 

//ɾ���ڵ�
Status DeleteVex(ALGraph& G, VertexType& v){
	int i=LocateVex(G, v);
	//���ڵ��Ӧ����������
	ArcNode* p=G.vertices[i].firstarc;
	ArcNode* q;
	while(p){
		q=p;p=p->nextarc;
		delete q;
	} 
	//������λ
	for(int k=i;k<G.vexnum;k++)	G.vertices[k]=G.vertices[k+1]; 
	p=G.vertices[G.vexnum-1].firstarc;
	while(p){
		q=p;p=p->nextarc;
		delete q;
	}
	G.vexnum--;
	//�������飬����������ýڵ����ı�ɾ�� 
	for(int k=0;k<G.vexnum;k++){
		DeleteArc(G, v, G.vertices[k].data); 
	}
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
	cout<<endl;
}

//�����������
void BFSTraverse(ALGraph& G){
	for(int i=0;i<G.vexnum;i++)
		BFSVisited[i]=false;
	queue<VertexType> q;
	for(int i=0;i<G.vexnum;i++){
		if(!BFSVisited[i]){
			BFSVisited[i]=true;
			cout<<G.vertices[i].data<<" ";
			q.push(i);
			while(!q.empty()){
				int count=q.front();q.pop();
				ArcNode* p=G.vertices[count].firstarc;
				while(p){
					if(!BFSVisited[p->adjvex]){
						q.push(p->adjvex);
						BFSVisited[p->adjvex]=true;
						cout<<G.vertices[p->adjvex].data<<" ";
					}
					p=p->nextarc;
				}
			}
		}
	}
	cout<<endl;
} 

void showGraph(ALGraph& G){
	cout<<"�ڽӱ�Ϊ��"<<endl;
	for(int i=0;i<G.vexnum;i++){
		cout<<G.vertices[i].data<<":";
		ArcNode* p=G.vertices[i].firstarc;
		while(p!=NULL){
			cout<<G.vertices[p->adjvex].data<<" ";
			p=p->nextarc;
		}
		cout<<endl;
	}
	cout<<endl;
} 

VertexType FirstAdjVex(ALGraph& G, VertexType v){
	int i=LocateVex(G, v);
	ArcNode* p=G.vertices[i].firstarc;
	return p->adjvex;
}

int NextAdjVex(ALGraph& G, VertexType v, VertexType w){
	int i=LocateVex(G, v);
	ArcNode* p=G.vertices[i].firstarc;
	while(p){
		if(LocateVex(G, p->adjvex)==w)	break;
		p=p->nextarc;
	}
	if(p==NULL)	return ERROR;
	else	p->nextarc->adjvex;
}

Status GetVex(ALGraph& G, VNode v){
	if(LocateVex(G, v.data)==ERROR)	return ERROR;
	else	return v.data;
}

Status PutVex(ALGraph& G, VNode v, VertexType value){
	VertexType old_value=GetVex(G, v);
	int i=LocateVex(G, old_value);
	G.vertices[i].data=value; 
	return OK; 
}

