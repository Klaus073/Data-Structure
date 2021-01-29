#include<iostream>
#include <math.h>
using namespace std;


bool repeated_elements_in_set_check(int Set[], int sizeOfSet)
{
    bool flag=true;
    
    for (int i = 0; i < sizeOfSet; i++)
    {
        for (int j = i+1; j < sizeOfSet; j++)
        {
            if (Set[i]==Set[j])
            {   
                flag=false;
                return flag;
            }
            else
            {
                flag=true;
            }   
        }
    }
   return flag;    
}
bool pair_is_in_relation(int left, int right, int Relation[], int sizeOfRelation)
{
    for(int i=0; i+1<sizeOfRelation; i+=2) {
        if (Relation[i]==left && Relation[i+1]==right)
            return true;
       
        
    }
    return false;
}
void reflexive(int Set[], int sizeOfSet, int Relation[], int sizeOfRelation) 
{
  bool flag = true;
  int *ptr=Set;
  if (sizeOfRelation==0 && sizeOfSet==0)
  {
      cout<<"set:relation "<<"[] ="<<"{}"<<endl;
      cout<<"Set is not Reflexive"<<endl;
        return;
    
  }
  if (sizeOfRelation!=0 && sizeOfSet==0)
  {
      cout<<"set:relation "<<"[] ={";
      for (int i = 0; i < sizeOfRelation-1; i++)
      {
          int x = Relation[i];
            int x1 = Relation[i+1];
            cout<<"("<<x<<","<<x1<<")"<< ",";
      }
      cout<<"}";
      cout<<"\nNot Possible "<<endl;
      return;
  }
  
  
      
   if (repeated_elements_in_set_check( ptr,  sizeOfSet)==true)
    {
        cout<<"{";
      for(int i=0; i<sizeOfRelation-1; i+=2) 
        {
            int e = Relation[i];
            int e1 = Relation[i+1];
            
           
            
            if(e==e1) 
            {
                
            cout<<"("<<e<<","<<e1<<")";
                    flag= true;
                   //break;
                }
                if (e!=e1)
        {
            flag=false;
        }
            }
            // if (e!=e1)
            // {
            //     cout<<"\n not reflexive because of this"<<endl;
            //     cout<<"("<<e<<","<<e1<<")"<< ","<<"it should be this "<<"("<<e<<","<<e<<")"<< ","<<endl;
            //     flag==false;
            //     return;
            // }
        
        
            
        }
   
//    else
//    {
//        flag=false;
//    }
   
 
  
  
  
  
 
//return flag;
if (flag)
  {
    cout<<"}"<<endl;
    cout << "Given Relation Is Reflixive :" << endl; 
  }
 
  else
  {
    cout<<"}"<<endl;
    cout << "Given Relation Is Not Reflixive :" << endl; 
  }
}

// bool symmetric(int Set[], int sizeOfSet, int Relation[], int sizeOfRelation)
// {
// bool flag = true; // set flag to true


// for(int i=0; i+1<sizeOfRelation; i+=2) // for each pair (e,f) in Relation
// {
//     int e = Relation[i];
//     int f = Relation[i+1];
//     if(pair_is_in_relation(f, e, Relation, sizeOfRelation)) // if pair(e,f) is not in Relation
//     {
//         if(flag) // set flag to false
//         {
//             return false;
//             break;
//         }
//     }
// }
// if(flag) // if flag return true
//     cout << "Symmetric - Yes" << endl;
// else // if flag is false return false
//     cout << "Symmetric - No" << endl;

//     return flag;
// }

// void antiSymmetric(int Set[], int sizeOfSet,int Relation[], int sizeOfRelation) 
// {
//     bool holds = true;
//     int *ptr=Set;
//   cout<<"{";
//   if(repeated_elements_in_set_check( ptr,  sizeOfSet)==true)
//     { 
//         for(int i=0; i<sizeOfRelation-1; i+=2)  
//             {
//                 int e = Relation[i];
//                 int f = Relation[i+1];
//                 cout<<"("<<e<<","<<f<<")"<< "";
//                 if(pair_is_in_relation(f, e, Relation, sizeOfRelation))
//                 {
//                     if (e != f)
//                     {
//                         holds = false;
//                         break;
//                     }
//                 }
//             }
//     }

//     else
//     {
//       holds=false;
//     }
    
//     if (holds)
//     {
//         cout<<"}"<<endl;
//         cout << "Given Relation Is Anti-Symmetric :" << endl; 
//     }
 
//   else
//     {
//         cout<<"}"<<endl;
//         cout << "Given Relation Is Not Anti-Symmetric :" << endl; 
//     }
// }



int main()
{
//int x[0] = {};
//cout<<exceptional_check_for_null_set(x,0);

////////////////////////////////
int set1[6] = {1, 2, 3,4,5,6,};
cout<<repeated_elements_in_set_check(set1,6)<<endl;
int rel1[14] = { 1, 1, 2, 2, 3, 2,3,3,4,4,5,5,6,6};
cout << "Set 1: " << endl;
reflexive(set1, 6, rel1, 14);
cout<<endl;
// cout<<symmetric(set1, 4, rel1, 8);
// cout<<endl;
// antiSymmetric(set1, 4, rel1, 8);
// cout<<endl;
// cout << endl;
// char set2[4] = {'x', 'y', 'z'};
// char rel2[8] = {'x', 'y', 'y', 'z', 'y', 'y', 'z', 'z'};
// cout << "Set 2: " << endl;
// charReflexive(set2, 4, rel2, 8);
// charSymmetric(set2, 4, rel2, 8);
// charAntiSymmetric(set2, 4, rel2, 8);

// cout << endl;
// char set3[3] = {'x', 'y', 'z'};
// char rel3[18] = {'x', 'x', 'y', 'z', 'x', 'y', 'z', 'y', 'x', 
//                  'z', 'y', 'y', 'z', 'x', 'y', 'x', 'z', 'z'};
// cout << "Set 3: " << endl;
// charReflexive(set3, 3, rel3, 18);
// charSymmetric(set3, 3, rel3, 18);
// charAntiSymmetric(set3, 3, rel3, 18);

// cout <<"-------------------" <<endl;
// int set4[4] = {1, 2, 3, 4};
// int rel4[12] = {1,1,1,2,2,1,2,2,3,3,4,4};
//                 //{(1, 1),(1, 2),(2, 1),(2, 2),(3, 3),(4, 4)}
// cout << "Set 4: " << endl;
// reflexive(set4, 4, rel4, 12);
// cout<<endl;
// cout<<symmetric(set4, 4, rel4, 12);
// cout<<endl;
// antiSymmetric(set4, 4, rel4, 12);




return 0;
}