#include<iostream>
#include<time.h>
#include<string.h>
#include<fstream>
#define max 50
using namespace std;

void staff_login();
void check_items_availability();
int staff_login_menu_display(); 
void add_item();
void generate_bill(char[10]);
void view_previous_bill();
void new_staff_signup();
void owners_menu_display();
void owners_login();
void view_staff_list();
void mainmenu();

class item
{
	public:
		char item_name[10];
		int item_id;
		float item_price;
		void get_item()
		{
			cout<<"\n\n\n\t\t\t\tEnter item name =";
			cin>>item_name;
			cout<<"\t\t\t\tEnter item id =";
			cin>>item_id;
			cout<<"\t\t\t\tEnter item price =";
			cin>>item_price;
	
		}
		void show_item()
		{
			cout<<"\t\t\t"<<item_name<<"\t\t\t\t\t";
			cout<<item_id<<"\t\t\t\t\t";
			cout<<item_price<<"\n";
		}
}it;

int main()
{
	mainmenu();
}


void mainmenu()
{
	int ch,o;
	cout<<"\n\n\n\t\t    --------------------------------------------------------------------------------\n";
	cout<<"\t\t\t-------------------------------------------------------------------------\n";
	cout<<"\t\t\t|\t\t\t\tMENU\t\t\t\t\t|\n";
	cout<<"\t\t\t|\t\t\t1. Staff Login\t\t\t\t\t|\n\t\t\t|\t\t\t2. Check Items Availability\t\t\t|\n\t\t\t|\t\t\t3. Owners Login\t\t\t\t\t|\n\t\t\t|\t\t\t4. New staff sign up\t\t\t\t|\n\t\t\t|\t\t\t5. exit\t\t\t\t\t\t|\n\t\t\t|\t\t\t\t\t\t\t\t\t|\n\t\t\t|";
	cout<<"\t\t\t\t\t\t\t\t\t|\n\t\t\t-------------------------------------------------------------------------\n";
	cout<<"\t\t    --------------------------------------------------------------------------------\n";
	cout<<"\t\t\t\t\t\tEnter your choice =";
	cin>>ch;
	system("cls");
	switch(ch)
	{
		case 1:staff_login();
			break;
		case 2:check_items_availability();
				printf("\t\tEnter any key to go back =");
				scanf("%d",&o);
				system("cls");
				mainmenu();
			break;
		case 3:owners_login();
			break;
		case 4:new_staff_signup();
			break;
		case 5:	cout<<"\n\n\n\n\t\t\tBYE";
				exit(0);
			break;
		default:cout<<"Wrong choice entered";		
	}
}
void new_staff_signup() 
{							// a function to create a username and password for a new staff
	ifstream in;
	ofstream of;
	char username[10],temp[10];
	char password[10],c;
	int f=1;							// way of storing in memory is "username	password"
	in.open("staff_username.txt");
	cout<<"\n\t\t\t-----------------------------------------------------------------------\n\n";
	cout<<"\t\t\tEnter Username :";
	c=getchar();
	gets(username);
	
	while(in.eof()==0)
	{
		in>>temp;
		
		if(strcmp(temp,username)==0)
		{
			f=0;
			cout<<"\t\t\t----------------------------------------------Try another its already in use!--------------------------------------------\n";
			break;
		}
	}
	if(f==1)
	{
		cout<<"\t\t\t\tavailable :)\n\t\t\tCreate Password:";
		gets(password);
		cout<<"\n\t\t\t-----------------------------------------------------------------------\n";
		of.open("staff_username.txt",ios::app);
		of<<username;
		of<<"\t";
		of<<password;
		of<<"\n";
		of.close();
	
	}
	
		int o;
	
	in.close();
	printf("enter any key to go back =");
	scanf("%d",&o);
	system("cls");
	mainmenu();
}
void staff_login()
{					//	a function that provide access to the staff account and perform operations 
	char c,username[10],password[10],temp[10],t[10];
	ifstream in;
	int i,choice;
	in.open("staff_username.txt");
	int p,q;
	printf("\n\n\t\t\t\tSTAFF LOGIN\n\n");
	cout<<"\n\t\t\t---------------------------------------------------------------------------------\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n\t\t\t\tEnter Username:";
	c=getchar();
	gets(username);
	cout<<"\t\t\t\tEnter Password:";
	gets(password);
	cout<<"\n\t\t\t----------------------------------------------------------------------------------\n";

	while(in.eof()==0)
	{
		in>>temp;
		if(strcmp(temp,username)==0)
		{
			p=1;
			in>>temp;
			
			if(strcmp(temp,password)==0)
			{
				q=1;
				break;
			}
			else
				q=0;
			
		}
		else
			p=0;
	}
	if(p==1&&q==1)
	{
		
		cout<<"\n\t\t\t\t\tWelcome";
		for(i=0;i<500000000;i++);
		system("cls");
		choice=staff_login_menu_display();
		system("cls");
		switch(choice)
		{
			case 1:add_item();
				break;
			case 2:generate_bill(username);
				break;
			case 3:view_previous_bill();
				break;
			case 4:mainmenu();
				break;
				
		}
		
	}
	else
	{
		cout<<"\n\t\t\teither username or password is incorrect !!";
	}
	
}


