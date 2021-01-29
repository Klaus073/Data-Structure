#include<iostream>
using namespace std;
//#define MAX 8
int main()
{
	int arr[8] = { 7,8,9,1,3,2,4,5 };
	int x = arr[0];
	int index = 0;
	int counter=0;
	int temp = 0;
	for (int i = 0; i < 8; i++)
	{
		if (x>arr[i])
		{
			x = arr[i];
			index = i;
            //counter++;
		}
	}
	cout << x <<"    "<<index  <<endl;

    
	//int* ptr = new int[temp];
	
	for (int i = index; i < 8; i++)
	{
		//ptr[i] = arr[i];
		cout << arr[i] << "   ";
		counter++;
	}

    cout<<endl;
	
    temp = counter;
	cout << counter << endl;
	cout << endl;
int* ptr = new int[temp];

	
	for (int i = index; i < 8; i++)
	{
		ptr[i] = arr[i];
		cout << ptr[i] << "   ";
		//counter++;
	}
	cout << endl;
for (int i = index; i < 8; i++)
{
    cout<<ptr[i]<<"  ";
}
cout<<endl;

      int len = sizeof(ptr)/sizeof(ptr[0]);
cout<<"ddd"<<len<<endl;
    for (int i = index; i < 8; i++)
    {
      if(ptr[i]<ptr[i+1])
      {
          cout<<ptr[i]<<endl;
      }
      else
      {
          cout<<ptr[i+1]<<endl;
      }
      
    }
    

}
