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
	// Todo
	return true;
}

/// <summary>
/// 指定座標を中心として、裏返せるラインが有るかどうかチェックする
/// </summary>
/// <param name="x">X座標</param>
/// <param name="y">Y座標</param>
/// <returns>各方向（方角）に対応した8ビットデータ</returns>
unsigned char Othello::lineCheck(int x, int y)
{
	// 目標となる石を設定
	auto target = turn == blackTurn ? blackStone : whiteStone;
	auto enemy = turn == blackTurn ? whiteStone : blackStone;

	unsigned char checkResult = 0x00;	// 戻り値
	bool enemyStoneFlag = false;		// 間に相手の石が存在するか否か

	// 指定座標がそもそも空白であればライン無しとして終了
	if (field[y][x] == wall || field[y][x] == empty) 
		return 0x00;
	
	// 8方向チェック
	// それぞれ現座標より1つ向こうから処理していく
	// N
	if (y >= 3)
	{
		for (int n = y - 1; n >= 0; n--)
		{
			// 空白に当たったら中断
			if (field[n][x] == wall || field[n][x] == empty) break;

			// 敵石判定
			if (field[n][x] == enemy)
				enemyStoneFlag = true;

			// 挟む形で石が存在するか判定
			if (field[n][x] == target && enemyStoneFlag)
			{
				checkResult |= N;
				enemyStoneFlag = false;		// フラグクリア
				break;
			}
		}
	}

	// E
	if (x <= FIELD_WIDTH - 4)
	{
		for (int n = x + 1; n <= FIELD_WIDTH - 1; n++)
		{
			// 空白か壁に当たったら中断
			if (field[y][n] == wall || field[y][n] == empty) break;

			// 敵石判定
			if (field[y][n] == enemy)
				enemyStoneFlag = true;

			// 挟む形で石が存在するか判定
			if (field[y][n] == target && enemyStoneFlag)
			{
				checkResult |= E;
				enemyStoneFlag = false;		// フラグクリア
				break;
			}
		}
	}

	// S
	if (y <= FIELD_HEIGHT - 4)
	{
		for (int n = y + 1; n <= FIELD_HEIGHT - 1; n++)
		{
			// 空白に当たったら中断
			if (field[n][x] == wall || field[n][x] == empty) break;

			// 敵石判定
			if (field[n][x] == enemy)
				enemyStoneFlag = true;

			// 挟む形で石が存在するか判定
			if (field[n][x] == target && enemyStoneFlag)
			{
				checkResult |= S;
				enemyStoneFlag = false;		// フラグクリア
				break;
			}
		}
	}

	// W
	if (x >= 3)
	{
		for (int n = x - 1; n >= 0; n--)
		{
			// 空白か壁に当たったら中断
			if (field[y][n] == wall || field[y][n] == empty) break;

			// 敵石判定
			if (field[y][n] == enemy)
				enemyStoneFlag = true;

			// 挟む形で石が存在するか判定
			if (field[y][n] == target && enemyStoneFlag)
			{
				checkResult |= W;
				enemyStoneFlag = false;		// フラグクリア
				break;
			}
		}
	}

	return checkResult;
}