void check_items_availability()
{
	ifstream in;
	int i=1,t;
	in.open("item_list.txt",ios::binary);
	if(in.eof())
	printf("\t\tNo data in file\n ");
	else
	{
	
		cout<<"\n\n\tITEM LIST\n\n\t\t\titem name\t\t\t\titem id\t\t\t\titem price\n\t\t-----------------------------------------------------------------------------------------------------------\n";
		while(in.eof()==0)
		{
				in>>it.item_name;
				in>>it.item_id;
				in>>it.item_price;
				if(!in.eof())
					it.show_item();
				cout<<"\n";
			
		}
	}
}

int staff_login_menu_display()
{
	int choice; //function for staff login menu display
	cout<<"\n\t\t\t\tSTAFF LOGIN MENU\n\t\t\t-----------------------------------------\n\t\t\t|\t\t\t\t\t|";
	cout<<"\n\t\t\t|\t\t\t\t\t|\n\t\t\t|\t\t\t\t\t|\n\t\t\t|\t\tMENU\t\t\t|\n\t\t\t|\t1. ADD new items\t\t|\n\t\t\t|\t2. Generate Bill\t\t|\n\t\t\t|\t3. View previous bills\t\t|\n\t\t\t|\t4. go back\t\t\t|\n\t\t\t|\t\t\t\t\t|\n\t\t\t|\t\t\t\t\t|";
	cout<<"\n\t\t\t-----------------------------------------\n\n\t\t\t\tEnter your choice=";
	cin>>choice;
	return choice;
	
}


void add_item()
{
	
	ofstream of;
	char ch,c;
	of.open("item_list.txt",ios::app);// stored in binary file
	do
	{
		cout<<"\n\t\t\t------------------------------------------------------------------------------\n";
		it.get_item();
		of<<it.item_name;
		of<<" ";
		of<<it.item_id;
		of<<" ";
		of<<it.item_price;
		of<<"\n";
		cout<<"\t\twant to add more(Y/N)=";
		c=getchar();
		cin>>ch;
		cout<<"\n\t\t\t------------------------------------------------------------------------------\n";
		
		
	}while(ch=='Y'||ch=='y');
	of.close();
	system("cls");
	staff_login();

}

