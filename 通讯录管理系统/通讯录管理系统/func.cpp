#include"func.h"
//��ʾ�˵�
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}

//�����ϵ��
void Addperson(Addressbooks* abs)
{
	if (abs->size == MAXSIZE)
	{
		cout << "ͨѶ¼����" << endl;
		return;
	}
	string name;
	int sex;
	cout << "������������" << endl;
	cin >> name;
	abs->personArray[abs->size].name = name;
	cout << "�������Ա�" << endl;
	cout << "1--�У�2--Ů��" << endl;
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
			cout << "�������������������Ա�" << endl;
			cout << "1--�У�2--Ů��" << endl;
		}
	}
	int age;
	cout << "���������䣺" << endl;
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
			cout << "���������������������䣺" << endl;
		}
	}
	string phonenumbers;
	cout << "������绰���룺" << endl;
	cin >> phonenumbers;
	abs->personArray[abs->size].m_phone = phonenumbers;
	cout << "������סַ��" << endl;
	string address;
	cin >> address;
	abs->personArray[abs->size] .m_address = address;
	cout << "�����ϵ�˳ɹ�" << endl;
	abs->size++;
	system("pause");//�밴���������
	system("cls");//��������
	return;
}

//��ʾ������ϵ��
void showperson(const Addressbooks* abs)
{
	//��ϵ���Ƿ�Ϊ��
	if (abs->size == 0)
	{
		cout << "ͨѶ¼Ϊ��" << endl;
		system("pause");//�밴���������
		system("cls");//��������
		return;
	}
	for (int i = 0; i < abs->size; i++)
	{
		cout << "������ " << abs->personArray[i].name<<"\t";
		cout << "�Ա� " << (abs->personArray[i].m_sex == 1 ? "��" : "Ů" )<< "\t";
		cout << "���䣺 " << abs->personArray[i].m_age<< "\t";
		cout << "�绰�� " << abs->personArray[i].m_phone << "\t";
		cout << "סַ�� " << abs->personArray[i].m_address << endl;
	}
	system("pause");//�밴���������
	system("cls");//��������
	return;
}

//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ����������±꣬�����ڷ���-1��
int isExist(const Addressbooks* abs, string name)
{
	int i = -1;//i��ʼֵΪ-1
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
//ɾ����ϵ��
void deleteperson(Addressbooks* abs)
{
	if (abs->size == 0)
	{
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else
	{
		cout << "������ɾ����ϵ������" << endl;
		string name;
		cin >> name;
		int key = isExist(abs, name);
		if (key == -1)
		{
			cout << "���޴���" << endl;
		}
		else
		{
			for (int i = key; i < abs->size - 1; i++)
			{
				abs->personArray[i] = abs->personArray[i + 1];//key֮������Ԫ��ǰ��һλ
			}
			abs->size--;//��Ա������һ
			cout << "�ɹ�ɾ������Ϊ��" << name << "����ϵ��" << endl;
		}
	}
	system("pause");//�밴���������
	system("cls");//��������
	return ;
}

//������ϵ��
void getperson(const Addressbooks* abs)
{
	if (abs->size == 0)
	{
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else
	{
		cout << "�����������ϵ������" << endl;
		string name;
		cin >> name;
		int key = isExist(abs, name);
		if (key == -1)
		{
			cout << "���޴���" << endl;
		}
		else
		{
			cout << "�ɹ���������Ϊ��" << name << "����ϵ��" << endl;
			cout << "������ " << abs->personArray[key].name << "\t";
			cout << "�Ա� " << (abs->personArray[key].m_sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺 " << abs->personArray[key].m_age << "\t";
			cout << "�绰�� " << abs->personArray[key].m_phone << "\t";
			cout << "סַ�� " << abs->personArray[key].m_address << endl;
		}
	}
	system("pause");//�밴���������
	system("cls");//��������
	return;
}

//�޸���ϵ��
void modifyperson(Addressbooks* abs)
{
	if (abs->size == 0)
	{
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸���ϵ������" << endl;
		string name;
		cin >> name;
		int key = isExist(abs, name);
		if (key == -1)
		{
			cout << "���޴���" << endl;
		}
		else
		{
			cout << "��������Ҫ�޸ĵ���Ϣ" << endl;
			cout << "����������������" << endl;
			cin >> name;
			abs->personArray[key].name = name;
			cout << "�����������Ա�" << endl;
			cout << "1--�У�2--Ů��" << endl;
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
					cout << "�������������������Ա�" << endl;
					cout << "1--�У�2--Ů��" << endl;
				}
			}
			int age;
			cout << "�������������䣺" << endl;
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
					cout << "���������������������䣺" << endl;
				}
			}
			string phonenumbers;
			cout << "����������绰���룺" << endl;
			cin >> phonenumbers;
			abs->personArray[key].m_phone = phonenumbers;
			cout << "����������סַ��" << endl;
			string address;
			cin >> address;
			abs->personArray[key].m_address = address;
			cout << "�޸���ϵ����Ϣ�ɹ�" << endl;
		}
	}
	system("pause");//�밴���������
	system("cls");//��������
	return;
}
//���ͨѶ¼
void cleanperson(Addressbooks* abs)
{
	if (abs->size == 0)
	{
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	int select;
	cout << "�������Ƿ�Ҫ��գ�";
	cout << "1�����ǣ�2������" << endl;
	while (true)
	{
		cin >> select;
		if (1 == select)
		{
			abs->size = 0;//size��Ϊ0�����߼����
			cout << "�ɹ����ͨѶ¼" << endl;
			break;
		}
		else if (2 == select)
		{
			cout << "��ѡ�����ͨѶ¼" << endl;
			break;
		}
		else
		{
			cout << "�����������������������Ƿ�Ҫ��գ�";
			cout << "1�����ǣ�2������" << endl;
		}
	}
	system("pause");//�밴���������
	system("cls");//��������
	return;
}