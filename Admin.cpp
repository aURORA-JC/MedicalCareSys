// Admin.cpp - MedicalSys for class CPP Programming
// version 0.1.2 fixed - dev at 2020.06.25 - produce by aurorajc

#include "Admin.h"

// 显示格式设定函数
void printUser(User& u);
void printHospital(Hospital& h);
void printBill(Bill& b);

// 含参构造函数
Admin::Admin(string adminId, string adminName, string adminArea) {
	this->adminId = adminId;
	this->adminName = adminName;
	this->adminArea = adminArea;

	// 初始化内存
	this->initVector();
}

// 管理员菜单函数
void Admin::openMenu() {
	cout << "欢迎回来，管理员：" << this->adminName << endl;
	cout << " --------------------------------------------------------\n"
		<< "|                                                        |\n"
		<< "|     1.添加用户      2.添加定点医院     3.添加账单      |\n"
		<< "|                                                        |\n"
		<< "|     4.列出用户      5.列出定点医院     6.列出账单      |\n"
		<< "|                                                        |\n"
		<< "|     7.搜索用户      8.搜索定点医院     9.搜索账单      |\n"
		<< "|                                                        |\n"
		<< "|     10.编辑用户     11.编辑定点医院    12.删除用户     |\n"
		<< "|                                                        |\n"
		<< "|     13.删除定点医院   14.删除账单   15.清除全部数据    |\n"
		<< "|                                                        |\n"
		<< "|                         0.注销                         |\n"
		<< "|                                                        |\n"
		<< " --------------------------------------------------------\n"
		<< "请选择：";
}

// 添加用户函数
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

		if (checkRepeat(w2usrUid, "0", 1, 1)) {
			cout << "医保卡号已存在！" << endl;
			continue;
		}

		string w2usrMedicalCardNum;
		cout << "输入医保卡号：" << endl;
		cin >> w2usrMedicalCardNum;

		if (checkRepeat(0, w2usrMedicalCardNum, 2, 1)) {
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

		string w2usrInHospital;
		cout << "用户当前是否住院（是、否）：" << endl;
		cin >> w2usrInHospital;

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

// 添加定点医院函数
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
		
		if (checkRepeat(w2hospitalHid, "0", 1, 2)) {
			cout << "医院编号已存在！" << endl;
			continue;
		}

		string w2hospitalId;
		cout << "输入定点医院机构号：" << endl;
		cin >> w2hospitalId;

		if (checkRepeat(0,w2hospitalId, 2, 2)) {
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

// 添加账单函数
void Admin::addBill() {
	ofstream ofs;
	ofs.open(BILL_FILE, ios::out | ios::app);

	int addNum;
	cout << "添加账单数量：" << endl;
	cin >> addNum;

	for (int i = 0; i < addNum; i++) {
		cout << "添加第 【 " << i + 1 << " 】份账单" << endl;

		long long w2billBid;
		cout << "设置账单编号：" << endl;
		cin >> w2billBid;

		if (checkRepeat(w2billBid, "0", 1, 3)) {
			cout << "账单编号已存在！" << endl;
			continue;
		}

		string w2billBelongs;
		cout << "设置账单" << endl;
		cin >> w2billBelongs;

		string w2billInfo;
		cout << "输入应缴费人医保卡号：" << endl;
		cin >> w2billInfo;

		string w2billSource;
		cout << "输入账单信息：" << endl;
		cin >> w2billSource;

		double w2billValue;
		cout << "输入账单金额：" << endl;
		cin >> w2billValue;

		string w2billStatus;
		string status;
		cout << "输入支付状态（是/否）:" << endl;
		cin >> status;
		if (status == "是") {
			w2billStatus = "已支付";
		}
		else {
			w2billStatus = "未支付";
		}
		
		cout << "信息录入中..." << endl;
		ofs << w2billBid << " " << w2billBelongs << " " << w2billInfo << " " << w2billSource << " " << w2billValue << " " << w2billStatus << endl;
		cout << "录入成功！" << endl;

		system("pause");
		this->initVector();
	}

	system("cls");
	ofs.close();
}

// 显示所有用户信息函数
void Admin::showUser() {
	cout << "所有用户信息如下：" << endl;
	if (!user.empty()) {
		for_each(user.begin(), user.end(), printUser);
	}
	else {
		cout << "空" << endl;
	}
	system("pause");
	system("cls");
}

// 显示所有定点医院信息函数
void Admin::showHospital() {
	cout << "所有定点医院信息如下：" << endl;
	if (!hospital.empty()) {
		for_each(hospital.begin(), hospital.end(), printHospital);
	}
	else {
		cout << "空" << endl;
	}
	system("pause");
	system("cls");
}

// 显示所有账单函数
void Admin::showBill() {
	cout << "所有账单信息如下：" << endl;
	if (!bill.empty()) {
		for_each(bill.begin(), bill.end(), printBill);
	}
	else {
		cout << "空" << endl;
	}
	system("pause");
	system("cls");
}

// 搜索用户函数函数
void Admin::searchUser() {
	usrList.clear();
	string choice;
	
	usrList.clear();
	cout << "选择搜索依据：" << endl
		<< "  1.医保卡号\n"
		<< "  2.姓名\n"
		<< "  3.证件号" << endl
		<< "请输入：";
	cin >> choice;
	if (choice == "1") {
		string id;
		cout << "输入医保卡号：";
		cin >> id;
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->usrMedicalCardNum) {
				usrList.push_back(*it);
			}
		}
	}
	else if (choice == "2") {
		string id;
		cout << "输入姓名：";
		cin >> id;
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->usrName) {
				usrList.push_back(*it);
			}
		}
	}
	else if (choice == "3") {
		string id;
		cout << "输入证件号：";
		cin >> id;
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->usrIdCardNum) {
				usrList.push_back(*it);
			}
		}
	}
	else {
		cout << "输入错误！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "搜索结果如下：" << endl;
	if (!usrList.empty()) {
		for_each(usrList.begin(), usrList.end(), printUser);
	}
	else {
		cout << "空" << endl;
	}

	system("pause");
	system("cls");
}

