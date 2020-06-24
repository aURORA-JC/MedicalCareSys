// User.h - MedicalSys for class CPP Programming
// version 0.0.3 - dev at Wan 2020.06.24 - produce by aurorajc

#include "User.h"

using namespace std;

void printUser(User& u);
void printBill(Bill& b);

// 构造函数
User::User() {

}

// 含参构造函数
User::User(long long usrUid, string usrMedicalCardNum, string usrName, int usrAge, string usrSex, string usrIdCardNum, string usrNation, string usrIdClass, bool usrInHospital, double usrCardBalance, string usrCareArea) {
	this->usrMedicalCardNum = usrMedicalCardNum;
	this->usrUid = usrUid;
	this->usrName = usrName;
	this->usrAge = usrAge;
	this->usrSex = usrSex;
	this->usrIdCardNum = usrIdCardNum;
	this->usrNation = usrNation;
	this->usrIdClass = usrIdClass;
	this->usrInHospital = usrInHospital;
	this->usrCardBanlance = usrCardBalance;
	this->usrCareArea = usrCareArea;
}

// 用户菜单
void User::openMenu() {
	cout << "欢迎回来，用户：" << this->usrName << endl;
		cout << " --------------------------------------------------------\n"
			<< "|                                                        |\n"
			<< "|             1.个人信息  2.余额充值  3.列出账单         |\n"
			<< "|                                                        |\n"
			<< "|             4.支付账单              0.注销             |\n"
			<< "|                                                        |\n"
			<< " --------------------------------------------------------\n"
			<< "请选择：";
}

// 显示信息
void User::showInfo() {
	User u;
	vector<User> list;
	list.clear();
	u.initVector();

	for (vector<User>::iterator it = u.usrData.begin(); it != u.usrData.end(); it++) {
		if (this->usrMedicalCardNum == it->usrMedicalCardNum) {
			list.push_back(*it);
		}
	}

	for_each(list.begin(), list.end(), printUser);

	system("pause");
	system("cls");
}

// 充值
void User::addCredit() {
	User u;
	vector<User> list;
	list.clear();
	u.initVector();
	double add;
	cout << "输入充值金额：";
	cin >> add;

	string status;
	cout << "当前余额：￥ " << setiosflags(ios::fixed) << setprecision(2) << this->usrCardBanlance << endl
		<< "即将充值：￥ " << add << " 是否充值？（是/否）" << resetiosflags(ios::fixed);
	cin >> status;
	if (status == "是") {
		for (vector<User>::iterator it = u.usrData.begin(); it != u.usrData.end(); it++) {
			if (this->usrMedicalCardNum == it->usrMedicalCardNum) {
				it->usrCardBanlance += add;
			}
		}

		u.updateUser();
		cout << "充值成功！" << endl
			<< "当前余额：￥ " << setiosflags(ios::fixed) << setprecision(2) << this->usrCardBanlance + add << resetiosflags(ios::fixed) << endl;

		system("pause");
		system("cls");
	}
	else {
		cout << "操作已取消！" << endl;
		system("pause");
		system("cls");
	}

}

// 显示账单
void User::showBill() {
	Bill a;
	vector<Bill> list;
	list.clear();
	a.initVector();

	for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
		if (it->billBelongs == this->usrMedicalCardNum) {
			list.push_back(*it);
		}
	}

	if (list.empty()) {
		cout << "空" << endl;
	}
	else {
		for_each(list.begin(), list.end(), printBill);
	}
	
	system("pause");
	system("cls");
}

// 支付账单
void User::payBill() {
	cout << "当前可支付账单如下：" << endl;
	Bill a;
	User u;
	vector<Bill> list;
	list.clear();
	a.initVector();
	u.initVector();

	for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
		if (it->billBelongs == this->usrMedicalCardNum && it->billStatus == 1) {
			list.push_back(*it);
		}
	}

	if (list.empty()) {
		cout << "无账单可支付！" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		for_each(list.begin(), list.end(), printBill);

		long long id;
		cout << endl << "输入目标账单Bid:";
		cin >> id;
		cout << "即将支付Bid为" << id << " 的账单。";
		system("pause");

		cout << "正在支付..." << endl;
		double value = 0;

		for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
			if (id == it->billBid) {
				it->billStatus = 0;
				value = it->billValue;
			}
		}

		for (vector<User>::iterator it = u.usrData.begin(); it != u.usrData.end(); it++) {
			if (this->usrMedicalCardNum == it->usrMedicalCardNum) {
				it->usrCardBanlance -= value;
			}
		}

		a.updateBill();
		u.updateUser();
		cout << "支付成功！" << endl;
		system("pause");
		system("cls");
		return;
	}

	system("pause");
	system("cls");
}

// 初始化
void User::initVector() {
	usrData.clear();

	ifstream ifs;
	ifs.open(USER_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "读取数据失败！" << endl;
		return;
	}

	User u;
	while (ifs >> u.usrUid && ifs >> u.username && ifs >> u.passwd && ifs >> u.usrMedicalCardNum && ifs >> u.usrName && ifs >> u.usrAge && ifs >> u.usrSex && ifs >> u.usrIdCardNum && ifs >> u.usrNation && ifs >> u.usrIdClass && ifs >> u.usrInHospital && ifs >> u.usrCardBanlance && ifs >> u.usrCareArea) {
		usrData.push_back(u);
	}
	ifs.close();
}

// 更新
void User::updateUser(){
	if (this->usrData.size() == 0) {
		return;
	}

	ofstream ofs;
	ofs.open(USER_FILE, ios::out | ios::trunc);
	for (unsigned int i = 0; i < usrData.size(); i++) {
		ofs << this->usrData[i].usrUid << " " << this->usrData[i].username << " "
			<< this->usrData[i].passwd << " " << this->usrData[i].usrMedicalCardNum << " " << this->usrData[i].usrName << " "
			<< this->usrData[i].usrAge << " " << this->usrData[i].usrSex << " "
			<< this->usrData[i].usrIdCardNum << " " << this->usrData[i].usrNation << " "
			<< this->usrData[i].usrIdClass << " " << this->usrData[i].usrInHospital << " "
			<< this->usrData[i].usrCardBanlance << " " << this->usrData[i].usrCareArea << endl;
	}
	ofs.close();
}

