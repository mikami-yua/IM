#include<stdio.h>

#define USERNAME "user1"
#define PASSWD "passwd1"

int main() {
	//定义用户名和密码
	char name[40];
	char passwd[40];
	printf("please input username:");
	scanf("%s", name);
	printf("\n");
	printf("please input password:");
	scanf("%s", passwd);

	//判断是否合法
	if (strcmp(name, USERNAME) != 0) {
		printf("username is not right!\n");
		return -1;
	}

	//判断密码是否正确
	if (strcmp(passwd, PASSWD) != 0) {
		
	}

	return 0;
}
