#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "RecommendTopTen.h"
#include "RecommendByPurchasedList.h"
#include "DBTester.h"

class App
{
public:
	App();
	~App();

	void run();
	
private:
	void printUserMenu();
	void printManagerMenu();

	void userRegisteration();
	int login();
	void buyAlbum();
	void printPurchasedList();
	void recommend();

	void addComposer();
	void addAlbum();

	void showList();
	void showDB();

private:
	BaseRecommendationAlg* rcdAlg;
	UserManager* um;
	ComposerManager* cm;
	AlbumManager* am;
	User* currentUser;
};

