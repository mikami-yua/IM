#ifndef NET_HDR_H
#define NET_HDR_H
//这个里包含了以后所有网络编程的公共头文件和宏定义
#include<WinSock2.h>
#include<stdio.h>
#include<windows.h>
#include<WS2tcpip.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#pragma comment(lib,"Ws2_32.lib")

#define MAX_LINE 80//定义字节流的长度80字节

#define  unsigned short u_short


#endif // !NET_HDR_H



