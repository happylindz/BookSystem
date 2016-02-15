#include "Header.h"
/*--------------------—----创建链表-----------------------------*/



struct book *bookCreate(){                                 //为book.txt创建链表
    
    struct book *head = NULL;
    struct book *former,*latter;
    
    FILE *bookInformation;
    bookInformation = fopen("books.txt", "r");       //打开图书信息book.txt文件
    
    
    latter = (struct book*)malloc(sizeof(struct book));
    former = latter;
    fscanf(bookInformation, "\n%s %s %d %s %d",latter->name,latter->author,&latter->number,latter->press,&latter->ok);
    
    head=latter;
    
    
    while (!feof(bookInformation)) {
        
        latter = (struct book*) malloc(sizeof(struct book));
        fscanf(bookInformation, "\n%s %s %d %s %d",latter->name,latter->author,&latter->number,latter->press,&latter->ok);
        //从文件中读取图书信息
        
        if (head == NULL) {
            head = former;
        }
        
        former->next = latter;                                     //联结图书信息
        former = latter;
        
    }
    
    latter->next = NULL;
    fclose(bookInformation);
    
    return head;                                    //返回头指针
    
}



