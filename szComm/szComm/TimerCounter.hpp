//#include "StdAfx.h"
#include <iostream>

#include <windows.h>


class TimerCounter
{
public:
	TimerCounter(void);//���캯��
	~TimerCounter(void);//��������

private:
	LARGE_INTEGER startCount;//��¼��ʼʱ��

	LARGE_INTEGER endCount;//��¼����ʱ��

	LARGE_INTEGER freq;//����CPUʱ��Ƶ��

public:
	double dbTime;//�������е�ʱ�䱣��������

public:
	void Start();//�������ʼ�㴦��ʼ��ʱ
	void Stop();//�����������㴦������ʱ
};

using namespace std;
TimerCounter::TimerCounter(void)
{
    QueryPerformanceFrequency(&freq);//��ȡ����CPUʱ��Ƶ��
}

TimerCounter::~TimerCounter(void)
{
}

void TimerCounter::Start()
{
    QueryPerformanceCounter(&startCount);//��ʼ��ʱ
}

void TimerCounter::Stop()
{
    QueryPerformanceCounter(&endCount);//ֹͣ��ʱ

    dbTime=((double)endCount.QuadPart-(double)startCount.QuadPart)/(double)freq.QuadPart;//��ȡʱ���

	printf("%lfms\n", dbTime * 1000);

	FILE *fp;
	fp=fopen("time.log","a+");
	fprintf(fp, "%lfms\n", dbTime*1000);
	fclose(fp);
}
