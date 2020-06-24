// Hospital.cpp - MedicalSys for class CPP Programming
// version 0.0.3 - dev at Wan 2020.06.24 - produce by aurorajc

#include "Hospital.h"

// 账单显示样式
void printBill(Bill& b);

// 构造函数
Hospital::Hospital() {

}

// 含参构造函数
Hospital::Hospital(long long hospitalHid, string hospitalId, string hospitalName, int hospitalLevel, string hospitalArea) {
	this->hospitalHid = hospitalHid;
	this->hospitalId = hospitalId;
	this->hospitalName = hospitalName;
	this->hospitalLevel = hospitalLevel;
	this->hospitalArea = hospitalArea;
}

// 定点医院菜单
void Hospital::openMenu() {
	cout << "欢迎回来，定点医院：" << this->hospitalName << endl;
	cout << " --------------------------------------------------------\n"
		<< "|                                                        |\n"
		<< "|             1.添加账单  2.列出账单  3.删除账单         |\n"
		<< "|                                                        |\n"
		<< "|                          0.注销                        |\n"
		<< "|                                                        |\n"
		<< " --------------------------------------------------------\n"
		<< "请选择：";
}

// 添加账单
void Hospital::addBill() {
	ofstream ofs;
	ofs.open(BILL_FILE, ios::out | ios::app);
	
	int addNum;
	cout << "添加账单数量：" << endl;
	cin >> addNum;

	for (int i = 0; i < addNum; i++) {
		cout << "添加第 【 " << i + 1 << " 】份账单" << endl;

		long long w2billBid;
		cout << "设置账单ID：" << endl;
		cin >> w2billBid;

		string w2billBelongs;
		cout << "输入应缴费人医保卡号：" << endl;
		cin >> w2billBelongs;

		string w2billInfo;
		cout << "输入账单信息：" << endl;
		cin >> w2billInfo;

		double w2billValue;
		cout << "输入账单金额" << endl;
		cin >> w2billValue;

		cout << "正在录入账单信息..." << endl;
		ofs << w2billBid << " " << w2billBelongs << " " << w2billInfo << " " << this->hospitalId << " " << w2billValue << " " << 1 << endl;
		cout << "账单信息录入成功！" << endl;
		
		system("pause");
	}

	system("cls");
	ofs.close();
}

// 列出账单
void Hospital::showBill() {
	Bill a;
	vector<Bill> list;
	list.clear();
	a.initVector();
	for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
		if (it->billSource == this->hospitalId) {
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

// 删除账单
void Hospital::deleteBill() {
	cout << "当前账单如下：" << endl;
	Bill a;
	vector<Bill> list;
	list.clear();
	a.initVector();

	for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
		if (it->billSource == this->hospitalId) {
			list.push_back(*it);
		}
	}

	if (list.empty()) {
		cout << "无账单可删除！" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		for_each(list.begin(), list.end(), printBill);
	
		long long id;
		cout << endl << "输入目标账单Bid:";
		cin >> id;
		cout << "即将删除Bid为" << id << " 的账单。";
		system("pause");

		cout << "正在删除..." << endl;
		list.clear();
		for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
			if (id == it->billBid) {
				continue;
			}
			else {
				list.push_back(*it);
			}	
		}
		a.billData.clear();
		a.billData.assign(list.begin(), list.end());
		a.updateBill();
		cout << "删除成功！" << endl;
		system("pause");
		system("cls");
		return;
	}
}