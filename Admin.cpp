// Admin.cpp - MedicalSys for class CPP Programming
// version 0.1.2 fixed - dev at 2020.06.25 - produce by aurorajc

#include "Admin.h"

// ��ʾ��ʽ�趨����
void printUser(User& u);
void printHospital(Hospital& h);
void printBill(Bill& b);

// ���ι��캯��
Admin::Admin(string adminId, string adminName, string adminArea) {
	this->adminId = adminId;
	this->adminName = adminName;
	this->adminArea = adminArea;

	// ��ʼ���ڴ�
	this->initVector();
}

// ����Ա�˵�����
void Admin::openMenu() {
	cout << "��ӭ����������Ա��" << this->adminName << endl;
	cout << " --------------------------------------------------------\n"
		<< "|                                                        |\n"
		<< "|     1.����û�      2.��Ӷ���ҽԺ     3.����˵�      |\n"
		<< "|                                                        |\n"
		<< "|     4.�г��û�      5.�г�����ҽԺ     6.�г��˵�      |\n"
		<< "|                                                        |\n"
		<< "|     7.�����û�      8.��������ҽԺ     9.�����˵�      |\n"
		<< "|                                                        |\n"
		<< "|     10.�༭�û�     11.�༭����ҽԺ    12.ɾ���û�     |\n"
		<< "|                                                        |\n"
		<< "|     13.ɾ������ҽԺ   14.ɾ���˵�   15.���ȫ������    |\n"
		<< "|                                                        |\n"
		<< "|                         0.ע��                         |\n"
		<< "|                                                        |\n"
		<< " --------------------------------------------------------\n"
		<< "��ѡ��";
}

// ����û�����
void Admin::addUser() {
	ofstream ofs;
	ofs.open(USER_FILE,ios::out | ios::app);
	
	int addNum;
	cout << "����û�������" << endl;
	cin >> addNum;

	for (int i = 0; i < addNum; i++) {
		cout << "��ӵ� �� " << i+1 << " �����û�" << endl;

		long long w2usrUid;
		cout << "�����û���ţ�" << endl;
		cin >> w2usrUid;

		if (checkRepeat(w2usrUid, "0", 1, 1)) {
			cout << "ҽ�������Ѵ��ڣ�" << endl;
			continue;
		}

		string w2usrMedicalCardNum;
		cout << "����ҽ�����ţ�" << endl;
		cin >> w2usrMedicalCardNum;

		if (checkRepeat(0, w2usrMedicalCardNum, 2, 1)) {
			cout << "ҽ�������Ѵ��ڣ�" << endl;
			continue;
		}

		string w2sysName;
		cout << "����ҽ��ϵͳ�û�����" << endl;
		cin >> w2sysName;

		string w2sysPassword;
		cout << "����ҽ��ϵͳ���룺" << endl;
		cin >> w2sysPassword;

		string w2usrName;
		cout << "�����û�������" << endl;
		cin >> w2usrName;

		int w2usrAge;
		cout << "�����û����䣺" << endl;
		cin >> w2usrAge;

		string w2usrSex;
		cout << "�����û��Ա�" << endl;
		cin >> w2usrSex;

		string w2usrIdCardNum;
		cout << "�����û�֤���ţ�" << endl;
		cin >> w2usrIdCardNum;

		string w2usrNation;
		cout << "�����û����壺" << endl;
		cin >> w2usrNation;

		string w2usrIdClass;
		cout << "�����û����" << endl;
		cin >> w2usrIdClass;

		string w2usrInHospital;
		cout << "�û���ǰ�Ƿ�סԺ���ǡ��񣩣�" << endl;
		cin >> w2usrInHospital;

		double w2usrCardBalance = 0;
		cout << "����ҽ�������" << endl;
		cin >> w2usrCardBalance;

		string w2usrCareArea;
		cout << "����ҽ��������" << endl;
		cin >> w2usrCareArea;

		cout << "��Ϣ¼����..." << endl;
		ofs << w2usrUid << " " << w2sysName << " " << w2sysPassword << " " << w2usrMedicalCardNum << " "<< w2usrName << " " << w2usrAge << " " << w2usrSex << " " << w2usrIdCardNum << " " << w2usrNation << " " << w2usrIdClass << " " << w2usrInHospital << " " << w2usrCardBalance << " " << w2usrCareArea << endl;
		cout << "¼��ɹ���" << endl;

		system("pause");
		this->initVector();
	}

	system("cls");
	ofs.close();
}

