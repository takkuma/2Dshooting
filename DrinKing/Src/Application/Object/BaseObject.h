#pragma once
//親クラス(基底クラス)

class GameScene;
class Player;

class BaseObject
{
public:
	BaseObject(){};
	~BaseObject() { Release(); };

	enum class ObjectType
	{
		Player,
		Enemy,
		P_Bullet,
		E_Bullet,
		UI,
		Back,
		None,
	};

	//仮想関数
	virtual void Update();
	virtual void Draw();
	virtual void Init();
	virtual void Release();
	//出現
	virtual void Pop();

	void SetTexture(std::string _fileName) {m_tex.Load(_fileName);}

	ObjectType GetObjType() { return m_objType; }
	Math::Vector3 GetPos() { return m_pos; }
	bool GetFlg() { return m_flg; }

	virtual void SetPos(Math::Vector3 a_pos) { m_pos = a_pos; }

	virtual void SetType(ObjectType a_objType) { m_objType = a_objType; }

	virtual void OnHit();
	virtual void OnHitBullet();
	void SetOwner(GameScene* a_owner) { m_owner = a_owner; }

	//ランク制度
	virtual void RankUp();
	virtual int GetRank() { return m_rank; }

	virtual int GetLife() { return m_life; }

protected:
	GameScene* m_owner;
	//プレイヤー関係========================
	//命名規則にキャメル型を採用
	KdTexture m_tex;
	Math::Vector3 m_pos;
	Math::Matrix m_mat;
	int m_cooltime;
	bool m_flg;
	float m_ang;
	float m_rad;
	float m_deg;
	float m_scale = 1;

	int m_rank = 1;
	int m_life = 3;

	Math::Rectangle rc = { 0,0,64,64 };
	ObjectType m_objType = ObjectType::None;
};