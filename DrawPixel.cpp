#include "DxLib.h"

#define _LESSON10 // 現在実施中のレッスン

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	
	// 座標
	int x = 300;
	int y = 360;
	int y_prev = 0;
	int y_temp = 0;

	
	// 移動係数
	float move = 0.0;

	// 移動量変数
	int dx = 0;
	int dy = 0;

	char key[256];

	// グラフィックハンドル
	int gh[12];

	LoadDivGraph(".\\res\\charall.png", 12, 3, 4, 49, 66, gh);
//	SetTransColor( int Red , int Green , int Blue ) ;
//	LoadDivGraph(".\\res\\Monster1_zorome.png", 12, 3, 4, 96/3, 128/4, gh);
	SetBackgroundColor(100,200,100);
	SetDrawScreen(DX_SCREEN_BACK);	// 描画先を裏画面に設定


#ifdef _LESSON1	// 点を書く
	DrawPixel(320, 240, GetColor(255, 255, 255));	// 点を打つ
	DrawPixel(340, 240, GetColor(255, 255, 255));	// 点を打つ
	DrawPixel(360, 240, GetColor(255, 255, 255));	// 点を打つ
#endif

#ifdef _LESSON2	// 画像を読み込んで表示する

	for (int i = 0; i < 100; i++) {
		LoadGraphScreen(i, 0, ".\\res\\star.png", TRUE);
	}

	gh = LoadGraph(".\\res\\star.png");
	for (int i = 0; i < 100; i++) {
		DrawGraph(i, 200, gh, TRUE);
	}
#endif

#ifdef _LESSON3	// 画像を動かす
	gh = LoadGraph(".\\res\\char.png");

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先を裏画面に設定

	int x = 0;
	while (ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen() == 0) {
		DrawGraph(x, 100, gh, TRUE);

		x += 2;
		if (x == 640) {
			break;
		}
	}
#endif

#ifdef _LESSON4	// キーボードのキー押下状態を取得
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
			DrawString(300, 240, "←", 0xffff);
		}
		else if (CheckHitKey(KEY_INPUT_UP) == 1) {
			DrawString(300, 240, "↑", 0xffff);
		}
		else if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
			DrawString(300, 240, "→", 0xffff);
		}
		else if (CheckHitKey(KEY_INPUT_DOWN) == 1) {
			DrawString(300, 240, "↓", 0xffff);
		}
		else if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
#endif

#ifdef _LESSON5	// キーボードのキー押下状態を取得2  画像移動
	gh = LoadGraph(".\\res\\char.png");

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先を裏画面に設定

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

#ifdef _LESSON6	// 音を鳴らす/止める
	int sh;
	sh = LoadSoundMem(".\\res\\sound1.mp3");

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先を裏画面に設定

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0) {
		if (key[KEY_INPUT_RETURN] == 1) {
			if (CheckSoundMem(sh) == 0) {
				PlaySoundMem(sh, DX_PLAYTYPE_BACK, TRUE);	// 音を鳴らす
			}
		}
		else if (key[KEY_INPUT_SPACE] == 1) {
			StopSoundMem(sh);	// 音を止める
		}
		else if (key[KEY_INPUT_ESCAPE] == 1) {
			DeleteSoundMem(sh);	// サウンドハンドルを削除
			break;
		}

	}
#endif

#ifdef _LESSON7	// キャラ斜め移動
	gh = LoadGraph(".\\res\\char.png");

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先を裏画面に設定

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

#ifdef _LESSON8_1	// キャラを滑らせる
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
			// 何もキーが押されてないとき
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


#ifdef _LESSON8_2	// キャラを滑らせる
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
			// 何もキーが押されてないとき
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


#ifdef _LESSON9	// キャラを歩かせる
	int xcount = 0;
	int ycount = 0;
	int ix = 0;
	int iy = 0;
	int result = 0;
	int row = 2; // 画像の行位置と向いてる方向（0:UP, 1:RIGHT, 2:DOWN, 3:LEFT）
	int col = 1; // 画像の列位置
	int pre_col=col; // 1つ前の画像の列位置

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

	// 斜め移動の時は横向きを優先するために、縦方向の判定の後で横方向の判定処理を行う
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


	if (loop == 10) {// loop30回に1回だけ列を変更する

		if (col == 0 || col == 2) {
			pre_col = col; // １つ前の列を保持
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

		loop = 0; // ループカウンタリセット
	}
	loop++;

	//斜め移動の場合は横顔を優先
	if (move == 0.71f) {

	}

	result = (row * 3) + col;
	DrawGraph(x, y, gh[result], TRUE);


	if (key[KEY_INPUT_ESCAPE] == 1) {
		break;
	}
}
#endif

#ifdef _LESSON10	// キャラを歩かせる
int xcount = 0;
int ycount = 0;
int ix = 0;
int iy = 0;
int result = 0;
int row = 2; // 画像の行位置と向いてる方向（0:UP, 1:RIGHT, 2:DOWN, 3:LEFT）
int col = 1; // 画像の列位置
int pre_col = col; // 1つ前の画像の列位置
bool jflag = false; // ジャンプフラグ


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

		// 斜め移動の時は横向きを優先するために、縦方向の判定の後で横方向の判定処理を行う
		if (key[KEY_INPUT_LEFT] == 1) {
			x -= (int)4 * move;
			row = 3;
		}
		if (key[KEY_INPUT_RIGHT] == 1) {
			x += (int)4 * move;
			row = 1;
		}

		// 画面移動制御
		if (x + (49 / 2) > 640) {
			x = 640 - (49 / 2);
		}
		if (x < (49 / 2)) {
			x = (49 / 2);
		}


		// ジャンプ処理
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

		if (loop == 10) {// loop30回に1回だけ列を変更する

			if (col == 0 || col == 2) {
				pre_col = col; // １つ前の列を保持
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

			loop = 0; // ループカウンタリセット
		}
		loop++;

		//斜め移動の場合は横顔を優先
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

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
