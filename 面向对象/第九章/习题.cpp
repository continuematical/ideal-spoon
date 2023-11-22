#include<bits/stdc++.h>
using namespace std;

//1.使用向量容器装入整数1-10，并且使用迭代器iterator和accumulate算法统计十个元素的和
void one(){
	vector<int> res;
	//装入
	for(int i=1;i<=10;i++)	res.push_back(i);
	//int sum=0;
	//for(vector<int>::iterator ite=res.begin();ite!=res.end();ite++)	sum+=*ite;
	cout<<accumulate(res.begin(), res.end(), 0)<<endl; 
} 

//2.使用stl算法和迭代器编写堆排序 
void two(){
	const int SIZE = 10;
	int num[SIZE]={10,3,8,11,20,7,19,5,16,1};
	vector<int> res(num,num+SIZE);
	ostream_iterator<int> output(cout," ");
	
	cout<<"堆排序之前："<<endl;
	copy(res.begin(), res.end(), output);
	cout<<endl;
	
	make_heap(res.begin(), res.end());
	cout<<"建堆之后："<<endl;
	copy(res.begin(), res.end(), output);
	cout<<endl;
	
	//堆排序
	sort_heap(res.begin(), res.end());
	cout<<"堆排序之后："<<endl;
	copy(res.begin(), res.end(), output); 
}

//3.使用stl标准库和迭代器编程实现有序集合的包含 差 交 并 操作
void three(){
	int* ptr;
	
	const int SIZE1=10, SIZE2=5, SIZE3=20;
	int set1[SIZE1]={0,1,2,3,4,5,6,7,8,9};
	int set2[SIZE2]={1,2,3,4,5};
	int set3[SIZE3]={1,2,3,11,12};
	ostream_iterator<int> output(cout," ");
	
	cout<<"set1中的元素："<<endl;
	copy(set1,set1+SIZE1,output);
	
	cout<<"\nset2中的元素"<<endl;
	copy(set2,set2+SIZE2,output);
	
	cout<<"\nset3中的元素"<<endl;
	copy(set2,set2+SIZE2,output);
	
	//包含关系 
	if(includes(set1,set1+SIZE1,set2,set2+SIZE2))	cout<<"\nset1包含set2"<<endl;
	else	cout<<"\nset1不包含set2"<<endl; 
	
	if(includes(set1,set1+SIZE1,set3,set3+SIZE3))	cout<<"\nset1包含set3"<<endl;
	else	cout<<"\nset1不包含set3"<<endl; 
	
	//差
	int diff[SIZE1];
	ptr=set_difference(set1,set1+SIZE1,set2,set2+SIZE2,diff);
	cout<<"\nset1和set2的差集"<<endl; 
	copy(diff,ptr,output);
	
	//交
	int intersection[SIZE1];
	ptr=set_intersection(set1,set1+SIZE1,set2,set2+SIZE2,intersection);
	cout<<"\nset1和set2的交集"<<endl;
	copy(intersection,ptr,output);
	
	//并
	int set_union[SIZE1];
	ptr=std::set_union(set1,set1+SIZE1,set2,set2+SIZE2,set_union);
	cout<<"\nset1和set2的并集"<<endl;
	copy(set_union,ptr,output); 
} 

//4.利用向量容器设计并实现一个图书评级类对若干图书进行评级
//对评级后的图书进行删除 插入等操作
class Review{
	private:
		string title;
		int rating;
	public:
		bool FillReview(Review& rv);
		void showReview(Review& rv);
}; 

bool Review::FillReview(Review& rv){
	cout<<"请输入书名（quit结束）\n"<<endl;
	cin>>rv.title;
	if(rv.title=="quit")	return false;
	cout<<"输入评级（0-5）\n"<<endl;
	cin>>rv.rating;
	if(!cin)	return false;
	cin.get();
	return true;
}

void Review::showReview(Review& rv){
	cout<<rv.title<<'\t'<<rv.rating<<endl;
}

void four(){
	
}

int main(){
	three();
	return 0;
} 
