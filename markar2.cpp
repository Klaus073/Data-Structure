#include<iostream>
#include<string>
using namespace std;

// ############# PART-A #######################
////////  DO NOT CHANGE FUNCTION NAME AND PARAMTERS ///////
//string leave_2nd_print_reverse(string str, int leave, int index=0){
        // YOUR CODE HERE

//}

////////  DO NOT CHANGE FUNCTION NAME AND PARAMTERS ///////
// ############# PART-B #######################

    //UNCOMMENT WHEN YOU DONE WITH PART A BECAUSE TEST CASES WILL SHOW YOU FAIL
int count_after_specific(string str, int num1, int num2, int index = 0) {
    int c = 0;
    string a=to_string(num1);
    string b=to_string(num2);
    if (index >= str.length()) {
        return 0;
    }
    else {

  
        if((str.substr(1)==a)&&(str.substr(2)==b))
        {

            c++;
        }
            return  count_after_specific(str,num1, num2,index+1 ) + c;

       

    }

}

int main() {



    // PART A SAMPLE
    //cout<<"Output:"<<leave_2nd_print_reverse("aabdfb",2,0)<<endl;
    // PART B SAMPLE
    cout << "Output:" << count_after_specific("111123112322511232000230", 2, 5, 0) << endl;


}