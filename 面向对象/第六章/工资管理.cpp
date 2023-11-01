#include<bits/stdc++.h>

class Employee{
	protected:
		char name[1000];//姓名 
		int EmpInfo;//编号 
		double accumPay;//月薪总额
		static int employeeNo;
	public:
		 
};

class Manager:virtual public Employee{
	protected:
		double monthPay;
	public:
		Manager():monthPay(8000){
		};
		void Pay(){
			accumPay=monthPay;	
		}
};

class Technician:virtual public Employee{
	protected:
		double workHour;//每小时工作时间
		double hourlyRate;//每小时工资
	public:
		Technician():hourlyRate(100){
		} 
		
		void setHours(int hours){
			this->workHour=hours;
		}
		
		void Pay(){
			accumPay=workHour*hourlyRate;
		}
};

class Salesman:virtual public Employee{
	protected:
		double CommRate;//提成百分比
		double sales;//销售量 
	public:
		Salesman():CommRate(0.04){
		} 
		
		void setSales(double s){
			this->sales=s;
		}
		
		void Pay(){
			accumPay=sales*CommRate;
		}
};

class SalesManger:public Salesman, public Manager{
	public:
		SalesManager(){
			CommRate=0.05;
			monthPay=5000;
		}
		
		void Pay(){
			accumPay=sales*CommRate+monthPay;
		}
};
