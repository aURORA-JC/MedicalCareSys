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
	cout << "��ӭ����������ҽԺ��" << this->hospitalName << endl;
	cout << " --------------------------------------------------------\n"
		<< "|                                                        |\n"
		<< "|             1.����˵�  2.�г��˵�  3.ɾ���˵�         |\n"
		<< "|                                                        |\n"
		<< "|                          0.ע��                        |\n"
		<< "|                                                        |\n"
		<< " --------------------------------------------------------\n"
		<< "��ѡ��";
}

void Hospital::addBill() {
	ofstream ofs;
	ofs.open(BILL_FILE, ios::out | ios::app);
	
	int addNum;
	cout << "����˵�������" << endl;
	cin >> addNum;

	for (int i = 0; i < addNum; i++) {
		cout << "��ӵ� �� " << i + 1 << " �����˵�" << endl;

		long long w2billBid;
		cout << "�����˵�ID��" << endl;
		cin >> w2billBid;

		string w2billBelongs;
		cout << "����Ӧ�ɷ���ҽ�����ţ�" << endl;
		cin >> w2billBelongs;

		string w2billInfo;
		cout << "�����˵���Ϣ��" << endl;
		cin >> w2billInfo;

		double w2billValue;
		cout << "�����˵����" << endl;
		cin >> w2billValue;

		cout << "����¼���˵���Ϣ..." << endl;
		ofs << w2billBid << " " << w2billBelongs << " " << w2billInfo << " " << this->hospitalId << " " << w2billValue << " " << 1 << endl;
		cout << "�˵���Ϣ¼��ɹ���" << endl;
		
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