#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
//メインデータ
int maindata[11][11];
//入力に応じてデータを移動
void form();
//form補助
void sform();
//新規生成
void create();
//新規生成の補助
int ex, ey;
//表出力
void table();
//for文とデータ制御
int x, y;
//スコア計算と終了感知
int end();
//アイテムコマンド
int item(int, int);
//アイテムデータ
int itemdata[3];
//フィールドの広さ
int field;
//ターン
int turn = 1;
//ユーザー入力
char doing;
//スコア
int score;
//スコアの設定値
int iscore;

int main(void)
{
	//ユーザー入力と初期値
	printf("Hello player.\nHow many field?\nPlese choice   ");
	do
	{

		scanf("%d", &field);
	} while (field > 10);
	create();
	table();
	while (1)
	{
		//スコア計算
		end(1);
		//表示
		printf("turn=%d   score=%d\n", turn, score);
		printf("w=up  s=down  a=left\nd=right  e=end  item=i\n");
		//入力
		char getch();
		doing = getch();
		//データ整理
		form();
		//表出力
		table();
		//終了
		if (end() != 1 || doing == 'e')
		{
			printf("---------------\ngameover\nscore %d\n---------------\n", score);
			break;
		}
		//新規生成
		create();
		//ターン計算
		turn++;
	}
}

/*	アイテムコマンドの実行
	ユーザー入力に応じて進行方向を定めsformに転送 */
void form()
{
	int i;
	//アイテムコマンド
	if (doing == 'i')
	{
		printf("do you want to power?\n1 abyss(奈落)\n2 aegis(神盾)\n3 dimension(次元)\n");
		scanf("%d", &i);
		printf("Really? Yes=Y No=anykey\n");
		char getch();
		doing = getch();
	}
	if (doing == 'y')
	{
		item(2, 1);
		item(2, 2);
		item(2, 3);
		item(3, i);
	}
	//重複する座標の制御のためfield回繰り返す
	for (i = field; i >= 1; i--)
	{
		//Wが押されたら
		if (doing == 'w')
		{
			//最後の最上部を含まず、xを減らしながら座標を指定
			for (x = field; x > 1; x--)
			{
				//yを減らしながら座標を指定（yは増やしても構わない）
				for (y = field; y >= 1; y--)
				{
					//上方向に移動させるようにsformに転送
					sform(-1, 0);
				}
			}
		}
		else if (doing == 's')
		{
			for (x = 1; x < field; x++)
			{
				for (y = field; y >= 1; y--)
				{
					sform(+1, 0);
				}
			}
		}
		else if (doing == 'a')
		{
			for (x = 1; x <= field; x++)
			{
				for (y = field; y > 1; y--)
				{
					sform(0, -1);
				}
			}
		}
		else if (doing == 'd')
		{
			for (x = 1; x <= field; x++)
			{
				for (y = 1; y < field; y++)
				{
					sform(0, +1);
				}
			}
		}
	}
}

/*	formから指定座標と進行方向a,bを受け取る
	データを読み込みデータを移動させる*/
void sform(int a, int b)
{
	//指定座標に数値があり、進行方向と指定座標同一である場合
	if (maindata[x][y] != 0 && maindata[x + a][y + b] == maindata[x][y])
	{
		//進行方向を二倍し、指定座標を初期化する
		maindata[x + a][y + b] *= 2;
		maindata[x][y] = 0;
		//指定座標に数値があり、進行方向に数値がない場合
	}
	else if (maindata[x][y] != 0 && maindata[x + a][y + b] == 0)
	{
		//指定座標の値を進行方向に移動させる
		maindata[x + a][y + b] = maindata[x][y];
		maindata[x][y] = 0;
	}
	//指定座標に数値がない場合はなにもしない
}

/*	数値が入っていない座標をランダムに選び数値を入力する */
void create()
{
	int i;
	//2か4を選ぶ
	int increace;
	//回数測定
	int ene;
	//turn<15ならば1回、turn>15で15刻みに新規生成回数が増える
	for (i = 1; i <= turn / 15 + 1; i++)
	{
		while (1)
		{
			//ランダム生成
			x = rand() % field + 1;
			y = rand() % field + 1;
			//ランダム座標に数値がない場合
			if (maindata[x][y] == 0)
			{
				//2か4を入力
				increace = rand() % 2 + 1;
				if (increace == 1)
				{
					increace = 4;
				}
				maindata[x][y] = increace;
				break;
				//20回ランダム生成しても入力できていない場合
			}
			else if (ene > 20)
			{
				//座標が埋まってきているので2を入力する
				maindata[ex][ey] = 2;
				break;
			}
			//ランダム生成の回数
			ene++;
		}
	}
}

void table()
{
	//表出力
	for (x = 1; x <= field; x++)
	{
		for (y = 1; y <= field; y++)
		{
			if (maindata[x][y] != 0)
			{
				printf("%4d", maindata[x][y]);
			}
			else
			{
				printf(" -- ");
			}
		}
		printf("\n");
	}
}

/*	mode1 所持アイテムの個数を返す number不要
	mode2 number指定でアイテムを手に入れる
	mode3 アイテムの使用
	number1 abyss(奈落) 最大数だけ残す
	number2 aegis(神盾) fieldを増やす
	number3 dimension(次元) スコアをそのままに全初期化する*/
int item(int mode, int number)
{
	int sum, ix, iy, i;
	if (mode == 1)
	{
		for (i = 3; i > 0; i--)
		{
			if (itemdata[i] != 0)
			{
				sum += 1;
			}
		}
		return sum;
	}
	else if (mode == 2)
	{
		if (number == 1)
		{
			itemdata[1] = 1;
		}
		else if (number == 2)
		{
			itemdata[2] = 1;
		}
		else if (number == 3)
		{
			itemdata[3] = 1;
		}
	}
	else if (mode == 3)
	{
		if (number == 1)
		{
			sum = 0;
			itemdata[1] = 0;
			for (x = 1; x <= field; x++)
			{
				for (y = 1; y <= field; y++)
				{
					if (maindata[x][y] >= sum)
					{
						sum = maindata[x][y];
					}
				}
			}
			for (x = 1; x <= field; x++)
			{
				for (y = 1; y <= field; y++)
				{
					if (maindata[x][y] != sum)
					{
						maindata[x][y] = 0;
					}
				}
			}
		}
		else if (number == 2)
		{
			itemdata[2] = 0;
			field += 1;
		}
		else if (number == 3)
		{
			itemdata[3] = 0;
			end();
			iscore = score;
			for (x = 1; x <= field; x++)
			{
				for (y = 1; y <= field; y++)
				{
					maindata[x][y] = 0;
				}
			}
		}
	}
}

int end()
{
	//初期化
	int ender = 0;
	score = iscore;
	//データを調べる
	for (x = 1; x <= field; x++)
	{
		for (y = 1; y <= field; y++)
		{
			//スコア換算
			score += maindata[x][y];
			//数値がない場合
			if (maindata[x][y] == 0)
			{
				//新規生成用に登録する
				ex = x;
				ey = y;
				//数値がない座標の数を数える
				ender++;
			}
		}
	}
	//数値がない座標が一つでもあれば
	if (ender > 0)
	{
		return 1;
	}
}