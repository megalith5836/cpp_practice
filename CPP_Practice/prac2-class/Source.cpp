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
	Neko MyCat("茶々丸");

	MyCat.naku();	// 猫を鳴かせる

	return 0;
}