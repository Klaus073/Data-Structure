#include<iostream>
using namespace std;
int main()
{

int temp=0;
    int one[]={234,432,456,654,678,876};
    int ans=0;
    
     int n1= sizeof(one)/sizeof(one[0]); 
     int *ptr=new int[n1];
     int *ptr1=new int[n1];
     int *ptr2=new int[n1];
     for (int i = 0; i < n1; i++)
     {
         ptr[i]=one[i]%10;
        ptr1[i]=one[i]%100/10;
        ptr2[i]=one[i]/100;
         cout<<ptr2[i]<<" "<<ptr1[i]<<"  "<<ptr[i]<<endl;
     }

     
   
      
   
    
    
    return 0;
}