// 複数のコンストラクタを持つクラスの作成練習

#include <iostream>
using namespace std;

#pragma region クラス定義

/// <summary>
/// タバコ箱クラス　現在箱の中に入っているタバコに対して処理を行う
/// </summary>
class Tabacco
{
	int value;

public:
	Tabacco(void);
	Tabacco(int);

	void Refill(int);
	void Use(void);
};

#pragma endregion

#pragma region メンバ関数定義

/// <summary>
/// 引数なしコンストラクタ　新品の箱を生成
/// </summary>
Tabacco::Tabacco(void) :value(20) {}

/// <summary>
/// コンストラクタ　指定本数を入れた箱を生成
/// </summary>
/// <param name="n">タバコの本数</param>
Tabacco::Tabacco(int n) : value(n) {}

/// <summary>
/// 指定本数を補充する
/// </summary>
/// <param name="n">補充本数</param>
void Tabacco::Refill(int n)
{
	if (value + n <= 20)	// 上限は20
	{
		value += n;
		cout << n << "本補充して" << value << "本になりました" << endl;
	}
	else
	{
		cout << "上限を超えての補充は出来ません" << endl;
	}
}

/// <summary>
/// タバコを1本消費する
/// </summary>
void Tabacco::Use(void)
{
	if (value > 0)
	{
		value--;
		cout << "あなたは一服しました　残り本数 : " << value << "本" << endl;
	}
	else
	{
		cout << "もう一本も残っていません。" << endl;
	}
}

#pragma endregion


int main(void)
{
	int value;

	cout << "タバコ箱を生成します。本数を指定してください（0を指定すると新品生成）" << endl;
	cout << "本数 >> ";
	cin >> value;

	// 無効な数値入力で終了
	if (value < 0 || value>20)
	{
		cout << "無効な数値です" << endl;
		return -1;
	}

	// タバコ箱の生成
	// Tabacco box;
	Tabacco box(value != 0 ? value : NULL);

	// 5回使用する
	for (int i = 0; i < 5; i++)
		box.Use();

	// 2回補充する（5本固定）
	for (int i = 0; i < 2; i++)
		box.Refill(5);

	return 0;
}