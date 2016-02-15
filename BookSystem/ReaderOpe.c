#include "Header.h"

/*----------------------读者信息管理系统-------------------------------*/


/*-------------------读者信息录入--------------------*/
void bookBorrow(struct book *head){
    
    struct book book[NUM];
    int i=0;
    FILE *fp,*fp1;
    char stuName[20],bookName[20],reader[20];                //定义学生姓名，书名，文件名
    char choice1,choice2;                                    //定义选择按钮
    int stuID,bookID,stuNum=1;                               //定义学生学号，图书编号以及记录学生次数
    struct book bookInNeed;                                  //定义存储书的结构体
    
    
    fflush(stdin);
    
    printf("请输入借书人名字:\n");                       //输入借书人的信息
    scanf("%s",stuName);
    printf("请输入借书人学号:\n");
    scanf("%d",&stuID);
    
    fp = fopen("Reader(1).txt", "r");
    do{

        fscanf(fp, "%s %d",stuInformation.name,&stuInformation.id);     //从文件中读取个人信息

        if ((strcmp(stuName, stuInformation.name)==0)||stuID==stuInformation.id) {

            printf("已找到身份信息.\n");             //在文件中搜索借书人，找到就输出
            printf("以下是您已借阅的书籍.\n");
            printf("-------------------------------------------------------\n");
            printf("书名         作者         编号        出版社     \n");
            while (!feof(fp)) {
                fscanf(fp, "\n%s %s %d %s %d",book[i].name,book[i].author,&book[i].number,book[i].press,&book[i].ok);
                printf("%-12s%-12s%-12d%-12s\n",book[i].name,book[i].author,book[i].number,book[i].press);//找到则输出图书信息
                i++;
            }
            printf("-------------------------------------------------------\n");

            fclose(fp);
            break;

        }
        
        stuNum++;
        sprintf(reader, "Reader(%d).txt",stuNum);

    }while((fp = fopen(reader, "r"))!=NULL);
    
    sprintf(reader, "Reader(%d).txt",stuNum);            //拼接字符串,创建文件名
    
    if ((fp = fopen(reader, "r"))==NULL) {               //在文件中找不到借书人，则重新创建文件

        sprintf(reader, "Reader(%d).txt",stuNum);
        fp = fopen(reader, "w");
    
        fprintf(fp, "%s %d",stuName,stuID);
        printf("已存储个人信息!\n");
     
        fclose(fp);

    }
    
    
    printf("按回车键继续:");
    getchar();
    getchar();
    
    
    bookDisplay(head);
    
book1:                                                     //标签图书1,用于重新还书位置确认
 
    do{
        
        fp1 = fopen("books.txt", "r+");
        printf("请输入借阅的书名;(按回车结束)\n");                       //输入要借阅的图书信息
        scanf("%s",bookName);
        printf("请输入借阅图书编号:(按回车借书)\n");
        scanf("%d",&bookID);
        
        while(1){

            fscanf(fp1,"\n%s %s %d %s %d",bookInNeed.name,bookInNeed.author,&bookInNeed.number,bookInNeed.press,&bookInNeed.ok);                              //从文件中读取图书信息

            if (strcmp(bookInNeed.name, bookName)==0) {

                printf("-------------------------------------------------------\n");
                
                printf("书名         作者         编号        出版社       状态 \n");
                printf("%-12s%-12s%-12d%-12s",bookInNeed.name,bookInNeed.author,bookInNeed.number,bookInNeed.press);
                
                if (bookInNeed.ok == 1) {                          //判断图书是否借出
                    printf("已借出\n");
                }else if(bookInNeed.ok == 2){
                    printf("在架待借\n");
                }else{
                    printf("错误\n");
                }
                
                printf("-------------------------------------------------------\n");
            
                break;
            
            }
            
            if (feof(fp1)) {                                  //如果在文件中搜索不到文件信息
                
                printf("你所需要的书可能已被借走或不存在,请重新选择操作:\n");
                printf("1:重新输入书名:\n");
                printf("2:下次再来。\n");
                int bookChoice;
            book2:                                         //标签图书2，用于重新输入选择确认
                
                scanf("%d",&bookChoice);
                
                
                if(bookChoice==1) {                         //判断选项
                    
                    goto book1;                             //返回重新输入正确的书
                    
                }else if(bookChoice==2){
                    
                    exit(0);                                 //退出系统
                    
                }else{
                    
                    printf("输入有误,请重新输入:");              //输入信息有误
                    goto book2;
                    
                }
                
            }
        }
        
        getchar();
        printf("请问是否需要?(Y|N)(按回车结束)\n");
        scanf("%c",&choice1);                             //判断选项，判断是否借书

        if (choice1 == 'Y'||choice1 == 'y') {
            
            fp = fopen(reader, "a");
           
            fprintf(fp, "\n%s %s %d %s %d",bookInNeed.name,bookInNeed.author,bookInNeed.number,bookInNeed.press,bookInNeed.ok);                     //将图书信息写入读者文件
           
            bookStateChange(1, head, bookName);            //改变图书借阅状态
            printf("借书成功\n");
            
        }
        
        getchar();
        
        printf("请问还需要继续借书么?(Y|N)(按回车确认)\n");
        scanf("%c",&choice2);                              //判断是否继续借书
        
        fclose(fp1);
        fclose(fp);
        
    }while(choice2=='Y'||choice2=='y');

}



