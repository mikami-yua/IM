//#define _CRT_SECURE_NO_WARNINGS //可以使用scanf函数 
#include<stdio.h>
#include<string.h>

#define MAX_MSG_LEN 512

void encode(char* msg,int key) {
	
	

	for (int i = 0; msg[i]; i++) {
		if (msg[i] >= 'a' && msg[i] <= 'z') {
			msg[i] = (msg[i] + key > 'z') ? (msg[i] + key - ('z' - 'a' + 1)) : (msg[i] + key);
		}
		else if (msg[i] >= 'A' && msg[i] <= 'Z') {
			msg[i] = (msg[i] + key > 'Z') ? (msg[i] + key - ('Z' - 'A' + 1)) : (msg[i] + key);
		}
		else {
			continue;
		}
	}
}

void decode(char* msg, int key) {
	for (int i = 0; msg[i]; i++) {
		if (msg[i] >= 'a' && msg[i] <= 'z') {
			msg[i] = (msg[i] - key < 'a') ? (msg[i] - key + ('z' - 'a' + 1)) : (msg[i] - key);
		}
		else if (msg[i] >= 'A' && msg[i] <= 'Z') {
			msg[i] = (msg[i] - key < 'A') ? (msg[i] - key + ('Z' - 'A' + 1)) : (msg[i] - key);
		}
		else {
			continue;
		}
	}
}

int main() {
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

	return 0;
}