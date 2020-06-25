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

// 登录及分组菜单函数
void loginSys(string, int);
void adminConsole(Identity*&);
void hospitalConsole(Identity*&);
void usrConsole(Identity*&);

// 显示格式设定函数
void printUser(User& u);
void printHospital(Hospital& h);
void printBill(Bill& b);

// 系统主函数
int main() {
	// 更改控制台标题
	system("title 试制型医疗保险管理系统");

	// 接收用户选择
	int select = 0;

	// 登陆页面操作
	while (true) {
		cout << "=================== 试制型医疗保险管理系统 ===================" << endl;

		cout << endl << "欢迎使用【试制型医疗保险管理系统】!" << endl << "选择您要进行的操作：" << endl
			<< "\t\t ---------------------------- \n"
			<< "\t\t|                            |\n"
			<< "\t\t|         1.登    录         |\n"
			<< "\t\t|                            |\n"
			<< "\t\t|         2.退    出         |\n"
			<< "\t\t|                            |\n"
			<< "\t\t ---------------------------- \n"
			<< "请选择：";

		// 输入选择
		cin >> select;

		// 判断选择
		if (select == 1) {
			while (true) {
				// 刷新控制台
				system("cls");
				cout << "=================== 试制型医疗保险管理系统 ===================" << endl;
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

				int select2 = 0;

				// 输入选择
				cin >> select2;

				// 判断选择
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
					cout << "您的输入有误，请重新输入!" << endl;
					system("pause");
					system("cls");
					break;
				}

			}
		}
		else if (select == 2) {
			cout << "感谢使用本系统，祝您生活愉快！" << endl;
			system("pause");
			return 0;
		}
		else{
			cout << "您的输入有误，请重新输入!" << endl;
			system("pause");
			system("cls");
		}
	}

	system("pause");
	return 0;
}

// 登录菜单函数
void loginSys(string dataName, int idType) {
	Identity* newId = NULL;

	ifstream ifs;
	ifs.open(dataName, ios::in);

	if (!ifs.is_open()) {
		cout << "数据文件不存在！" << endl;
		ifs.close();
		return;
	}

	string usrname;
	string passwd;
	char ch;
	const char ENTER = 13;

	cout << "请输入用户名/手机号/邮箱：" << endl;
	cin >> usrname;

	cout << "请输入密码：" << endl;
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
				cout << "授权认证成功！" << endl;
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
				cout << "授权认证成功！" << endl;
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
				cout << "授权认证成功！" << endl;
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

	cout << "授权认证失败！" << endl;

	system("pause");
	system("cls");
	return;
}

// 管理员菜单函数
void adminConsole(Identity* &Console) {
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
			cout << "编辑用户" << endl;
			Manage->editUser();
		}
		else if (select == 11) {
			cout << "编辑定点医院" << endl;
			Manage->editHospital();
		}
		else if (select == 12) {
			cout << "删除用户" << endl;
			Manage->deleteUser();
		}
		else if (select == 13) {
			cout << "删除定点医院" << endl;
			Manage->deleteHospital();
		}
		else if (select == 14) {
			cout << "删除账单" << endl;
			Manage->deleteBill();
		}
		else if (select == 15) {
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

// 定点医院菜单函数
void hospitalConsole(Identity*& Console) {
	while (true) {
		Console->openMenu();

		Hospital* Manage = (Hospital*)Console;

		int select = 0;
		cin >> select;

		if (select == 1) {
			cout << "添加账单" << endl;
			Manage->addBill();
		}
		else if (select == 2) {
			cout << "列出账单" << endl;
			Manage->showBill();
		}
		else if (select == 3) {
			cout << "修改账单" << endl;
			Manage->editBill();
		}
		else if (select == 4) {
			cout << "删除账单" << endl;
			Manage->deleteBill();
		}
		else {
			delete Console;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

// 用户菜单函数
void usrConsole(Identity*& Console) {
	while (true) {
		Console->openMenu();

		User* Manage = (User*)Console;

		int select = 0;
		cin >> select;

		if (select == 1) {
			cout << "个人信息" << endl;
			Manage->showInfo();
		}
		else if (select == 2) {
			cout << "余额充值" << endl;
			Manage->addCredit();
		}
		else if (select == 3) {
			cout << "列出账单" << endl;
			Manage->showBill();
		}
		else if (select == 4) {
			cout << "支付账单" << endl;
			Manage->payBill();
		}
		else {
			delete Console;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

// 用户信息样式函数
void printUser(User& u) {
	cout << setiosflags(ios::left) << setfill(' ')
		<< "UID：" << setw(5) << u.usrUid
		<< "医保卡号:" << setw(20) << u.usrMedicalCardNum
		<< "姓名：" << setw(17) << u.usrName
		<< "年龄：" << setw(5) << u.usrAge
		<< "性别：" << setw(5) << u.usrSex
		<< "证件号码：" << setw(20) << u.usrIdCardNum
		<< "民族：" << setw(9) << u.usrNation
		<< "类别：" << setw(10) << u.usrIdClass
		<< "在院情况：" << setw(5) << u.usrInHospital
		<< "余额：￥ " << setw(14) << setiosflags(ios::fixed) << setprecision(2) << u.usrCardBanlance
		<< "医保所属区域：" << setw(10) << u.usrCareArea
		<< resetiosflags(ios::left | ios::fixed) << endl;
}

// 定点医院信息样式函数
void printHospital(Hospital& h) {
	cout << setiosflags(ios::left) << setfill(' ')
		<< "HID：" << setw(5) << h.hospitalHid
		<< "定点医院机构号：" << setw(10) << h.hospitalId
		<< "医院名：" << setw(30) << h.hospitalName
		<< "医院等级：" << setw(5) << h.hospitalLevel
		<< "医院所属区域：" << setw(10) << h.hospitalArea
		<< resetiosflags(ios::left | ios::fixed) << endl;
}

// 账单信息样式函数
void printBill(Bill& b) {
	cout << setiosflags(ios::left) << setfill(' ')
		<< "BID：" << setw(5) << b.billBid
		<< "缴费人医保卡号：" << setw(20) << b.billBelongs
		<< "账单详情：" << setw(30) << b.billInfo
		<< "出具医院机构号：" << setw(15) << b.billSource
		<< "账单金额：￥" << setw(10) << setiosflags(ios::fixed) << setprecision(2) << b.billValue
		<< "账单状态：" << setw(5) << b.billStatus
		<< resetiosflags(ios::left | ios::fixed) << endl;
}