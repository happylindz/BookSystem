#include "Header.h"

/*----------------------图书信息管理系统-------------------------------*/


void bookDisplay(struct book *head){                     //图书信息展示
    
    struct book *temp = head;
    
    printf("\n书名         作者         编号        出版社       状态 \n");
    printf("-------------------------------------------------------\n");
    
    while (temp!=NULL) {
        
        printf("%-12s%-12s%-12d%-12s",temp->name,temp->author,temp->number,temp->press);     //输出链表
        
        if (temp->ok == 1) {                          //判断图书是否借出
            printf("已借出\n");
        }else if(temp->ok == 2){
            printf("在架待借\n");
        }else{
            printf("错误\n");
        }
        
        printf("------------------------------------------------------\n");
        temp=temp->next;                                  //连接下一个节点
        
    }
    
}




void bookSearch(struct book *head){                          //图书信息搜索
    
    FILE *fp;
    fp = fopen("books.txt", "r+");
    
    struct book *passPoint = head;
    char bookName[20];
    
    
    printf("请输入您要查看的图书:(按回车确认)\n");
    scanf("%s",bookName);                                   //键盘录入图书名
    
    
    while (passPoint!=NULL) {
        
        if (strcmp(passPoint->name, bookName)==0) {           //在链表寻找匹配的图书信息
            printf("以下是您要查询的图书:\n");
            printf("-------------------------------------------------------\n");
           
            printf("书名         作者         编号        出版社       状态 \n");
            printf("%-12s%-12s%-12d%-12s",passPoint->name,passPoint->author,passPoint->number,passPoint->press);     //输出链表
            
            if (passPoint->ok == 1) {                          //判断图书是否借出
                printf("已借出\n");
            }else if(passPoint->ok == 2){
                printf("在架待借\n");
            }else{
                printf("错误\n");
            }
            
            printf("-------------------------------------------------------\n");
            break;
            
        }
        
        passPoint = passPoint->next;
        
    }
    
    
    if (passPoint==NULL) {
        
        printf("未找到该书。\n");                        //在链表中找不到该书
        
    }
    
    
    fclose(fp);
    
}



void bookAdd(struct book *head){                                  //图书信息记录添加
    
    int addAmount;
    int i;
    
    struct book *addBook;
    FILE *fp;
    
    fp = fopen("books.txt", "a+");
    addBook = (struct book*)malloc(sizeof(struct book));             //为添加图书----分配内存
    printf("-------------------------\n");
    printf("请问需要添加几本书?\n");
    scanf("%d",&addAmount);
    
    for (i = 0; i < addAmount; i++) {
        
        printf("书名:");scanf("%s",addBook->name);
        printf("作者:");scanf("%s",addBook->author);
        printf("编号:");scanf("%d",&addBook->number);
        printf("出版社:");scanf("%s",addBook->press);
        printf("状态:(1:已借出.2:在架待借)");scanf("%d",&addBook->ok);
        
        fseek(fp, 2, 0);                                            //将光标移到文件末尾
        
        fprintf(fp, "\n%s %s %d %s %d",addBook->name,addBook->author,addBook->number,addBook->press,addBook->ok); //将图书信息记录写入文件中
        printf("该书已添加成功\n");
        printf("------------------------\n");

    }
    
    fclose(fp);
    
}



int bookDelete(struct book *head){                         //删除图书信息
    
    char bookName[20],choice;
    int bookID;
    struct book *passPoint = head;
    struct book *temp = NULL;
    FILE *fp;
    
    printf("请输入书名:\n");
    scanf("%s",bookName);                            //键盘录入书名
    printf("请输入编号:\n");
    scanf("%d",&bookID);
    getchar();
    if ((strcmp(head->name, bookName)==0)||bookID==head->number) {           //判断头指针中存储的书与删除的书是否匹配
        
        temp = head;                                 //temp临时存储头指针
        printf("-------------------------------------------------------\n");
        
        printf("书名         作者         编号        出版社       状态 \n");
        printf("%-12s%-12s%-12d%-12s",temp->name,temp->author,temp->number,temp->press);     //输出链表
        
        if (temp->ok == 1) {                          //判断图书是否借出
            printf("已借出\n");
        }else if(temp->ok == 2){
            printf("在架待借\n");
        }else{
            printf("错误\n");
        }
        
        printf("-------------------------------------------------------\n");
        head = head->next;
       
        free(temp);                                 //释放temp
        goto book;
        
        
    }
    
    passPoint = head;
    
    while (passPoint->next!=NULL) {                          //循环直到链表末尾
        
        
        if (strcmp(passPoint->next->name,bookName)==0) {
            
            if (passPoint->next->next==NULL) {
                
                printf("-------------------------------------------------------\n");
                
                printf("书名         作者         编号        出版社       状态 \n");
                printf("%-12s%-12s%-12d%-12s",passPoint->next->name,passPoint->next->author,passPoint->next->number,passPoint->next->press);     //输出链表
                
                if (passPoint->next->ok == 1) {                          //判断图书是否借出
                    printf("已借出\n");
                }else if(passPoint->next->ok == 2){
                    printf("在架待借\n");
                }else{
                    printf("错误\n");
                }
                
                printf("-------------------------------------------------------\n");
                
                temp = passPoint->next;
                passPoint->next = NULL;
                free(temp);                                 //释放temp

                break;
                
            }else{
                
                
                printf("-------------------------------------------------------\n");
                
                printf("书名         作者         编号        出版社       状态 \n");
                printf("%-12s%-12s%-12d%-12s",passPoint->next->name,passPoint->next->author,passPoint->next->number,passPoint->next->press);     //输出链表
                
                if (passPoint->next->ok == 1) {                          //判断图书是否借出
                    printf("已借出\n");
                }else if(passPoint->next->ok == 2){
                    printf("在架待借\n");
                }else{
                    printf("错误\n");
                }
                
                printf("-------------------------------------------------------\n");

                temp = passPoint->next;
                passPoint->next = passPoint->next->next;
                free(temp);                                 //释放temp

                break;

            }
            
        }
        
        passPoint = passPoint->next;
        
    }
    
book:                                                          //图书标签
    
    passPoint = head;
    
    printf("请问是否删除该书?(Y|N)\n");
    scanf("%c",&choice);                                      //键盘录入选项
    
    
    if (choice == 'Y'||choice == 'y') {                        //选择选项
        
        fp = fopen("books.txt", "w");
        
        while (passPoint!=NULL) {
            
            fprintf(fp, "\n%s %s %d %s %d",passPoint->name,passPoint->author,passPoint->number,passPoint->press,passPoint->ok);//重新写入图书信息
            passPoint = passPoint->next;
            
        }
        
        printf("已删除成功.\n");
        
    }else{
        
        printf("谢谢使用.\n");
        return 0;
        
    }
    
    fclose(fp);
    return 0;
}



void bookEmpty(){                                          //清空图书记录
    
    
    FILE *fp;
    fp = fopen("books.txt", "w");                       //重写book.txt文件
    
    printf("已清空所有图书记录\n");
    printf("------------------------\n");
    
}


