// クラスの学習

#include <iostream>
#include <string>
using namespace std;

// 猫クラス
class Neko
{
	string name;	// 猫の名前

public:
	Neko(string);			// コンストラクタ

	void naku(void) const;	// 猫を鳴かせる
};

// オオカミクラス
class Wolf
{
	string name;	// オオカミの名前

public:
	Wolf(string);			// コンストラクタ

	void naku(void) const;	// オオカミを吠えさせる
};

// メンバ関数の定義
Neko::Neko(string s) :name(s) {}
void Neko::naku(void) const { cout << name << " : Meow..." << endl; }

Wolf::Wolf(string s) : name(s) { };
void Wolf::naku(void) const { cout << name << " : Howl..." << endl; }

int main(void)
{
	string nekoName, wolfName;

	cout << "猫の名前を入力 : ";
	cin >> nekoName;

	cout << "オオカミの名前を入力 : ";
	cin >> wolfName;

	Neko MyCat(nekoName);
	Wolf MyWolf(wolfName);

	MyCat.naku();	// 猫を鳴かせる
	MyWolf.naku();	// オオカミを吠えさせる

	return 0;
}