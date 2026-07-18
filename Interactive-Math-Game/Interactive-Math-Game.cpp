#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
   Project Name : Math Game ...

   A simple interactive Math Game that tests users with random questions.
   It allows selecting the number of questions, difficulty level, and operation type,
   then automatically generates questions, checks answers, and displays the final results.

*/

enum enQuestionsLevel
{
	EasyLevel = 1, MedLevel = 2, HardLevel = 3, Mix = 4
};

enum enOperationType
{
	Add = 1, Sub = 2, Mult = 3, Div = 4, MixOp = 5
};

struct stQuestion
{
	int Number1 = 0;
	int Number2 = 0;
	enOperationType OperationType;
	enQuestionsLevel QuestionLevel;
	int CorrectAnswer = 0;
	int PlayerAnswer = 0;
	bool AnswerResult = false;
};

struct stQuizz
{
	stQuestion QuestionList[100];
	short NumberOfQuestion;
	enQuestionsLevel QuestionsLevel;
	enOperationType OpType;
	short NumberOfWrongAnswers = 0;
	short NumberOfRightAnswers = 0;
	bool isPass = false;
};

string GetOpTypeSymbol(enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return "+";
	case enOperationType::Sub:
		return "-";
	case enOperationType::Mult:
		return "*";
	case enOperationType::Div:
		return "/";
	default:
		return "Mix";
	}
}

string GetQuestionLevelText(enQuestionsLevel QuestionLevel)
{
	string arrQuestionLevelText[4] = { "Easy", "Med" , "Hard" , "Mix" };
	return arrQuestionLevelText[QuestionLevel - 1];
}

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

int SimpleCalculator(int Number1, int Number2, enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return Number1 + Number2;
	case enOperationType::Sub:
		return Number1 - Number2;
	case enOperationType::Mult:
		return Number1 * Number2;
	case enOperationType::Div:
		return Number1 / Number2;
	default:
		return Number1 + Number2;
	}
}

short ReadHowManyQuestion()
{
	short NumberOfQuestions;
	do
	{
		cout << "How Many Questions do you want to answer? \n";
		cin >> NumberOfQuestions;
	} while (NumberOfQuestions < 1 || NumberOfQuestions > 10);

	return NumberOfQuestions;
}

enOperationType GetRandomOperationType()
{
	int Op = RandomNumber(1, 4);
	return (enOperationType)Op;
}

enQuestionsLevel ReadQuestionsLevel()
{
	short QuestionsLevel = 0;
	do
	{
		cout << "Enter Question Level [1] Easy , [2] Med , [3] Hard , [4] Mix ?\n";
		cin >> QuestionsLevel;
	} while (QuestionsLevel < 1 || QuestionsLevel > 4);

	return (enQuestionsLevel)QuestionsLevel;
}

enOperationType ReadOpType()
{
	short OpType;
	do
	{
		cout << "Enter Operation Type [1] Add , [2] Sub , [3] Mult , [4] Div , [5] Mix  ? \n";
		cin >> OpType;
	} while (OpType < 1 || OpType > 5);

	return (enOperationType)OpType;
}

stQuestion GenerateQuestions(enQuestionsLevel QuestionsLevel, enOperationType OpType)
{
	stQuestion Question;

	if (QuestionsLevel == enQuestionsLevel::Mix)
	{
		QuestionsLevel = (enQuestionsLevel)RandomNumber(1, 3);
	}

	if (OpType == enOperationType::MixOp)
	{
		OpType = GetRandomOperationType();
	}

	Question.OperationType = OpType;

	switch (QuestionsLevel)
	{
	case enQuestionsLevel::EasyLevel:
		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);
		break;

	case enQuestionsLevel::MedLevel:
		Question.Number1 = RandomNumber(10, 50);
		Question.Number2 = RandomNumber(10, 50);
		break;

	case enQuestionsLevel::HardLevel:
		Question.Number1 = RandomNumber(50, 100);
		Question.Number2 = RandomNumber(50, 100);
		break;
	}

	Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
	Question.QuestionLevel = QuestionsLevel;

	return Question;
}

void GenerateQuizzQuestions(stQuizz& Quizz)
{
	for (short Question = 0; Question < Quizz.NumberOfQuestion; Question++)
	{
		Quizz.QuestionList[Question] = GenerateQuestions(Quizz.QuestionsLevel, Quizz.OpType);
	}
}

int ReadQuestionAnswe()
{
	int Answer = 0;
	cin >> Answer;
	return Answer;
}

string GetFinalResultText(bool Pass)
{
	if (Pass)
		return "PASS :-)";
	else
		return "FAIL :-(";
}

void PrintQuizzResults(stQuizz Quizz)
{
	cout << "\n";
	cout << "___________________________\n\n";
	cout << "Final Result is " << GetFinalResultText(Quizz.isPass);
	cout << "\n_______________________________________\n\n";

	cout << "Number Of Questions:" << Quizz.NumberOfQuestion << endl;
	cout << "Questions Level    :" << GetQuestionLevelText(Quizz.QuestionsLevel) << endl;
	cout << "OpType             :" << GetOpTypeSymbol(Quizz.OpType) << endl;
	cout << "Number Of Right Answers:" << Quizz.NumberOfRightAnswers << endl;
	cout << "Number Of Wrong Answers:" << Quizz.NumberOfWrongAnswers << endl;
	cout << "_____________________________________\n";

}

void PrintTheQuestion(stQuizz& Quizz, short QuestionNumber)
{
	cout << "\n";
	cout << "Question [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestion << "] \n\n";
	cout << Quizz.QuestionList[QuestionNumber].Number1 << endl;
	cout << Quizz.QuestionList[QuestionNumber].Number2 << " ";
	cout << GetOpTypeSymbol(Quizz.QuestionList[QuestionNumber].OperationType);
	cout << "\n_____________" << endl;
}

void CorrectTheQuestionAnswer(stQuizz& Quizz, short QuestionNumber)
{
	if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer)
	{
		Quizz.QuestionList[QuestionNumber].AnswerResult = false;
		Quizz.NumberOfWrongAnswers++;

		cout << "Wrong Answer :-( \n";
		cout << "The right answer is : ";
		cout << Quizz.QuestionList[QuestionNumber].CorrectAnswer;
		cout << "\n";
	}

	else
	{
		Quizz.QuestionList[QuestionNumber].AnswerResult = true;
		Quizz.NumberOfRightAnswers++;

		cout << "Right Answer :-) \n";
	}
	cout << endl;
}

void AskAndCorrectQuestionListAnswers(stQuizz& Quizz)
{
	for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestion; QuestionNumber++)
	{
		PrintTheQuestion(Quizz, QuestionNumber);

		Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswe();

		CorrectTheQuestionAnswer(Quizz, QuestionNumber);
	}

	Quizz.isPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers);
}

void PlayMathGame()
{
	stQuizz Quizz;
	Quizz.NumberOfQuestion = ReadHowManyQuestion();
	Quizz.QuestionsLevel = ReadQuestionsLevel();
	Quizz.OpType = ReadOpType();


	GenerateQuizzQuestions(Quizz);
	AskAndCorrectQuestionListAnswers(Quizz);
	PrintQuizzResults(Quizz);



}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char PlayAgain = 'Y';
	do
	{
		ResetScreen();
		PlayMathGame();

		cout << "\nDo you want to play again? [Y/N] \n";
		cin >> PlayAgain;
	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}