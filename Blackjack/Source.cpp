#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

char difficulty;
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
int playerCardOne = 0;
int playerCardTwo = 0;
int dealerCardOne = 0;
int dealerCardTwo = 0;

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
		std::cout << "\nCash is " << cash;
}
//Should be good to go
void bidding() {
	
	do {
		bid = 0;
		if (cash >= 200) {

			std::cout << "\nPlease enter how much you wish to bid (1 - 200)";
			std::cin >> bid;
		}
		else {

			std::cout << "\nPlease enter how much you wish to bid (1 - " << cash << ")";
			std::cin >> bid;
		}
		if (bid == 0 || bid > 200 || bid > cash) std::cout << "\nInvalid bid entry";

	} while (bid == 0 || bid > 200 || bid > cash);

	cash = cash - bid;
}
//Should be good to go
void cardInitialPlayer() {
	int cardPlayer = 0;
	do {
		
		cardPlayer = (rand() % 13) + 1;
		std::cout << "\nCard is " << cardPlayer;
		switch(cardPlayer) {
		case 1:
			if (acecount >= 1){
				acecount--;
				dealingPlayer++;
			}
			break;
		case 2:
			if (twocount >= 1){
				twocount--;
				dealingPlayer++;
			}
			break;
		case 3:
			if (threecount >= 1){
				threecount--;
				dealingPlayer++;
			}
			break;
		case 4:
			if (fourcount >= 1){
				fourcount--;
				dealingPlayer++;
			}
			break;
		case 5:
			if (fivecount >= 1){
				fivecount--;
				dealingPlayer++;
			}
			break;
		case 6:
			if (sixcount >= 1){
				sixcount--;
				dealingPlayer++;
			}
			
			break;
		case 7:
			if (sevencount >= 1){
				sevencount--;
				dealingPlayer++;
			}
			break;
		case 8:
			if (eightcount >= 1){
				eightcount--;
				dealingPlayer++;
			}
			break;
		case 9:
			if (ninecount >= 1){
				ninecount--;
				dealingPlayer++;
			}
			break;
		case 10:
			if (tencount >= 1){
				tencount--;
				dealingPlayer++;
			}
			break;
		case 11:
			if (jackcount >= 1){
				jackcount--;
				dealingPlayer++;
			}
			break;
		case 12:
			if (queencount >= 1){
				queencount--;
				dealingPlayer++;
			}
			break;
		case 13:
			if (kingcount >= 1){
				kingcount--;
				dealingPlayer++;
			}
			break;

		default:
			std::cout << "\nError generating card";
		}
		if (playerCardOne == 0) (playerCardOne = cardPlayer);
		else (playerCardTwo = cardPlayer);
	
	} while (dealingPlayer < 2);


}
void cardInitialDealer() {
	int cardDealer = 0;
	do {

		cardDealer = (rand() % 13) + 1;
		std::cout << "\nCard is " << cardDealer;
		switch (cardDealer) {
		case 1:
			if (acecount >= 1) {
				acecount--;
				dealingDealer++;
			}
			break;
		case 2:
			if (twocount >= 1) {
				twocount--;
				dealingDealer++;
			}
			break;
		case 3:
			if (threecount >= 1) {
				threecount--;
				dealingDealer++;
			}
			break;
		case 4:
			if (fourcount >= 1) {
				fourcount--;
				dealingDealer++;
			}
			break;
		case 5:
			if (fivecount >= 1) {
				fivecount--;
				dealingDealer++;
			}
			break;
		case 6:
			if (sixcount >= 1) {
				sixcount--;
				dealingDealer++;
			}

			break;
		case 7:
			if (sevencount >= 1) {
				sevencount--;
				dealingDealer++;
			}
			break;
		case 8:
			if (eightcount >= 1) {
				eightcount--;
				dealingDealer++;
			}
			break;
		case 9:
			if (ninecount >= 1) {
				ninecount--;
				dealingDealer++;
			}
			break;
		case 10:
			if (tencount >= 1) {
				tencount--;
				dealingDealer++;
			}
			break;
		case 11:
			if (jackcount >= 1) {
				jackcount--;
				dealingDealer++;
			}
			break;
		case 12:
			if (queencount >= 1) {
				queencount--;
				dealingDealer++;
			}
			break;
		case 13:
			if (kingcount >= 1) {
				kingcount--;
				dealingDealer++;
			}
			break;

		default:
			std::cout << "\nError generating card";
		}
		if (dealerCardOne == 0) (dealerCardOne = cardDealer);
		else (dealerCardTwo = cardDealer);
	
	} while (dealingDealer < 2);


}
void gameLoop() {


bidding();
cardInitialPlayer();
cardInitialDealer();

}

int main()
{
	srand(time(0));
	difficultySelection();
	gameLoop();
	std::cout << "\n1 count is " << acecount;
	std::cout << "\n2 count is " << twocount;
	std::cout << "\n3 count is " << threecount;
	std::cout << "\n4 count is " << fourcount;
	std::cout << "\n5 count is " << fivecount;
	std::cout << "\n6 count is " << sixcount;
	std::cout << "\n7 count is " << sevencount;
	std::cout << "\n8 count is " << eightcount;
	std::cout << "\n9 count is " << ninecount;
	std::cout << "\n10 count is " << tencount;
	std::cout << "\n11 count is " << jackcount;
	std::cout << "\n12 count is " << queencount;
	std::cout << "\n13 count is " << kingcount;

	std::cout << "\nPlayercardone count is " << playerCardOne;
	std::cout << "\nPlayercardtwo count is " << playerCardTwo;
	std::cout << "\nDealercardone count is " << dealerCardOne;
	std::cout << "\nDealercardtwo count is " << dealerCardTwo;



	return 0;

}