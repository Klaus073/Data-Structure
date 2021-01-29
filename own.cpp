#include <iostream>

using namespace std;

void ref(int s[], int sizeOfSet, int r[], int sizeOfRelation)
{
    string flag="";
    if (sizeOfSet==0 && sizeOfRelation==0)
    {
        cout<<"Set=[]"<<"  "<<"Relation={}"<<endl;
        cout<<"Relation is Reflexive"<<endl;
        return;
    }
    else if (sizeOfSet==0 && sizeOfRelation!=0)
    {
        cout<<"Set=[] "<<endl;
        cout<<"Relation={";
        for (int i = 0; i < sizeOfRelation-1; i+=2)
        {
            int x1=r[1];
            int x2=r[i+1];
            cout<<"("<<x1<<","<<x2<<")";
        }
        cout<<endl;
        cout<<"not reflexive not possible"<<endl;
        return;
    }

    bool found=true;
    
   for (int i = 0; i < sizeOfSet; i++)
   {
       //cout<<"hello1"<<endl;
       for (int j = 0; j < sizeOfRelation-1; j+=2)
       {
           //cout<<"hello2"<<endl;
            if (r[j]==r[j+1])
            {
                if (s[i]==r[j])
                {
                    found=true;
                    break;
              
                }
                 else if (s[i]!=r[j])
               {
                found=false;
               }
                
            } 
       } 
       if (found==true)
            {
                flag="Give Data holds Reflexive property ";
               
            }
        else if (found==false)
            {
                flag="Give Data dont holds Reflexive property ";
                cout<<"Because of these sets";
                cout<<"("<<s[i]<<","<<s[i]<<")"<<endl;
            }
   }
   
   cout<<flag<<endl;
   
    
}
void sym(int s[], int sizeOfSet, int r[], int sizeOfRelation)
{
bool flag=true;
if (sizeOfSet==0 && sizeOfRelation==0)
    {
        cout<<"Set=[]"<<"  "<<"Relation={}"<<endl;
        cout<<"Relation is  Symmetric"<<endl;
        return;
    }
    else if (sizeOfSet==0 && sizeOfRelation!=0)
    {
        cout<<"Set=[] "<<endl;
        cout<<"Relation={";
        for (int i = 0; i < sizeOfRelation; i+=2)
        {
            int x1=r[1];
            int x2=r[i+1];
            cout<<"("<<x1<<","<<x2<<")";
        }
        cout<<endl;
        cout<<"not  Symmetric not possible"<<endl;
        return;
    }

for (int i = 0; i < sizeOfRelation; i+=2)
{
    //cout<<"hello1"<<endl;
    
    int x1=r[i];
    int x2=r[i+1];

    if (x1==x2)
    {
        flag =true;
    }
    else
    {
         for (int j = 0; j < sizeOfRelation-1; j+=2)
    {
       // cout<<"hello2"<<endl;
         int t1=r[j];
         int t2=r[j+1];
        
        if (t1==x2 && t2==x1)
        {
            flag=true;
            //cout<<"true if "<<endl;
             break;
        }
        else if (t1!=x2 && t2!=x1)
        {
            flag= false;
           // cout<<"false if "<<endl;
        }
    }
     if (flag==true)
    {
        cout<<"relation is Symmetric"<<endl;
        break;
    }
    else if (flag==false)
    {
        cout<<"relation is not Symmetric beacuse of these not found subsets"<<endl;
        cout<<"("<<x2<<","<<x1<<")";
        //break;
    }
    }
}
}
void asym(int s[], int sizeOfSet, int r[], int sizeOfRelation)
{
bool flag=true;
if (sizeOfSet==0 && sizeOfRelation==0)
    {
        cout<<"Set=[]"<<"  "<<"Relation={}"<<endl;
        cout<<"Relation is Anti Symmetric"<<endl;
        return;
    }
    else if (sizeOfSet==0 && sizeOfRelation!=0)
    {
        cout<<"Set=[] "<<endl;
        cout<<"Relation={";
        for (int i = 0; i < sizeOfRelation; i+=2)
        {
            int x1=r[1];
            int x2=r[i+1];
            cout<<"("<<x1<<","<<x2<<")";
        }
        cout<<endl;
        cout<<"not Anti Symmetric not possible"<<endl;
        return;
    }

for (int i = 0; i < sizeOfRelation; i+=2)
{
  //  cout<<"hello1"<<endl;
    
    int x1=r[i];
    int x2=r[i+1];
    if (x1==x2)
    {
        flag =true;
    }
    else
    {
    
        for (int j = 0; j < sizeOfRelation-1; j+=2)
       {
        //cout<<"hello2"<<endl;
         int t1=r[j];
         int t2=r[j+1];
        
      if (x2==t1 && x1==t2)
      {
          //cout<<"if-1"<<endl;
          if (x1==x2)
          {
              flag=true;
          }
          else
          {
              flag=false;
          }
          
          
      }
     else if (x2!=t1 && x1!=t2)
      {
         // cout<<"if-2"<<endl;
         flag==true;
      }
  
      
    }
           }  
            if (flag==true)
    {
        cout<<"relation is Anti Symmetric"<<endl;
      // break;
    }
    else if (flag==false)
    {
        cout<<"relation is not AntiSymmetric beacuse of these not found subsets"<<endl;
        cout<<"("<<x2<<"!="<<x1<<")";
        break;
    }

    }       

}



