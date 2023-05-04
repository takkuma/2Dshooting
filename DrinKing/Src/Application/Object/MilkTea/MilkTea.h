#pragma once
#include"../BaseObject.h"

class Milk_Bullet;

class Milk :public BaseObject
{
public:
	//�R���X�g���N�^�c�C���X�^���X�������Ƃ��ɍŏ��ɂP�x�������s�����֐�
	Milk() {};
	//�f�X�g���N�^�c
	~Milk() { Release(); };
	//���W���[�֐�
	//�I�[�o�[���C�h�c�e�N���X�̊֐����㏑��
	void Update()override;
	void Draw()override;
	void Init()override;
	void Release()override;
	void Pop()override;
	void OnHit()override;
	void OnHitBullet()override;
private:
	//�ێ琫�E�ǐ��E�ėp��
	std::vector<std::shared_ptr<Milk_Bullet>>m_objList;

	static const int BulletNum = 5;

	static const int MaxCoolTime = 120;
};