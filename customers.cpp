#include"my_class.h"
#include<iostream>
#include<fstream>
using namespace std;

customers::customers(){
}	
void customers::setid (int a){
	c_id=a;	
}	

void customers:: setname (char *a){	
	c_name=a;	
}
void customers::setage (float a){
	c_age=a;
}
void customers::setgender(char *a){
	c_gender=a;		
}
void customers::setbalance (double a){
	c_balance=a;
}
void customers::pclass (){
	std::cout<<c_id<<"\t"<<c_name<<"\t"<<c_age<<"\t"<<c_gender<<"\t"<<c_balance<<"\n";
}
int customers::getid(){
	return c_id;
}	
void customers::getname(char *a,int n){
	a=c_name;
}
float customers::getage(){
	return c_age;
}

int menu(){	
	int ch;
	std::cout<<"1-add customer\n2-delete customer\n3-withdraw\n4-depopsit\n5-display names (M or F)\n6-calculate total balance\n7-show top ten names\n8- save\n9-display\n-1 EXIT";	
	std::cin>>ch;	return ch;
}

void p2class (customers *e, int i){
	cout<<e[i].c_id<<"\t"<<e[i].c_name<<"\t"<<e[i].c_age<<"\t"<<e[i].c_gender<<"\t"<<e[i].c_balance<<"\n";
}

int  read(customers  *e){
 	int  id,c=0;
 	char  *gender=new  char  [100];
 	char  *name=new  char  [100];
 	float  age;
 	double  balance;
 	ifstream  ifile;
 	ifile.open("test.txt");
 	if  (!ifile) 	 	cout<<"File  not  found.\n";
 	else{
 	 	while(!ifile.eof()){
 	 	 	ifile>>id>>name>>age>>gender>>balance;
 	 	 	e[c].setid(id);
 	 	 	e[c].setname(name);
 	 	 	e[c].setage(age);
 	 	 	e[c].setgender(gender);
 	 	 	e[c].setbalance(balance);
 	 	 	c++;
 	 	 	gender=new  char  [100];
 	 	 	name=new  char  [100];
 	 	}
 	}
 	ifile.close();
 	cout<<"there  are  "<<c<<"  customers\n";
 	return  c;
}

void  customeradd(customers  *e,int&  n){
 	customers  *temp=new  customers  [n+1];
 	cout<<"\n";
 	bool  notfound=false;
 	cout<<"new  id:";
 	int  id;
 	cin>>id;
 	for(int  i=0;i<n;i++){
 	 	if(e[i].c_id==id) 	 	 	notfound=true;
 	}
 	if(!notfound){
 	temp=e;
 	n=n+1;
 	e=new  customers  [n];
 	e=temp;
 	e[n-1].setid(id);
 	cout<<"\n";
 	cout<<"new  name:  ";
 	char  *a=new  char  [100];
 	cin>>a;
 	e[n-1].setname(a);
 	a=new  char  [100];
 	cout<<"\n";
 	cout<<"new  age:  ";
 	float  age;
 	cin>>age;
 	e[n-1].setage(age);
 	cout<<"\n";
 	cout<<"new  gender:  ";
 	char  *gender=new  char  [10];
 	cin>>gender;
 	e[n-1].setgender(gender);
 	gender=new  char  [10];
 	cout<<"\n";
 	cout<<"new  balance:  ";
 	double  balance;
 	cin>>balance;
 	e[n-1].setbalance(balance);
 	}
 	else   	 	cout<<"ID  lready  taken\n";
}

void  delecust(customers  *e,int&  n,  int  id){
 	int  found=binsearch(e,id,0,n-1);
 	if  (found!=-1){
 	 	for  (int  i=found;i<n-1;i++){
 	 	 	e[i]=e[i+1];
 	 	}
 	 	cout<<"deleted  profile  of  ID  "<<id<<"\n";
 	 	n=n-1;
 	}
 	else 
		cout<<"not  found\n";
}

int  binsearch(customers  *e,  int  k,int  lb,int  ub){
 	  int  m;
 	  while  (lb<=ub){
 	 	  m=(lb+ub)/2;
 	 	  if  (e[m].c_id>k) 
			  ub=m-1;
 	 	  else  if(e[m].c_id<k) 
			  lb=m+1;
 	 	  else  if(e[m].c_id==k)
			  return  m;
 	  }
 	  return  -1;
  }

void  withdraw(customers  *e,int  n,int  id,float  wdraw){
 	int  found=binsearch(e,id,0,n-1);
 	if  (found!=-1){
 	 	if  (wdraw>0){
 	 	 	if  (e[found].c_balance>wdraw){
 	 	 	 	e[found].c_balance=e[found].c_balance-wdraw;
 	 	 	}
 	 	 	else 	
				cout<<"can  not  withdraw...withdraw  ammount  must  be  less  or  equal  to  "<<e[found].c_balance<<"\n";
 	 	}
 	 	else 
			cout<<"withdraw  ammount  must  be  a  positive  ammount\n";
 	}
 	else 
		cout<<"invlaid  ID\n";
}

void  deposit(customers  *e,int  n,int  id,float  depo){
 	  int  found=binsearch(e,id,0,n-1);
 	  if  (found!=-1){
 	 	  if(depo>=0){
 	 	e[found].c_balance=e[found].c_balance+depo;
 	 	  }
 	 	  else 	
			  cout<<e[found].c_name<<"deposit  value  must  be  >  or  =  to  0\n";
 	}
 	else 	
		cout<<"invlaid  ID\n";
  }

void  display(customers  *e,int  n,  char  chgen){
 	char  k;
 	  for(int  i=0;i<n;i++){
 	 	  if(e[i].c_gender[0]==chgen) 
			  cout<<e[i].c_name<<"\n";
 	  }
  }

double  totalbalance(customers  *e,int  n){
 	  double  sum=0;
 	  for  (int  i=0;i<n;i++){
 	 	  sum+=e[i].c_balance;
 	  }
 	  return  sum;
  }
  void  sort(customers  *e,  int  n){
 	  for  (int  i=1;i<=n-1;i++){
 	 	  for  (int  j=0;j<n-1;j++){
 	 	 	  if(e[j].c_id>e[j+1].c_id){
 	 	 	 	  swap(e[j],e[j+1]);
 	 	 	  }
 	 	  }
 	  }
  }
  void  swap(customers  *x,customers  *y){
 	  customers  *temp;
 	  temp=x;
 	  x=y;
 	  y=x;
  }

  void  top10(customers  *e,  int  n){
 	  for  (int  i=1;i<=n-1;i++){
 	 	  for  (int  j=0;j<n-1;j++){
 	 	 	  if  (e[j].c_balance<e[j+1].c_balance) 	
				  swap(e[j],e[j+1]);
 	 	  }
 	  }
 	  int  c=1;
 	  for  (int  i=0;i<10;i++){
 	 	cout<<c<<"-"<<e[i].c_name<<"\n";
 	 	c++;
 	}
  }
  void  save(customers  *e,int  n){
 	  ofstream  ofile;
 	  ofile.open("test.txt");
 	  for  (int  i=0;i<n;i++){
 	 	  ofile<<e[i].c_id<<"\t"<<e[i].c_name<<"\t"<<e[i].c_age<<"\t"<<e[i].c_gender<<"\t"<<e[i].c_balance<<"\n";
 	  }
 	  ofile.close();
  }
	
