#ifndef CHAT_LOG_H

#define CHAT_LOG_H

/*
聊天记录的结构
	发送者	
	接收者
	发送时间
	内容

文本文件保存

功能存储，导入导出
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

#define MAXLINE 512 //支持最大的消息长度
#define FILED_SEPS "/" //消息分隔符
#define MSG_FIELDS 4 //每行的字段个数

//备份单个消息
void back_single_msg(char *msg,int from,int to,FILE *fp);
//导出消息备份
void export_msg_from_to_sb(FILE *sfp,FILE *dfp,int from,int to);



#endif // !CHAT_LOG_H
