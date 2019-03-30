// クラスの学習

#include <iostream>
#include <string>
using namespace std;

// 猫を鳴かせるための簡単なクラス
class Neko
{
	string name;	// 猫の名前

public:
	Neko(string s);			// コンストラクタ

	void naku(void) const;	// 猫を鳴かせるメンバ関数
};

// 関数定義
Neko::Neko(string s) :name(s) {}
void Neko::naku(void) const { cout << name << " : Meow..." << endl; }

int main(void)
{
	string nekoName;

	cout << "猫の名前を入力" << endl;
	cin >> nekoName;

	Neko MyCat(nekoName);

	MyCat.naku();	// 猫を鳴かせる

	return 0;
}