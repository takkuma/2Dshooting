#include "BaseBullet.h"

void BaseBullet::Draw()
{
	if (!m_flg)return;
	//Ž©‹@‚Ì•`‰æ
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_tex, 0, 0);
}

void BaseBullet::Release()
{

}

void BaseBullet::Shot(Math::Vector3 a_pos)
{
	if (!m_flg)
	{
		m_pos.x = a_pos.x;
		m_pos.y = a_pos.y - 7;
		m_scale = 1;
		m_flg = true;
	}
}