// 搜索定点医院函数
void Admin::searchHospital() {
	hospitalList.clear();
	string choice;
	
	hospitalList.clear();
	cout << "选择搜索依据：" << endl
		<< "  1.机构号\n"
		<< "  2.名称" << endl
		<< "请输入：";
	cin >> choice;
	if (choice == "1") {
		string id;
		cout << "输入机构号：";
		cin >> id;
		for (vector<Hospital>::iterator it = hospital.begin(); it != hospital.end(); it++) {
			if (id == it->hospitalId) {
				hospitalList.push_back(*it);
			}
		}
	}
	else if (choice == "2") {
		string id;
		cout << "输入医院名：";
		cin >> id;
		for (vector<Hospital>::iterator it = hospital.begin(); it != hospital.end(); it++) {
			if (id == it->hospitalName) {
				hospitalList.push_back(*it);
			}
		}
	}
	else {
		cout << "输入错误！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "搜索结果如下：" << endl;
	if (!hospitalList.empty()) {
		for_each(hospitalList.begin(), hospitalList.end(), printHospital);
	}
	else {
		cout << "空" << endl;
	}

	system("pause");
	system("cls");
}

// 搜索账单函数
void Admin::searchBill() {
	billList.clear();
	string choice;

	hospitalList.clear();
	cout << "选择搜索依据：" << endl
		<< "  1.医保卡号\n"
		<< "  2.定点医院机构号" << endl
		<< "请输入：";
	cin >> choice;

	if (choice == "1") {
		string id;
		cout << "输入医保卡号：";
		cin >> id;
		for (vector<Bill>::iterator it = bill.begin(); it != bill.end(); it++) {
			if (id == it->billBelongs) {
				billList.push_back(*it);
			}
		}
	}
	else if (choice == "2") {
		string id;
		cout << "输入机构号：";
		cin >> id;
		for (vector<Bill>::iterator it = bill.begin(); it != bill.end(); it++) {
			if (id == it->billSource) {
				billList.push_back(*it);
			}
		}
	}
	else {
		cout << "输入错误！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "搜索结果如下：" << endl;
	if (!billList.empty()) {
		for_each(billList.begin(), billList.end(), printBill);
	}
	else {
		cout << "空" << endl;
	}

	system("pause");
	system("cls");
}

// 编辑用户信息函数
void Admin::editUser() {
	this->searchUser();

	long long id;
	cout << endl << "输入修改用户的Uid:";
	cin >> id;

	string choice;
	cout << "选择修改内容：" << endl
		<< "  1.姓名\n"
		<< "  2.年龄\n"
		<< "  3.人员类别\n" 
		<< "  4.账户余额\n" 
		<< "  5.所属地区\n" << endl;
	cin >> choice;

	if (choice == "1") {
		cout << "输入姓名：" << endl;
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->usrUid) {
				cin >> it->usrName;
			}
		}
	}
	else if (choice == "2") {
		cout << "输入年龄：" << endl;
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->usrUid) {
				cin >> it->usrAge;
			}
		}
	}
	else if (choice == "3") {
		cout << "输入类别：" << endl;
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->usrUid) {
				cin >> it->usrIdClass;
			}
		}
	}
	else if (choice == "4") {
		cout << "输入余额：" << endl;
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->usrUid) {
				cin >> it->usrCardBanlance;
			}
		}
	}
	else if (choice == "5") {
		cout << "输入所属地区：" << endl;
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->usrUid) {
				cin >> it->usrCareArea;
			}
		}
	}
	else {
		cout << "输入错误！" << endl;
		system("pause");
		system("cls");
		return;
	}

	updateData(1);
	cout << "修改成功！" << endl;

	system("pause");
	system("cls");
}

