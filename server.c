#include"net_hdr.h"
//服务器端

/*监听socket

sever_socket_init(); 创建描述符，初始化邦定
sever_main_loop(); 处理主循环
main();

*/

int server_sock_init(short SERVER_PORT) {
	struct sockaddr_in serveraddr;
	int ret, fd;

	if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("socket error with code: %d\n", fd);
		exit(-1);
	}
	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(SERVER_PORT);

	if ((ret = bind(fd, &serveraddr, sizeof(serveraddr))) < 0) {
		printf("bind return error\n");
		exit(-2);
	}

	if ((ret = listen(fd, 10)) < 0) {
		printf("listen return error\n");
		exit(-3);
	}

	return fd;
}

void server_main_loop(int listenfd) {
	int connfd, n;
	socklen_t len;
	struct sockaddr_in cliaddr;
	char buff[MAX_LINE];

	while (1)
	{
		len = sizeof(cliaddr);
		printf("waitting for client's connection...\n");
		connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &len);
		printf("connection form %s ,port is %d \n", inet_ntop(AF_INET, &cliaddr.sin_addr
			, buff, sizeof(buff), ntohs(cliaddr.sin_port)));
		
		while ((n=recv(connfd,buff,MAX_LINE,0))>0)
		{
			send(connfd, buff, n, 0);//接收到有东西，原封不动的返回客户端
		}
		closesocket(connfd);
	}
}

int server_startup() {
	int listenfd;
	socklib_init();
	listenfd = server_sock_init(10056);
	server_main_loop(listenfd);

	sock_cleanup(listenfd);

	return 0;
}