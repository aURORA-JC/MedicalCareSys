#include "Admin.h"


Admin::Admin() {

}

Admin::Admin(string adminId, string adminName, string adminArea) {
	this->adminId = adminId;
	this->adminName = adminName;
	this->adminArea = adminArea;

	this->initVector();
}

void Admin::openMenu() {
	cout << "欢迎回来，管理员：" << this->adminName << endl;
	cout << " --------------------------------------------------------\n"
		<< "|                                                        |\n"
		<< "|         1.添加用户  2.添加定点医院  3.添加账单         |\n"
		<< "|                                                        |\n"
		<< "|         4.列出用户  5.列出定点医院  6.列出账单         |\n"
		<< "|                                                        |\n"
		<< "|         7.搜索用户  8.搜索定点医院  9.搜索账单         |\n"
		<< "|                                                        |\n"
		<< "|         10.删除用户 11.删除定点医院 12.删除账单        |\n"
		<< "|                                                        |\n"
		<< "|         13.清除全部数据             0.注销             |\n"
		<< " --------------------------------------------------------\n"
		<< "请选择：";
}

void Admin::addUser() {
	ofstream ofs;
	ofs.open(USER_FILE,ios::out | ios::app);
	
	int addNum;
	cout << "添加投保人数量：" << endl;
	cin >> addNum;

	for (int i = 0; i < addNum; i++) {
		cout << "添加第 【 " << i+1 << " 】个投保人" << endl;

		string f2Id;
		cout << "输入医保卡号：" << endl;
		cin >> f2Id;

		if (this->checkRepeat(f2Id, 1)) {
			cout << "医保卡号重复！录入终止！" << endl;
			break;
		}

		string f2Name;
		cout << "输入医保系统用户名：" << endl;
		cin >> f2Name;

		string f2Pwd;
		cout << "设置医保系统密码：" << endl;
		cin >> f2Pwd;

		string f2usrName;
		cout << "输入投保人姓名：" << endl;
		cin >> f2usrName;

		int f2age;
		cout << "输入投保人年龄：" << endl;
		cin >> f2age;

		string f2idCardNum;
		cout << "输入投保人证件号：" << endl;
		cin >> f2idCardNum;

		string f2usrNation;
		cout << "输入投保人民族：" << endl;
		cin >> f2usrNation;

		string f2idClass;
		cout << "输入投保人类别：" << endl;
		cin >> f2idClass;

		bool f2inHosp;
		string statu;
		cout << "投保人当前是否住院（是、否）：" << endl;
		cin >> statu;
		if (statu == "是")
			f2inHosp = 0;
		else
			f2inHosp = 1;

		double f2cardBalance = 0;
		cout << "输入医保卡余额" << endl;
		cin >> f2cardBalance;

		string f2medicalArea;
		cout << "输入医保所属地" << endl;
		cin >> f2medicalArea;

		cout << "信息录入中..." << endl;
		ofs << f2Id << " " << f2Name << " " << f2Pwd << " " << f2usrName << " " << f2age << " " << f2idCardNum << " " << f2usrNation << " " << f2idClass << " " << f2inHosp << " " << f2cardBalance << " " << f2medicalArea << endl;
		cout << "录入成功！" << endl;

		system("pause");
		this->initVector();
	}

	system("cls");
	this->initVector();
	ofs.close();
}

void Admin::addHospital() {
	ofstream ofs;
	ofs.open(HOSPITAL_FILE, ios::out | ios::app);

	int addNum;
	cout << "添加定点医院数量：" << endl;
	cin >> addNum;

	for (int i = 0; i < addNum; i++) {
		cout << "添加第 【 " << i + 1 << " 】个定点医院" << endl;

		string f2Id;
		cout << "输入定点医院机构号：" << endl;
		cin >> f2Id;

		if (this->checkRepeat(f2Id, 1)) {
			cout << "定点医院机构号重复！录入终止！" << endl;
			break;
		}

		string f2Name;
		cout << "输入医保系统用户名：" << endl;
		cin >> f2Name;

		string f2Pwd;
		cout << "设置医保系统密码：" << endl;
		cin >> f2Pwd;

		string f2hospName;
		cout << "输入医院名称：" << endl;
		cin >> f2hospName;

		int f2level;
		cout << "输入医院等级：" << endl;
		cin >> f2level;

		string f2hospArea;
		cout << "输入医院所属地区：" << endl;
		cin >> f2hospArea;

		cout << "信息录入中..." << endl;
		ofs << f2Id << " " << f2Name << " " << f2Pwd << " " << f2hospName << " " << f2level << " " << f2hospArea << endl;
		cout << "录入成功！" << endl;
		
		system("pause");
		this->initVector();
	}

	system("cls");
	this->initVector();
	ofs.close();
}

