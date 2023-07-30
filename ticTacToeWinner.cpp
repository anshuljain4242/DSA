#include<iostream>
#include<string>
#include<vector>
using namespace std;


string ticTacToeWinner(vector<vector<int> > moves, int n) {
    int k = moves.size();
    
    vector<int> A(8, 0), B(8, 0);
    
    for(int i=0; i<k; i++){
        
        int row = moves[i][0];
        int col = moves[i][1];

        vector<int>& player = (i%2 == 0) ?A:B;

        player[row]++;
        player[col+3]++;   
        if(row == col) player[6]++;
        if(row == 2-col) player[7]++;                 
    }

    for(int i=0; i<8; i++){
        if(A[i] == 3) return "player1";
        if(B[i] == 3) return "player2";
    }

    if(k == 9) return "draw";
    return "uncertain";
}