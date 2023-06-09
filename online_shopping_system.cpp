#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<conio.h>
#include<cstdio>
#include<vector>
#include<stdlib.h>
#include <ctime>
#include <cstdlib>
using namespace std;

string date = "16 ";
string month = " May";

//classes
class User;
class Cart;
class Buyer;
class Seller;
class Product;
class Electronic;
class Clothing;
class Beauty;
class allProducts;
class Review;

//functions
void login_signup();
void login();
void login_Seller(string email,string pass);
void login_for_seller(string email,Seller &objS);
void signup();
bool check_email_seller(string str);
void accountInfo(User);
void mainmenu_Seller(Seller &objS);
void mainmenu_Buyer(Buyer &objB);
void get_products(Seller &obj);
void update_seller_info(Seller &objS);
void update_buyer_info(Buyer &objB);
void buy(Buyer &objB);
string genrateString();
void reset_ID_Products(int flag,int dID,string email,allProducts &objall); //this function is reseting Product id for all type of products
int get_dID(string str);  //this function gets ID of product to be deleted in integer


istream& operator>>(istream &input,Seller &obj);
istream& operator>>(istream &input,Electronic &obj);

class Product{
	friend void buy(Buyer &objB);
	friend void reset_ID_Products(int flag,int dID,string email,allProducts &objall);
	protected:
		string ProductID;
		string pname;
		double pprice;
		string pdescription;
		int stock;
		bool availability;
		string storeName;
		int deliveryTime;
		void set_pname(string pname){
			this->pname=pname;
		}
		void set_pprice(double pprice){
			this->pprice=pprice;
		}
		void set_pdescription(string pdescription){
			this->pdescription=pdescription;
		}
		void set_stock(int stock){
			this->stock=stock;
		}
		void set_storeName(string storeName){
			this->storeName=storeName;
		}
		void set_deliveryTime(int deliveryTime){
			this->deliveryTime=deliveryTime;
		}
	public:
		Product(){}
		Product(string pname,double pprice,string pdescription,int stock,string storeName,int deliveryTime){
			this->pname=pname;
			this->pprice=pprice;
			this->pdescription=pdescription;
			this->stock=stock;
			this->storeName=storeName;
			this->deliveryTime=deliveryTime;
			if(stock>0){
				availability=1;
			}
		}
		string get_ProductID(){
			return ProductID;
		}
		string get_pname(){
			return pname;
		}
		double get_pprice(){
			return pprice;
		}
		string get_pdescription(){
			return pdescription;
		}
		bool get_availability(){
			return availability;
		}
		string get_storeName(){
			return storeName;
		}
		int get_deliveryTime(){
			return deliveryTime;
		}
		void display(){
			cout << "Product ID = " << ProductID << endl;
			cout << "Product name = " << pname << endl;
			cout << "Product price = " << pprice << endl;
			cout << "Product description = " << pdescription << endl;
			cout << "Product stock = " << stock << endl;
			cout << "Product store name = " << storeName << endl;
			cout << "Product delivery time = " << deliveryTime << endl;
		}
		void write_product(){}
};

class Electronic : public Product{
	friend class Seller;
	friend void addProduct();
	friend void get_products(Seller &obj);
	friend istream& operator>>(istream &input,Electronic &obj);
	friend class allProducts;
	friend void buy(Buyer &objB);
	
	private:
		string brand;
		string warranty;
		string model;
		string color;
		void set_brand(string brand){
			this->brand=brand;
		}
		void set_warranty(string warranty){
			this->warranty=warranty;
		}
		void set_model(string model){
			this->model=model;
		}
		void set_color(string color){
			this->color=color;
		}
	public:
		Electronic(){}
		Electronic(string brand,string warranty,string model,string color,string pname,double pprice,string pdescription,int stock,string storeName,int deliveryTime):Product(pname,pprice,pdescription,stock,storeName,deliveryTime){
			this->brand=brand;
			this->warranty=warranty;
			this->model=model;
			this->color=color;
		}
		string get_brand(){
			return brand;
		}
		string get_warranty(){
			return warranty;
		}
		string get_model(){
			return model;
		}
		string get_color(){
			return color;
		}
		void display(){
			cout << "Product name = " << pname << endl;
			cout << "Product price = " << pprice << endl;
			cout << "Product description = " << pdescription << endl;
			cout << "Product stock = " << stock << endl;
			cout << "Product store name = " << storeName << endl;
			cout << "Product delivery time = " << deliveryTime << endl;
			cout << "Product brand = " << brand << endl;
			cout << "Product warranty = " << warranty << endl;
			cout << "Product model = " << model << endl;
			cout << "Product color = " << color << endl;
		}
		
		void write_product(){
			fstream file;
			file.open("Electronic.txt",ios::app);
			if(!file){
		            cout<<"Error while opening the file";
	            }
	            else{
	            	file << ProductID << endl;
	            	file << pname << endl;
	            	file << pprice << endl;
	            	file << pdescription << endl;
	            	file << stock << endl;
	            	file << storeName << endl;
	            	file << deliveryTime << endl;
	            	file << brand << endl;
	            	file << warranty << endl;
	            	file << model << endl;
	            	file << color << endl;
				}
				file.close();
		}
		void update_product(){
			int i;
			fstream file;
			file.open("Electronic.txt",ios::in);
			vector<Electronic>tempEE;
			Electronic temp;
			string line;
			while(getline(file,line)){
			temp.ProductID=line;
			
			getline(file,line);
			temp.pname=line;
			
			getline(file,line);
			temp.pprice=stod(line);
			
			getline(file,line);
			temp.pdescription=line;
			
			getline(file,line);
			temp.stock=stoi(line);
			
			getline(file,line);
			temp.storeName=line;
			
			getline(file,line);
			temp.deliveryTime=stoi(line);
			
			getline(file,line);
			temp.brand=line;
			
			getline(file,line);
			temp.warranty=line;
			
			getline(file,line);
			temp.model=line;
			
			getline(file,line);
			temp.color=line;
			
			if(temp.stock>0){
				temp.availability=1;
			}
			else{
				temp.availability=0;
			}
			tempEE.push_back(temp);
			}
			file.close();
			file.open("Electronic.txt",ios::out);
			if(!file){
		            cout<<"Error while opening the file";
	            }
	            else{
	            	for(i=0;i<tempEE.size();i++){
	            		if(ProductID==tempEE[i].ProductID){
	            			write_product();
						}
						else{
							tempEE[i].write_product();
						}
	                }
				}
			file.close();
		}
};

class Clothing : public Product{
	friend class Seller;
	friend void addProduct();
	friend void get_products(Seller &obj);
	friend istream& operator>>(istream &input,Clothing &obj);
	friend class allProducts;
	
	private:
		string ageGroup;
		int size;
		string fabric;
		string color;
		void set_ageGroup(string ageGroup){
			this->ageGroup=ageGroup;
		}
		void set_size(int size){
			this->size=size;
		}
		void set_fabric(string fabric){
			this->fabric=fabric;
		}
		void set_color(string color){
			this->color=color;
		}
	public:
		Clothing(){}
		Clothing(string ageGroup,int size,string fabric,string color,string pname,double pprice,string pdescription,int stock,string storeName,int deliveryTime):Product(pname,pprice,pdescription,stock,storeName,deliveryTime){
			this->ageGroup=ageGroup;
			this->size=size;
			this->fabric=fabric;
			this->color=color;
		}
		string get_ageGroup(){
			return ageGroup;
		}
		int get_size(){
			return size;
		}
		string get_fabric(){
			return fabric;
		}
		string get_color(){
			return color;
		}
		void display(){
			cout << "Product name = " << pname << endl;
			cout << "Product price = " << pprice << endl;
			cout << "Product description = " << pdescription << endl;
			cout << "Product stock = " << stock << endl;
			cout << "Product store name = " << storeName << endl;
			cout << "Product delivery time = " << deliveryTime << endl;
			cout << "Product age group = " << ageGroup << endl;
			cout << "Product size = " << size << endl;
			cout << "Product fabric = " << fabric << endl;
			cout << "Product color = " << color << endl;
		}
		void write_product(){
			fstream file;
			file.open("Clothing.txt",ios::app);
			if(!file){
		            cout<<"Error while opening the file";
	            }
	            else{
	            	file << ProductID << endl;
	            	file << pname << endl;
	            	file << pprice << endl;
	            	file << pdescription << endl;
	            	file << stock << endl;
	            	file << storeName << endl;
	            	file << deliveryTime << endl;
	            	file << ageGroup << endl;
	            	file << size << endl;
	            	file << fabric << endl;
	            	file << color << endl;
				}
				file.close();
		}
		void update_product(){
			int i;
			fstream file;
			file.open("Clothing.txt",ios::in);
			vector<Clothing>tempCC;
			Clothing temp;
			string line;
			while(getline(file,line)){
			temp.ProductID=line;
			
			getline(file,line);
			temp.pname=line;
			
			getline(file,line);
			temp.pprice=stod(line);
			
			getline(file,line);
			temp.pdescription=line;
			
			getline(file,line);
			temp.stock=stoi(line);
			
			getline(file,line);
			temp.storeName=line;
			
			getline(file,line);
			temp.deliveryTime=stoi(line);
			
			getline(file,line);
			temp.ageGroup=line;
			
			getline(file,line);
			temp.size=stoi(line);
			
			getline(file,line);
			temp.fabric=line;
			
			getline(file,line);
			temp.color=line;
			
			if(temp.stock>0){
				temp.availability=1;
			}
			else{
				temp.availability=0;
			}
			tempCC.push_back(temp);
			}
			file.close();
			file.open("Clothing.txt",ios::out);
			if(!file){
		            cout<<"Error while opening the file";
	            }
	            else{
	            	for(i=0;i<tempCC.size();i++){
	            		if(ProductID==tempCC[i].ProductID){
	            			write_product();
						}
						else{
							tempCC[i].write_product();
						}
	                }
				}
			file.close();
		}
};

