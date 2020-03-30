//#include "StdAfx.h"
#include <iostream>

#include <windows.h>


class TimerCounter
{
public:
	TimerCounter(void);//构造函数
	~TimerCounter(void);//析构函数

private:
	LARGE_INTEGER startCount;//记录开始时间

	LARGE_INTEGER endCount;//记录结束时间

	LARGE_INTEGER freq;//本机CPU时钟频率

public:
	double dbTime;//程序运行的时间保存在这里

public:
	void Start();//被测程序开始点处开始计时
	void Stop();//被测程序结束点处结束计时
};

using namespace std;
TimerCounter::TimerCounter(void)
{
    QueryPerformanceFrequency(&freq);//获取主机CPU时钟频率
}

TimerCounter::~TimerCounter(void)
{
}

void TimerCounter::Start()
{
    QueryPerformanceCounter(&startCount);//开始计时
}

void TimerCounter::Stop()
{
    QueryPerformanceCounter(&endCount);//停止计时

    dbTime=((double)endCount.QuadPart-(double)startCount.QuadPart)/(double)freq.QuadPart;//获取时间差

	printf("%lfms\n", dbTime * 1000);

	FILE *fp;
	fp=fopen("time.log","a+");
	fprintf(fp, "%lfms\n", dbTime*1000);
	fclose(fp);
}
