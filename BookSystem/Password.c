#include "Header.h"

/*-----------------用户登入-------------------*/

void userLogin(){
  
    char userID[20],password[20],user[20];                //用于输入系统账户及密码
    char systemID[20],systemPassword[20];                 //用于调用文件中存储的账号密码
    FILE *fp;
    int i=1;
    
password:
    
    printf("请输入图书管理账号:(按回车继续)\n");            //输入管理的账户和密码
    scanf("%s",userID);
    printf("请输入图书管理密码:(按回车继续)\n");
    scanf("%s",password);
    
    while (1) {
        
        sprintf(user, "password(%d).txt",i);                    //拼接文件名，对文件名进行遍历
        fp = fopen(user, "r");
        if ((fp = fopen(user, "r"))!=NULL){
            
            fscanf(fp, "%s %s",systemID,systemPassword);            //键盘读取账号密码
            
            if (strcmp(password, systemPassword)==0&&strcmp(userID, systemID)==0) {//进行校对，校对成功则进入系统
               
                break;
           
            }
        
        }
        if ((fp = fopen(user, "r"))==NULL) {                      //当找完所有文件后无匹配后就报错

            printf("密码输入有误，请重新输入:\n");
            i=1;
            goto password;
        
        }
        i++;
        
    }
    printf("登入成功.\n");

}


/*-----------------密码修改-------------------*/

void passwordChange(){
    
    FILE *fp;
    
    char password[20],userID[20];                       //用于键盘输入的账号密码
    char systemPassword[20],systemID[20];               //用于读取文件中的账号密码
    char user[20];                                      //用来打开密码文件的文件名
    int i=1;
    
//    fscanf(fp, "%s %s",userID,password);                 //从文件中读取旧密码

password:
    
    printf("请输入账号:(按回车确认)\n");                 //输入账号密码
    scanf("%s",userID);
    printf("请输入旧密码:(按回车确认)\n");
    scanf("%s",password);

    while (1) {
        
        sprintf(user, "password(%d).txt",i);
        
        if ((fp = fopen(user, "r"))!=NULL){
            
            fscanf(fp, "%s %s",systemID,systemPassword);            //键盘读取账号密码
            
            if (strcmp(password, systemPassword)==0&&strcmp(userID, systemID)==0) {
                break;
                
            }
            
        }
        if ((fp = fopen(user, "r"))==NULL) {                    //遍历文件后找不到匹配项则报错
            
            printf("输入有误，请重新输入:\n");
            i=1;
            goto password;
            
        }
        i++;
        
    }
    
    
    
    fp = fopen(user, "w");
    printf("请输入您要修改的密码:(按回车结束)\n");           //输入新密码
    scanf("%s",password);
    
    
    fprintf(fp, "%s %s",userID,password);                    //将新密码保存在文件中
    printf("密码修改成功.\n");
    
    fclose(fp);
    
}



/*-----------------用户注册-------------------*/

void userRegister(){
    
    char userID[20],password[20],user[20];
    FILE *fp;
    int i=1;
    
    printf("-------------------------------\n");
    printf("请输入新建管理账号:(按回车结束)\n");               //输入管理的账户和密码
    scanf("%s",userID);
    printf("请输入新建管理密码:(按回车结束)\n");
    scanf("%s",password);
    
    do{
     
        sprintf(user, "password(%d).txt",i);
        i++;

    }while((fp = fopen(user, "r"))!=NULL);                    //先遍历判断已注册的账号密码

    
    if ((fp = fopen(user, "r"))==NULL) {
        
        fp = fopen(user, "w");                                //创建写入新账号密码的文件
        
        fprintf(fp, "%s %s",userID,password);                 //输入新注册的账户信息
        printf("新用户创建成功\n");
        printf("-------------------------------\n");

        fclose(fp);

    }

}


