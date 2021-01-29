#include <iostream>
#include <string>
using namespace std;

string fun(string str,int leave,int index)
{
  static string temp="";
    if(index>=str.size()||leave>=str.size())
        return temp;
    else
    {
        fun(str,leave+2,index);
    temp=temp+str[index+leave];
      
       return temp;
    }
         
}

int main()
{
    cout << fun("aabdfb",2,0);
    // if (fun("aabdfb",2,0) == "fb"){
    //     cout<<"Match"<<endl;
    // }
    // else cout<<"MissMatch"<<endl;
    
    return 0;

}