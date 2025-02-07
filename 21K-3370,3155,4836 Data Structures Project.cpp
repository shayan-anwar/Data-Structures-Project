 #include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<Queue>
#include <istream> 
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <windows.h>
#define N 100
using namespace std;

COORD CursorPosition;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoXY(int x, int y) 
{ 
CursorPosition.X = x; // Locates column
CursorPosition.Y = y; // Locates Row
SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}
void loader(string xyz)
{system("color 5F");
    int i;
	system("cls");
	gotoXY(20,10);
	cout<<xyz<<endl;
	gotoXY(20,12);
	for (i=0;i<30;i++)
	{
		Sleep(50);
		printf("%c",219);
	}
}
int staffCount[5] = {0,0,0,0,0};
int roomcount[5] = {0,0,0,0,0};
int countDays(int day1,int month1,int year1,int day2,int month2,int year2){
	int sum1 = (1*day1)+ (month1*30)+(year1*365);
	//cout<<sum1;
	int sum2 = (1*day2)+ (month2*30)+(year2*365);
	return (sum2-sum1);
	
}

int timeDiffrence(int h1,int m1,int h2,int m2){
	int sum1 = (h1*60)+m1;
	int sum2 = (h2*60)+m2;
	return (sum2-sum1);	
}

void RandomPassword(char* password){
	const char pass[]="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int string_length = sizeof(pass)-1;
	
    srand(time(NULL));
    //cout<<"Generated password:";
    for(int i = 0; i < 7; i++)
    password[i] =  pass[rand() % string_length];
    //cout<<password;
}
bool isDateCorrect(int d,int m,int y){
	if(d<1||m<1||y<1||m>12){
		return false;	
	}
	else if(d>30&&(m==4||m==6||m==9||m==11)){
		return false;
	}
	else if(d>28&&(m==2)){
		return false;
	}
	else if(d>31&&(m==1||m==3||m==5||m==7||m==8||m==10||m==12)){
		return false;
	}
	else{
		return true;
	}

}
void RandomID(char* x,char*y){
	char nums[10] = {'0','1','2','3','4','5','6','7','8','9'};
	srand(time(NULL));
	char ID[8];
	ID[0] = x[0];
	ID[1] = x[1];
	ID[2] = x[2];
	char tempc;
	int tempi;
	for(int i=3;i<=6;++i){
		ID[i] = nums[rand()%10];
	}
	strcpy(y,ID);
}

int charIDtointID(char *x){
	int ID=0;
	int dig;
	int place=1000;
	for(int i=0;i<4;++i){
		switch(x[i+3]){
			case '0':
				dig = 0;
				break;
			case '1':
				dig = 1;
				break;
			case '2':
				dig = 2;
				break;
			case '3':
				dig = 3;
				break;
			case '4':
				dig = 4;
				break;
			case '5':
				dig = 5;
				break;
			case '6':
				dig = 6;
				break;
			case '7':
				dig = 7;
				break;
			case '8':
				dig = 8;
				break;
			case '9':
				dig = 9;
				break;
		}
		ID+= dig*place;
		place/=10;
	}
	return ID;
	
}

														
class Admin
{
public:
	char ID[N];
	char name[N];
	char password[N];
	char phoneNo[N];
	char email[N];

	Admin(){
		strcpy(ID,"1234");	
		strcpy(name,"Ahmed Mustafa");
		strcpy(password,"1234");
		strcpy(phoneNo,"03132538919");
		strcpy(email,"ahmed@gmail.com");
	}
	void displayInfo(){
		system("cls");
		cout<<"Name: "<<name<<endl;
		cout<<"Id: "<<ID<<endl;
		cout<<"Email: "<<email<<endl;
		cout<<"Phone: "<<phoneNo<<endl;
	}
	bool check_login(char* id,char* pass){
		if(strcmp(id,ID)==0&&strcmp(pass,password)==0){
			return true;
		}
		else{
			return false;
		}
	}

	
};
Admin admin;

class Member
{
public:
	char ID[N];
	char fName[N/2];
	char lName[N/2];
	char password[N];
	char phoneNo[N];
	char email[N];
	char CNIC[N];
	char CreditCardNumber[N];
public:
	Member(){
		
	}
	Member(char *id,char* fn,char*ln,char *pass,char *ph,char *em,char* cnic,char*cred){
		strcpy(ID,id);
		strcpy(fName,fn);
		strcpy(lName,ln);
		strcpy(password,pass);
		strcpy(phoneNo,ph);
		strcpy(email,em);
		strcpy(CNIC,cnic);
		strcpy(CreditCardNumber,cred);
	}
	bool checkLogin(char* id,char*pass){
		if(strcmp(id,ID)==0&&strcmp(pass,password)==0){
			return true;
		}
		else{
			return false;
		}
	}
	void displayInfo(){
		cout<<"Name: "<<fName<<" "<<lName<<endl;
		cout<<"Id: "<<ID<<endl;
		cout<<"Password: "<<password<<endl;
		cout<<"Email: "<<email<<endl;
		cout<<"Phone: "<<phoneNo<<endl;
		cout<<"CNIC: "<<CNIC<<endl;
		cout<<"Credit Card Number: "<<CreditCardNumber<<endl;
	}
	
};




class Room{
public:
	char roomtype[N];
	char ID[N];
	int floorno;
	int capacity;
	int numID;
	bool isBooked;
	char bookingID[N];
	Room(){
	}
	Room(char* roomtype,char* roomid,int floorno){
		this->capacity=capacity;
		this->floorno=floorno;
		strcpy(this->ID,roomid);
		strcpy(this->roomtype,roomtype);
		isBooked = false;
		numID = charIDtointID(ID);
		
		if(strcmp(roomtype,"Single")==0){
			capacity = 1;
		}
		else if(strcmp(roomtype,"Double")==0){
			capacity = 2;
		}
		else if(strcmp(roomtype,"Quad")==0){
			capacity = 4;
		}
		else if(strcmp(roomtype,"King")==0){
			capacity = 1;
		}
		else if(strcmp(roomtype,"Suite")==0){
			capacity = 5;
		}
		
	}
    void displayInfo()
{
	cout<<"\t\t ROOM DETAILS"<<endl<<endl;
	cout<<"Room ID: " << ID<<endl;
	cout<<"Room Type: " << roomtype << endl;
	cout<<"Floor no: "<<floorno<<endl;
	cout<<"Capacity: " << capacity << endl;
	cout<<"Booked: "<<isBooked<<endl;
	if(isBooked){
		cout<<"Booking ID: "<<bookingID<<endl;
	}

	
}
bool checkBooking(char*rt){
	if((strcmp(roomtype,rt)==0)&&!isBooked){
		return true;
	
	}
	else{
		return false;
	}
}
};



class Staff{
	public:
		char ID[N];
		char password[N];
		char fName[N];
		char lName[N];
		char email[N];
		char phoneNo[N];
		char jobDescription[N];
		char dateOfBirth[N];
		int joinDay,joinMonth,joinYear;
		long salary;
		int numID;
		int Age;
		char homeAddress[N];
	public:
		Staff(){
			
		}
		Staff(char*id,char*pass,char*fn,char*ln,int age,char*email,char *address,char* ph,char* jd,long sal,char*dob,int d,int m,int y){
				joinDay = d;
				strcpy(this->email,email);
				strcpy(this->password,pass);
				strcpy(this->phoneNo,ph);
				strcpy(this->jobDescription,jd);
				strcpy(this->dateOfBirth,dob);
				strcpy(this->fName,fn);
				strcpy(this->lName,ln);
				salary = sal;
				strcpy(this->ID,id);
				numID = charIDtointID(this->ID);
				this->Age = age;
				strcpy(this->homeAddress,address);
				joinMonth = m;
				joinYear = y;
				//cout<<password;
				//cout<<numID
				
		}		
		bool checkLogin(char* id,char* pass){
			if(strcmp(ID,id)==0){
				if(strcmp(password,pass)==0){
					return true;
				}
				else{
					return false;
				}
			}
			else{
				return false;
			}
		}
		
		void displayInfo(){
			cout<<"\n\n*********************** STAFF INFORMATION ******************************"<<endl;
			cout<<"Name: "<<fName<<" "<<lName<<endl;
			cout<<"Id: "<<ID<<endl;
			cout<<"NumID: "<<numID<<endl;
			cout<<"Password: "<<password<<endl;
			cout<<"Address: "<<homeAddress<<endl;
			cout<<"Email: "<<email<<endl;
			cout<<"Date Of Birth: "<<dateOfBirth<<endl;
			cout<<"Joining Date: "<<joinDay<<"/"<<joinMonth<<"/"<<joinYear<<endl;
			cout<<"Phone: "<<phoneNo<<endl;
			cout<<"Salary: Rs."<<salary<<endl;
			cout<<"Job Description: "<<jobDescription<<endl;
		}
		
};


class Booking{
	public:
		char ID[N];
		char memberID[N];
		int sdate,smonth,syear;
		int edate,emonth,eyear;
		int cdate,cmonth,cyear;
		char roomID[N];
		int floorno;
		int noofpeople;
		int checkinHours;
		int checkinMins;
		int checkoutHours;
		int checkoutMins;
		char roomtype[N];
		bool isActive;
		int numID;
		float costPerNight;
		float foodCost;
		float cleaningCost;
		int totalNightsSpent;
		char bookingType[N];
		bool checkedIn;
		bool checkedOut;
		
