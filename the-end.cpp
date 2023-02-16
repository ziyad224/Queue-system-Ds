#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;
struct client {
	string ServiceName, FirstName, LastName;//,VIP_stute;
	string MobileNumber;
	//bool vip;
	int Clint_No;
	int clint_vip;
};
struct node
{
	client info;
	node* next;
};
//global pointer
node* current = NULL;
node* front = NULL;
node* rear = NULL;
node* vrear = NULL;
node* vfront = NULL;
node* vcurrent = NULL;
//---------------------------------
//menu functions call
void glopal_enqueue();
void dequeue();
void search_Name();
void Search_Number();
void Search_Service_Name();
void display();
void update_clients();
void global_search();
void vip_enqueue();
void global_display();
void global_read_file();
void diplay_vip();
void global_search();
void global_update();
void saveinfile(); 
void readfromfile();
//----------------------------------------------------------------------------
//menu function collectes  all the function to fo displayed in on function 
void menu() {
	char choice;
	cout << " ****** ^_^ welcome to queue application ^_^ ******" << endl;
	cout << "*||===============================================||*\n";
	cout << "*||<Note>                                         ||*\n";
	cout << "*||------                                         ||*\n";
	cout << "*||\tPress E to Enqueue                        ||*\n";
	cout << "*||\tPress D to Dequeue                        ||*\n";
	cout << "*||\tPress P to Display Clients (All & VIB)    ||*\n";
	cout << "*||\tPress S to Search                         ||*\n";
	cout << "*||\tPress U to Update                         ||*\n";
	cout << "*||\tPress I to change Updata your inormation  ||*\n";
	cout << "*||\tPress F to  read Your data from file	  ||*\n";
	cout << "*||\tPress Q to Quit                           ||*\n";
	cout << "*||===============================================||*\n";
	cout << "\t\t\t\t\t\t\t" << endl;
	cout << "Hello Sir PLease ENTER A LETTER FOR THE SEARVICE YOU WANT :) \n ";
	cout << "( "<<"E\tD\tP\ts\tU\tI\tF\tQ" << " )"<<endl;
	cin >> choice;
	switch (choice)
	{
	case 'E':
	case'e':
		glopal_enqueue();
		menu();
		break;
	case 'D':
	case'd':
		dequeue();
		display();
		menu();
		break;
	case 'P':
	case'p':
		global_display();
		menu();
		break;
	case 'S':
	case's':
		global_search();
		menu();
		break;
	case 'U':
	case'u':
		vip_enqueue();
		menu();
		break;
	case'I':
	case'i':
		global_update();
		menu();
		break;
	case 'F':
	case'f':
		global_read_file();
		menu();
		break;
	case 'Q':
	case'q':
		cout << " THANKS FOR USING QUEUE Application " << endl;
		cout << "please press ESC from your keyboard to quit" << endl;
		return;
	default:
		cout << " !! INVALID INPUT " << endl;
		break;
	}
}
void saveinfile()
{
	ofstream input;
	input.open("Contact data.txt", ios::app);
	if (!input) {
		cout << "file error.";
		system("pause");
	}
	input << vcurrent->info.FirstName << endl;
	input << vcurrent->info.LastName << endl;
	input << vcurrent->info.MobileNumber << endl;
	input << vcurrent->info.ServiceName << endl;
	current = vcurrent->next;
	if (!input)
	{
		input << current->info.FirstName << endl;
		input << current->info.LastName << endl;
		input << current->info.MobileNumber << endl;
		input << current->info.ServiceName << endl;
		current = current->next;
	}

	input.close();
};
bool IsEmpty()
{
	if (front == NULL && rear == NULL)
		return true;
	else
		return false;
}
void check_se_name(string str) {
	int flag = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
		{
			flag = 1;
		}
		else
		{
			flag = 0;
			break;
		}
	}
	if (flag == 0) {
		cout << "please enter letters only ^_^" << endl;

		return;

	}
}
void NumberChecker() {
	string Num, size;
	cout << "Enter Number: ";
	for (int i = 0; i < 12; i++) {
		cin >> Num;
		size = Num;
		if (size == Num) {
			cout << "Number accepted.\n";
			break;
			while (size != Num)
			{
				cout << "please enter you number agien\n";
				cin >> Num;
				return;
			}
		}
		else {
			cout << "Number is not right\n";
			cout << "plz Enter The True Number: ";
		}
	}
	current->info.MobileNumber = Num;
};
void check_no(string n) {
	int flag = 0;
	for (int i = 0; i < n.size(); i++)
	{
		if (n[i] >= 12 && n[i] <= 0)
			
		{
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}
	if (flag == 0) {
		cout << "please enter correct number ^_^" << endl;
	}
}
//********************************************************************************
int c = 1 ;// counter top rint the clients numbers within the queue
void vip_enqueue()
{
	string First_Name, Last_Name, Serves_Name;
	string mobile_num;
	vcurrent = new node;
	//vcurrent->info.vip = 1;
	cout << "Enter first name:";
	cin >> First_Name;
	vcurrent->info.FirstName = First_Name;
	cout << "Enter Last Name:";
	cin >> Last_Name;
	vcurrent->info.LastName = Last_Name;
	cout << "Please Enter Your Mobile Number\t\t for EX(01145000440):\n ";
	//NumberChecker();
	cin >> mobile_num;
	check_no(mobile_num);
	vcurrent->info.MobileNumber = mobile_num;
	cout << "Enter Service name : " << endl;
	cin >> Serves_Name;
	vcurrent->info.ServiceName = Serves_Name;
	check_se_name(Serves_Name);
	vcurrent->next = NULL;
	if (vfront == NULL)
	{
		vfront = vrear = vcurrent;
	}
	else
	{
		vrear->next = vcurrent;
		vrear = vcurrent;
	}
	vrear->next = NULL;
	saveinfile();	
	
}
void Reg_enqueue()
{
	string First_Name, Last_Name, Serves_Name;
	string mobile_num;
	current = new node;
	//current->info.vip = 0;
	cout << "Enter first name:";
	cin >> First_Name;
	current->info.FirstName = First_Name;
	cout << "Enter Last Name:";
	cin >> Last_Name;
	current->info.LastName = Last_Name;
	cout << "Please Enter Your Mobile Number\t\t for EX(01145000440):\n ";
	cin >> mobile_num;
	check_no(mobile_num);
	current->info.MobileNumber = mobile_num;
	cout << "Enter Service name : " << endl;
	cin >> Serves_Name;
	current->info.ServiceName = Serves_Name;
	check_se_name(Serves_Name);
	current->next = NULL;
	if (front == NULL)
	{
		front = rear = current;
	}
	else
	{
		rear->next = current;
		rear = current;
	}
	rear->next = NULL;
}
void glopal_enqueue()
{
	string x;
	cout << "Please Enter The Number of service You Want:" << endl;
	cout << "1-For\" VIP Clients\"\t\t\t 2-For\"Normal Clients\"\n";
	cin >> x;
	if (x == "1")
	{
		check_no(x);
		vip_enqueue();
		return;
	}
	else if (x == "2")
	{
		check_no(x);
		Reg_enqueue();
		return;
	}
	else
	{
		cout << "non :( ";
	}

}
//************************************************************************************
void Search_Number()
{
	current = front;
	string SearchNum, Size;
	cout << "Enter Number You Want To Search: ";
	for (int i = 0; i < 12; i++)
	{
		cin >> SearchNum;
		Size = SearchNum;
		if (Size == SearchNum)
		{
			cout << "Number Accepted.\n";
			break;
		}
		else
		{
			cout << "NUmber is NOt True Please Enter the Right Nmber: ";
		}
	}
	if (front != NULL)
	{
		while (current != NULL)
		{
			if (current->info.MobileNumber == SearchNum)
			{
				cout << "           First Name:";
				cout << current->info.FirstName;
				cout << "           Last Name:";
				cout << current->info.LastName;
				cout << "           MObile number:";
				cout << current->info.MobileNumber;
				break;
			}
			else
			{
				current = current->next;
			}

		}
	}
	else
	{
		cout << "NO Data Found  \n";
	}


	if (current == NULL)
	{
		cout << "  NUmber not Found  \n";
	}


}
void search_Name_vip()
{
	vcurrent = vfront;
	string Fname, Lname;
	cout << "Please Enter Client's Name You Want To Updata \n";
	cout << "First Name\n";
	cin >> Fname;
	cout << "Last Name\n";
	cin >> Lname;

	if (vfront != NULL)
	{
		while (vcurrent != NULL)
		{
			vcurrent = vcurrent->next;
			while (vcurrent != NULL)
			{
				if (vcurrent->info.FirstName == Fname
					&& vcurrent->info.LastName == Lname)
				{
					cout << "          First Name:" << endl;
					cout << vcurrent->info.FirstName << "\n";
					cout << "            Last Name:" << endl;
					cout << vcurrent->info.LastName << "\n";
					cout << "              Service Name:" << endl;
					cout << vcurrent->info.ServiceName << "\n";
					cout << "                Phone Number: " << endl;
					cout << vcurrent->info.MobileNumber << "\n";
					break;
				}
				vcurrent = vcurrent->next;
				break;
			}
			
		}
	}

}
void search_Name()
{
	current = front;
	string Fname, Lname;
	cout << "Please Enter Client's Name You Want To Updata \n";
	cout << "First Name\n";
	cin >> Fname;
	cout << "Last Name\n";
	cin >> Lname;

	if (front != NULL)
	{
		while (current != NULL)
		{
			current = current->next;
			while (current != NULL)
			{
				if (current->info.FirstName == Fname
					&& current->info.LastName == Lname)
				{
					cout << "          First Name:" << endl;
					cout << current->info.FirstName << "\n";
					cout << "            Last Name:" << endl;
					cout << current->info.LastName << "\n";
					cout << "              Service Name:" << endl;
					cout << current->info.ServiceName << "\n";
					cout << "                Phone Number: " << endl;
					cout << current->info.MobileNumber << "\n";
					break;
				}
				current = current->next;
				break;
			}
			
		}
	}

}
void Search_Service_Name()
{
	node* ptr = front, * ptr2 = NULL;
	string SName;
	cout << "Enter Service Name You want to Search About:";
	cin >> SName;
	if (front != NULL)
	{
		while (ptr != NULL)
		{
			ptr2 = ptr->next;
			while (ptr2 != NULL)
			{
				if (ptr2->info.ServiceName == SName)
				{
					cout << "\n           First Name \n";
					cout << ptr2->info.FirstName;
					cout << "\n             Last Name \n";
					cout << ptr2->info.FirstName;
					cout << "\n               Servic Name \n";
					cout << ptr2->info.ServiceName;
					cout << "\n                phone Number  \n";
					cout << ptr2->info.MobileNumber;
				}
				ptr2 = ptr2->next;
				break;
			}
			ptr = ptr->next;
		}
	}
}
void global_search()
{
	char x;
	cout << "  \tPlease Enter NUmber of What Kind of Seach do You Want :) \n";
	cout << "\t\t Enter NUmber\n";
	cout << "\t1-Search By Client's Name \n";
	cout << "\t2-Search By Client's Phone Number\n";
	cout << "\t3-Search By Client's Service Name\n";
	cin >> x;
	cout << "Happy To Help You :) " << endl;

	switch (x)
	{
	case'1':
		char n; 
		cout << "1-for vip ||2-for normal" << endl;
		cin >> n;
		if (n=='1')
		{
			search_Name_vip();
		}
		else if (n=='2')
		{
			search_Name();
		}
		else
		{
			cout << "INVLID INPUT" << endl;
		}
		break;
	case'2':
		Search_Number();
		break;
	case'3':
		Search_Service_Name();
		break;

	default:
		cout << "(INVID INPUT)!! Please Choose Number NUmber From 1 To 3 " << endl;
	}


}
//***************************************************

void dequeue()
{
	if (front != NULL || vfront != NULL)
	{


		if (vfront != NULL)//to delete the vip first
		{
			vcurrent = vfront;
			vfront = vfront->next;
			delete vcurrent;
			c--;
		}
		else
		{
			current = front;
			front = front->next;
			delete current;
			c--;
		}

	}
}

//*******************************************************
void update_clients()//updata clients data if te client want to change his information
{
	current = front;
	string Fname, Lname;
	cout << "Please Enter Client's Name You Want To Updata \n";
	cout << "First Name\n";
	cin >> Fname;
	cout << "Last Name\n";
	cin >> Lname;

	if (front != NULL)
	{
		while (current != NULL)
		{
			if (current->info.FirstName == Fname && current->info.LastName == Lname)
			{
				cout << "Enter First Name..\n";
				cin >> current->info.FirstName;
				cout << "Last Name..\n";
				cin >> current->info.LastName;
				cout << "Enter Service Name..\n";
				cin >> current->info.ServiceName;
				cout << "Enter PHone Number..\n";
				cin >> current->info.MobileNumber;
			
				break;
			}
		}
	}
	else if (current == NULL)
	{
		cout << "No data IN the Queue\n";
	}
	else
	{
		cout << "non" << endl;
	}

}
void update_clients_vip()
{
	vcurrent = vfront;
	string Fname, Lname;
	cout << "Please Enter Client's Name You Want To Updata \n";
	cout << "First Name\n";
	cin >> Fname;
	cout << "Last Name\n";
	cin >> Lname;

	if (vfront != NULL)
	{
		while (vcurrent != NULL)
		{
			if (vcurrent->info.FirstName == Fname && vcurrent->info.LastName == Lname)
			{
				cout << "Enter First Name..\n";
				cin >> vcurrent->info.FirstName;
				cout << "Last Name..\n";
				cin >> vcurrent->info.LastName;
				cout << "Enter Service Name..\n";
				cin >> vcurrent->info.ServiceName;
				cout << "Enter PHone Number..\n";
				cin >> vcurrent->info.MobileNumber;

				break;
			}
		}
	}
	else if (vcurrent == NULL)
	{
		cout << "No data IN the Queue\n";
	}
	else
	{
		cout << "non" << endl;
	}
}
void global_update()
{
	char n;
	cout << "1-for vip client ||2-for normal" << endl;
	cin >> n;
	if (n == '1')
	{
		update_clients_vip();
	}
	else if (n == '2')
	{
		update_clients();
	}
	else cout << "INVILD INPUT" << endl;
}
//********************************************************************************

void global_display()
{
	char nu;
	cout << "1-for vip only || 2-All clients" << endl;
	cin >> nu;
	if (nu == '1')
	{
		diplay_vip();
		c = 1;

	}
	else if (nu == '2')
	{
		display();
		c = 1;

	}
	else cout << "INVAILD INPUT :)" << endl;

}
void display() //for all clients
{
	if (vfront != NULL)
	{
		vcurrent = vfront;
		while (vcurrent != NULL)
		{
			cout << "**************************" << endl;
			cout << "DATA" << endl;
			cout << "First Name :" << vcurrent->info.FirstName << " " << endl;
			cout << "Second Name :" << vcurrent->info.LastName << " " << endl;
			cout << "client No :" <<c++ << " " << endl;
			cout << "Phone No. :" << "0" << vcurrent->info.MobileNumber << " " << endl;
			cout << "Service Name :" << vcurrent->info.ServiceName << " " << endl;
			cout << "**************************";
			vcurrent = vcurrent->next;
		}
	}
	if (front != NULL)
	{
		current = front;
		while (current != NULL)
		{
			cout << "**************************" << endl;
			cout << "DATA" << endl;
			cout << "First Name :" << current->info.FirstName << " " << endl;
			cout << "Second Name :" << current->info.LastName << " " << endl;
			cout << "client No :" << c++ << " " << endl;

			cout << "Phone No. :" << "0" << current->info.MobileNumber << " " << endl;
			cout << "Service Name :" << current->info.ServiceName << " " << endl;
			cout << "**************************";
			current = current->next;
		}
	}

	else
	{
		cout << "NO CLIENTS HERE :) \n " << endl;
	}
}
void diplay_vip()// for vip clients
{
	if (vfront != NULL)
	{
		vcurrent = vfront;
		while (vcurrent != NULL)
		{
			cout << "**************************" << endl;
			cout << "DATA" << endl;
			cout << "First Name :" << vcurrent->info.FirstName << " " << endl;
			cout << "Second Name :" << vcurrent->info.LastName << " " << endl;
			cout << "Client No. :" << c++<< " " << endl;
			cout << "Phone No. :" << "0" << vcurrent->info.MobileNumber << " " << endl;
			cout << "Service Name :" << vcurrent->info.ServiceName << " " << endl;
			cout << "**************************";
			vcurrent = vcurrent->next;
		}
	}

}
//********************************************************************************
void readfromfile() {
	for (int i = 0; i < 5; i++)
	{
	ifstream output;
	output.open("Contact data read .txt", ios::app);
	if (!output) {
		cout << "file error.";
		system("pause");
	}

		string Fn, Ln, Em;
		string N;
		output >> Fn >> Ln >> N >> Em;
		current = new node;
		current->info.FirstName = Fn;
		current->info.LastName = Ln;
		current->info.MobileNumber = N;
		current->info.ServiceName = Em;
		current->next = NULL;
		if (front == NULL)
		{	
			front = current;
			rear = current;
		}
		else
		{
			rear->next = current;
			rear = rear->next;
		}
		current = current->next;
		output.close();
	
	}
	
};
void readfromfile_vip()
{
	for (int i = 0; i < 5; i++)
	{
	ifstream output;
	output.open("Contact data read vip.txt", ios::app);
	if (!output) {
		cout << "file error.";
		system("pause");
	}
	
		string Fn, Ln, Em, J;
		string N;
		output >> Fn >> Ln >> N >> Em;
		vcurrent = new node;
		vcurrent->info.FirstName = Fn;
		vcurrent->info.LastName = Ln;
		vcurrent->info.MobileNumber = N;
		vcurrent->info.ServiceName = Em;
		vcurrent->next = NULL;
		if (vfront == NULL)
		{
			vfront = vcurrent;
			vrear = vcurrent;
		}
		else
		{
			vrear -> next = vcurrent;
			vrear = vrear->next;
		}
		vcurrent = vcurrent->next;

		output.close();
	}

}
void global_read_file()
{
	char n;
	cout << "1-to read from vip clients || 2-to read normal clients" << endl;
	cin >> n;
	if (n == '1')
	{
		readfromfile_vip();
	}
	else if (n=='2')
	{
		readfromfile();
	}
	else
	{
		cout << "INVALID INPUT" << endl;
	}
}
//**********************************************************************
int main()
{
	menu();
	return 0;
}