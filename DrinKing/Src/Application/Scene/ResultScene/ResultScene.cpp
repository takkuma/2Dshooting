#include "ResultScene.h"
#include "../../Object/Player/Player.h"

void ResultScene::Update()
{
	for (int i = 0; i < m_objList.size(); i++)
	{
		m_objList[i]->Update();
	}

	std::shared_ptr<Player>player;
	player = std::make_shared<Player>();
	m_rank = player->GetRank();
	//10‚ÌŒ…
	m_tenRank = m_rank / 10;
	//1‚ÌŒ…
	m_oneRank = m_rank % 10;

	for (int i = 0; i < 2; i++)
	{
		Math::Matrix transMat;
		Math::Matrix scaleMat;
		scaleMat = Math::Matrix::CreateScale(2);
		transMat = Math::Matrix::CreateTranslation(m_pos[i]);
		m_mat[i] = scaleMat * transMat;
	}

	//ÅIƒ‰ƒ“ƒN‚Ì•\Ž¦
	if (m_rank >= 41)
	{
		m_score = 5;
	}
	else if(m_rank <= 40 && m_rank >=31)
	{
		m_score = 4;
	}
	else if (m_rank <= 30 && m_rank >= 21)
	{
		m_score = 3;
	}
	else if (m_rank <= 20 && m_rank >= 11)
	{
		m_score = 2;
	}
	else if (m_rank <= 10 && m_rank >= 2)
	{
		m_score = 1;
	}
	else
	{
		m_score = 0;
	}


	m_RankScaleMat = Math::Matrix::CreateScale(2);
	m_RankTransMat = Math::Matrix::CreateTranslation(m_RankPos);
	m_RankMat = m_RankScaleMat * m_RankTransMat;
}

void ResultScene::Draw()
{
	KdShaderManager::Instance().m_spriteShader.Begin();
	{
		for (int i = 0; i < m_objList.size(); i++)
		{
			m_objList[i]->Draw();
		}

		for (int i = 0; i < 2; i++)
		{
	
			if (i == 1)
			{
				if (m_tenRank == 0)continue;
				rc = { 32 * m_tenRank,0,32,64 };
				KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mat[i]);
				KdShaderManager::Instance().m_spriteShader.DrawTex(&m_tex, 0, 0, 32, 64, &rc);
			}
			else
			{
				rc = { 32 * m_oneRank,0,32,64 };
				KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mat[i]);
				KdShaderManager::Instance().m_spriteShader.DrawTex(&m_tex, 0, 0, 32, 64, &rc);
			}
		}

		rc = { 32 * m_score,0,32,64 };
		KdShaderManager::Instance().m_spriteShader.SetMatrix(m_RankMat);
		KdShaderManager::Instance().m_spriteShader.DrawTex(&m_RankTex, 0, 0, 32, 64, &rc);
	}
	KdShaderManager::Instance().m_spriteShader.End();
}

void ResultScene::Init()
{
	std::shared_ptr<BaseObject> title;
	title = std::make_shared<BaseObject>();
	title->Init();
	title->SetTexture("Asset/Textures/Result.png");
	m_objList.push_back(title);

	m_tex.Load("Asset/Textures/UI/Number.png");
	for (int i = 0; i < 2; i++)
	{
		m_pos[i] = { float(315 - (64 * i)),0 ,0 };
		m_mat[i] = Math::Matrix::Identity;
	}

	m_RankTex.Load("Asset/Textures/UI/Rank.png");
	m_RankPos = { 300, -165 ,0 };
	m_RankMat = Math::Matrix::Identity;
}

void ResultScene::Release()
{

}
