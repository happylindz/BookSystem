#include "Header.h"

/*----------------------图书信息管理系统登入界面-------------------------------*/


int main(int argc, const char * argv[]) {
 
    int choice;
    
    
    printf("*************************\n\n");
    printf("    欢迎来到图书管理系统    \n\n");
    printf("*************************\n");
    
//    userLogin();
    
    
    printf("-------------------------------\n");
    while (1) {                                        //一级选项循环
        
        printf("请选择:(按回车确认)\n");                  //输入提示
        printf("1:图书信息管理\n");
        printf("2:读者信息管理\n");
        printf("3.密码修改\n");
        printf("4:注册账户\n");
        printf("5.帮助\n");
        printf("0:退出\n");
        
        
        
        scanf("%d",&choice);
        if (choice == 1) {                              //选项1为图书管理信息系统
            
            printf("您已登入图书管理信息\n");
            struct book *head = bookCreate();
            
            switch (menu1()) {
                case 1:
                    bookDisplay(head);                //图书信息展示
                    break;
                case 2:
                    bookSearch(head);                 //图书信息检索
                    break;
                case 3:
                    bookAdd(head);                    //添加图书信息记录
                    break;
                case 4:
                    bookDelete(head);                 //删除图书信息记录
                    break;
                case 5:
                    bookEmpty(head);                  //清空图书信息记录
                    break;
                case 0:
                    break;
            }
            
            
        }else if(choice == 2){                       //选项2为读者管理信息系统
            
            
            printf("您已登入读者管理信息\n");
            struct book *head = bookCreate();
            
            switch (menu2()) {
              
                case 1:
                    bookBorrow(head);                  //图书借阅记录
                    break;
                case 2:
                    bookReturn(head);                 //图书归还记录
                    break;
                case 3:
                    readerDisplay();
                    break;
                case 0:
                    break;
           
            }
            
            
        }else if (choice == 0){
            
            printf("感谢使用!\n");                  //退出系统
            break;
            
        }else if (choice == 3){
            
            passwordChange();                         //密码修改
            
        }else if (choice == 4){
            
            userRegister();
        
        }else if (choice == 5){                        //账号注册
         
            helpWord();
            getchar();
            printf("按回车确认:");
            getchar();
        
        }
        else{
            
            printf("输入有误.\n");
            
        }
        
    }
    
}
