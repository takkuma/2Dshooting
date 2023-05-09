#pragma once
#include"../../Object/BaseObject.h"

class Rank :public BaseObject
{
public:
	Rank() {};
	~Rank() { Release(); };
	//ƒƒWƒƒ[ŠÖ”
	void Update()override;
	void Draw()override;
	void Init();
	void Release()override;
	void SetOwner(GameScene* a_owner) { m_owner = a_owner; }
private:
	Math::Vector3 m_pos[4];
	Math::Matrix m_mat[4];

	KdTexture m_SlashTex;
	Math::Vector3 m_SlashPos;
	Math::Matrix m_SlashMat;

	int m_tenRank;
	int m_oneRank;
};
