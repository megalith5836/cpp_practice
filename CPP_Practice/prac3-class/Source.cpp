// �N���X�̗��K2

#include <iostream>
#include <string>
using namespace std;

// ���P�b�g�N���X
class Rocket
{
	int fuel;
	int velocity;

public:
	Rocket(int);	// �R���X�g���N�^�i�R���j
	void Acc(void);	// ���P�b�g�̉���
};

// �����o�֐���`
Rocket::Rocket(int n) :fuel(n), velocity(0) {}
void Rocket::Acc(void) {
	if (fuel >= 2)
	{
		fuel -= 2;
		velocity += 2;
		cout << "�c��R�� : " << fuel << "\n���ݑ��x : " << velocity << endl;
	}
	else 
	{
		cout << "�R���؂�ł�" << endl;
	}
}

int main(void)
{
	int fuel;
	
	cout << "���P�b�g���쐬���܂��B�R��? : ";
	cin >> fuel;

	Rocket Leno(fuel);

	for (int i = 0; i < 3; i++)
		Leno.Acc();

}