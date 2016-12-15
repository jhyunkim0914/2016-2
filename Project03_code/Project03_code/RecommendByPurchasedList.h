#pragma once
#include "BaseRecommendationAlg.h"
class RecommendByPurchasedList :
	public BaseRecommendationAlg
{
public:
	RecommendByPurchasedList();
	RecommendByPurchasedList(UserManager* um, ComposerManager* cm, AlbumManager* am, User * user);
	~RecommendByPurchasedList();

	virtual vector<MusicAlbum> recommend();
};

