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


	bool canPlace(int, int);	// マスに石を置けるかのチェック関数
	void checkStone(void);		// フィールド上の石数をチェックする関数
	
public:
	Othello(void);

	void drawField(void);		// フィールド描画関数
	bool putStone(int, int);	// 指定座標に石を配置する関数

};