// MedicalSys.cpp - MedicalSys for class CPP Programming
// version 0.1.1 rc1 - dev at 2020.06.25 - produce by aurorajc

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

// ��¼������˵�����
void loginSys(string, int);
void adminConsole(Identity*&);
void hospitalConsole(Identity*&);
void usrConsole(Identity*&);

// ��ʾ��ʽ�趨����
void printUser(User& u);
void printHospital(Hospital& h);
void printBill(Bill& b);

// ϵͳ������
int main() {
	// ���Ŀ���̨����
	system("title ������ҽ�Ʊ��չ���ϵͳ");

	// �����û�ѡ��
	int select = 0;

	// ��½ҳ�����
	while (true) {
		cout << "=================== ������ҽ�Ʊ��չ���ϵͳ ===================" << endl;

		cout << endl << "��ӭʹ�á�������ҽ�Ʊ��չ���ϵͳ��!" << endl << "ѡ����Ҫ���еĲ�����" << endl
			<< "\t\t ---------------------------- \n"
			<< "\t\t|                            |\n"
			<< "\t\t|         1.��    ¼         |\n"
			<< "\t\t|                            |\n"
			<< "\t\t|         2.��    ��         |\n"
			<< "\t\t|                            |\n"
			<< "\t\t ---------------------------- \n"
			<< "��ѡ��";

		// ����ѡ��
		cin >> select;

		// �ж�ѡ��
		if (select == 1) {
			while (true) {
				// ˢ�¿���̨
				system("cls");
				cout << "=================== ������ҽ�Ʊ��չ���ϵͳ ===================" << endl;
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

				int select2 = 0;

				// ����ѡ��
				cin >> select2;

				// �ж�ѡ��
				switch (select2) {
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
					cout << "����������������������!" << endl;
					system("pause");
					system("cls");
					break;
				}

			}
		}
		else if (select == 2) {
			cout << "��лʹ�ñ�ϵͳ��ף��������죡" << endl;
			system("pause");
			return 0;
		}
		else{
			cout << "����������������������!" << endl;
			system("pause");
			system("cls");
		}
	}

	system("pause");
	return 0;
}

