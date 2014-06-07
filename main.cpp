#include<fstream>
#include"my_class.h"
#include<iostream>
using namespace std;


int main(){
	customers  *t=new  customers  [99],*e;
 	int  n=read(t);
 	e=new  customers  [n];
 	e=t;
 	sort(e,n);
 	for  (int  i=0;i<n;i++){
 	 	p2class(e,i);
 	}
 	cout<<"__________\n";
 	int  ch=menu(),idwithdraw,iddeposit;
 	float  withdrawvalue,depositvalue;
 	char  gendertype;

	while  (ch!=-1){
 	switch  (ch){
 	case  1: 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	/*  case  1  :  profile  add  */ 
		cout<<"add  a  profile...\n";
 	 	customeradd(e,n);
 	 	sort(e,n);
 	 	cout<<"___________________________________________\n";
 	 	for  (int  i=0;i<n;i++){
 	 	p2class(e,i);
 	 	}
 	 	break;
	case  2: 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	/*  case  2  :  profile  delete  */ 
		cout<<"which  ID  to  delete?  ";
 	 	int  id;
 	 	cin>>id;
 	 	delecust(e,n,id);
 	 	sort(e,n);
 	 	cout<<"___________________________________________\n";
 	 	for  (int  i=0;i<n;i++){
 	 	 	p2class(e,i);
 	 	}
 	 	break;
 	case  3: 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	/*  case  3  :  withdraw  */ 
		cout<<"enter  ID  to  withdraw  from:  ";
 	 	cin>>idwithdraw;
 	 	cout<<"enter  ammount  to  withdraw:  ";
 	 	cin>>withdrawvalue;
 	 	withdraw(e,n,idwithdraw,withdrawvalue);
 	 	cout<<"___________________________________________\n";
 	 	for  (int  i=0;i<n;i++){
 	 	p2class(e,i);
 	}
 	 	break;
 	case  4: 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	/*  case  4  :  depsoit*/ 
		cout<<"enter  ID  to  deopist  to:  ";
 	 	cin>>iddeposit;
 	 	cout<<"enter  ammount  to  deposit:  ";
 	 	cin>>depositvalue;
 	 	deposit(e,n,iddeposit,depositvalue);
 	 	cout<<"___________________________________________\n";
 	 	for  (int  i=0;i<n;i++){
 	 	p2class(e,i);
 	}
 	 	break;
 	case  5: 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	/*  case  5  :  M/F  display  */ 	
		cout<<"Do  you  want  to  display  males  or  females?  (M/F)";
 	 	cin>>gendertype;
 	 	display(e,n,gendertype);
 	 	break;
 	case  6: 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	/*  case  6  :  total  balance  */ 	 
		cout<<"___________________________________________\n";
 	 	cout<<"The  total  balance  of  all  "<<n<<"  people  combined  is  "<<totalbalance(e,n)<<"\n";
 	 	break;
 	case  7: 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	/*  case  7  :  top  10  */ 
		cout<<"___________________________________________\n";
 	 	top10(e,n);
 	 	sort(e,n);
 	 	break;
 	case  8: 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	/*  case  8  :  save  */ 
		cout<<"___________________________________________\n";
 	 	save(e,n);
 	 	cout<<"saved...\n";
 	 	break;
 	case  9: 	 	for  (int  i=0;i<n;i++){
 	 	p2class(e,i);
 	}
 	 	break;
 	default: 	 	cout<<"not  valid,  try  again\n";
 	 	}
 	cout<<"___________________________________________\n";
 	ch=menu();
 	cout<<"___________________________________________\n";
 	}
 	for  (int  i=0;i<n;i++){
 	 	p2class(e,i);
 	}
 	return  0;
}
	
