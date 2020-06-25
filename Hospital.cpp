// Hospital.cpp - MedicalSys for class CPP Programming
// version 0.1.1 rc1 - dev at 2020.06.25 - produce by aurorajc

#include "Hospital.h"

// 显示格式设定函数
void printBill(Bill& b);

// 含参构造函数
Hospital::Hospital(long long hospitalHid, string hospitalId, string hospitalName, int hospitalLevel, string hospitalArea) {
	this->hospitalHid = hospitalHid;
	this->hospitalId = hospitalId;
	this->hospitalName = hospitalName;
	this->hospitalLevel = hospitalLevel;
	this->hospitalArea = hospitalArea;
}

// 定点医院菜单函数
void Hospital::openMenu() {
	cout << "欢迎回来，定点医院：" << this->hospitalName << endl;
	cout << " --------------------------------------------------------\n"
		<< "|                                                        |\n"
		<< "|             1.添加账单  2.列出账单  3.修改账单         |\n"
		<< "|                                                        |\n"
		<< "|             4.删除账单             0.注销              |\n"
		<< "|                                                        |\n"
		<< " --------------------------------------------------------\n"
		<< "请选择：";
}

// 添加账单函数
void Hospital::addBill() {
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

		if (checkRepeat(w2billBid)) {
			cout << "账单编号已存在！" << endl;
			continue;
		}

		string w2billBelongs;
		cout << "输入应缴费人医保卡号：" << endl;
		cin >> w2billBelongs;

		string w2billInfo;
		cout << "输入账单信息：" << endl;
		cin >> w2billInfo;

		double w2billValue;
		cout << "输入账单金额：" << endl;
		cin >> w2billValue;

		cout << "正在录入账单信息..." << endl;
		ofs << w2billBid << " " << w2billBelongs << " " << w2billInfo << " " << this->hospitalId << " " << w2billValue << " " << "未支付" << endl;
		cout << "账单信息录入成功！" << endl;
		
		system("pause");
	}

	system("cls");
	ofs.close();
}

// 列出账单函数
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

// 编辑账单函数
void Hospital::editBill() {
	cout << "当前账单如下：" << endl;
	Bill a;
	vector<Bill> list;
	list.clear();
	rights.clear();
	a.initVector();

	for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
		if (it->billSource == this->hospitalId) {
			list.push_back(*it);
			this->rights.push_back(it->billBid);
		}
	}

	if (list.empty()) {
		cout << "无账单可修改！" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		for_each(list.begin(), list.end(), printBill);

		long long id;
		cout << endl << "输入目标账单的Bid:";
		cin >> id;

		if (!checkRights(id)) {
			cout << "当前BID不可访问！" << endl;
			system("pause");
			system("cls");
			return;
		}

		int choice;
		cout << "选择修改内容：" << endl
			<< "  1.详情\n"
			<< "  2.金额\n"
			<< "  3.支付状态" << endl;
		cin >> choice;

		if (choice == 1) {
			cout << "输入详情：" << endl;
			for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
				if (id == it->billBid) {
					cin >> it->billInfo;
				}
			}
		}
		else if (choice == 2) {
			cout << "输入金额：" << endl << "￥";
			for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
				if (id == it->billBid) {
					cin >> it->billValue;
				}
			}
		}
		else if (choice == 3) {
			cout << "设置支付状态（是/否）：" << endl;
			for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
				if (id == it->billBid) {
					string status;
					cin >> status;
					if (status == "是") {
						it->billStatus = "已支付";
					}
					else {
						it->billStatus = "未支付";
					}
				}
			}
		}
		else {
			cout << "输入错误！" << endl;
			system("pause");
			system("cls");
			return;
		}

		a.updateBill();
		cout << "修改成功！" << endl;

		system("pause");
		system("cls");
	}
}

// 删除账单函数
void Hospital::deleteBill() {
	cout << "当前账单如下：" << endl;
	Bill a;
	vector<Bill> list;
	list.clear();
	rights.clear();
	a.initVector();

	for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
		if (it->billSource == this->hospitalId) {
			list.push_back(*it);
			rights.push_back(it->billBid);
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
		cout << endl << "输入目标账单的Bid:";
		cin >> id;

		if (!checkRights(id)) {
			cout << "当前BID不可访问！" << endl;
			system("pause");
			system("cls");
			return;
		}

		cout << "即将删除Bid为" << id << " 的账单。是否继续？(是/否)";
		string choice;
		cin >> choice;
		if (choice != "是") {
			cout << "操作已取消！" << endl;
			system("pause");
			system("cls");
			return;
		}

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

// 重复检查函数
bool Hospital::checkRepeat(long long id) {
	Bill a;
	a.initVector();
	bool repeat = false;
	for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
		if (id == it->billBid)
			repeat = true;
	}

	return repeat;
}

// 权限检查函数
bool Hospital::checkRights(long long id) {
	bool right = false;
	for (vector<long long>::iterator it = rights.begin(); it != rights.end(); it++ ) {
		if (id == *it) {
			right = true;
		}
	}
	return right;
}
