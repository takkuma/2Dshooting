#pragma once
//��΂ɏ���
//���d�ǂݍ��ݗ}���R�}���h
#include"../BaseObject.h"

class Tea_Bullet;

class Tea:public BaseObject
{
public:
	//�R���X�g���N�^�c�C���X�^���X�������Ƃ��ɍŏ��ɂP�x�������s�����֐�
	Tea(){};
	//�f�X�g���N�^�c
	~Tea() { Release(); };
	//���W���[�֐�
	//�I�[�o�[���C�h�c�e�N���X�̊֐����㏑��
	void Update()override;
	void Draw()override;
	void Init()override;
	void Release()override;
	void Pop()override;

private:
	//�ێ琫�E�ǐ��E�ėp��
	std::vector<std::shared_ptr<Tea_Bullet>>m_objList;
};