// ��Ӷ���ҽԺ����
void Admin::addHospital() {
	ofstream ofs;
	ofs.open(HOSPITAL_FILE, ios::out | ios::app);

	int addNum;
	cout << "��Ӷ���ҽԺ������" << endl;
	cin >> addNum;

	for (int i = 0; i < addNum; i++) {
		cout << "��ӵ� �� " << i + 1 << " ��������ҽԺ" << endl;

		long long w2hospitalHid;
		cout << "����ҽԺ��ţ�" << endl;
		cin >> w2hospitalHid;
		
		if (checkRepeat(w2hospitalHid, "0", 1, 2)) {
			cout << "ҽԺ����Ѵ��ڣ�" << endl;
			continue;
		}

		string w2hospitalId;
		cout << "���붨��ҽԺ�����ţ�" << endl;
		cin >> w2hospitalId;

		if (checkRepeat(0,w2hospitalId, 2, 2)) {
			cout << "����ҽԺ�������Ѵ��ڣ�" << endl;
			continue;
		}

		string w2hospitalUsrName;
		cout << "����ҽ��ϵͳ�û�����" << endl;
		cin >> w2hospitalUsrName;

		string w2hospitalPasswd;
		cout << "����ҽ��ϵͳ���룺" << endl;
		cin >> w2hospitalPasswd;

		string w2hospitalName;
		cout << "����ҽԺ���ƣ�" << endl;
		cin >> w2hospitalName;

		int w2hospiatlLevel;
		cout << "����ҽԺ�ȼ���" << endl;
		cin >> w2hospiatlLevel;

		string w2hosptialArea;
		cout << "����ҽԺ����������" << endl;
		cin >> w2hosptialArea;

		cout << "��Ϣ¼����..." << endl;
		ofs << w2hospitalHid << " " << w2hospitalUsrName << " " << w2hospitalPasswd << " " << w2hospitalId << " " << w2hospitalName << " " << w2hospiatlLevel << " " << w2hosptialArea << endl;
		cout << "¼��ɹ���" << endl;
		
		system("pause");
		this->initVector();
	}

	system("cls");
	ofs.close();
}

// ����˵�����
void Admin::addBill() {
	ofstream ofs;
	ofs.open(BILL_FILE, ios::out | ios::app);

	int addNum;
	cout << "����˵�������" << endl;
	cin >> addNum;

	for (int i = 0; i < addNum; i++) {
		cout << "��ӵ� �� " << i + 1 << " �����˵�" << endl;

		long long w2billBid;
		cout << "�����˵���ţ�" << endl;
		cin >> w2billBid;

		if (checkRepeat(w2billBid, "0", 1, 3)) {
			cout << "�˵�����Ѵ��ڣ�" << endl;
			continue;
		}

		string w2billBelongs;
		cout << "�����˵�" << endl;
		cin >> w2billBelongs;

		string w2billInfo;
		cout << "����Ӧ�ɷ���ҽ�����ţ�" << endl;
		cin >> w2billInfo;

		string w2billSource;
		cout << "�����˵���Ϣ��" << endl;
		cin >> w2billSource;

		double w2billValue;
		cout << "�����˵���" << endl;
		cin >> w2billValue;

		string w2billStatus;
		string status;
		cout << "����֧��״̬����/��:" << endl;
		cin >> status;
		if (status == "��") {
			w2billStatus = "��֧��";
		}
		else {
			w2billStatus = "δ֧��";
		}
		
		cout << "��Ϣ¼����..." << endl;
		ofs << w2billBid << " " << w2billBelongs << " " << w2billInfo << " " << w2billSource << " " << w2billValue << " " << w2billStatus << endl;
		cout << "¼��ɹ���" << endl;

		system("pause");
		this->initVector();
	}

	system("cls");
	ofs.close();
}

