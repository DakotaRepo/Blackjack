#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int start = 1;
char difficulty;
int cash = 10;


void difficultySelection() {
	do {
		std::cout << "Select Difficulty";

		std::cin >> difficulty;

		std::cout << "\nDifficulty is " << difficulty;

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
			cash = 400;

		}
}

int main()
{
	std::cout << "\nStart is " << start;
	if (start = 1) difficultySelection();
	std::cout << "\nStart is " << start;
	std::cout << "\nCash is " << cash;


	return 0;

}