		Booking(){
		}
		Booking(char* id,char*mID,int sdate,int smonth,int syear,int edate,int emonth,int eyear,int floorno,int noofpeople,char* roomtype,char*roomid,char* bk,int checkoutHours,int checkoutMins)
		{
		checkedIn = false;
		checkedOut = false;
		foodCost = 0;
		cleaningCost = 0;
		strcpy(memberID,mID);
		this->sdate=sdate;
		this->smonth=smonth;
		this->syear=syear;
		this->edate=edate;
		this->emonth=emonth;
		this->eyear=eyear;
		strcpy(this->roomID,roomid);
		this->floorno=floorno;
		strcpy(this->roomtype,roomtype);
	    this->noofpeople=noofpeople;
		this->isActive = true;
		this->checkinHours = checkinHours;
		this->checkinMins = checkinMins;
		this->checkoutHours = checkoutHours;
		this->checkoutMins = checkoutMins;
		strcpy(this->bookingType,bk);
		strcpy(this->ID,id);
		numID = charIDtointID(ID);	
		}
		void showbookingmember(){
			cout<<"\t\t***** BOOKING DETAILS *****";
			cout<<endl<<endl<<endl;
			cout<<"Booking ID: "<<ID<<endl;
			cout<<"Member ID:"<<memberID<<endl;
			cout<<"Booking Starts: "<<sdate<<"-"<<smonth<<"-"<<syear<<endl;
			cout<<"Booking Ends: "<<edate<<"-"<<emonth<<"-"<<eyear<<endl;
			cout<<"Room ID: "<<roomID<<endl;
			cout<<"Floor Number: "<<floorno<<endl;
			cout<<"Number of people: "<<noofpeople<<endl;
			cout<<"Room Type: "<<roomtype<<endl;
			cout<<"Package: "<<bookingType<<endl;
			cout<<"Food Expenditure: Rs."<<foodCost<<endl;
			cout<<"Cleaning Expenditure: Rs."<<cleaningCost<<endl;
		}
		void displayInfo(){
			cout<<"\t\t***** BOOKING DETAILS *****";
			cout<<endl;
			cout<<"Booking ID: "<<ID<<endl;
			cout<<"Member ID:"<<memberID<<endl;
			cout<<"Booking Starts: "<<sdate<<"-"<<smonth<<"-"<<syear<<endl;
			cout<<"Booking Ends: "<<edate<<"-"<<emonth<<"-"<<eyear<<endl;
			cout<<"Room Numbers: "<<roomID<<endl;
			cout<<"Floor Number: "<<floorno<<endl;
			cout<<"Number of people: "<<noofpeople<<endl;
			if(checkedIn){
				cout<<"Check-in Time: "<<checkinHours<<"::"<<checkinMins<<endl;
			}
			cout<<"Check-out Time: "<<checkoutHours<<"::"<<checkoutMins<<endl;
			cout<<"Room Type: "<<roomtype<<endl;
			cout<<"Booking Type: "<<bookingType<<endl;
			cout<<"Active: "<<isActive<<endl;
			cout<<"Checked In: "<<checkedIn<<endl;
			cout<<"Checked Out: "<<checkedOut<<endl;
			//cout<<"NUM ID: "<<numID<<endl;
		}
		void checkOutBill(){
			cout<<"\t\t ****** TOTAL BILL ******"<<endl;
			cout<<endl;
			cout<<"Booking ID: "<<ID<<endl;
			cout<<"Member ID:"<<memberID<<endl;
			cout<<"Booking Start Date: "<<cdate<<"-"<<cmonth<<"-"<<cyear<<endl;
			cout<<"Check Out Date: "<<edate<<"-"<<emonth<<"-"<<eyear<<endl;
			cout<<"Package: "<<bookingType<<endl;
			cout<<"Cost Per Night: Rs."<<costPerNight<<endl;
			if(checkedOut){
				totalNightsSpent = countDays(sdate,smonth,syear,cdate,cmonth,cyear);
			}
			else{
				totalNightsSpent =countDays(sdate,smonth,syear,edate,emonth,eyear);
			}
		
			cout<<"Total Nights Spent: "<<totalNightsSpent<<endl;
			cout<<"Food Bill: Rs."<<foodCost<<endl;
			cout<<"Cleaning Bill: Rs."<<cleaningCost<<endl;
			int totalBill = (totalNightsSpent*costPerNight)+foodCost+cleaningCost;
			cout<<"Total Bill: Rs."<<totalBill;
			cout<<"\t\tTHANKS FOR STAYING WITH US  !"<<endl;
			cout<<"\t WE HOPE YOU'LL CHOOSE US FOR YOUR NEXT STAY!"<<endl;
		}
		
		
};

//Linked List
template <class T>
class NodeL{
	public:
		T data;
		NodeL* next;
		NodeL* prev;
		NodeL(){
			next = NULL;
			prev = NULL;
		}
		NodeL(T data){
			this->data = data;
			next = NULL;
			prev = NULL;
		}
};
template<class T>
class LinkedList{
	public:
		NodeL<T>* head;	
		LinkedList(){
			head = NULL;
		}
		void insert(T data){
			NodeL<T>* newNode = new NodeL<T>(data);
			if(head==NULL){
				head = newNode;
			}
			else{
				NodeL<T>*temp = head;
				while(temp->next!=NULL){
					temp = temp->next;
				}
				newNode->prev = temp;
				temp->next = newNode;
				
			}
		}
		
		void displayList(){
			if(head==NULL){
				cout<<"No list exists!!!";
				return;
			}
			NodeL<T>* temp = head;
			while(temp!=NULL){
				(temp->data).displayInfo();
				temp = temp->next;
				cout<<endl<<endl<<endl;
			}
		}
		NodeL<T>* searchNode(char* id){
			NodeL<T>* temp = head;
			while(temp!=NULL){
				if(strcmp((temp->data).ID,id)==0){
					return temp;
					break;
				}
				temp = temp->next;
			}
			return NULL;
		}
		bool deleteNode(char* id){
			NodeL<T>* temp = searchNode(id);
			if(temp==NULL||head==NULL){
				cout<<"Not Found\n";
				return false;
			}
			
			else{
				NodeL<T>* temp1;
				NodeL<T>* temp2;
				
				temp1 = temp->next;
				temp2 = temp->prev;
			
				delete temp;
				temp = temp2;
				temp->next = temp1;
				head = temp;
				//delete temp1;
				//delete temp2;
				return true;
			}
		}	
};

												//Linked List Functions
LinkedList<Member> memberList;
template<class T>
bool checkUniqueID(LinkedList<T>list,char*id){
	NodeL<T>*temp = list.head;
	while(temp!=NULL){
		if(strcmp(id,temp->data.ID)==0){
			return false;
		}
		temp = temp->next;
	}
	return true;
}
template<class T>
bool checkUniquePass(LinkedList<T>list,char* pass){
	NodeL<T>*temp = list.head;
	while(temp!=NULL){
		if(strcmp(pass,temp->data.password)==0){
			return false;
		}
		temp = temp->next;
	}
	return true;
}
template <class T>
void FillLinkedList(LinkedList<T>&list,char* fileName){
	ifstream obj;
	NodeL<T>* ptr = list.head;
	
	obj.open(fileName,ios::in|ios::binary);
	if(!obj){
		cout<<"File Not Found\n";
		return;
	}
	while(obj!=NULL){
		T temp;
	
		obj.read((char*)&temp, sizeof(temp));
		if(obj.eof()){
			break;
		}
		list.insert(temp);
		
	}
	obj.close();
}

template <class T>
void EmptyLinkedList(LinkedList<T>list,char* fileName){
	ofstream obj;
	obj.open(fileName,ios::trunc|ios::binary);
	NodeL<T>* ptr = list.head;
	
	if(!obj){
		cout<<"File not found\n";
		return;
	}
	
	while(ptr!=NULL){
		T temp = ptr->data;
		obj.write((char*)&temp, sizeof(temp));
		ptr = ptr->next;
	}
	obj.close();
}


