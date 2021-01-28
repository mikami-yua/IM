#pragma once

#ifndef user_manage.h
#define user_manage

#include<stdio.h>
#include<string.h>

#define MAX_USER 50
#define OFF_LINE 0
#define ON_LINE 1
#define MAX_NAME_LEN 32

struct USER
{
	char name[MAX_NAME_LEN];
	int id;
	int stat;//在线状态
};

void user_arr_init(int id, char* name);

//增加好友 0 成功 -1失败
int user_add(int uid, char* name);

int user_delete(char* name);

//排序好友
void user_sort(struct USER* p);

//查找好友
struct USER* user_find(char* name);

//导出好友信息
void user_info();

//test函数
void user_add_test();
void user_delete_test();



#endif // !user_manage.h  避免重复导入这个文件