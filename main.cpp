#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

typedef struct person
{
	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_addr;
};

struct addressbooks
{
	
	struct person personArray[1000]; 
	int m_Size;
};

void showmenu()
{
	cout << "************************" << endl;
	cout << "**** 1�������ϵ�� ****" << endl;
	cout << "**** 2����ʾ��ϵ�� ****" << endl;
	cout << "**** 3��ɾ����ϵ�� ****" << endl;
	cout << "**** 4��������ϵ�� ****" << endl;
	cout << "**** 5���޸���ϵ�� ****" << endl;
	cout << "**** 6�������ϵ�� ****" << endl;
	cout << "**** 0���˳�ͨѶ¼ ****" << endl;
	cout << "************************" << endl;
}

//�����ϵ��
void addperson(addressbooks *ads)
{
	if (ads->m_Size == 1000)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		string name;
		cout << "����������" << endl;
		cin >> name;
		ads->personArray[ads->m_Size].m_name = name;

		cout << "�������Ա�" << endl;
		cout << "1--��" << endl;
		cout << "2--Ů" << endl;

		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				ads->personArray[ads->m_Size].m_sex = sex;
				break;
			}
		}
		int age=0;
		cout << "���������䣺" << endl;
		cin >> age;
		ads->personArray[ads->m_Size].m_age = age;

		string phone;
		cout << "��������ϵ�绰��" << endl;
		cin >> phone;
		ads->personArray[ads->m_Size].m_phone = phone;

		string address;
		cout << "�������ͥסַ��" << endl;
		cin >> address;
		ads->personArray[ads->m_Size].m_addr = address;

		ads->m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system( "cls" );
	}
}
//��ʾ��ϵ��
void showperson(addressbooks *ads)
{
	if (ads->m_Size == 0)
	{
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < ads->m_Size; i++) {
			cout << "������" << ads->personArray[i].m_name << "\t";
			cout << "�Ա�" << (ads->personArray[i].m_sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << ads->personArray[i].m_age << "\t";
			cout << "��ϵ�绰��" << ads->personArray[i].m_phone << "\t";
			cout << "��ͥסַ��" << ads->personArray[i].m_addr << "\t";
		}
	}
	system("pause");
	system("cls");
}
//�ж���ϵ���Ƿ����
int isExist(addressbooks* ads, string name)
{
	for (int i = 0; i < ads->m_Size; i++)
	{
		if (ads->personArray[i].m_name == name)
		{
			return i;
		}
	}
	return -1;
}
//ɾ����ϵ��
void deleteperson(addressbooks* ads)
{
	cout << "����Ҫɾ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;

	int ret = isExist(ads, name);
	if (ret != -1)
	{
		for (int i = ret; i < ads->m_Size; i++)
		{
			ads->personArray[i] = ads->personArray[i + 1];
		}
		ads->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//������ϵ��
void reserch(addressbooks* ads)
{
	cout << "��������ϵ��������" << endl;
	string name;
	cin >> name;

	int ret = isExist(ads, name);
	if (ret != -1)
	{
		cout << ads->personArray[ret].m_name << "\t";
		cout << (ads->personArray[ret].m_sex == 1 ? "��":"Ů") << "\t";
		cout << ads->personArray[ret].m_age << "\t";
		cout << ads->personArray[ret].m_phone << "\t";
		cout << ads->personArray[ret].m_addr << "\t";
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//�޸���ϵ��
void modifyperson(addressbooks* ads)
{
	cout << "��������ϵ��������" << endl;
	string name;
	cin >> name;

	int ret = isExist(ads, name);
	if (ret != -1)
	{
		cout << "������" << endl;
		string name;
		cin >> name;
		ads->personArray[ret].m_name = name;
		
		cout << "�Ա�" << endl;
		cout << "1--��" << endl;
		cout << "2--Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				ads->personArray[ret].m_sex = sex;
				break;
			}
			cout << "��������" << endl;
		}

		int age = 0;
		cout << "���䣺" << endl;
		cin >> age;
		ads->personArray[ret].m_age = age;

		string phone = " ";
		cout << "��ϵ�绰: " << endl;
		cin >> phone;
		ads->personArray[ret].m_phone = phone;

		string address;
		cout << "��ͥסַ��" << endl;
		cin >> address;
		ads->personArray[ret].m_addr = address;

		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//���ͨѶ¼
void cleanperson(addressbooks* ads)
{
	ads->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}

int main()
{
	int select = 0;
	addressbooks abs;
	abs.m_Size = 0;//��ʼ��ͨѶ¼��
	
	while (true)
	{
		showmenu();
		cin >> select;

		switch (select)
		{
		case 1://�����ϵ��
			addperson(&abs);
			break;
		case 2://��ʾ��ϵ��
			showperson(&abs);
			break;
		case 3://ɾ����ϵ��
			deleteperson(&abs);
			break;
		case 4://������ϵ��
			reserch(&abs);
			break;
		case 5://�޸���ϵ��
			modifyperson(&abs);
			break;
		case 6://���ͨѶ¼
			cleanperson(&abs);
			break;
		case 0://�Ƴ�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");

	return 0;
}