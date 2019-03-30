#include <iostream>
#include <string>
#include "Othello.h"
using namespace std;

/// <summary>
/// �R���X�g���N�^
/// </summary>
Othello::Othello(void)
{
	turn = blackTurn;
	turnCount = 1;
	gameEndFlag = false;

	// �Ֆʂ̏�����
	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			field[y][x] =
				(y == 0 || y == FIELD_HEIGHT - 1) ||
				(x == 0 || x == FIELD_WIDTH - 1)
				? wall
				: empty;
		}
	}

	// �΂̏����z�u
	field[FIELD_HEIGHT / 2][FIELD_WIDTH / 2] = blackStone;
	field[FIELD_HEIGHT / 2 - 1][FIELD_WIDTH / 2 - 1] = blackStone;
	field[FIELD_HEIGHT / 2][FIELD_WIDTH / 2 - 1] = whiteStone;
	field[FIELD_HEIGHT / 2 - 1][FIELD_WIDTH / 2] = whiteStone;

	// �ΐ��`�F�b�N
	checkStone();
}

/// <summary>
/// �t�B�[���h��`�悷�邾���̒P���Ȋ֐�
/// </summary>
void Othello::drawField(void)
{
	string drawMark;

	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			switch (field[y][x])
			{
				case wall:			drawMark = "��"; break;
				case empty:			drawMark = "��"; break;
				case blackStone:	drawMark = "��"; break;
				case whiteStone:	drawMark = "��"; break;
				default:			drawMark = "�H";
			}
			cout << drawMark;
		}
		cout << endl;
	}
}

/// <summary>
/// �w�肵���}�X�ɐ΂��u���邩�ۂ����`�F�b�N����
/// </summary>
/// <param name="x">�}�X��X���W</param>
/// <param name="y">�}�X��Y���W</param>
/// <returns>�΂��u���邩�ۂ�</returns>
bool Othello::canPlace(int x, int y)
{
	// Todo
	return true;
}

/// <summary>
/// ���ݔՖʂɒu����Ă���΂̐����`�F�b�N���L�^
/// </summary>
void Othello::checkStone(void)
{
	// ��U����������
	blackCount = 0;
	whiteCount = 0;

	for (int y = 1; y < FIELD_HEIGHT - 1; y++)
	{
		for (int x = 1; x < FIELD_WIDTH - 1; x++)
		{
			if (field[y][x] == blackStone)
				blackCount++;
			else if (field[y][x] == whiteStone)
				whiteCount++;
		}
	}
}

/// <summary>
/// �w����W�ɐ΂�z�u����
/// </summary>
/// <param name="x">�}�X��X���W</param>
/// <param name="y">�}�X��Y���W</param>
/// <returns>�΂̔z�u�ɐ����������ۂ�</returns>
bool Othello::putStone(int x, int y)
{
	return true;
}