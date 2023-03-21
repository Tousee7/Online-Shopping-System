#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<conio.h>
#include<cstdio>
using namespace std;

class User{
	protected:
	    string firstName;
	    string lastName;
	    string fullName;
	    string email;
	    string password;
	    string phoneNumber;
	    string address;
	public:
		User(){
			//default constructor
		}
		User(string firstName,string lastName,string email,string password,string phoneNumber,string address){
			this->address=firstName;
	        this->lastName=lastName;
	        fullName=firstName+" "+lastName;
	        this->email=email;
	        this->password=password;
	        this->phoneNumber=phoneNumber;
	        this->address=address;
		}
		string get_name(){
			return fullName;
		}
		string get_email(){
			return email;
		}
		string get_password(){
			return password;
		}
		string get_phoneNumber(){
			return phoneNumber;
		}
		string get_address(){
			return address;
		}
		void set_name(string fullName,string lastName){
			this->firstName=firstName;
			this->lastName=lastName;
			fullName=firstName+" "+lastName;
		}
		void set_email(string email){
			this->email=email;
		}
		void set_password(string password){
			this->password=password;
		}
		void set_phoneNumber(string phoneNumber){
			this->phoneNumber=phoneNumber;
		}
};

//functions
void login_signup();
void login();
void signup();
void accountInfo(User);
void login_signup(){
	system("cls");
	int choice;
	cout << "1.Login if you already have an account.\n2.Sign up to create a new account.\n";
	cin >> choice;
	if(choice==1){
		login();
	}
	else if(choice==2){
		signup();
	}
	else{
		system("cls");
		cout << "Wrong choice entered.Please try again\n";
		login_signup();
	}
}
void login(){
	int flag;
	system("cls");
	string email,pass;
	fflush(stdin);
	cout << "Enter your email = ";
	cin >> email;
	cout << "Enter your password = ";
	cin >> pass;
	User objUser;
	fstream file;
	file.open("userDetails.dat",ios::in | ios::binary);
	if(!file){
		cout<<"Error while opening the file";
	}
	else{
		User objUser;
		file.read((char *)&objUser,sizeof(objUser));
		while(!file.eof()){
			if((email==objUser.get_email()) && (pass==objUser.get_password())){
				flag=1;
				break;
			}
			else{
				flag=-1;
				file.read((char *)&objUser,sizeof(objUser));
				continue;
			}
		}
		file.close();
		if(flag<0){
			cout << "Incorrect email or password.Press any key to try again.\n";
			getch();
			login();
		}
		else{
			cout << "Account logged in successfully.Press any key to proceed.\n";
		    getch();
		    accountInfo(objUser);
		}
	}
}
void accountInfo(User objUser){
	system("cls");
	cout << "Name = " << objUser.get_name() << endl;
	cout << "Email = " << objUser.get_email() << endl;
	cout << "Password = " << objUser.get_password() << endl;
	cout << "Phone Number = " << objUser.get_phoneNumber() << endl;
	cout << "Address = " << objUser.get_address() << endl;
	cout << "Press any key to proceed.\n";
	getch();
	login_signup();
}
void signup(){
	fstream file;
	string fname,lname,email,password,phone,address;
	system("cls");
	cout << "Enter first name = ";
	cin >> fname;
	fflush(stdin);
	cout << "Enter last name = ";
	cin >> lname;
	fflush(stdin);
	cout << "Enter email address = ";
	cin >> email;
	fflush(stdin);
	cout << "Enter password = ";
	cin >> password;
	fflush(stdin);
	cout << "Enter phone number = ";
	cin >> phone;
	fflush(stdin);
	cout << "Enter home address = ";
	cin >> address;
	fflush(stdin);
	User objUser(fname,lname,email,password,phone,address);
	file.open("userDetails.dat",ios::app | ios::binary);
	if(!file){
		cout<<"Error while opening the file";
	}
	else{
		file.write((char *)&objUser,sizeof(objUser));
		file.close();
		cout << "Account has been created successfully.Press any key to login.\n";
        getch();
        login_signup();
	}
}
int main(){
	login_signup();
	return 0;
}
