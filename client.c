#include"net_hdr.h"

//创建一个socket描述符，把描述符连接到用户提供的地址结构
client_sock_init(char* addr, short SERVER_PORT) {
	int sockfd;
	struct sockaddr_in serveraddr;

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("socket error with code: %d\n", sockfd);
		exit(-1);
	}
	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(SERVER_PORT);

	//判断地址是否正确
	if (inet_pton(AF_INET, addr, &serveraddr.sin_addr) <= 0) {
		//inet_pton(AF_INET, argv[1], &servaddr.sin_addr
		printf("inet_pton error for %s\n", addr);
		closesocket(sockfd);
		exit(-2);
	}
	if (connect(sockfd, &serveraddr, sizeof(serveraddr)) < 0) {
		printf("connect error for %s\n", addr);
		closesocket(sockfd);
		exit(-3);
	}
	return sockfd;
}

void send_add_msg(int fd) {
	int n = 0;
	char recvline[MAX_LINE];
	char *buffs[] = { "I love this msg","Hi there!" ,"Please tell me","Do you here me"};
	for (int i = 0; i < sizeof(buffs) / sizeof(char); i++) {
		printf("send msg:%s \n", buffs[i]);
		send(fd, buffs[i], strlen(buffs[i]), 0);
		if ((n = recv(fd, recvline, MAX_LINE, 0)) > 0) {
			recvline[n] = 0;
			printf("received: %s\n", recvline);
		}
	}
}

int start_client(int argc,char *argv[]) {
	int sockfd;
	if (argc != 2) {
		printf("usage:%s <ipv4 address>\n", argv[1]);
		return -1;
	}
	socklib_init();
	sockfd = client_sock_init(argv[1], 10056);
	send_add_msg(sockfd);
	sock_cleanup(sockfd);

	return 0;
}