// ��ʾ�����û���Ϣ����
void Admin::showUser() {
	cout << "�����û���Ϣ���£�" << endl;
	if (!user.empty()) {
		for_each(user.begin(), user.end(), printUser);
	}
	else {
		cout << "��" << endl;
	}
	system("pause");
	system("cls");
}

// ��ʾ���ж���ҽԺ��Ϣ����
void Admin::showHospital() {
	cout << "���ж���ҽԺ��Ϣ���£�" << endl;
	if (!hospital.empty()) {
		for_each(hospital.begin(), hospital.end(), printHospital);
	}
	else {
		cout << "��" << endl;
	}
	system("pause");
	system("cls");
}

// ��ʾ�����˵�����
void Admin::showBill() {
	cout << "�����˵���Ϣ���£�" << endl;
	if (!bill.empty()) {
		for_each(bill.begin(), bill.end(), printBill);
	}
	else {
		cout << "��" << endl;
	}
	system("pause");
	system("cls");
}

// �����û���������
void Admin::searchUser() {
	usrList.clear();
	string choice;
	
	usrList.clear();
	cout << "ѡ���������ݣ�" << endl
		<< "  1.ҽ������\n"
		<< "  2.����\n"
		<< "  3.֤����" << endl
		<< "�����룺";
	cin >> choice;
	if (choice == "1") {
		string id;
		cout << "����ҽ�����ţ�";
		cin >> id;
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->usrMedicalCardNum) {
				usrList.push_back(*it);
			}
		}
	}
	else if (choice == "2") {
		string id;
		cout << "����������";
		cin >> id;
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->usrName) {
				usrList.push_back(*it);
			}
		}
	}
	else if (choice == "3") {
		string id;
		cout << "����֤���ţ�";
		cin >> id;
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->usrIdCardNum) {
				usrList.push_back(*it);
			}
		}
	}
	else {
		cout << "�������" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����������£�" << endl;
	if (!usrList.empty()) {
		for_each(usrList.begin(), usrList.end(), printUser);
	}
	else {
		cout << "��" << endl;
	}

	system("pause");
	system("cls");
}

