#include <iostream>
using namespace std;
class larr
{
public:
	larr();
	~larr();
	int get()
	{
		return *arr;
	}
	int search()
	{
		arr = head;
		int x = 0;
		int y = 0;
		cout <<endl<< "enter the no u want to update";
		cin >> x;
		while (*arr != NULL)
		{
			if (*arr == x)
			{
				y = 1;
			}
			else
			{
				arr++;
			}
		}
		if (y == 1)
		{
			cout << endl << "found";
			return 1;
		}
		else
		{
			
			cout << endl << "not found";
			return 0;
		
		}
	}
	void update()
	{
		int x;
		x=search();
		if (x == 1)
		{
			cout << endl << "enter the new data";
			int y = 0;
			cin >> y;
			*arr = y;
		}
	}
	int lenght()
	{
		arr = head;
		int x = 0;
		while (*arr)
		{
			x++;
			arr++;
		}
		return x;
	}
	void add()
	{
		size--;
		if (size >= 0)
		{
			cout << endl << "enter data ";
			int  d;
			cin >> d;
			{
				arr = head;
				while (*arr)
				{
					arr++;
				}
				*arr = d;
			}
		}
		else
		{
			cout << endl << "array is full";
		}
	}
	void print()
	{
	
		arr = head;
		cout << endl;
		while(*arr!=NULL)
		{
			cout << *arr;
			arr++;
		}
	}
private:
	int* arr;
	int* head;
	int size;
};

larr::larr()
{
	cout << endl << "enter the size of array :";
	cin >> size;
	arr = new int[size];
	head = arr;
	for (size_t i = 0; i < size; i++)
	{
		*arr = NULL;
		arr++;
		*arr = NULL;
	}
	arr = head;
}

larr::~larr()
{

}
int main()
{
	larr a;
	a.add();
	a.add();
	a.add();
	a.add();
	//cout << a.lenght();
	a.print();
	system("pause");
	return 0;
}