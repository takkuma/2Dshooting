#pragma once
#include"../../Object/BaseObject.h"

class Life :public BaseObject
{
public:
	Life() {};
	~Life() { Release(); };
	//ƒƒWƒƒ[ŠÖ”
	void Update()override;
	void Draw()override;
	void Init();
	void Release()override;
	void SetOwner(GameScene* a_owner) { m_owner = a_owner; }
private:
	Math::Vector3 m_pos[3];
	Math::Matrix m_mat[3];
};
