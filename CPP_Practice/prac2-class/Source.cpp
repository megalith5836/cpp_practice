// �N���X�̊w�K

#include <iostream>
#include <string>
using namespace std;

// �L������邽�߂̊ȒP�ȃN���X
class Neko
{
	string name;	// �L�̖��O

public:
	Neko(string s);			// �R���X�g���N�^

	void naku(void) const;	// �L������郁���o�֐�
};

// �֐���`
Neko::Neko(string s) :name(s) {}
void Neko::naku(void) const { cout << name << " : Meow..." << endl; }

int main(void)
{
	string nekoName;

	cout << "�L�̖��O�����" << endl;
	cin >> nekoName;

	Neko MyCat(nekoName);

	MyCat.naku();	// �L�������

	return 0;
}