#include <stdio.h>
#include <stdlib.h>
int main()
{
	//如果没有输入时间参数项，程序将一直运行，需要手动 killall 结束运行

	// pressure 程序占用内存50MB，压力状态维持360s，后台运行
	system("/tmp/upgrade/pressure -m50 -t360 &");
	
	// pressure 程序占用 CPU 50%，压力状态维持360s，后台运行
	system("/tmp/upgrade/pressure -p50 -t360 &");
	
	// pressure 程序占用内存50MB，同时占用 CPU 25%，压力状态维持360s，后台运行
	system("/tmp/upgrade/pressure -m50 -p25 -t360 &");
	
	//版本信息
	system("/tmp/upgrade/pressure -v");
	
	//帮助信息
	system("/tmp/upgrade/pressure -h");
	
	//帮助信息
	system("/tmp/upgrade/pressure -?");

	//主动结束 pressure 程序
	system("killall pressure");
	
	exit(0);
}