// 编辑定点医院信息函数
void Admin::editHospital() {
	this->searchHospital();

	long long id;
	cout << endl << "输入修改医院的Hid:";
	cin >> id;

	string choice;
	cout << "选择修改内容：" << endl
		<< "  1.机构号\n"
		<< "  2.医院名\n"
		<< "  3.所属区域" << endl;
	cin >> choice;

	if (choice == "1") {
		cout << "输入机构号：" << endl;
		for (vector<Hospital>::iterator it = hospital.begin(); it != hospital.end(); it++) {
			if (id == it->hospitalHid) {
				cin >> it->hospitalId;
			}
		}
	}
	else if (choice == "2") {
		cout << "输入医院名：" << endl;
		for (vector<Hospital>::iterator it = hospital.begin(); it != hospital.end(); it++) {
			if (id == it->hospitalHid) {
				cin >> it->hospitalName;
			}
		}
	}
	else if (choice == "3") {
		cout << "输入所属地区：" << endl;
		for (vector<Hospital>::iterator it = hospital.begin(); it != hospital.end(); it++) {
			if (id == it->hospitalHid) {
				cin >> it->hospitalArea;
			}
		}
	}
	else {
		cout << "输入错误！" << endl;
		system("pause");
		system("cls");
		return;
	}

	updateData(2);
	cout << "修改成功！" << endl;

	system("pause");
	system("cls");
}

