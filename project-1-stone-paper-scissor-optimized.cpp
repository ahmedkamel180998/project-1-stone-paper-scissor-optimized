#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

enum enGameChoice { stone = 1, paper = 2, scissors = 3 };
enum enWinner { player = 1, computer = 2, draw = 3 };

struct stRoundInfo {
	short roundNumber = 0;
	enGameChoice playerChoice = enGameChoice::paper;
	enGameChoice computerChoice = enGameChoice::paper;
	enWinner roundWinner = enWinner::draw;
	string roundWinnerName;
};

struct stGameResults {
	short gameRounds = 0;
	short playerWonTimes = 0;
	short computerWonTimes = 0;
	short drawTimes = 0;
	enWinner gameWinner = enWinner::draw;
	string gameWinnerName;
};

int readNumberInRange(string message, int from, int to) {
	int numberInRange;

	do
	{
		cout << message << endl;
		cin >> numberInRange;
	} while (numberInRange < from || numberInRange > to);

	return numberInRange;
}

int getRandomNumber(int lowerBound, int upperBound) {
	int randomNumber = (rand() % (upperBound - lowerBound) + 1 + lowerBound);
	return randomNumber;
}

short howManyRounds() {
	return readNumberInRange("How Many Rounds 1 to 10 ?", 1, 10);
}


// Screen Formatting Functions

string tabs(short howManyTabs) {
	string tabs = "";

	for (short i = 0; i < howManyTabs; i++)
	{
		tabs = tabs + "\t";
	}
	return tabs;
}

string newLines(short howManyTabs) {
	string newLines = "";

	for (short i = 0; i < howManyTabs; i++)
	{
		newLines = newLines + "\n";
	}
	return newLines;
}

void showGameOverScreen() {
	cout << tabs(4) << "---------------------------------------------" << newLines(2);
	cout << tabs(4) << "----------------- Game Over -----------------" << newLines(2);
	cout << tabs(4) << "---------------------------------------------" << newLines(2);
}

void setWinnerScreenColor(enWinner winner) {
	switch (winner)
	{
	case enWinner::player:
		system("color 2F");
		break;
	case enWinner::computer:
		system("color 4F");
		cout << "\a";
		break;
	case enWinner::draw:
		system("color 6F");
		break;
	}
}

void resetScreen() {
	system("cls");
	system("color 0F");
}

// end Screen Formatting Functions


enGameChoice readPlayerChoice() {
	return (enGameChoice)readNumberInRange("Your Choice: [1] Stone, [2] Paper, [3] Scissor ?", 1, 3);
}

enGameChoice getComputerChoice() {
	return (enGameChoice)getRandomNumber(1, 3);
}

enWinner whoWonTheRound(stRoundInfo roundInfo) {
	if (roundInfo.playerChoice == roundInfo.computerChoice)
	{
		return enWinner::draw;
	}

	// this switch statement excludes computer Won times only
	switch (roundInfo.playerChoice)
	{
	case enGameChoice::stone:
		if (roundInfo.computerChoice == paper)
			return enWinner::computer;
	case enGameChoice::paper:
		if (roundInfo.computerChoice == scissors)
			return enWinner::computer;
	case enGameChoice::scissors:
		if (roundInfo.computerChoice == stone)
			return enWinner::computer;
	}

	//if you reach here then player is the winner
	return enWinner::player;
}

string roundWinnerName(enWinner roundWinner) {
	string roundWinnerName[3] = { "Player", "Computer", "Draw" };
	return roundWinnerName[roundWinner - 1];
}

string choiceName(enGameChoice gameChoice) {
	string roundChoiceName[3] = { "Stone", "Paper", "Scissors" };
	return roundChoiceName[gameChoice - 1];
}

void showRoundResults(stRoundInfo roundInfo) {
	cout << "---------- Round [" << roundInfo.roundNumber << "] ----------\n" << endl;
	cout << "Player Choice: " << choiceName(roundInfo.playerChoice) << endl;
	cout << "Computer Choice: " << choiceName(roundInfo.computerChoice) << endl;
	cout << "Round Winner: " << roundInfo.roundWinnerName << "\n" << endl;
	cout << "-------------------------------\n" << endl;

	setWinnerScreenColor(roundInfo.roundWinner);
}

