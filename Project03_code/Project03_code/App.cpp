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
		cout << "1. �α���" << endl;
		cout << "2. ȸ������" << endl;
		cout << "3. �׽�Ʈ" << endl;
		cout << "4. ����" << endl;
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
				cout << "�α��� ����!" << endl;
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
				cout << "���� : ";
				int check;
				cin >> check;
				if (check == 1)
					showDB();
				else if (check == 2)
					showList();
				else if (check == 3)
					break;
				else
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Wrong!!!!" << endl;
				}
					
			}
		}
		else if (input == 4)
		{
			return;
		}
		else
		{
			cin.clear();
			cin.ignore(100, '\n');
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
		cout << "1. �ٹ� ����" << endl;
		cout << "2. ���� ���" << endl;
		cout << "3. ���� ��õ" << endl;
		cout << "4. ����" << endl;
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
			cin.clear();
			cin.ignore(100, '\n');
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
		cout << "1. ���ǰ� ���" << endl;
		cout << "2. �ٹ� ���" << endl;
		cout << "3. ����" << endl;
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
			cin.clear();
			cin.ignore(100, '\n');
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
		cout << "�߰��Ϸ�!" << endl;
	else
		cout << "�̹� �Էµ� ���̵��Դϴ�" << endl;
	return;
}

int App::login()
{
	int id; string password;
	cout << "ID : "; cin >> id;
	cout << "PW : "; cin >> password;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Wrong Input!" << endl;
	}
	currentUser = um->authenticateUser(id, password); //�α��� ������ ������ �Է�, �ƴҽ� nullptr
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
	//���������� ���н� -1, �����α��� 0, �����ڷα��� 1 ���
	return -2;
}

void App::buyAlbum()
{
	int index = 1;
	cout << "�ٹ� ���" << endl;
	for (vector<MusicAlbum>::iterator it = am->getAllAlbumList()->begin(); it != am->getAllAlbumList()->end(); it++)
	{
		Composer composer = cm->searchComposerById(it->getComposerId());
		cout << index << "��. " << composer.getName() << " - " << it->getName() << "(�������� : " << it->getPurchasedCount() << "ȸ)" << endl;
		index++;
	}

	cout << "�ٹ����̵� �Է����ּ��� : ";
	int input;
	cin >> input;
	if (input == 0)
		return;
	currentUser->getPurchasedList()->push_back(input);
	um->writeFileFromDB();
	am->updateMusicAlbumSellCount(input);
	cout << "���Ű� �Ϸ�Ǿ����ϴ�!" << endl;
}

void App::printPurchasedList()
{
	int index = 1;
	cout << "���� ���" << endl;
	for (vector<int>::iterator it = currentUser->getPurchasedList()->begin(); it != currentUser->getPurchasedList()->end(); it++)
	{
		MusicAlbum album = am->searchMusicAlbumById(*it); Composer composer = cm->searchComposerById(album.getComposerId());
		cout << index << "��. " << composer.getName() << " - " << album.getName() << "(�������� : " << album.getPurchasedCount() << "ȸ)" << endl;
		index++;
	}
}

void App::recommend()
{
	BaseRecommendationAlg *bralg;
	int input = -1;
	cout << "1. Top10 ����Ʈ\n";
	cout << "2. ���Ÿ�� ��� ��õ\n:";
	cin >> input;

	if (input == 1)
	{
		bralg = new RecommendTopTen(um, cm, am, currentUser);
		vector<MusicAlbum> topten = bralg->recommend();
		int index = 1;
		cout << "Top10 ���" << endl;
		for (vector<MusicAlbum>::iterator it = topten.begin(); it != topten.end(); it++)
		{
			Composer composer = cm->searchComposerById(it->getComposerId());
			cout << index << "��. " << composer.getName() << " - " << it->getName() << "(�������� : " << it->getPurchasedCount() << "ȸ)" << endl;
			index++;
		}
	}
	else if (input == 2)
	{
		bralg = new RecommendByPurchasedList(um, cm, am, currentUser);
		vector<MusicAlbum> musicList = bralg->recommend();
		int index = 1;
		cout << "���Ÿ�� ��� ��õ ���" << endl;
		for (vector<MusicAlbum>::iterator it = musicList.begin(); it != musicList.end(); it++)
		{
			Composer composer = cm->searchComposerById(it->getComposerId());
			cout << index << "����. " << composer.getName() << " - " << it->getName() << "(�������� : " << it->getPurchasedCount() << "ȸ)" << endl;
			index++;
		}
	}
	else
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "�߸��� �Է°��Դϴ�." << endl;
	}
	
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

	int index = 1;
	for (vector<Composer>::iterator it = cm->getAllComposerList()->begin(); it != cm->getAllComposerList()->end(); it++)
	{
		cout << index++ << ". " << it->getName() << endl;
	}

	cout << "���ǰ��� �̸����� �����Ͻʽÿ� : ";
	cin >> searchParam;
	if (cm->searchComposerByName(searchParam).getId() == -1)
	{
		cout << "���ǰ��� �����ϴ�." << endl;
		return;
	}
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
		cout << it->getId() << '\t' << it->getComposerId() << '\t' << it->getPurchasedCount() << '\t' << it->getName()  << '\t' << endl;
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
