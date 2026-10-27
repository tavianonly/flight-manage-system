#include "flight.h"

typedef struct User_node//登录账号密码链表
{
    struct User_node *next;//指向下一个结构体
    struct User_node *pre;//指向上一个
    char user_name[50] ;//用户名；
    char password[50] ;//密码

}User_node_x,*User_node_p;

/* 创建普通用户节点 */
User_node_p create_user_node(const char *name, const char *password)
{
    User_node_p newNode =
        (User_node_p)malloc(sizeof(User_node_x));

    if (newNode == NULL)
    {
        printf("内存分配失败！\n");
        return NULL;
    }

    /* 用户名和密码数组的容量都是 50 */
    strcpy(newNode->user_name, name);
    strcpy(newNode->password, password);

    newNode->next = NULL;
    newNode->pre = NULL;

    return newNode;
}

User_node_p creat_node(void)//创建链表入口（直接复用创建节点函数）
{
    // 头节点不需要有效账号，传空字符串
    User_node_p headnode = create_user_node("", "");
    if (headnode == NULL)
    {
        printf("内存分配失败\n");
        return NULL;
    }
    // 双向循环链表核心：头节点自环
    headnode->next = headnode;
    headnode->pre = headnode;
    return headnode;
}

User_node_p creat_head(void)//创建链表入口
{
    return creat_node();
}

int user_register(User_node_p head)//用户登录界面
{
    
    User_node_p p = head->next;
    char name[50], pwd[50];
    printf("======== 用户注册 ========\n");
    printf("请输入用户名：");
    scanf("%s", name);
    printf("请输入密码：");
    scanf("%s", pwd);

   while (p !=head)
   {
     if(strcmp(p->user_name,name)==0)
     {
        printf("用户名已经存在,注册失败");
        return 0;
     }
     p = p->next;
   }
    User_node_p newnode = (User_node_p)malloc(sizeof(struct User_node));
    if(newnode == NULL)
    {
        printf("fail");
        return 0;
    }

    strcpy(newnode->user_name, name);
    strcpy(newnode->password, pwd);

    head->pre->next = newnode;
    newnode->pre = head->pre;
    newnode->next = head;
    head->pre = newnode;

    printf("注册成功");
    return 1;
}



//创建航班链表
typedef struct Flight_node
{
    struct Flight_node *next;
    struct Flight_node *pre;
    char flight_id[20];
    char start[30];
    char dest[30];
    char time[20];
    int price;
    int seat;
}Flight_node_x,*Flight_node_p;
//创建航班节点
Flight_node_p create_plane(const char *fid,const char *s,const char *d,const char *t,int p,int se)
{
    Flight_node_p new = (Flight_node_p)malloc(sizeof(struct Flight_node));
    if (p == NULL)
    {
        printf("fail");
        return 0;
    }
    strcpy(new->flight_id,fid);
    strcpy(new->start,s);
    strcpy(new->dest,d);
    strcpy(new->time,t);
    new->price = p;
    new->seat = se;
    new->next = NULL;
    new->pre = NULL;
    return new;
}
// 创建航班头节点
Flight_node_p create_plane_head(void)
{
    Flight_node_p create_plane(const char *fid,const char *s,const char *d,const char *t,int p,int se);
}


// 查询航班
void search_flight()
{
    printf("==== 查询航班 ====\n");
    printf("这里后续写遍历航班链表、按出发地/目的地查找\n");
}

// 预订机票
void book_flight()
{
    printf("==== 预订机票 ====\n");
    printf("这里后续写选航班、生成订单、扣余票\n");
}

// 查询已订机票
void show_order()
{
    printf("==== 查询已订机票 ====\n");
    printf("这里后续遍历当前用户的订单链表\n");
}

// 退订机票
void cancel_order()
{
    printf("==== 退订机票 ====\n");
    printf("这里后续找到订单删除、航班票数+1\n");
}





void login(User_node_p head)//登录后界面
{  
    char name [50],passward[50];
    printf("请输入用户名",name);
    scanf("%s",name);
    printf("请输入密码",passward);
    scanf("%s",passward);
    int flag = 0;
    User_node_p p = head->next;
    while(p != head)
    {
        if(strcmp(p->user_name, name) == 0 && strcmp(p->password, passward) == 0)
        {
            printf("账号密码正确");
            flag = 1;
            break;
        }
        p = p->next;
    }
    printf("没有该用户注册记录");
    while(flag)
    {
        int select;
        printf("\n==== 用户系统菜单 ====\n");
        printf("1. 查询航班\n");
        printf("2. 预定航班\n");
        printf("3. 查询已定航班\n");
        printf("4. 退订航班\n");
        printf("请选择：");
        scanf("%d", &select);
        switch (select)
        {
            case 1 :
            search_flight();
            break;
             case 2:
            book_flight();
            break;
             case 3:
            show_order();
            break;
             case 4:
            cancel_order();
        default:
        printf("输入错误，请重新选择");
            break;
        }



        
    }
    
}
