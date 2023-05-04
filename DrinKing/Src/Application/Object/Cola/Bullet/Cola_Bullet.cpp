#include "Cola_Bullet.h"
#include "../../../Scene/GameScene/GameScene.h"
#include "Src/Application/Object/BaseObject.h"

void Cola_Bullet::Update()
{
	if (!m_flg)return;
	m_pos.x += 5;
	m_scale += 0.02f;
	if (m_pos.x > 640 + 16 * m_scale)
	{
		m_flg = false;
	}

	Math::Matrix transMat;
	Math::Matrix scaleMat;
	transMat = Math::Matrix::CreateTranslation(m_pos);
	scaleMat = Math::Matrix::CreateScale(m_scale);
	m_mat = scaleMat * transMat;

	//“–‚½‚è”»’è
	for (auto& obj : m_gamescene->GetObjectList())
	{
		if (obj->GetObjType() == BaseObject::ObjectType::Enemy)
		{
			if (obj->GetFlg())
			{
				//player‚Æenemy
				Math::Vector3 v = obj->GetPos() - m_pos;
				if (v.Length() < 32 + 8 * m_scale)
				{
					obj->OnHitBullet();
				}
			}
		}
	}
}

void Cola_Bullet::Init()
{
	m_pos = {};
	m_flg = false;
	m_tex.Load("Asset/Textures/Bullet/bullet_cola.png");
	m_mat = Math::Matrix::Identity;
	BaseObject::ObjectType::P_Bullet;
}

void Cola_Bullet::Release()
{
	
}
