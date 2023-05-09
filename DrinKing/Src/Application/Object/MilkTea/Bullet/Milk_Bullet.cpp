#include "Milk_Bullet.h"
#include "../../../Scene/GameScene/GameScene.h"
#include "Src/Application/Object/BaseObject.h"

void Milk_Bullet::Update()
{
	if (!m_flg)return;

	m_pos.x -= 7;
	m_pos.y -= sin(DirectX::XMConvertToRadians(m_deg)) * 2;

	if (m_pos.x < -640 - 8)
	{
		m_flg = false;
	}

	Math::Matrix transMat;
	transMat = Math::Matrix::CreateTranslation(m_pos);
	m_mat = transMat;

	//“–‚½‚è”»’è
	for (auto& obj : m_gamescene->GetObjectList())
	{
		if (obj->GetObjType() == BaseObject::ObjectType::Player)
		{
			if (obj->GetFlg())
			{
				//player‚Æenemy
				Math::Vector3 v = obj->GetPos() - m_pos;
				if (v.Length() < 48)
				{
					obj->OnHit();
					m_flg = false;
				}
			}
		}
	}
}

void Milk_Bullet::Init()
{
	m_pos = { 640 + 32 , 0, 0 };
	m_flg = false;
	m_tex.Load("Asset/Textures/Bullet/bullet_milktea.png");
	m_mat = Math::Matrix::Identity;
	BaseObject::ObjectType::E_Bullet;
}

void Milk_Bullet::Release()
{
}

void Milk_Bullet::Shot(Math::Vector3 a_pos)
{
	if (!m_flg)
	{
		m_pos.x = a_pos.x;
		m_pos.y = a_pos.y;
		for (auto& obj : m_gamescene->GetObjectList())
		{
			if (obj->GetObjType() == BaseObject::ObjectType::Player)
			{
				m_deg = GetAngleDeg(a_pos, obj->GetPos());
			}
		}
		m_scale = 1;
		m_flg = true;
	}
}

float Milk_Bullet::GetAngleDeg(Math::Vector3 a_pos, Math::Vector3 a_Ppos)
{
	for (auto& obj : m_gamescene->GetObjectList())
	{
		if (obj->GetObjType() == BaseObject::ObjectType::Player)
		{
			float a = a_pos.x - a_Ppos.x;
			float b = a_pos.y - a_Ppos.y;
			float rad = atan2(b, a);
			float deg = DirectX::XMConvertToDegrees(rad);
			if (deg < 0)
			{
				deg += 360;
			}

			return deg;
		}
	}
}
