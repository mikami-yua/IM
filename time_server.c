#include"net_hdr.h"

int time_server() {
	
	int listenfd, connfd;//listen状态 connect状态
	socklen_t len;
	struct sockaddr_in servaddr, cliaddr;
	char buff[MAX_LINE];
	time_t ticks;
	WSADATA wsa_data;
	int ret;//以上是网络需要的变量

	if ((ret = WSAStartup(MAKEWORD(2,2), &wsa_data))!=0) {
		printf("WSAStartup load failed!\n");
		return -1;
	}

	//以下五行实现了服务器地址的填充：ip、端口的填充
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;//ipv4
	servaddr.sin_port = htons(10056);//定义端口
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);//无论什么ip服务器照单全收

	ret = bind(listenfd, &servaddr, sizeof(servaddr));//bind函数将本地地址和端口号进行绑定

	//监听
	listen(listenfd, 10);

	for (;;) {
		len = sizeof(cliaddr);
		printf("watting for client connect...\n");
		connfd = accept(listenfd, &cliaddr, &len);//接收来自客户端的连接请求，将返回一个新的socket
		//新对socket描述符用于在客户端和服务器直间通信，&cliaddr, &len返回客户端的地址结构
		printf("connected from %s ,port is %d\n", inet_ntop(AF_INET, &cliaddr, buff, sizeof(buff)), ntohs(cliaddr.sin_port));
		ticks = time(NULL);
		_snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
		send(connfd, buff, strlen(buff), 0);//把字符串发送到客户端（发送的是字符不需要考虑大小段）
		closesocket(connfd);
	}
	closesocket(connfd);
	WSACleanup();
	//TCP    0.0.0.0:10056          0.0.0.0:0              LISTENING
	return -1;
}