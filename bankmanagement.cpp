
Conversation opened. 1 read message.

Skip to content
Using National University of Comp. &amp; Emerging Sciences Mail with screen readers
bank management 
Conversations
Using 0.59 GB
Manage
Program Policies
Powered by Google
Last account activity: 6 minutes ago
Details

#include<iostream>  
#include<fstream>    
#include<cctype>      
#include<iomanip>
#include<Windows.h>
using namespace std;


/****************************************************************************************/
/*                             Login Class                                           */
/***************************************************************************************/
class login{
	private:
		string id;
		string password;
		string real_id;
		string real_password;
	public:
		login(){
		}
		login(string a, string b){
			id=a;
			password=b;
		}
		void set_id(string a){
			id=a;
		}
		void set_password(string b){
			password=b;
		}
		//function to set id and password from file
		void set_real_values(string a, string b){
			real_id=a;
			real_password=b;
		}
		void display(){
			cout<<"\nreal ID "<<real_id;
			cout<<"\nreal Password "<<real_password;
			cout<<"\nID "<<id;
			cout<<"\nPassword "<<password;
		}
		int check(){
			int flag=0;
			for (int j=0;j<sizeof(real_id);j++){
				if(real_id[j]==id[j]){
					flag=flag;
				}
				else{
					flag=flag+1;
				}
			}
			for (int j=0;j<sizeof(real_password);j++){
				if(real_password[j]==password[j]){
					flag=flag;
				}
				else{
					flag=flag+1;
				}
			}
			return (flag);
		}
};
/****************************************************************************************/
/*                             Login Class Ending                                       */
/***************************************************************************************/





/****************************************************************************************/
/*                             Account class base                                      */
/***************************************************************************************/
class account{
    protected:
	int ano;
    char name[100];
    int dep;
    char type;
public:
    void create_acc(){
	    cout<<"\nEnter The Account Number :";
	    cin>>ano;
	    cout<<"\n\nEnter, Name of The Account Holder : ";
	    cin.ignore();
	    cin.getline(name,100);
	    cout<<"\nEnter Type of Account(Current/Savings) : ";
	    cin>>type;
	    cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	    cin>>dep;     //We have set the minimum initial amount for savings be 500 & for current be 1000 
	    cout<<"\n\n\nCongrats Account Has Been Created..";
	} 
	void show_acc() const{
	    cout<<"\nAccount Number : "<<ano;
	    cout<<"\nAccount Holder Name : ";
	    cout<<name;
	    cout<<"\nType of Account : "<<type;
	    cout<<"\nBalance amount : "<<dep;
	}	

        
    void adep(int x){
	    dep+=x;

	}   
    void draw(int x){
    	dep-=x;
	}          
    int retbal() const{
    	return dep;
	}
	char qtype() const{
		return type;
	}    
	int retano() const{
			return ano;
		}
};

/****************************************************************************************/
/*                            Manager class child                                       */
/***************************************************************************************/

class manager:public account{
	 public:
		 void report() const{
			cout<<ano<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<dep<<endl;
		}
		
};

/****************************************************************************************/
/*                            Account class child                                       */
/***************************************************************************************/

class employee:public account{
	public:
		void modify(){
		    cout<<"\nAccount Number : "<<ano;
		    cout<<"\nModify Account Holder Name : ";
		    cin.ignore();
		    cin.getline(name,100);
		    cout<<"\nModify Type of Account : ";
		    cin>>type;
		    cout<<"\nModify Balance amount : ";
		    cin>>dep;
		}
};

/****************************************************************************************/
/*                       function to show options                                       */
/***************************************************************************************/


void main_table(){
	system("cls");
	cout<<"\n\n\n\tACTION MENU";
	cout<<"\n\n\t01. NEW ACCOUNT";
	cout<<"\n\n\t02. DEPOSIT";
	cout<<"\n\n\t03. WITHDRAW";
	cout<<"\n\n\t04. BALANCE ENQUIRY";
	cout<<"\n\n\t05. COMPLETE ACCOUNT HOLDERS LIST";
	cout<<"\n\n\t06. CLOSE AN ACCOUNT";
	cout<<"\n\n\t07. MODIFY AN ACCOUNT";
	cout<<"\n\n\t08. EXIT";
	cout<<"\n\n\tSelect Your Option (1-8) ";
}



