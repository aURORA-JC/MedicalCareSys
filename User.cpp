#include "User.h"

void printBill(Bill& b);

User::User() {

}

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

void User::openMenu() {
	cout << "欢迎回来，用户：" << this->usrName << endl;
		cout << " --------------------------------------------------------\n"
			<< "|                                                        |\n"
			<< "|             1.个人信息  2.余额充值  3.列出账单         |\n"
			<< "|                                                        |\n"
			<< "|             4.搜索账单  5.支付账单  0.注销             |\n"
			<< "|                                                        |\n"
			<< " --------------------------------------------------------\n"
			<< "请选择：";
}

void User::showInfo() {
	printUser(*this);
	system("pause");
	system("cls");
}

void User::addCredit() {
	double add;
	cout << "输入充值金额：";
	cin >> add;

	string status;
	cout << "当前余额：￥ " << this->usrCardBanlance << endl
		<< "即将充值：￥ " << add << " 是否充值？（是/否）";
	cin >> status;
	if (status == "是") {
		this->usrCardBanlance += add;
		cout << "充值成功！" << endl
			<< "当前余额：￥ " << this->usrCardBanlance << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "操作已取消！" << endl;
		system("pause");
		system("cls");
	}

}

void User::showBill() {
	Bill a;
	vector<Bill> list;
	list.clear();
	a.initVector();
	for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
		if (it->billSource == this->usrMedicalCardNum) {
			list.push_back(*it);
		}
	}
	for_each(list.begin(), list.end(), printBill);
	system("pause");
	system("cls");
}

void User::payBill() {

}



