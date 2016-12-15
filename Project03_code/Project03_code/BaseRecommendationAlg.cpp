#include "BaseRecommendationAlg.h"

BaseRecommendationAlg::BaseRecommendationAlg()
{
}

BaseRecommendationAlg::BaseRecommendationAlg(UserManager * um, ComposerManager * cm, AlbumManager * am, User * user)
{
	this->um = um; this->cm = cm; this->am = am; this->user = user;
}

BaseRecommendationAlg::~BaseRecommendationAlg()
{
}