// 删除用户信息函数
void Admin::deleteUser() {
	this->searchUser();

	long long id;
	cout << endl << "输入删除用户的Uid:";
	cin >> id;
	cout << "即将删除Uid为" << id << " 的用户。是否继续？(是/否)";
	string choice;
	cin >> choice;
	if (choice != "是") {
		cout << "操作已取消！" << endl;
		system("pause");
		system("cls");
		return;
	}

	string usrBill;

	usrList.clear();
	for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
		if (id == it->usrUid) {
			usrBill = it->usrMedicalCardNum;
			continue;
		}
		else {
			usrList.push_back(*it);
		}
	}

	bill.clear();
	for (vector<Bill>::iterator it = bill.begin(); it != bill.end(); it++) {
		if (usrBill == it->billBelongs) {
			continue;
		}
		else {
			billList.push_back(*it);
		}
	}
	user.clear();
	user.assign(usrList.begin(), usrList.end());

	bill.clear();
	bill.assign(billList.begin(), billList.end());
	updateData(1);
	updateData(3);
	cout << "删除成功！" << endl;
	
	system("pause");
	system("cls");
}

// 删除医院信息函数
void Admin::deleteHospital() {
	this->searchHospital();

	long long id;
	cout << endl << "输入删除医院的Hid:";
	cin >> id;
	cout << "即将删除Hid为" << id << "的医院。是否继续？(是/否)";
	string choice;
	cin >> choice;
	if (choice != "是") {
		cout << "操作已取消！" << endl;
		system("pause");
		system("cls");
		return;
	}

	string hospitalBill;

	hospitalList.clear();
	for (vector<Hospital>::iterator it = hospital.begin(); it != hospital.end(); it++) {
		if (id == it->hospitalHid) {
			hospitalBill = it->hospitalId;
			continue;
		}
		else {
			hospitalList.push_back(*it);
		}
	}

	bill.clear();
	for (vector<Bill>::iterator it = bill.begin(); it != bill.end(); it++) {
		if (hospitalBill == it->billSource) {
			continue;
		}
		else {
			billList.push_back(*it);
		}
	}
	hospital.clear();
	hospital.assign(hospitalList.begin(), hospitalList.end());

	bill.clear();
	bill.assign(billList.begin(), billList.end());
	updateData(2);
	updateData(3);
	cout << "删除成功！" << endl;
	
	system("pause");
	system("cls");
}

// 删除账单信息函数
void Admin::deleteBill() {
	this->searchBill();
	
	long long id;
	cout << endl << "输入删除账单的Bid:";
	cin >> id;
	cout << "即将删除Bid为" << id << "的账单。是否继续？(是/否)";
	string choice;
	cin >> choice;
	if (choice != "是") {
		cout << "操作已取消！" << endl;
		system("pause");
		system("cls");
		return;
	}

	hospitalList.clear();
	for (vector<Bill>::iterator it = bill.begin(); it != bill.end(); it++) {
		if (id = it->billBid) {
			continue;
		}
		else {
			billList.push_back(*it);
		}
	}
	bill.clear();
	bill.assign(billList.begin(), billList.end());
	updateData(3);
	cout << "删除成功！" << endl;
	
	system("pause");
	system("cls");
}

// 清空所有数据函数
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

// 容器初始化函数
void Admin::initVector() {
	// 清空容器
	user.clear();
	hospital.clear();
	bill.clear();

	ifstream ifs;
	
	// 读取用户信息
	ifs.open(USER_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "读取数据失败！USER_FILE ERROR!" << endl;
		return;
	}

	User u;
	while (ifs >> u.usrUid && ifs >> u.username && ifs >> u.passwd && ifs >> u.usrMedicalCardNum && ifs >> u.usrName && ifs >> u.usrAge && ifs >> u.usrSex && ifs >> u.usrIdCardNum && ifs >> u.usrNation && ifs >> u.usrIdClass && ifs >> u.usrInHospital && ifs >> u.usrCardBanlance && ifs >> u.usrCareArea) {
		user.push_back(u);
	}
	cout << "当前用户数为：" << user.size() << " 人" << endl;
	ifs.close();

	// 读取医院信息
	ifs.open(HOSPITAL_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "读取数据失败！HOSPITAL_FILE ERROR!" << endl;
		return;
	}

	Hospital h;
	while (ifs >> h.hospitalHid && ifs >> h.username && ifs >> h.passwd && ifs >> h.hospitalId && ifs >> h.hospitalName && ifs >> h.hospitalLevel && ifs >> h.hospitalArea) {
		hospital.push_back(h);
	}
	cout << "当前定点医院数量为：" << hospital.size()  << " 所"<< endl;
	ifs.close();

	// 读取账单信息
	ifs.open(BILL_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "读取数据失败！BILL_FILE ERROR!" << endl;
		return;
	}

	Bill b;
	while (ifs >> b.billBid && ifs >> b.billBelongs && ifs >> b.billInfo && ifs >> b.billSource && ifs >> b.billValue && ifs >> b.billStatus) {
		bill.push_back(b);
	}
	cout << "当前账单数量为：" << bill.size() << " 份" << endl;
	ifs.close();
}