enWinner whoWonTheGame(short playerWonTimes, short computerWonTimes) {
	if (playerWonTimes > computerWonTimes)
		return enWinner::player;
	else if (computerWonTimes > playerWonTimes)
		return enWinner::computer;
	else
		return enWinner::draw;
}

string gameWinnerName(enWinner gameWinner) {
	string gameWinnerName[3] = { "Player", "Computer", "Draw" };
	return gameWinnerName[gameWinner - 1];
}

stGameResults fillGameResults(short gameRounds, short playerWonTimes, short computerWonTimes, short drawTimes) {
	stGameResults gameResults;

	gameResults.gameRounds = gameRounds;
	gameResults.playerWonTimes = playerWonTimes;
	gameResults.computerWonTimes = computerWonTimes;
	gameResults.drawTimes = drawTimes;
	gameResults.gameWinner = whoWonTheGame(playerWonTimes, computerWonTimes);
	gameResults.gameWinnerName = gameWinnerName(gameResults.gameWinner);

	return gameResults;
}

stGameResults playGame(short howManyRounds) {
	stRoundInfo roundInfo;
	short playerWonTimes = 0, computerWonTimes = 0, drawTimes = 0;

	// this for loop to fill roundInfo structure
	for (short gameRound = 1; gameRound <= howManyRounds; gameRound++)
	{
		cout << "\nRound [" << gameRound << "] Begins\n" << endl;
		roundInfo.roundNumber = gameRound;
		roundInfo.playerChoice = readPlayerChoice();
		roundInfo.computerChoice = getComputerChoice();
		roundInfo.roundWinner = whoWonTheRound(roundInfo);
		roundInfo.roundWinnerName = roundWinnerName(roundInfo.roundWinner);

		// increase win/draw times
		if (roundInfo.roundWinner == enWinner::player)
			playerWonTimes += 1;
		else if (roundInfo.roundWinner == enWinner::computer)
			computerWonTimes += 1;
		else
			drawTimes += 1;

		// print roundInfo details
		showRoundResults(roundInfo);
	}

	// fill stGameResults structure
	return fillGameResults(howManyRounds, playerWonTimes, computerWonTimes, drawTimes);
}

void showFinalGameResults(stGameResults gameResults) {
	cout << tabs(4) << "--------------- [Game Results] --------------" << newLines(2);
	cout << tabs(4) << "Game Rounds: " << gameResults.gameRounds << endl;
	cout << tabs(4) << "Player Won Times: " << gameResults.playerWonTimes << endl;
	cout << tabs(4) << "Computer Won Times: " << gameResults.computerWonTimes << endl;
	cout << tabs(4) << "Draw Times: " << gameResults.drawTimes << endl;
	cout << tabs(4) << "The Game Winner: " << gameResults.gameWinnerName << endl;
	cout << tabs(4) << "---------------------------------------------" << newLines(2);

	setWinnerScreenColor(gameResults.gameWinner);
}

// to validate that the user character should be 'Y' , 'y' , 'N' or 'n' not other characters
char playAgain() {
	char playAgain;
	do
	{
		cout << tabs(4) << "Do You Want To Play Again ? [Y/N]" << endl;
		cout << tabs(4);
		cin >> playAgain;
	} while (playAgain != 'Y' && playAgain != 'y' && playAgain != 'N' && playAgain != 'n');
	return playAgain;
}

void startGame() {
	stGameResults gameResults;
	char replay = 'Y';

	do
	{
		resetScreen();
		gameResults = playGame(howManyRounds());
		showGameOverScreen();
		showFinalGameResults(gameResults);
		replay = playAgain();
	} while (replay == 'Y' || replay == 'y');
}

int main()
{
	//warning C4244: 'argument' : conversion from 'time_t' to 'unsigned int', possible loss of data
	// time() returns a time_t, which can be 32 or 64 bits. srand() takes an unsigned int, which is 32 bits. To be fair, you probably won't care since it's only being used as a seed for randomization.
	//srand(time(NULL));

	//This line involves an implicit cast from time_t which time returns to unsigned int which srand takes :
	srand((unsigned int)time(NULL));

	//You can make it an explicit cast instead :
	//srand(static_cast<unsigned int>(time(NULL)));

	startGame();
	return 0;
}