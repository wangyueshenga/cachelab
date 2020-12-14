#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <getopt.h>
#include <string.h>

int h, v, s, E, b, S; // 这个是我们模拟的参数，为了方便在函数里调用，设置成全局


int hit_count,
    miss_count,
    eviction_count; // 三个在 printSummary 函数中的参数，需要不断更新


char t[1000]; // 存 getopt 中选项内容，表示的是验证中需使用的trace文件名


typedef struct
{
    int valid_bits;
    int tag;
    int stamp;
} cache_line, *cache_asso, **cache; // cache 模拟器的结构。由合法位、标记位和时间戳组成

cache cache_ = NULL; // 声明一个空的结构体类型二维数组,模拟缓存




void printUsage();// 打印 helper 内容的函数，-h 命令使用，内容可自定义

void init_cache();// 初始化cache的函数

void update(unsigned int);

void update_stamp();

void parse_trace()