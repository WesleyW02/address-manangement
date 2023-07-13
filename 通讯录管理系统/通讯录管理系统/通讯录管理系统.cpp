#include"func.h"

int main()
{
	//创建通讯录：
	Addressbooks abs;
	abs.size = 0;
	int select=0;
	while (true)
	{
		showMenu();
		cout << "请输入您的选择" << endl;
		cin >> select;
		switch (select)
		{
		case 0:
			//退出系统
			cout << "欢迎下次使用" << endl;
			return 0;
			break;
		case 1:
			//插入联系人
			Addperson(&abs);
			break;
		case 2:
			//显示所有联系人
			showperson(&abs);
			break;
		case 3:
			//删除联系人
			deleteperson(&abs);
			break;
		case 4:
			//查找联系人
			getperson(&abs);
			break;
		case 5:
			//修改联系人
			modifyperson(&abs);
			break;
		case 6:
			//清空通讯录
			cleanperson(&abs);
			break;
		default:
			cout << "请输入合法的选择" << endl;
			break;
		}
	}
}