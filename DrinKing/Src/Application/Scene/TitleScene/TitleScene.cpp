#include "TitleScene.h"
#include "../../Object/BaseObject.h"

void TitleScene::Update()
{
	for (int i = 0; i < m_objList.size(); i++)
	{
		m_objList[i]->Update();
	}

	Math::Matrix scaleMat;
	Math::Matrix transMat;

	m_scale += 0.01f;
	if (m_scale >= 1)
	{
		m_scale = 1.0f;
	}


	transMat = Math::Matrix::CreateTranslation(m_NamePos);
	scaleMat = Math::Matrix::CreateScale(m_scale);
	m_NameMat = scaleMat * transMat;

	m_PushMat = Math::Matrix::CreateTranslation(m_PushPos);
}

void TitleScene::Draw()
{
	KdShaderManager::Instance().m_spriteShader.Begin();
	{
		for (int i = 0; i < m_objList.size(); i++)
		{
			m_objList[i]->Draw();
		}

		KdShaderManager::Instance().m_spriteShader.SetMatrix(m_NameMat);
		KdShaderManager::Instance().m_spriteShader.DrawTex(&m_NameTex, 0, 0);

		KdShaderManager::Instance().m_spriteShader.SetMatrix(m_PushMat);
		KdShaderManager::Instance().m_spriteShader.DrawTex(&m_PushTex, 0, 0);
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

	m_NameTex.Load("Asset/Textures/GameName.png");
	m_NamePos = {-320,0,0};
	m_NameMat = Math::Matrix::Identity;
	m_scale = 0;

	m_PushTex.Load("Asset/Textures/UI/Push.png");
	m_PushPos = { -350,-100,0 };
	m_PushMat = Math::Matrix::Identity;

}

void TitleScene::Release()
{
}
