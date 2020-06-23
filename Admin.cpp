#include "Admin.h"

// 显示格式设定
void printUser(User& u);
void printHospital(Hospital& h);
void printBill(Bill& b);

// 构造函数
Admin::Admin() {

}

// 含参构造函数
Admin::Admin(string adminId, string adminName, string adminArea) {
	this->adminId = adminId;
	this->adminName = adminName;
	this->adminArea = adminArea;

	// 初始化内存
	this->initVector();
}

// 管理员菜单
void Admin::openMenu() {
	cout << "欢迎回来，管理员：" << this->adminName << endl;
	cout << " --------------------------------------------------------\n"
		<< "|                                                        |\n"
		<< "|            1.添加用户         2.添加定点医院           |\n"
		<< "|                                                        |\n"
		<< "|            3.列出用户         4.列出定点医院           |\n"
		<< "|                                                        |\n"
		<< "|            5.搜索用户         6.搜索定点医院           |\n"
		<< "|                                                        |\n"
		<< "|            7.删除用户         8.删除定点医院           |\n"
		<< "|                                                        |\n"
		<< "|            9.清除全部数据     0.注销                   |\n"
		<< "|                                                        |\n"
		<< " --------------------------------------------------------\n"
		<< "请选择：";
}

// 添加用户
void Admin::addUser() {
	ofstream ofs;
	ofs.open(USER_FILE,ios::out | ios::app);
	
	int addNum;
	cout << "添加用户数量：" << endl;
	cin >> addNum;

	for (int i = 0; i < addNum; i++) {
		cout << "添加第 【 " << i+1 << " 】个用户" << endl;

		long long w2usrUid;
		cout << "设置用户编号：" << endl;
		cin >> w2usrUid;

		string w2usrMedicalCardNum;
		cout << "输入医保卡号：" << endl;
		cin >> w2usrMedicalCardNum;

		if (checkRepeat(w2usrMedicalCardNum, 1)) {
			cout << "医保卡号已存在！" << endl;
			continue;
		}

		string w2sysName;
		cout << "输入医保系统用户名：" << endl;
		cin >> w2sysName;

		string w2sysPassword;
		cout << "设置医保系统密码：" << endl;
		cin >> w2sysPassword;

		string w2usrName;
		cout << "输入用户姓名：" << endl;
		cin >> w2usrName;

		int w2usrAge;
		cout << "输入用户年龄：" << endl;
		cin >> w2usrAge;

		string w2usrSex;
		cout << "输入用户性别：" << endl;
		cin >> w2usrSex;

		string w2usrIdCardNum;
		cout << "输入用户证件号：" << endl;
		cin >> w2usrIdCardNum;

		string w2usrNation;
		cout << "输入用户民族：" << endl;
		cin >> w2usrNation;

		string w2usrIdClass;
		cout << "输入用户类别：" << endl;
		cin >> w2usrIdClass;

		bool w2usrInHospital;
		string status;
		cout << "用户当前是否住院（是、否）：" << endl;
		cin >> status;
		if (status == "是") {
			w2usrInHospital = 0;
		}
		else {
			w2usrInHospital = 1;
		}

		double w2usrCardBalance = 0;
		cout << "输入医保卡余额" << endl;
		cin >> w2usrCardBalance;

		string w2usrCareArea;
		cout << "输入医保所属地" << endl;
		cin >> w2usrCareArea;

		cout << "信息录入中..." << endl;
		ofs << w2usrUid << " " << w2sysName << " " << w2sysPassword << " " << w2usrMedicalCardNum << " "<< w2usrName << " " << w2usrAge << " " << w2usrSex << " " << w2usrIdCardNum << " " << w2usrNation << " " << w2usrIdClass << " " << w2usrInHospital << " " << w2usrCardBalance << " " << w2usrCareArea << endl;
		cout << "录入成功！" << endl;

		system("pause");
		this->initVector();
	}

	system("cls");
	ofs.close();
}

// 添加定点医院
void Admin::addHospital() {
	ofstream ofs;
	ofs.open(HOSPITAL_FILE, ios::out | ios::app);

	int addNum;
	cout << "添加定点医院数量：" << endl;
	cin >> addNum;

	for (int i = 0; i < addNum; i++) {
		cout << "添加第 【 " << i + 1 << " 】个定点医院" << endl;

		long long w2hospitalHid;
		cout << "设置医院编号：" << endl;
		cin >> w2hospitalHid;
		
		string w2hospitalId;
		cout << "输入定点医院机构号：" << endl;
		cin >> w2hospitalId;

		if (checkRepeat(w2hospitalId, 1)) {
			cout << "定点医院机构号已存在！" << endl;
			continue;
		}

		string w2hospitalUsrName;
		cout << "输入医保系统用户名：" << endl;
		cin >> w2hospitalUsrName;

		string w2hospitalPasswd;
		cout << "设置医保系统密码：" << endl;
		cin >> w2hospitalPasswd;

		string w2hospitalName;
		cout << "输入医院名称：" << endl;
		cin >> w2hospitalName;

		int w2hospiatlLevel;
		cout << "输入医院等级：" << endl;
		cin >> w2hospiatlLevel;

		string w2hosptialArea;
		cout << "输入医院所属地区：" << endl;
		cin >> w2hosptialArea;

		cout << "信息录入中..." << endl;
		ofs << w2hospitalHid << " " << w2hospitalUsrName << " " << w2hospitalPasswd << " " << w2hospitalId << " " << w2hospitalName << " " << w2hospiatlLevel << " " << w2hosptialArea << endl;
		cout << "录入成功！" << endl;
		
		system("pause");
		this->initVector();
	}

	system("cls");
	ofs.close();
}

