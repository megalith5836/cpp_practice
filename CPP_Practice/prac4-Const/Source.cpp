// �����̃R���X�g���N�^�����N���X�̍쐬���K

#include <iostream>
using namespace std;

#pragma region �N���X��`

/// <summary>
/// �^�o�R���N���X�@���ݔ��̒��ɓ����Ă���^�o�R�ɑ΂��ď������s��
/// </summary>
class Tabacco
{
	int value;

public:
	Tabacco(void);
	Tabacco(int);

	void Refill(int);
	void Use(void);
};

#pragma endregion

#pragma region �����o�֐���`

/// <summary>
/// �����Ȃ��R���X�g���N�^�@�V�i�̔��𐶐�
/// </summary>
Tabacco::Tabacco(void) :value(20) {}

/// <summary>
/// �R���X�g���N�^�@�w��{������ꂽ���𐶐�
/// </summary>
/// <param name="n">�^�o�R�̖{��</param>
Tabacco::Tabacco(int n) : value(n) {}

/// <summary>
/// �w��{�����[����
/// </summary>
/// <param name="n">��[�{��</param>
void Tabacco::Refill(int n)
{
	if (value + n <= 20)	// �����20
	{
		value += n;
		cout << n << "�{��[����" << value << "�{�ɂȂ�܂���" << endl;
	}
	else
	{
		cout << "����𒴂��Ă̕�[�͏o���܂���" << endl;
	}
}

/// <summary>
/// �^�o�R��1�{�����
/// </summary>
void Tabacco::Use(void)
{
	if (value > 0)
	{
		value--;
		cout << "���Ȃ��͈ꕞ���܂����@�c��{�� : " << value << "�{" << endl;
	}
	else
	{
		cout << "������{���c���Ă��܂���B" << endl;
	}
}

#pragma endregion


int main(void)
{
	int value;

	cout << "�^�o�R���𐶐����܂��B�{�����w�肵�Ă��������i0���w�肷��ƐV�i�����j" << endl;
	cout << "�{�� >> ";
	cin >> value;

	// �����Ȑ��l���͂ŏI��
	if (value < 0 || value>20)
	{
		cout << "�����Ȑ��l�ł�" << endl;
		return -1;
	}

	// �^�o�R���̐���
	// Tabacco box;
	Tabacco box(value != 0 ? value : NULL);

	// 5��g�p����
	for (int i = 0; i < 5; i++)
		box.Use();

	// 2���[����i5�{�Œ�j
	for (int i = 0; i < 2; i++)
		box.Refill(5);

	return 0;
}