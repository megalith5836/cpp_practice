// クラスの学習

#include <iostream>
#include <string>
using namespace std;

class Neko
{
private:
	string name;	// 猫の名前

public:
	Neko(string s)	// コンストラクタ
	{
		name = s;
	}

	void naku()		// 鳴き声を発する
	{
		cout << name << " : Meow..." << endl;
	}
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