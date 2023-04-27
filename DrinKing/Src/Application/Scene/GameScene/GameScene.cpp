#include "GameScene.h"
#include "../../Object/Player/Player.h"
#include "../../Object/Tea/Tea.h"
#include "../../Object/Beer/Beer.h"
#include "../../Object/MilkTea/MilkTea.h"

void GameScene::Update()
{
	//�|�����[�t�B�Y��
	for (int i = 0; i < m_objList.size(); i++)
	{
		m_objList[i]->Update();
	}
}

void GameScene::Draw()
{
	// ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
	// 2D�̕`��͂��̊Ԃōs��
	KdShaderManager::Instance().m_spriteShader.Begin();
	{
		for (int i = 0; i < m_objList.size(); i++)
		{
			m_objList[i]->Draw();
		}
	}
	KdShaderManager::Instance().m_spriteShader.End();
}

void GameScene::Init()
{
	//���@�̏�����
	std::shared_ptr<Player>player;
	player = std::make_shared<Player>();
	player->Init();

	//�����G�̏�����
	std::shared_ptr<Tea>tea[Tea_Num];
	for (int i = 0; i < Tea_Num; i++)
	{
		tea[i] = std::make_shared<Tea>();
		tea[i]->Init();
		m_objList.push_back(tea[i]);
	}
	

	//�r�[���̏�����
	std::shared_ptr<Beer>beer[Beer_Num];
	for (int i = 0; i < Beer_Num; i++)
	{
		beer[i] = std::make_shared<Beer>();
		beer[i]->Init();
		m_objList.push_back(beer[i]);
	}

	std::shared_ptr<Milk>milk;
	
	milk = std::make_shared<Milk>();
	milk->Init();
	m_objList.push_back(milk);
	

	//�`�����ɂ�����̂����ɂ���
	m_objList.push_back(player);
}

void GameScene::Release()
{
}
