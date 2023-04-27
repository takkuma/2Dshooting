#include "MilkTea.h"
#include "Bullet/Milk_Bullet.h"

void Milk::Update()
{
	Pop();

	if (!m_flg)return;

	m_cooltime++;
	if (m_cooltime >= 60)
	{
		for (int i = 0; i < m_objList.size(); i++)
		{
			m_objList[i]->Shot(m_pos);
			m_cooltime = 0;	
			break;
		}
	}

	//ˆÚ“®================================
	m_pos.x -= 0.5f;
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

void Milk::Draw()
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

void Milk::Init()
{
	std::shared_ptr<Milk_Bullet>milkbullet;
	milkbullet = std::make_shared<Milk_Bullet>();
	milkbullet->Init();

	//‰Šú‰»
	m_tex.Load("Asset/Textures/milktea.png");
	m_pos = { 0, 0, 0 };
	m_mat = Math::Matrix::Identity;
	m_flg = false;
	m_cooltime = 0;
	m_objList.push_back(milkbullet);
}

void Milk::Release()
{

}

void Milk::Pop()
{
	if (!m_flg)
	{
		if (rand() % 150 < 1)
		{
			m_flg = true;
			m_pos = { 320 + 16, (rand() % 250) - 150.0f };
		}
	}
}
