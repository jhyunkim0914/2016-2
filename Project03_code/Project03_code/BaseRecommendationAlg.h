#pragma once
//#include "MusicAlbum.h"
#include "AlbumManager.h"
#include "userManager.h"
#include "composerManager.h"
#include <vector>
#include <iostream>
class BaseRecommendationAlg
{
public:
	BaseRecommendationAlg();
	~BaseRecommendationAlg();

	virtual vector<MusicAlbum> recommend() = 0;

private:
	AlbumManager* am;
	UserManager* um;
	ComposerManager* cm;
};

