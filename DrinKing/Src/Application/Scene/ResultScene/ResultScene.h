#pragma once
#include "../BaseScene.h"

class ResultScene :public BaseScene
{
public:
	ResultScene() {};
	~ResultScene() {};

	void Update()override;
	void Draw()override;
	void Init()override;
	void Release()override;
private:
	int m_rank;

	KdTexture m_tex;
	Math::Vector3 m_pos[2];
	Math::Matrix m_mat[2];
    int m_tenRank;
	int m_oneRank;
	Math::Rectangle rc={0,0,32,32};

	KdTexture m_RankTex;
	Math::Vector3 m_RankPos;
	Math::Matrix m_RankMat;
	Math::Matrix m_RankTransMat;
	Math::Matrix m_RankScaleMat;
	int m_score = 0;
};
