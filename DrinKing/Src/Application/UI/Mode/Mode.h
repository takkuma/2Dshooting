#pragma once
#include"../../Object/BaseObject.h"

class Mode :public BaseObject
{
public:
	Mode() {};
	~Mode() { Release(); };
	//ÉÅÉWÉÉÅ[ä÷êî
	void Update()override;
	void Draw()override;
	void Init();
	void Release()override;
	void SetOwner(GameScene* a_owner) { m_owner = a_owner; }
private:
	KdTexture m_WaterTex;
	Math::Vector3 m_WaterPos;
	Math::Matrix m_WaterMat;

	KdTexture m_ColaTex;
	Math::Vector3 m_ColaPos;
	Math::Matrix m_ColaMat;

	KdTexture m_SportTex;
	Math::Vector3 m_SportPos;
	Math::Matrix m_SportMat;

	KdTexture m_ZkeyTex;
	Math::Vector3 m_ZkeyPos;
	Math::Matrix m_ZkeyMat;

	KdTexture m_XkeyTex;
	Math::Vector3 m_XkeyPos;
	Math::Matrix m_XkeyMat;

	KdTexture m_CkeyTex;
	Math::Vector3 m_CkeyPos;
	Math::Matrix m_CkeyMat;
};
