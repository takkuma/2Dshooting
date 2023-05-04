#include "TitleScene.h"
#include "../../Object/BaseObject.h"

void TitleScene::Update()
{
	for (int i = 0; i < m_objList.size(); i++)
	{
		m_objList[i]->Update();
	}
}

void TitleScene::Draw()
{
	KdShaderManager::Instance().m_spriteShader.Begin();
	{
		for (int i = 0; i < m_objList.size(); i++)
		{
			m_objList[i]->Draw();
		}
	}
	KdShaderManager::Instance().m_spriteShader.End();
}

void TitleScene::Init()
{
	std::shared_ptr<BaseObject> title;
	title = std::make_shared<BaseObject>();
	title->Init();
	title->SetTexture("Asset/Textures/Title.png");
	m_objList.push_back(title);
}

void TitleScene::Release()
{
}
