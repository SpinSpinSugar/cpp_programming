#include "MainClasses.cpp"

class Hero : public Unit {
public:
    ~Hero() override {};
};

class Undead : public Hero {
public:
    ~Undead() override {}
};

class Human : public Hero {
public:
    ~Human() override {};
};

class Horde : public Hero {
public:
    ~Horde() override {};
};

class Elf : public Hero {
public:
    ~Elf() override {};
};

class TavernHero : public Hero {
public:
    ~TavernHero() override {};
};

//Elf heroes
class DemonHunter final : public Elf {
public:
    ~DemonHunter() override {};
};

class KeeperOfTheGrove final : public Elf {
public:
    ~KeeperOfTheGrove() override {};
};

class PrincessOfTheMoon final : public Elf {
public:
    ~PrincessOfTheMoon() override {};
};

class Warden final : public Elf {
public:
    ~Warden() override {};
};

//Human heroes
class Paladin final : public Human {
public:
    ~Paladin() override {};
};

class Archmage final : public Human {
public:
    ~Archmage() override {};
};

class BloodMage final : public Human {
public:
    ~BloodMage() override {};
};

class MountainKing final : public Human {
    ~MountainKing() override {};
};

//Undead heroes
class DeathKnight final : public Undead {
public:
    ~DeathKnight() override {};
};

class Lich final : public Undead {
public:
    ~Lich() override {};
};

class DreadLord final : public Undead {
public:
    ~DreadLord() override {};
};

class CryptLord final : public Undead {
public:
    ~CryptLord() override {};
};

//Horde heroes
class Blademaster final : public Horde {
public:
    ~Blademaster() override {};
};

class ShadowHunter final : public Horde {
public:
    ~ShadowHunter() override {};
};

class FarSeer final : public Horde {
public:
    ~FarSeer() override {};
};

class TaurenChieftain final : public Horde {
public:
    ~TaurenChieftain() override {};
};

//Tavern heroes
class Naga final : public TavernHero {
public:
    ~Naga() override {};
};

class DarkRanger final : public TavernHero {
public:
    ~DarkRanger() override {};
};

class Brewmaster final : public TavernHero {
public:
    ~Brewmaster() override {};
};

class Beastmaster final : public TavernHero {
public:
    ~Beastmaster() override {};
};

class PitLord final : public TavernHero {
public:
    ~PitLord() override {};
};

class Tinker final : public TavernHero {
public:
    ~Tinker() override {};
};

class Firelord final : public TavernHero {
public:
    ~Firelord() override {};
};

class Alchemist final : public TavernHero {
public:
    ~Alchemist() override {};
};