#include <stdio.h>
//�\�o�͗p
int i,j;
void table();
//���W�F���p
int x,y,data[9][9];
void riversi(int);
int fish;
//�F�ʗp�@256=White 512=Black
int ancolor,color;
//�^�[���p
int turn=1;
void conturn();
//�I���p
int count,wcount,bcount;
//�G���y���[�p
void emperor();
int emp;

int main(){
	//�����ݒ�ƕ\�o��
	printf("osero\n");
	data[4][4]=256;
	data[4][5]=512;
	data[5][4]=512;
	data[5][5]=256;
	table();
	while(1){
		//�F����
		conturn();
		//���W�F��
		while(1){
			// X���W
			while(1){
				printf("X=");
				scanf("%d",&x);
				if(x>0&&x<9)break;
				if(x==11)break;
				printf("error\n");
			}
			// Y���W
			while(1){
				printf("Y=");
				scanf("%d",&y);
				if(y>0&&y<9)break;
				if(y==11&&x==11){
					emperor();
					emp=1;
					break;
				}
				printf("error\n");
			}
			riversi(0);
			if(fish==1){
				fish=0;
				if(data[x][y]==0){
					break;
				}
			}
			if(emp!=1)printf("error\n");
			emp=0;
		}
		// ����
		data[x][y]=color;
		riversi(1);
		// �\�o��
		table();
		//�I�����m
		for(i=1;i<=8;i++){
			for(j=1;j<=8;j++){
				if(data[j][i]==256)wcount+=1;
				if(data[j][i]==512)bcount+=1;
			}
		}
		if(wcount+bcount>=64){
			printf("Thank you for playing.\n");
			printf("Black %d\n",bcount);
			printf("White %d\n",wcount);
			break;
		}
		bcount=0;
		wcount=0;
	}
	return 0;
}
//�^�[��
void conturn(){
	turn+=1;
	if(turn%2==0){
		color=512;
		ancolor=256;
		printf("\nturn Black\n");
	}else{
		color=256;
		ancolor=512;
		printf("\nturn White\n");
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
				printf(" ��");
			}else if(data[j][i]==512){
				printf(" ��");
			}else if(data[j][i]==0){
				printf("�[");
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
//�G���y���[�v���O����
void emperor(){
	printf("�G���y���[�v���O���������s\n");
	//���W�F��
	while(1){
		// X���W
		while(1){
			printf("X=");
			scanf("%d",&x);
			if(x>0&&x<9)break;
			printf("�G���[�@X�̒l���͈͊O\n");
		}
		// Y���W
		while(1){
			printf("Y=");
			scanf("%d",&y);
			if(y>0&&y<9)break;
			printf("�G���[�@Y�̒l���͈͊O\n");
		}
		//�F�w��
		while(1){
			printf("512=B 256=W 0=  \ncolor=");
			scanf("%d",&color);
			if(color==512||color==256||color==0)break;
		}
		data[x][y]=color;
		table();
		turn-=1;
		conturn();
		break;
	}
}
//���o�[�V�v���O����
void riversi(int meat){
	int a,b;
	for(a=-1;a<=1;a++){
		for(b=-1;b<=1;b++){
			if(data[x+a*2][y+b*2]==color){
				if(data[x+a*1][y+b*1]==ancolor){
					if(meat==0){
						fish=1;
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
				if(data[x+a*3][y+b*3]&&data[x+a*2][y+b*2]==ancolor){
					if(meat==0){
						fish=1;
					}else{
						for(i=3;i>0;i--)data[x+a*i][y+b*i]=color;
					}
				}
			}
			else if(data[x+a*5][y+b*5]==color){
				if(data[x+a*4][y+b*4]&&data[x+a*3][y+b*3]&&data[x+a*2][y+b*2]==ancolor){
					if(meat==0){
						fish=1;
					}else{
						for(i=4;i>0;i--)data[x+a*i][y+b*i]=color;
					}
				}
			}
			else if(data[x+a*6][y+b*6]==color){
				if(data[x+a*5][y+b*5]&&data[x+a*4][y+b*4]&&data[x+a*3][y+b*3]&&data[x+a*2][y+b*2]==ancolor){
					if(meat==0){
						fish=1;
						}else{
						for(i=5;i>0;i--)data[x+a*i][y+b*i]=color;
					}
				}
			}
			else if(data[x+a*7][y+b*7]==color){
				if(data[x+a*6][y+b*6]&&data[x+a*5][y+b*5]&&data[x+a*4][y+b*4]&&data[x+a*3][y+b*3]&&data[x+a*2][y+b*2]==ancolor){
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