int main(){
    cout<<"****************************"<<endl;
cout<<"  SET - 1  "<<endl;
int set1[6] = {1, 2, 3,4,5,6};

int rel1[14] = {1,1,2,2,3,2,3,3,4,4,5,5,6,6};
cout<<"Set=[";
for (int i = 0; i < 6; i++)
{
    cout<<set1[i]<<",";
}
cout<<"]";
cout<<endl;
cout<<"Relation={";
for (int i = 0; i < 14; i++)
{
   cout<<rel1[i]<<",";
}
cout<<"}";
cout<<endl;
	//cout<<"  SET - 2  "<<endl;
	ref(set1, 6, rel1, 14);
    cout<<"-------------"<<endl;
    sym(set1, 6, rel1, 14);
    cout<<endl;
    cout<<"-------------"<<endl;
    asym(set1, 6, rel1, 14);
    cout<<endl;
    

    int set2[] = {};
int rel2[] ={} ;
cout<<"****************************"<<endl;
cout<<"  SET - 2  "<<endl;
	ref(set2, 0, rel2, 0);
    cout<<"-------------"<<endl;
    sym(set2, 0, rel2, 0);
    cout<<endl;
    cout<<"-------------"<<endl;
    asym(set2, 0, rel2, 0);
    cout<<endl;
cout<<"****************************"<<endl;
cout<<"  SET - 3  "<<endl;
    int set3[] = {};
int rel3[2] ={1,1} ;
//ref(set1, 0, rel1, 0);
    ref(set3, 0, rel3, 2);
    cout<<"-------------"<<endl;
    sym(set3, 0, rel3, 2);
    cout<<endl;
    cout<<"-------------"<<endl;
    asym(set3, 0, rel3, 2);
    cout<<endl;
cout<<"****************************"<<endl;
cout<<"  SET - 4  "<<endl;
    int set4[6] = {1, 2, 3,4,5,6,};

int rel4[16] = {1,1,2,2,3,2,2,3,3,3,4,4,5,5,6,6};
ref(set4,6 , rel4, 16);
cout<<"Set=[";
for (int i = 0; i < 6; i++)
{
    cout<<set4[i]<<",";
}
cout<<"]";
cout<<endl;
cout<<"Relation={";
for (int i = 0; i < 16; i++)
{
   cout<<rel4[i]<<",";
}
cout<<"}";
cout<<endl;
    cout<<"-------------"<<endl;
    sym(set4, 6, rel4, 16);
    cout<<endl;
    cout<<"-------------"<<endl;
    asym(set4, 6, rel4, 16);
    cout<<endl;

    cout<<"****************************"<<endl;
cout<<"  SET - 5  "<<endl;
    int set5[6] = {1, 2, 3,4,5,6};

int rel5[4] = {1,1,2,2};

cout<<"Set=[";
for (int i = 0; i < 6; i++)
{
    cout<<set5[i]<<",";
}
cout<<"]";
cout<<endl;
cout<<"Relation={";
for (int i = 0; i < 4; i++)
{
   cout<<rel5[i]<<",";
}
cout<<"}";
cout<<endl;
ref(set5,6 , rel5, 4);
    cout<<"-------------"<<endl;
    sym(set4, 6, rel4, 16);
    cout<<endl;
    cout<<"-------------"<<endl;
    asym(set5, 6, rel4, 4);
    cout<<endl;

return 0;
}