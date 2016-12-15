#pragma once
#include "BaseRecommendationAlg.h"
class RecommendTopTen :
	public BaseRecommendationAlg
{
public:
	RecommendTopTen();
	RecommendTopTen(UserManager* um, ComposerManager* cm, AlbumManager* am, User * user);
	~RecommendTopTen();

	virtual vector<MusicAlbum> recommend();
};