void Admin::addBill() {
	ofstream ofs;
	ofs.open(BILL_FILE, ios::out | ios::app);

	int addNum;
	cout << "添加账单数目：";
	cin >> addNum;
	for (int i = 0; i < addNum; i++) {
		cout << "添加第 【 " << i + 1 << " 】个账单" << endl;

		string f2belong;
		cout << "输入应支付人医保卡号：" << endl;
		cin >> f2belong;

		string f2about;
		cout << "输入详细信息：" << endl;
		cin >> f2about;

		string f2hospital;
		cout << "输入相关医院：" << endl;
		cin >> f2hospital;

		double f2value;
		cout << "输入账单金额：" << endl;
		cin >> f2value;

		cout << "信息录入中..." << endl;
		ofs << f2belong << " " << f2about << " " << f2hospital << " " << f2value << endl;
		cout << "录入成功！" << endl;

		system("pause");
	} 

	system("cls");
	ofs.close();
}

void printUser(User& u);
void printHospital(Hospital& h);

void Admin::showUser() {
	cout << "所有投保人信息如下：" << endl;
	for_each(user.begin(), user.end(), printUser);
	system("pause");
	system("cls");
}

void Admin::showHospital() {
	cout << "所有定点医院信息如下：" << endl;
	for_each(hospital.begin(), hospital.end(), printHospital);
	system("pause");
	system("cls");
}

void Admin::showBill() {
}

void Admin::searchUser() {

}

void Admin::searchHospital() {

}

void Admin::searchBill() {

}

void Admin::deleteUser() {

}

void Admin::deleteHospital() {

}

void Admin::deleteBill() {

}

void Admin::deleteAll() {

}

void Admin::initVector() {
	ifstream ifs;
	ifs.open(USER_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "读取数据失败！" << endl;
		return;
	}

	user.clear();
	hospital.clear();

	User u;
	while (ifs >> u.userId && ifs >> u.userName && ifs >> u.userAge && ifs >> u.idCardNum && ifs >> u.userNation && ifs >> u.idClass && ifs >> u.inHsopital && ifs >> u.cardBanlance && ifs >> u.MedialCareBelongsArea) {
		user.push_back(u);
	}
	cout << "当前投保人数为：" << user.size() << " 人" << endl;
	ifs.close();

	ifs.open(HOSPITAL_FILE, ios::in);

	Hospital h;
	while (ifs >> h.hospitalId && ifs >> h.hospitalName && ifs >> h.hospitalLevel && ifs >> h.hospitalArea) {
		hospital.push_back(h);
	}
	cout << "当前定点医院数量为：" << hospital.size()  << " 所"<< endl;
	ifs.close();
}

bool Admin::checkRepeat(string id, int type) {
	if (type == 1) {
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->userId)
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


void printUser(User &u) {
	cout << "医保卡号:" << setw(20) << u.userId << resetiosflags
		<< "姓名：" << setw(10) << u.userName << resetiosflags
		<< "年龄：" << setw(4) << u.userAge << resetiosflags
		// << "性别：" << setw(2) << u.userAge << resetiosflags
		<< "证件号码：" << setw(20) << u.idCardNum << resetiosflags
		<< "民族：" << setw(5) << u.userNation << resetiosflags
		<< "类别：" << setw(5) << u.idClass << resetiosflags
		<< "在院情况：" << setw(2) << u.inHsopital << resetiosflags
		<< "余额：" << setw(10) << setiosflags(ios::fixed) << setprecision(2) << u.cardBanlance << resetiosflags
		<< "医保所属区域：" << setw(10) << u.MedialCareBelongsArea << resetiosflags << endl;
}

void printHospital(Hospital& h) {
	cout << "定点医院机构号：" << setw(10) << h.hospitalId << resetiosflags
		<< "医院名：" << setw(25) << h.hospitalName << resetiosflags
		<< "医院等级：" << setw(2) << h.hospitalLevel << resetiosflags
		<< "医院所属区域：" << setw(10) << h.hospitalArea << resetiosflags << endl;
}