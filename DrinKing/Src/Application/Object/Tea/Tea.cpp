#include "Tea.h"
#include "Bullet/Tea_Bullet.h"

void Tea::Update()
{
	Pop();
	if (!m_flg)return;

	m_cooltime++;
	if (m_cooltime >= 90)
	{
		for (int i = 0; i < m_objList.size(); i++)
		{
			if (m_objList[i]->GetFlg())continue;
			m_objList[i]->Shot(m_pos);
			m_cooltime = 0;
			break;
		}
	}

	//移動================================
	m_pos.x -= 3.0f;
	if (m_pos.x < -640 - 32)
	{
		m_flg = false;
	}

	for (int i = 0; i < m_objList.size(); i++)
	{
		m_objList[i]->Update();
	}


	//行列
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

	//自機の描画
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_tex, 0,0, &rc);
}

void Tea::Init()
{
	std::shared_ptr<Tea_Bullet>teabullet;
	for (int i = 0; i < BulletNum; i++)
	{
		teabullet = std::make_shared<Tea_Bullet>();
		teabullet->Init();
		m_objList.push_back(teabullet);
	}
	

	//初期化
	m_tex.Load("Asset/Textures/tea.png");
	m_pos = { 0, 0, 0};
	m_mat = Math::Matrix::Identity;
	m_flg = false;
	m_cooltime = 0;

	
}

void Tea::Release()
{

}

//出現
void Tea::Pop()
{
	if (!m_flg)
	{
		if (rand() % 150 < 1)
		{
			m_flg = true;
			m_pos= { 640 + 16, (rand() % 500) - 300.0f};
		}
	}
}
