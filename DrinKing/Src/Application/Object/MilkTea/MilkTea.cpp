#include "MilkTea.h"
#include "Bullet/Milk_Bullet.h"
#include "../../Scene/GameScene/GameScene.h"

void Milk::Update()
{
	for (auto& obj : m_owner->GetObjectList())
	{
		if (obj->GetObjType() == ObjectType::Player)
		{
			if (obj->GetRank() < 2 || obj->GetRank() > 26)
			{
				m_flg = false;
				return;
			}
		}
	}

	Pop();

	if (m_flg)
	{
		//ˆÚ“®================================
		m_pos.x -= 1.0f;
		if (m_pos.x < -640 - 32)
		{
			m_flg = false;
		}

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

void Milk::Draw()
{
	for (auto& obj : m_owner->GetObjectList())
	{
		if (obj->GetObjType() == ObjectType::Player)
		{
			if (obj->GetRank() < 2 || obj->GetRank() > 26)
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

void Milk::Init()
{
	std::shared_ptr<Milk_Bullet>milkbullet;
	for (int i = 0; i < BulletNum; i++)
	{
		milkbullet = std::make_shared<Milk_Bullet>();
		milkbullet->Setgamescene(m_owner);
		milkbullet->Init();
		m_objList.push_back(milkbullet);
	}

	//‰Šú‰»
	m_tex.Load("Asset/Textures/Object/milktea.png");
	m_pos = { 640 + 32 , 0, 0 };
	m_mat = Math::Matrix::Identity;
	m_flg = false;
	m_objType = ObjectType::Enemy;
}

void Milk::Release()
{

}

void Milk::Pop()
{
	if (!m_flg)
	{
		if (rand() % 150 < 1)
		{
			m_flg = true;
			m_pos = { 640 + 32, (rand() % 500) - 300.0f };
			m_cooltime = MaxCoolTime;
		}
	}
}

void Milk::OnHit()
{
	m_flg = false;
}

void Milk::OnHitBullet()
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
