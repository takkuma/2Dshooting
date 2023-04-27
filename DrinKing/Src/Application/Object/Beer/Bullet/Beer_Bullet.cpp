#include "Beer_Bullet.h"

void Beer_Bullet::Update()
{
	if (!m_flg)return;
	m_pos.x -= 5;

	if (m_pos.x < -640 - 8)
	{
		m_flg = false;
	}

	Math::Matrix transMat;
	transMat = Math::Matrix::CreateTranslation(m_pos);
	m_mat = transMat;
}

void Beer_Bullet::Init()
{
	m_pos = {};
	m_flg = false;
	m_tex.Load("Asset/Textures/bullet_beer.png");
	m_mat = Math::Matrix::Identity;
}

void Beer_Bullet::Release()
{

}
