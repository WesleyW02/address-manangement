#pragma once
#include<iostream>
#include<string>

#define MAXSIZE 100
using namespace std;

//定义联系人结构体
typedef struct person
{
	string name;
	int m_sex;//性别：1.男。2.女
	int m_age;
	string m_phone;
	string m_address;
}person;
// 定义通讯结构体
typedef struct Addressbooks
{
	int size;//联系人个数
	person personArray[MAXSIZE];
}Addressbooks;
//显示菜单
void showMenu();
//添加联系人
void Addperson(Addressbooks* abs);
//显示联系人
void showperson(const Addressbooks* abs);
//检测联系人是否存在，如果存在，返回联系人在数组的下标，不存在返回-1；
int isExist(const Addressbooks* abs,string name);
//删除联系人
void deleteperson(Addressbooks* abs);
//查找联系人
void getperson(const Addressbooks* abs);
//修改联系人
void modifyperson(Addressbooks* abs);
//清空通讯录
void cleanperson(Addressbooks* abs);