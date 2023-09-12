#include<iostream>
using namespace std;

char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
char turn = 'X';
int row;
int col;




void display_board(){
    
    
     cout << "     |     |     " << endl;
    cout << "   " << board[0][0]<<" | " <<  board[0][1] <<"   |  "<< board[0][2]   << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
   cout << "   " << board[1][0]<<" | " <<  board[1][1] <<"   |  "<< board[1][2]   << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
   cout << "   " << board[2][0]<<" | " <<  board[2][1] <<"   |  "<< board[2][2]   << endl;
    cout << "     |     |     " << endl;
    
    
    
    
}

void player_turn(){
   
    int choice;
    if(turn == 'X')
    cout << " player 1 turn " << endl;
    if(turn == 'O')
    cout << " player 2 turn " << endl;
  
    cin>>choice;
    
   switch(choice){
       case 1:
       row = 0;
       col = 0;
       break;
       
       case 2:
       row = 0;
       col = 1;
       break;
       
       case 3:
       row = 0;
       col = 2;
       break;
       
       case 4:
       row = 1;
       col = 0;
       break;
       
       case 5:
       row = 1;
       col = 1;
       break;
       
       case 6:
       row = 1;
       col = 2;
       break;
       
       case 7:
       row = 2;
       col = 0;
       break;
       
       case 8:
       row = 2;
       col = 1;
       break;
       
      case 9:
       row = 2;
       col = 2;
       break;
       
       default:
       cout << " wrong choice " << endl;
       break;     
  
     }
     
     if(turn == 'X'&& board[row][col] != 'X' && board[row][col] != 'O'){
         board[row][col] = 'X';
         turn = 'O';
     }
     
     
 else if(turn == 'O' && board[row][col] != 'X' && board[row][col] != 'O'){
         board[row][col] = 'O';
         turn = 'X';
     }
     else{
         cout << "slot is already filled , please try again! " << endl;
         player_turn();
         
     }
    display_board();

    
}


 bool game_win(){
     
     // check win
    for(int i=0; i<=3; i++){
        if(board[i][0]== board[i][1] && board[i][1] == board[i][2])
        return false;
        
    }
          for(int j=0; j<3; j++){
        if(board[0][j]== board[1][j] && board[1][j] == board[2][j])
        return false;
          }
      
    for(int i=0; i<3; i++)
      if(board[0][0]== board[1][1] && board[1][1]== board[2][2] ){
          return false;
      }  

     
     
    //check if any box is not filled 
    
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;
    
}



int main(){
    
    cout << "Tic tac toe game " << endl;
    cout << " player 1 has symbol X " << endl;
    cout << " player 2 has symbol 0 " << endl;
    cout << "------------------" << endl;
    
    cout << " Here we have the game board " << endl;
    display_board();
    
    while(game_win()){
    
      
   player_turn();
     game_win();
     
  }
    if(turn == 'X')
    cout << " player 2 has won the game " << endl;
    if(turn == 'O')
    cout << " player 1 has won the game " << endl;

 //   system("CLS");
    
    return 0;
    
}