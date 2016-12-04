#include "userManager.h"

UserManager::UserManager()
{
}

UserManager::UserManager(string fileName)
{
	setFileName(fileName);
}

UserManager::~UserManager()
{
}

bool UserManager::setDBFromFile()
{
	ifstream inFile("userDB", ios::in | ios::binary);

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
	int length = inFile.tellg();
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
		inFile.read(&password[0], sizeof(passwordSize));
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

bool UserManager::addUserToFile(User addedUser)
{
	for (vector<User>::iterator it = userList.begin(); it != userList.end(); it++)
	{
		if (it->getId() == addedUser.getId())
		{
			return false;
		}
	}
	userList.push_back(addedUser);
	return true;
}

bool UserManager::authenticateUser(int _id, string _pw)
{
	return false;
}

vector<int> UserManager::getPurchasedListByUserId(int _id)
{
	return vector<int>();
}

vector<User> UserManager::getAllUserList()
{
	return userList;
}

bool UserManager::addAlbumIdToPurchaseList(int _userId, int _albumId)
{
	return false;
}
