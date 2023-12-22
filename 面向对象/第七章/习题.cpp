#include<bits/stdc++.h>
using namespace std;

//1.重载运算符<<，将Date对象的值以日期形式输出
class Date{
	private:
		int year;
		int month;
		int day;
	public:
		int days(int year, int month){
			bool leap;
			if((year%400==0) || (year%4==0 && year%100!=0))	leap=true;
			else	leap=false;
			
			switch(month){
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					return 31;
				case 4:
				case 6:
				case 9:
				case 11:
					return 30;
				case 2:
					if(leap)	return 29;
					else	return 28;
					break;
			}
		} 
		
		
		Date(int y=1985, int m=1, int d=1){
			if(m>12 || m<1){
				cout<<"Invalid month!"<<endl;
				m=1;
			}
			if(d>days(y,m)){
				cout<<"Invalid days!"<<endl;
				d=1;
			}
			day=d;
			year=y;
			month=m;
		}
		
		void NewDay(){
			if(day<days(year,month))	day++;
			else{
				day=1;
				month++;
				if(month==13){
					year++;
					month=1;
				}
			}
		}
		
		void display(){
			cout<<year<<"-"<<month<<"-"<<day<<endl;
		}
		
		//重载运算符
		friend ostream &operator << (ostream & output, const Date & d){
			output<<d.year<<"-"<<d.month<<"-"<<d.day<<endl;
			return output;
		} 
};

//2.定义Location类，重载运算符
class Location{
	private:
		int x;
		int y;
	public:
		Location(int xx, int yy){
			x=xx;
			y=yy;
		}
		
		Location &operator + (Location& offset);
		Location &operator - (Location& offset);
		
		int getX(){
			return x;
		}
		
		int getY(){
			return y;
		}
}; 

Location&Location::operator + (Location& offset){
	x+=offset.x;
	y+=offset.y;
	return *this;
}

Location& Location::operator - (Location& offset){
	x-=offset.x;
	y-=offset.y;
	return *this;
}
