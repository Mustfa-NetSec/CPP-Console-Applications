#include <iostream>
#include <string>
using namespace std;

/*Project Name : Stone-Paper-Scissor Game.
A Small Game Program For Stone-Paper-Scissor.*/

enum enGameChoice
{
	Stone = 1, Paper = 2, Scissor = 3
};

enum enWinner
{
	Player1 = 1, Computer = 2, Draw = 3
};

struct stRoundInfo
{
	short RoundNumber = 0;
	enGameChoice Player1Choice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName;
};

struct stGameResults
{
	short GameRounds = 0;
	short Player1WinTimes = 0;
	short Computer2WinTimes = 0;
	short DrawTimes = 0;
	enWinner GameWinner;
	string WinnerName = "";
};



int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

enGameChoice GetComputerChoice()
{
	return (enGameChoice)RandomNumber(1, 3);
}

string Tabs(short NumberOfTabs)
{
	string t = "";
	for (int i = 1; i <= NumberOfTabs; i++) 
	{
		t = t + "\t";
	}
	return t;
}

string WinnerName(enWinner Winner)
{
	string arrWinnerName[3] = { "Player1" , "Computer" , "No Winner (Draw)" };
	return arrWinnerName[Winner - 1];
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
	{
		return enWinner::Draw;
	}

	switch (RoundInfo.Player1Choice)
	{
	case enGameChoice::Stone:
		if (RoundInfo.ComputerChoice == enGameChoice::Paper)
		{
			return enWinner::Computer;
		}
		break;

	case enGameChoice::Paper:
		if (RoundInfo.ComputerChoice == enGameChoice::Scissor)
		{
			return enWinner::Computer;
		}
		break;

	case enGameChoice::Scissor:
		if (RoundInfo.ComputerChoice == enGameChoice::Stone)
		{
			return enWinner::Computer;
		}
		break;
	}
	return enWinner::Player1; 
}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
	if (Player1WinTimes > ComputerWinTimes)
	{
		return enWinner::Player1;
	}
	else if (ComputerWinTimes > Player1WinTimes)
	{
		return enWinner::Computer;
	}
	else
	{
		return enWinner::Draw;
	}
}

stGameResults FillGameResults(int GameRounds, short Player1WinTimes, short ComputerWinTimes, short DrawTimes)
{
	stGameResults GameResults;

	GameResults.GameRounds = GameRounds;
	GameResults.Player1WinTimes = Player1WinTimes;
	GameResults.Computer2WinTimes = ComputerWinTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.GameWinner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);
	GameResults.WinnerName = WinnerName(GameResults.GameWinner);

	return GameResults;
}

string ChoiceName(enGameChoice Choice)
{
	string arrGameChoice[3] = { "Stone" , "Paper" , "Scissor" };
	return arrGameChoice[Choice - 1];
}

enGameChoice ReadPlayer1Choice()
{
	short Choice = 1;

	do
	{
		cout << "\nYour Choice : [1]:Stone , [2]:Paper , [3]:Scissor : ";
		cin >> Choice;

	} while (Choice < 1 || Choice > 3);

	return(enGameChoice)Choice;
}

void PrintRoundResults(stRoundInfo RounInfo)
{
	cout << "\n_____________Round [" << RounInfo.RoundNumber << "] ______________\n\n";
	cout << "Player1 Choice : " << ChoiceName(RounInfo.Player1Choice) << endl;
	cout << "Computer Choice : " << ChoiceName(RounInfo.ComputerChoice) << endl;
	cout << "Round Winner   : [" << RounInfo.WinnerName << "]\n";
	cout << "___________________________________________\n" << endl;
}

void SetWinnerScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player1:
		system("color 2F"); 
		break;

	case enWinner::Computer:
		system("color 4F"); 
		cout << "\a";
		break;

	default:
		system("color 6F");   
		break;
	}
}

stGameResults PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;
	short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

	for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		cout << "\nRound [" << GameRound << "] begins:\n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.Player1Choice = ReadPlayer1Choice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		if (RoundInfo.Winner == enWinner::Player1)
			Player1WinTimes++;
		else if (RoundInfo.Winner == enWinner::Computer)
			ComputerWinTimes++;
		else
			DrawTimes++;

		PrintRoundResults(RoundInfo);
	}
	return FillGameResults(HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes);
}

short ReadHowManyRounds()
{
	short GameRounds = 1;

	do
	{
		cout << "How many Rounds 1 to 10\n";
		cin >> GameRounds;

	} while (GameRounds < 1 || GameRounds > 10);

	return GameRounds;
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void showFinalGameResults(stGameResults GameResults)
{
	cout << Tabs(2) << "_________________[ Game Results ]________________\n\n";
	cout << Tabs(2) << "Game Round         :" << GameResults.GameRounds << endl;
	cout << Tabs(2) << "Player1 Won Times  :" << GameResults.Player1WinTimes << endl;
	cout << Tabs(2) << "Computer Won Times :" << GameResults.Computer2WinTimes << endl;
	cout << Tabs(2) << "Draw Times         :" << GameResults.DrawTimes << endl;
	cout << Tabs(2) << "Final Winner       :" << GameResults.WinnerName << endl;
	cout << Tabs(2) << "___________________________________________________________\n";

	SetWinnerScreenColor(GameResults.GameWinner);
}

void ShowGameOverScreen()
{
	cout << Tabs(2) << "______________________________________________\n\n";
	cout << Tabs(2) << "            ++++ Game Over ++++\n";
	cout << Tabs(2) << "______________________________________________\n\n";
}

void StartGame()
{
	char PlayAgain = 'Y';

	do
	{
		ResetScreen();
		stGameResults GameResults = PlayGame(ReadHowManyRounds());
		ShowGameOverScreen();
		showFinalGameResults(GameResults);

		cout << endl << Tabs(3) << "Do You Want to play again Y/N : ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}