class Beauty : public Product{
	friend class Seller;
	friend void addProduct();
	friend void get_products(Seller &obj);
	friend istream& operator>>(istream &input,Beauty &obj);
	friend class allProducts;
	
	private:
		string brand;
		string gender;
		string type;
		void set_brand(string brand){
			this->brand=brand;
		}
		void set_gender(string gender){
			this->gender=gender;
		}
		void set_type(string type){
			this->type=type;
		}
	public:
		Beauty(){}
		Beauty(string brand,string gender,string type,string pname,double pprice,string pdescription,int stock,string storeName,int deliveryTime):Product(pname,pprice,pdescription,stock,storeName,deliveryTime){
			this->brand=brand;
			this->gender=gender;
			this->type=type;
		}
		string get_brand(){
			return brand;
		}
		string get_gender(){
			return gender;
		}
		string get_type(){
			return type;
		}
		void display(){
			cout << "Product name = " << pname << endl;
			cout << "Product price = " << pprice << endl;
			cout << "Product description = " << pdescription << endl;
			cout << "Product stock = " << stock << endl;
			cout << "Product store name = " << storeName << endl;
			cout << "Product delivery time = " << deliveryTime << endl;
			cout << "Product brand = " << brand << endl;
			cout << "Product gender = " << gender << endl;
			cout << "Product type = " << type << endl;
		}
		void write_product(){
			fstream file;
			file.open("Beauty.txt",ios::app);
			if(!file){
		            cout<<"Error while opening the file";
	            }
	            else{
	            	file << ProductID << endl;
	            	file << pname << endl;
	            	file << pprice << endl;
	            	file << pdescription << endl;
	            	file << stock << endl;
	            	file << storeName << endl;
	            	file << deliveryTime << endl;
	            	file << brand << endl;
	            	file << gender << endl;
	            	file << type << endl;
				}
				file.close();
		}
		
		void update_product(){
			int i;
			fstream file;
			file.open("Beauty.txt",ios::in);
			vector<Beauty>tempBB;
			Beauty temp;
			string line;
			while(getline(file,line)){
			temp.ProductID=line;
			
			getline(file,line);
			temp.pname=line;
			
			getline(file,line);
			temp.pprice=stod(line);
			
			getline(file,line);
			temp.pdescription=line;
			
			getline(file,line);
			temp.stock=stoi(line);
			
			getline(file,line);
			temp.storeName=line;
			
			getline(file,line);
			temp.deliveryTime=stoi(line);
			
			getline(file,line);
			temp.brand=line;
			
			getline(file,line);
			temp.gender=line;
	
			getline(file,line);
			temp.type=line;
			
			if(temp.stock>0){
				temp.availability=1;
			}
			else{
				temp.availability=0;
			}
			tempBB.push_back(temp);
			}
			file.close();
			file.open("Beauty.txt",ios::out);
			if(!file){
		            cout<<"Error while opening the file";
	            }
	            else{
	            	for(i=0;i<tempBB.size();i++){
	            		if(ProductID==tempBB[i].ProductID){
	            			write_product();
						}
						else{
							tempBB[i].write_product();
						}
	                }
				}
			file.close();
		}
};

class allProducts{
	public:
		vector<Electronic> objE;
		vector<Clothing> objC;
		vector<Beauty> objB;
		
		void read_allProducts(){   //this function is reading all products in an object of class allProducts
		string line;
		Electronic tempE;
		Clothing tempC;
		Beauty tempB;
		fstream file;
		file.open("Electronic.txt",ios::in);
		while(getline(file,line)){
			tempE.ProductID=line;
			
			getline(file,line);
			tempE.pname=line;
			
			getline(file,line);
			tempE.pprice=stod(line);
			
			getline(file,line);
			tempE.pdescription=line;
			
			getline(file,line);
			tempE.stock=stoi(line);
			
			getline(file,line);
			tempE.storeName=line;
			
			getline(file,line);
			tempE.deliveryTime=stoi(line);
			
			getline(file,line);
			tempE.brand=line;
			
			getline(file,line);
			tempE.warranty=line;
			
			getline(file,line);
			tempE.model=line;
			
			getline(file,line);
			tempE.color=line;
			
			if(tempE.stock>0){
				tempE.availability=1;
			}
			else{
				tempE.availability=0;
			}
			objE.push_back(tempE);
		}
		file.close();
		file.open("Clothing.txt",ios::in);
		while(getline(file,line)){
			tempC.ProductID=line;
			
			getline(file,line);
			tempC.pname=line;
			
			getline(file,line);
			tempC.pprice=stod(line);
			
			getline(file,line);
			tempC.pdescription=line;
			
			getline(file,line);
			tempC.stock=stoi(line);
			
			getline(file,line);
			tempC.storeName=line;
			
			getline(file,line);
			tempC.deliveryTime=stoi(line);
			
			getline(file,line);
			tempC.ageGroup=line;
			
			getline(file,line);
			tempC.size=stoi(line);
			
			getline(file,line);
			tempC.fabric=line;
			
			getline(file,line);
			tempC.color=line;
			
			if(tempC.stock>0){
				tempC.availability=1;
			}
			else{
				tempC.availability=0;
			}
			objC.push_back(tempC);
		}
		file.close();
		file.open("Beauty.txt",ios::in);
		while(getline(file,line)){
			tempB.ProductID=line;
			
			getline(file,line);
			tempB.pname=line;
			
			getline(file,line);
			tempB.pprice=stod(line);
			
			getline(file,line);
			tempB.pdescription=line;
			
			getline(file,line);
			tempB.stock=stoi(line);
			
			getline(file,line);
			tempB.storeName=line;
			
			getline(file,line);
			tempB.deliveryTime=stoi(line);
			
			getline(file,line);
			tempB.brand=line;
			
			getline(file,line);
			tempB.gender=line;
	
			getline(file,line);
			tempB.type=line;
			
			if(tempB.stock>0){
				tempB.availability=1;
			}
			else{
				tempB.availability=0;
			}
			objB.push_back(tempB);
		}
		file.close();
	}
	
	
	void write_allProducts(){    //this function is writing all products from an object of class allProducts to all files of products
		    int i;
		    fstream file;
		    file.open("Electronic.txt",ios::out);
			    if(!file){
		                cout<<"Error while opening the file";
	                }
	            else{
	            	    for(i=0;i<objE.size();i++){
	            		    objE[i].write_product();
	                    }
				    }
		    file.close();
		    file.open("Clothing.txt",ios::out);
			    if(!file){
		                cout<<"Error while opening the file";
	                }
	            else{
	            	    for(i=0;i<objC.size();i++){
	            		    objC[i].write_product();
	                    }
				    }
		    file.close();
		    file.open("Beauty.txt",ios::out);
			    if(!file){
		                cout<<"Error while opening the file";
	                }
	            else{
	            	    for(i=0;i<objB.size();i++){
	            		    objB[i].write_product();
	                    }
				    }
		    file.close();
	}
};

class Review{
	private:
		string reviewerName;
		string comment;
		int rating;
	public:
		Review(){}
		Review(string reviewerName,string comment,int rating){
			this->reviewerName=reviewerName;
			this->comment=comment;
			this->rating=rating;
		}
		string get_reviewerName(){
			return reviewerName;
		}
		string get_comment(){
			return comment;
		}
		int get_rating(){
			return rating;
		}
		void set_reviewerName(string reviewerName){
			this->reviewerName=reviewerName;
		}
		void set_comment(string comment){
			this->comment=comment;
		}
		void set_rating(int rating){
			this->rating=rating;
		}
		void addReview(string n,string c){
			int rate;
			cout << "Rate this product out of 10 = ";
			cin >> rate;
			if(rate<0 || rate>10){
				addReview(n,c);
			}
			else{
				reviewerName=n;
				comment=c;
				rating=rate;
			}
		}
};

