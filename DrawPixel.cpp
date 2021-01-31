#include "DxLib.h"

#define _LESSON10 // ���ݎ��{���̃��b�X��

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	
	// ���W
	int x = 300;
	int y = 360;
	int y_prev = 0;
	int y_temp = 0;

	
	// �ړ��W��
	float move = 0.0;

	// �ړ��ʕϐ�
	int dx = 0;
	int dy = 0;

	char key[256];

	// �O���t�B�b�N�n���h��
	int gh[12];

	LoadDivGraph(".\\res\\charall.png", 12, 3, 4, 49, 66, gh);
//	SetTransColor( int Red , int Green , int Blue ) ;
//	LoadDivGraph(".\\res\\Monster1_zorome.png", 12, 3, 4, 96/3, 128/4, gh);
	SetBackgroundColor(100,200,100);
	SetDrawScreen(DX_SCREEN_BACK);	// �`���𗠉�ʂɐݒ�


#ifdef _LESSON1	// �_������
	DrawPixel(320, 240, GetColor(255, 255, 255));	// �_��ł�
	DrawPixel(340, 240, GetColor(255, 255, 255));	// �_��ł�
	DrawPixel(360, 240, GetColor(255, 255, 255));	// �_��ł�
#endif

#ifdef _LESSON2	// �摜��ǂݍ���ŕ\������

	for (int i = 0; i < 100; i++) {
		LoadGraphScreen(i, 0, ".\\res\\star.png", TRUE);
	}

	gh = LoadGraph(".\\res\\star.png");
	for (int i = 0; i < 100; i++) {
		DrawGraph(i, 200, gh, TRUE);
	}
#endif

#ifdef _LESSON3	// �摜�𓮂���
	gh = LoadGraph(".\\res\\char.png");

	SetDrawScreen(DX_SCREEN_BACK);	// �`���𗠉�ʂɐݒ�

	int x = 0;
	while (ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen() == 0) {
		DrawGraph(x, 100, gh, TRUE);

		x += 2;
		if (x == 640) {
			break;
		}
	}
#endif

#ifdef _LESSON4	// �L�[�{�[�h�̃L�[������Ԃ��擾
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
			DrawString(300, 240, "��", 0xffff);
		}
		else if (CheckHitKey(KEY_INPUT_UP) == 1) {
			DrawString(300, 240, "��", 0xffff);
		}
		else if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
			DrawString(300, 240, "��", 0xffff);
		}
		else if (CheckHitKey(KEY_INPUT_DOWN) == 1) {
			DrawString(300, 240, "��", 0xffff);
		}
		else if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
#endif

#ifdef _LESSON5	// �L�[�{�[�h�̃L�[������Ԃ��擾2  �摜�ړ�
	gh = LoadGraph(".\\res\\char.png");

	SetDrawScreen(DX_SCREEN_BACK);	// �`���𗠉�ʂɐݒ�

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll(key)==0){

		DrawGraph(x, y, gh, TRUE);


		if (key[KEY_INPUT_LEFT] == 1) {
			x -= 6;
		}
		else if (key[KEY_INPUT_RIGHT] == 1) {
			x += 6;
		}
		else if (key[KEY_INPUT_UP] == 1) {
			y -= 6;
		}
		else if (key[KEY_INPUT_DOWN] == 1) {
			y += 6;
		}
		else if (key[KEY_INPUT_ESCAPE] == 1) {
			break;
		}
	}
#endif

#ifdef _LESSON6	// ����炷/�~�߂�
	int sh;
	sh = LoadSoundMem(".\\res\\sound1.mp3");

	SetDrawScreen(DX_SCREEN_BACK);	// �`���𗠉�ʂɐݒ�

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0) {
		if (key[KEY_INPUT_RETURN] == 1) {
			if (CheckSoundMem(sh) == 0) {
				PlaySoundMem(sh, DX_PLAYTYPE_BACK, TRUE);	// ����炷
			}
		}
		else if (key[KEY_INPUT_SPACE] == 1) {
			StopSoundMem(sh);	// �����~�߂�
		}
		else if (key[KEY_INPUT_ESCAPE] == 1) {
			DeleteSoundMem(sh);	// �T�E���h�n���h�����폜
			break;
		}

	}
#endif

