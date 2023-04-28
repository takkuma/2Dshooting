#pragma once
//�e�N���X(���N���X)

class BaseObject
{
public:
	BaseObject(){};
	~BaseObject() { Release(); };

	enum class ObjectType
	{
		Player,
		Enemy,
		Bullet,
		Item,
		Back,
		None,
	};

	//���z�֐�
	virtual void Update() = 0;
	virtual void Draw();
	virtual void Init() = 0;
	virtual void Release();
	//�o��
	virtual void Pop();

	void SetTexture(std::string _fileName) {
		m_tex.Load(_fileName);
	}

	ObjectType GetObjType() { return m_objType; }
	Math::Vector3 GetPos() { return m_pos; }
	bool GetFlg() { return m_flg; }

	virtual void OnHit();
protected:
	//�v���C���[�֌W========================
	//�����K���ɃL�������^���̗p
	KdTexture m_tex;
	Math::Vector3 m_pos;
	Math::Matrix m_mat;
	float m_cooltime;
	bool m_flg;
	float m_ang;
	float m_rad;

	Math::Rectangle rc = { 0,0,64,64 };
	ObjectType m_objType = ObjectType::None;
};