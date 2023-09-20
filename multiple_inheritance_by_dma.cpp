#include<iostream>
using namespace std;

class employee{
	int id;
	public:
		employee();
		employee(int);
		void display();
		int findsalary(){
			return 0;
		}
};

employee::employee(){
	cout<<"in default employee"<<endl;
	id=0;
}

employee::employee(int i){
	cout<<"in para employee"<<endl;
	id =i;
}

void employee::display(){
	cout<<"id of employee : "<<id<<endl;
}

class wageemployee:public employee{
	int hrs, rate;
	public:
		wageemployee();
		wageemployee(int, int,int);
		void display();
		int findsalary();
};

wageemployee::wageemployee(){
	cout<<"in default of wageemployee"<<endl;
		hrs=0;
		rate=0;
}

wageemployee::wageemployee(int i, int h, int r):employee(i){
	cout<<"in pra wageemployee"<<endl;
	hrs = h;
	rate = r;
}

void wageemployee::display(){
	employee::display();
	cout<<"hours of work : "<<hrs<<endl;
	cout<<"rate per hour : "<<rate<<endl;
}

int wageemployee::findsalary(){
	return hrs*rate;
}

class salesmanager: public wageemployee{
	int sales , comm;
	public:
		salesmanager();
		salesmanager(int, int,int,int,int);
		void display();
		int findaslary();
};

salesmanager::salesmanager(){
	cout<<"in deafult of salesmanager "<<endl;
	sales=0;
	comm=0;
}
salesmanager::salesmanager(int i, int h, int r,int s, int c):wageemployee(i,h,r){
	cout<<"in para of salesmanager"<<endl;
	sales = s;
	comm = c;
}

void salesmanager::display(){
	wageemployee::display();
	cout<<"no. of sales : "<<sales<<endl;
	cout<<"rate of per commission : "<<comm<<endl;
}

int salesmanager::findaslary(){
	return (wageemployee::findsalary())+ sales*comm;
}

int main(){
	salesmanager *sm = new salesmanager(101,10,500,2000,1);
	sm->display();
	if(sm)
	delete[] sm;
	cout<<sm->findaslary();
}