void generate_bill(char username[10])
{
	
	
	int ch=0,i,total=0,itm[max];
	char c,op,o;

	check_items_availability();//function call

	ofstream of;
	of.open("bill.txt",ios::app);
	
	do
	{
		cout<<"\n\tEnter item id from item list =";
		cin>>itm[ch];
		ch++;
			
		cout<<"\t\t\tWant something else(Y/N)=";
		c=getchar();
		cin>>op;

	}while(op=='Y'||op=='y');
	
system("cls");	
		
		ifstream in;
		in.open("item_list.txt");
	cout<<"\t\t\t\t\tWELCOME TO AVAILABLE GROCERY STORE :) \n---------------------------------------------------------------------------------------------------------------------\n";
	cout<<"\t\t\titem name\t\t\titem id\t\t\t\titem price\n-------------------------------------------------------------------------------------------------------------------------\n";
		 
		while(in.eof()==0)
		{
												
			in>>it.item_name;
			in>>it.item_id;
			in>>it.item_price;
			
			i=0;
			if(in.eof()==0)
			{
			
			while(i<ch)
			{
					
				if(it.item_id==itm[i])
				{
					it.show_item();
				
					total=total+it.item_price;		
				}
				i++;
			}
			}
		}
	
					
		
	cout<<"\n--------------------------------------------------------------------------------------------------------------------------\n";
	cout<<"\t\tTotal= Rs ";
	cout<<total;
	cout<<"\n\t\tTHANKS\t\tAttended By : "<<username<<"\n";
	
     time_t t = time(NULL); 
  
     of<<username<<" "<<total<<" "<<ctime(&t)<<"\n";  // order of storing in bill.txt
    cout<<"\t\t\t"<<ctime(&t);
	of.close();
		printf("Enter any key to go back to staff login ");
		scanf("%d",&o);
		
	system("cls");
	staff_login();
 
}

void view_previous_bill()
{
	ifstream in;
	char str[50];
	int o;
	in.open("bill.txt");
	
	cout<<"\n\t\tAttend By   Total Bill     Date & Time\n\n\t\t===================================================\n";
	if(in.eof())
	{
		//
	}
	else
	{
		
		while(in.eof()==0)
		{
			in.getline(str,50);
			cout<<"\t\t\t";
			puts(str);
			cout<<"\n";
			
		}
	}
	printf("Enter any number to go back to staff login =");
	scanf("%d",&o);
		system("cls");
		staff_login();
	
}

void owners_login()
{
	char username[30],ACTUAL_USERNAME[30]={"parasgulati"};
	char password[30],ACTUAL_PASSWORD[30]={"paras"};
	int i;
	printf("\n\n\t\t\tOWNERS LOGIN\n\n");
	cout<<"\t\t-----------------------------------------------------------------------------------------------";
	cout<<"\n\n\t\t\tEnter Username : ";
	cin>>username;
	if(strcmp(username,ACTUAL_USERNAME)==0)
	{
		cout<<"\t\t\tEnter Password : ";
		cin>>password;
		if(strcmp(password,ACTUAL_PASSWORD)==0)
		{
			system("cls");
			cout<<"\n\n\n\n\n\t\t\t\t--------------------WELCOME------------------------\n";
			for(i=0;i<500000000;i++);
			system("cls");
			
			owners_menu_display();
		}
		else
		{
			cout<<"-------------------------------------------password is wrong !!----------------------------------------------------------";
		}
	}
	else
	{
		cout<<"-----------------------------------------------username is wrong !!--------------------------------------------------------------";
	}
	cout<<"\n--------------------------------------------------------------------------------------------------";

}

void owners_menu_display()
{
	int ch;
	cout<<"\t\t-----------------------------------------------\n";
	cout<<"\t\t|\n\t\t\tOWNERS MENU\n\n\t\t\tMENU\n\t\t\t1. view staff list and passwwords\n\t\t\t2. view previous bills\n\t\t\t3. go back\n\t\t\tenter your choice=";
	cin>>ch;
	system("cls");
	switch(ch)
	{
		case 1:view_staff_list();
			break;
		case 2:view_previous_bill();
			break;
		case 3:mainmenu();
			break;
		default:cout<<"----------------------------------------------wrong chocie entered !---------------------------------------------";
	}
}

void view_staff_list()
{
	ifstream ino;
	ino.open("staff_username.txt");
	int o;
	char str[50];
	cout<<"\n\t\t---------------------------------------------------------------------------------------------------------------------------------\n";
	cout<<"\t\t\tStff U.N  Password\n\t\t--------------------------------------------------------------------------------------------------------------------\n";
	while(ino.eof()==0)
	{
		ino.getline(str,50);
		cout<<"\t\t\t"<<str;
		cout<<"\n";
	}
	printf("Enter any key to go back =");
	scanf("%d",&o);
	system("cls");
	owners_menu_display();
}
