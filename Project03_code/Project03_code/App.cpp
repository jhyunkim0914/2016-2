#include "App.h"

App::App()
{
	um = new UserManager(); um->setFileName("userDB");
	cm = new ComposerManager(); cm->setFileName("composerDB");
	am = new AlbumManager(); am->setFileName("albumDB");
}

App::~App()
{
}

void App::run()
{
	um->setDBFromFile();
	cm->setDBFromFile();
	am->setDBFromFile();

	int input = -1;
	while (1)
	{
		cout << "1. 로그인" << endl;
		cout << "2. 회원가입" << endl;
		cout << "3. 테스트" << endl;
		cout << "4. 종료" << endl;
		cin >> input;
		if (input == 1)
		{
			int loginResult = login();
			if (loginResult == 0)
			{
				printUserMenu();
			}
			else if (loginResult == 1)
			{
				printManagerMenu();
			}
			else
			{
				cout << "로그인 실패!" << endl;
			}
			
		}
		else if (input == 2)
		{
			userRegisteration();
		}
		else if (input == 3)
		{
			while (1)
			{
				cout << "선택 : ";
				int check;
				cin >> check;
				if (check == 1)
					showDB();
				else if (check == 2)
					showList();
				else if (check == 3)
					break;
				else
					cout << "Wrong!!!!" << endl;
			}
		}
		else if (input == 4)
		{
			break;
		}
		else
		{
			cout << "Wrong Input!" << endl;
		}
	}
	return;
}

void App::printUserMenu()
{
	cout << "UserLogin!" << endl;
	int input = -1;
	while (1)
	{
		cout << "1. 앨범 구매" << endl;
		cout << "2. 구매 목록" << endl;
		cout << "3. 음악 추천" << endl;
		cout << "4. 종료" << endl;
		cin >> input;
		if (input == 1)
		{
			buyAlbum();
		}
		else if (input == 2)
		{
			printPurchasedList();
		}
		else if (input == 3)
		{
			recommend();
		}
		else if (input == 4)
		{
			break;
		}
		else
		{
			cout << "Wrong Input!" << endl;
		}
	}
	return;
}

void App::printManagerMenu()
{
	cout << "ManagerLogin!" << endl;
	int input = -1;
	while (1)
	{
		cout << "1. 음악가 등록" << endl;
		cout << "2. 앨범 등록" << endl;
		cout << "3. 종료" << endl;
		cin >> input;
		if (input == 1)
		{
			addComposer();
		}
		else if (input == 2)
		{
			addAlbum();
		}
		else if (input == 3)
		{
			break;
		}
		else
		{
			cout << "Wrong Input!" << endl;
		}
	}
	return;
}

void App::userRegisteration()
{
	User addedUser;
	addedUser.setUserFromKB();
	if (um->addUserToFile(addedUser) == true)
		cout << "추가완료!" << endl;
	else
		cout << "이미 입력된 아이디입니다" << endl;
	return;
}

int App::login()
{
	int id; string password;
	cout << "ID : "; cin >> id;
	cout << "PW : "; cin >> password;
	currentUser = um->authenticateUser(id, password); //로그인 성공시 포인터 입력, 아닐시 nullptr
	if (currentUser == nullptr)
	{
		return -1;
	}
	else
	{
		if (currentUser->getIsAdmin() == 0)
			return 0;
		else if (currentUser->getIsAdmin() == 1)
			return 1;
	}
	//최종적으로 실패시 -1, 유저로그인 0, 관리자로그인 1 출력
	return -2;
}

void App::buyAlbum()
{
	cout << "앨범아이디 : ";
	int input;
	cin >> input;
	currentUser->getPurchasedList()->push_back(input);
	um->writeFileFromDB();
	am->updateMusicAlbumSellCount(input);
}

void App::printPurchasedList()
{
	int index = 1;
	cout << "구매 목록" << endl;
	for (vector<int>::iterator it = currentUser->getPurchasedList()->begin(); it != currentUser->getPurchasedList()->end(); it++)
	{
		MusicAlbum album = am->searchMusicAlbumById(*it); Composer composer = cm->searchComposerById(album.getComposerId());
		cout << index << "번. " << composer.getName() << " - " << album.getName() << "(구매지수 : " << album.getPurchasedCount() << "회)" << endl;
	}
}

void App::recommend()
{
}

void App::addComposer()
{
	Composer addedComposer;
	addedComposer.setComposerFromKB();
	cm->addComposerToFile(addedComposer);
	
	return;
}

void App::addAlbum()
{
	Composer composer;
	string searchParam;

	cout << "음악가를 선택하십시오 : ";
	cin >> searchParam;
	composer = cm->searchComposerByName(searchParam);
	MusicAlbum album;
	album.setAlbumFromKB();
	album.setPurchasedCount(0);
	album.setComposerId(composer.getId());
	am->addMusicAlbumToFile(album);
	return;
}

void App::showList()
{
	cout << "userList" << endl;
	for (vector<User>::iterator it = um->getAllUserList()->begin(); it != um->getAllUserList()->end(); it++)
	{
		cout << it->getIsAdmin() << '\t' << it->getId() << '\t' << it->getPW() << '\t';
		for (vector<int>::iterator it2 = it->getPurchasedList()->begin(); it2 != it->getPurchasedList()->end(); it2++)
		{
			cout << *it2 << ' ';
		}
		cout << endl;
	}
	cout << "composerList" << endl;
	for (vector<Composer>::iterator it = cm->getAllComposerList()->begin(); it != cm->getAllComposerList()->end(); it++)
	{
		cout << it->getId() << '\t' << it->getName() << endl;
	}
	cout << "albumList" << endl;
	for (vector<MusicAlbum>::iterator it = am->getAllAlbumList()->begin(); it != am->getAllAlbumList()->end(); it++)
	{
		cout << it->getId() << '\t' << it->getId() << '\t' << it->getComposerId() << '\t' << it->getName() << '\t' << it->getPurchasedCount() << '\t' << endl;
	}
}

void App::showDB()
{
	cout << "userDB" << endl;
	um->showDB();
	cout << "composerDB" << endl;
	cm->showDB();
	cout << "albumDB" << endl;
	am->showDB();
}
