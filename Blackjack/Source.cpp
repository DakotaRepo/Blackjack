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
int dealing = 0;

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
//Need to add player and dealer hand, add checks to card count
void cardDealing() {
	int card = 0;
	do {
		
		card = (rand() % 13) + 1;
		std::cout << "\nCard is " << card;
		switch(card) {
		case 1:
			acecount--;
			break;
		case 2:
			twocount--;
			break;
		case 3:
			threecount--;
			break;
		case 4:
			fourcount--;
			break;
		case 5:
			fivecount--;
			break;
		case 6:
			sixcount--;
			break;
		case 7:
			sevencount--;
			break;
		case 8:
			eightcount--;
			break;
		case 9:
			ninecount--;
			break;
		case 10:
			tencount--;
			break;
		case 11:
			jackcount--;
			break;
		case 12:
			queencount--;
			break;
		case 13:
			kingcount--;
			break;

		default:
			std::cout << "\nError generating card";
		}
		dealing++;

	} while (dealing < 25);


}

void gamePlay() {


bidding();
cardDealing();

}

int main()
{
	srand(time(0));
	difficultySelection();
	gamePlay();
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



	return 0;

}