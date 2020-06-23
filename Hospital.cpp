#include "Hospital.h"

void printBill(Bill& b);

Hospital::Hospital() {

}

Hospital::Hospital(long long hospitalHid, string hospitalId, string hospitalName, int hospitalLevel, string hospitalArea) {
	this->hospitalHid = hospitalHid;
	this->hospitalId = hospitalId;
	this->hospitalName = hospitalName;
	this->hospitalLevel = hospitalLevel;
	this->hospitalArea = hospitalArea;
}

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
	for_each(list.begin(), list.end(), printBill);
	system("pause");
	system("cls");
}

void Hospital::deleteBill() {
	
}