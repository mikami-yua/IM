//#define _CRT_SECURE_NO_WARNINGS //可以使用scanf函数 
#define _WINSOCK_DEPRECATED_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<WinSock2.h>//网络编程需要的库

#include"user_manage.h"
 
#pragma comment(lib,"Ws2_32.lib")//动态连接到这个库 Ws2_32.lib win sock编程必须的库

int main(int argc,char **argv[]) {
	/*加解密
	char msg[MAX_MSG_LEN];
	int key = 3;//ASCII码的偏移加密
	//获取用户的消息
	printf("please input msg:");

	fflush(stdin);
	fgets(msg, sizeof(msg) / sizeof(char), stdin);
	printf("\n");
	printf("please input key:");
	scanf_s("%d", &key);

	if (key < 1 || key>10) {
		key = 3;
	}
	//去掉多余的换行符
	if (msg[strlen(msg) - 1] == '\n') {
		msg[strlen(msg) - 1] = '\0';
	}
	printf("\nbefore encrypt msg:\n%s\nkey=%d\n", msg, key);
	encode(msg, key);
	
	printf("\nafter encrypt msg:\n%s\n", msg);


	//解密
	decode(msg, key);
	printf("\nafter decrypt msg:\n%s\n", msg);
	*/
	/*好友管理
	//用户相关
	struct USER* user;
	//初始化
	user_arr_init(1, "brend");
	printf("=========================\n");
	user_add_test();
	user_info();
	user = user_find("tom3");
	if (user) {
		printf("%d \t %s \n", user->id, user->name);
	}
	else
	{
		printf("cannot find\n");
	}
	user_sort(NULL);
	user_info();
	user_delete_test();
	user_info();
	*/
	/*
	union {//联合体共享地址空间，以最大元素的作为整个联合体的大小
		short s;
		char c[2];
	}un;
	un.s = 0x0102;
	//0x000186a0
	//低地址---------------高地址 00 01 86 a0 大段字节序存储
	//a0 86 01 00  小段字节序存储
	//网络编程要求大段字节序
	if (sizeof(short) == 2) {
		if (un.c[0] == 1 && un.c[1] == 2)
			printf("big order\n");
		else {
			printf("small order\n");
		}
	}
	//需要转换为大段字节序，为了避免网络通信出现歧义
	//u_long ntohl(u_long netlong)//net to host long
	//u_short ntohs(u_short netshort)
	//htonl  htons  四个函数
	//main函数的参数值
	for (int i = 0; i < argc; i++) {
		printf("argument%d:%s\n", i, argv[i]);//argument0:E:\c_project\IM\Debug\IM.exe
	}
	*/
	//把用户输入的点分10进制ip地址转换为一个无符号的整型数
	WSADATA wsa_data;
	int ret;
	unsigned long ul_addr = INADDR_NONE;

	//希望用户输入ip地址
	if (argc != 2) {//第一个参数是执行路径，第二个参数是ip地址
		printf("usage:%s<IPV4 address> \n", argv[0]);
		return -1;
	}
	ret = WSAStartup(MAKEWORD(2, 2), &wsa_data);//按照2.2的版本 分给wsa_data  正常返回0
	if (ret != 0) {
		printf("start failed!\n%d",ret);
		return -1;
	}
	ul_addr = inet_addr(argv[1]);
	if (ul_addr == INADDR_NONE || ul_addr == INADDR_ANY) {//没拿到或者少输入了
		printf("inet_addr failed and return error!\n");
		WSACleanup();
		return -1;
	}
	printf("inet_addr return success!\n");


	WSACleanup();//完成winsock库的清理工作
	//所用使用winsock编程的都必须使用这两个库进行初始化和清理

	return 0;
}