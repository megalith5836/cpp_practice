// �N���X�̊w�K

#include <iostream>
#include <string>
using namespace std;

// �L�N���X
class Neko
{
	string name;	// �L�̖��O

public:
	Neko(string);			// �R���X�g���N�^

	void naku(void) const;	// �L�������
};

// �I�I�J�~�N���X
class Wolf
{
	string name;	// �I�I�J�~�̖��O

public:
	Wolf(string);			// �R���X�g���N�^

	void naku(void) const;	// �I�I�J�~��i��������
};

// �����o�֐��̒�`
Neko::Neko(string s) :name(s) {}
void Neko::naku(void) const { cout << name << " : Meow..." << endl; }

Wolf::Wolf(string s) : name(s) { };
void Wolf::naku(void) const { cout << name << " : Howl..." << endl; }

int main(void)
{
	string nekoName, wolfName;

	cout << "�L�̖��O����� : ";
	cin >> nekoName;

	cout << "�I�I�J�~�̖��O����� : ";
	cin >> wolfName;

	Neko MyCat(nekoName);
	Wolf MyWolf(wolfName);

	MyCat.naku();	// �L�������
	MyWolf.naku();	// �I�I�J�~��i��������

	return 0;
}