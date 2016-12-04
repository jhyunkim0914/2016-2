#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "RecommendTopTen.h"
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
	void login();
	void buyAlbum();
	void printPurchasedList();
	void recommend();

	void addComposer();
	void addAlbum();

private:
	BaseRecommendationAlg* rcdAlg;
	UserManager* um;
	ComposerManager* cm;
	AlbumManager* am;
	int currentUserId;
};

