#include<iostream>
using namespace std;

bool canPlace(int board[][100],int row,int col,int n){

    // Row mein queen to nahi h
    for(int i=0;i<n;i++){
        if(board[row][i]==1){
            return false;
        }
    }

    // Col mein queen to nahi h
    for(int i=0;i<n;i++){
        if(board[i][col]==1){
            return false;
        }
    }

    /// Diagonals
    /// Top Left
    
    int i=row,j=col;
    while(i>=0&&j>=0){
        if(board[i][j]==1){
            return false;
        }
        i--;
        j--;
    } 

    ///Top Right
    i=row,j=col;
    while(i>=0 && j<n){
        if(board[i][j]==1){
            return false;
        }
        i--;
        j++;
    }

    return true;
}



bool solveNQueen(int board[][100],int n,int row){
    if(row==n){
        ///Print the board
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                cout<<board[x][y]<<" ";
            }
            cout<<endl;

        }

        return true;
    }

    ///Rec Case

    ///Try to place the queen in the current row

    for(int pos=0;pos<n;pos++){

            if(canPlace(board,row,pos,n)){
                    board[row][pos]=1;

                    bool agliQueenRakhPayeKya = solveNQueen(board,n,row+1);
                    if(agliQueenRakhPayeKya==true){
                        return true;
                    }

                    board[row][pos]=0;
            }

    }
    ///Backtracking
    return false;
}

int main(){

    int board[100][100];

    int n;
    cin>>n;

    for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                board[x][y]=0;
            }

        }
    if(n < 4 && n > 1)
        cout <<"Not possible" <<endl;
    else{
        solveNQueen(board,n,0);
    }


    return 0;
}
