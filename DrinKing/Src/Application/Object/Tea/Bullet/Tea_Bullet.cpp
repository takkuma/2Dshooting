#include "Tea_Bullet.h"

void Tea_Bullet::Update()
{
	if (!m_flg)return;
	m_pos.x -= 5;

	if (m_pos.x < -320 - 8)
	{
		m_flg = false;
	}

	Math::Matrix transMat;
	transMat = Math::Matrix::CreateTranslation(m_pos);
	m_mat = transMat;
}

void Tea_Bullet::Init()
{
	m_pos = {};
	m_flg = false;
	m_tex.Load("Asset/Textures/bullet_tea.png");
	m_mat = Math::Matrix::Identity;
}

void Tea_Bullet::Release()
{
}