// ��������ҽԺ����
void Admin::searchHospital() {
	hospitalList.clear();
	string choice;
	
	hospitalList.clear();
	cout << "ѡ���������ݣ�" << endl
		<< "  1.������\n"
		<< "  2.����" << endl
		<< "�����룺";
	cin >> choice;
	if (choice == "1") {
		string id;
		cout << "��������ţ�";
		cin >> id;
		for (vector<Hospital>::iterator it = hospital.begin(); it != hospital.end(); it++) {
			if (id == it->hospitalId) {
				hospitalList.push_back(*it);
			}
		}
	}
	else if (choice == "2") {
		string id;
		cout << "����ҽԺ����";
		cin >> id;
		for (vector<Hospital>::iterator it = hospital.begin(); it != hospital.end(); it++) {
			if (id == it->hospitalName) {
				hospitalList.push_back(*it);
			}
		}
	}
	else {
		cout << "�������" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����������£�" << endl;
	if (!hospitalList.empty()) {
		for_each(hospitalList.begin(), hospitalList.end(), printHospital);
	}
	else {
		cout << "��" << endl;
	}

	system("pause");
	system("cls");
}

// �����˵�����
void Admin::searchBill() {
	billList.clear();
	string choice;

	hospitalList.clear();
	cout << "ѡ���������ݣ�" << endl
		<< "  1.ҽ������\n"
		<< "  2.����ҽԺ������" << endl
		<< "�����룺";
	cin >> choice;

	if (choice == "1") {
		string id;
		cout << "����ҽ�����ţ�";
		cin >> id;
		for (vector<Bill>::iterator it = bill.begin(); it != bill.end(); it++) {
			if (id == it->billBelongs) {
				billList.push_back(*it);
			}
		}
	}
	else if (choice == "2") {
		string id;
		cout << "��������ţ�";
		cin >> id;
		for (vector<Bill>::iterator it = bill.begin(); it != bill.end(); it++) {
			if (id == it->billSource) {
				billList.push_back(*it);
			}
		}
	}
	else {
		cout << "�������" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����������£�" << endl;
	if (!billList.empty()) {
		for_each(billList.begin(), billList.end(), printBill);
	}
	else {
		cout << "��" << endl;
	}

	system("pause");
	system("cls");
}

// �༭�û���Ϣ����
void Admin::editUser() {
	this->searchUser();

	long long id;
	cout << endl << "�����޸��û���Uid:";
	cin >> id;

	string choice;
	cout << "ѡ���޸����ݣ�" << endl
		<< "  1.����\n"
		<< "  2.����\n"
		<< "  3.��Ա���\n" 
		<< "  4.�˻����\n" 
		<< "  5.��������\n" << endl;
	cin >> choice;

	if (choice == "1") {
		cout << "����������" << endl;
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->usrUid) {
				cin >> it->usrName;
			}
		}
	}
	else if (choice == "2") {
		cout << "�������䣺" << endl;
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->usrUid) {
				cin >> it->usrAge;
			}
		}
	}
	else if (choice == "3") {
		cout << "�������" << endl;
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->usrUid) {
				cin >> it->usrIdClass;
			}
		}
	}
	else if (choice == "4") {
		cout << "������" << endl;
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->usrUid) {
				cin >> it->usrCardBanlance;
			}
		}
	}
	else if (choice == "5") {
		cout << "��������������" << endl;
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->usrUid) {
				cin >> it->usrCareArea;
			}
		}
	}
	else {
		cout << "�������" << endl;
		system("pause");
		system("cls");
		return;
	}

	updateData(1);
	cout << "�޸ĳɹ���" << endl;

	system("pause");
	system("cls");
}

// �༭����ҽԺ��Ϣ����
void Admin::editHospital() {
	this->searchHospital();

	long long id;
	cout << endl << "�����޸�ҽԺ��Hid:";
	cin >> id;

	string choice;
	cout << "ѡ���޸����ݣ�" << endl
		<< "  1.������\n"
		<< "  2.ҽԺ��\n"
		<< "  3.��������" << endl;
	cin >> choice;

	if (choice == "1") {
		cout << "��������ţ�" << endl;
		for (vector<Hospital>::iterator it = hospital.begin(); it != hospital.end(); it++) {
			if (id == it->hospitalHid) {
				cin >> it->hospitalId;
			}
		}
	}
	else if (choice == "2") {
		cout << "����ҽԺ����" << endl;
		for (vector<Hospital>::iterator it = hospital.begin(); it != hospital.end(); it++) {
			if (id == it->hospitalHid) {
				cin >> it->hospitalName;
			}
		}
	}
	else if (choice == "3") {
		cout << "��������������" << endl;
		for (vector<Hospital>::iterator it = hospital.begin(); it != hospital.end(); it++) {
			if (id == it->hospitalHid) {
				cin >> it->hospitalArea;
			}
		}
	}
	else {
		cout << "�������" << endl;
		system("pause");
		system("cls");
		return;
	}

	updateData(2);
	cout << "�޸ĳɹ���" << endl;

	system("pause");
	system("cls");
}

