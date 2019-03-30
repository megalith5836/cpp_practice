// クラスの練習2

#include <iostream>
#include <string>
using namespace std;

// ロケットクラス
class Rocket
{
	int fuel;
	int velocity;

public:
	Rocket(int);	// コンストラクタ（燃料）
	void Acc(void);	// ロケットの加速
};

// メンバ関数定義
Rocket::Rocket(int n) :fuel(n), velocity(0) {}
void Rocket::Acc(void) {
	if (fuel >= 2)
	{
		fuel -= 2;
		velocity += 2;
		cout << "残り燃料 : " << fuel << "\n現在速度 : " << velocity << endl;
	}
	else 
	{
		cout << "燃料切れです" << endl;
	}
}

int main(void)
{
	int fuel;
	
	cout << "ロケットを作成します。燃料? : ";
	cin >> fuel;

	Rocket Leno(fuel);

	for (int i = 0; i < 3; i++)
		Leno.Acc();

}