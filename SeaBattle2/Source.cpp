//морской бой
//часть вторая
//

#include <iostream>
using namespace std;

#define size 10

int playerOne = 0;
int playerTwo = 0;
int fillFieldPlayerOne = 0;
int fillFieldPlayerTwo = 0;
const char* upLine = "ABCDEFGHIJ";
const char* leftLine = "0123456789";
char fieldFirstPlayerOne[size][size]; 
char fieldSecondPlayerOne[size][size];
char fieldFirstPlayerTwo[size][size];
char fieldSecondPlayerTwo[size][size];

void startGame()//старт игры
{
	cout << "\tHello!" << endl;
	cout << "1 - computer; 0 - human" << endl;
	cout << "You can choose player one: " << endl;
	cin >> playerOne;
	cout << "You can choose player two: " << endl;
	cin >> playerTwo;

	cout << "1 - random; 0 - hands" << endl;
	cout << "You can choose fill field player one: " << endl;
	cin >> fillFieldPlayerOne;
	cout << "You can choose fill field player two: " << endl;
	cin >> fillFieldPlayerTwo;
}

void printField(const char a[][size])
{
	system("CLS");
	cout << " " << upLine << endl;
	for (size_t i = 0; i < size; i++)
	{
		cout << i << " ";
		for (size_t j = 0; j < size; j++)
		{
			cout << a[i][j];
		}cout << endl;
	}
	cout << endl;
}

void rulesFill(char a[][size], char begin[2], char end[2])
{
	int startRow;
	int startCol;
	int endRow;
	int endCol;

	startRow = int(begin[1]) - 48;//в какой строке начало
	startCol = int(begin[0]) - 65;//в каком столбце начало
	endRow = int(end[1]) - 48;//в какой строке конец
	endCol = int(end[0]) - 65;//в каком столбце конец

	if(startRow == endRow) //если номера строк у начала и конца одинаковые - по горизонтали
		for (size_t j = startCol; j <= endCol; j++)
		{
			a[startRow][j] = '*';
		}
	else					//по вертикали
		for (size_t i = startRow; i <= endRow; i++)
		{
			a[i][startCol] = '*';
		}
}

void fillFieldHands(char a[][size], char b[][size])
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			a[i][j] = ' ';
			b[i][j] = ' ';
		}
	}
}

void fillFieldRand(char a[][size])
{

}


void game()
{
	cout << playerOne << " - player One" << endl;
	cout << fillFieldPlayerOne << " - fill field player One" << endl;
	cout << playerTwo << " - player Two" << endl;
	cout << fillFieldPlayerTwo << " - fill field player Two" << endl;
}

int main()
{
	startGame();
	//fillFieldHands(fieldFirstPlayerOne, fieldSecondPlayerOne);
	//game();

	return 0;
}