// ɾ���û���Ϣ����
void Admin::deleteUser() {
	this->searchUser();

	long long id;
	cout << endl << "����ɾ���û���Uid:";
	cin >> id;
	cout << "����ɾ��UidΪ" << id << " ���û����Ƿ������(��/��)";
	string choice;
	cin >> choice;
	if (choice != "��") {
		cout << "������ȡ����" << endl;
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
	cout << "ɾ���ɹ���" << endl;
	
	system("pause");
	system("cls");
}

// ɾ��ҽԺ��Ϣ����
void Admin::deleteHospital() {
	this->searchHospital();

	long long id;
	cout << endl << "����ɾ��ҽԺ��Hid:";
	cin >> id;
	cout << "����ɾ��HidΪ" << id << "��ҽԺ���Ƿ������(��/��)";
	string choice;
	cin >> choice;
	if (choice != "��") {
		cout << "������ȡ����" << endl;
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
	cout << "ɾ���ɹ���" << endl;
	
	system("pause");
	system("cls");
}

// ɾ���˵���Ϣ����
void Admin::deleteBill() {
	this->searchBill();
	
	long long id;
	cout << endl << "����ɾ���˵���Bid:";
	cin >> id;
	cout << "����ɾ��BidΪ" << id << "���˵����Ƿ������(��/��)";
	string choice;
	cin >> choice;
	if (choice != "��") {
		cout << "������ȡ����" << endl;
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
	cout << "ɾ���ɹ���" << endl;
	
	system("pause");
	system("cls");
}

// ����������ݺ���
void Admin::deleteAll() {
	cout << "���棡����׼������������ݣ��˲��������棡" << endl;

	string choice;
	cout << "�Ƿ���������������롮�ǡ�" << endl;
	cin >> choice;

	if (choice == "��") {
		ofstream ofs;
		ofs.open(USER_FILE, ios::trunc);
		ofs.close();

		ofs.open(HOSPITAL_FILE, ios::trunc);
		ofs.close();

		ofs.open(BILL_FILE, ios::trunc);
		ofs.close();

		cout << "����ɹ���" << endl;
		
		this->initVector();
		system("pause");
		system("cls");
	}
	else {
		cout << "������ȡ����" << endl;
		system("pause");
		system("cls");
		return;
	}
}

// ������ʼ������
void Admin::initVector() {
	// �������
	user.clear();
	hospital.clear();
	bill.clear();

	ifstream ifs;
	
	// ��ȡ�û���Ϣ
	ifs.open(USER_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "��ȡ����ʧ�ܣ�USER_FILE ERROR!" << endl;
		return;
	}

	User u;
	while (ifs >> u.usrUid && ifs >> u.username && ifs >> u.passwd && ifs >> u.usrMedicalCardNum && ifs >> u.usrName && ifs >> u.usrAge && ifs >> u.usrSex && ifs >> u.usrIdCardNum && ifs >> u.usrNation && ifs >> u.usrIdClass && ifs >> u.usrInHospital && ifs >> u.usrCardBanlance && ifs >> u.usrCareArea) {
		user.push_back(u);
	}
	cout << "��ǰ�û���Ϊ��" << user.size() << " ��" << endl;
	ifs.close();

	// ��ȡҽԺ��Ϣ
	ifs.open(HOSPITAL_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "��ȡ����ʧ�ܣ�HOSPITAL_FILE ERROR!" << endl;
		return;
	}

	Hospital h;
	while (ifs >> h.hospitalHid && ifs >> h.username && ifs >> h.passwd && ifs >> h.hospitalId && ifs >> h.hospitalName && ifs >> h.hospitalLevel && ifs >> h.hospitalArea) {
		hospital.push_back(h);
	}
	cout << "��ǰ����ҽԺ����Ϊ��" << hospital.size()  << " ��"<< endl;
	ifs.close();

	// ��ȡ�˵���Ϣ
	ifs.open(BILL_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "��ȡ����ʧ�ܣ�BILL_FILE ERROR!" << endl;
		return;
	}

	Bill b;
	while (ifs >> b.billBid && ifs >> b.billBelongs && ifs >> b.billInfo && ifs >> b.billSource && ifs >> b.billValue && ifs >> b.billStatus) {
		bill.push_back(b);
	}
	cout << "��ǰ�˵�����Ϊ��" << bill.size() << " ��" << endl;
	ifs.close();
}

// �ظ���麯��
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

// �������ݺ���
void Admin::updateData(int choice) {
	ofstream ofs;

	// �����û�
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

	// ����ҽԺ
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

	// �����˵�
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
