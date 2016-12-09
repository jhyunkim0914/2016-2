#include "userManager.h"

UserManager::UserManager()
{
}

UserManager::~UserManager()
{
}

bool UserManager::setDBFromFile()
{
	ifstream inFile(fileName, ios::in | ios::binary);

	int isAdmin = -1;
	int id = -1;
	int passwordSize = -1;
	string password = "";
	int listSize = -1;
	int listSource = -1;
	vector<int> list;

	User temp;

	if (!inFile)
	{
		cout << "Cannot open file.\n";
		return false;
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
		temp.setIsAdmin(isAdmin);
		//아이디 입력
		inFile.read((char *)&id, sizeof(int));
		cout << id << '\t';
		temp.setId(id);
		//패스워드 사이즈 입력
		inFile.read((char *)&passwordSize, sizeof(int));
		cout << passwordSize << '\t';
		//패스워드 입력
		password.resize(passwordSize);
		inFile.read(&password[0], passwordSize);
		cout << password << '\t';
		temp.setPW(password);
		//리스트 사이즈 입력
		inFile.read((char *)&listSize, sizeof(int));
		cout << listSize << '\t';
		//리스트 사이즈만큼 반복
		for (int i = 0; i < listSize; i++)
		{
			//리스트 내용 입력
			inFile.read((char *)&listSource, sizeof(int));
			cout << listSource << '\t';
			list.push_back(listSource);
		}
		temp.setPurchasedList(list);
		userList.push_back(temp);
		cout << endl;
	}
	return true;
}

bool UserManager::writeFileFromDB()
{
	ofstream outFile(fileName, ios::out | ios::binary);
	if (!outFile)
	{
		cout << "Cannot open file.\n";
		return false;
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
		outFile.write((char *)insTemp.c_str(), inTemp);
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
	return true;
}

void UserManager::showDB()
{
	ifstream inFile(fileName, ios::in | ios::binary);

	int isAdmin = -1;
	int id = -1;
	int passwordSize = -1;
	string password = "";
	int listSize = -1;
	int listSource = -1;
	vector<int> list;

	User temp;

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
		temp.setIsAdmin(isAdmin);
		//아이디 입력
		inFile.read((char *)&id, sizeof(int));
		cout << id << '\t';
		temp.setId(id);
		//패스워드 사이즈 입력
		inFile.read((char *)&passwordSize, sizeof(int));
		cout << passwordSize << '\t';
		//패스워드 입력
		password.resize(passwordSize);
		inFile.read(&password[0], passwordSize);
		cout << password << '\t';
		temp.setPW(password);
		//리스트 사이즈 입력
		inFile.read((char *)&listSize, sizeof(int));
		cout << listSize << '\t';
		//리스트 사이즈만큼 반복
		for (int i = 0; i < listSize; i++)
		{
			//리스트 내용 입력
			inFile.read((char *)&listSource, sizeof(int));
			cout << listSource << '\t';
			list.push_back(listSource);
		}
		cout << endl;
	}
	inFile.close();
}

bool UserManager::addUserToFile(User addedUser)
{
	for (vector<User>::iterator it = userList.begin(); it != userList.end(); it++)
	{
		if (it->getId() == addedUser.getId())
		{
			return false;
		}
	}
	userList.push_back(addedUser); //userList에 해당 유저를 추가한다. (메모리)
	
	writeFileFromDB(); //userDB에 새로 쓴다.
	return true;
}

User* UserManager::authenticateUser(int _id, string _pw)
{
	for (vector<User>::iterator it = userList.begin(); it != userList.end(); it++)
	{
		if (it->getId() == _id)
		{
			if (it->getPW() == _pw)
				return &(*it);
			else
				return nullptr;
		}
	}
	return nullptr;
}

vector<int>* UserManager::getPurchasedListByUserId(int _id)
{
	for (vector<User>::iterator it = userList.begin(); it != userList.end(); it++)
	{
		if (it->getId() == _id)
		{
			return it->getPurchasedList();
		}
	}
	return nullptr;
}

vector<User>* UserManager::getAllUserList()
{
	return &userList;
}

bool UserManager::addAlbumIdToPurchaseList(int _userId, int _albumId)
{
	for (vector<User>::iterator it = userList.begin(); it != userList.end(); it++)
	{
		if (it->getId() == _userId)
		{
			it->getPurchasedList()->push_back(_albumId); //userList에 구매내역 추가 (메모리)
			writeFileFromDB(); //userDB에 새로 쓴다.
			return true;
		}
	}
	return false;
}