/****************************************************************************************/
/*                   Displaying name of Project                                        */
/***************************************************************************************/

void display(){
	for (int i=0;i<=7;i++){
		cout<<"__________";
		Sleep(100);
	}
	cout<<"\n\t\t\t";
	char array[]="Welcome to bank Management System";
	for (int i=0;i<=32;i++){
		cout<<array[i];
		Sleep(100);
	}
	cout<<"\n";
	for (int i=0;i<=7;i++){
		cout<<"__________";
		Sleep(100);
	}
	cout<<"\n";
	return;
}

/****************************************************************************************/
/*                          function to select user type                               */
/***************************************************************************************/

void start_menu(){
	cout<<"\n\n\n\t\t\t01.	Manger";
	cout<<"\n\t\t\t02.	Employee";
	cout<<"\n\t\t\t03.	Customer";
}

/*****function declartions******/

void delete_acc(int n);
void display_all();
void dep_withdraw(int n, int option);
void modify_acc(int n);
void display_sp(int n); 
void write_acc();



/******************************/

/****************************************************************************************/
/*                        				   Main Function                               */
/***************************************************************************************/

int main(){
	
/****************************************************************************************/
/*                    		instructions to display table                               */
/***************************************************************************************/	
	display();
	system("cls");
	start_menu();
	system("cls");
	Sleep(1000);
/*instructions to select option*/
	int choice;
	cout<<"\n";
	cin>>choice;
	system("cls");
	switch (choice){
		
		case 1:
		{	// checking wether the user Enter correct Id or not
			///////////////////////////////////////////////////
				string log;
				string pass;
				login obj1;
				cout<<"\n\n\n\n\n\n\t\tLogin ID\t";
				getline(cin, log);
				obj1.set_id(log);
				cout<<"\t\tPassword\t";
				getline(cin,pass);
				obj1.set_password(pass);	
				for (int i=0;i<=5;i++){
					cout<<"\xdb\xdb\xdb\xdb";
					Sleep(500);
					cout<<"\xdb\xdb\xdb\xdb";
				}
				
			/*********************************************************************/	
				/*variables to store id and password from file*/
				/*stroing id in a and password in b*/
				
				ifstream objj;
				objj.open("admin.txt");
				string a;
				string b;
				getline (objj, a);
				getline (objj, b);
				objj.close();
				obj1.set_real_values(a,b);
				
				
			/**********************************************************************/
			
			
			
			/*CODE to try again Until User Entered The same id and password*/
			
			while(obj1.check()!=0){
				system("CLS");
				cout<<"\n\n\n\n\n\n\t\tLogin ID\t";
				getline(cin, log);
				obj1.set_id(log);
				cout<<"\t\tPassword\t";
				getline(cin,pass);
				obj1.set_password(pass);
				for (int i=0;i<=5;i++){
					cout<<"\xdb\xdb\xdb\xdb";
					Sleep(500);
					cout<<"\xdb\xdb\xdb\xdb";
				}
			}
			/***************************************************************/
			
			//if user enter correct id then the remaining code will execute
			///////////////////////////////////////////////////////////////
			char ch;
			int num;
			do
			{
				system("cls");
				cout<<"\n\n\n\tACTION MENU";
				cout<<"\n\n\t01. NEW ACCOUNT";
				cout<<"\n\n\t02. COMPLETE ACCOUNT HOLDERS LIST";
				cout<<"\n\n\t06. CLOSE AN ACCOUNT";
				cout<<"\n\n\t08. EXIT";
				cout<<"\n\n\tSelect Your Option (1-8) ";
				cin>>ch;
				system("cls");   //Clear The Screen
				switch(ch)
				{
				case '1':
					write_acc();
					break;
				case '2':
					display_all();
					break;
				case '3':
					cout<<"\n\n\tEnter The Account Number : "; cin>>num;
					delete_acc(num);
					break;
				 case '4':
					cout<<"\n\n\tThanks For Visiting Our Bank!";
					break;
				 default :cout<<"\a";
				}
				cin.ignore();
				cin.get();
				}while(ch!='8');
            	break;
            }
            
            case 2:
            	{
            		// checking wether the user Enter correct Id or not
			///////////////////////////////////////////////////
				string log;
				string pass;
				login obj1;
				cout<<"\n\n\n\n\n\n\t\tLogin ID\t";
				getline(cin, log);
				obj1.set_id(log);
				cout<<"\t\tPassword\t";
				getline(cin,pass);
				obj1.set_password(pass);	
				for (int i=0;i<=5;i++){
					cout<<"\xdb\xdb\xdb\xdb";
					Sleep(500);
					cout<<"\xdb\xdb\xdb\xdb";
				}
				
			/*********************************************************************/	
				/*variables to store id and password from file*/
				/*stroing id in a and password in b*/
				
				ifstream objj;
				objj.open("employee.txt");
				string a;
				string b;
				getline (objj, a);
				getline (objj, b);
				objj.close();
				obj1.set_real_values(a,b);
				
				
			/**********************************************************************/
			
			
			
			/*CODE to try again Until User Entered The same id and password*/
			
			while(obj1.check()!=0){
				system("CLS");
				cout<<"\n\n\n\n\n\n\t\tLogin ID\t";
				getline(cin, log);
				obj1.set_id(log);
				cout<<"\t\tPassword\t";
				getline(cin,pass);
				obj1.set_password(pass);
				for (int i=0;i<=5;i++){
					cout<<"\xdb\xdb\xdb\xdb";
					Sleep(500);
					cout<<"\xdb\xdb\xdb\xdb";
				}
			}
			cout<<"\nSuccessfully logged into employee";
			Sleep(1000);
			/***************************************************************/
			
			//if user enter correct id then the remaining code will execute
			///////////////////////////////////////////////////////////////
			char ch;
			int num;
			do
			{
				system("cls");
				cout<<"\n\n\n\tACTION MENU";
				cout<<"\n\n\t01. NEW ACCOUNT";
				cout<<"\n\n\t02. DEPOSIT";
				cout<<"\n\n\t03. WITHDRAW";
				cout<<"\n\n\t04. BALANCE ENQUIRY";
				cout<<"\n\n\t05. MODIFY AN ACCOUNT";
				cout<<"\n\n\t06. EXIT";
				cout<<"\n\n\tSelect Your Option (1-8) ";
				cin>>ch;
				system("cls");   //Clear The Screen
				switch(ch)
				{
				case '1':
					write_acc();
					break;
				case '2':
					cout<<"\n\n\tEnter The Account Number : "; cin>>num;
					dep_withdraw(num, 1);
					break;
				case '3':
					cout<<"\n\n\tEnter The Account Number : "; cin>>num;
					dep_withdraw(num, 2);
					break;
				case '4': 
					cout<<"\n\n\tEnter The Account Number : "; cin>>num;
					display_sp(num);
					break;
				 case '5':
					cout<<"\n\n\tEnter The Account Number : "; cin>>num;
					modify_acc(num);
					break;
				 case '6':
					cout<<"\n\n\tThanks For Visiting Our Bank!";
					break;
				 default :cout<<"\a";
				}
				cin.ignore();
				cin.get();
				}while(ch!='8');
            	break;
            }
				}
		

}

