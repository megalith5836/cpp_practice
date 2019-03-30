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
	// Todo
	return true;
}

/// <summary>
/// �w����W�𒆐S�Ƃ��āA���Ԃ��郉�C�����L�邩�ǂ����`�F�b�N����
/// </summary>
/// <param name="x">X���W</param>
/// <param name="y">Y���W</param>
/// <returns>�e�����i���p�j�ɑΉ�����8�r�b�g�f�[�^</returns>
unsigned char Othello::lineCheck(int x, int y)
{
	// �ڕW�ƂȂ�΂�ݒ�
	auto target = turn == blackTurn ? blackStone : whiteStone;
	auto enemy = turn == blackTurn ? whiteStone : blackStone;

	unsigned char checkResult = 0x00;	// �߂�l
	bool enemyStoneFlag = false;		// �Ԃɑ���̐΂����݂��邩�ۂ�

	// �w����W�����������󔒂ł���΃��C�������Ƃ��ďI��
	if (field[y][x] == wall || field[y][x] == empty) 
		return 0x00;
	
	// 8�����`�F�b�N
	// ���ꂼ�ꌻ���W���1���������珈�����Ă���
	// N
	if (y >= 3)
	{
		for (int n = y - 1; n >= 0; n--)
		{
			// �󔒂ɓ��������璆�f
			if (field[n][x] == wall || field[n][x] == empty) break;

			// �G�Δ���
			if (field[n][x] == enemy)
				enemyStoneFlag = true;

			// ���ތ`�Ő΂����݂��邩����
			if (field[n][x] == target && enemyStoneFlag)
			{
				checkResult |= N;
				enemyStoneFlag = false;		// �t���O�N���A
				break;
			}
		}
	}

	// E
	if (x <= FIELD_WIDTH - 4)
	{
		for (int n = x + 1; n <= FIELD_WIDTH - 1; n++)
		{
			// �󔒂��ǂɓ��������璆�f
			if (field[y][n] == wall || field[y][n] == empty) break;

			// �G�Δ���
			if (field[y][n] == enemy)
				enemyStoneFlag = true;

			// ���ތ`�Ő΂����݂��邩����
			if (field[y][n] == target && enemyStoneFlag)
			{
				checkResult |= E;
				enemyStoneFlag = false;		// �t���O�N���A
				break;
			}
		}
	}

	// S
	if (y <= FIELD_HEIGHT - 4)
	{
		for (int n = y + 1; n <= FIELD_HEIGHT - 1; n++)
		{
			// �󔒂ɓ��������璆�f
			if (field[n][x] == wall || field[n][x] == empty) break;

			// �G�Δ���
			if (field[n][x] == enemy)
				enemyStoneFlag = true;

			// ���ތ`�Ő΂����݂��邩����
			if (field[n][x] == target && enemyStoneFlag)
			{
				checkResult |= S;
				enemyStoneFlag = false;		// �t���O�N���A
				break;
			}
		}
	}

	// W
	if (x >= 3)
	{
		for (int n = x - 1; n >= 0; n--)
		{
			// �󔒂��ǂɓ��������璆�f
			if (field[y][n] == wall || field[y][n] == empty) break;

			// �G�Δ���
			if (field[y][n] == enemy)
				enemyStoneFlag = true;

			// ���ތ`�Ő΂����݂��邩����
			if (field[y][n] == target && enemyStoneFlag)
			{
				checkResult |= W;
				enemyStoneFlag = false;		// �t���O�N���A
				break;
			}
		}
	}

	return checkResult;
}