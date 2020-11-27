#ifndef _TEST_H_
#define _TEST_H_

#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
#include <stdlib.h>


#define TWO 2
#define NUM 20
typedef struct LIST //可以储存的成员信息列表
{
	char name[20];
	char sex[20];
	int age;
	char tel[20];
	char address[50];
}list;

typedef struct ADDRESS_BOOK
{
	list *call;//调用信息表
	int count;//表明存储个数
	int  capacity;//当前通讯录容量
}address;

void Menu();//菜单
void Add();//添加联系人信息
void Delect();//删除联系人信息
int Found();//找到并打印联系人信息
void Alter();//修改联系人信息
void Show();//显示所有联系人
void Empty();//清空所有联系人
void Rank();//以姓氏排序
void Open();//开辟空间函数

#endif