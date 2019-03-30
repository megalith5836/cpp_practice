#pragma once

/// <summary>
/// �I�Z���Q�[���Ɋւ���N���X
/// �Ֆʂ̃T�C�Y��8x8�Œ�i�ǂ��܂߂�10x10�j
/// </summary>
class Othello
{
	static const int FIELD_HEIGHT = 10;
	static const int FIELD_WIDTH = 10;

	int field[FIELD_HEIGHT][FIELD_WIDTH];	// �Ֆʁi�T�C�Y�Œ�j

	int turn;			// ���݂̃^�[��
	int turnCount;		// �^�[�����i�ꏄ��1�J�E���g�j
	int blackCount;		// ���̐ΐ�
	int whiteCount;		// ���̐ΐ�
	bool gameEndFlag;	// �Q�[���I���t���O�@True�ŏI��

	enum Stones {		// �}�X�̏�Ԃ�\���񋓌^
		wall,
		empty,
		blackStone,
		whiteStone
	};

	enum Turn {			// �^�[����\���񋓌^
		blackTurn,
		whiteTurn
	};


	bool canPlace(int, int);	// �}�X�ɐ΂�u���邩�̃`�F�b�N�֐�
	void checkStone(void);		// �t�B�[���h��̐ΐ����`�F�b�N����֐�
	
public:
	Othello(void);

	void drawField(void);		// �t�B�[���h�`��֐�
	bool putStone(int, int);	// �w����W�ɐ΂�z�u����֐�

};