class Cart{
	friend void buy(Buyer &objB);
	private:
		string delDate;
		string orderDate;
		string orderNo;
		string trackingID;
		string payMethod;
		Product *pptr;
		string ProductID;
	public:
		Cart(){}
		Cart(string delDate,string orderDate,string orderNo,string trackingID,string payMehtod){
			this->delDate=delDate;
			this->orderDate=orderDate;
			this->orderNo=orderNo;
			this->trackingID=trackingID;
			this->payMethod=payMethod;
		}
		string get_ProductID(){
			return ProductID;
		}
		string get_delDate(){
			return delDate;
		}
		string get_orderDate(){
			return orderDate;
		}
		string get_orderNo(){
			return orderNo;
		}
		string get_trackingID(){
			return trackingID;
		}
		string get_payMethod(){
			return payMethod;
		}
		void set_delDate(string delDate){
			this->delDate=delDate;
		}
		void set_orderDate(string orderDate){
			this->orderDate=orderDate;
		}
		void set_orderNo(string orderNo){
			this->orderNo=orderNo;
		}
		void set_trackingID(string trackinID){
			this->trackingID=trackingID;
		}
		void set_payMethod(string payMethod){
			this->payMethod=payMethod;
		}
		void set_ProductID(string ProductID){
			this->ProductID=ProductID;
		}
		void display(){
			cout << "Order Date: " << get_orderDate() << endl;
			cout << "Delivery Date: " << get_delDate() << endl;
			cout << "Tracking ID: " << get_trackingID() << endl;
			cout << "Payment Method: " << get_payMethod() << endl;
		}
};

class User{
	protected:
	    string firstName;
	    string lastName;
	    string fullName;
	    string email;
	    string password;
	    string phoneNumber;
	    string address;
	    double balance;
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
		void set_firstName(string firstName){
			this->firstName=firstName;
		}
		void set_lastName(string lastName){
			this->lastName=lastName;
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
		void set_balance(double balance){
			this->balance=balance;
		}
		void set_address(string address){
			this->address=address;
		}
		void display(){
			system("cls");
	        cout << "First name = " << firstName << endl;
	        cout << "Last name = " << lastName << endl;
	        cout << "Email = " << email << endl;
	        cout << "Password = " << password << endl;
	        cout << "Phone Number = " << phoneNumber << endl;
	        cout << "Address = " << address << endl;
	        cout << "Balance = " << balance << endl;
		}
};

class Seller : public User{
	friend void buy(Buyer &objB);
	friend istream& operator>>(istream &input,Seller &obj);
	friend void get_products(Seller &obj);
	friend void signup();
	friend void update_seller_info(Seller &objS);
	friend void reset_ID_Products(int flag,int dID,string email,allProducts &objall);
	
	private:
		int noOfProduct;
		int noOfProductsold;
		double profit;
		allProducts objSellerP;
	public:
		void set_noOfProduct(int noOfProduct){
			this->noOfProduct=noOfProduct;
		}
		void set_noOfProductsold(int noOfProductsold){
			this->noOfProductsold=noOfProductsold;
		}
		void set_profit(double profit){
			this->profit=profit;
		}
		int get_noOfProduct(){
			return noOfProduct;
		}
		
		void write_Seller(){
	    fstream file;
	    file.open("Seller.txt",ios::app);
	    file << firstName << endl;
	    file << lastName << endl;
	    file << email << endl;
	    file << password << endl;
	    file << phoneNumber << endl;
	    file << address << endl;
	    file << noOfProduct << endl;
	    file << noOfProductsold << endl;
	    file << profit << endl;
	    file << balance << endl;
	    file.close();
        }
		
		void display(){
			User::display();
			cout << "Number of products = " << noOfProduct << endl;
			cout << "Number of products sold= " << noOfProductsold << endl;
			cout << "Profits = " << profit << endl;
		}
		void addProduct(){
			system("cls");
			int choice;
			cout << "Enter choice of product category to list\n1.Electronic\n2.Clothing\n3.Beauty\n";
			cin >> choice;
			if(choice==1){
				noOfProduct++;
				Electronic tempE;
				cin >> tempE;
				tempE.ProductID = email + to_string(noOfProduct);
				tempE.write_product();
				objSellerP.objE.push_back(tempE);
				update();
				cout << "Product added successsfully.Press any key to continue.";
				getch();
			}
			else if(choice==2){
				noOfProduct++;
				Clothing tempC;
				cin >> tempC;
				tempC.ProductID = email + to_string(noOfProduct);
				tempC.write_product();
				objSellerP.objC.push_back(tempC);
				update();
				cout << "Product added successsfully.Press any key to continue.";
				getch();
			}
			else if(choice==3){
				noOfProduct++;
				Beauty tempB;
				cin >> tempB;
				tempB.ProductID = email + to_string(noOfProduct);
				tempB.write_product();
				objSellerP.objB.push_back(tempB);
				update();
				cout << "Product added successsfully.Press any key to continue.";
				getch();
			}
			else{
				cout << "Entered wrong choice.Press any key to try again";
				getch();
				addProduct();
			}
		}
		
		void update(){
			fstream file;
			file.open("Seller.txt",ios::in);
			vector<Seller>tempSS;
			Seller tempS;
			string line;
			while(getline(file,line)){
		    tempS.set_firstName(line);
		
		    getline(file,line);
		    tempS.set_lastName(line);
		
		    getline(file,line);
		    tempS.set_email(line);
		
		    getline(file,line);
		    tempS.set_password(line);
		
		    getline(file,line);
		    tempS.set_phoneNumber(line);
		
		    getline(file,line);
		    tempS.set_address(line);
		
		    getline(file,line);
		    tempS.set_noOfProduct(stoi(line));
		
		    getline(file,line);
		    tempS.set_noOfProductsold(stoi(line));
		
		    getline(file,line);
		    tempS.set_profit(stod(line));
		
		   getline(file,line);
		   tempS.set_balance(stod(line));
		   
		   tempSS.push_back(tempS);
		}
		file.close();
		file.open("Seller.txt",ios::out);
		for(int i=0;i<tempSS.size();i++){
			if(email==tempSS[i].get_email()){
				write_Seller();
			}
			else{
				tempSS[i].write_Seller();
			}
		}
		}
		
	void display_seller_products(){
	int i;
	cout << "Press any key to continue" << endl;
	cout << "------------------Electronic Products------------------" << endl;
	for(i=0;i<objSellerP.objE.size();i++){
		objSellerP.objE[i].display();
		cout << endl;
	}
	cout << endl << endl;
	cout << "------------------Clothing Products------------------" << endl;
	for(i=0;i<objSellerP.objC.size();i++){
		objSellerP.objC[i].display();
		cout << endl;
	}
	cout << endl << endl;
	cout << "------------------Beauty Products------------------" << endl;
	for(i=0;i<objSellerP.objB.size();i++){
		objSellerP.objB[i].display();
		cout << endl;
	}
	getch();
    }
    
    void update_seller_products(){
    	system("cls");
    	int choice1,choice2,i;
    	cout << "Which type of product you want to update?\n1.Electronic\n2.Clothing\n3.Beauty\n";
    	cin >> choice1;
    	if(choice1==1){
    		Electronic tempE;
    		for(i=0;i<objSellerP.objE.size();i++){
    			cout << "-----------------Product " << i+1 << "-----------------" << endl;
    			objSellerP.objE[i].display();
    			cout << endl;
			}
			cout << "-------------------------------------------" << endl;
			cout << "Enter product number = ";
			cin >> choice2;
    		cout << "Enter new information for product\n";
    		cin >> tempE;
    		tempE.ProductID=objSellerP.objE[choice2-1].ProductID;
    		tempE.update_product();
    		objSellerP.objE[choice2-1]=tempE;
		}
		
		else if(choice1==2){
			Clothing tempC;
    		for(i=0;i<objSellerP.objC.size();i++){
    			cout << "-----------------Product " << i+1 << "-----------------" << endl;
    			objSellerP.objC[i].display();
    			cout << endl;
			}
			cout << "-------------------------------------------" << endl;
			cout << "Enter product number = ";
			cin >> choice2;
    		cout << "Enter new information for product\n";
    		cin >> tempC;
    		tempC.ProductID=objSellerP.objC[choice2-1].ProductID;
    		tempC.update_product();
    		objSellerP.objC[choice2-1]=tempC;
		}
		else if(choice1==3){
			Beauty tempB;
    		for(i=0;i<objSellerP.objB.size();i++){
    			cout << "-----------------Product " << i+1 << "-----------------" << endl;
    			objSellerP.objB[i].display();
    			cout << endl;
			}
			cout << "-------------------------------------------" << endl;
			cout << "Enter product number = ";
			cin >> choice2;
    		cout << "Enter new information for product\n";
    		cin >> tempB;
    		tempB.ProductID=objSellerP.objB[choice2-1].ProductID;
    		tempB.update_product();
    		objSellerP.objB[choice2-1]=tempB;
		}
	}
	