/*---------------读者信息删除------------------------*/

void bookReturn(struct book *head){
    
    struct book books[NUM];
    char stuName[20],bookName[20],reader[20];           //定义学生姓名，书名，读者文件名
    char choice1,choice2;                               //定义两个选择按钮
    int stuID,bookID,stuNum = 1;                        //定义学生学号，图书编号和用于记录文件名编号
    int i = 0,bookCount,bookNum = 0;                    //定义图书总数和用于记录图书在文件中的位置变量
    
    FILE *fp;
    
book:
 
    printf("请输入借书人名字:\n");                       //输入借书人的信息
    scanf("%s",stuName);
    printf("请输入借书人学号:\n");
    scanf("%d",&stuID);
    fp = fopen("Reader(1).txt", "r");
    
    do{
        
        fscanf(fp, "%s %d",stuInformation.name,&stuInformation.id);     //从文件中读取个人信息
        
        if ((strcmp(stuName, stuInformation.name)==0)||stuID==stuInformation.id) {
            
            printf("已找到身份信息.\n");             //在文件中搜索借书人，找到就输出
            printf("-------------------------------------------------------\n");
            printf("以下是您已借阅的书籍.\n");
            printf("书名         作者         编号        出版社     \n");
            while (!feof(fp)) {
                fscanf(fp, "\n%s %s %d %s %d",books[i].name,books[i].author,&books[i].number,books[i].press,&books[i].ok);
                printf("%-12s%-12s%-12d%-12s\n",books[i].name,books[i].author,books[i].number,books[i].press);//找到则输出图书信息
            }
            printf("-------------------------------------------------------\n");

            fclose(fp);
            break;
            
        }
        
        stuNum++;
        sprintf(reader, "Reader(%d).txt",stuNum);
        
    }while((fp = fopen(reader, "r"))!=NULL);             //循环直到已无reader文件
    
    
    sprintf(reader, "Reader(%d).txt",stuNum);            //拼接字符串,创建文件名
    
    
    if ((fp = fopen(reader, "r"))==NULL) {               //在文件中找不到借书人，报错
       
        printf("找不到该人信息!\n");
        printf("请重新输入信息:\n");

        stuNum = 1;
        fclose(fp);
        
        goto book;                                       //用于返回重新输入学生信息

    }

    do{
        
        fp = fopen(reader, "r+");                        //读写上述找到学生信息的文件
        
        i = 0;
        printf("请输入归还图书书名:\n");                    //输入要归还的图书信息
        scanf("%s",bookName);
        printf("请输入归还图书编号:\n");
        scanf("%d",&bookID);
        
        while (!feof(fp)) {
            fscanf(fp, "\n%s %s %d %s %d",books[i].name,books[i].author,&books[i].number,books[i].press,&books[i].ok);
            i++;
        }
        bookCount = i;                                              //bookCount记录图书总数
        for (i = 1; i < bookCount; i++) {
            if ((strcmp(bookName,books[i].name)==0)||bookID==books[i].number) {
                
                bookNum = i;
                printf("-------------------------------------------------------\n");

                printf("已找到你所归还的图书!\n");
                printf("\n书名         作者         编号        出版社      \n");
                printf("%-12s%-12s%-12d%-12s\n",books[i].name,books[i].author,books[i].number,books[i].press);//找到则输出图书信息
            
                printf("-------------------------------------------------------\n");

                fclose(fp);
                break;
            }
        }
        
        getchar();
        printf("请问确认要归还?(Y|N)(按回车确认)\n");
        scanf("%c",&choice1);
       
        if (choice1=='Y'||choice1=='y') {                               //确认是否归还
           
            fp = fopen(reader, "w");                                    //重写读者信息
            fprintf(fp, "%s %d",stuName,stuID);                         //重新写入读者的姓名学号
            
            for(i=1;i<bookCount;i++) {                                 //重新写入还在借阅的书
              
                if (i == bookNum) {                                      //遇到归还的书则跳过
                    continue;
                }
                
                fprintf(fp, "\n%s %s %d %s %d",books[i].name,books[i].author,books[i].number,books[i].press,books[i].ok);
                
            }
        
            bookStateChange(2, head, bookName);                          //改变图书的状态
        
        }
        fclose(fp);
        getchar();
        printf("请问是否继续归还图书?(Y|N)(按回车确认)\n");
        scanf("%c",&choice2);
        
    }while(choice2=='Y'||choice2=='y');
    
    
}


