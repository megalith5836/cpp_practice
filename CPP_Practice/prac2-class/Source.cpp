// �N���X�̊w�K

#include <iostream>
#include <string>
using namespace std;

class Neko
{
private:
	string name;	// �L�̖��O

public:
	Neko(string s)	// �R���X�g���N�^
	{
		name = s;
	}

	void naku()		// �����𔭂���
	{
		cout << name << " : Meow..." << endl;
	}
};

int main(void)
{
	Neko MyCat("���X��");

	MyCat.naku();	// �L�������

	return 0;
}