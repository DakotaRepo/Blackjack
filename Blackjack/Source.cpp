#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

char difficulty;
char playerChoice;
int cash = 0;
int bid = 0;
int	kingcount = 4;
int	queencount = 4;
int	jackcount = 4;
int	tencount = 4;
int	ninecount = 4;
int	eightcount = 4;
int	sevencount = 4;
int	sixcount = 4;
int	fivecount = 4;
int	fourcount = 4;
int	threecount = 4;
int	twocount = 4;
int	acecount = 4;
int dealingPlayer = 0;
int dealingDealer = 0;
int playerCardValue = 0;
int dealerCardValue = 0;
int cardDealer = 0;
int cardPlayer = 0;
bool playerIsBlackjack = false;
bool dealerIsBlackjack = false;
bool matchIsBlackjack = false;
bool playerDoubleDown = false;

//Need to balance this after adding in victory conditions
void difficultySelection() {
	do {
		std::cout << "Select Difficulty\n[E]asy\n[N]ormal\n[H]ard\n";

		std::cin >> difficulty;

	} while (difficulty != 'e' && difficulty != 'n' && difficulty != 'h' && difficulty != 'E' && difficulty != 'N' && difficulty != 'H');

		switch (difficulty) {

		case 'e': case 'E':
			cash = 300;
			break;
		
		case 'n': case 'N':
			cash = 200;
			break;
		
		case 'h': case 'H':
			cash = 100;
			break;
		
		default: 
			std::cout << "Error";

		}
}
//Should be good to go
void bidding() {
	
	do {
		bid = 0;
		
		if (cash >= 200) {

			std::cout << "\n\nYou have " << cash << " Cash total\n";
			std::cout << "\nPlease enter how much you wish to bid (1 - 200)";
			std::cin >> bid;
		}
		
		if (cash < 200) {

			std::cout << "\nPlease enter how much you wish to bid (1 - " << cash << ")";
			std::cin >> bid;
		}
		
		if (bid == 0 || bid > 200 || bid > cash) std::cout << "\nInvalid bid entry";
		
		if (std::cin.fail()) {
			
			std::cout << "\nError, you must enter a number\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}

	} while (bid == 0 || bid > 200 || bid > cash);

	cash = cash - bid;
}
//Should be good to go
void cardInitialPlayer() {
	do {
		
		cardPlayer = (rand() % 13) + 1;
		switch(cardPlayer) {
		case 1:
			if (acecount >= 1){
				
				acecount--;
				dealingPlayer++;
				playerCardValue = playerCardValue + 11;
				std::cout << "\nPlayer Card is Ace";
			}
			break;
		case 2:
			if (twocount >= 1){
				
				twocount--;
				dealingPlayer++;
				playerCardValue = playerCardValue + 2;
				std::cout << "\nPlayer Card is 2";
			}
			break;
		case 3:
			if (threecount >= 1){
				
				threecount--;
				dealingPlayer++;
				playerCardValue = playerCardValue + 3;
				std::cout << "\nPlayer Card is 3";
			}
			break;
		case 4:
			if (fourcount >= 1){
				
				fourcount--;
				dealingPlayer++;
				playerCardValue = playerCardValue + 4;
				std::cout << "\nPlayer Card is 4";
			}
			break;
		case 5:
			if (fivecount >= 1){
				
				fivecount--;
				dealingPlayer++;
				playerCardValue = playerCardValue + 5;
				std::cout << "\nPlayer Card is 5";
			}
			break;
		case 6:
			if (sixcount >= 1){
				
				sixcount--;
				dealingPlayer++;
				playerCardValue = playerCardValue + 6;
				std::cout << "\nPlayer Card is 6";
			}
			
			break;
		case 7:
			if (sevencount >= 1){
				
				sevencount--;
				dealingPlayer++;
				playerCardValue = playerCardValue + 7;
				std::cout << "\nPlayer Card is 7";
			}
			break;
		case 8:
			if (eightcount >= 1){
				
				eightcount--;
				dealingPlayer++;
				playerCardValue = playerCardValue + 8;
				std::cout << "\nPlayer Card is 8";
			}
			break;
		case 9:
			if (ninecount >= 1){
				
				ninecount--;
				dealingPlayer++;
				playerCardValue = playerCardValue + 9;
				std::cout << "\nPlayer Card is 9";
			}
			break;
		case 10:
			if (tencount >= 1){
				
				tencount--;
				dealingPlayer++;
				playerCardValue = playerCardValue + 10;
				std::cout << "\nPlayer Card is 10";
			}
			break;
		case 11:
			if (jackcount >= 1){
				
				jackcount--;
				dealingPlayer++;
				playerCardValue = playerCardValue + 10;
				std::cout << "\nPlayer Card is Jack";
			}
			break;
		case 12:
			if (queencount >= 1){
				
				queencount--;
				dealingPlayer++;
				playerCardValue = playerCardValue + 10;
				std::cout << "\nPlayer Card is Queen";
			}
			break;
		case 13:
			if (kingcount >= 1){
				
				kingcount--;
				dealingPlayer++;
				playerCardValue = playerCardValue + 10;
				std::cout << "\nPlayer Card is King";
			}
			break;

		default:
			std::cout << "\nError generating card";
		}

	} while (dealingPlayer < 2);

	std::cout << "\n";

}
void cardInitialDealer() {
	do {

		cardDealer = (rand() % 13) + 1;
		switch (cardDealer) {
		case 1:
			if (acecount >= 1) {
				
				acecount--;
				dealingDealer++;
				dealerCardValue = dealerCardValue + 11;
				std::cout << "\nDealer Card is Ace";
			}
			break;
		case 2:
			if (twocount >= 1) {
				
				twocount--;
				dealingDealer++;
				dealerCardValue = dealerCardValue + 2;
				std::cout << "\nDealer Card is 2";
			}
			break;
		case 3:
			if (threecount >= 1) {
				
				threecount--;
				dealingDealer++;
				dealerCardValue = dealerCardValue + 3;
				std::cout << "\nDealer Card is 3";
			}
			break;
		case 4:
			if (fourcount >= 1) {
				
				fourcount--;
				dealingDealer++;
				dealerCardValue = dealerCardValue + 4;
				std::cout << "\nDealer Card is 4";
			}
			break;
		case 5:
			if (fivecount >= 1) {
				
				fivecount--;
				dealingDealer++;
				dealerCardValue = dealerCardValue + 5;
				std::cout << "\nDealer Card is 5";
			}
			break;
		case 6:
			if (sixcount >= 1) {
				
				sixcount--;
				dealingDealer++;
				dealerCardValue = dealerCardValue + 6;
				std::cout << "\nDealer Card is 6";
			}

			break;
		case 7:
			if (sevencount >= 1) {
				
				sevencount--;
				dealingDealer++;
				dealerCardValue = dealerCardValue + 7;
				std::cout << "\nDealer Card is 7";
			}
			break;
		case 8:
			if (eightcount >= 1) {
				
				eightcount--;
				dealingDealer++;
				dealerCardValue = dealerCardValue + 8;
				std::cout << "\nDealer Card is 8";
			}
			break;
		case 9:
			if (ninecount >= 1) {
				
				ninecount--;
				dealingDealer++;
				dealerCardValue = dealerCardValue + 9;
				std::cout << "\nDealer Card is 9";
			}
			break;
		case 10:
			if (tencount >= 1) {
				
				tencount--;
				dealingDealer++;
				dealerCardValue = dealerCardValue + 10;
				std::cout << "\nDealer Card is 10";
			}
			break;
		case 11:
			if (jackcount >= 1) {
				
				jackcount--;
				dealingDealer++;
				dealerCardValue = dealerCardValue + 10;
				std::cout << "\nDealer Card is Jack";
			}
			break;
		case 12:
			if (queencount >= 1) {
				
				queencount--;
				dealingDealer++;
				dealerCardValue = dealerCardValue + 10;
				std::cout << "\nDealer Card is Queen";
			}
			break;
		case 13:
			if (kingcount >= 1) {
				
				kingcount--;
				dealingDealer++;
				dealerCardValue = dealerCardValue + 10;
				std::cout << "\nDealer Card is King";
			}
			break;

		default:
			std::cout << "\nError generating card";
		}
	
	} while (dealingDealer < 2);


}
void blackjackCheck() {

	matchIsBlackjack = false;
	
	if (playerCardValue == 21 && dealerCardValue != 21) {
		
		std::cout << "\n\nCongratulations! You have drawn a blackjack!";
		bid = bid * 3;
		cash = cash + bid;
		matchIsBlackjack = true;
	}
	
	else if (dealerCardValue == 21 && playerCardValue != 21) {
		
		std::cout << "\n\nUnfortunately, the dealer has drawn a blackjack!";
		bid = 0;
		matchIsBlackjack = true;
	}
	else if (dealerCardValue == 21 & playerCardValue == 21) {
		
		std::cout << "\n\nYou have both drawn a blackjack! The match is a tie";
		cash = cash + bid;
		matchIsBlackjack = true;
	}
}
void dealingPlayerGameplay() {
	do {

		cardPlayer = (rand() % 13) + 1;
		switch (cardPlayer) {
		case 1:
			if (acecount >= 1) {
				acecount--;
				dealingPlayer++;
				playerCardValue++;
				std::cout << "\nPlayer Card is Ace";
			}
			break;
		case 2:
			if (twocount >= 1) {
				twocount--;
				dealingPlayer++;
				playerCardValue = playerCardValue + 2;
				std::cout << "\nPlayer Card is 2";
			}
			break;
		case 3:
			if (threecount >= 1) {
				threecount--;
				dealingPlayer++;
				playerCardValue = playerCardValue + 3;
				std::cout << "\nPlayer Card is 3";
			}
			break;
		case 4:
			if (fourcount >= 1) {
				fourcount--;
				dealingPlayer++;
				playerCardValue = playerCardValue + 4;
				std::cout << "\nPlayer Card is 4";
			}
			break;
		case 5:
			if (fivecount >= 1) {
				fivecount--;
				dealingPlayer++;
				playerCardValue = playerCardValue + 5;
				std::cout << "\nPlayer Card is 5";
			}
			break;
		case 6:
			if (sixcount >= 1) {
				sixcount--;
				dealingPlayer++;
				playerCardValue = playerCardValue + 6;
				std::cout << "\nPlayer Card is 6";
			}

			break;
		case 7:
			if (sevencount >= 1) {
				sevencount--;
				dealingPlayer++;
				playerCardValue = playerCardValue + 7;
				std::cout << "\nPlayer Card is 7";
			}
			break;
		case 8:
			if (eightcount >= 1) {
				eightcount--;
				dealingPlayer++;
				playerCardValue = playerCardValue + 8;
				std::cout << "\nPlayer Card is 8";
			}
			break;
		case 9:
			if (ninecount >= 1) {
				ninecount--;
				dealingPlayer++;
				playerCardValue = playerCardValue + 9;
				std::cout << "\nPlayer Card is 9";
			}
			break;
		case 10:
			if (tencount >= 1) {
				tencount--;
				dealingPlayer++;
				playerCardValue = playerCardValue + 10;
				std::cout << "\nPlayer Card is 10";
			}
			break;
		case 11:
			if (jackcount >= 1) {
				jackcount--;
				dealingPlayer++;
				playerCardValue = playerCardValue + 10;
				std::cout << "\nPlayer Card is Jack";
			}
			break;
		case 12:
			if (queencount >= 1) {
				queencount--;
				dealingPlayer++;
				playerCardValue = playerCardValue + 10;
				std::cout << "\nPlayer Card is Queen";
			}
			break;
		case 13:
			if (kingcount >= 1) {
				kingcount--;
				dealingPlayer++;
				playerCardValue = playerCardValue + 10;
				std::cout << "\nPlayer Card is King";
			}
			break;

		default:
			std::cout << "\nError generating card";
		}

	} while (dealingPlayer < 1);
}
void dealingDealerGameplay() {
	do {

		cardDealer = (rand() % 13) + 1;
		switch (cardDealer) {
		case 1:
			if (acecount >= 1) {
				acecount--;
				dealingDealer++;
				dealerCardValue++;
				std::cout << "\nDealer Card is Ace\n";
			}
			break;
		case 2:
			if (twocount >= 1) {
				twocount--;
				dealingDealer++;
				dealerCardValue = dealerCardValue + 2;
				std::cout << "\nDealer Card is 2\n";
			}
			break;
		case 3:
			if (threecount >= 1) {
				threecount--;
				dealingDealer++;
				dealerCardValue = dealerCardValue + 3;
				std::cout << "\nDealer Card is 3\n";
			}
			break;
		case 4:
			if (fourcount >= 1) {
				fourcount--;
				dealingDealer++;
				dealerCardValue = dealerCardValue + 4;
				std::cout << "\nDealer Card is 4\n";
			}
			break;
		case 5:
			if (fivecount >= 1) {
				fivecount--;
				dealingDealer++;
				dealerCardValue = dealerCardValue + 5;
				std::cout << "\nDealer Card is 5\n";
			}
			break;
		case 6:
			if (sixcount >= 1) {
				sixcount--;
				dealingDealer++;
				dealerCardValue = dealerCardValue + 6;
				std::cout << "\nDealer Card is 6\n";
			}

			break;
		case 7:
			if (sevencount >= 1) {
				sevencount--;
				dealingDealer++;
				dealerCardValue = dealerCardValue + 7;
				std::cout << "\nDealer Card is 7\n";
			}
			break;
		case 8:
			if (eightcount >= 1) {
				eightcount--;
				dealingDealer++;
				dealerCardValue = dealerCardValue + 8;
				std::cout << "\nDealer Card is 8\n";
			}
			break;
		case 9:
			if (ninecount >= 1) {
				ninecount--;
				dealingDealer++;
				dealerCardValue = dealerCardValue + 9;
				std::cout << "\nDealer Card is 9\n";
			}
			break;
		case 10:
			if (tencount >= 1) {
				tencount--;
				dealingDealer++;
				dealerCardValue = dealerCardValue + 10;
				std::cout << "\nDealer Card is 10\n";
			}
			break;
		case 11:
			if (jackcount >= 1) {
				jackcount--;
				dealingDealer++;
				dealerCardValue = dealerCardValue + 10;
				std::cout << "\nDealer Card is Jack\n";
			}
			break;
		case 12:
			if (queencount >= 1) {
				queencount--;
				dealingDealer++;
				dealerCardValue = dealerCardValue + 10;
				std::cout << "\nDealer Card is Queen\n";
			}
			break;
		case 13:
			if (kingcount >= 1) {
				kingcount--;
				dealingDealer++;
				dealerCardValue = dealerCardValue + 10;
				std::cout << "\nDealer Card is King\n";
			}
			break;

		default:
			std::cout << "\nError generating card";
		}

	} while (dealingPlayer < 1);
}
void gamePlay() {

	blackjackCheck();
	playerDoubleDown = false;

	while (matchIsBlackjack == false && playerDoubleDown == false && playerChoice != 'S' && playerChoice != 's' && playerCardValue < 21) {
		
		std::cout << "\n\nYour card value is " << playerCardValue;
		std::cout << "\nDealer card value is " << dealerCardValue;
		std::cout << "\n\nWould you like to [H]it, [S]tand, or [D]ouble Down?";
		std::cin >> playerChoice;


		if (playerChoice == 'H' || playerChoice == 'h') dealingPlayerGameplay();
		
		else if (playerChoice == 'D' || playerChoice == 'd') {

			if (bid <= cash * 2) {
				cash = cash - bid;
				bid = bid + bid;
				dealingPlayerGameplay();
				playerDoubleDown = true;
			}
			else std::cout << "You don't have enough cash to double down!";
		}

		else if (playerChoice == 'S' || playerChoice == 's');
		
		else (std::cout << "\n\nInvalid selection");
	}

	while (matchIsBlackjack == false && dealerCardValue <= 21 && dealerCardValue < playerCardValue && playerCardValue <= 21) {
		
		std::cout << "\nDealer is drawing a card";
		dealingDealerGameplay();
		std::cout << "\nYour card value is " << playerCardValue;
		std::cout << "\nDealer card value is " << dealerCardValue << "\n";
	}

	if (matchIsBlackjack == false && playerCardValue > dealerCardValue && playerCardValue <= 21 || matchIsBlackjack == false && playerCardValue <= 21 && dealerCardValue > 21) {

		bid = bid + bid;
		cash = cash + bid;
		std::cout << "\nCongratulations, you have won this round!";
		std::cout << "\n\nPlayer final card value " << playerCardValue << "\nDealer final card value " << dealerCardValue;

	}

	if (matchIsBlackjack == false && dealerCardValue > playerCardValue && dealerCardValue <= 21 || matchIsBlackjack == false && dealerCardValue <= 21 && playerCardValue > 21) {

		std::cout << "\n\nUnfortunately, the dealer has won this round!";
		std::cout << "\n\nPlayer final card value " << playerCardValue << "\nDealer final card value " << dealerCardValue;

	}

	if (matchIsBlackjack == false && playerCardValue == dealerCardValue) {

		cash = cash + bid;
		std::cout << "\nYou and the dealer have tied!";
		std::cout << "\n\nPlayer final card value " << playerCardValue << "\nDealer final card value " << dealerCardValue;

	}
}
void gameReset() {

kingcount = 4;
queencount = 4;
jackcount = 4;
tencount = 4;
ninecount = 4;
eightcount = 4;
sevencount = 4;
sixcount = 4;
fivecount = 4;
fourcount = 4;
threecount = 4;
twocount = 4;
acecount = 4;
dealingPlayer = 0;
dealingDealer = 0;
playerCardValue = 0;
dealerCardValue = 0;
playerChoice = 'n';

}
void gameLoop() {

	do {

		bidding();
		cardInitialPlayer();
		cardInitialDealer();
		gamePlay();
		gameReset();
	} while (cash < 1000);

}

int main()
{
	srand(time(0));
	difficultySelection();
	gameLoop();



	return 0;

}