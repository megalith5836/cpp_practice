// クラスの学習

#include <iostream>
#include <string>
using namespace std;

class Neko
{
private:
	string name;	// 猫の名前

public:
	// コンストラクタ
	Neko(string s) : name(s) {}

	// 鳴き声を発するメンバ関数
	void naku() const { cout << name << " : Meow..." << endl; }
};

int main(void)
{
	string nekoName;

	cout << "猫の名前を入力" << endl;
	cin >> nekoName;

	Neko MyCat(nekoName);

	MyCat.naku();	// 猫を鳴かせる

	return 0;
}