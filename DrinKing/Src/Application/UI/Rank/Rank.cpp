#include "Rank.h"
#include "../../Scene/GameScene/GameScene.h"

void Rank::Update()
{
	//Œ»Ý‚Ì‡ˆÊ‚ÌXV
	for (auto& obj : m_owner->GetObjectList())
	{
		obj->GetObjType() == ObjectType::Player;
		//10‚ÌŒ…
		m_tenRank = obj->GetRank() / 10;
		//1‚ÌŒ…
		m_oneRank = obj->GetRank() % 10;
	}

	for (int i = 0; i < 4; i++)
	{
		Math::Matrix transMat;
		transMat = Math::Matrix::CreateTranslation(m_pos[i]);
		m_mat[i] = transMat;
	}

	m_SlashMat = Math::Matrix::CreateTranslation(m_SlashPos);
}

void Rank::Draw()
{
	//”Žš‚Ì•\Ž¦
	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			rc = { 0,0,32,64 };
			KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mat[i]);
			KdShaderManager::Instance().m_spriteShader.DrawTex(&m_tex, 0, 0, 32, 64, &rc);
		}
		else if (i % 3 == 0)
		{
			rc = { 32 * m_tenRank,0,32,64 };
			KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mat[i]);
			KdShaderManager::Instance().m_spriteShader.DrawTex(&m_tex, 0, 0, 32, 64, &rc);
		}
		else if (i % 2 == 0)
		{
			rc = { 32 * m_oneRank,0,32,64 };
			KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mat[i]);
			KdShaderManager::Instance().m_spriteShader.DrawTex(&m_tex, 0, 0, 32, 64, &rc);
		}
		else if (i % 1 == 0)
		{
			rc = { 32 * 5,0,32,64 };
			KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mat[i]);
			KdShaderManager::Instance().m_spriteShader.DrawTex(&m_tex, 0, 0, 32, 64, &rc);
		}
	}

	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_SlashMat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_SlashTex, 0, 0);
}

void Rank::Init()
{
	m_tex.Load("Asset/Textures/UI/Number.png");
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
		{
			m_pos[i] = { float(585 - (32 * i)),360 - 55,0 };
			m_mat[i] = Math::Matrix::Identity;
		}
		else
		{
			m_pos[i] = { float(545 - (32 * i)),360 - 55,0 };
			m_mat[i] = Math::Matrix::Identity;
		}
	}

	m_SlashTex.Load("Asset/Textures/UI/Slash.png");
	m_SlashPos = { float(585 - 65),360 - 55,0 };
	m_SlashMat = Math::Matrix::Identity;
}

void Rank::Release()
{
}
