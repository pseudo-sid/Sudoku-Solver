#include<iostream>
#include<cmath>
using namespace std;

bool canPlace(int mat[][9], int i, int j, int n, int num){
    for(int x = 0; x < n; x++){
        //rows and columns
        if(mat[x][j] == num || mat[i][x] == num)
            return false;
    }
    int rn = sqrt(n);
    int sx = (i/rn) * rn;
    int sy = (j/rn) * rn;
    for(int x = sx; x < sx + rn; x++)
        for(int y = sy; y < sy + rn; y++)
            if(mat[x][y] == num)
                return false;
    return true;
}

bool solveSudoku(int mat[][9], int i, int j, int n){
    //base case
    if(i == n){
        //print the solution
        for(int k = 0; k < n; k++)
        {
            if(k % 3 == 0)
                cout << endl;
            for(int l = 0; l < n; l++){
                if(l %3 == 0)
                    cout <<" ";
                cout << mat[k][l] <<" ";
            }
            cout << endl;
        }
        return true;
    }
    
    //case row end
    if(j == n)
        return solveSudoku(mat, i+1, 0, n);
    //Skip the prefilled cells
    if(mat[i][j] != 0)
        return solveSudoku(mat, i, j+1, n);
    //recursive case
    //fill the current cell with possible options
    for(int number = 1; number <= n; number++){
        if(canPlace(mat, i,j, n, number)){
            //Assume this is correct
            mat[i][j] = number;
            bool couldWeSolve = solveSudoku(mat, i , j+1, n);
            if(couldWeSolve)
                return true;
            
        }
    }
    //backtrack
    mat[i][j] = 0;
    return false;
}
int main(){

//feed your own values. 0 for empty block and value for value block. The program prints the solution to the problem.
    int mat[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    solveSudoku(mat, 0,0,9);
    return 0;
}
