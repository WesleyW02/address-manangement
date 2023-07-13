#pragma once
#include<iostream>
#include<string>

#define MAXSIZE 100
using namespace std;

//������ϵ�˽ṹ��
typedef struct person
{
	string name;
	int m_sex;//�Ա�1.�С�2.Ů
	int m_age;
	string m_phone;
	string m_address;
}person;
// ����ͨѶ�ṹ��
typedef struct Addressbooks
{
	int size;//��ϵ�˸���
	person personArray[MAXSIZE];
}Addressbooks;
//��ʾ�˵�
void showMenu();
//�����ϵ��
void Addperson(Addressbooks* abs);
//��ʾ��ϵ��
void showperson(const Addressbooks* abs);
//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ����������±꣬�����ڷ���-1��
int isExist(const Addressbooks* abs,string name);
//ɾ����ϵ��
void deleteperson(Addressbooks* abs);
//������ϵ��
void getperson(const Addressbooks* abs);
//�޸���ϵ��
void modifyperson(Addressbooks* abs);
//���ͨѶ¼
void cleanperson(Addressbooks* abs);