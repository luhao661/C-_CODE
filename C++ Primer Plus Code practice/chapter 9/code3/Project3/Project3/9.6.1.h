#define _CRT_SECURE_NO_WARNINGS 1

#ifndef A_9_6_1_H//�������������ֿ�ͷ
#define A_9_6_1_H

const int Len = 40;

struct golf
{
	char fullname[Len];
	int handicap;
};

//�ǽ����汾
void setgolf(golf& g,const char * name,int hc);
//�����汾
int setgolf(golf& g);
//��������handicap��Ա��ֵ
void handicap(golf& g, int hc);
//��ʾgolf�ṹ�����еĳ�Ա������
void showgolf(const golf&g);

#endif				/*A_9_6_1_H*/