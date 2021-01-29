#include <iostream> 
using namespace std; 
#define rows 4 
#define cols 5 
int r[4] = { 0, 0, 1, -1 }; 
int c[4] = { 1, -1, 0, 0 }; 
  
bool checker(int x, int y, int matrix[][cols]) 
{ 
    if (x >= 0 && x <= rows && y >= 0 &&  y <= cols && matrix[x][y] == 1) 
        return true; 
    return false; 
} 
  

void helper(int i, int j, int k[][cols]) 
{ 
    
    k[i][j] = 1; 
    for (int g = 0; g < 4; g++) 
        if (checker(i + r[g], j + c[g], k)) 
            helper(i + r[g], j + c[g], k); 
} 

int helper_two(int matrix[][cols]) 
{ 
    
    for (int i = 0; i < cols; i++) 
        if (matrix[0][i] == 1) 
            helper(0, i, matrix); 


    for (int i = 0; i < cols; i++) 
        if (matrix[rows - 1][i] == 1) 
            helper(rows - 1, i, matrix); 


    for (int i = 0; i < rows; i++) 
        if (matrix[i][0] == 1) 
            helper(i, 0, matrix); 


    for (int i = 0; i < rows; i++) 
        if (matrix[i][cols - 1] == 1) 
            helper(i, cols - 1, matrix); 
  
    
    int result = 0; 
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j++) 
            if (matrix[i][j] == 1) 
                result++; 
    return result; 
} 

int main() 
{ 
    int matrix[][cols] = { { 0, 0, 0, 0, 0 }, 
                     { 0, 0, 0, 0, 0 }, 
                     { 0, 1, 0, 0, 0 }, 
                     { 0, 0, 0, 0, 0 } }; 
    cout << helper_two(matrix) << endl; 
    return 0; 
}