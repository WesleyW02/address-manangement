#include"func.h"
//显示菜单
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

//添加联系人
void Addperson(Addressbooks* abs)
{
	if (abs->size == MAXSIZE)
	{
		cout << "通讯录已满" << endl;
		return;
	}
	string name;
	int sex;
	cout << "请输入姓名：" << endl;
	cin >> name;
	abs->personArray[abs->size].name = name;
	cout << "请输入性别：" << endl;
	cout << "1--男，2--女：" << endl;
	while (true)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abs->personArray[abs->size].m_sex=sex;
			break;
		}
		else
		{
			cout << "输入有误，请重新输入性别：" << endl;
			cout << "1--男，2--女：" << endl;
		}
	}
	int age;
	cout << "请输入年龄：" << endl;
	while (true)
	{
		cin >> age;
		if (age > 0 && age < 100)
		{
			abs->personArray[abs->size].m_age = age;
			break;
		}
		else
		{
			cout << "输入有误，请重新输入年龄：" << endl;
		}
	}
	string phonenumbers;
	cout << "请输入电话号码：" << endl;
	cin >> phonenumbers;
	abs->personArray[abs->size].m_phone = phonenumbers;
	cout << "请输入住址：" << endl;
	string address;
	cin >> address;
	abs->personArray[abs->size] .m_address = address;
	cout << "添加联系人成功" << endl;
	abs->size++;
	system("pause");//请按任意键继续
	system("cls");//清屏操作
	return;
}

//显示所有联系人
void showperson(const Addressbooks* abs)
{
	//联系了是否为空
	if (abs->size == 0)
	{
		cout << "通讯录为空" << endl;
		system("pause");//请按任意键继续
		system("cls");//清屏操作
		return;
	}
	for (int i = 0; i < abs->size; i++)
	{
		cout << "姓名： " << abs->personArray[i].name<<"\t";
		cout << "性别： " << (abs->personArray[i].m_sex == 1 ? "男" : "女" )<< "\t";
		cout << "年龄： " << abs->personArray[i].m_age<< "\t";
		cout << "电话： " << abs->personArray[i].m_phone << "\t";
		cout << "住址： " << abs->personArray[i].m_address << endl;
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作
	return;
}

//检测联系人是否存在，如果存在，返回联系人在数组的下标，不存在返回-1；
int isExist(const Addressbooks* abs, string name)
{
	int i = -1;//i初始值为-1
	for (int j = 0; j < abs->size; j++)
	{
		if (name == abs->personArray[j].name)
		{
			i = j;
			break;
		}
	}
	return i;
}
//删除联系人
void deleteperson(Addressbooks* abs)
{
	if (abs->size == 0)
	{
		cout << "通讯录为空" << endl;
	}
	else
	{
		cout << "请输入删除联系人姓名" << endl;
		string name;
		cin >> name;
		int key = isExist(abs, name);
		if (key == -1)
		{
			cout << "查无此人" << endl;
		}
		else
		{
			for (int i = key; i < abs->size - 1; i++)
			{
				abs->personArray[i] = abs->personArray[i + 1];//key之后所有元素前移一位
			}
			abs->size--;//人员个数减一
			cout << "成功删除姓名为：" << name << "的联系人" << endl;
		}
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作
	return ;
}

//查找联系人
void getperson(const Addressbooks* abs)
{
	if (abs->size == 0)
	{
		cout << "通讯录为空" << endl;
	}
	else
	{
		cout << "请输入查找联系人姓名" << endl;
		string name;
		cin >> name;
		int key = isExist(abs, name);
		if (key == -1)
		{
			cout << "查无此人" << endl;
		}
		else
		{
			cout << "成功查找姓名为：" << name << "的联系人" << endl;
			cout << "姓名： " << abs->personArray[key].name << "\t";
			cout << "性别： " << (abs->personArray[key].m_sex == 1 ? "男" : "女") << "\t";
			cout << "年龄： " << abs->personArray[key].m_age << "\t";
			cout << "电话： " << abs->personArray[key].m_phone << "\t";
			cout << "住址： " << abs->personArray[key].m_address << endl;
		}
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作
	return;
}

//修改联系人
void modifyperson(Addressbooks* abs)
{
	if (abs->size == 0)
	{
		cout << "通讯录为空" << endl;
	}
	else
	{
		cout << "请输入想要修改联系人姓名" << endl;
		string name;
		cin >> name;
		int key = isExist(abs, name);
		if (key == -1)
		{
			cout << "查无此人" << endl;
		}
		else
		{
			cout << "请输入需要修改的信息" << endl;
			cout << "请重新输入姓名：" << endl;
			cin >> name;
			abs->personArray[key].name = name;
			cout << "请重新输入性别：" << endl;
			cout << "1--男，2--女：" << endl;
			int sex;
			while (true)
			{
				cin >> sex;
				if (sex == 1 || sex == 2)
				{
					abs->personArray[key].m_sex = sex;
					break;
				}
				else
				{
					cout << "输入有误，请重新输入性别：" << endl;
					cout << "1--男，2--女：" << endl;
				}
			}
			int age;
			cout << "请重新输入年龄：" << endl;
			while (true)
			{
				cin >> age;
				if (age > 0 && age < 100)
				{
					abs->personArray[key].m_age = age;
					break;
				}
				else
				{
					cout << "输入有误，请重新输入年龄：" << endl;
				}
			}
			string phonenumbers;
			cout << "请重新输入电话号码：" << endl;
			cin >> phonenumbers;
			abs->personArray[key].m_phone = phonenumbers;
			cout << "请重新输入住址：" << endl;
			string address;
			cin >> address;
			abs->personArray[key].m_address = address;
			cout << "修改联系人信息成功" << endl;
		}
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作
	return;
}
//清空通讯录
void cleanperson(Addressbooks* abs)
{
	if (abs->size == 0)
	{
		cout << "通讯录为空" << endl;
	}
	int select;
	cout << "请输入是否要清空：";
	cout << "1——是，2——否" << endl;
	while (true)
	{
		cin >> select;
		if (1 == select)
		{
			abs->size = 0;//size置为0，做逻辑清空
			cout << "成功清空通讯录" << endl;
			break;
		}
		else if (2 == select)
		{
			cout << "您选择不清空通讯录" << endl;
			break;
		}
		else
		{
			cout << "您的输入有误，请重新输入是否要清空：";
			cout << "1——是，2——否" << endl;
		}
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作
	return;
}