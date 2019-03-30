#pragma once

/// <summary>
/// オセロゲームに関するクラス
/// 盤面のサイズは8x8固定（壁を含めて10x10）
/// </summary>
class Othello
{
	static const int FIELD_HEIGHT = 10;
	static const int FIELD_WIDTH = 10;

	int field[FIELD_HEIGHT][FIELD_WIDTH];	// 盤面（サイズ固定）

	int turn;			// 現在のターン
	int turnCount;		// ターン数（一巡で1カウント）
	int blackCount;		// 黒の石数
	int whiteCount;		// 白の石数
	bool gameEndFlag;	// ゲーム終了フラグ　Trueで終了

	enum Stones {		// マスの状態を表す列挙型
		wall,
		empty,
		blackStone,
		whiteStone
	};

	enum Turn {			// ターンを表す列挙型
		blackTurn,
		whiteTurn
	};

	enum Direction {	// 各方向を方角で表す列挙型
		N = 0x01,
		NE = 0x02,
		E = 0x04,
		SE = 0x08,
		S = 0x10,
		SW = 0x20,
		W = 0x40,
		NW = 0x80
	};
	
public:
	Othello(void);

	void drawField(void);				// フィールド描画関数
	bool putStone(int, int);			// 指定座標に石を配置する関数
	bool canPlace(int, int);			// マスに石を置けるかのチェック関数
	unsigned char lineCheck(int, int);	// 指定座標を中心として8方向チェックを行う関数
	void checkStone(void);				// フィールド上の石数をチェックする関数
};