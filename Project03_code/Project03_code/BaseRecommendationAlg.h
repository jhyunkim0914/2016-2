#pragma once
//#include "MusicAlbum.h"
#include "AlbumManager.h"
#include "userManager.h"
#include "composerManager.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class BaseRecommendationAlg
{
public:
	BaseRecommendationAlg();
	BaseRecommendationAlg(UserManager* um, ComposerManager* cm, AlbumManager* am, User * user);
	~BaseRecommendationAlg();

	virtual vector<MusicAlbum> recommend() = 0;

public:
	AlbumManager* am;
	UserManager* um;
	ComposerManager* cm;
	User* user;
};

