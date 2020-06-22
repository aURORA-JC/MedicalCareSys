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
	// 更改控制台标题
	system("title 试制型医疗保险管理系统");

	// 接收用户选择
	int select = 0;

	// 输入错误计数
	int tryTime = 4;

	// 登陆页面操作
	while (true) {
		cout << "=================== 试制型医疗保险管理系统 ===================" << endl
			<< "当前时间：" << endl;

		cout << endl << "欢迎使用【试制型医疗保险管理系统】!" << endl << "选择您要进行的操作：" << endl
			<< "\t\t ---------------------------- \n"
			<< "\t\t|                            |\n"
			<< "\t\t|         1.登    陆         |\n"
			<< "\t\t|                            |\n"
			<< "\t\t|         2.退    出         |\n"
			<< "\t\t|                            |\n"
			<< "\t\t ---------------------------- \n"
			<< "请选择：";

		// 输入选择
		cin >> select;

		// 判断选择
		switch (select) {
		case 1:
			while (true) {
				// 刷新控制台
				system("cls");
				cout << "=================== 试制型医疗保险管理系统 ===================" << endl
					<< "当前时间：" << endl;
				cout << endl << "请选择您的身份：" << endl
					<< "\t\t ---------------------------- \n"
					<< "\t\t|                            |\n"
					<< "\t\t|         1.投 保 人         |\n"
					<< "\t\t|                            |\n"
					<< "\t\t|         2.定点医院         |\n"
					<< "\t\t|                            |\n"
					<< "\t\t|         3.管 理 员         |\n"
					<< "\t\t|                            |\n"
					<< "\t\t ---------------------------- \n"
					<< "请选择：";

				// 输入选择
				cin >> select;

				// 判断选择
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
					cout << "您的输入有误，请重新输入!";
					
					// 3次尝试机会后退出
					tryTime--;
					if (tryTime == 0) {
						cout << endl << "感谢使用本系统，祝您生活愉快！" << endl;
						system("pause");
						return 0;
					}
					else {
						cout << "（剩余尝试次数：" << tryTime << " 次）" << endl;
					}
					system("pause");
					system("cls");
					break;
				}

			}
			break;
		case 2:
			cout << "感谢使用本系统，祝您生活愉快！" << endl;
			system("pause");
			return 0;
		default:
			cout << "您的输入有误，请重新输入!";

			// 3次尝试机会后退出
			tryTime--;
			if (tryTime == 0) {
				cout << endl << "感谢使用本系统，祝您生活愉快！" << endl;
				system("pause");
				return 0;
			}
			else {
				cout << "（剩余尝试次数：" << tryTime << " 次）" << endl;
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
		cout << "数据文件不存在！" << endl;
		ifs.close();
		return;
	}

	string id ;
	string usrname;
	string passwd;
	char ch;
	const char ENTER = 13;

	if (idType == 1) {
		cout << "请输入您的医保卡号：" << endl;
		cin >> id;
	}
	else if(idType ==2) {
		cout << "请输入定点医院机构号：" << endl;
		cin >> id;
	}

	cout << "请输入用户名/手机号/邮箱：" << endl;
	cin >> usrname;

	cout << "请输入密码：" << endl;
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
				cout << "授权认证成功！" << endl;
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
				cout << "授权认证成功！" << endl;
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
				cout << "授权认证成功！" << endl;
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

	cout << "授权认证失败！" << endl;

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
			cout << "添加用户" << endl;
			Manage->addUser();
		}
		else if (select == 2) {
			cout << "添加定点医院" << endl;
			Manage->addHospital();
		}
		else if (select == 3) {
			cout << "添加账单" << endl;
			Manage->addBill();
		}
		else if (select == 4) {
			cout << "列出用户" << endl;
			Manage->showUser();
		}
		else if (select == 5) {
			cout << "列出定点医院" << endl;
			Manage->showHospital();
		}
		else if (select == 6) {
			cout << "列出账单" << endl;
			Manage->showBill();
		}
		else if (select == 7) {
			cout << "搜索用户" << endl;
			Manage->searchUser();
		}
		else if (select == 8) {
			cout << "搜索定点医院" << endl;
			Manage->searchHospital();
		}
		else if (select == 9) {
			cout << "搜索账单" << endl;
			Manage->searchBill();
		}
		else if (select == 10) {
			cout << "删除用户" << endl;
			Manage->deleteUser();
		}
		else if (select == 11) {
			cout << "删除定点医院" << endl;
			Manage->deleteHospital();
		}
		else if (select == 12) {
			cout << "删除账单" << endl;
			Manage->deleteBill();
		}
		else if (select == 13) {
			cout << "清除所有数据" << endl;
			Manage->deleteAll();
		}
		else {
			delete Console;
			cout << "管理员身份注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}