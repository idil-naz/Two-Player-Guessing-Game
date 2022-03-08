#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void checkGuess(int lucky_number, int guessPlayer1, int guessPlayer2, int *flag, int *p1Score, int *p2Score); //Function prototype

int main(){
	
	int lucky_number; //The number that players will try to guess
	int guessPlayer1; //Player 1's guess
	int guessPlayer2; //Player 2's guess
	
	int p1Score = 0; //Score of player 1
	int p2Score = 0; //Score of player 2
	
	srand(time(0));
	lucky_number = (rand() % 1000) + 1; //Random number generator
	
	printf("\nA lucky number has been generated randomly. \n");
	printf(" The lucky number is: %d\n\n", lucky_number);
	
	int flag=0; //The flag variable that will act as a bool
	
	while(flag == 0){ //The guessing will continue unless one (or both) of the players make a correct guess and the flag becomes 1
		
		printf("********************************\n");
		printf("\nPlayer 1, enter your guess: ");
		scanf("%d", &guessPlayer1);       //Player 1 makes a guess 
	
		printf("Player 2, enter your guess: ");
		scanf("%d", &guessPlayer2);      //Player 2 makes a guess
		
		if(guessPlayer1 < 0 || guessPlayer2 < 0){  //The error message if one of the users enter a negative number 
		
		printf("Invalid guess! Try again.\n");
		continue;
		}	

		checkGuess(lucky_number, guessPlayer1, guessPlayer2, &flag, &p1Score, &p2Score);
	}
		
		printf("\n\nThe scores are: \n");
		printf("Player 1: %d", p1Score);
		printf("\nPlayer 2: %d\n", p2Score); //Printing the scores

	return 0;
}

void checkGuess(int lucky_number, int guessPlayer1, int guessPlayer2, int *flag, int *p1Score, int *p2Score){ //The function takes 6 parameters, 3 of which are pointers
	
	int p1Proximity;
	int p2Proximity;
	
		
		p1Proximity = abs(lucky_number - guessPlayer1); //Calculation of the proximities
		p2Proximity = abs(lucky_number - guessPlayer2);
	
		printf("\nProximity of Player 1's guess to the lucky number is: %d", p1Proximity);    //Printing the proximities onto the screen
		printf("\nProximity of Player 2's guess to the lucky number is: %d\n\n", p2Proximity);
	
	if(p1Proximity < p2Proximity){   
		
		printf("Player 1's guess is the closest to the lucky number.\n");
		
		*p1Score = *p1Score + 1; //Player 1 gets a point if their guess is close to the lucky number
		}
			
	else if(p2Proximity < p1Proximity){
		
		printf("Player 2's guess is closest to the lucky number.\n");
		
		*p2Score = *p2Score + 1; //Player 2 gets a point if their guess is close to the lucky number
		
		}
		
	else if(guessPlayer1 == guessPlayer2){
		printf("Both players have guessed the same number.\n");
		
		*p1Score = *p1Score + 1;
		*p2Score = *p2Score + 1;  //Both player 1 and 2 guess the same number
		}
		
	
	if(guessPlayer1 == lucky_number && guessPlayer2 != lucky_number){     //Player 1 guessed the correct the number but Player 2 did not
		*flag = 1;                //The game ends when the correct number is guessed
		*p1Score = *p1Score + 1;
		printf("Player 1 has guessed the number correctly!");
		
		}
	
		
	else if(guessPlayer2 == lucky_number && guessPlayer1 != lucky_number){  //Player 2 guessed the correct the number but Player 1 did not
		*flag = 1;                //The game ends when the correct number is guessed
		*p2Score = *p2Score + 1;
		printf("Player 2 has guessed the number correctly!");
		
		}		
	
	else if(guessPlayer1 == guessPlayer2 && (guessPlayer1 == lucky_number && guessPlayer2 == lucky_number)){   //Both players guessed the same and correct number
		*flag = 1;                //The game ends when the correct number is guessed
		
		*p1Score = *p1Score + 1;
		*p2Score = *p2Score + 1; //Both players gets +1 Score because they guessed correctly
		
		printf("Both players have guessed the number correctly!");
		
		}

}
