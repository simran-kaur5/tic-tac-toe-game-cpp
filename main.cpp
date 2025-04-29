#include <iostream>
#include <vector>
using namespace std;
void print(int n,vector<vector<char>> &mat){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool checkWinnerH(int n,vector<vector<char>> &mat){
    for(int i=0;i<n;i++){
        if(mat[i][0]==mat[i][1] && mat[i][1]==mat[i][2]){
            if(mat[i][0]=='O' || mat[i][0]=='X'){
                cout<<"Winner is: "<<mat[i][0]<<endl;
                return true;
            }
        }
    }
    return false;
}
bool checkWinnerV(int n,vector<vector<char>> &mat){
    for(int i=0;i<n;i++){
        if(mat[0][i]==mat[1][i] && mat[1][i]==mat[2][i]){
            if(mat[0][i]=='O' || mat[0][i]=='X'){
                cout<<"Winner is: "<<mat[0][i]<<endl;
                return true;
            }
        }
                    
    }
    return false;
}
bool checkWinnerD(int n,vector<vector<char>> &mat){
    if(mat[0][0]==mat[1][1] && mat[1][1]==mat[2][2]){
        if(mat[0][0]=='O'||mat[0][0]=='X'){
            cout<<"Winner is: "<<mat[0][0]<<endl;
            return true;
        }
    }
    if(mat[0][2]==mat[1][1] && mat[1][1]==mat[2][0]){
        if(mat[0][2]=='O'||mat[0][2]=='X'){
            cout<<"Winner is: "<<mat[0][2]<<endl;
            return true;
        }
    }
     return false;
}
bool checkAllFilled(int n,vector<vector<char>> &mat){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]!='O' && mat[i][j]!='X'){
                return false;
            }
        }
    }
    return true;
}
bool isFree(int i,int j,vector<vector<char>> &mat,int n){
    return mat[i][j]!='O' && mat[i][j]!='X';
}
void ticTacToe(int n ,vector<vector<char>> &mat){
    char currentPlayer ='O';
    while(true){
    print(n,mat);
    char num;
    cout<<"Player '"<<currentPlayer<<"' enter number 1-9: ";
    cin>>num;
    //if(num>9){
      //  cout<<"Enter a valid number"<<endl;
        //continue;
    //}
    int k=-1,l=-1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(mat[i][j]==num){
                k=i;
                l=j;
            }
        }
    }
    if(k==-1 && l==-1){
            cout<<"Enter a valid number"<<endl;
                continue;
    }
    if(isFree(k,l,mat,n)){
        if(currentPlayer!='O' && currentPlayer!='X'){
            cout<<"Enter a valid symbol.";
            continue;
        }
        mat[k][l]=currentPlayer;
        }else{
            cout<<"The space is already filled";
            }
        if(checkWinnerD(n,mat) || checkWinnerV(n,mat)||checkWinnerH(n,mat)){
            cout<<"Game Over";
            return;
        }
      if(checkAllFilled(n, mat)) {
            print(n, mat);
            cout << "Match Drawn!\n";
            return;
        }
        currentPlayer=(currentPlayer=='O'?'X':'O');
         
    }
}
int main() {
    int n=3;
    vector<vector<char>>mat={
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };
     ticTacToe( n,mat);
    return 0;
}