	void Delete(){  //this function is deleting specific product
		system("cls");
		allProducts objall;
		objall.read_allProducts();
		int dID;
    	int choice1,choice2,i;
    	cout << "Which type of product you want to delete?\n1.Electronic\n2.Clothing\n3.Beauty\n";
    	cin >> choice1;
    	if(choice1==1){
    		for(i=0;i<objSellerP.objE.size();i++){
    			cout << "-----------------Product " << i+1 << "-----------------" << endl;
    			objSellerP.objE[i].display();
    			cout << endl;
			}
			cout << "-------------------------------------------" << endl;
			cout << "Enter product number = ";
			cin >> choice2;
			dID = get_dID(objSellerP.objE[choice2-1].ProductID);
			//cout << dID << endl;
			reset_ID_Products(noOfProduct-dID,dID,email,objall);
			noOfProduct--;
			update();
			cout << "Product deleted successfully.Press any key to continue.";
			getch();
			login_Seller(email,password);
		}
		else if(choice1==2){
    		for(i=0;i<objSellerP.objC.size();i++){
    			cout << "-----------------Product " << i+1 << "-----------------" << endl;
    			objSellerP.objC[i].display();
    			cout << endl;
			}
			cout << "-------------------------------------------" << endl;
			cout << "Enter product number = ";
			cin >> choice2;
			dID = get_dID(objSellerP.objC[choice2-1].ProductID);
			reset_ID_Products(noOfProduct-dID,dID,email,objall);
			noOfProduct--;
			update();
			cout << "Product deleted successfully.Press any key to continue.";
			getch();
			login_Seller(email,password);
		}
		else if(choice1==3){
    		for(i=0;i<objSellerP.objB.size();i++){
    			cout << "-----------------Product " << i+1 << "-----------------" << endl;
    			objSellerP.objB[i].display();
    			cout << endl;
			}
			cout << "-------------------------------------------" << endl;
			cout << "Enter product number = ";
			cin >> choice2;
			dID = get_dID(objSellerP.objB[choice2-1].ProductID);
			reset_ID_Products(noOfProduct-dID,dID,email,objall);
			noOfProduct--;
			update();
			cout << "Product deleted successfully.Press any key to continue.";
			getch();
			login_Seller(email,password);
		}
	}
};

class Buyer : public User{
	friend void buy(Buyer &objB);
	friend void signup();
	friend void login();
	friend bool check_email_buyer(string str);
	friend void update_buyer_info(Buyer& objB);
	friend istream& operator>>(istream &input, Buyer &obj);
	private:
		int noOfProductsBought;
		vector<Cart> objCart;
	public:
		
		void set_noOfProductsBought(int noOfProductsBought){
			this->noOfProductsBought=noOfProductsBought;
		}
		
		void display(){
			User::display();
			cout << "Number of products bought= " << noOfProductsBought << endl;
		}
		
		void displayCart(){
			system("cls");
			for(int i=0; i<noOfProductsBought; i++){
				cout << "Order Date: " << objCart[i].get_orderDate() << endl;
				cout << "Delivery Date: " << objCart[i].get_delDate() << endl;
				cout << "Tracking ID: " << objCart[i].get_trackingID() << endl;
				cout << "Payment Method: " << objCart[i].get_payMethod() << endl;
			}
		}
		
		void write_Buyer(){
			fstream file;
			file.open("Buyer.txt",ios::app);
			file << firstName << endl;
			file << lastName << endl;
			file << email << endl;
			file << password << endl;
			file << phoneNumber << endl;
			file << address << endl;
			file << noOfProductsBought << endl;
			file << balance << endl;
			for(int i=0; i<noOfProductsBought; i++){
				file << objCart[i].get_ProductID() << endl;
				file << objCart[i].get_delDate() << endl;
				file << objCart[i].get_orderDate() << endl;
				file << objCart[i].get_orderNo() << endl;
				file << objCart[i].get_trackingID() << endl;
				file << objCart[i].get_payMethod() << endl;
			}
			file.close();
		}
		void update(){
			int counter;
			fstream file;
			file.open("Buyer.txt",ios::in);
			vector<Buyer>tempBB;
			Buyer tempB;
			string line;
			while(getline(file,line)){
		    tempB.set_firstName(line);
		
		    getline(file,line);
		    tempB.set_lastName(line);
		
		    getline(file,line);
		    tempB.set_email(line);
		
		    getline(file,line);
		    tempB.set_password(line);
		
		    getline(file,line);
		    tempB.set_phoneNumber(line);
		
		    getline(file,line);
		    tempB.set_address(line);
		
		    getline(file,line);
		    tempB.set_noOfProductsBought(stoi(line));
			counter=stoi(line);
			
		    getline(file,line);
		    tempB.set_balance(stod(line));
		    
		   for(int i=0; i<counter; i++){
		        getline(file, line);
				tempB.objCart[i].set_ProductID(line);
		        		   	
				getline(file, line);
				tempB.objCart[i].set_delDate(line);
				
				getline(file, line);
				tempB.objCart[i].set_orderDate(line);
				
				getline(file, line);
				tempB.objCart[i].set_orderNo(line);
					
				getline(file, line);
				tempB.objCart[i].set_trackingID(line);
				
				getline(file, line);
				tempB.objCart[i].set_payMethod(line);
				
		   }
		   
		   tempBB.push_back(tempB);
		}
		file.close();
		file.open("Buyer.txt",ios::out);
		for(int i=0;i<tempBB.size();i++){
			if(email==tempBB[i].get_email()){
				write_Buyer();
			}
			else{
				tempBB[i].write_Buyer();
			}
		}
	}
	