// ��¼�˵�����
void loginSys(string dataName, int idType) {
	Identity* newId = NULL;

	ifstream ifs;
	ifs.open(dataName, ios::in);

	if (!ifs.is_open()) {
		cout << "�����ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	string usrname;
	string passwd;
	char ch;
	const char ENTER = 13;

	cout << "�������û���/�ֻ���/���䣺" << endl;
	cin >> usrname;

	cout << "���������룺" << endl;
	while ((ch = _getch()) != ENTER)
	{
		if (ch == '\b');
		else {
			passwd += ch;
			cout << '*';
		}
	}

	cout << endl;

	if (idType == 1) {
		long long f2usrUid;
		string f2sysName;
		string f2sysPasswd;
		while (ifs >> f2usrUid && ifs >> f2sysName && ifs >> f2sysPasswd) {
			if (usrname == f2sysName && passwd == f2sysPasswd) {
				cout << "��Ȩ��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				string f2usrMedicalCardNum;
				string f2usrName;
				int f2usrAge;
				string f2usrSex;
				string f2usrIdCardNum;
				string f2usrNation;
				string f2usrIdClass;
				string f2usrInHospital;
				double f2usrCardBalance;
				string f2usrCareArea;
				ifs >> f2usrMedicalCardNum;
				ifs >> f2usrName;
				ifs >> f2usrAge;
				ifs >> f2usrSex;
				ifs >> f2usrIdCardNum;
				ifs >> f2usrNation;
				ifs >> f2usrIdClass;
				ifs >> f2usrInHospital;
				ifs >> f2usrCardBalance;
				ifs >> f2usrCareArea;
				newId = new User(f2usrUid, f2usrMedicalCardNum, f2usrName, f2usrAge, f2usrSex, f2usrIdCardNum, f2usrNation, f2usrIdClass, f2usrInHospital, f2usrCardBalance, f2usrCareArea);
				usrConsole(newId);
				ifs.close();
				return;
			}
		}

	}
	else if (idType == 2) {
		long long f2hospitalHid;
		string f2sysName;
		string f2sysPasswd;
		while (ifs >> f2hospitalHid && ifs >> f2sysName && ifs >> f2sysPasswd) {
			if (usrname == f2sysName && passwd == f2sysPasswd) {
				cout << "��Ȩ��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				string f2hospitalId;
				string f2hospitalName;
				int f2hospitalLevel;
				string f2hospitalArea;
				ifs >> f2hospitalId;
				ifs >> f2hospitalName;
				ifs >> f2hospitalLevel;
				ifs >> f2hospitalArea;
				newId = new Hospital(f2hospitalHid, f2hospitalId, f2hospitalName, f2hospitalLevel, f2hospitalArea);
				hospitalConsole(newId);
				ifs.close();
				return;
			}
		}
	}
	else if (idType == 3) {
		string f2sysName;
		string f2sysPasswd;
		while (ifs >> f2sysName && ifs >> f2sysPasswd) {
			if (usrname == f2sysName && passwd == f2sysPasswd) {
				cout << "��Ȩ��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				string f2adminId;
				string f2adminName;
				string f2adminArea;
				ifs >> f2adminId;
				ifs >> f2adminName;
				ifs >> f2adminArea;
				newId = new Admin(f2adminId, f2adminName, f2adminArea);
				adminConsole(newId);
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

// ����Ա�˵�����
void adminConsole(Identity* &Console) {
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
			cout << "�༭�û�" << endl;
			Manage->editUser();
		}
		else if (select == 11) {
			cout << "�༭����ҽԺ" << endl;
			Manage->editHospital();
		}
		else if (select == 12) {
			cout << "ɾ���û�" << endl;
			Manage->deleteUser();
		}
		else if (select == 13) {
			cout << "ɾ������ҽԺ" << endl;
			Manage->deleteHospital();
		}
		else if (select == 14) {
			cout << "ɾ���˵�" << endl;
			Manage->deleteBill();
		}
		else if (select == 15) {
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

// ����ҽԺ�˵�����
void hospitalConsole(Identity*& Console) {
	while (true) {
		Console->openMenu();

		Hospital* Manage = (Hospital*)Console;

		int select = 0;
		cin >> select;

		if (select == 1) {
			cout << "����˵�" << endl;
			Manage->addBill();
		}
		else if (select == 2) {
			cout << "�г��˵�" << endl;
			Manage->showBill();
		}
		else if (select == 3) {
			cout << "�޸��˵�" << endl;
			Manage->editBill();
		}
		else if (select == 4) {
			cout << "ɾ���˵�" << endl;
			Manage->deleteBill();
		}
		else {
			delete Console;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

// �û��˵�����
void usrConsole(Identity*& Console) {
	while (true) {
		Console->openMenu();

		User* Manage = (User*)Console;

		int select = 0;
		cin >> select;

		if (select == 1) {
			cout << "������Ϣ" << endl;
			Manage->showInfo();
		}
		else if (select == 2) {
			cout << "����ֵ" << endl;
			Manage->addCredit();
		}
		else if (select == 3) {
			cout << "�г��˵�" << endl;
			Manage->showBill();
		}
		else if (select == 4) {
			cout << "֧���˵�" << endl;
			Manage->payBill();
		}
		else {
			delete Console;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

// �û���Ϣ��ʽ����
void printUser(User& u) {
	cout << setiosflags(ios::left) << setfill(' ')
		<< "UID��" << setw(5) << u.usrUid
		<< "ҽ������:" << setw(20) << u.usrMedicalCardNum
		<< "������" << setw(17) << u.usrName
		<< "���䣺" << setw(5) << u.usrAge
		<< "�Ա�" << setw(5) << u.usrSex
		<< "֤�����룺" << setw(20) << u.usrIdCardNum
		<< "���壺" << setw(9) << u.usrNation
		<< "���" << setw(10) << u.usrIdClass
		<< "��Ժ�����" << setw(5) << u.usrInHospital
		<< "���� " << setw(14) << setiosflags(ios::fixed) << setprecision(2) << u.usrCardBanlance
		<< "ҽ����������" << setw(10) << u.usrCareArea
		<< resetiosflags(ios::left | ios::fixed) << endl;
}

// ����ҽԺ��Ϣ��ʽ����
void printHospital(Hospital& h) {
	cout << setiosflags(ios::left) << setfill(' ')
		<< "HID��" << setw(5) << h.hospitalHid
		<< "����ҽԺ�����ţ�" << setw(10) << h.hospitalId
		<< "ҽԺ����" << setw(30) << h.hospitalName
		<< "ҽԺ�ȼ���" << setw(5) << h.hospitalLevel
		<< "ҽԺ��������" << setw(10) << h.hospitalArea
		<< resetiosflags(ios::left | ios::fixed) << endl;
}

// �˵���Ϣ��ʽ����
void printBill(Bill& b) {
	cout << setiosflags(ios::left) << setfill(' ')
		<< "BID��" << setw(5) << b.billBid
		<< "�ɷ���ҽ�����ţ�" << setw(20) << b.billBelongs
		<< "�˵����飺" << setw(30) << b.billInfo
		<< "����ҽԺ�����ţ�" << setw(15) << b.billSource
		<< "�˵�����" << setw(10) << setiosflags(ios::fixed) << setprecision(2) << b.billValue
		<< "�˵�״̬��" << setw(5) << b.billStatus
		<< resetiosflags(ios::left | ios::fixed) << endl;
}