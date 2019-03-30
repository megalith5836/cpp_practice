#include <iostream>
#include <string>
#include "Othello.h"
using namespace std;

/// <summary>
/// コンストラクタ
/// </summary>
Othello::Othello(void)
{
	turn = blackTurn;
	turnCount = 1;
	gameEndFlag = false;

	// 盤面の初期化
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

	// 石の初期配置
	field[FIELD_HEIGHT / 2][FIELD_WIDTH / 2] = blackStone;
	field[FIELD_HEIGHT / 2 - 1][FIELD_WIDTH / 2 - 1] = blackStone;
	field[FIELD_HEIGHT / 2][FIELD_WIDTH / 2 - 1] = whiteStone;
	field[FIELD_HEIGHT / 2 - 1][FIELD_WIDTH / 2] = whiteStone;

	// 石数チェック
	checkStone();
}

/// <summary>
/// フィールドを描画するだけの単純な関数
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
				case wall:			drawMark = "■"; break;
				case empty:			drawMark = "□"; break;
				case blackStone:	drawMark = "●"; break;
				case whiteStone:	drawMark = "○"; break;
				default:			drawMark = "？";
			}
			cout << drawMark;
		}
		cout << endl;
	}
}

/// <summary>
/// 指定したマスに石が置けるか否かをチェックする
/// </summary>
/// <param name="x">マスのX座標</param>
/// <param name="y">マスのY座標</param>
/// <returns>石が置けるか否か</returns>
bool Othello::canPlace(int x, int y)
{
	// Todo
	return true;
}

/// <summary>
/// 現在盤面に置かれている石の数をチェックし記録
/// </summary>
void Othello::checkStone(void)
{
	// 一旦初期化する
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
/// 指定座標に石を配置する
/// </summary>
/// <param name="x">マスのX座標</param>
/// <param name="y">マスのY座標</param>
/// <returns>石の配置に成功したか否か</returns>
bool Othello::putStone(int x, int y)
{
	return true;
}