#ifdef _LESSON7	// �L�����΂߈ړ�
	gh = LoadGraph(".\\res\\char.png");

	SetDrawScreen(DX_SCREEN_BACK);	// �`���𗠉�ʂɐݒ�

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0) {

		DrawGraph(x, y, gh, TRUE);

		move = 1.0f;
		if (key[KEY_INPUT_LEFT] == 1 || key[KEY_INPUT_RIGHT]) {
			if (key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN]) {
				move = 0.71f;
			}
			else {
				move = 1.0f;
			}
		}

		if (key[KEY_INPUT_LEFT] == 1) {
			x -= 6*move;
		}
		if (key[KEY_INPUT_RIGHT] == 1) {
			x += 6*move;
		}
		if (key[KEY_INPUT_UP] == 1) {
			y -= 6 * move;
		}
		if (key[KEY_INPUT_DOWN] == 1) {
			y += 6 * move;
		}
		if (key[KEY_INPUT_ESCAPE] == 1) {
			break;
		}
	}
#endif

#ifdef _LESSON8_1	// �L���������点��
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0) {

		move = 0.0f;
		DrawGraph(x, y, gh, TRUE);

		if (key[KEY_INPUT_LEFT] == 1 || key[KEY_INPUT_RIGHT]) {
			if (key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN]) {
				move = 0.71f;
			}
			else {
				move = 1.0f;
			}
		}
		else if (key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN] == 1) {
			move = 1.0f;
		}


		if (key[KEY_INPUT_LEFT] == 1) {
			x -= (int)10 * move;
			dx = (int)-10 * move;
		}
		if (key[KEY_INPUT_RIGHT] == 1) {
			x += (int)10 * move;
			dx = (int)10 * move;
		}
		if (key[KEY_INPUT_UP] == 1) {
			y -= (int)10 * move;
			dy = (int)-10 * move;
		}
		if (key[KEY_INPUT_DOWN] == 1) {
			y += (int)10 * move;
			dy = (int)10 * move;
		}

		if (move == 0.0f) {
			// �����L�[��������ĂȂ��Ƃ�
			if (dx != 0) {
				if (dx < 0) {
					++dx;
				}
				if (dx > 0) {
					--dx;
				}
			}

			if (dy != 0) {
				if (dy < 0) {
					++dy;
				}
				if (dy > 0) {
					--dy;
				}
			}

			x += dx;
			y += dy;
		}


		if (key[KEY_INPUT_ESCAPE] == 1) {
			break;
		}

	}
#endif


#ifdef _LESSON8_2	// �L���������点��
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0) {

		move = 1.0f;
		DrawGraph(x, y, gh, TRUE);

		if (key[KEY_INPUT_LEFT] == 1 || key[KEY_INPUT_RIGHT]) {
			if (key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN]) {
				move = 0.71f;
			}
			else {
				move = 1.0f;
			}
		}

		if (key[KEY_INPUT_LEFT] == 1) {
			x -= (int)10 * move;
			dx = (int)-10 * move;
		}
		if (key[KEY_INPUT_RIGHT] == 1) {
			x += (int)10 * move;
			dx = (int)10 * move;
		}
		if (key[KEY_INPUT_UP] == 1) {
			y -= (int)10 * move;
			dy = (int)-10 * move;
		}
		if (key[KEY_INPUT_DOWN] == 1) {
			y += (int)10 * move;
			dy = (int)10 * move;
		}

		if (CheckHitKeyAll(DX_CHECKINPUT_KEY) == 0) {
			// �����L�[��������ĂȂ��Ƃ�
			if (dx != 0) {
				if (dx < 0) {
					++dx;
				}
				if (dx > 0) {
					--dx;
				}
			}

			if (dy != 0) {
				if (dy < 0) {
					++dy;
				}
				if (dy > 0) {
					--dy;
				}
			}

			x += dx;
			y += dy;
		}

		if (key[KEY_INPUT_ESCAPE] == 1) {
			break;
		}
	}
#endif


#ifdef _LESSON9	// �L�������������
	int xcount = 0;
	int ycount = 0;
	int ix = 0;
	int iy = 0;
	int result = 0;
	int row = 2; // �摜�̍s�ʒu�ƌ����Ă�����i0:UP, 1:RIGHT, 2:DOWN, 3:LEFT�j
	int col = 1; // �摜�̗�ʒu
	int pre_col=col; // 1�O�̉摜�̗�ʒu

	int loop = 0;
