#include"func.h"

int main()
{
	//����ͨѶ¼��
	Addressbooks abs;
	abs.size = 0;
	int select=0;
	while (true)
	{
		showMenu();
		cout << "����������ѡ��" << endl;
		cin >> select;
		switch (select)
		{
		case 0:
			//�˳�ϵͳ
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
			break;
		case 1:
			//������ϵ��
			Addperson(&abs);
			break;
		case 2:
			//��ʾ������ϵ��
			showperson(&abs);
			break;
		case 3:
			//ɾ����ϵ��
			deleteperson(&abs);
			break;
		case 4:
			//������ϵ��
			getperson(&abs);
			break;
		case 5:
			//�޸���ϵ��
			modifyperson(&abs);
			break;
		case 6:
			//���ͨѶ¼
			cleanperson(&abs);
			break;
		default:
			cout << "������Ϸ���ѡ��" << endl;
			break;
		}
	}
}