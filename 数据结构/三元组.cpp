typedef int ElemType;
#define MaxSize 100

typedef struct Triple{
	int i,j;
	ElemType e;
}Triple;

typedef struct TSMatrix{
	Triple data[MaxSize];
	int r,c,n;//行数，列数，总数 
}TSMatrix;

//按位就座 
int num[MaxSize], repos[MaxSize];
//相对于原矩阵，每一列的非零元素个数
//每一列非零元素起始位置 
void createRpos(TSMatrix ts){
	for(int i=0;i<ts.n;i++)	num[i]=0;
	for(int i=0;i<ts.n;i++)	++num[ts.data[i].j];
	repos[1]=1;
	for(int i=1;i<ts.n;i++)	repos[i]=repos[i-1]+num[i-1];
} 

//T为转置矩阵，S为原矩阵 
void fastTransposeMatrix(TSMatrix &T, TSMatrix &S){
	T.n=S.n;T.r=S.c;T.c=S.r;
	if(T.n){
		createRpos(S);
		for(int i=0;i<T.n;i++){
			int col=S.data[i].j;
			int p=repos[col];
			T.data[p].i=S.data[i].j;
			T.data[p].j=S.data[i].i;
			T.data[p].j=S.data[i].e;
			++repos[col];//定位到这一列下一位非零元素 
		}
	}
}
