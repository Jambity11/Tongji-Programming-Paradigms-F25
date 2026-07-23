const int TYPE_RUNNER = 0; // 边缘行者
const int TYPE_PSYCHO = 1; // 赛博精神病

class CyberEntity {
protected:
	double hp = 100.0;
	double baseDamage;
	double defense;
public:
	CyberEntity() {}
	CyberEntity(double hp, double baseDamage, double defense) : 
		hp(hp), baseDamage(baseDamage), defense(defense) { }
	double getHp() const { return hp; }
	double getBaseDamage() const { return baseDamage; }
	double getDefense() const { return defense; }
	virtual bool attack(CyberEntity& target) = 0;
	void takeDamage(double damage) {
		double actual_damage = damage * (1.0 - defense);
		if (hp <= actual_damage) hp = 0;
		else hp -= actual_damage;
	}
	virtual int getType() const = 0;
};

class Edgerunner : public CyberEntity{
public:
	Edgerunner() : CyberEntity() {}
	Edgerunner(double hp, double baseDamage, double defense, int s) : 
		CyberEntity(hp, baseDamage, defense), sanity(s) { }
	int sanity;
	bool attack(CyberEntity& target) override {
		target.takeDamage(getBaseDamage());
		if (target.getHp() < 1e-8) return 1;
		else return 0;
	}
	int getType() const override { return TYPE_RUNNER; }
	virtual void useInhibitor() {
		if (0.0 < hp && hp < 100.0 && sanity > 0) {
			sanity--;
			hp++;
		}
	}
};

class David : public Edgerunner {
public:
	David() : Edgerunner(100.0, 20.0, 0.1, 3) {}
	void useInhibitor() override {
		if (0.0 < hp && hp < 100.0 && sanity > 0) {
			sanity--;
			hp += 20.0;
			if (hp > 100.0) hp = 100.0;
		}
	}
};

class CyberPsycho : public CyberEntity {
public:
	CyberPsycho(){}
	CyberPsycho(double hp, double baseDamage, double defense) : 
		CyberEntity(hp, baseDamage, defense) { }
	bool attack(CyberEntity& target) override {
		if (target.getType() == TYPE_PSYCHO) return 0;
		else if (target.getType() == TYPE_RUNNER) {
			target.takeDamage(getBaseDamage());
			if (target.getHp() < 1e-8) return 1;
			else return 0;
		}
	}
	int getType() const { return TYPE_PSYCHO; }
};

class Smasher : public CyberPsycho {
public:
	Smasher() :
		CyberPsycho(100.0, 25.0, 0.2) { }
	~Smasher() {}
};