// 显示所有用户信息
void Admin::showUser() {
	cout << "所有用户信息如下：" << endl;
	for_each(user.begin(), user.end(), printUser);
	system("pause");
	system("cls");
}

// 显示所有定点医院信息
void Admin::showHospital() {
	cout << "所有定点医院信息如下：" << endl;
	for_each(hospital.begin(), hospital.end(), printHospital);
	system("pause");
	system("cls");
}

// 搜索用户
void Admin::searchUser() {
	int choice;
	
	usrList.clear();
	cout << "选择搜索依据：" << endl
		<< "  1.医保卡号\n"
		<< "  2.姓名\n"
		<< "  3.证件号" << endl
		<< "请输入：";
	cin >> choice;
	if (choice == 1) {
		string id;
		cout << "输入医保卡号：";
		cin >> id;
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->usrMedicalCardNum)
				usrList.push_back(*it);
		}
	}
	else if (choice == 2) {
		string id;
		cout << "输入姓名：";
		cin >> id;
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->usrName)
				usrList.push_back(*it);
		}
	}
	else if (choice == 3) {
		string id;
		cout << "输入证件号：";
		cin >> id;
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->usrIdCardNum)
				usrList.push_back(*it);
		}
	}
	else {
		cout << "输入错误！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "搜索结果如下：" << endl;
	if (usrList.size() != 0) {
		for_each(usrList.begin(), usrList.end(), printUser);
	}
	else {
		cout << "空" << endl;
	}

	system("pause");
	system("cls");
}

// 搜索定点医院
void Admin::searchHospital() {
	int choice;
	
	hospitalList.clear();
	cout << "选择搜索依据：" << endl
		<< "  1.机构号\n"
		<< "  2.名称" << endl
		<< "请输入：";
	cin >> choice;
	if (choice == 1) {
		string id;
		cout << "输入机构号：";
		cin >> id;
		for (vector<Hospital>::iterator it = hospital.begin(); it != hospital.end(); it++) {
			if (id == it->hospitalId)
				hospitalList.push_back(*it);
		}
	}
	else if (choice == 2) {
		string id;
		cout << "输入医院名：";
		cin >> id;
		for (vector<Hospital>::iterator it = hospital.begin(); it != hospital.end(); it++) {
			if (id == it->hospitalName)
				hospitalList.push_back(*it);
		}
	}
	else {
		cout << "输入错误！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "搜索结果如下：" << endl;
	if (hospitalList.size() != 0) {
		for_each(hospitalList.begin(), hospitalList.end(), printHospital);
	}
	else {
		cout << "空" << endl;
	}

	system("pause");
	system("cls");
}

// 删除用户信息
void Admin::deleteUser() {
	this->searchUser();


	this->initVector();
}

// 删除医院信息
void Admin::deleteHospital() {
	this->searchHospital();


	this->initVector();
}

// 清空所有数据
void Admin::deleteAll() {
	cout << "警告！正在准备清空所有数据！此操作不可逆！" << endl;

	string choice;
	cout << "是否继续操作？请输入‘是’" << endl;
	cin >> choice;

	if (choice == "是") {
		ofstream ofs;
		ofs.open(USER_FILE, ios::trunc);
		ofs.close();

		ofs.open(HOSPITAL_FILE, ios::trunc);
		ofs.close();

		ofs.open(BILL_FILE, ios::trunc);
		ofs.close();

		cout << "清除成功！" << endl;
		
		this->initVector();
		system("pause");
		system("cls");
	}
	else {
		cout << "操作已取消！" << endl;
		system("pause");
		system("cls");
		return;
	}
}

// 初始化向量数组
void Admin::initVector() {
	user.clear();
	hospital.clear();

	ifstream ifs;
	ifs.open(USER_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "读取数据失败！" << endl;
		return;
	}

	User u;
	while (ifs >> u.usrUid && ifs >> u.username && ifs >> u.passwd && ifs >> u.usrMedicalCardNum && ifs >> u.usrName && ifs >> u.usrAge && ifs >> u.usrSex && ifs >> u.usrIdCardNum && ifs >> u.usrNation && ifs >> u.usrIdClass && ifs >> u.usrInHospital && ifs >> u.usrCardBanlance && ifs >> u.usrCareArea) {
		user.push_back(u);
	}
	cout << "当前用户数为：" << user.size() << " 人" << endl;
	ifs.close();

	ifs.open(HOSPITAL_FILE, ios::in);

	Hospital h;
	while (ifs >> h.hospitalHid && ifs >> h.username && ifs >> h.passwd && ifs >> h.hospitalId && ifs >> h.hospitalName && ifs >> h.hospitalLevel && ifs >> h.hospitalArea) {
		hospital.push_back(h);
	}
	cout << "当前定点医院数量为：" << hospital.size()  << " 所"<< endl;
	ifs.close();
}

// 查重去重函数
bool Admin::checkRepeat(string id, int type) {
	if (type == 1) {
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->usrMedicalCardNum)
				return true;
		}
	}
	else {
		for (vector<Hospital>::iterator it = hospital.begin(); it != hospital.end(); it++) {
			if (id == it->hospitalId)
				return true;
		}
	}
	return false;
}