	void delete_Cart(){
		system("cls");
		int i,choice;
		for(i=0;i<objCart.size();i++){
			cout << "---------Product " << i+1 << "---------" << endl;
			objCart[i].display();
			cout << endl;
		}
		cout << "Enter product number to delete from Cart = ";
		cin >> choice;
		vector<Cart>tempC;
		
		for(i=0;i<objCart.size();i++){
			if(i==choice-1){
				continue;
			}
			else{
				tempC.push_back(objCart[i]);
			}
		}
		objCart.clear();
		objCart.shrink_to_fit();
		if(choice-1>0){
			for(i=0;i<tempC.size();i++){
			objCart.push_back(tempC[i]);
		    }
		}
		noOfProductsBought--;
		update();
	}
};











//--------------------------------------------------------all functions----------------------------------------------------------------------

void login_for_seller(string email,Seller &objS){
	system("cls");
		fstream file;
		file.open("Seller.txt",ios::in);
		Seller tempS;
		string line;
		while(getline(file,line)){
		tempS.set_firstName(line);
		
		getline(file,line);
		tempS.set_lastName(line);
		
		getline(file,line);
		tempS.set_email(line);
		
		getline(file,line);
		tempS.set_password(line);
		
		getline(file,line);
		tempS.set_phoneNumber(line);
		
		getline(file,line);
		tempS.set_address(line);
		
		getline(file,line);
		tempS.set_noOfProduct(stoi(line));
		
		getline(file,line);
		tempS.set_noOfProductsold(stoi(line));
		
		getline(file,line);
		tempS.set_profit(stod(line));
		
		getline(file,line);
		tempS.set_balance(stod(line));
		
		if(tempS.get_email()==email){
			objS=tempS;
			break;
		}
		else{
			continue;
		}
		}
}


string genrateString(){
	// seed the random number generator with the current time
    srand(time(nullptr));
    
    // define the length of the random string
    const int length = 10;
    
    // define the character set from which to choose the characters
    const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    
    // generate the random string
    string random_string;
    for (int i = 0; i < length; ++i)
    {
        int index = rand() % charset.length();
        random_string += charset[index];
    }
    return random_string;
}


void buy(Buyer &objB){
	int i;
	system("cls");
	int choice1,choice2,choice3;
	string email;
	allProducts objall;
	Seller objS;
	Cart tempC;
	
	objall.read_allProducts();
	
	cout << "Enter product category you want to buy\n1.Electronic\n2.Clothing\n3.Beauty\n4.Exit\n";
	cin >> choice1;
	if(choice1==1){
		Electronic tempP;  //temp object of electronic
		
		system("cls");
		for(i=0;i<objall.objE.size();i++){
			cout << i+1 << ".";
			cout << objall.objE[i].pname << endl;
			cout << endl;
		}
		cout << "Enter product number to view or press " << objall.objE.size()+1 << " to exit = ";
		cin >> choice2;
		if(choice2==objall.objE.size()+1){
			buy(objB);
		}
		system("cls");
		if(objall.objE[choice2-1].stock==0){
			objall.objE[choice2-1].display();
			cout << "Product is out of stock.Press any key to continue";
			getch();
			buy(objB);
		}
		
		objall.objE[choice2-1].display();
		cout << "Press 1 to buy from wallet ,2 to buy through COD and 3 to exit = ";
		cin >> choice3;
		if(choice3==2){
			tempP=objall.objE[choice2-1];
			tempP.stock--;
			objB.noOfProductsBought++;
			
			//populating cart temp object
			tempC.ProductID=tempP.ProductID;
			tempC.set_delDate(to_string(tempP.deliveryTime) + month);
			tempC.set_orderDate(date + month);
			tempC.set_payMethod("COD");
			tempC.orderNo = genrateString() + "djwdjc";
			tempC.trackingID = "iuwocwi" + genrateString();
			
			//updating seller temp object
			email=tempP.ProductID;
			i=email.length()-1;
		    if(email[i-1]>47 && email[i-1]<58){
			    email.pop_back();
			    email.pop_back();
		    }
		    else{
			    email.pop_back();
		    }
			login_for_seller(email,objS);
			objS.noOfProductsold++;
			
			//updating all three -> product,seller,buyer
			objB.objCart.push_back(tempC);
			tempP.update_product();
			objS.update();
			objB.update();
			cout << "Product bought successfully.Press any key to continue.";
			getch();
		}
		else if(choice3==1){
			tempP=objall.objE[choice2-1];
			tempP.stock--;
			objB.noOfProductsBought++;
			if(objB.balance<tempP.pprice){
				cout << "Balance is low.Cannot buy product.Press any key to continue";
				getch();
				buy(objB);
			}
			objB.balance-=tempP.pprice;
			
			//populating cart temp object
			tempC.ProductID=tempP.ProductID;
			tempC.set_delDate(to_string(tempP.deliveryTime) + month);
			tempC.set_orderDate(date + month);
			tempC.set_payMethod("Wallet");
			tempC.orderNo = genrateString() + "djwdjc";
			tempC.trackingID = "iuwocwi" + genrateString();
			
			//updating seller temp object
			email=tempP.ProductID;
			i=email.length()-1;
		    if(email[i-1]>47 && email[i-1]<58){
			    email.pop_back();
			    email.pop_back();
		    }
		    else{
			    email.pop_back();
		    }
			login_for_seller(email,objS);
			objS.noOfProductsold++;
			objS.balance+=tempP.pprice;
			objS.profit+=tempP.pprice;
			
			//updating all three -> product,seller,buyer
			objB.objCart.push_back(tempC);
			tempP.update_product();
			objS.update();
			objB.update();
			cout << "Product bought successfully.Press any key to continue.";
			getch();
		}
		else{
			buy(objB);
		}	
	}
	
	if(choice1==2){
		Clothing tempP;  //temp object of Clothing
		
		system("cls");
		for(i=0;i<objall.objC.size();i++){
			cout << i+1 << ".";
			cout << objall.objC[i].pname << endl;
			cout << endl;
		}
		cout << "Enter product number to view or press " << objall.objC.size()+1 << " to exit = ";
		cin >> choice2;
		if(choice2==objall.objC.size()+1){
			buy(objB);
		}
		system("cls");
		if(objall.objC[choice2-1].stock==0){
			objall.objC[choice2-1].display();
			cout << "Product is out of stock.Press any key to continue";
			getch();
			buy(objB);
		}
		
		objall.objC[choice2-1].display();
		cout << "Press 1 to buy from wallet ,2 to buy through COD and 3 to exit = ";
		cin >> choice3;
		if(choice3==2){
			tempP=objall.objC[choice2-1];
			tempP.stock--;
			objB.noOfProductsBought++;
			
			//populating cart temp object
			tempC.ProductID=tempP.ProductID;
			tempC.set_delDate(to_string(tempP.deliveryTime) + month);
			tempC.set_orderDate(date + month);
			tempC.set_payMethod("COD");
			tempC.orderNo = genrateString() + "djwdjc";
			tempC.trackingID = "iuwocwi" + genrateString();
			
			//updating seller temp object
			email=tempP.ProductID;
			i=email.length()-1;
		    if(email[i-1]>47 && email[i-1]<58){
			    email.pop_back();
			    email.pop_back();
		    }
		    else{
			    email.pop_back();
		    }
			login_for_seller(email,objS);
			objS.noOfProductsold++;
			
			//updating all three -> product,seller,buyer
			objB.objCart.push_back(tempC);
			tempP.update_product();
			objS.update();
			objB.update();
			cout << "Product bought successfully.Press any key to continue.";
			getch();
		}
		else if(choice3==1){
			tempP=objall.objC[choice2-1];
			tempP.stock--;
			objB.noOfProductsBought++;
			if(objB.balance<tempP.pprice){
				cout << "Balance is low.Cannot buy product.Press any key to continue";
				getch();
				buy(objB);
			}
			objB.balance-=tempP.pprice;
			
			//populating cart temp object
			tempC.ProductID=tempP.ProductID;
			tempC.set_delDate(to_string(tempP.deliveryTime) + month);
			tempC.set_orderDate(date + month);
			tempC.set_payMethod("Wallet");
			tempC.orderNo = genrateString() + "djwdjc";
			tempC.trackingID = "iuwocwi" + genrateString();
			
			//updating seller temp object
			email=tempP.ProductID;
			i=email.length()-1;
		    if(email[i-1]>47 && email[i-1]<58){
			    email.pop_back();
			    email.pop_back();
		    }
		    else{
			    email.pop_back();
		    }
			login_for_seller(email,objS);
			objS.noOfProductsold++;
			objS.balance+=tempP.pprice;
			objS.profit+=tempP.pprice;
			
			//updating all three -> product,seller,buyer
			objB.objCart.push_back(tempC);
			tempP.update_product();
			objS.update();
			objB.update();
			cout << "Product bought successfully.Press any key to continue.";
			getch();
		}
		else{
			buy(objB);
		}	
	}
	
	if(choice1==3){
		Beauty tempP;  //temp object of Beauty
		
		system("cls");
		for(i=0;i<objall.objB.size();i++){
			cout << i+1 << ".";
			cout << objall.objB[i].pname << endl;
			cout << endl;
		}
		cout << "Enter product number to view or press " << objall.objB.size()+1 << " to exit = ";
		cin >> choice2;
		if(choice2==objall.objB.size()+1){
			buy(objB);
		}
		system("cls");
		if(objall.objB[choice2-1].stock==0){
			objall.objB[choice2-1].display();
			cout << "Product is out of stock.Press any key to continue";
			getch();
			buy(objB);
		}
		
		objall.objB[choice2-1].display();
		cout << "Press 1 to buy from wallet ,2 to buy through COD and 3 to exit = ";
		cin >> choice3;
		if(choice3==2){
			tempP=objall.objB[choice2-1];
			tempP.stock--;
			objB.noOfProductsBought++;
			
			//populating cart temp object
			tempC.ProductID=tempP.ProductID;
			tempC.set_delDate(to_string(tempP.deliveryTime) + month);
			tempC.set_orderDate(date + month);
			tempC.set_payMethod("COD");
			tempC.orderNo = genrateString() + "djwdjc";
			tempC.trackingID = "iuwocwi" + genrateString();
			
			//updating seller temp object
			email=tempP.ProductID;
			i=email.length()-1;
		    if(email[i-1]>47 && email[i-1]<58){
			    email.pop_back();
			    email.pop_back();
		    }
		    else{
			    email.pop_back();
		    }
			login_for_seller(email,objS);
			objS.noOfProductsold++;
			
			//updating all three -> product,seller,buyer
			objB.objCart.push_back(tempC);
			tempP.update_product();
			objS.update();
			objB.update();
			cout << "Product bought successfully.Press any key to continue.";
			getch();
		}
		else if(choice3==1){
			tempP=objall.objB[choice2-1];
			tempP.stock--;
			objB.noOfProductsBought++;
			if(objB.balance<tempP.pprice){
				cout << "Balance is low.Cannot buy product.Press any key to continue";
				getch();
				buy(objB);
			}
			objB.balance-=tempP.pprice;
			
			//populating cart temp object
			tempC.ProductID=tempP.ProductID;
			tempC.set_delDate(to_string(tempP.deliveryTime) + month);
			tempC.set_orderDate(date + month);
			tempC.set_payMethod("Wallet");
			tempC.orderNo = genrateString() + "djwdjc";
			tempC.trackingID = "iuwocwi" + genrateString();
			
			//updating seller temp object
			email=tempP.ProductID;
			i=email.length()-1;
		    if(email[i-1]>47 && email[i-1]<58){
			    email.pop_back();
			    email.pop_back();
		    }
		    else{
			    email.pop_back();
		    }
			login_for_seller(email,objS);
			objS.noOfProductsold++;
			objS.balance+=tempP.pprice;
			objS.profit+=tempP.pprice;
			
			//updating all three -> product,seller,buyer
			objB.objCart.push_back(tempC);
			tempP.update_product();
			objS.update();
			objB.update();
			cout << "Product bought successfully.Press any key to continue.";
			getch();
		}
		else{
			buy(objB);
		}	
	}
	
	else if(choice1==4){
		mainmenu_Buyer(objB);
	}
}


void reset_ID_Products(int flag,int dID,string email,allProducts &objall){   //this function is reseting Product id for all type of products
	int i,j;
	if(flag==0){
		flag=1;
	}
	allProducts tempall;
	    string *strCheck = new string[flag];
		string *strSet = new string[flag];
		j=dID;
		for(i=0;i<flag;i++){
			strSet[i] = email + to_string(j);
			strCheck[i] = email + to_string(j+1);
			j++;
		}
		
		for(i=0;i<objall.objE.size();i++){
			if(objall.objE[i].ProductID==(email + to_string(dID))){
				continue;
			}
			else{
				for(j=0;j<flag;j++){
					if(objall.objE[i].ProductID==strCheck[j]){
						objall.objE[i].ProductID=strSet[j];
						tempall.objE.push_back(objall.objE[i]);
					}
					else{
						tempall.objE.push_back(objall.objE[i]);
						continue;
					}
				}
			}
		}
		
		for(i=0;i<objall.objC.size();i++){
			if(objall.objC[i].ProductID==(email + to_string(dID))){
				continue;
			}
			else{
				for(j=0;j<flag;j++){
					if(objall.objC[i].ProductID==strCheck[j]){
						objall.objC[i].ProductID=strSet[j];
						tempall.objC.push_back(objall.objC[i]);
					}
					else{
						tempall.objC.push_back(objall.objC[i]);
						continue;
					}
				}
			}
		}
		
		for(i=0;i<objall.objB.size();i++){
			if(objall.objB[i].ProductID==(email + to_string(dID))){
				continue;
			}
			else{
				for(j=0;j<flag;j++){
					if(objall.objB[i].ProductID==strCheck[j]){
						objall.objB[i].ProductID=strSet[j];
						tempall.objB.push_back(objall.objB[i]);
					}
					else{
						tempall.objB.push_back(objall.objB[i]);
						continue;
					}
				}
			}
		}
		tempall.write_allProducts();
}

int get_dID(string str){
	int i=str.length()-1;
	if(str[i-1]>47 && str[i-1]<58){
		return (int)((int)str[i-1]-'0')*10 + ((int)str[i]-'0');
	}
	else{
		return (int)(str[i]-'0');
	}
}

void get_products(Seller &obj){
	system("cls");
	int n=obj.get_noOfProduct();
	int i;
	if(n>0){
		string *str = new string[n];
		for(i=0;i<n;i++){
			str[i] = obj.get_email() + to_string(i+1);
		}
		string line;
		Electronic tempE;
		Clothing tempC;
		Beauty tempB;
		fstream file;
		file.open("Electronic.txt",ios::in);
		while(getline(file,line)){
			tempE.ProductID=line;
			
			getline(file,line);
			tempE.pname=line;
			
			getline(file,line);
			tempE.pprice=stod(line);
			
			getline(file,line);
			tempE.pdescription=line;
			
			getline(file,line);
			tempE.stock=stoi(line);
			
			getline(file,line);
			tempE.storeName=line;
			
			getline(file,line);
			tempE.deliveryTime=stoi(line);
			
			getline(file,line);
			tempE.brand=line;
			
			getline(file,line);
			tempE.warranty=line;
			
			getline(file,line);
			tempE.model=line;
			
			getline(file,line);
			tempE.color=line;
			
			if(tempE.stock>0){
				tempE.availability=1;
			}
			else{
				tempE.availability=0;
			}
			for(int i=0;i<n;i++){
				if(tempE.ProductID==str[i]){
					obj.objSellerP.objE.push_back(tempE);
				}
				else{
					continue;
				}
			}
		}
		file.close();
		file.open("Clothing.txt",ios::in);
		while(getline(file,line)){
			tempC.ProductID=line;
			
			getline(file,line);
			tempC.pname=line;
			
			getline(file,line);
			tempC.pprice=stod(line);
			
			getline(file,line);
			tempC.pdescription=line;
			
			getline(file,line);
			tempC.stock=stoi(line);
			
			getline(file,line);
			tempC.storeName=line;
			
			getline(file,line);
			tempC.deliveryTime=stoi(line);
			
			getline(file,line);
			tempC.ageGroup=line;
			
			getline(file,line);
			tempC.size=stoi(line);
			
			getline(file,line);
			tempC.fabric=line;
			
			getline(file,line);
			tempC.color=line;
			
			if(tempC.stock>0){
				tempC.availability=1;
			}
			else{
				tempC.availability=0;
			}
			for(int i=0;i<n;i++){
				if(tempC.ProductID==str[i]){
					obj.objSellerP.objC.push_back(tempC);
				}
				else{
					continue;
				}
			}
		}
		file.close();
		file.open("Beauty.txt",ios::in);
		while(getline(file,line)){
			tempB.ProductID=line;
			
			getline(file,line);
			tempB.pname=line;
			
			getline(file,line);
			tempB.pprice=stod(line);
			
			getline(file,line);
			tempB.pdescription=line;
			
			getline(file,line);
			tempB.stock=stoi(line);
			
			getline(file,line);
			tempB.storeName=line;
			
			getline(file,line);
			tempB.deliveryTime=stoi(line);
			
			getline(file,line);
			tempB.brand=line;
			
			getline(file,line);
			tempB.gender=line;
	
			getline(file,line);
			tempB.type=line;
			
			if(tempB.stock>0){
				tempB.availability=1;
			}
			else{
				tempB.availability=0;
			}
			for(int i=0;i<n;i++){
				if(tempB.ProductID==str[i]){
					obj.objSellerP.objB.push_back(tempB);
				}
				else{
					continue;
				}
			}
		}
		file.close();
	}
}

void mainmenu_Seller(Seller &objS){
	system("cls");
	int choice;
	cout << "1.Display account information\n2.Display products\n3.List a new product\n4.Edit personal details\n5.Edit product details.\n6.Delete a product\n7.Logout\n";
	cin >> choice;
	if(choice==1){
		system("cls");
		objS.display();
		cout << "Press any key to continue\n";
		getch();
		mainmenu_Seller(objS);
	}
	else if(choice==2){
		objS.display_seller_products();
		mainmenu_Seller(objS);
	}
	else if (choice==3){
		objS.addProduct();
		mainmenu_Seller(objS);
	}
	else if(choice==4){
		update_seller_info(objS);
		cout << "Account information updated successfully.Press any key to continue\n";
		getch();
		mainmenu_Seller(objS);
	}
	else if(choice==5){
		objS.update_seller_products();
		mainmenu_Seller(objS);
	}
	else if(choice==6){
		objS.Delete();
		mainmenu_Seller(objS);
	}
	else if(choice==7){
		login_signup();
	}
	else{
		cout << "Entered wrong choice.Press any key to try again.\n";
		getch();
		mainmenu_Seller(objS);
	}
}


void mainmenu_Buyer(Buyer &objB){
	system("cls");
	int choice;
	cout << "1.Display account information\n2.Edit account information\n3.Display Cart\n4.Buy a Product\n5.Delete cart produt\n6.Logout\n";
	cin >> choice;
	if(choice==1){
		system("cls");
		objB.display();
		cout << "Press any key to continue\n";
		getch();
		mainmenu_Buyer(objB);
	}
	else if(choice==2){
   		update_buyer_info(objB);
   		cout << "Press any key to continue\n";
		getch();
		mainmenu_Buyer(objB);
	}
	else if (choice==3){
		objB.displayCart();
		cout << "Press any key to continue\n";
		getch();
		mainmenu_Buyer(objB);
	}
	else if(choice==4){
		buy(objB);
		mainmenu_Buyer(objB);
	}
	else if(choice==5){
		objB.delete_Cart();
		mainmenu_Buyer(objB);
	}
	else if(choice==6){
		login_signup();
	}
	else{
		cout << "Entered wrong choice.Press any key to try again.\n";
		getch();
		mainmenu_Buyer(objB);
	}
}


void update_seller_info(Seller &objS){
	system("cls");
		int flag;
		string str;
		cout << "1.Update first name\n2.Update last name\n3.Update Password\n4.Update Phone number\n5.Update address\n6.Update balance" << endl;
		cin >> flag;
		fflush(stdin);
		cout << "Enter new information = ";
		cin >> str;
		fflush(stdin);
		if(flag==1){
			objS.firstName=str;
		}
		else if(flag==2){
			objS.lastName=str;
		}
		else if(flag==3){
			objS.password=str;
		}
		else if(flag==4){
			objS.phoneNumber=str;
		}
		else if(flag==5){
			objS.address=str;
		}
		else if(flag==6){
			objS.balance=stod(str);
		}
		else{
			cout << "Entered wrong choice.Press any key to try again.\n";
		    getch();
		    mainmenu_Seller(objS);
		}
		objS.update();
}

void update_buyer_info(Buyer& objB){
	system("cls");
		int flag;
		string str;
		cout << "1.Update first name\n2.Update last name\n3.Update Password\n4.Update Phone number\n5.Update address\n6.Update balance" << endl;
		cin >> flag;
		fflush(stdin);
		cout << "Enter new information = ";
		cin >> str;
		fflush(stdin);
		if(flag==1){
			objB.set_firstName(str);
		}
		else if(flag==2){
			objB.set_lastName(str);
		}
		else if(flag==3){
			objB.set_password(str);
		}
		else if(flag==4){
			objB.set_phoneNumber(str);
		}
		else if(flag==5){
			objB.set_address(str);
		}
		else if(flag==6){
			objB.set_balance(stod(str));
		}
		else{
			cout << "Entered wrong choice.Press any key to try again.\n";
		    getch();
		    mainmenu_Buyer(objB);
		}
		objB.update();
}

bool check_password_seller(string str){
	fstream file;
	file.open("Seller.txt",ios::in);
	vector<Seller> objS;
	Seller tempS;
	string line;
	while(getline(file,line)){
		tempS.set_firstName(line);
		
		getline(file,line);
		tempS.set_lastName(line);
		
		getline(file,line);
		tempS.set_email(line);
		
		getline(file,line);
		tempS.set_password(line);
		
		getline(file,line);
		tempS.set_phoneNumber(line);
		
		getline(file,line);
		tempS.set_address(line);
		
		getline(file,line);
		tempS.set_noOfProduct(stoi(line));
		
		getline(file,line);
		tempS.set_noOfProductsold(stoi(line));
		
		getline(file,line);
		tempS.set_profit(stod(line));
		
		getline(file,line);
		tempS.set_balance(stod(line));
		
		objS.push_back(tempS);
	}
	bool flag=0;
	for(int i=0;i<objS.size();i++){
		if(objS[i].get_password()==str){
			flag=1;
			break;
		}
		else{
			continue;
		}
	}
	file.close();
	return flag;
}

bool check_email_seller(string str){
	fstream file;
	file.open("Seller.txt",ios::in);
	vector<Seller> objS;
	Seller tempS;
	string line;
	while(getline(file,line)){
		tempS.set_firstName(line);
		
		getline(file,line);
		tempS.set_lastName(line);
		
		getline(file,line);
		tempS.set_email(line);
		
		getline(file,line);
		tempS.set_password(line);
		
		getline(file,line);
		tempS.set_phoneNumber(line);
		
		getline(file,line);
		tempS.set_address(line);
		
		getline(file,line);
		tempS.set_noOfProduct(stoi(line));
		
		getline(file,line);
		tempS.set_noOfProductsold(stoi(line));
		
		getline(file,line);
		tempS.set_profit(stod(line));
		
		getline(file,line);
		tempS.set_balance(stod(line));
		
		objS.push_back(tempS);
	}
	bool flag=0;
	for(int i=0;i<objS.size();i++){
		if(objS[i].get_email()==str){
			flag=1;
			break;
		}
		else{
			continue;
		}
	}
	file.close();
	return flag;
}

bool check_email_buyer(string str){
	int counter;
	fstream file;
	file.open("Buyer.txt",ios::in);
	vector<Buyer> objB;
	Buyer tempB;
	string line;
	while(getline(file,line)){
		tempB.set_firstName(line);
		
		getline(file,line);
		tempB.set_lastName(line);
		
		getline(file,line);
		tempB.set_email(line);
		
		getline(file,line);
		tempB.set_password(line);
		
		getline(file,line);
		tempB.set_phoneNumber(line);
		
		getline(file,line);
		tempB.set_address(line);
		
		getline(file,line);
		tempB.set_noOfProductsBought(stoi(line));
		counter=stoi(line);
		
		getline(file,line);
		tempB.set_balance(stod(line));
		
		for(int i=0; i<counter; i++){
			getline(file, line);
			tempB.objCart[i].set_delDate(line);
				
			getline(file, line);
			tempB.objCart[i].set_orderDate(line);
				
			getline(file, line);
			tempB.objCart[i].set_orderNo(line);
					
			getline(file, line);
			tempB.objCart[i].set_trackingID(line);
				
			getline(file, line);
			tempB.objCart[i].set_payMethod(line);
		}
		
		objB.push_back(tempB);
	}
	bool flag=0;
	for(int i=0;i<objB.size();i++){
		if(objB[i].get_email()==str){
			flag=1;
			break;
		}
		else{
			continue;
		}
	}
	file.close();
	return flag;
}


istream& operator>>(istream &input,Seller &obj){
	system("cls");
	cout << "Enter first name = ";
	cin >> obj.firstName;
	fflush(stdin);
	cout << "Enter last name = ";
	cin >> obj.lastName;
	fflush(stdin);
	cout << "Enter email address = ";
	cin >> obj.email;
	if(check_email_seller(obj.email)){
		cout << "Email already taken.Enter details again.Press any continue.\n";
		getch();
		signup();
	}
	fflush(stdin);
	cout << "Enter password = ";
	cin >> obj.password;
	fflush(stdin);
	cout << "Enter phone number = ";
	cin >> obj.phoneNumber;
	fflush(stdin);
	cout << "Enter home address = ";
	cin >> obj.address;
	fflush(stdin);
	cout << "Enter wallet balance = ";
	cin >> obj.balance;
	fflush(stdin);
	obj.noOfProduct=0;
	obj.noOfProductsold=0;
	obj.profit=0;
}


istream& operator>>(istream &input, Buyer &obj){
	system("cls");
	cout << "Enter first name = ";
	cin >> obj.firstName;
	fflush(stdin);
	cout << "Enter last name = ";
	cin >> obj.lastName;
	fflush(stdin);
	cout << "Enter email address = ";
	cin >> obj.email;
	if(check_email_buyer(obj.email)){
		cout << "Email already taken.Enter details again.Press any continue.\n";
		getch();
		signup();
	}
	fflush(stdin);
	cout << "Enter password = ";
	cin >> obj.password;
	fflush(stdin);
	cout << "Enter phone number = ";
	cin >> obj.phoneNumber;
	fflush(stdin);
	cout << "Enter home address = ";
	cin >> obj.address;
	fflush(stdin);
	cout << "Enter wallet balance = ";
	cin >> obj.balance;
	fflush(stdin);
	obj.noOfProductsBought=0;
}


istream& operator>>(istream &input,Electronic &obj){
	cout << "Enter product name = ";
	cin >> obj.pname;
	fflush(stdin);
	cout << "Enter product price = ";
	cin >> obj.pprice;
	fflush(stdin);
	cout << "Enter product description = ";
	cin >> obj.pdescription;
	fflush(stdin);
	cout << "Enter product stock = ";
	cin >> obj.stock;
	fflush(stdin);
	cout << "Enter product storename = ";
	cin >> obj.storeName;
	fflush(stdin);
	cout << "Enter product delivery time in days = ";
	cin >> obj.deliveryTime;
	fflush(stdin);
	cout << "Enter product brand = ";
	cin >> obj.brand;
	fflush(stdin);
	cout << "Enter product warranty = ";
	cin >> obj.warranty;
	fflush(stdin);
	cout << "Enter product model = ";
	cin >> obj.model;
	fflush(stdin);
	cout << "Enter product color = ";
	cin >> obj.color;
	fflush(stdin);
	if(obj.stock>0){
		obj.availability=1;
	}
}

istream& operator>>(istream &input,Clothing &obj){
	cout << "Enter product name = ";
	cin >> obj.pname;
	fflush(stdin);
	cout << "Enter product price = ";
	cin >> obj.pprice;
	fflush(stdin);
	cout << "Enter product description = ";
	cin >> obj.pdescription;
	fflush(stdin);
	cout << "Enter product stock = ";
	cin >> obj.stock;
	fflush(stdin);
	cout << "Enter product storename = ";
	cin >> obj.storeName;
	fflush(stdin);
	cout << "Enter product delivery time in days = ";
	cin >> obj.deliveryTime;
	fflush(stdin);
	cout << "Enter product age group = ";
	cin >> obj.ageGroup;
	fflush(stdin);
	cout << "Enter product size = ";
	cin >> obj.size;
	fflush(stdin);
	cout << "Enter product fabric = ";
	cin >> obj.fabric;
	fflush(stdin);
	cout << "Enter product color = ";
	cin >> obj.color;
	fflush(stdin);
	if(obj.stock>0){
		obj.availability=1;
	}
}

istream& operator>>(istream &input,Beauty &obj){
	cout << "Enter product name = ";
	cin >> obj.pname;
	fflush(stdin);
	cout << "Enter product price = ";
	cin >> obj.pprice;
	fflush(stdin);
	cout << "Enter product description = ";
	cin >> obj.pdescription;
	fflush(stdin);
	cout << "Enter product stock = ";
	cin >> obj.stock;
	fflush(stdin);
	cout << "Enter product storename = ";
	cin >> obj.storeName;
	fflush(stdin);
	cout << "Enter product delivery time in days = ";
	cin >> obj.deliveryTime;
	fflush(stdin);
	cout << "Enter product brand = ";
	cin >> obj.brand;
	fflush(stdin);
	cout << "Enter product gender = ";
	cin >> obj.gender;
	fflush(stdin);
	cout << "Enter product type = ";
	cin >> obj.type;
	fflush(stdin);
	if(obj.stock>0){
		obj.availability=1;
	}
}
void login_signup(){
	system("cls");
	int choice;
	cout << "1.Login if you already have an account.\n2.Sign up to create a new account.\n3.Exit\n";
	cin >> choice;
	if(choice==1){
		login();
	}
	else if(choice==2){
		signup();
	}
	else if(choice==3){
		exit(0);
	}
	else{
		system("cls");
		cout << "Wrong choice entered.Please try again\n";
		login_signup();
	}
}

void login_Seller(string email,string pass){
	system("cls");
		fstream file;
		file.open("Seller.txt",ios::in);
		Seller objS;
		Seller tempS;
		string line;
		int flag=0;
		while(getline(file,line)){
		tempS.set_firstName(line);
		
		getline(file,line);
		tempS.set_lastName(line);
		
		getline(file,line);
		tempS.set_email(line);
		
		getline(file,line);
		tempS.set_password(line);
		
		getline(file,line);
		tempS.set_phoneNumber(line);
		
		getline(file,line);
		tempS.set_address(line);
		
		getline(file,line);
		tempS.set_noOfProduct(stoi(line));
		
		getline(file,line);
		tempS.set_noOfProductsold(stoi(line));
		
		getline(file,line);
		tempS.set_profit(stod(line));
		
		getline(file,line);
		tempS.set_balance(stod(line));
		
		if((tempS.get_email()==email) && (tempS.get_password()==pass)){
			objS=tempS;
			flag=1;
			break;
		}
		else{
			flag=0;
			continue;
		}
		}
		file.close();
		if(flag>0){
			get_products(objS);
			mainmenu_Seller(objS);
		}
		else{
			cout << "Entered wrong email or password.Press any key to try again\n";
			getch();
			login();
		}
}


void login(){
	system("cls");
	int choice;
	cout << "Do you want to login as a seller os as a buyer?\n1.Seller\n2.Buyer\n3.Exit\n";
	cin >> choice;
	if(choice==1){
		system("cls");
		fstream file;
		file.open("Seller.txt",ios::in);
		Seller objS;
		Seller tempS;
		string line,email,pass;
		int flag=0;
		cout << "Enter your email = ";
	    cin >> email;
	    cout << "Enter your password = ";
	    cin >> pass;
		while(getline(file,line)){
		tempS.set_firstName(line);
		
		getline(file,line);
		tempS.set_lastName(line);
		
		getline(file,line);
		tempS.set_email(line);
		
		getline(file,line);
		tempS.set_password(line);
		
		getline(file,line);
		tempS.set_phoneNumber(line);
		
		getline(file,line);
		tempS.set_address(line);
		
		getline(file,line);
		tempS.set_noOfProduct(stoi(line));
		
		getline(file,line);
		tempS.set_noOfProductsold(stoi(line));
		
		getline(file,line);
		tempS.set_profit(stod(line));
		
		getline(file,line);
		tempS.set_balance(stod(line));
		
		if((tempS.get_email()==email) && (tempS.get_password()==pass)){
			objS=tempS;
			flag=1;
			break;
		}
		else{
			flag=0;
			continue;
		}
		}
		file.close();
		if(flag>0){
			get_products(objS);
			mainmenu_Seller(objS);
		}
		else{
			cout << "Entered wrong email or password.Press any key to try again\n";
			getch();
			login();
		}
	}
	else if(choice==2){
		int counter;
		system("cls");
		fstream file;
		file.open("Buyer.txt",ios::in);
		Buyer objB;
		Buyer tempB;
		
		string line,email,pass;
		int flag=0;
		cout << "Enter your email = ";
	    cin >> email;
	    cout << "Enter your password = ";
	    cin >> pass;
		while(getline(file,line)){
		tempB.set_firstName(line);
		
		getline(file,line);
		tempB.set_lastName(line);
		
		getline(file,line);
		tempB.set_email(line);
		
		getline(file,line);
		tempB.set_password(line);
		
		getline(file,line);
		tempB.set_phoneNumber(line);
		
		getline(file,line);
		tempB.set_address(line);
		
		getline(file,line);
		tempB.set_noOfProductsBought(stoi(line));
		counter=stoi(line);
		
		getline(file,line);
		tempB.set_balance(stod(line));
		Cart tempC;
		
		for(int i=0; i<counter; i++){
			getline(file, line);
			tempC.set_ProductID(line);
			
			getline(file, line);
			tempC.set_delDate(line);
			
			getline(file, line);
			tempC.set_orderDate(line);
			
			getline(file, line);
			tempC.set_orderNo(line);
			
			getline(file, line);
			tempC.set_trackingID(line);
			
			getline(file, line);
			tempC.set_payMethod(line);
			
			tempB.objCart.push_back(tempC);
		}
		
		if((tempB.get_email()==email) && (tempB.get_password()==pass)){
			objB=tempB;
			flag=1;
			break;
		}
		else{
			flag=0;
			continue;
		}
		}
		file.close();
		if(flag>0){
			mainmenu_Buyer(objB);
		}
		else{
			cout << "Entered wrong email or password.Press any key to try again\n";
			getch();
			login();
		}
	}
	else if(choice==3){
		exit(0);
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
	system("cls");
	int choice;
	cout << "Do you want to signup as a seller or as a buyer?\n1.Seller\n2.Buyer\n";
	cin >> choice;
	if(choice==1){
		Seller objS;
		cin >> objS;
		fstream file;
	    file.open("Seller.txt",ios::app);
		if(!file){
		cout<<"Error while opening the file";
	    }
	    else{
		fstream file;
	    file.open("Seller.txt",ios::app);
	    file << objS.firstName << endl;
	    file << objS.lastName << endl;
	    file << objS.email << endl;
	    file << objS.password << endl;
	    file << objS.phoneNumber << endl;
	    file << objS.address << endl;
	    file << objS.noOfProduct << endl;
	    file << objS.noOfProductsold << endl;
	    file << objS.profit << endl;
	    file << objS.balance << endl;
		file.close();
		cout << "Account has been created successfully.Press any key to login.\n";
        getch();
        login_signup();
	    }	
	}
	else if(choice==2){
		Buyer objB;
		cin >> objB;
		fstream file;
	    file.open("Buyer.txt",ios::app);
		if(!file){
		cout<<"Error while opening the file";
	    }
	    else{
		fstream file;
	    file.open("Buyer.txt",ios::app);
	    file << objB.firstName << endl;
	    file << objB.lastName << endl;
	    file << objB.email << endl;
	    file << objB.password << endl;
	    file << objB.phoneNumber << endl;
	    file << objB.address << endl;
	    file << objB.noOfProductsBought << endl;
	    file << objB.balance << endl;
		file.close();
		cout << "Account has been created successfully.Press any key to login.\n";
        getch();
        login_signup();
    	}
	}
	else{
		cout << "Entered wrong choice.Try again\n" << endl;
		signup();
	}
}
int main(){
	login_signup();
	return 0;
}
