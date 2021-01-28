#define _CRT_SECURE_NO_WARNINGS //可以使用scanf函数 
#define USERNAME "user1"
#define PASSWD "passwd1"

#define USER1 10001
#define PASSWD1 "apple"

#define USER2 10002
#define PASSWD2 "banana"

#define USER3 10003
#define PASSWD3 "cat"
int user;
char passwd[40];

int checkForSingle(char* name, char* passwd) {
	/*printf("please input username:");
	scanf("%s", name);
	printf("\n");
	printf("please input password:");
	scanf("%s", passwd);*/

	//判断是否合法
	if (strcmp(name, USERNAME) != 0) {
		printf("username is not right!\n");
		return -1;
	}

	//判断密码是否正确
	if (strcmp(passwd, PASSWD) != 0) {
		printf("password is not right!\n");
		return -1;
	}

	printf("login in success!\n");
}

int check_for_users(int user,char* passwd) {
	
	int result = -1;//0成功 其他失败
	//printf("please input username:");
	//scanf("%d", &user);//不是数组需要取地址
	//printf("\n");
	//printf("please input password:");
	//scanf("%s", passwd);
	switch (user)
	{
	case 10001:
		result = strcmp(passwd, PASSWD1);
		break;

	case 10002:
		result = strcmp(passwd, PASSWD2);
		break;

	case 10003:
		result = strcmp(passwd, PASSWD3);
		break;
	default:
		result = -1;
		break;
	}
	if (result == 0) {
		printf("login in success!\n");
	}
	else
	{
		printf("login in fail!\n");
	}

	return result;
}
