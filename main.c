#include"chat_log.h"

int main(int argc, char** argv[]) {
	FILE* fp;
	char* msg_simple[] = {
		"Whatever is worth doing is worth doing well.",
		"Happiness is a way station between too much and too little.",
		"In love folly is always sweet.",
		"The hard part isn’t making the decision. It’s living with it.",
		"Your happy passer-by all knows, my distressed there is no place hides.",
		"You may be out of my sight, but never out of my mind.",
		"Love is not a maybe thing. You know when you love someone.",
		"In the end, it’s not the years in your life that count. It’s the life in your years.",
		"When the whole world is about to rain, let’s make it clear in our heart together.",
		"I’ll think of you every step of the way."
	};
	if (argc != 2) {
		printf("usage %s <save file>\n",argv[0]);
		return -1;
	}
	if ((fp = fopen(argv[1], "a+")) == NULL) {
		perror("open file error!");
		return -2;
	}

	for (int i = 0; i < sizeof(msg_simple) / sizeof(char*); i++) {
		back_single_msg(msg_simple[i], 10000, 10001, fp);
	}
	rewind(fp);//文件指针的偏移量归零
	export_msg_from_to_sb(fp, stdout, 10000, 10001);
	return 0;
}