NodeL<Member>* memberLogin(LinkedList<Member>obj,char*user,char*pass){
	NodeL<Member>* temp = obj.head;
	if(temp==NULL){
		return NULL;
	}
	while(temp!=NULL){
		if(temp->data.checkLogin(user,pass)){
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}
void loginMenu();												
void Signup(){
	char ID[N];
	char pass[N];
	char email[N];
	bool eflag = true;
	
	
	if(memberList.head!=NULL){
		do{
		cout<<"Email: ";
		cin>>email;
		 eflag = true;
		NodeL<Member>* temp = memberList.head;
		while(temp!=NULL){
		if(strcmp((temp->data).email,email)==0){
			cout<<"You Already Have An Account With This Email Address.";
			eflag = false;
			break;
		}
		temp = temp->next;
		}
		
		}while(eflag==false);
	}
	else{
		cout<<"Email: ";
		cin>>email;
	}
	cout<<"\t\t********** SIGN - UP **********"<<endl<<endl;
		cout<<"Username: ";
		cin>>ID;
		cout<<"Password: ";
		cin>>pass;
	if(memberList.head!=NULL){
		
		while(!checkUniqueID(memberList,ID)||!checkUniquePass(memberList,pass)||admin.check_login(ID,pass)){
			cout<<"Your Credentials  are not Unique\tPlease Try again"<<endl;
			system("pause");
			cout<<"Username: ";
			cin>>ID;
			cout<<"Password: ";
			cin>>pass;
		}
		
		
	}
	char fn[N/2];
	char ln[N/2];
	char ph[N];
	char cnic[N];
 	char cred[N];
 	cout<<"\t\t ***** ENTER YOUR DETAILS ***** "<<endl<<endl;
	cout<<"First Name: ";
	cin>>fn;
	cout<<"Last Name: ";
	cin>>ln;
	cout<<"Phone Number : ";
	cin>>ph;
	cout<<"CNIC : ";
	cin>>cnic;
	cout<<"Credit Card Number : ";
	cin>>cred;
	
	Member tempMember(ID,fn,ln,pass,ph,email,cnic,cred);
	memberList.insert(tempMember);
	EmptyLinkedList(memberList,"Members.dat");
	system("cls");
	tempMember.displayInfo();
	cout<<endl;
	system("pause");
	loginMenu();
	
}
//Binary Search Tree

template <class T>
class Node{
public:
    T data;
    Node* left;
    Node* right;
    
    Node(T data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


template <class T>
class BST{
public:
    Node<T>* addNode(T data){
            Node<T>* newNode = new Node<T>(data);
            return newNode;
    }
    
    Node<T>* InsertBST(Node<T>* root, T data){
        if(root == NULL)
            return addNode(data);
            
        else if(data.numID < (root->data).numID)
            root->left = InsertBST(root->left, data);
            
        else if(data.numID > (root->data).numID)
            root->right = InsertBST(root->right, data);
            
        return root;
    }
    
    Node<T>* minvaluenode(Node<T>* node){
        Node<T>* current = node;
        
        while(current -> left != NULL)
            current = current->left;
            
        return current;
    }
    
    
    Node<T>* Deletenode(Node<T>* root, T data){
        if(root == NULL)
            return NULL;
            
        else if(data.numID < root->data.numID)
            root->left = Deletenode(root->left, data);
            
        else if(data.numID > (root->data).numID)
            root->right = Deletenode(root->right, data);
            
        else{
            if(root->left == NULL){
                Node<T>* temp = root->right;
                delete root;
                return temp;
            }
            
            else if(root->right == NULL){
                Node<T>* temp = root->left;
                delete root;
                return temp;
            }
            
            else{
                Node<T>* temp = minvaluenode(root->right);
                root->data = temp->data;
                root->right = Deletenode(root->right, temp->data);
            }
        }
        return root;
    }
    
    Node<T>* SearchBST(Node<T>* root, int data){
        if(root == NULL)
            return NULL;
        
        else if(data == (root->data).numID)
            return root;
        
        else if(data < (root->data).numID)
            return SearchBST(root->left, data);
        
        else if(data > (root->data).numID)
            return SearchBST(root->right, data);
    }
    
    void Inorder(Node<T>* root){
        if(root == NULL)
            return;
            
        Inorder(root->left);
        (root->data).displayInfo();
		cout<<endl<<endl;
        Inorder(root->right);
    }
    
    int countNodes(Node<T>*root){
   		 int a = 0;
		if(root==NULL){
			return 0;
		}
		a = countNodes(root->left) +1;
		a = countNodes(root->right) +1;
		return a;
	}
    
};

Node<Booking>* rootBooking = NULL;
BST<Booking> bookingList;
Node<Staff>* rootStaff = NULL;
BST<Staff> staffList;
Node<Room>* rootRoom = NULL;
BST<Room> roomList;







//BST functions
template <class T>
void emptyTree(Node<T>* root,ofstream &file){
	if(root==NULL){
		return;
	}
	emptyTree(root->left,file);
	file.write((char*)&(root->data),sizeof(root->data));
	emptyTree(root->right,file);
	
}
template <class T>
Node<T>* fillTree(char*fileName){
	Node<T>* root = NULL;
	BST <T>obj;
	ifstream file(fileName,ios::in|ios::binary);
	if(file==NULL){
		cout<<"No file found\n";
		return NULL;
	}
	T temp;
	while(file){
		file.read((char*)&temp,sizeof(temp));
		
		if(!file){
			break;
		}
		root = obj.InsertBST(root,temp);
		
	}
	file.close();
	return root;
}

template <class T>
bool isIDUnique(Node<T>*root,int x){
	bool flag;
	if(root==NULL){
		return true;
	}
	if((root->data).numID==x){
		return false;
	}
	if(x>(root->data).numID){
		flag = isIDUnique(root->right,x);
	}
	else if(x<(root->data).numID){
		flag = isIDUnique(root->left,x);
	}
	return flag;
}
template <class T>
bool isPasswordUnique(Node<T>* root,char* x){
	bool flag = true;
	if(root==NULL){
		return true;
	}
	if(strcmp((root->data).password,x)==0){
		return false;
	}
	flag = isPasswordUnique(root->left,x);
	flag = isPasswordUnique(root->right,x);
	return flag;
}

void addRoom(){
	char ID[N];
	int numID;
	RandomID("RMN",ID);
	numID = charIDtointID(ID);
	if(rootRoom!=NULL){
		while(!isIDUnique<Room>(rootRoom,numID)){
				RandomID("RMN",ID);
				numID = charIDtointID(ID);
		}
	}
	ID[7] = '\0';
	int floorno;
	cout<<"Enter The Floor Number of The Room (1-10)";
	do{
		cin>>floorno;
	}while(floorno<1||floorno>10);
	char roomtype[N];
	int capacity;
	int choice;
		do{
			cout<<"Select the Room Type\n\n\n1.Single\n2.Double\n3.Quad\n4.Suite\n5.King: ";
			cin>>choice;
			switch(choice){
				case 1:
					strcpy(roomtype,"Single");

					break;
				case 2:
					strcpy(roomtype,"Double");
					break;
				case 3:
					strcpy(roomtype,"Quad");
					break;
				case 4:
					strcpy(roomtype,"Suite");
					break;
				case 5:
					strcpy(roomtype,"King");
					break;
				case 6:
					cout<<"Wrong choice: ";
					break;
			}
		}while(choice<1||choice>5);	
		Room tempRoom(roomtype,ID,floorno);
		tempRoom.displayInfo();
		rootRoom = roomList.InsertBST(rootRoom,tempRoom);
		ofstream fileRoom("Rooms.dat",ios::trunc|ios::binary);
		emptyTree<Room>(rootRoom,fileRoom);
		fileRoom.close();
}

void editRoom(){
	system("cls");
	roomList.Inorder(rootRoom);
	cout<<endl<<endl<<endl;
	char ID[N];
	cout<<"Enter the ROOM ID: ";
	cin>>ID;
	if(ID[0]!='R'||ID[1]!='M'||ID[2]!='N'){
		cout<<"Invalid Room ID"<<endl;
		return;
	}
	int tempID = charIDtointID(ID);
	Node<Room>* temp;
	temp = roomList.SearchBST(rootRoom,tempID);
	if(temp==NULL){
		cout<<"No Record Found\n";
		return;
	}

	if((temp->data).isBooked){
		cout<<"This Room is Already Booked. No Alterations Can Be Made."<<endl;
		return;
	}

		int choice;
		char roomtype[N];
		do{
			cout<<"Select the Room Type\n\n\n1.Single\n2.Double\n3.Quad\n4.King:\n ";
			cin>>choice;
			switch(choice){
				case 1:
					strcpy(roomtype,"Single");
					break;
				case 2:
					strcpy(roomtype,"Double");
					break;
				case 3:
					strcpy(roomtype,"Quad");
					break;
			
				case 4:
					strcpy(roomtype,"King");
					break;
				case 5:
					cout<<"Wrong choice: ";
					break;
			}
		}while(choice<1||choice>4);
		strcpy((temp->data).roomtype,roomtype);
		
	ofstream fileRoom("Rooms.dat",ios::trunc|ios::binary);
	emptyTree<Room>(rootRoom,fileRoom);
	fileRoom.close();
	
}

void deleteRoom(){
	if(rootRoom!=NULL){
			roomList.Inorder(rootRoom);
			cout<<endl<<endl<<endl;
			char ID[N];
			cout<<"Enter the Room ID: ";
			cin>>ID;
			if(ID[0]!='R'||ID[1]!='M'||ID[2]!='N'){
				cout<<"Invalid Room ID"<<endl;
				return;
			}
			int tempID = charIDtointID(ID);
			Node<Room>* temp = roomList.SearchBST(rootRoom,tempID);
			if(temp==NULL){
				cout<<"No Data Found\n";
				return;	
			}
			if((temp->data).isBooked){
				cout<<"This Room is Currently Booked, therefore cannot be deleted yet."<<endl;
				return;
			}
			rootRoom = roomList.Deletenode(rootRoom,temp->data);
	}
	else{
		cout<<"No Records Available\n";
	}
	ofstream fileRoom("Rooms.dat",ios::trunc|ios::binary);
	emptyTree<Room>(rootRoom,fileRoom);
	fileRoom.close();
}
Node<Staff>* staffLogin(char* ID,char *pass,Node<Staff>* root){
	Node<Staff>* x;
	if(root==NULL){
		return NULL;
	}
	if(ID[0]!='S'||ID[1]!='T'||ID[2]!='F'){
		return NULL;
	}
	
	x = staffList.SearchBST(rootStaff,charIDtointID(ID));
	if(x==NULL){
		return NULL;
	}
	if((x->data).checkLogin(ID,pass)){
		return x;
	}
	/*
	x = staffLogin(ID,pass,root->left);
	if((root->data).checkLogin(ID,pass)){
	return root;
	}
	x =  staffLogin(ID,pass,root->right);
	
	return x;
	*/
	
}

void addStaff(){
	time_t now = time(0);
	tm* ltm = localtime(&now);
	char ID[N];
	char pass[N];
	int op;
	char fn[N];
	char ln[N];
	int age;
	long salary;
	char ph[11];
	char email[N];
	char homeaddress[N];
	int joindate,joinmonth,joinyear;
	char position[N];
	char dob[N];
	RandomID("STF",ID);
	RandomPassword(pass);
	ID[7] = '\0';
	pass[7] = '\0';
	cout<<"*********************** STAFF REGISTRATION ******************************"<<endl;
	cout<<"First Name: ";
	cin>>fn;
	cout<<"Last Name: ";
	cin>>ln;
	cout<<"Enter Date Of Birth: ";
	cin>>dob;
	cout<<"Enter age";
	cin>>age;
	cout<<"Enter Email ID";
	cin>>email;
	cout<<"Enter Phone Number";
	cin>>ph;
	cout<<"Enter Home Address (without space)";
	cin>>homeaddress;
	joindate = ltm->tm_mday;joinmonth = ltm->tm_mon+1;joinyear = ltm->tm_year+1900;
	cout<<"Enter Salary";
	cin>>salary;
	cout<<"Choose an option for position of employee: "<<endl<<endl;
	cout<<"1.Cleaner"<<endl;
	cout<<"2.Front desk operator"<<endl;
	cout<<"3.Restaurant Staff"<<endl;
	cout<<"4.Guard"<<endl;
	cout<<"5.IT expert"<<endl;
	do{
	cin>>op;
	switch (op){
		case 1:
			strcpy(position,"Cleaner");
			break;
		case 2:
			strcpy(position,"FrontDeskOperator");
			break;
	    case 3:
	    	strcpy(position,"RestaurantStaff");
			break;
		case 4:
			strcpy(position,"Guard");
			break;
		case 5:
			strcpy(position,"ITExpert");
			break;
		default:
			cout<<"Wrong Choice"<<endl;
	}
	}while(op<1||op>6);
	//Staff tempStaff(ID,pass,"AhmedMustafa",20,"ahmedmustafa700@gmail.com","Johar Karachi","03132538919","Manager",50000,"24/7/2002",25,7,2002);
	Staff tempStaff(ID,pass,fn,ln,age,email,homeaddress,ph,position,salary,dob,joindate,joinmonth,joinyear);
	system("cls");
	tempStaff.displayInfo();
	rootStaff = staffList.InsertBST(rootStaff,tempStaff);
	ofstream fileStaff("Staff.dat",ios::trunc|ios::binary);
	emptyTree<Staff>(rootStaff,fileStaff);
	fileStaff.close();

	
	
}
void deleteStaff(){
	cout<<"********** STAFF DELETION **********"<<endl<<endl<<endl<<endl;
	char ID[N];
	cout<<"Staff ID: ";
	cin>>ID;
	if(ID[0]!='S'||ID[1]!='T'||ID[2]!='F'){
		cout<<"Invalid Staff ID"<<endl;
		return;
	}
	int tempID = charIDtointID(ID);
	if(rootStaff!=NULL){
			Node<Staff>* temp = staffList.SearchBST(rootStaff,tempID);
			if(temp==NULL){
				cout<<"No Record Exists\n";
			}
			rootStaff = staffList.Deletenode(rootStaff,temp->data);
	}
	else{
		cout<<"No List Exists\n";
	}
	ofstream fileStaff("Staff.dat",ios::trunc|ios::binary);
	emptyTree<Staff>(rootStaff,fileStaff);
	fileStaff.close();

}
void editStaff(){
	staffList.Inorder(rootStaff);
	cout<<endl<<endl<<endl;
	char newPass[N];
	char ID[N];
	cout<<"Staff ID: ";
	cin>>ID;
	if(ID[0]!='S'||ID[1]!='T'||ID[2]!='F'){
		cout<<"Invalid Staff ID"<<endl;
		return;
	}
	int tempID = charIDtointID(ID);
	Node<Staff>* temp = staffList.SearchBST(rootStaff,tempID);
	if(temp==NULL){
		cout<<"No Record Found\n";
		return;
	}
	else{
		int choice;
		cout<<"\t\t***** DATA UPDATE MENU ******"<<endl<<endl;
		cout<<"1.Update Password\n2.Update Email\n3.Update Address\n4.Update Phone Number";
		do{
			cin>>choice;
			switch(choice){
				case 1:
					do{
					
					cout<<"Enter the New Password: ";
					cin>>newPass;
					}while(strcmp(admin.password,newPass)==0||!isPasswordUnique<Staff>(rootStaff,newPass));
					strcpy((temp->data).password,newPass);
					break;
				case 2:
					char newEmail[N];
					cout<<"Enter the New Email: ";
					cin>>newEmail;
					strcpy((temp->data).email,newEmail);
					break;
				case 3:
					char newAddress[N];
					cout<<"Enter the New Address: ";
					cin>>newAddress;
					strcpy((temp->data).homeAddress,newEmail);					
					break;
				case 4:
					char newPh[N];
					cout<<"Enter the new Phone Number: ";
					cin>>newPh;
					strcpy((temp->data).phoneNo,newPh);
					break;
				default:
					break;
			}
			
		}while(choice<1||choice>4);
		
		
	}
	ofstream fileStaff("Staff.dat",ios::trunc|ios::binary);
	emptyTree<Staff>(rootStaff,fileStaff);
	fileStaff.close();	
}

Node<Room>* searchSuitableRoom(Node<Room>* root,char*roomType,int sdate,int smonth,int syear){
	Node<Room>* x;
	if(root==NULL){
		return NULL;
	}
	if(strcmp((root->data).roomtype,roomType)==0){
		if(!(root->data).isBooked){
			return root;
		}
		else{
			Node<Booking>* tempBooking = bookingList.SearchBST(rootBooking,charIDtointID((root->data).bookingID));
			int ed = (tempBooking->data).edate,em = (tempBooking->data).emonth,ey = (tempBooking->data).eyear;
			if(countDays(sdate,smonth,syear,ed,em,ey)<=0){
				return root;
			}
		}
	}
	x = searchSuitableRoom(root->left,roomType,sdate,smonth,syear);
	x = searchSuitableRoom(root->right,roomType,sdate,smonth,syear);
	return x;
}

/*
void displayMinimumAvailable(Node<Booking>*root,char* roomType,int min){


	
}
*/
void countAvailableRooms(Node<Room>*root,int*array);
void addBooking(Member mem){
	//Booking(char* id,char*mID,int sdate,int smonth,int syear,int edate,int emonth,int eyear,int roomno,int floorno,int checkinHour,int checkinMins,char* roomtype,char*roomid)
	time_t now = time(0);
	tm* ltm = localtime(&now);
	char ID[N];
	RandomID("BKN",ID);
	int tempID = charIDtointID(ID);
	if(rootBooking!=NULL){
		while(!isIDUnique(rootBooking,tempID)){
			RandomID("BKN",ID);
			tempID = charIDtointID(ID);
		}
	}
	ID[7] = '\0';
	int sdate,smonth,syear;
	int edate,emonth,eyear;
	int d = ltm->tm_mday,mo = ltm->tm_mon+1,y = ltm->tm_year+1900;
	int cost;
	int xchoice;
	int rc[5] = {0,0,0,0,0};
	countAvailableRooms(rootRoom,rc);
label:	
	system("cls");
	cout<<"Booking ID: "<<ID<<endl;
	do{
	cout<<"Enter the Booking start Day: ";
	cin>>sdate;
	cout<<"Enter the Booking start Month: ";
	cin>>smonth;
	cout<<"Enter the Booking start Year: ";
	cin>>syear;
	if(countDays(sdate,smonth,syear,d,mo,y)>0||!isDateCorrect(sdate,smonth,syear)){
		cout<<"\n\nWrong Date Entered"<<endl;
	}
	}while(countDays(sdate,smonth,syear,d,mo,y)>0||!isDateCorrect(sdate,smonth,syear));
	
	
	/*
	sdate = ltm->tm_mday;
	smonth = ltm->tm_mon+1;
	syear = ltm->tm_year+1900;
	*/
	//cout<<sdate<<" "<<smonth<<" "<<syear<<" ";
	do{
	cout<<"Enter Booking End Day: ";
	cin>>edate;
	cout<<"Enter Booking End Day: ";
	cin>>emonth;
	cout<<"Enter Booking End Day: ";
	cin>>eyear;
	if(countDays(sdate,smonth,syear,edate,emonth,eyear)<1||!isDateCorrect(edate,emonth,eyear)){
		cout<<"\n\nWrong Date Entered"<<endl;
	}
	}while(countDays(sdate,smonth,syear,edate,emonth,eyear)<1||!isDateCorrect(edate,emonth,eyear));
	Node<Room>* tempRoom;
	char package[N];
	cout<<"Select Package:\n1.Premium Single Rooms Available\t1 Person Only"<<endl;
	cout<<"2.Budget Single Rooms Available\t1 Person Only"<<endl;
	cout<<"3.Budget Double\t2 People Only"<<endl;
	cout<<"4.Premium Double\t2 People Only"<<endl;
	cout<<"5.Suite\t5 People Only"<<endl;
	cout<<"6.King\t1 Person Only"<<endl;
	cout<<"7.Premium Quad\t4 People Only"<<endl;
	cout<<"8.Budget Quad\t4 People Only"<<endl;
	int choice;
	do{
		cin>>choice;
		switch(choice){
			case 1:
				strcpy(package,"Premium Single");
				tempRoom = searchSuitableRoom(rootRoom,"Single",sdate,smonth,syear);
				cost = 5700;
				break;
			case 2:
				strcpy(package,"Budget Single");
				tempRoom = searchSuitableRoom(rootRoom,"Single",sdate,smonth,syear);
				cost = 8900;
				break;
			case 3:
				strcpy(package,"Budget Double");
				tempRoom = searchSuitableRoom(rootRoom,"Double",sdate,smonth,syear);
				cost = 7700;
				break;
			case 4:
				strcpy(package,"Premium Double");
				tempRoom = searchSuitableRoom(rootRoom,"Double",sdate,smonth,syear);
				cost = 9900;
				break;
			case 5:
				strcpy(package,"Suite");
				tempRoom = searchSuitableRoom(rootRoom,"Suite",sdate,smonth,syear);
				cost = 12900;
				break;
			case 6:
				strcpy(package,"King");
				tempRoom = searchSuitableRoom(rootRoom,"King",sdate,smonth,syear);
				cost = 14900;
				break;
			case 7:
				strcpy(package,"Premium Quad");
				tempRoom = searchSuitableRoom(rootRoom,"Quad",sdate,smonth,syear);
				cost =11900;
				break;
			case 8:
				strcpy(package,"Budget Quad");
				tempRoom = searchSuitableRoom(rootRoom,"Quad",sdate,smonth,syear);
				cost = 9700;
				break;
			default:
				cout<<"Wrong Choice"<<endl;
				break;
				
		}
	}while(choice<1||choice>8);
	if(tempRoom==NULL){
		cout<<"No Rooms Available"<<endl;
		return;
	}
	
	int h = ltm->tm_hour;
	int m = ltm->tm_min;
	int oh = h;
	int om = m;
	int nop;
	do{
		cout<<"Enter the number of people: ";
		cin>>nop;
		
	}while(nop>(tempRoom->data).capacity||nop<0);
	
	
	
	cout<<"1.Proceed with the Booking\t2.Return To Menu\t(Any Digit).Re-Enter the Booking Details"<<endl;
	cin>>xchoice;
	if(xchoice==2){
		return;
	}
	if(xchoice!=1&&xchoice!=2){
		goto label;
	}
	
	strcpy((tempRoom->data).bookingID,ID);
	(tempRoom->data).isBooked = true;
	Booking tempBooking(ID,mem.ID,sdate,smonth,syear,edate,emonth,eyear,(tempRoom->data).floorno,nop,(tempRoom->data).roomtype,(tempRoom->data).ID,package,oh,om);
	tempBooking.costPerNight = cost;
	//tempBooking.showbookingadmin();
	rootBooking = bookingList.InsertBST(rootBooking,tempBooking);
	ofstream fileBooking("Bookings.dat",ios::trunc|ios::binary);
	emptyTree<Booking>(rootBooking,fileBooking);
	fileBooking.close();
	
	ofstream fileRoom("Rooms.dat",ios::trunc|ios::binary);
	emptyTree<Room>(rootRoom,fileRoom);
	fileRoom.close();
}
void checkIn(){
	cout<<"\t\t***** CHECK-IN MENU *****"<<endl<<endl;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	int d = ltm->tm_mday,m = ltm->tm_mon+1,y = ltm->tm_year+1900;
	char ID[N];
	char memID[N];
	cout<<"Enter The Booking ID: ";
	cin>>ID;
	if(ID[0]!='B'||ID[1]!='K'||ID[2]!='N'){
		cout<<"Invalid Booking ID"<<endl;
		return;
	}
	cout<<"Enter the MemberID: ";
	cin>>memID;
	int tempID = charIDtointID(ID);
	Node<Booking>* tempBooking = bookingList.SearchBST(rootBooking,tempID);
	if(tempBooking==NULL){
		cout<<"Sorry This Booking ID Is Not Valid."<<endl;
		system("pause");
		return;
	}
	if(!(tempBooking->data).isActive){
		cout<<"This Booking Has Expired"<<endl;
		return;
	}
	if(strcmp((tempBooking->data).memberID,memID)!=0){
		cout<<"The Member ID and Booking ID donot match."<<endl;
			system("pause");
		return;
	}
	if(countDays(d,m,y,(tempBooking->data).sdate,(tempBooking->data).smonth,(tempBooking->data).syear)>0){
		cout<<"The Booking Will Start in "<<countDays(d,m,y,(tempBooking->data).sdate,(tempBooking->data).smonth,(tempBooking->data).syear)<<" days."<<endl;
		system("pause");
		return;
	}
	if((tempBooking->data).checkedIn){
		cout<<"You have already checked In"<<endl;
		system("pause");
		return;
	}
	if(!(tempBooking->data).isActive){
		cout<<"Sorry This Booking Has Expired."<<endl;
		system("pause");
		return;
	}
	


	(tempBooking->data).checkinHours = ltm->tm_hour;
	(tempBooking->data).checkinMins = ltm->tm_min;
	(tempBooking->data).checkedIn = true;
	cout<<"Successfully Checked In\n";
	
	ofstream fileBooking("Bookings.dat",ios::trunc|ios::binary);
	emptyTree<Booking>(rootBooking,fileBooking);
	fileBooking.close();
	

}
void checkOut(){
	char ID[N];
	cout<<"\t\t***** CHECK-OUT MENU *****"<<endl<<endl;
	cout<<"Enter ID: ";
	cin>>ID;
	if(ID[0]!='B'||ID[1]!='K'||ID[2]!='N'){
		cout<<"Invalid Booking ID"<<endl;
		return;
	}
	char memID[N];
	cout<<"Enter Member ID: ";
	cin>>memID;
	int tempID = charIDtointID(ID);
	Node<Booking>* tempBooking = bookingList.SearchBST(rootBooking,tempID);
	if(!(tempBooking->data).isActive){
		cout<<"Sorry This Booking Has Expired."<<endl;
		system("pause");
		return;
	}
	if(strcmp((tempBooking->data).memberID,memID)!=0){
		cout<<"The Member ID and Booking ID donot match."<<endl;
		system("pause");
		return;
	}
	time_t now = time(0);
	tm* ltm = localtime(&now);
	if(!(tempBooking->data).checkedIn){
		cout<<"This Member Has Not Checked In."<<endl;
			system("pause");
		return;
	}
	int d = ltm->tm_mday,m =ltm->tm_mon+ 1 ,y = ltm->tm_year+1900;
	if(countDays((tempBooking->data).sdate,(tempBooking->data).smonth,(tempBooking->data).syear,d,m,y)==0){
		cout<<"You Have To Stay 1 Night before You Can Check-Out"<<endl;
		return;
	}
	//Booking temp;
	(tempBooking->data).cdate =  ltm->tm_mday;
	(tempBooking->data).cmonth = ltm->tm_mon+ 1;
	(tempBooking->data).cyear = ltm->tm_year+1900;
	(tempBooking->data).checkoutHours = ltm->tm_hour;
	(tempBooking->data).checkoutMins = ltm->tm_min;
	int tempRoomID = charIDtointID((tempBooking->data).roomID);
	Node<Room>*tempRoom = roomList.SearchBST(rootRoom,tempRoomID);
	(tempRoom->data).isBooked = false;
	(tempBooking->data).isActive = false;
	(tempBooking->data).checkedOut = true;
	system("cls");
	(tempBooking->data).checkOutBill();
	system("pause");
	
	
	
	ofstream fileBooking("Bookings.dat",ios::trunc|ios::binary);
	emptyTree<Booking>(rootBooking,fileBooking);
	fileBooking.close();
	ofstream fileRoom("Rooms.dat",ios::trunc|ios::binary);
	emptyTree<Room>(rootRoom,fileRoom);
	fileRoom.close();
}

void displayAllBooking(){
	bookingList.Inorder(rootBooking);
}
void displayActiveBooking(Node<Booking>*root){
	if(root==NULL){
		return;
	}
	displayActiveBooking(root->left);
	if((root->data).isActive){
		(root->data).displayInfo();
	}
	displayActiveBooking(root->right);
}
void displayPastBooking(Node<Booking>*root){
	if(root==NULL){
		return;
	}
	displayPastBooking(root->left);
	if((root->data).isActive==false){
		(root->data).displayInfo();
	}
	displayPastBooking(root->right);
	
}
void searchBooking(){
	bookingList.Inorder(rootBooking);
	cout<<endl<<endl<<endl;
	cout<<"\t\t SEARCH BOOKING"<<endl<<endl;
	char ID[N];
	cout<<"ID: ";
	cin>>ID;
	if(ID[0]!='B'||ID[1]!='K'||ID[2]!='N'){
		cout<<"Invalid Booking ID"<<endl;
		return;
	}
	int tempID = charIDtointID(ID);
	Node<Booking>* tempBooking = bookingList.SearchBST(rootBooking,tempID);
	if(tempBooking==NULL){
		cout<<"No Record Exists\n";
	}
	else{
		(tempBooking->data).displayInfo();
	}
}

void displayActiveBooking(Node<Booking>* root,Member tempMember){
	if(root==NULL){
		return;
	}
	displayActiveBooking(root->left,tempMember);
	if(strcmp(tempMember.ID,(root->data).memberID)==0&&(root->data).isActive){
		(root->data).showbookingmember();
	}
	displayActiveBooking(root->right,tempMember);
	
}
void displayPastBooking(Node<Booking>* root,Member tempMember){
	if(root==NULL){
		return;
	}
	displayPastBooking(root->left,tempMember);
	if(strcmp(tempMember.ID,(root->data).memberID)==0&&!(root->data).isActive){
		(root->data).showbookingmember();
	}
	displayPastBooking(root->right,tempMember);
	
}

int foodMenu(){
	int quantity,op,price=0,tbill=0;
	system("cls");
	do{
		cout<<"*********************************************************"<<endl;
		cout<<"Press numeric keys for desired item"<<endl;
		cout<<"*********************** DESI ****************************"<<endl;
		cout<<"1.Biryani               RS.300"<<endl;
		cout<<"2.Chicken karahi        RS.700"<<endl;
		cout<<"3.Daal                  RS.250"<<endl;
		cout<<"4.Chicken qeema         RS.450"<<endl;
		cout<<"5.Tandoor Roti          RS.25"<<endl;
		cout<<"********************* Fast Food *************************"<<endl;
		cout<<"6.Chicken Burger        RS.350"<<endl;
		cout<<"7.Alfredo Pasta         RS.750"<<endl;
		cout<<"8.Chicken Broast        RS.450"<<endl;
		cout<<"9.Club Sandwich         RS.500"<<endl;
		cout<<"10.Beef Mushroom Burger RS.370"<<endl;
		cout<<"*********************** BBQ *****************************"<<endl;
		cout<<"11.Chicken Tikka        RS.390"<<endl;
		cout<<"12.Chicken Malai Boti   RS.420"<<endl;
		cout<<"13.Beef Seekh Kabab     RS.450"<<endl;
		cout<<"14.BBQ Platter          RS.950"<<endl;
		cout<<"15.Shrimp Tikka         RS.1225"<<endl;
		cout<<"********************* Drinks & Sides ********************"<<endl;
		cout<<"16.Coke                 RS.70"<<endl;
		cout<<"17.Sprite               RS.70"<<endl;
		cout<<"18.Lemonade             RS.150"<<endl;
		cout<<"19.Garden Salad         RS.170"<<endl;
		cout<<"20.Raita                RS.85"<<endl;
		cout<<"0.exit"<<endl;
        cin>>op;
        switch(op){
       	case 1:
        		cout<<"Enter Quantity";
        		cin>>quantity;
        		price=300*quantity;
        		tbill=tbill+price;
        		break;
		case 2:
        		cout<<"enter quantity";
        		cin>>quantity;
        		price=700*quantity;
        		tbill=tbill+price;
        		break;
        case 3:
        		cout<<"enter quantity";
        		cin>>quantity;
        		price=250*quantity;
        		tbill=tbill+price;
        		break;
		case 4:
        		cout<<"enter quantity";
        		cin>>quantity;
        		price=450*quantity;
        		tbill=tbill+price;
        		break;
       	case 5:
        		cout<<"enter quantity";
        		cin>>quantity;
        		price=25*quantity;
        		tbill=tbill+price;
        		break;
		case 6:
        		cout<<"enter quantity";
        		cin>>quantity;
        		price=350*quantity;
        		tbill=tbill+price;
        		break;
       	case 7:
        		cout<<"enter quantity";
        		cin>>quantity;
        		price=750*quantity;
        		tbill=tbill+price;
        		break;
		case 8:
        		cout<<"enter quantity";
        		cin>>quantity;
        		price=45*quantity;
        		tbill=tbill+price;
        		break;
       	case 9:
        		cout<<"enter quantity";
        		cin>>quantity;
        		price=500*quantity;
        		tbill=tbill+price;
        		break;
		case 10:
        		cout<<"enter quantity";
        		cin>>quantity;
        		price=370*quantity;
        		tbill=tbill+price;
        		break;
       	case 11:
        		cout<<"enter quantity";
        		cin>>quantity;
        		price=390*quantity;
        		tbill=tbill+price;
        		break;
		case 12:
        		cout<<"enter quantity";
        		cin>>quantity;
        		price=420*quantity;
        		tbill=tbill+price;
        		break;
       	case 13:
        		cout<<"enter quantity";
        		cin>>quantity;
        		price=450*quantity;
        		tbill=tbill+price;
        		break;
		case 14:
        		cout<<"enter quantity";
        		cin>>quantity;
        		price=950*quantity;
        		tbill=tbill+price;
        		break;
       	case 15:
        		cout<<"enter quantity";
        		cin>>quantity;
        		price=1225*quantity;
        		tbill=tbill+price;
        		break;
		case 16:
        		cout<<"enter quantity";
        		cin>>quantity;
        		price=70*quantity;
        		tbill=tbill+price;
        		break;
       	case 17:
        		cout<<"enter quantity";
        		cin>>quantity;
        		price=70*quantity;
        		tbill=tbill+price;
        		break;
		case 18:
        		cout<<"enter quantity";
        		cin>>quantity;
        		price=150*quantity;
        		tbill=tbill+price;
        		break;
       	case 19:
        		cout<<"enter quantity";
        		cin>>quantity;
        		price=170*quantity;
        		tbill=tbill+price;
        		break;
		case 20:
        		cout<<"enter quantity";
        		cin>>quantity;
        		price=85*quantity;
        		tbill=tbill+price;
        		break;
			default:
				
				break;
		}
		cout<<"\t\tTotal Bill = RS."<<tbill<<endl;
	}while(op!=0);
	return tbill;
	
}

void countRooms(Node<Room>*root,int* array){
	if(root==NULL){
		return;
	}
	countRooms(root->left,array);
	if(strcmp(root->data.roomtype,"Single")==0){
		array[0]+=1;
	}
	else if(strcmp(root->data.roomtype,"Double")==0){
		array[1]+=1;
	}
	else if(strcmp(root->data.roomtype,"Quad")==0){
		array[2]+=1;
	}
	else if(strcmp(root->data.roomtype,"King")==0){
		array[3]+=1;
	}
	else if(strcmp(root->data.roomtype,"Suite")==0){
		array[4]+=1;
	}
	countRooms(root->right,array);
	
}
void countAvailableRooms(Node<Room>*root,int* array){
	if(root==NULL){
		return;
	}
	countAvailableRooms(root->left,array);
	if(strcmp(root->data.roomtype,"Single")==0&&!(root->data).isBooked){
		array[0]+=1;
	}
	else if(strcmp(root->data.roomtype,"Double")==0&&!(root->data).isBooked){
		array[1]+=1;
	}
	else if(strcmp(root->data.roomtype,"Quad")==0&&!(root->data).isBooked){
		array[2]+=1;
	}
	else if(strcmp(root->data.roomtype,"King")==0&&!(root->data).isBooked){
		array[3]+=1;
	}
	else if(strcmp(root->data.roomtype,"Suite")==0&&!(root->data).isBooked){
		array[4]+=1;
	}
	countAvailableRooms(root->right,array);
	
}

int countMembers(){
	NodeL<Member>* temp = memberList.head;
	int count = 0;
	while(temp!=NULL){
		++count;
		temp = temp->next;
	}
	return count;
}

void countStaff(Node<Staff>*root,int*array){
	if(root==NULL){
		return;
	}
	countStaff(root->left,array);
	if(strcmp((root->data).jobDescription,"FrontDeskOperator")==0){
		++array[0];
	}
	else if(strcmp((root->data).jobDescription,"Cleaner")==0){
		++array[1];
	}
	else if(strcmp((root->data).jobDescription,"RestaurantStaff")==0){
		++array[2];
	}
	else if(strcmp((root->data).jobDescription,"Guard")==0){
		++array[3];
	}
	else if(strcmp((root->data).jobDescription,"ITExpert")==0){
		++array[4];
	}
	countStaff(root->right,array);
}

void processFoodOrder(){
	char bookingID[N];
	char memberID[N];
	cout<<"\t\t***** RESTURANT MENU *****"<<endl<<endl;
	cout<<"Enter The Booking ID: ";
	cin>>bookingID;
	if(bookingID[0]!='B'||bookingID[1]!='K'||bookingID[2]!='N'){
		cout<<"Invalid Booking ID"<<endl;
		return;
	}
	cout<<"Enter The Member ID: ";
	cin>>memberID;
	int tempID = charIDtointID(bookingID);
	Node<Booking>* temp = bookingList.SearchBST(rootBooking,tempID);
	if(temp==NULL){
		cout<<"This Booking ID is Invalid\n";
		return;
	}
	if(!(temp->data).isActive){
		cout<<"This Booking Has Expired"<<endl;
		return;
	}
	if(strcmp((temp->data).memberID,memberID)!=0){
		cout<<"Booking and Member ID donot match."<<endl;
		return;
	}
	if(!(temp->data).checkedIn){
		cout<<"This Member Has Not Checked In Yet"<<endl;
		return;
	}
	int bill = foodMenu();
	(temp->data).foodCost+= bill;
	ofstream fileBooking("Bookings.dat",ios::trunc|ios::binary);
	emptyTree<Booking>(rootBooking,fileBooking);
	fileBooking.close();	
}
int cleaningMenu(){
	int cop,qnt,total=0,tbill=0;
	
	system("cls");
do{
		//system("cls");
	cout<<endl<<"***** CLEANING PACKAGES *****"<<endl;
	cout<<"\t Choose an option "<<endl;
	cout<<"1. Dry Cleaning \t RS.200/piece"<<endl;
	cout<<"2. Ironing \t         RS.100/piece "<<endl;
	cout<<"3. Shoe Polishing \t RS.100/pair"<<endl;
	cout<<"4. Room Cleaning \t FREE "<<endl;
	cout<<"0. Exit"<<endl;
	cin>>cop;
	//do{
	//cin>>cop;
	switch(cop){
		case 1:
			cout<<"Enter number of items"<<endl;
			cin>>qnt;
			total=200*qnt;
			tbill+=total;
			//cout<<"Your Total Amount Is: Rs."<<total<<endl;
			cout<<"Your Clothes will Be collected from your room within 15 minutes"<<endl;
			break;
		case 2:
			cout<<"Enter number of items"<<endl;
			cin>>qnt;
			total=100*qnt;
			tbill+=total;
			//cout<<"Your Total Amount Is: Rs."<<total<<endl;
			cout<<"Your Clothes will Be collected from your room within 15 minutes!"<<endl;
			break;
		case 3:
			cout<<"Enter number of pairs"<<endl;
			cin>>qnt;
			total=200*qnt;
			tbill+=total;
			//cout<<"Your Total Amount Is: Rs."<<total<<endl;
			cout<<"Your Shoes will Be collected from your room within 15 minutes!"<<endl;
			break;
		case 4:
			cout<<"Cleaner will be sent to your room once its available!"<<endl;
			break;
		case 0:
			break;
		default:
			cout<<"Wrong Choice"<<endl;
	}
	cout<<"Your Total Bill is: "<<tbill<<endl;
}while(cop!=0);
return tbill;
}
void processCleaningOrder(){
	system("cls");
	cout<<"\t\t***** CLEANING MENU *****"<<endl<<endl;
	char bookingID[N];
	char memberID[N];
	cout<<"Enter The Booking ID: ";
	cin>>bookingID;
	if(bookingID[0]!='B'||bookingID[1]!='K'||bookingID[2]!='N'){
		cout<<"Invalid Booking ID"<<endl;
		return;
	}
	cout<<"Enter The Member ID: ";
	cin>>memberID;
	int tempID = charIDtointID(bookingID);
	Node<Booking>* temp = bookingList.SearchBST(rootBooking,tempID);
	if(temp==NULL){
		cout<<"This Booking ID is Invalid\n";
		return;
	}
	if(!(temp->data).isActive){
		cout<<"This Booking Has Expired"<<endl;
		return;
	}
	if(strcmp((temp->data).memberID,memberID)!=0){
		cout<<"Booking and Member ID donot match."<<endl;
		return;
	}
	if(!(temp->data).checkedIn){
		cout<<"This Member Has Not Checked In Yet"<<endl;
		return;
	}
	int bill = cleaningMenu();
	(temp->data).cleaningCost+=bill;
	ofstream fileRoom("Rooms.dat",ios::trunc|ios::binary);
	emptyTree<Room>(rootRoom,fileRoom);
	fileRoom.close();
	ofstream fileBooking("Bookings.dat",ios::trunc|ios::binary);
	emptyTree<Booking>(rootBooking,fileBooking);
	fileBooking.close();
}


void loginMenu();
void adminMenu(){
	  system("cls");
	  cout<<"*************************ADMIN MENU*************************"<<endl;
	  for(int i=0;i<5;++i){
	  	roomcount[i] = 0;
	  }
	  for(int i=0;i<5;++i){
	  	staffCount[i] = 0;
	  }
	  countAvailableRooms(rootRoom,roomcount);
	  countStaff(rootStaff,staffCount);
	  cout<<"Available Rooms\t\t\tTotal Staff Members\t\t\t"<<"TotalMembers: "<<countMembers()<<endl;
	  cout<<"Single: "<<roomcount[0]<<"\t\t\tFront Desk: "<<staffCount[0]<<endl;
	  cout<<"Double: "<<roomcount[1]<<"\t\t\tCleaner: "<<staffCount[1]<<endl;
	  cout<<"Quad: "<<roomcount[2]<<"\t\t\t\tRestaurant Staff: "<<staffCount[2]<<endl;
	  cout<<"King: "<<roomcount[3]<<"\t\t\t\tGuard: "<<staffCount[3]<<endl;
	  cout<<"Suite: "<<roomcount[4]<<"\t\t\tIT Expert: "<<staffCount[4]<<endl;
	  cout<<endl;
	  int choice;
	  cout<<"\t\t\tPress '1' to View All Booking Records."<<endl;
	  cout<<"\t\t\tPress '2' to View Past Booking Records."<<endl;
	  cout<<"\t\t\tPress '3' to View Active Booking Records."<<endl;
	  cout<<"\t\t\tPress '4' to Search the booking records."<<endl;
	  cout<<"\t\t\tPress '5' to View all Rooms."<<endl;
	  cout<<"\t\t\tPress '6' to Add a room."<<endl;
	  cout<<"\t\t\tPress '7' to Edit a room info."<<endl;
	  cout<<"\t\t\tPress '8' to Delete a room."<<endl;
	  cout<<"\t\t\tPress '9' to View All Members Info."<<endl;
	  cout<<"\t\t\tPress '10' to Add a Staff member info."<<endl;
	  cout<<"\t\t\tPress '11' to Edit a Staff member info."<<endl;
	  cout<<"\t\t\tPress '12' to Display All Staff Members."<<endl;
	  cout<<"\t\t\tPress '13' to Log Out."<<endl;
	  cout<<"\t\t\tPress '14' to Exit."<<endl;
	  
	
	do{
		cin>>choice;
		switch(choice){
			case 1:
				system("cls");
				if(rootBooking==NULL){
					cout<<"No Records Exists\n";
				}
				else{
					
					displayAllBooking();
				}
				system("pause");
				adminMenu();
				break;
			case 2:
				system("cls");
				if(rootBooking==NULL){
					cout<<"No Records Exists\n";
				}
				else{
					displayPastBooking(rootBooking);
				}
				system("pause");
				adminMenu();
				break;
			case 3:
				system("cls");
				if(rootBooking==NULL){
					cout<<"No Records Exists\n";
				}
				else{
					displayActiveBooking(rootBooking);
				}
				system("pause");
				adminMenu();
				break;
			case 4:
				system("cls");
				searchBooking();
				system("pause");
				adminMenu();
				break;
			case 5:
				system("cls");
				roomList.Inorder(rootRoom);
				system("pause");
				adminMenu();
				break;
			case 6:
				system("cls");
				addRoom();
				system("pause");
				adminMenu();
				break;
			case 7:
				system("cls");
				editRoom();
				system("pause");
				adminMenu();
				break;
			case 8:
				system("cls");
				deleteRoom();
				system("pause");
				adminMenu();
				break;
			case 9:
				system("cls");
				memberList.displayList();
				system("pause");
				adminMenu();
				break;
			case 10:
				system("cls");
				addStaff();
				system("pause");
				adminMenu();
				break;
			case 11:
				system("pause");
				editStaff();
				adminMenu();
				break;
			case 12:
				system("cls");
				if(rootStaff==NULL){
					cout<<"No Record Exists\n";
				}
				else{
					staffList.Inorder(rootStaff);
				}
				
				system("pause");
				adminMenu();
				break;
			case 13:
				//system("pause");
				loginMenu();
				//adminMenu();
				break;
			case 14:
				exit(0);
				break;
			default:
				cout<<"Wrong Choice\n"<<endl;
				adminMenu();
				
		}
		
	}while(choice<1||choice>14);

	
}
void cancelBooking(Member &obj){
	system("cls");
	cout<<"\t\t***** CANCELLATION MENU *****"<<endl<<endl;
	 displayActiveBooking(rootBooking,obj);
	 cout<<endl<<endl;
	 char ID[N];
	 cout<<"Booking ID: ";
	 cin>>ID;
	if(ID[0]!='B'||ID[1]!='K'||ID[2]!='N'){
		cout<<"Invalid Booking ID"<<endl;
		return;
	}
	 Node<Booking>* tempBooking = bookingList.SearchBST(rootBooking,charIDtointID(ID));
	 if(tempBooking==NULL){
	 	cout<<"Invalid BookingID"<<endl;
	 	return;
	 }
	 if((tempBooking->data).checkedIn){
	 	cout<<"You have Already Checked In!! This Booking Cannot Be Cancelled"<<endl;
	 	return;
	 }
	 
	time_t now = time(0);
	tm* ltm = localtime(&now);
	int d = ltm->tm_mday,m = ltm->tm_mon+1,y = ltm->tm_year+1900;
	if(countDays(d,m,y,(tempBooking->data).sdate,(tempBooking->data).smonth,(tempBooking->data).syear)<=0){
		cout<<"Your Booking Has Started. This Booking Cannot Be Canceled."<<endl;
		return;
	}	
	(tempBooking->data).isActive = false;
	Node<Room>* tempRoom = roomList.SearchBST(rootRoom,charIDtointID((tempBooking->data).roomID));
	(tempRoom->data).isBooked = false;
	cout<<"This Booking Has Been Cancelled"<<endl;
	ofstream fileBooking("Bookings.dat",ios::trunc|ios::binary);
	emptyTree<Booking>(rootBooking,fileBooking);
	fileBooking.close();
	ofstream fileRoom("Rooms.dat",ios::trunc|ios::binary);
	emptyTree<Room>(rootRoom,fileRoom);
	fileRoom.close();
}

void memberMenu(Member &objMember){
	  int choice;
	  do{
	  	system("cls");
	  	cout<<"\t\t\t\t********** MEMBER MENU **********"<<endl<<endl<<endl<<endl;
		cout<<"\t***** WELCOME "<<objMember.fName<<" "<<objMember.lName<<endl;
	  	cout<<"\t\t\tPress '1' to View Past booking records."<<endl;
	  	cout<<"\t\t\tPress '2' to View Active Bookings."<<endl;
	  	cout<<"\t\t\tPress '3' to Add Booking."<<endl;
	  	cout<<"\t\t\tPress '4' to Log Out."<<endl;
	  	cout<<"\t\t\tPress '5' to Cancel A Booking"<<endl;
	 	cout<<"\t\t\tPress '6' to Exit."<<endl;
	  	cout<<"\t\t\tPress '7' to Display Your Info."<<endl;
	  	cout<<"\t\t\tPress '8' to Display Packages."<<endl;
	  	cin>>choice;
	  	switch(choice){
	  		case 1:
	  			system("cls");
	  			displayPastBooking(rootBooking,objMember);
	  			system("pause");
	  			memberMenu(objMember);
	  			break;
	  		case 2:
	  			system("cls");
	  			displayActiveBooking(rootBooking,objMember);
	  			system("pause");
	  			memberMenu(objMember);
	  			break;
	  		case 3:
	  			system("cls");
	  			addBooking(objMember);
	  			system("pause");
	  			memberMenu(objMember);
	  			break;
	  		case 4:
	  			loginMenu();
	  			break;
	  		case 6:
	  			exit(0);
	  			break;
			case 5:
				system("cls");
				cancelBooking(objMember);
				system("pause");
				memberMenu(objMember);
				break;
			case 7:
				system("cls");
				objMember.displayInfo();
				system("pause");
				memberMenu(objMember);
				break;
			case 8:
				system("cls");
				cout<<"1.Premium Single:\tRs.6000 per Night\tAC||WIFI"<<endl<<endl;
				cout<<"2.Budget Single\tRs.2000 per Night"<<endl<<endl;
				cout<<"3.Premium Double\tRs.12000 per Night\tAC||WIFI"<<endl<<endl;
				cout<<"4.Budget Double\tRs.7000 per Night"<<endl<<endl;
				cout<<"5.Premium Quad\tRs.17000 per Night\tAC||WIFI"<<endl<<endl;
				cout<<"6.Budget Quad\tRs.30000 per Night\t"<<endl<<endl;
				cout<<"7.King\tRs.25000 per Night\t AC||WIFI||SPA||HEATED FLOORING||GYM MEMBERSHIP\tRoom for 1 Person"<<endl<<endl;
				cout<<"8.Suite\tRs.40000 per Night\tAC||WIFI||SPA||HEATED FLOORING||GYM MEMBERSHIP\tRoom for 5 Person"<<endl<<endl;
				system("pause");
				memberMenu(objMember);
				break;	  	
				
			
		}
	  }while(choice<1||choice>8);
	  return;
	}
void resturantstaffMenu(Staff &staff){
	int choice;
	bool extFlag = false;
	do{
 	  system("cls");
 	  	cout<<"********** RESTAURANT STAFF MENU **********"<<endl<<endl<<endl<<endl;
 	  cout<<"Welcome "<<staff.fName<<" "<<staff.lName<<endl<<endl<<endl;
 	  cout<<"Press '1' Process A Food Order."<<endl;
	  cout<<"Press '2' to View Your Account Information."<<endl;
	  cout<<"Press '3' Log Out."<<endl;
	  cout<<"Press '4' To Exit"<<endl;
	  cin>>choice;
	  switch(choice){
	  	case 1:
	  		system("cls");
	  		processFoodOrder();
	  		system("pause");
	  		break;
	  	case 2:
	  		system("cls");
	  		staff.displayInfo();
	  		system("pause");
	  		break;
	  	case 3:
	  		loginMenu();
	  		break;
	  	case 4:
	  		exit(1);
	  		break;
	  }
	}while(!extFlag);
}


void employeeMenu(Staff &staff){
	int choice;
	bool extFlag = false;
	do{
 	  system("cls");
 	  cout<<"\t\t********** STAFF MENU **********"<<endl;
 	  cout<<"Welcome "<<staff.fName<<" "<<staff.lName<<endl<<endl<<endl;
	  cout<<"Press '1' to View Your Account Information."<<endl;
	  cout<<"Press '2' Log Out."<<endl;
	  cout<<"Press '3' To Exit"<<endl;
	  cin>>choice;
	  switch(choice){
	  	
	  	case 1:
	  		system("cls");
	  		staff.displayInfo();
	  		system("pause");
	  		employeeMenu(staff);
	  		break;
	  	case 2:
	  		loginMenu();
	  		break;
	  	case 3:
	  		exit(1);
	  		break;
	  	default:
	  		cout<<"Invalid Choice"<<endl;
	  }
	}while(!extFlag);
}

void frontdeskMenu(Staff &staff){
	int choice;
	bool extFlag = false;
	do{
 	system("cls");
 	cout<<"\t\t********** FRONT DESK MENU **********"<<endl<<endl<<endl<<endl;
 	cout<<"\tWelcome "<<staff.fName<<" "<<staff.lName<<endl<<endl<<endl;
 	  cout<<"\t\t\tPress '1' Check In."<<endl;
 	  cout<<"\t\t\tPress '2' Check Out."<<endl;
	  cout<<"\t\t\tPress '3' to View Your Account Information."<<endl;
	  cout<<"\t\t\tPress '4' Log Out."<<endl;
	  cout<<"\t\t\tPress '5' To Exit"<<endl;
	  cin>>choice;
	  switch(choice){
	  	case 1:
	  		system("cls");
	  		checkIn();
	  		system("pause");
	  		break;
	  	case 2:
	  		system("cls");
	  		checkOut();
	  		system("pause");
	  		break;
	  	case 3:
	  		system("cls");
	  		staff.displayInfo();
	  		system("pause");
	  		break;
	  	case 4:
	  		loginMenu();
	  		break;
	  	case 5:
	  		exit(1);
	  		break;
	  	default:
	  		cout<<"Wrong Choice"<<endl;
	  }
	}while(true);
}

void cleanerMenu(Staff &staff){
	int choice;
	bool extFlag = false;
	do{
 	  system("cls");
 	  cout<<"\t\t ***** CLEANER MENU *****"<<endl<<endl;
 	  cout<<"\tWelcome "<<staff.fName<<" "<<staff.lName<<endl<<endl<<endl;
 	  cout<<"Press '1' to Process A Cleaning Order."<<endl;
	  cout<<"Press '2' to View Your Account Information."<<endl;
	  cout<<"Press '3' Log Out."<<endl;
	  cout<<"Press '4' To Exit."<<endl;
	  cin>>choice;
	  switch(choice){
	  	case 1:
	  		processCleaningOrder();
	  		system("pause");
	  		cleanerMenu(staff);
	  		break;
	  	case 2:
	  		system("cls");
	  		staff.displayInfo();
	  		system("pause");
	  		cleanerMenu(staff);
	  		break;
	  	case 3:
	  		loginMenu();
	  		break;
	  	case 4:
	  		exit(1);
	  		break;
	  }
	}while(choice!=4);
	
}

void staffMenu(Staff &staff){
	  system("cls");
	  if(strcmp(staff.jobDescription,"Cleaner")==0){
	  	cleanerMenu(staff);
	  	return;
	  }
	  else if(strcmp(staff.jobDescription,"FrontDeskOperator")==0){
	  	frontdeskMenu(staff);
	  	return;
	  }
	  else if(strcmp(staff.jobDescription,"RestaurantStaff")==0){
	  	resturantstaffMenu(staff);
	  	return;
	  }
	  else{
	  	employeeMenu(staff);
	  	return;
	  }
	 
}

void loginMenu(){
	bool exitFlag = false;
do{
	
	system("cls");
	char id[N];
	char password[N];
	cout<<"\t\t*********** LOG-IN PAGE **********"<<endl;
	cout<<"ID: ";
	cin>>id;
	cout<<"PASSWORD: ";
	cin>>password;
	NodeL<Member>* tempMember = memberLogin(memberList,id,password);
	Node<Staff>* tempStaff = staffLogin(id,password,rootStaff);
	if(admin.check_login(id,password)){
		adminMenu();
		return;
	}
	else if(tempMember!=NULL){
		memberMenu(tempMember->data);	
	}
	else if(tempStaff!=NULL){
		staffMenu(tempStaff->data);
	}
	else{
		int choice;
		cout<<"User Not Found!!!"<<endl;
		system("cls");
		do{
			system("cls");
			cout<<"0.Quit The Program\t\t1.Try Again "<<endl;
			cin>>choice;
		}while(choice!=1&&choice!=0);
		exitFlag = choice;
		if(choice==0){
			exit(1);
		}
	
	}
	
}while(exitFlag);
}
void showadds(){
	int bop,nop;
	system("color 5f");
	do{
	cout<<"Enter number of people OR press 0 to view all packages OR -1 to EXIT"<<endl;
	cin>>nop;
	if(nop==1){
		system("cls");
cout<<"\t     ***** SINGLE BUDGET ROOM *****          |\t     ***** PREMIUM SINGLE ROOM *****"<<endl;
cout<<"\t                                             |"<<endl;
cout<<"\t Price : RS.5700 /per night (tax included)   |\t Price : RS.8900 / per night (tax included)"<<endl;;
cout<<"\t                                             |"<<endl;
cout<<"> 1 Bed \t > Pool View Room \t > Sleeps 1  |> 1 King Size Bed \t > City View Room \t > Sleeps 1 "<<endl;
cout<<"                                                     |> Free Club Access \t > Pool & Spa Included \t > Breakfast Included "<<endl;
cout<<endl;
cout<<" o BATHROOM     \t o BEDROOM                   |\to BATHROOM \t  \t o BEDROOM "<<endl;
cout<<"\t                                             |"<<endl;
cout<<" > Private Bathroom      > Free Wifi                 | > Private Bathroom      > Free Wifi "<<endl;	
cout<<" > Bathrobes             > Coffee & Tea Bar          | > Bath Tub              > LCD Tv"<<endl;;
cout<<" > Shampoos & Soap       > Mini Bar                  | > Bathrobes             > Coffee & Tea Bar"<<endl;;
cout<<" > Slippers              > Workspace                 | > Shampoos & Soap       > Mini Bar"<<endl;;
cout<<" > Towels                > Safe                      | > Slippers              > Workspace"<<endl;
cout<<" > Hair Dryers           > Fridge                    | > Towels                > Safe"<<endl;;
cout<<" > Free Toiletries       > Daily Housekeeping        | > Hair Dryers           > Fridge"<<endl;
cout<<"                                                     | > Free Toiletries       > Daily Housekeeping"<<endl;
cout<<endl;
}
else if(nop==2){
	system("cls");
cout<<"---------------------------------------------------------------------------------------------------------------------------"	<<endl;
cout<<endl;
cout<<"\t     ***** DOUBLE BUDGET ROOM *****          |\t     ***** PREMIUM DOUBLE ROOM *****"<<endl;
cout<<"\t                                             |"<<endl;
cout<<"\t Price : RS.7700 /per night (tax included)   |\t Price : RS.9900 / per night (tax included)"<<endl;;
cout<<"\t                                             |"<<endl;
cout<<"> 1 Queen Bed \t > Pool View Room \t > Sleeps 2  |> 1 King Size Bed \t > City View Room \t > Sleeps 2 "<<endl;
cout<<"                                                     |> Free Club Access \t > Pool & Spa Included \t > Breakfast Included "<<endl;
cout<<endl;
cout<<" o BATHROOM     \t o BEDROOM                   |o BATHROOM   \t  \t o BEDROOM "<<endl;
cout<<"\t                                             |"<<endl;
cout<<" > Private Bathroom      > Free Wifi                 | > Private Bathroom      > Free Wifi "<<endl;	
cout<<" > Bathrobes             > Coffee & Tea Bar          | > Bath Tub              > LCD Tv"<<endl;;
cout<<" > Shampoos & Soap       > Mini Bar                  | > Bathrobes             > Coffee & Tea Bar"<<endl;;
cout<<" > Slippers              > Workspace                 | > Shampoos & Soap       > Mini Bar"<<endl;;
cout<<" > Towels                > Safe                      | > Slippers              > Workspace"<<endl;
cout<<" > Hair Dryers           > Fridge                    | > Towels                > Safe"<<endl;;
cout<<" > Free Toiletries       > Daily Housekeeping        | > Hair Dryers           > Fridge"<<endl;
cout<<"                                                     | > Free Toiletries       > Daily Housekeeping"<<endl;
cout<<endl;
}
else if(nop>2 ){
	system("cls");
cout<<"---------------------------------------------------------------------------------------------------------------------------"	<<endl;
cout<<endl;
cout<<"\t     ***** QUAD BUDGET ROOM *****            |  \t     ***** PREMIUM QUAD ROOM *****"<<endl;
cout<<"\t                                             |"<<endl;
cout<<"\t Price : RS.9700 /per night (tax included)   |\t Price : RS.11900 / per night (tax included)"<<endl;;
cout<<"\t                                             |"<<endl;
cout<<">1 King Bed & 2 Single Beds> Pool View Room >Sleeps 4|> 2 King Size Beds \t > City View Room \t > Sleeps 4 "<<endl;
cout<<"                                                     |> Free Club Access \t > Pool & Spa Included \t > Breakfast Included "<<endl;
cout<<endl;
cout<<" o BATHROOM     \t o BEDROOM                   |o BATHROOM \t    \t o BEDROOM "<<endl;
cout<<"\t                                             |"<<endl;
cout<<" > Private Bathroom      > Free Wifi                 | > Private Bathroom      > Free Wifi "<<endl;	
cout<<" > Bathrobes             > Coffee & Tea Bar          | > Bath Tub              > LCD Tv"<<endl;;
cout<<" > Shampoos & Soap       > Mini Bar                  | > Bathrobes             > Coffee & Tea Bar"<<endl;;
cout<<" > Slippers              > Workspace                 | > Shampoos & Soap       > Mini Bar"<<endl;;
cout<<" > Towels                > Safe                      | > Slippers              > Workspace"<<endl;
cout<<" > Hair Dryers           > Fridge                    | > Towels                > Safe"<<endl;;
cout<<" > Free Toiletries       > Daily Housekeeping        | > Hair Dryers           > Fridge"<<endl;
cout<<"                                                     | > Free Toiletries       > Daily Housekeeping"<<endl;
cout<<endl;
cout<<"---------------------------------------------------------------------------------------------------------------------------"	<<endl;
cout<<endl;
cout<<"\t     ***** PREMIUM SUITE *****               |\t     ***** PREMIUM KING ROOM *****"<<endl;
cout<<"\t                                             |"<<endl;
cout<<"\t Price : RS.12900 /per night (tax included)  |\t Price : RS.14900 / per night (tax included)"<<endl;;
cout<<"\t                                             |"<<endl;
cout<<"> 1 King Bed  > Skyline View Room > Sleeps 2         |> 1 King Bed & 2 Queen Beds > Skyline View Room > Sleeps 5 "<<endl;
cout<<"> Free Club   > Pool&Spa Inc      > Breakfast Inc    |> Free Club Access > Pool & Spa Included > Breakfast Included "<<endl;
cout<<endl;
cout<<" o BATHROOM     \t o BEDROOM                   |o BATHROOM   \t  \t o BEDROOM "<<endl;
cout<<"\t                                             |"<<endl;
cout<<" > Private Bathroom      > Free Wifi                 | > Private Bathroom      > Free Wifi "<<endl;	
cout<<" > Bathrobes             > Coffee & Tea Bar          | > Bath Tub              > LCD Tv"<<endl;;
cout<<" > Shampoos & Soap       > Mini Bar                  | > Bathrobes             > Coffee & Tea Bar"<<endl;;
cout<<" > Slippers              > Workspace                 | > Shampoos & Soap       > Mini Bar"<<endl;;
cout<<" > Towels                > Safe                      | > Slippers              > Workspace"<<endl;
cout<<" > Hair Dryers           > Fridge                    | > Towels                > Safe"<<endl;;
cout<<" > Free Toiletries       > Daily Housekeeping        | > Hair Dryers           > Fridge"<<endl;
cout<<"                                                     | > Free Toiletries       > Daily Housekeeping"<<endl;
cout<<"                                                     | > Free Spa Services "<<endl;
cout<<endl;
cout<<"---------------------------------------------------------------------------------------------------------------------------"	<<endl;
}
else if(nop==0){
	system("cls");
	cout<<"\t     ***** SINGLE BUDGET ROOM *****          |\t     ***** PREMIUM SINGLE ROOM *****"<<endl;
cout<<"\t                                             |"<<endl;
cout<<"\t Price : RS.5700 /per night (tax included)   |\t Price : RS.8900 / per night (tax included)"<<endl;;
cout<<"\t                                             |"<<endl;
cout<<"> 1 Bed \t > Pool View Room \t > Sleeps 1  |> 1 King Size Bed \t > City View Room \t > Sleeps 1 "<<endl;
cout<<"                                                     |> Free Club Access \t > Pool & Spa Included \t > Breakfast Included "<<endl;
cout<<endl;
cout<<" o BATHROOM     \t o BEDROOM                   |\to BATHROOM \t  \t o BEDROOM "<<endl;
cout<<"\t                                             |"<<endl;
cout<<" > Private Bathroom      > Free Wifi                 | > Private Bathroom      > Free Wifi "<<endl;	
cout<<" > Bathrobes             > Coffee & Tea Bar          | > Bath Tub              > LCD Tv"<<endl;;
cout<<" > Shampoos & Soap       > Mini Bar                  | > Bathrobes             > Coffee & Tea Bar"<<endl;;
cout<<" > Slippers              > Workspace                 | > Shampoos & Soap       > Mini Bar"<<endl;;
cout<<" > Towels                > Safe                      | > Slippers              > Workspace"<<endl;
cout<<" > Hair Dryers           > Fridge                    | > Towels                > Safe"<<endl;;
cout<<" > Free Toiletries       > Daily Housekeeping        | > Hair Dryers           > Fridge"<<endl;
cout<<"                                                     | > Free Toiletries       > Daily Housekeeping"<<endl;
cout<<endl;
cout<<"---------------------------------------------------------------------------------------------------------------------------"	<<endl;
cout<<endl;
cout<<"\t     ***** DOUBLE BUDGET ROOM *****          |\t     ***** PREMIUM DOUBLE ROOM *****"<<endl;
cout<<"\t                                             |"<<endl;
cout<<"\t Price : RS.7700 /per night (tax included)   |\t Price : RS.9900 / per night (tax included)"<<endl;;
cout<<"\t                                             |"<<endl;
cout<<"> 1 Queen Bed \t > Pool View Room \t > Sleeps 2  |> 1 King Size Bed \t > City View Room \t > Sleeps 2 "<<endl;
cout<<"                                                     |> Free Club Access \t > Pool & Spa Included \t > Breakfast Included "<<endl;
cout<<endl;
cout<<" o BATHROOM     \t o BEDROOM                   |o BATHROOM   \t  \t o BEDROOM "<<endl;
cout<<"\t                                             |"<<endl;
cout<<" > Private Bathroom      > Free Wifi                 | > Private Bathroom      > Free Wifi "<<endl;	
cout<<" > Bathrobes             > Coffee & Tea Bar          | > Bath Tub              > LCD Tv"<<endl;;
cout<<" > Shampoos & Soap       > Mini Bar                  | > Bathrobes             > Coffee & Tea Bar"<<endl;;
cout<<" > Slippers              > Workspace                 | > Shampoos & Soap       > Mini Bar"<<endl;;
cout<<" > Towels                > Safe                      | > Slippers              > Workspace"<<endl;
cout<<" > Hair Dryers           > Fridge                    | > Towels                > Safe"<<endl;;
cout<<" > Free Toiletries       > Daily Housekeeping        | > Hair Dryers           > Fridge"<<endl;
cout<<"                                                     | > Free Toiletries       > Daily Housekeeping"<<endl;
cout<<endl;
cout<<"---------------------------------------------------------------------------------------------------------------------------"	<<endl;
cout<<endl;
cout<<"\t     ***** QUAD BUDGET ROOM *****            |  \t     ***** PREMIUM QUAD ROOM *****"<<endl;
cout<<"\t                                             |"<<endl;
cout<<"\t Price : RS.9700 /per night (tax included)   |\t Price : RS.8900 / per night (tax included)"<<endl;;
cout<<"\t                                             |"<<endl;
cout<<">1 King Bed & 2 Single Beds> Pool View Room >Sleeps 4|> 2 King Size Beds \t > City View Room \t > Sleeps 4 "<<endl;
cout<<"                                                     |> Free Club Access \t > Pool & Spa Included \t > Breakfast Included "<<endl;
cout<<endl;
cout<<" o BATHROOM     \t o BEDROOM                   |o BATHROOM \t    \t o BEDROOM "<<endl;
cout<<"\t                                             |"<<endl;
cout<<" > Private Bathroom      > Free Wifi                 | > Private Bathroom      > Free Wifi "<<endl;	
cout<<" > Bathrobes             > Coffee & Tea Bar          | > Bath Tub              > LCD Tv"<<endl;;
cout<<" > Shampoos & Soap       > Mini Bar                  | > Bathrobes             > Coffee & Tea Bar"<<endl;;
cout<<" > Slippers              > Workspace                 | > Shampoos & Soap       > Mini Bar"<<endl;;
cout<<" > Towels                > Safe                      | > Slippers              > Workspace"<<endl;
cout<<" > Hair Dryers           > Fridge                    | > Towels                > Safe"<<endl;;
cout<<" > Free Toiletries       > Daily Housekeeping        | > Hair Dryers           > Fridge"<<endl;
cout<<"                                                     | > Free Toiletries       > Daily Housekeeping"<<endl;
cout<<endl;
cout<<"---------------------------------------------------------------------------------------------------------------------------"	<<endl;
cout<<endl;
cout<<"\t     ***** PREMIUM SUITE *****               |\t     ***** PREMIUM KING ROOM *****"<<endl;
cout<<"\t                                             |"<<endl;
cout<<"\t Price : RS.12900 /per night (tax included)  |\t Price : RS.14900 / per night (tax included)"<<endl;;
cout<<"\t                                             |"<<endl;
cout<<"> 1 King Bed  > Skyline View Room > Sleeps 2         |> 1 King Bed & 2 Queen Beds > Skyline View Room > Sleeps 5 "<<endl;
cout<<"> Free Club   > Pool&Spa Inc      > Breakfast Inc    |> Free Club Access > Pool & Spa Included > Breakfast Included "<<endl;
cout<<endl;
cout<<" o BATHROOM     \t o BEDROOM                   |o BATHROOM   \t  \t o BEDROOM "<<endl;
cout<<"\t                                             |"<<endl;
cout<<" > Private Bathroom      > Free Wifi                 | > Private Bathroom      > Free Wifi "<<endl;	
cout<<" > Bathrobes             > Coffee & Tea Bar          | > Bath Tub              > LCD Tv"<<endl;;
cout<<" > Shampoos & Soap       > Mini Bar                  | > Bathrobes             > Coffee & Tea Bar"<<endl;;
cout<<" > Slippers              > Workspace                 | > Shampoos & Soap       > Mini Bar"<<endl;;
cout<<" > Towels                > Safe                      | > Slippers              > Workspace"<<endl;
cout<<" > Hair Dryers           > Fridge                    | > Towels                > Safe"<<endl;;
cout<<" > Free Toiletries       > Daily Housekeeping        | > Hair Dryers           > Fridge"<<endl;
cout<<"                                                     | > Free Toiletries       > Daily Housekeeping"<<endl;
cout<<"                                                     | > Free Spa Services "<<endl;
cout<<endl;
cout<<"---------------------------------------------------------------------------------------------------------------------------"	<<endl;
}
}while(nop!=-1);
}
int main(void){
	loader("DATASY HOTEL & CLUB");
	system("cls");
	showadds();
	system("cls");
	rootBooking = fillTree<Booking>("Bookings.dat");
	rootRoom = fillTree<Room>("Rooms.dat");
	rootStaff = fillTree<Staff>("Staff.dat");
	FillLinkedList(memberList,"Members.dat");
	char choice;
	system("color F5");
	cout<<"\t************ Welcome To Datasy Hotels & Club ***********"<<endl<<endl;
	cout<<"\t   Please Sign-Up if you're not a member Else Log-in"<<endl<<endl;
	cout<<"\t\t\ta.Login\t\tb.Sign-Up"<<endl;
	do{
	cin>>choice;
	if(toupper(choice)=='A'){
		system("cls");
		loginMenu();
	}
	else if(toupper(choice)=='B'){
		system("cls");
		Signup();
	}
	else{
		cout<<"Please Enter Valid Input\n";
	}
	}while(toupper(choice)!='A'||toupper(choice)!='B');
}

