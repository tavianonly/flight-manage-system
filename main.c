#include "flight.h"


int main(void)
{
    // 1. 创建双向循环链表表头
    User_node_p head = creat_head();
    if (head == NULL)
    {
        printf("链表表头创建失败！\n");
        return -1;
    }

    int select;
    while (1)
    {
        printf("\n==== 用户系统菜单 ====\n");
        printf("2. 用户登录\n");
        printf("1. 用户注册\n");
        printf("0. 退出程序\n");
        printf("请选择：");
        scanf("%d", &select);

        switch (select)
        {
            case 2:
                login(head);
                break;

            case 1:
                user_register(head);
                break;
            case 0:
                printf("程序退出\n");
                return 0;
            default:
                printf("输入错误，请重新选择！\n");
                break;
        }
    }
    return 0;
}