// 重复检查函数
bool Admin::checkRepeat(long long id, string id2, int type, int type2) {
	if (type == 1) {
		if (type2 == 1) {
			for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
				if (id == it->usrUid)
					return true;
			}
		}
		else if (type2 == 2) {
			for (vector<Hospital>::iterator it = hospital.begin(); it != hospital.end(); it++) {
				if (id == it->hospitalHid) {
					return true;
				}
			}
		}
		else if (type2 == 3) {
			for (vector<Bill>::iterator it = bill.begin(); it != bill.end(); it++) {
				if (id == it->billBid)
					return true;
			}
		}
	}
	else if (type == 2) {
		if (type2 == 1) {
			for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
				if (id2 == it->usrMedicalCardNum) {
					return true;
				}
			}
		}
		else if (type2 == 2) {
			for (vector<Hospital>::iterator it = hospital.begin(); it != hospital.end(); it++) {
				if (id2 == it->hospitalId) {
					return true;
				}
			}
		}
	}
	return false;
}

// 更新数据函数
void Admin::updateData(int choice) {
	ofstream ofs;

	// 更新用户
	if (choice == 1) {    
		if (this->usrList.empty()) {
			return;
		}

		ofs.open(USER_FILE, ios::out | ios::trunc);
		for (unsigned int i = 0; i < user.size(); i++) {
			ofs << this->user[i].usrUid << " " << this->user[i].username << " "
				<< this->user[i].passwd << " " << this->user[i].usrMedicalCardNum << " "
				<< this->user[i].usrName << " "<< this->user[i].usrAge << " "
				<< this->user[i].usrSex << " " << this->user[i].usrIdCardNum << " "
				<< this->user[i].usrNation << " " << this->user[i].usrIdClass << " "
				<< this->user[i].usrInHospital << " " << this->user[i].usrCardBanlance << " "
				<< this->user[i].usrCareArea << endl;
		}
	}

	// 更新医院
	else if (choice == 2){
		if (this->hospitalList.empty()) {
			return;
		}

		ofs.open(HOSPITAL_FILE, ios::out | ios::trunc);
		for (unsigned int i = 0; i < hospital.size(); i++) {
			ofs << this->hospital[i].hospitalHid << " " << this->hospital[i].username << " "
				<< this->hospital[i].passwd << " " << this->hospital[i].hospitalId << " "
				<< this->hospital[i].hospitalName << " " << this->hospital[i].hospitalLevel << " "
				<< this->hospital[i].hospitalArea << endl;
		}
	}

	// 更新账单
	else if (choice == 3){
		if (this->billList.empty()) {
			return;
		}

		ofs.open(BILL_FILE, ios::out | ios::trunc);
		for (unsigned int i = 0; i < bill.size(); i++) {
			ofs << this->bill[i].billBid << " " << this->bill[i].billBelongs << " "
				<< this->bill[i].billInfo << " " << this->bill[i].billSource << " "
				<< this->bill[i].billValue << " " << this->bill[i].billStatus << endl;
		}
	}

	ofs.close();
}
