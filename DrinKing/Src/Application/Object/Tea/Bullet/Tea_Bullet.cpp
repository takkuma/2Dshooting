#include "Tea_Bullet.h"
#include "../../../Scene/GameScene/GameScene.h"
#include "Src/Application/Object/BaseObject.h"

void Tea_Bullet::Update()
{
	if (!m_flg)return;
	m_pos.x -= 7;

	if (m_pos.x < -640 - 8)
	{
		m_flg = false;
	}

	Math::Matrix transMat;
	transMat = Math::Matrix::CreateTranslation(m_pos);
	m_mat = transMat;

	//当たり判定
	for (auto& obj : m_gamescene->GetObjectList())
	{
		if (obj->GetObjType() == BaseObject::ObjectType::Player)
		{
			if (obj->GetFlg())
			{
				//playerとenemy
				Math::Vector3 v = obj->GetPos() - m_pos;
				if (v.Length() < 40)
				{
					obj->OnHit();
					m_flg = false;
				}
			}
		}
	}
}

void Tea_Bullet::Init()
{
	m_pos = { 640 + 32 , 0, 0 };
	m_flg = false;
	m_tex.Load("Asset/Textures/Bullet/bullet_tea.png");
	m_mat = Math::Matrix::Identity;
	BaseObject::ObjectType::E_Bullet;
}

void Tea_Bullet::Release()
{
}
