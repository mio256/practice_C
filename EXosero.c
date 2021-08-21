#include <stdio.h>
#include <stdlib.h>
//�\�p
int i,j;
void table();
//���o�[�V�p
int x,y,data[9][9];
void riversi(int);
int fish;
//�^�[���p
//256=White 512=Black
int ancolor,color;
int turn=1;
void conturn();
void tapioka();
//�I���p
int count,wcount,bcount;
//�G���y���[�p
void emperor();
int emp;

int main(){
	//��������
	printf("Hello new world.\nPlease have a good time with EXosero.\n");
	data[4][4]=256;
	data[4][5]=512;
	data[5][4]=512;
	data[5][5]=256;
	table();
	while(1){
		//�^�[������
		conturn();
		//�����ΐ�^�[��
		if(color==256){
			tapioka();
		}else if(color==512){
			//���[�U�[�^�[��
			while(1){
				//�ϐ��̏�����
				x=0;
				y=0;
				emp=0;
				// X�̓���
				while(1){
					printf("X=");
					scanf("%d",&x);
					if(x>=1&&x<=8)break;
					if(x==11){
						emperor();
						break;
					}
					printf("error outX\n");
				}
				if(emp!=0)break;
				// Y�̓���
				while(1){
					printf("Y=");
					scanf("%d",&y);
					if(y>=1&&y<=8)break;
					if(y==11){
						emperor();
						break;
					}
					printf("error outY\n");
				}
				if(emp!=0)break;
				//���W���K�������f
				riversi(0);
				if(fish==1&&data[x][y]==0){
					//riversi(0)�ɂ���ă��o�[�V�\�ł����fish=1
					fish=0;
					//���W�m�肵�I��
					data[x][y]=color;
					break;
				}else if(1)printf("error Noriversi\n");
			}
		}
		//�G���y���[�R�}���h
		if(emp==11)break;
		if(emp==512){
			for(i=1;i<=8;i++){
				for(j=1;j<=8;j++){
					data[j][i]=512;
				}
			}
		}
		if(emp==256){
			for(i=1;i<=8;i++){
				for(j=1;j<=8;j++){
					data[j][i]=256;
				}
			}
		}
		//���o�[�V�̎��s
		riversi(1);
		//�\�̏o��
		table();
		//�I�����m
		for(i=1;i<=8;i++){
			for(j=1;j<=8;j++){
				if(data[j][i]==256)wcount+=1;
				if(data[j][i]==512)bcount+=1;
			}
		}
		if(wcount+bcount>=64){
			printf("turn %d\n",turn-1);
			printf("Black %d\n",bcount);
			printf("White %d\n",wcount);
			if(bcount>wcount){
				printf("______________\n");
				printf("YOU WIN\n");
				printf("______________\n");
			}
			//�v���O�����I��
			break;
		}
		bcount=0;
		wcount=0;
	}
	printf("Thank you for playing.\n");
	scanf("%d",&i);
	return 0;
}
//�^�[������
void conturn(){
	turn+=1;
	if(turn%2==0){
		color=512;
		ancolor=256;
		printf("\nyour turn\n");
	}else{
		color=256;
		ancolor=512;
		printf("\nmy turn\n");
	}
}
//�\�o��
void table(){
	printf("\n");
	for(i=1;i<=8;i++){
		printf(" %d",i);
	}
	printf("\n");
	for(i=1;i<=8;i++){
		printf("%d",i);
		for(j=1;j<=8;j++){
			if(data[j][i]==256){
				printf("��");
			}else if(data[j][i]==512){
				printf("��");
			}else if(data[j][i]==0){
				printf("--");
			}
		}
		printf("%d",i);
		printf("\n");
	}
	for(i=1;i<=8;i++){
		printf(" %d",i);
	}
	printf("\n");
}
//�G���y���[
void emperor(){
	printf("Hello emperor\n");
	emp=1;
	while(1){
		//�ϐ�������
		x=0;
		y=0;
		//X�̓���
		while(1){
			printf("X=");
			scanf("%d",&x);
			if(x==11||x==512||x==256){
				emp=x;
				break;
			}
			if(x>=1&&x<=8)break;
		}
		if(emp!=1)break;
		//Y�̓���
		while(1){
			printf("Y=");
			scanf("%d",&y);
			if(y==11||x==512||x==256){
				emp=x;
				break;
			}
			if(y>=1&&y<=8)break;
		}
		if(emp!=1)break;
		//���W�l�̓���
		while(1){
			printf("512=�� 256=�� 0=--\ncolor=");
			scanf("%d",&color);
			if(color==512||color==256||color==0)break;
		}
		data[x][y]=color;
		turn-=1;
		break;
	}
}
//�����ΐ�
void tapioka(){
	while(1){
		//�����_���Ŏ��
		x=rand() % 8+1;
		y=rand() % 8+1;
		riversi(0);
		if(fish==1){
			fish=0;
			if(data[x][y]==0){
				data[x][y]=color;
				break;
			}
		}
	}
}
//���o�[�V
void riversi(int meat){
	int a,b;
	for(a=-1;a<=1;a++){
		for(b=-1;b<=1;b++){
			//-1����1�̎w������̓��ɓ��F�������
			if(data[x+a*2][y+b*2]==color){
				//���̊Ԃ��ِF�ł����
				if(data[x+a*1][y+b*1]==ancolor){
					//meat=0��fish��Ԃ�
					if(meat==0){
						fish=1;
						
					//meat=1�Ń��o�[�V���s
					}else{
						for(i=1;i>0;i--)data[x+a*i][y+b*i]=color;
					}
				}
			}
			else if(data[x+a*3][y+b*3]==color){
				if(data[x+a*2][y+b*2]&&data[x+a*1][y+b*1]==ancolor){
					if(meat==0){
						fish=1;
					}else{
						for(i=2;i>0;i--)data[x+a*i][y+b*i]=color;
					}
				}
			}
			else if(data[x+a*4][y+b*4]==color){
				if(data[x+a*3][y+b*3]&&data[x+a*2][y+b*2]&&data[x+a*1][y+b*1]==ancolor){
					if(meat==0){
						fish=1;
					}else{
						for(i=3;i>0;i--)data[x+a*i][y+b*i]=color;
					}
				}
			}
			else if(data[x+a*5][y+b*5]==color){
				if(data[x+a*4][y+b*4]&&data[x+a*3][y+b*3]&&data[x+a*2][y+b*2]&&data[x+a*1][y+b*1]==ancolor){
					if(meat==0){
						fish=1;
					}else{
						for(i=4;i>0;i--)data[x+a*i][y+b*i]=color;
					}
				}
			}
			else if(data[x+a*6][y+b*6]==color){
				if(data[x+a*5][y+b*5]&&data[x+a*4][y+b*4]&&data[x+a*3][y+b*3]&&data[x+a*2][y+b*2]&&data[x+a*1][y+b*1]==ancolor){
					if(meat==0){
						fish=1;
						}else{
						for(i=5;i>0;i--)data[x+a*i][y+b*i]=color;
					}
				}
			}
			else if(data[x+a*7][y+b*7]==color){
				if(data[x+a*6][y+b*6]&&data[x+a*5][y+b*5]&&data[x+a*4][y+b*4]&&data[x+a*3][y+b*3]&&data[x+a*2][y+b*2]&&data[x+a*1][y+b*1]==ancolor){
					if(meat==0){
						fish=1;
					}else{
						for(i=6;i>0;i--)data[x+a*i][y+b*i]=color;
					}
				}
			}
		}
	}
}