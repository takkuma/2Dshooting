#include "BaseBullet.h"

void BaseBullet::Draw()
{
	if (!m_flg)return;
	//Ž©‹@‚Ì•`‰æ
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_tex, m_pos.x, m_pos.y);
}

void BaseBullet::Release()
{

}

void BaseBullet::Shot(Math::Vector3 a_pos)
{
	if (!m_flg)
	{
		m_flg = true;
		m_pos.x = a_pos.x;
		m_pos.y = a_pos.y - 7;
	}
}
