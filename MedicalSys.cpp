// MedicalSys for class CPP Programming - produce by aurorajc
// version 0.0.1 - dev at Wan 2020.06.22

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "gobalNeed.h"
#include "Identity.h"
#include "User.h"
#include "Hospital.h"
#include "Admin.h"
#include "Bill.h"

void loginSys(string, int);
void manageConsole(Identity*&);

int main() {
	// ���Ŀ���̨����
	system("title ������ҽ�Ʊ��չ���ϵͳ");

	// �����û�ѡ��
	int select = 0;

	// ����������
	int tryTime = 4;

	// ��½ҳ�����
	while (true) {
		cout << "=================== ������ҽ�Ʊ��չ���ϵͳ ===================" << endl
			<< "��ǰʱ�䣺" << endl;

		cout << endl << "��ӭʹ�á�������ҽ�Ʊ��չ���ϵͳ��!" << endl << "ѡ����Ҫ���еĲ�����" << endl
			<< "\t\t ---------------------------- \n"
			<< "\t\t|                            |\n"
			<< "\t\t|         1.��    ½         |\n"
			<< "\t\t|                            |\n"
			<< "\t\t|         2.��    ��         |\n"
			<< "\t\t|                            |\n"
			<< "\t\t ---------------------------- \n"
			<< "��ѡ��";

		// ����ѡ��
		cin >> select;

		// �ж�ѡ��
		switch (select) {
		case 1:
			while (true) {
				// ˢ�¿���̨
				system("cls");
				cout << "=================== ������ҽ�Ʊ��չ���ϵͳ ===================" << endl
					<< "��ǰʱ�䣺" << endl;
				cout << endl << "��ѡ��������ݣ�" << endl
					<< "\t\t ---------------------------- \n"
					<< "\t\t|                            |\n"
					<< "\t\t|         1.Ͷ �� ��         |\n"
					<< "\t\t|                            |\n"
					<< "\t\t|         2.����ҽԺ         |\n"
					<< "\t\t|                            |\n"
					<< "\t\t|         3.�� �� Ա         |\n"
					<< "\t\t|                            |\n"
					<< "\t\t ---------------------------- \n"
					<< "��ѡ��";

				// ����ѡ��
				cin >> select;

				// �ж�ѡ��
				switch (select) {
				case 1:
					loginSys(USER_FILE, 1);
					break;
				case 2:
					loginSys(HOSPITAL_FILE, 2);
					break;
				case 3:
					loginSys(ADMIN_FILE, 3);
					break;
				default:
					cout << "����������������������!";
					
					// 3�γ��Ի�����˳�
					tryTime--;
					if (tryTime == 0) {
						cout << endl << "��лʹ�ñ�ϵͳ��ף��������죡" << endl;
						system("pause");
						return 0;
					}
					else {
						cout << "��ʣ�ೢ�Դ�����" << tryTime << " �Σ�" << endl;
					}
					system("pause");
					system("cls");
					break;
				}

			}
			break;
		case 2:
			cout << "��лʹ�ñ�ϵͳ��ף��������죡" << endl;
			system("pause");
			return 0;
		default:
			cout << "����������������������!";

			// 3�γ��Ի�����˳�
			tryTime--;
			if (tryTime == 0) {
				cout << endl << "��лʹ�ñ�ϵͳ��ף��������죡" << endl;
				system("pause");
				return 0;
			}
			else {
				cout << "��ʣ�ೢ�Դ�����" << tryTime << " �Σ�" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}

void loginSys(string dataName, int idType) {
	Identity* newId = NULL;

	ifstream ifs;
	ifs.open(dataName, ios::in);

	if (!ifs.is_open()) {
		cout << "�����ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	string id ;
	string usrname;
	string passwd;
	char ch;
	const char ENTER = 13;

	if (idType == 1) {
		cout << "����������ҽ�����ţ�" << endl;
		cin >> id;
	}
	else if(idType ==2) {
		cout << "�����붨��ҽԺ�����ţ�" << endl;
		cin >> id;
	}

	cout << "�������û���/�ֻ���/���䣺" << endl;
	cin >> usrname;

	cout << "���������룺" << endl;
	while ((ch = _getch()) != ENTER)
	{
		passwd += ch;
		std::cout << '*';
	}

	cout << endl;

	if (idType == 1) {
		string f2Id;
		string f2Name;
		string f2Pwd;
		while (ifs >> f2Id && ifs >> f2Name && ifs >> f2Pwd) {
			if (id == f2Id && usrname == f2Name && passwd == f2Pwd) {
				cout << "��Ȩ��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				string f2usrName;
				int f2age;
				string f2idCardNum;
				string f2usrNation;
				string f2idClass;
				bool f2inHosp;
				double f2cardBalance;
				string f2medicalArea;
				ifs >> f2usrName;
				ifs >> f2age;
				ifs >> f2idCardNum;
				ifs >> f2usrNation;
				ifs >> f2idClass;
				ifs >> f2inHosp;
				ifs >> f2cardBalance;
				ifs >> f2medicalArea;
				newId = new User(f2Id, f2usrName, f2age, f2idCardNum, f2usrNation, f2idClass, f2inHosp, f2cardBalance, f2medicalArea);
				ifs.close();
				return;
			}
		}

	}
	else if (idType == 2) {
		string f2Id;
		string f2Name;
		string f2Pwd;
		while (ifs >> f2Id && ifs >> f2Name && ifs >> f2Pwd) {
			if (id == f2Id && usrname == f2Name && passwd == f2Pwd) {
				cout << "��Ȩ��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				string f2hospName;
				int f2level;
				string f2hospArea;
				ifs >> f2hospName;
				ifs >> f2level;
				ifs >> f2hospArea;
				newId = new Hospital(f2Id, f2hospName, f2level, f2hospArea);
				ifs.close();
				return;
			}
		}
	}
	else if (idType == 3) {
		string f2Name;
		string f2Pwd;
		while (ifs >> f2Name && ifs >> f2Pwd) {
			if (usrname == f2Name && passwd == f2Pwd) {
				cout << "��Ȩ��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				string f2admId;
				string f2admName;
				string f2admArea;
				ifs >> f2admId;
				ifs >> f2admName;
				ifs >> f2admArea;
				newId = new Admin(f2admId, f2admName, f2admArea);
				manageConsole(newId);
				ifs.close();
				return;
			}
		}
	}

	cout << "��Ȩ��֤ʧ�ܣ�" << endl;

	system("pause");
	system("cls");
	return;
}

void manageConsole(Identity* &Console) {
	while (true) {
		Console->openMenu();

		Admin* Manage = (Admin*)Console;

		int select = 0;
		cin >> select;

		if (select == 1) {
			cout << "����û�" << endl;
			Manage->addUser();
		}
		else if (select == 2) {
			cout << "��Ӷ���ҽԺ" << endl;
			Manage->addHospital();
		}
		else if (select == 3) {
			cout << "����˵�" << endl;
			Manage->addBill();
		}
		else if (select == 4) {
			cout << "�г��û�" << endl;
			Manage->showUser();
		}
		else if (select == 5) {
			cout << "�г�����ҽԺ" << endl;
			Manage->showHospital();
		}
		else if (select == 6) {
			cout << "�г��˵�" << endl;
			Manage->showBill();
		}
		else if (select == 7) {
			cout << "�����û�" << endl;
			Manage->searchUser();
		}
		else if (select == 8) {
			cout << "��������ҽԺ" << endl;
			Manage->searchHospital();
		}
		else if (select == 9) {
			cout << "�����˵�" << endl;
			Manage->searchBill();
		}
		else if (select == 10) {
			cout << "ɾ���û�" << endl;
			Manage->deleteUser();
		}
		else if (select == 11) {
			cout << "ɾ������ҽԺ" << endl;
			Manage->deleteHospital();
		}
		else if (select == 12) {
			cout << "ɾ���˵�" << endl;
			Manage->deleteBill();
		}
		else if (select == 13) {
			cout << "�����������" << endl;
			Manage->deleteAll();
		}
		else {
			delete Console;
			cout << "����Ա���ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}