/*
*
*
*
Author Anil soni & farhan Hussain
*
*
*
*/



#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include<string>
#include<ctime>

using namespace std;
#ifdef _WIN32
#include<windows.h>
        #include<conio.h>
        #define clear system("cls
    #ifdef _WIN64
        #include<windows.h>
        #include<conio.h>
        #define clear system("cls");
    #endif // _WIN64
#elif __linux
    #include<unistd.h>
    #include"conio.h"
    #define clear cout << "\x1b[2J\x1b[1;1H" << flush;
           //__linux
#elif __Unix
    #include<unistd.h>
    #include"conio.h"
    #define clear anil
           //__Unix
#elif __APPLE__
    #include<condition_variable>
#endif // _WIN32


string username,type;
void Staff();
void customer();
class account
{
    public:

	int acno;
	char name[20];
	int deposit;
	char type;
	char password[30];


	void create_account();	//function to get data from user
	void show_account() const;	//function to show data on screen
	void modify();	//function to add new data
	void dep(int);	//function to accept amount and add to balance amount
	void draw(int);	//function to accept amount and subtract from balance amount
	void report() const;	//function to show data in tabular format
	int retacno() const;	//function to return account number
	int retdeposit() const;	//function to return balance amount
	char rettype() const;	//function to return type of account



};         //class ends here

void login()
{
    clear

    cout<<"\n\n\n\n\n\n\n\n\n\n\tPress S for Staff Login or Press C for Customer Login : ";
    int a=getch();
    if(toupper(a)== 'S')
    {
        type = "STAFF";
    }
    else if(toupper(a)=='C')
    {
        type = "USER";
    }
    else if(a == 27)
    {
        exit(0);
    }
    else
    {

        cout<<"\a";
        login();
    }
    logins :
    clear
        string password;

    cout<<"\n\n\n\n\n\n\n\t\t\tEnter username  : ";
        cin>>username;
        cout<<"\n\t\t\tEnter passwword : ";
        cin>>password;


	        string userAndPass = username + " " + password + " " + type; // Search pattern

	        int offset;

	        string line;

	        ifstream usersFile;

	        usersFile.open ("users.txt");


bool found = false;

	if(usersFile.is_open()) {

	    while(getline(usersFile,line) && !found) {

	        if (line.compare(userAndPass) == 0) { //match strings exactly!

	            found = true; // found is true => break loop

	        }

	    }
	    usersFile.close(); //close the file before recursivly opening it again later

	    if(found) {

	        if(type=="USER")
            {
                customer();
            }
            else if(type=="STAFF")
            {
                Staff();
            }

	    }

	    else {

	        cout << "\n\n\t\tUsername and/or password incorrect!\n";
            #ifdef __linux
            sleep(1);
            #elif _WIN32
            Sleep(2000);
            #endif // _WIN32
	        goto logins; //ok we didn't find them, lets redue this!

	    }

	}

	            usersFile.close();




	    }



string month(int a)
{
    string month_name[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    while(a)
    {
        return month_name[a-1];
    }
}

void Title()
{
    time_t now = time(0);

   tm *ltm = localtime(&now);

    int i;
    clear
    for(i=0; i<=79; i++)
    {
        cout<<"_";
    }

cout<<"\n\t\t\t"<<"System of Banking Process\n"<<endl;
if(type == "STAFF")
{
cout<<"Username : "<<username<<"\t\t"<<"Staff"<<"\t\t\t\t"<<month(1+ltm ->tm_mon)<<" "<< ltm->tm_mday<< " "<< 1900 +ltm->tm_year<<endl;
}
else
{
    cout<<"Username : "<<username<<"\t\t"<<"User"<<"\t\t\t\t"<<month(1+ltm ->tm_mon)<<" "<< ltm->tm_mday<< " "<< 1900 +ltm->tm_year<<endl;
}
for(i=0; i<=79; i++)
    {
        cout<<"_";
    }

}
void account::create_account()
{
    bool flag;
        Title();

    cout<<"\nEnter The Account No. : ";
	do{
	cin>>acno; }while(acno<10000);
	cout<<"\n\nEnter The Name of The account Holder : ";
	cin.ignore();
	cin.getline(name,30);
	cout<<"Enter password : ";

	cin.getline(password,30);
	do{
	cout<<"\nEnter Type of The account (C/S) : ";
	cin>>type;
	type=toupper(type);
	if(type == 'S')
    {
        flag = false;
    }
    else if(type == 'C')
    {
        flag = false;
    }
    else
    { flag = true;
	}}while(flag);
	cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	cin>>deposit;
	cout<<"\n\n\nAccount Created..";
	//create_login();
}





void account::show_account() const
{

	cout<<"\nAccount No. : "<<acno;
	cout<<"\nPassword  : "<<password;
	cout<<"\nAccount Holder Name : ";
	cout<<name;
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<deposit;
}


void account::modify()
{
    Title();
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,30);
	cout<<"\nPassword  : ";
	cin.ignore();
	cin.getline(password,30);
	cout<<"\nModify Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nModify Balance amount : ";
	cin>>deposit;
}


void account::dep(int x)
{

	deposit+=x;
}

void account::draw(int x)
{
	deposit-=x;
}

