#include "Water_Bullet.h"
#include "../../../Scene/GameScene/GameScene.h"
#include "Src/Application/Object/BaseObject.h"
#include "../../Player/Player.h"

void Water_Bullet::Update()
{
	if (!m_flg)return;
	m_pos.x += 5;
	if (m_pos.x > 640 + 8)
	{
		m_flg = false;
	}

	Math::Matrix transMat;
	transMat = Math::Matrix::CreateTranslation(m_pos);
	m_mat = transMat;

	//“–‚½‚è”»’è
	for (auto& obj : m_gamescene->GetObjectList())
	{
		if (obj->GetObjType() == BaseObject::ObjectType::Enemy)
		{
			if (obj->GetFlg())
			{
				//player‚Æenemy
				Math::Vector3 v = obj->GetPos() - m_pos;
				if (v.Length() < 40)
				{
					obj->OnHitBullet();
					m_flg = false;
				}

			}
		}
	}
}

void Water_Bullet::Init()
{
	m_pos = {};
	m_flg = false;
	m_tex.Load("Asset/Textures/Bullet/bullet_water.png");
	m_mat = Math::Matrix::Identity;
	BaseObject::ObjectType::P_Bullet;
}

void Water_Bullet::Release()
{

}
