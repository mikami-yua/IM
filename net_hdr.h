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

/*以下内容系统中均有定义
struct sockaddr_in
{
	short sin_family;//表示该地址结构的地址簇 值有：AF_INET(ipv4) AF_INET6(ipv6)
	u_short sin_port;//地址的端口号
	struct in_addr sin_addr;//ip地址的结构
	char sin_zero[8];//保留的数据成员留作将来使用
};

struct sockaddr //比sockaddr_in更通用的地址结构
{
	u_short sa_family;
	char sa_data[14];
};


struct in_addr
{
	u_long S_addr;//根据点分10进制字符串转换而来
};
*/

#endif // !NET_HDR_H



