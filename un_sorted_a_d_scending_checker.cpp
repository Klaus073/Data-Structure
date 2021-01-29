#include <iostream>
using namespace std;
class ArrayPlaying
{
	int arr[7] = { 1,2,3,4,56,5 };
	int* ptr = arr;
	

public:
	void Length()
	{
		int arrLength = *(&arr + 1) - arr;
		cout << "Lngth of the array is " << arrLength << endl;
	}
	void get()
	{
		cout << "Enter the element you want to find inside the array \n";
		int element;
		cin >> element;
		int count = 0;
		while (ptr != *(&arr + 1))
		{
			if (*ptr == element)
			{
				cout << *ptr << " is present at index  " << count << endl;
				break;
			}
			ptr++;
			count++;
			
		}
		cout << endl;

	}
	void update()
	{
		cout << "Enter the element you want to update \n";
		int update;
		int newElement;
		cin >> update;
		int count=0;
		cout << "Enter the new element \n";
		cin >> newElement;
		while (ptr < *(&arr + 1))
		{
			if (*ptr == update)
			{
				*ptr = newElement;
				break;
			}
			
			count++;
			ptr++;
		
		
		}
		cout << "The new element is " << *ptr << " at index " << count << endl;
		
	}
	void back()
	{
		int element;
		cout << "Enter the current element inside the array where pointer is pointing \n";
		cin >> element;
		while (*ptr != element)
		{
			ptr++;
		}
		ptr--;
		cout << "The element present before the element that you entered is  " << *ptr << endl;

	}
	void next()
	{
		int element;
		cout << "Enter the current element inside the array where the pointer is pointing \n";
		cin >> element;
		while (ptr !=*(&arr+1))
		{
			ptr++;

		}
		ptr++;
		cout << "The element present after the element that you entered is  " << *ptr << endl;
	}
	void start()
	{
		ptr = arr;
		cout << "The element at the start of array \n"<<*ptr << endl;
	}
	void end()
	{
		while (ptr != *(&arr + 1))
		{
			if (ptr= *(&arr))
			{
				cout<<"The element at the end of the array is \n" << *ptr << endl;
				break;
			}
		}
	}
	void Search()
	{
		int x, y = 0;
		cout << "Enter the element you want to search inside the array \n";
		cin >> x;
		while (*arr != -1)
		{
			ptr++;
			
			if (*arr == x)
			{
				cout << "The element you searched for is present \n";
				return;
			}
			else
			{
				cout << "element not found \n";
				break;
			}
		}
		

	}
	void remove();
	void add();
};

int main()
{
	ArrayPlaying ApOBJ;
	//ApOBJ.get();
	//ApOBJ.update();
	//ApOBJ.back();
	//ApOBJ.next();
	//ApOBJ.start();
	//ApOBJ.end();
	ApOBJ.Search();

	return 0;
}