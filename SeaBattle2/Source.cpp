//������� ���
//����� ������
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

void startGame()//����� ����
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

void printField(const char a[][size])//������ �����
{
	//system("CLS");
	cout << "  " << upLine << endl;
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

void fillClearField(char a[][size],char b[][size])
{

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			a[i][j] = ' ';
			b[i][j] = ' ';
		}
	}
	printField(a);
	printField(b);
}

void printShip(char a[][size], char begin[2], char end[2])
{
	int startRow;
	int startCol;
	int endRow;
	int endCol;

	startRow = int(begin[1]) - 48;//� ����� ������ ������
	startCol = int(begin[0]) - 65;//� ����� ������� ������
	endRow = int(end[1]) - 48;//� ����� ������ �����
	endCol = int(end[0]) - 65;//� ����� ������� �����

	if (startRow == endRow) //���� ������ ����� � ������ � ����� ���������� - �� �����������
		for (size_t j = startCol; j <= endCol; j++)
		{
			a[startRow][j] = '*';
		}
	else					//�� ���������
		for (size_t i = startRow; i <= endRow; i++)
		{
			a[i][startCol] = '*';
		}
}

void fillFieldHands(char a[][size], char b[][size])
{
	for (size_t i = 4; i >= 1; i--)//����� ������� �� 4 �� 1
	{
		for (size_t j = 1; j <= 5 - i; j++)//���-�� �������� �� 1 �� 4
		{
			printField(a);
			char begin[3], end[3];
			cout << "ship length: " << i << endl;
			cout << "\tbegin: ";//������ �������
			cin >> begin;
			if (i > 1)
			{
				cout << "\tend: ";//����� �������
				cin >> end;
			}
			else
			{
				end[0] = begin[0];
				end[1] = begin[1];
			}
			printShip(a, begin, end);//���������� �������
		}
	}
}

#define leftRight 1
#define upDown 0
void fillFieldRand(char a[][size])
{
	char begin[2];
	char end[2];
	int x;

	int startRow;
	int startCol;
	int endRow;
	int endCol;

	//�� �����������
	x = rand() % 10;
	begin[1] = int(upLine[x]);
	cout << begin[1]<<" - begin up line" << endl;
	end[1] = int(upLine[x+3]);
	cout << end[1]<<" - end up line" << endl;

	//�� ���������
	x = rand() % 10;
	begin[0] = int(leftLine[x]);
	cout << begin[0]<<" - begin left line" << endl;
	end[0] = int(leftLine[x+2]);
	cout << end[0]<<" - end left line" << endl;

	startRow = begin[1];
	startCol = begin[0];
	endRow = end[1];
	endCol = end[0];
	
	int direction;
	direction = rand() % 1;
	if (direction == leftRight) //��� ������� 1. ������� �� ������ ���� ������ ���������� �� ����� ������� 2. ������� �� ������ ���������� ��� ������������
	{
		if (startRow == endRow) //���� ������ ����� � ������ � ����� ���������� - �� �����������
			for (size_t j = startCol; j <= endCol; j++)
			{
				a[startRow][j] = '*';
			}
	}

	if (direction == upDown)//��� ������� 1. ������� �� ������ ���� ������ ���������� �� ������ ������� 2. ������� �� ������ ���������� ��� ������������
	{
		if (startCol == endCol)					//�� ���������
			for (size_t i = startRow; i <= endRow; i++)
			{
				a[i][startCol] = '*';
			}
	}
}

void randomFill(char a[10][10], char b[10][10])//��������� ����
{
	for (size_t i = 4; i >= 1; i--)//����� ������� �� 4 �� 1
	{
		for (size_t j = 1; j <= 5 - i; j++)//���-�� �������� �� 1 �� 4
		{
			if (fillFieldPlayerOne == 1)//���� ������� ������ ������� ����
			{

			}
			
		}
	}
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

	srand(time(NULL));
	fillClearField(fieldSecondPlayerOne, fieldSecondPlayerTwo);
	fillFieldRand(fieldSecondPlayerOne);
	//startGame();
	
	//fillFieldHands(fieldFirstPlayerOne, fieldSecondPlayerOne);
	//game();

	return 0;
}