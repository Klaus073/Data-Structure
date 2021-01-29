#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class Person
{
	private:
		string name;
		int age;
		string gender;
		string address;
		string phone;
		
	public:
		Person()
		{
			
		}
		
		void set_name(string n)
		{
			name=n;
		}
		void set_age(int a)
		{
			age=a;
		}
		void set_gender(string g)
		{
			gender=g;
		}
		void set_address(string ad)
		{
			address=ad;
		}
		void set_phone(string p)
		{
			phone=p;
		}
		
		string get_name()
		{
			return name;
		}
		int get_age()
		{
			return age;
		}
		string get_gender()
		{
			return gender;
		}
		string get_address()
		{
			return address;
		}
		string get_phone()
		{
			return phone;
		}
		
		virtual void save_info()
		{
			cin.ignore();
			cout<<"Enter name:";
			getline(std::cin,name);
			cout<<"Enter gender:";
			cin>>gender;
			cout<<"Enter age:";
			cin>>age;
			cin.ignore();
			cout<<"Enter address:";
			getline(cin,address);
			cout<<"Enter Phone:";
			cin>>phone;
		}
		
		virtual void display_info()
		{
			cout<<"Name:"<<name;
			cout<<"Gender:"<<gender;
			cout<<"Age:"<<age;
			cout<<"Address:"<<address;
			cout<<"Phone:"<<phone;
		}
};

class Patient: public Person
{
	private:
		string sickness;
		string prescription;
	public:
		Patient()
		{
			
		}
		void save_info()
		{
			cout<<"\nEnter the following data for patient\n\n";
			Person::save_info();
			cout<<"Enter sickness:";
			cin>>sickness;
			cout<<"Enter Prescription:";
			cin>>prescription;
		}
		void display_info()
		{
			cout<<"\nDisplaying patient information:\n-------------------------------------";
			cout<<"\nPatient's Name:"<<get_name();
			cout<<"\nPatient's gender:"<<get_gender();
			cout<<"\nPatient's age:"<<get_age();
			cout<<"\nPatient's address:"<<get_address();
			cout<<"\nPatient's phone:"<<get_phone();
			cout<<"\nPatient's sickness:"<<sickness;
			cout<<"\nPrescription for the sickness:"<<prescription;
		}
};
class staff:public Person
{
	private:
		string education;
		long salary;
		
	public:
		staff()
		{
			
		}
		void save_info()
	{
		cout<<"\nEnter the following data for staff\n\n";
		Person::save_info();
		cout<<"Enter education:";
		cin>>education;
		cout<<"Enter salary:";
		cin>>salary;
	}
	void display_info()
	{
		cout<<"\nDisplaying Staff's information:\n------------------------";
		cout<<"\nstaff's Name:"<<get_name();
		cout<<"\nstaff's gender:"<<get_gender();
		cout<<"\nstaff's age:"<<get_age();
		cout<<"\nstaff's address:"<<get_address();
		cout<<"\nstaff's phone:"<<get_phone();
		cout<<"\nstaff's education:"<<education;
		cout<<"\nstaff's salary:"<<salary;
	}
};

int main()
{
	
	int number=0, i=0;
	char type='\0', option='\0';
	cout<<"How many person's information you want to enter:";
	cin>>number;
	Person*persons[number];
	do
	{
		again:
		cout<<"\nEnter choice: P for Patient, S for staff:";
		cin>>type;
		if(type=='p'|| type=='P')
		{
			persons[i]=new Patient();
			persons[i]->save_info();
			i++;
		}
		else if(type=='s'|| type=='S')
		{
			persons[i]=new staff();
			persons[i]->save_info();
			i++;
		}
		else
		{
			cout<<"\n Sorry invalid choice, Try again\n";
			goto again;
		}
		cout<<"Do you want to enter more data(Y for yes, N for No):";
		cin>>option;
	}while((option=='Y' || option=='y') && i<number);
	for (int j=0; j<i; j++)
	{
		cout<<"\n";
		persons[j]->display_info();
		cout<<"\n-------------------";
	}
}
