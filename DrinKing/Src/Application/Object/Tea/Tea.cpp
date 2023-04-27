#include "Tea.h"
#include "Bullet/Tea_Bullet.h"

void Tea::Update()
{
	Pop();
	if (!m_flg)return;

	m_cooltime++;
	if (m_cooltime >= 30)
	{
		for (int i = 0; i < m_objList.size(); i++)
		{
			m_objList[i]->Shot(m_pos);
			m_cooltime = 0;
		}
	}

	//ˆÚ“®================================
	m_pos.x -= 1.5f;
	if (m_pos.x < -320 - 16)
	{
		m_flg = false;
	}

	for (int i = 0; i < m_objList.size(); i++)
	{
		m_objList[i]->Update();
	}


	//s—ñ
	Math::Matrix transMat;
	transMat = Math::Matrix::CreateTranslation(m_pos);
	m_mat = transMat;
}

void Tea::Draw()
{
	if (!m_flg)return;

	for (int i = 0; i < m_objList.size(); i++)
	{
		m_objList[i]->Draw();
	}

	//©‹@‚Ì•`‰æ
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_tex, m_pos.x, m_pos.y, &rc);
}

void Tea::Init()
{
	std::shared_ptr<Tea_Bullet>teabullet;
	teabullet = std::make_shared<Tea_Bullet>();
	teabullet->Init();

	//‰Šú‰»
	m_tex.Load("Asset/Textures/tea.png");
	m_pos = { 0, 0, 0};
	m_mat = Math::Matrix::Identity;
	m_flg = false;
	m_cooltime = 0;
	m_objList.push_back(teabullet);
}

void Tea::Release()
{

}

//oŒ»
void Tea::Pop()
{
	if (!m_flg)
	{
		if (rand() % 150 < 1)
		{
			m_flg = true;
			m_pos= { 320 + 16, (rand() % 250) - 150.0f};
		}
	}
}