void account::report() const
{
    cout.setf(ios::left);
	//cout<<setw(10)<<acno<<setw(10)<<name<<"\t\t"<<setw(1)<<type<<setw(6)<<" "<<deposit<<endl;
    cout<<"  "<<setw(7)<<acno<<"   "<<setw(10)<<name<<"   "<< setw(10)<< password <<"   "<< setw(1)<<type<<"     " <<setw(6)<<deposit<<endl;
}


int account::retacno() const
{
	return acno;
}

int account::retdeposit() const
{
	return deposit;
}

char account::rettype() const
{
	return type;
}


void write_account();	//function to write record in binary file
void display_sp(int);	//function to display account details given by user
void modify_account(int);	//function to modify record of file
void delete_account(int);	//function to delete record of file
void display_all();		//function to display all account details
void deposit_withdraw(int, int); // function to desposit/withdraw amount for given account
void intro();	//introductory screen function





void customer()
{
    char ch;
	int num;
    do
	{

Title();

        cout<<"\n\n\t01. DEPOSIT AMOUNT";
		cout<<"\n\n\t02. WITHDRAW AMOUNT";
		cout<<"\n\n\t03. BALANCE ENQUIRY";

		cout<<"\n\n\t04. LOGOUT";
		cout<<"\n\n\t05. EXIT";
		cout<<"\n\n\tSelect Your Option (1-5) ";
		char a=getch();
		switch(a)
		{
		case '1':
			Title();
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;

		case '2':
		    Title();
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '3':
		    Title();
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;

		 case '4':
		     Title();
			cout<<"Are you sure to Logout : [Y/N]";
                if(getch()=='y')
                {
                    exit(0);
                }
            break ;

		case '5':
			exit(0);
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
    }while(ch!='5');

}
void Staff()
{clear

 char ch;
	int num;
    do
	{

Title();

		cout<<"\n\n\t01. NEW ACCOUNT";
		cout<<"\n\n\t02. DEPOSIT AMOUNT";
		cout<<"\n\n\t03. WITHDRAW AMOUNT";
		cout<<"\n\n\t04. BALANCE ENQUIRY";
		cout<<"\n\n\t05. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t06. CLOSE AN ACCOUNT";
		cout<<"\n\n\t07. MODIFY AN ACCOUNT";
		cout<<"\n\n\t08. EXIT";
		cout<<"\n\n\tSelect Your Option (1-8) ";
		char a=getch();
		switch(a)
		{
		case '1':
			write_account();
			break;
		case '2':
		    Title();
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
		    Title();
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4':
		    Title();
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
		case '5':

			display_all();
			break;
		case '6':
		    Title();
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;
		 case '7':
		     Title();
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			modify_account(num);
			break;
		 case '8':
		     Title();
			cout<<"\n\n\n\n\n\tThanks for using bank managemnt system\n\n\n\n\n\n\n";
			exit(0);
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
    }while(ch!='8');


}



//***************************************************************
//    	function to write in file
//****************************************************************

void write_account()
{
    Title();
	account ac;
	ofstream outFile;
	ofstream userfile;
	outFile.open("account.txt",ios::app);
	userfile.open("users.txt",ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
    outFile.close();
    userfile<< ac.name <<" "<< ac.password << " "<< "USER"<<endl;
    userfile.close();
}

//***************************************************************
//    	function to read specific record from file
//****************************************************************

void display_sp(int n)
{

	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.txt");
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";
    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=true;
		}
	}
    inFile.close();

	if(flag==false)
		cout<<"\n\nAccount number does not exist";
   //getch();
}


//***************************************************************
//    	function to modify record of file
//****************************************************************

void modify_account(int n)
{
    Title();
	bool found=false;
	account ac;
	fstream File;
    File.open("account.txt");
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
		    File.write(reinterpret_cast<char *> (&ac), sizeof(account));
		    cout<<"\n\n\t Record Updated";
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}

//***************************************************************
//    	function to delete record of file
//****************************************************************


void delete_account(int n)
{
    Title();
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.txt");
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat");
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
    inFile.close();
	outFile.close();
	remove("account.txt");
	rename("Temp.dat","account.txt");
	cout<<"\n\n\tRecord Deleted ..";
}

//***************************************************************
//    	function to display all accounts deposit list
//****************************************************************

void display_all()
{
    Title();
	account ac;
	ifstream inFile;
	inFile.open("account.txt");
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<" A/c no.   NAME        PASSWORD     Type    Balance\n";
	cout<<"====================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();


}

//***************************************************************
//    	function to deposit and withdraw amounts
//****************************************************************

void deposit_withdraw(int n, int option)
{
    Title();
	int amt;
	bool found=false;
	account ac;
	fstream File;
    File.open("account.txt");
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited";
				cin>>amt;
				ac.dep(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
		      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}


//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{


    char wlcm='_';
    cout<<"\n\n\t\t\t System of Banking Process \n\n";
    cout<<"\t\t\t";for(int i=0; i<27; i++)
        {
            cout<<wlcm;
        }
    cout<<"\n\n\n\n\t\t\t\n";
    cout<<"\t\t\t/*\tCreated By\t *\\|| \n ";
    cout<<"\t\t\t";for(int i=0; i<27; i++)
    {
        cout<<wlcm;
    }
    cout<<"\n\n\t\t\t\tAnil Soni\t  \n\n";
    cout<<"\t\t\t\tFarhan hussain   \n";

    cout<<"\n\n\n\n\t\t\tPress any key to continue....";
getch();
}

int main()
{
    intro();
    clear
    login();



	return 0;
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************
