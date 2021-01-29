#include<iostream>
using namespace std;

int abc(int x,int y)
{
    int a=0;
    if(y==0)
    {
        return 1;
    }
    else
    {
        //a=abc(x,y-1);
        //cout<<a<<endl;
        return x*=x*abc(x,y-1);
    }
    
}
int main(){
    cout<<abc(5,3);
    return 0;

}