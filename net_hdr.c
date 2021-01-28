#include"net_hdr.h"

struct sockaddr_in
{
	short sin_family;//表示该地址结构的地址簇 值有：AF_INET(ipv4) AF_INET6(ipv6)
	u_short sin_port;//地址的端口号
	struct in_addr sin_addr;//ip地址的结构
	char sin_zero[8];//保留的数据成员留作将来使用
};

struct sockaddr //比sockaddr_in更通用的地址结构
{
	u_short sa_family;
	char sa_data[14];
};


struct in_addr
{
	u_long S_addr;//根据点分10进制字符串转换而来
};