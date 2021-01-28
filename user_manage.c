#include"user_manage.h"

//所有的好友数组最多支持max个
static struct USER user_arr[MAX_USER];
//实际的好友数目
static int user_count = 0;
//代表通信用户本身的结构体数组
static struct USER user_self;

//好友数组初始化
void user_arr_init(int id, char* name) {
	memset(user_arr,0,sizeof(user_arr));//某一块内存中的内容全部设置为指定的值， 这个函数通常为新申请的内存做初始化工作。 
	user_count = 0;
	memset(&user_self, 0, sizeof(user_self));//对用户本身初始化
	user_self.id = id;
	strcpy(user_self.name, name);//字符串的赋值
	user_self.stat = OFF_LINE;
}

//导出好友信息
void user_info() {
	struct USER* p = user_arr, * p_end = p + user_count;
	printf("all friend info:\n userId:%d \t name:%s \t cnt:%d\n", user_self.id,
		user_self.name, user_count);
	int i = 0;
	while (p < p_end) {
		i++;
		printf("the %dth user \t name:%s \t id:%d\n", i, p->name, p->id);
		p++;
	}
	printf("\n");
}

//查找好友
struct USER* user_find(char* name) {
	struct USER* p = user_arr, * p_end = p + user_count;
	while (p<p_end)
	{
		if (strcmp(p->name, name)==0) {
			//printf("%s", p->name);
			break;
		}
		p++;
	}
	//printf("%s", p->name);
	
	return (p == p_end) ? NULL : p;
}

//排序好友by name 选择排序
void user_sort(struct USER *p) {
	int i, j, index;
	struct USER temp;
	for (i = 0; i < user_count - 1; i++) {
		index = i;
		for (j = i + 1; j < user_count; j++) {
			if (strcmp(user_arr[j].name, user_arr[index].name) < 0) {
				index = j;
			}
		}
		if (index != i) {
			temp = user_arr[index];
			user_arr[index] = user_arr[i];
			user_arr[i] = temp;
		}
	}
}

//增加好友 0 成功 -1失败
int user_add(int uid, char* name) {
	struct USER* p, * user;
	//判断好友id合法
	//好友数目不能超过上限
	if (!uid  || uid == user_self.id || user_count == MAX_USER) {
		return -1;
	}
	//好友不能已经是好友了
	if ( user_find(name) != NULL) {
		return -1;
	}
	//添加好友
	p = &user_arr[user_count];
	p->id = uid;
	strcpy(p->name, name);
	p->stat = OFF_LINE;
	user_count++;
	return 0;
}
//删除好友
int user_delete(char* name) {
	struct USER* p, * user,*p_end=user_arr+user_count;
	//查找是否在好友列表
	if ((user = user_find(name)) == NULL) {
		return -1;
	}
	//现在user已指向目标
	p = user + 1;
	while (p<p_end)
	{
		*user = *p++;
	}
	memset(p - 1, 0, sizeof(*p));
	user_count--;
	return 0;
}

//
void user_add_test() {
	
	user_add(10002, "tom2");	
	user_add(10003, "tom3");
	user_add(10004, "tom4");
	user_add(10005, "tom5");
	user_add(10001, "tom1");
}

void user_delete_test() {
	user_delete("tom5");
	user_delete("tom1");
	user_delete("tom2");
}