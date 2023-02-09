#include <cstdlib>
#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

char Field[9] = {'-','-','-','-','-','-','-','-','-',};
void clearScreen() {
    for (int i = 0; i < 100; i++) {   // clears the top of the console.
        cout << endl;
}
}
bool checkWinner(char player) {
    int wins[3][3] = { {0,1,2},
                       {3,4,5},
				       {6,7,8} };       //victory condition check.
	int row = 0	;
	int col = 0;
	 int diag1=0; 
   int diag2=0;			       
    for (int i = 0; i < 3; i++) {
    
        for (int j = 0; j < 3; j++){
		if (Field[wins[i][j]] == player)
                 row++;
           
        if (Field[wins[j][i]] == player)
                 col++;

        if (Field[wins[j][j]] == player)
                 diag1++;
           
        if (Field[wins[2-j][j]] == player)
                  diag2++;

}
        if (row == 3 || col == 3||diag1==3||diag2==3 ) {
		
	     return true;
	     break;
	}
	row=0;
	col=0;
	diag1=0;
	diag2=0;
}
        return false;
}

void printField() {
    cout << endl;
    cout << endl;
    cout << " TIC - TAC - TOE " << endl;
    cout << " Lets play the game ! " << endl;
    cout << " Player 1 moves (X) ..... Player 2 moves (0) " << endl;
    cout << "          |         |       " << endl;
    cout << "     " << Field[0] << "    |    " << Field[1] << "    |    " << Field[2] << endl;
    cout << " _________|_________|________ " << endl;
    cout << "          |         |       " << endl;
    cout << "     " << Field[3] << "    |    " << Field[4] << "    |    " << Field[5] << endl;
    cout << " _________|_________|________ " << endl;
    cout << "          |         |       " << endl;
    cout << "     " << Field[6] << "    |    " << Field[7] << "    |    " << Field[8] << endl;
    cout << "          |         |       " << endl;
}
int  getChoice() {
    cout << "\n Options for entering numbers: \n";
    cout << "   |   |   " << endl;
    cout << " 1 | 2 | 3 " << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " 4 | 5 | 6 " << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " 7 | 8 | 9 " << endl;
    cout << "   |   |   " << endl;
    cout << endl;

   printField();
    cout << " Enter a number: ";
    int choice;
    cin >> choice;
    while (choice > 9 || choice < 1 || Field[choice - 1] != '-') {  //we check whether the move is legal.
        cout << "Enter a number from 1 to 9:"<<endl;
        cin >> choice;
    }
    return choice;
}

char playGame()   {
    int turn = 1;
    while (!checkWinner('X') && !checkWinner('0')) {
        clearScreen();
        int choice =  getChoice() ;
        if (turn % 2 == 1) {
            Field[choice - 1] = 'X';
            if (checkWinner('X')) {                                      // assign the signs 'x' and '0' to the tetanus and check the winning condition.
                return 'X';
            }
        }
        else {
            Field[choice - 1] = '0';
            if (checkWinner('0')) {
                return '0';
            }
        }
        turn++;
        if (turn ==9) {
            return 'D';
        }  
    }
}
int main() {
	 char winner = playGame();
    printField();
  if ( winner=='X'){
  	cout<<"Player  <X> won!!!"<<endl;
  }
  if (winner=='0'){
  	cout<<"Player <0> won!!!"<<endl;
  }
  if (winner=='D'){
  	cout<<"It is draw!!!"<<endl;

} 
system("pause");
return 0;	
	
}

