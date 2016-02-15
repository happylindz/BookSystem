#include "Header.h"

/*----------------------图书管理菜单登入界面-------------------------------*/


int menu1(){
    
    int choice;
    
    printf("\n\n请选择数字进行操作(按回车确认)\n");
    printf("-------------------------\n");
    printf("1:显示所有图书\n");
    printf("2:查看指定图书\n");
    printf("3:添加图书信息记录\n");
    printf("4:删除图书信息记录\n");
    printf("5:清除所有图书记录\n");
    printf("0:退出\n");
    printf("-------------------------\n");
    printf("请选择:");
    
    
    while (1) {
        
        scanf("%d",&choice);                   //选择选项
        
        if (choice == 1) {
            return 1;
        }else if (choice == 2){
            return 2;
        }else if (choice == 3){
            return 3;
        }else if(choice == 4){
            return 4;
        }else if (choice == 5){
            return 5;
        }else if(choice == 0){
            printf("感谢您的使用。");
            return 0;
        }else{
            printf("输入有误,请重新输入:\n");
        }
        
        
    }
    
    
    return 0;
    
}
int menu2(){
    int choice;
    
    
    printf("\n\n请选择数字进行操作(按回车确认)\n");
    printf("-------------------------\n");
    printf("1:图书借阅记录\n");
    printf("2:图书归还记录\n");
    printf("3:显示所有读者信息\n");
    printf("0:退出\n");
    printf("-------------------------\n");
    printf("请选择:");
    
    
    while (1) {
        
        scanf("%d",&choice);                   //选择选项
        
        if (choice == 1) {
            return 1;
        }else if (choice == 2){
            return 2;
        }else if(choice == 3){
            return 3;
        }else if (choice == 0){
            printf("感谢您的使用。");
            return 0;
        }else{
            printf("输入有误,请重新输入:\n");
        }
        
    }
    
    return 0;
    
}
