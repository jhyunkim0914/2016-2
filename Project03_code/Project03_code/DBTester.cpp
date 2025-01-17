#include "DBTester.h"



DBTester::DBTester()
{
}


DBTester::~DBTester()
{
}

void DBTester::inFile()
{
	vector<User> userList;
	vector<int> tempList;

	User temp1;
	temp1.setIsAdmin(1);
	temp1.setId(1024);
	temp1.setPW("a");
	tempList.push_back(1); tempList.push_back(2);
	temp1.setPurchasedList(tempList);
	userList.push_back(temp1);

	User temp2;
	temp2.setIsAdmin(0);
	temp2.setId(2048);
	temp2.setPW("bc");
	tempList.clear(); tempList.push_back(3);
	temp2.setPurchasedList(tempList);
	userList.push_back(temp2);

	User temp3;
	temp3.setIsAdmin(0);
	temp3.setId(2049);
	temp3.setPW("def");
	tempList.clear(); tempList.push_back(2); tempList.push_back(5);
	temp3.setPurchasedList(tempList);
	userList.push_back(temp3);


	ofstream outFile("userDB", ios::out | ios::binary);
	if (!outFile)
	{
		cout << "Cannot open file.\n";
		return;
	}
	for (vector<User>::iterator it = userList.begin(); it != userList.end(); it++)
	{
		//관리자 여부 입력
		int inTemp = it->getIsAdmin();
		outFile.write((char *)&inTemp, sizeof(int));
		//아이디 입력
		inTemp = it->getId();
		outFile.write((char *)&inTemp, sizeof(int));
		//패스워드 사이즈 입력
		inTemp = it->getPW().size();
		outFile.write((char *)&inTemp, sizeof(int));
		//패스워드 입력
		string insTemp = it->getPW();
		outFile.write((char *)insTemp.c_str(), sizeof(insTemp.size()));
		//구입목록 사이즈 입력
		inTemp = it->getPurchasedList()->size();
		outFile.write((char *)&inTemp, sizeof(int));
		//구입목록 입력
		for (int i = 0; i < inTemp; i++)
		{
			//구입목록 각각 입력
			int inTemp2 = it->getPurchasedList()->at(i);
			outFile.write((char *)&inTemp2, sizeof(int));
		}
	}
	outFile.close();
}

void DBTester::outFile()
{
	ifstream inFile("userDB", ios::in | ios::binary);

	int isAdmin = -1;
	int id = -1;
	int passwordSize = -1;
	string password = "";
	int listSize = -1;
	int listSource = -1;

	if (!inFile)
	{
		cout << "Cannot open file.\n";
		return;
	}

	//파일 길이를 설정한다.
	inFile.seekg(0, inFile.end);
	std::streampos length = inFile.tellg();
	inFile.seekg(0, inFile.beg);

	//파일의 끝까지 반복, length위치 주의!
	while (length != inFile.tellg())
	{
		//관리자 여부 입력
		inFile.read((char *)&isAdmin, sizeof(int));
		cout << isAdmin << '\t';
		//아이디 입력
		inFile.read((char *)&id, sizeof(int));
		cout << id << '\t';
		//패스워드 사이즈 입력
		inFile.read((char *)&passwordSize, sizeof(int));
		cout << passwordSize << '\t';
		//패스워드 입력
		password.resize(passwordSize);
		inFile.read(&password[0], sizeof(passwordSize));
		cout << password << '\t';
		//리스트 사이즈 입력
		inFile.read((char *)&listSize, sizeof(int));
		cout << listSize << '\t';
		//리스트 사이즈만큼 반복
		for (int i = 0; i < listSize; i++)
		{
			//리스트 내용 입력
			inFile.read((char *)&listSource, sizeof(int));
			cout << listSource << '\t';
		}

		cout << endl;
	}
	inFile.close();
}
