// �N���X�̊w�K

#include <iostream>
#include <string>
using namespace std;

class Neko
{
private:
	string name;	// �L�̖��O

public:
	// �R���X�g���N�^
	Neko(string s) : name(s) {}

	// �����𔭂��郁���o�֐�
	void naku() const { cout << name << " : Meow..." << endl; }
};

int main(void)
{
	string nekoName;

	cout << "�L�̖��O�����" << endl;
	cin >> nekoName;

	Neko MyCat(nekoName);

	MyCat.naku();	// �L�������

	return 0;
}