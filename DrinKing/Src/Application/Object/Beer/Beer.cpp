#include "Beer.h"
#include "Bullet/Beer_Bullet.h"

void Beer::Update()
{
	Pop();
	
	if (!m_flg)return;
	//ˆÚ“®================================
	m_deg -= 3;
	if (m_deg < -360)
	{
		m_deg = 0;
	}
	m_pos.y += 2 * sin(DirectX::XMConvertToRadians(m_deg));
	m_pos.x -= 2;
	if (m_pos.x < -640 - 32)
	{
		m_flg = false;
	}

	m_cooltime++;

	if (m_cooltime > 90)
	{
		for (int i = 0; i < m_objList.size(); i++)
		{
			if (m_objList[i]->GetFlg())continue;
			m_objList[i]->Shot(m_pos);
			m_cooltime = 0;
			break;
		}
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

void Beer::Draw()
{
	if (!m_flg)return;

	for (int i = 0; i < m_objList.size(); i++)
	{
		m_objList[i]->Draw();
	}
	

	//©‹@‚Ì•`‰æ
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_tex, 0, 0, &rc);
}

void Beer::Init()
{
	//’e‚Ì‰Šú‰»
	std::shared_ptr<Beer_Bullet>beerbullet;
	for (int i = 0; i < BulletNum; i++)
	{
		beerbullet = std::make_shared<Beer_Bullet>();
		beerbullet->Init();
		m_objList.push_back(beerbullet);
	}
	
	//‰Šú‰»
	m_tex.Load("Asset/Textures/Beer.png");
	m_pos = {};
	m_mat = Math::Matrix::Identity;
	m_deg = 0;
	m_flg = false;
	m_cooltime = 0;

	
}

void Beer::Release()
{

}

//oŒ»
void Beer::Pop()
{
	if (!m_flg)
	{
		if (rand() % 150 < 1)
		{
			m_pos = { 640 + 32,(rand() % 400) - 200.0f };
			m_ang = rand() % 360;
			m_flg = true;
		}
	}
}
