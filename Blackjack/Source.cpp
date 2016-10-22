#include <iostream>
#include <vector>
#include <string>
#include <fstream>

char difficulty;
int cash = 10;
int bid = 0;


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

void gamePlay() {
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

bidding();

}

int main()
{
	difficultySelection();
	gamePlay();



	return 0;

}