/*----------------读者信息显示---------------------*/

void readerDisplay(){
    
    struct book books[NUM];                                           //用于读取文件中的图书信息
    char stuName[20];                                                 //用于输入学生姓名
    char reader[20];                                                  //用于创建文件名
    int i=0,num=1,booksCount,booksBegin=0,stuID;                      //定义了图书总数，图书起点记录和学生学号
    FILE *fp;
    
    sprintf(reader, "Reader(%d).txt",num);
    fp = fopen(reader, "r");
    
    do{
        
        printf("\n读者(%d):\n",num);
        fscanf(fp, "%s %d",stuName,&stuID);                           //读取读者的个人信息
       
        while (!feof(fp)) {                                           //读取某同学的借阅图书信息
           
            fscanf(fp, "%s %s %d %s %d\n",books[i].name,books[i].author,&books[i].number,books[i].press,&books[i].ok);
            i++;

        }
        
        booksCount = i;
        printf("-------------------------------------------------------\n");
        printf("姓名\t\t  学号\n");
        printf("%-10s%-10d\n",stuName,stuID);                          //输出读者个人信息
        printf("其借阅%d本书\n",booksCount-booksBegin);
        printf("\n书名         作者         编号        出版社        \n");
        
        for (i = booksBegin; i<booksCount; i++) {                      //输入读者借阅图书信息
            
            printf("%-12s%-12s%-12d%-12s\n",books[i].name,books[i].author,books[i].number,books[i].press);
            
        }
        
        printf("-------------------------------------------------------\n");
        num++;
       
        sprintf(reader, "Reader(%d).txt",num);
        fclose(fp);
       
        booksBegin = i;
        
    }while ((fp = fopen(reader, "r"))!=NULL);                           //读取读者信息直到无文件可读

    
}



/*----------------图书状态更改---------------------*/


void bookStateChange(int ok,struct book *head,char bookName[]){
    
    struct book *passPoint = head;
    FILE *fp;
    fp = fopen("books.txt", "r+");                         //打开books.txt文件
    
    while (passPoint!=NULL) {
        
        if (strcmp(passPoint->name, bookName)==0) {        //找到该书在链表中的位置
            
            passPoint->ok = ok;                             //找到位置后将数据修改
            
        }
        
        passPoint = passPoint->next;
        
    }
    
    
    fclose(fp);
    fp = fopen("books.txt", "w");                               //重写books.txt文件

    passPoint = head;
    
    while (passPoint!=NULL) {
        
        fprintf(fp, "\n%s %s %d %s %d",passPoint->name,passPoint->author,passPoint->number,passPoint->press,passPoint->ok);                                   //将内存中的数据重新写入文件
        
        passPoint = passPoint->next;
        
    }
    fclose(fp);
    
}

