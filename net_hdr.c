#include"net_hdr.h"

void socklib_init()//负责加载sock库
{
	WSADATA wsa_data;
	int ret;

	if ((ret = WSAStartup(MAKEWORD(2, 2), &wsa_data)) != 0) {
		printf("WSAStartup load failed!\n");
		exit(-1);
	}


}

void sock_cleanup(int fd)//对sock库进行清理
{
	closesocket(fd);
	WSACleanup();
}