#ifndef __FLIGHT_H
#define __FLIGHT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 结构体类型定义
typedef struct User_node
{
    struct User_node *next;
    struct User_node *pre;
    char user_name[50];
    char password[50];
}User_node_x,*User_node_p;

// 下面这一堆就是【函数声明】
User_node_p create_user_node(const char *name, const char *password);
User_node_p create_node(void);
User_node_p creat_head(void);
int user_register(User_node_p head);
void login(User_node_p head);
// 航班相关
void search_flight();   // 查询航班
void book_flight();     // 预订机票
void show_order();      // 查询已订机票
void cancel_order();    // 退订机票


#endif
