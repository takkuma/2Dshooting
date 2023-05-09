#include "Beer.h"
#include "Bullet/Beer_Bullet.h"
#include "../../Scene/GameScene/GameScene.h"

void Beer::Update()
{
	for (auto& obj : m_owner->GetObjectList())
	{
		if (obj->GetObjType() == ObjectType::Player)
		{
			if (obj->GetRank() < 2 || obj->GetRank() > 41)
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
		m_deg -= 3;
		if (m_deg < -360)
		{
			m_deg += 360;
		}
		m_pos.y += 3 * sin(DirectX::XMConvertToRadians(m_deg));
		m_pos.x -= 2;
		if (m_pos.x < -640 - 32)
		{
			m_flg = false;
		}

		m_cooltime++;

		if (m_cooltime > MaxCoolTime)
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

void Beer::Draw()
{
	for (auto& obj : m_owner->GetObjectList())
	{
		if (obj->GetObjType() == ObjectType::Player)
		{
			if (obj->GetRank() < 2 || obj->GetRank() > 41)
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

void Beer::Init()
{
	//’e‚Ì‰Šú‰»
	std::shared_ptr<Beer_Bullet>beerbullet;
	for (int i = 0; i < BulletNum; i++)
	{
		beerbullet = std::make_shared<Beer_Bullet>();
		beerbullet->Setgamescene(m_owner);
		beerbullet->Init();
		m_objList.push_back(beerbullet);
	}
	
	//‰Šú‰»
	m_tex.Load("Asset/Textures/Object/Beer.png");
	m_pos = { 640 + 32 , 0, 0 };
	m_mat = Math::Matrix::Identity;
	m_deg = 0;
	m_flg = false;
	m_cooltime = MaxCoolTime;
	m_objType = ObjectType::Enemy;
}

void Beer::Release()
{

}

//oŒ»
void Beer::Pop()
{
	if (!m_flg)
	{
		if (rand() % 150 < 1)
		{
			m_pos = { 640 + 32,(rand() % 360 - 64) - 200.0f };
			m_deg = rand() % 360;
			m_cooltime = MaxCoolTime;
			m_flg = true;
		}
	}
}

void Beer::OnHit()
{
	m_flg = false;
}

void Beer::OnHitBullet()
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
