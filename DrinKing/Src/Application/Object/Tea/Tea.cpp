#include "Tea.h"
#include "Bullet/Tea_Bullet.h"
#include "../../Scene/GameScene/GameScene.h"
#include "../BaseObject.h"

void Tea::Update()
{
	for (auto& obj : m_owner->GetObjectList())
	{
		if (obj->GetObjType() == ObjectType::Player)
		{
			if (obj->GetRank() < 2)
			{
				m_flg = false;
				return;
			}
		}
	}


	Pop();
	if (m_flg)
	{
		m_cooltime++;
		if (m_cooltime >= MaxCoolTime)
		{
			for (int i = 0; i < m_objList.size(); i++)
			{
				if (m_objList[i]->GetFlg())continue;
				m_objList[i]->Shot(m_pos);
				m_cooltime = 0;
				break;
			}
		}

		//ˆÚ“®================================
		m_pos.x -= 3.0f;
		if (m_pos.x < -640 - 32)
		{
			m_flg = false;
		}

		//s—ñ
		Math::Matrix transMat;
		transMat = Math::Matrix::CreateTranslation(m_pos);
		m_mat = transMat;
	}

	for (int i = 0; i < m_objList.size(); i++)
	{
		m_objList[i]->Update();
	}
}

void Tea::Draw()
{
	for (auto& obj : m_owner->GetObjectList())
	{
		if (obj->GetObjType() == ObjectType::Player)
		{
			if (obj->GetRank() < 2)
			{
				return;
			}
		}
	}
	//’e‚Ì•`‰æ
	for (int i = 0; i < m_objList.size(); i++)
	{
		m_objList[i]->Draw();
	}
	if (!m_flg)return;
	//©‹@‚Ì•`‰æ
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_tex, 0, 0, &rc);
}

void Tea::Init()
{
	std::shared_ptr<Tea_Bullet>teabullet;
	for (int i = 0; i < BulletNum; i++)
	{
		teabullet = std::make_shared<Tea_Bullet>();
		teabullet->Setgamescene(m_owner);
		teabullet->Init();
		m_objList.push_back(teabullet);
	}
	

	//‰Šú‰»
	m_tex.Load("Asset/Textures/Object/tea.png");
	m_pos = { 640+32 , 0, 0 };
	m_mat = Math::Matrix::Identity;
	m_flg = false;
	m_cooltime = MaxCoolTime;
	m_objType = ObjectType::Enemy;
}

void Tea::Release()
{

}

//oŒ»
void Tea::Pop()
{
	if (!m_flg)
	{
		if (rand() % 150 < 1)
		{
			m_flg = true;
			m_pos= { 640 + 16, (rand() % 500) - 300.0f};
			m_cooltime = MaxCoolTime;
		}
	}
}

void Tea::OnHit()
{
	m_flg = false;
}

void Tea::OnHitBullet()
{
	for (auto& obj : m_owner->GetObjectList())
	{
		if (obj->GetObjType() == ObjectType::Player)
		{
			obj->RankUp();
			break;
		}
	}

	m_flg = false;
}
