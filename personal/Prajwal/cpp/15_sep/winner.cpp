// Determine the winner of a game of deleting Characters from a String
/* Given numeric string str, the task is to determine the winner of the game when two players play a game optimally with the string as per the given conditions:

    - Player 1 always starts first.
    - In one turn one player can remove the contiguous elements from the string and the number of elements removed will add up to his score. Player 1 will remove odd contiguous elements and Player 1 will remove even contiguous elements.
    - Any player who is not able to make a move loses the game.
    - After all the strings are removed, the player with maximum scores wins the game and if scores are equal then print “-1”.
*/
#include <bits/stdc++.h> 
using namespace std;   

void determineWinner(string str) 
{     
    vector<int> A(10);  
    // sum1 as player 1
    // sum2 as player 2
    int sum1 = 0, sum2 = 0;   
   
    for (int i = 0; i < str.length(); i++) { 
        A[int(str[i]) - 48]++; 
    } 
  
    for (int i = 0; i <= 9; i++) { 
  
        // Turn for the player1 
        if (i % 2 != 0) { 
  
            // Add score of player1 
            sum1 = sum1 + A[i]; 
        } 
        else { 
  
            // Add score of player2 
            sum2 = sum2 + A[i]; 
        } 
    } 
  
    // Check if its a draw 
    if (sum1 == sum2) { 
        cout << "-1"; 
    } 
  
    // If score of player 1 is greater 
    else if (sum1 > sum2) { 
        cout << "Player 1"; 
    } 
  
    // Otherwise 
    else { 
        cout << "Player 2"; 
    } 
}   

int main() 
{ 
    string str = "78787"; 
    determineWinner(str); 
    return 0; 
} 
