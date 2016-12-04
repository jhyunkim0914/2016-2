#pragma once
#include "User.h"
#include "BaseManager.h"
#include <fstream>
class UserManager :
	public BaseManager
{
public:
	UserManager();
	UserManager(string fileName);
	~UserManager();

public:
	bool setDBFromFile();
	bool addUserToFile(User addedUser);
	bool authenticateUser(int _id, string _pw);
	vector<int> getPurchasedListByUserId(int _id);
	vector<User> getAllUserList();	
	bool addAlbumIdToPurchaseList(int _userId, int _albumId);

private:
	vector<User> userList;
};

