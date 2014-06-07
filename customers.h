#ifndef MY_CLASS
#define MY_CLASS
class customers{
private: 
	int c_id;
	char *c_name;
	float c_age;
	char *c_gender;
	double c_balance;
public:customers();
	   void setid (int a);
	   void setname (char *a);
	   void setage (float a);

	   void setgender(char *a);
	   void setbalance (double a);
	   void pclass ();
	   int getid();
	   void getname(char *a,int n);
	   float getage();


	   friend void p2class (customers *,int ); /*		secondary function to display, optional		*/	
	   friend int read(customers *); /* working */	
	   friend void customeradd(customers *,int& ); /* working */	
	   friend void delecust(customers *,int& , int ); /* working */	
	   friend int binsearch(customers *, int,int,int); /* working */	
	   friend void withdraw(customers *,int,int,float); /* working */	
	   friend void deposit(customers *,int,int,float);  /* working */
	   friend void display(customers *,int , char); /* working */		
	   friend double totalbalance(customers *,int); /* working */		
	   friend void sort(customers *, int); /*working */		
	   friend void swap(customers *,customers *); /* working */	
	   friend void top10(customers *, int ); /* working */	
	   friend void save(customers *,int); /* working */

};

int menu();
#endif
