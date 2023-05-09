#include "Mode.h"
#include "../../Scene/GameScene/GameScene.h"

void Mode::Update()
{
	m_WaterMat = Math::Matrix::CreateTranslation(m_WaterPos);
	m_ZkeyMat = Math::Matrix::CreateTranslation(m_ZkeyPos);
	m_ColaMat = Math::Matrix::CreateTranslation(m_ColaPos);
	m_XkeyMat = Math::Matrix::CreateTranslation(m_XkeyPos);
	m_SportMat = Math::Matrix::CreateTranslation(m_SportPos);
	m_CkeyMat = Math::Matrix::CreateTranslation(m_CkeyPos);
}

void Mode::Draw()
{
	for (auto& obj : m_owner->GetObjectList())
	{
		obj->GetObjType() == ObjectType::Player;
		m_rank = obj->GetRank();
	}
	//水
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_WaterMat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_WaterTex, 0, 0);
	
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_ZkeyMat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_ZkeyTex, 0, 0);

	if (m_rank < 35)
	{
		//コーラ
		KdShaderManager::Instance().m_spriteShader.SetMatrix(m_ColaMat);
		KdShaderManager::Instance().m_spriteShader.DrawTex(&m_ColaTex, 0, 0);

		KdShaderManager::Instance().m_spriteShader.SetMatrix(m_XkeyMat);
		KdShaderManager::Instance().m_spriteShader.DrawTex(&m_XkeyTex, 0, 0);
	}
	if (m_rank < 21)
	{
		//スポドリ
		KdShaderManager::Instance().m_spriteShader.SetMatrix(m_SportMat);
		KdShaderManager::Instance().m_spriteShader.DrawTex(&m_SportTex, 0, 0);

		KdShaderManager::Instance().m_spriteShader.SetMatrix(m_CkeyMat);
		KdShaderManager::Instance().m_spriteShader.DrawTex(&m_CkeyTex, 0, 0);
	}
}

void Mode::Init()
{
	//水モード
	m_WaterTex.Load("Asset/Textures/UI/UI_water.png");
	m_WaterPos = { -350,360 - 35,0 };
	m_WaterMat = Math::Matrix::Identity;

	m_ZkeyTex.Load("Asset/Textures/UI/Zkey.png");
	m_ZkeyPos = { -350,360 - 67,0 };
	m_ZkeyMat = Math::Matrix::Identity;

	//コーラモード
	m_ColaTex.Load("Asset/Textures/UI/UI_cola.png");
	m_ColaPos = { -310,360 - 35,0 };
	m_ColaMat = Math::Matrix::Identity;

	m_XkeyTex.Load("Asset/Textures/UI/Xkey.png");
	m_XkeyPos = { -310,360 - 67,0 };
	m_XkeyMat = Math::Matrix::Identity;

	//スポドリモード
	m_SportTex.Load("Asset/Textures/UI/UI_sport.png");
	m_SportPos = { -270,360 - 35,0 };
	m_SportMat = Math::Matrix::Identity;

	m_CkeyTex.Load("Asset/Textures/UI/Ckey.png");
	m_CkeyPos = { -270,360 - 67,0 };
	m_CkeyMat = Math::Matrix::Identity;
}

void Mode::Release()
{
}
