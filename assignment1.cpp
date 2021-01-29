#include <iostream>
using namespace std;

class list {
    protected:       
   int arr[5] ={1,2,3,4,5};
  
   public:
   
  int i = 0, j = n;
   void  print()
   {
       int item = 10, k = 3, n = 5;
       for (int i = 0; i < n; i++)
       {
           cout<<" arr["<<i<<"]"<<"="<<arr[i]<<endl;
           
       }
       
   }
   void insert()
       {
           int item = 10, k = 3, n = 5;
           int i = 0, j = n;
           n = n + 1;
while( j >= k) {
      arr[j+1] = arr[j];
      j = j - 1;

   arr[k] = item;

   cout<<"The array elements after insertion :\n";

   for(int i = 0; i<n; i++) {
      cout<< i<< arr[i];
   }

       }
   }
};


int main()
{
cout<<"hello\n";
list l;
l.print();
l.insert();


return 0;
}