//function to write record in binary file

void write_acc()
{
    manager ac;
    ofstream x;
    x.open("info.dat",ios::binary|ios::app);
    ac.create_acc();
    x.write(reinterpret_cast<char *> (&ac), sizeof(manager));
    x.close();
}


//function to display account details given by user
void display_sp(int n)  
{
    manager ac;
    bool flag=false;
    ifstream x;
    x.open("info.dat",ios::binary);
    if(!x)
    {
        cout<<"File could not be opened!! Press any Key to exit...";
        return;
    }
    cout<<"\nBALANCE DETAILS\n";

        while(x.read(reinterpret_cast<char *> (&ac), sizeof(manager)))
    {
        if(ac.retano()==n)
        {
            ac.show_acc();
            flag=true;
        }
    }
    x.close();
    if(flag==false)
        cout<<"\n\nAccount number does not exist";
}
//function to modify record of file
void modify_acc(int n)
{
    bool found=false;
    employee ac;
    fstream x;
    x.open("info.dat",ios::binary|ios::in|ios::out);
    if(!x)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    while(!x.eof() && found==false)
    {
        x.read(reinterpret_cast<char *> (&ac), sizeof(employee));
        if(ac.retano()==n)
        {
            ac.show_acc();
            cout<<"\n\nEnter The New Details of account"<<endl;
            ac.modify();
            int pos=(-1)*static_cast<int>(sizeof(employee));
            x.seekp(pos,ios::cur);
            x.write(reinterpret_cast<char *> (&ac), sizeof(employee));
            cout<<"\n\n\t Record Updated";
            found=true;
          }
    }
    x.close();
    if(found==false)
        cout<<"\n\n Record Not Found ";
}
// function to desposit/withdraw amount for given account
void dep_withdraw(int n, int option)
{
    int amt;
    bool found=false;
    employee ac;
    fstream x;
    x.open("info.dat", ios::binary|ios::in|ios::out);
    if(!x)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    while(!x.eof() && found==false)
    {
        x.read(reinterpret_cast<char *> (&ac), sizeof(employee));
        if(ac.retano()==n)
        {
            ac.show_acc();
            if(option==1)
            {
                cout<<"\n\n\tTO DEPOSITE AMOUNT ";
                cout<<"\n\nEnter The amount to be deposited";
                cin>>amt;
                ac.adep(amt);
            }
            if(option==2)
            {
                cout<<"\n\n\tTO WITHDRAW AMOUNT ";
                cout<<"\n\nEnter The amount to be withdraw";
                cin>>amt;
                int bal=ac.retbal()-amt;
                if((bal<500 && ac.qtype()=='S') || (bal<1000 && ac.qtype()=='C'))
                    cout<<"Insufficience balance";
                else
                    ac.draw(amt);
            }
            int pos=(-1)*static_cast<int>(sizeof(ac));
            x.seekp(pos,ios::cur);
            x.write(reinterpret_cast<char *> (&ac), sizeof(employee));
            cout<<"\n\n\t Record Updated";
            found=true;
           }
         }
    x.close();
    if(found==false)
        cout<<"\n\n Record Not Found ";
}
//function to display all account details
void display_all()
{
    manager ac;
    ifstream x;
    x.open("info.dat",ios::binary);
    if(!x)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout<<"====================================================\n";
    cout<<"A/c no.      NAME           Type  Balance\n";
    cout<<"====================================================\n";
    while(x.read(reinterpret_cast<char *> (&ac), sizeof(manager)))
    {
        ac.report();
    }
    x.close();
}
//function to delete record of file    
void delete_acc(int n)
{
    manager ac;
    ifstream x;
    ofstream y;
    x.open("info.dat",ios::binary);
    if(!x)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    y.open("Temp.dat",ios::binary);
    x.seekg(0,ios::beg);
    while(x.read(reinterpret_cast<char *> (&ac), sizeof(manager)))
    {
        if(ac.retano()!=n)
        {
            y.write(reinterpret_cast<char *> (&ac), sizeof(manager));
        }
    }
    x.close();
    y.close();
    remove("info.dat");
    rename("Temp.dat","info.dat");
    cout<<"\n\n\tRecord Deleted ..";
}
Untitled3.cpp
Displaying Untitled3.cpp.