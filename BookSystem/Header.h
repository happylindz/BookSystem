#ifndef BookSystem_Header_h
#define BookSystem_Header_h

#define NUM 1000
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct book{
    char name[20];
    char author[20];
    char press[20];
    int ok;
    int number;
    struct book *next;
}bookInformation;


struct student{
    char name[20];
    int id;
}stuInformation;


struct student stu[50];


int menu1();
int menu2();

struct book *bookCreate();

void bookDisplay(struct book *head);
void bookSearch(struct book *head);
void bookAdd(struct book *head);
int bookDelete(struct book *head);
void bookEmpty();

void bookBorrow(struct book *head);
void bookReturn(struct book *head);
void readerDisplay();
void bookStateChange(int ok,struct book *head,char bookName[]);

void userLogin();
void passwordChange();
void userRegister();

void helpWord();

#endif
