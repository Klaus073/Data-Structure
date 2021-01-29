#include<iostream>
#include <math.h>
using namespace std;
bool pair_is_in_relation(int left, int right, int b[], int sizeOfB)
{
    for(int i=0; i+1<sizeOfB; i+=2) {
        if (b[i]==left && b[i+1]==right)
            return true;
    }
    return false;
}
bool reflexive(int a[], int sizeOfA, int b[], int sizeOfB) 
{
  bool hold = true;
  for(int i=0; i+1<sizeOfB; i+=2) 
  {
    int e = b[i];
    int e1 = b[i];
    if(pair_is_in_relation(e1, e, b, sizeOfB) == false) 
    {
        if (hold) 
    {
            return false;
            break;
         }
    }
  }
  if (hold)
    cout << "Reflexive - Yes" << endl; 
  else
    cout << "Reflexive - No" << endl; 
return hold;
}

bool symmetric(int a[], int sizeOfA, int b[], int sizeOfB)
{
bool hold = true; // set hold to true
for(int i=0; i+1<sizeOfB; i+=2) // for each pair (e,f) in b
{
    int e = b[i];
    int f = b[i+1];
    if(pair_is_in_relation(f, e, b, sizeOfB)) // if pair(e,f) is not in b
    {
        if(hold) // set hold to false
        {
            return false;
            break;
        }
    }
}
if(hold) // if hold return true
    cout << "Symmetric - Yes" << endl;
else // if hold is false return false
    cout << "Symmetric - No" << endl;
}

void antiSymmetric(int b[], int sizeOfB)
{
bool hold = true; // set hold to true
for(int i = 0; i < sizeOfB;) // for each pair (e,f) in b
{
    if(hold == false)
    {
        cout << "AntiSymmetric - No" << endl; 
        break; //Did not find (e,e) in b
    }
    for(int j = 0; j < sizeOfB;)
    {
        if(b[i] == b[j+1] && b[i+1] == b[j]) //If true, then pair(f,e) exists
        {
            if(b[i+1] != b[i]) //If true, relation is antisymmetric
            {
                hold = true;
                break;
            }
            else
            {
                hold = false;
                j = j + 2;
            }
        }
        else
        {
            hold = false;
            j = j + 2;
        }

    }
    i = i + 2;

}
if(hold == true)
    cout << "AntiSymmetric - Yes" << endl;

}

void transitive(int a[], int sizeOfA, int b[], int sizeOfB)
{

}

int main()
{
char keepGoing = 'y';
    while (keepGoing=='y') {

int set1[4] = {0, 1, 2, 3};
int rel1[8] = {0, 0, 1, 1, 2, 2, 3, 3};
cout << "Set 1: " << endl;
reflexive(set1, 3, rel1, 4);
symmetric(set1, 3, rel1, 4);
//antiSymmetric(set1, 3, rel1, 4);

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

cout << endl;
int set4[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int rel4[20] = {1, 7, 2, 5, 2, 8, 3, 6, 4, 7, 5, 8, 6, 6, 1, 1,
                2, 2};
cout << "Set 4: " << endl;
reflexive(set4, 8, rel4, 20);
symmetric(set4, 8, rel4, 20);
//antiSymmetric(set4, 8, rel4, 20);

cout << endl << "Would you like to test it again? (y/n): ";
    cin >> keepGoing;
}

return 0;
}