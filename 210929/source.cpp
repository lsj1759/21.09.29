#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void Input();
void Process();
void Draw();
void MovePlayer(int XDirection, int YDirection);

bool Goal();

void ChangeColor(int Color);

// ������ �ʱ�ȭ �Ѵ�.
int Map[10][10] =
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,9,0,0,0,1},
	{1,0,1,0,0,0,0,0,0,1},
	{1,0,1,0,0,1,0,0,0,1},
	{1,0,1,0,0,1,0,0,0,1},
	{1,0,0,0,0,1,0,0,0,1},
	{1,0,1,0,0,1,0,1,0,1},
	{1,0,1,0,0,0,0,1,0,1},
	{1,0,0,0,0,0,0,1,9,1},
	{1,1,1,1,1,1,1,1,1,1}
};

int PlayerX = 1;
int PlayerY = 1;

bool bIsRunning = true;
int  Key;


int main()
{
	while (bIsRunning)
	{
		Input();
		Process();
		Draw();
	}

	return 0;
}

void Input()
{
	Key = _getch();
	if (Key == 0x00 || Key == 0Xe0)
	{
		// Ȯ��Ű�� ��� Ű�� �ϳ��� �Է� �޴´�.
		Key = _getch();
	}
}

void Process()
{
	switch (Key)
	{
		//up
		case 'W':
		case 'w':
		{
			//PlayerY--;
			MovePlayer(0, -1);
			break;
		}
		//down
		case 'S':
		case 's':
		{
			//PlayerY++;
			MovePlayer(0, 1);
			break;
		}
		//left
		case 'A':
		case 'a':
		{
			//PlayerX--;
			MovePlayer(-1, 0);
			break;
	}
		//right
		case 'D':
		case 'd':
		{
			//PlayerX++;
			MovePlayer(1, 0);
			break;
		}
		//quit
		case 'Q':
		case 'q':
		{
			bIsRunning = false;
			break;
		}

    }
}

void Draw()
{
	//ȭ���� �����.
	system("cls");

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (PlayerX == j && PlayerY == i)
			{
				ChangeColor(171);
				cout << "P";
				ChangeColor(7);
				cout << " ";
			}
			else if (Map[i][j] == 0)
			{
				cout << " " << " ";
			}
			else if (Map[i][j] == 9)
			{
				ChangeColor(14);
				cout << "G";
				ChangeColor(7);
				cout << " ";
			}
			else if (Map[i][j] == 1)
			{
				cout << "X" << " ";
			}
		}

		cout << endl;
	}

}

void MovePlayer(int XDirection, int YDirection)
{
	//���� ������ ���
	int NewPlayerX = PlayerX + XDirection;
	int NewPlayerY = PlayerY + YDirection;

	//�̸� ����
	if (Map[NewPlayerY][NewPlayerX] == 0)
	{
		//�̵�
		PlayerX = NewPlayerX;
		PlayerY = NewPlayerY;
	}
	
	
	else if (Map[NewPlayerY][NewPlayerX] == 9)
	{
		bIsRunning = false;
	}
}

bool Goal()
{
	return Map[PlayerY][PlayerX] == 9 ? true false;

	//if (Map[PlayerY][PlayerX] == 9)
	//{
	//	return true;
	//}

	//return false;
}

void ChangeColor(int Color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