while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0) {

	move = 1.0f;

	if (key[KEY_INPUT_LEFT] == 1 || key[KEY_INPUT_RIGHT]) {
		if (key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN]) {
			move = 0.71f;
		}
		else {
			move = 1.0f;
		}
	}

	// �΂߈ړ��̎��͉�������D�悷�邽�߂ɁA�c�����̔���̌�ŉ������̔��菈�����s��
	if (key[KEY_INPUT_UP] == 1) {
		y -= (int)4 * move;
		row = 0;
	}
	if (key[KEY_INPUT_DOWN] == 1) {
		y += (int)4 * move;
		row = 2;
	}
	if (key[KEY_INPUT_LEFT] == 1) {
		x -= (int)4 * move;
		row = 3;
	}
	if (key[KEY_INPUT_RIGHT] == 1) {
		x += (int)4 * move;
		row = 1;
	}


	if (loop == 10) {// loop30���1�񂾂����ύX����

		if (col == 0 || col == 2) {
			pre_col = col; // �P�O�̗��ێ�
			col = 1;
		}
		else if (col == 1) {
			if (pre_col == 0) {
				col = 2;
			}
			else {// pre_col == 2
				col = 0;
			}
		}

		loop = 0; // ���[�v�J�E���^���Z�b�g
	}
	loop++;

	//�΂߈ړ��̏ꍇ�͉����D��
	if (move == 0.71f) {

	}

	result = (row * 3) + col;
	DrawGraph(x, y, gh[result], TRUE);


	if (key[KEY_INPUT_ESCAPE] == 1) {
		break;
	}
}
#endif

#ifdef _LESSON10	// �L�������������
int xcount = 0;
int ycount = 0;
int ix = 0;
int iy = 0;
int result = 0;
int row = 2; // �摜�̍s�ʒu�ƌ����Ă�����i0:UP, 1:RIGHT, 2:DOWN, 3:LEFT�j
int col = 1; // �摜�̗�ʒu
int pre_col = col; // 1�O�̉摜�̗�ʒu
bool jflag = false; // �W�����v�t���O


	int loop = 0;
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0) {

		move = 1.0f;

		if (key[KEY_INPUT_LEFT] == 1 || key[KEY_INPUT_RIGHT]) {
			if (key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN]) {
				move = 0.71f;
			}
			else {
				move = 1.0f;
			}
		}

		// �΂߈ړ��̎��͉�������D�悷�邽�߂ɁA�c�����̔���̌�ŉ������̔��菈�����s��
		if (key[KEY_INPUT_LEFT] == 1) {
			x -= (int)4 * move;
			row = 3;
		}
		if (key[KEY_INPUT_RIGHT] == 1) {
			x += (int)4 * move;
			row = 1;
		}

		// ��ʈړ�����
		if (x + (49 / 2) > 640) {
			x = 640 - (49 / 2);
		}
		if (x < (49 / 2)) {
			x = (49 / 2);
		}


		// �W�����v����
		if (jflag == true) {
			y_temp = y;
			y += (y - y_prev) + 1;
			y_prev = y_temp;
			if (y == 360) {
				jflag = false;
			}
		}

		if (key[KEY_INPUT_SPACE] == 1 && jflag == false){
			jflag = true;
			y_prev = y;
			y -= 20;
		}

		if (loop == 10) {// loop30���1�񂾂����ύX����

			if (col == 0 || col == 2) {
				pre_col = col; // �P�O�̗��ێ�
				col = 1;
			}
			else if (col == 1) {
				if (pre_col == 0) {
					col = 2;
				}
				else {// pre_col == 2
					col = 0;
				}
			}

			loop = 0; // ���[�v�J�E���^���Z�b�g
		}
		loop++;

		//�΂߈ړ��̏ꍇ�͉����D��
		if (move == 0.71f) {

		}

		result = (row * 3) + col;
		//DrawGraph(x, y, gh[result], TRUE);
		DrawGraph(x - (49 / 2), y - (66 / 2), gh[result], TRUE);



		if (key[KEY_INPUT_ESCAPE] == 1) {
			break;
		}
	}
#endif

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}
