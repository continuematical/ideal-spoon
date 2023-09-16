#include <bits/stdc++.h> 
using namespace std;
const int N = 100;

typedef struct arcnode{
    struct arcnode *next;
    int vex;
    arcnode(const int &d) : vex(d), next(NULL) {}
} arcnode;

typedef struct node{
    char ve;//节点信息 
    arcnode *fir = new arcnode(0);//节点指向的第一条边 
} arclist[N];


class ALGraph{
	private:
    	arclist ar;//顶点数组 
    	int vexnum, arcnum;//顶点数目 边数目 
    	bool vis[N];//是否被访问到 

	public:
    	ALGraph(){
        	vexnum = arcnum = 0;
        	for (int i = 0; i < N; i++)
            	ar[i].ve = '#';
    	}
    
    	void visit(){
        	for (int i = 0; i < 100; ++i)
            	vis[i] = false;
    	}
    
    
    	void insert_node(char c){
        	ar[vexnum++].ve = c;
    	}
    
    
    	void delete_node(char c){
        	int i;
        	//找到节点 
        	for (i = 0; i < vexnum; ++i)
            	if (ar[i].ve == c)	break;
        	for (int j = i; j < vexnum - 1; ++j)	ar[j] = ar[j + 1];
        	vexnum--;
        	for (int k = 0; k < vexnum; ++k){
            	arcnode *T = ar[k].fir;
            	while (T->next){
                	if (T->next->vex == i){
                    	if (T->next->next)	T->next = T->next->next;
                    	else	T->next = NULL;
                    	break;
                	}
                	else if (T->next->vex > i){
                    	T->next->vex--;
                    	T = T->next;
                	}
                	else	T = T->next;
            	}
        	}
    	}
    
    
    	void insert_edge(char u, char v){
        	int x = -1, y = -1;
        	for (int i = 0; i < vexnum; ++i)
            	if (ar[i].ve == u)	x = i;
            	else if (ar[i].ve == v)	y = i;
            
			//两个节点都要 
        	arcnode *p = new arcnode(0);
        	p->vex = y;
        	arcnode *q = ar[x].fir;
        	while (q->next)
            	q = q->next;
        	p->next = q->next;
        	q->next = p;

        	arcnode *r = new arcnode(0);
        	r->vex = x;
        	q = ar[y].fir;
        	while (q->next)	q = q->next;
        	r->next = q->next;
        	q->next = r;

        	arcnum++;
    	}
    
    
    	void delete_edge(char u, char v){
        	int x = -1, y = -1;
        	for (int i = 0; i < vexnum; ++i)
            	if (ar[i].ve == u)	x = i;
            	else if (ar[i].ve == v)	y = i;
        	arcnode *T = ar[x].fir;
        	while (T->next)
            	if (T->next->vex != y)	T = T->next;
            	else{
                	if (T->next->next)	T->next = T->next->next;
                	else	T->next = NULL;
                	break;
            	}

        	T = ar[y].fir;
        	while (T->next)
            	if (T->next->vex != x)	T = T->next;
            	else{
                	if (T->next->next)	T->next = T->next->next;
                	else	T->next = NULL;
                	break;
            	}
        	arcnum--;
    	}

    	void bfs(int u){
        	queue<int> q;
        	int v;
        	cout << ar[u].ve << " ";
        	q.push(u);vis[u] = true;
        	while (!q.empty()){
            	v = q.front();q.pop();
            	arcnode *p = ar[v].fir;
            	while (p->next){
                	p = p->next;
                	if (!vis[p->vex]){
                    	cout << ar[p->vex].ve << " ";
                    	vis[p->vex] = true;q.push(p->vex);
                	}
            	}
        	}
    	}
    
    	void dfs(int u){
        	cout << ar[u].ve << " ";
        	vis[u] = true;
        	arcnode *p = ar[u].fir;
        	while (p->next){
            	p=p->next;
            	if (!vis[p->vex])	dfs(p->vex);
        	}
    	}

    	void display_edge(){
        	cout << "修改后的结果" << endl;
        	for (int i = 0; i < vexnum; cout << endl, ++i){
            	cout << ar[i].ve << "  :";
            	arcnode *T = new arcnode(0);
            	T = ar[i].fir->next;
            	while (T){
                	cout << T->vex << " ";
                	T = T->next;
            	}
            	delete T;
        	}
    	}
};

void initNode(ALGraph& g){
	g.insert_node('A');
	g.insert_node('B'); 
	g.insert_node('C'); 
	g.insert_node('D'); 
	g.insert_node('E'); 
	g.insert_node('F'); 
	g.insert_node('G');
	g.insert_node('H'); 
}

void initEdge(ALGraph& g){
	g.insert_edge('A','B');
    g.insert_edge('A','C');
    g.insert_edge('A','E');
    g.insert_edge('C','D');
    g.insert_edge('B','D');
    g.insert_edge('D','F');
    g.insert_edge('D','G');
    g.insert_edge('G','H');
}

int main(){
    ALGraph g;
    initNode(g); 
    initEdge(g); 
    g.display_edge();
    return 0;
}

