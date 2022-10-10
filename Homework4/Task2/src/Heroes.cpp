#include "MainClasses.cpp"

class Hero : public Unit {

};

class Undead : public Hero {
    //~Undead() override {}
};

class Human : public Hero {
};

class Horde : public Hero {
};

class Elf : public Hero {
};

class TavernHero : public Hero {

};

//Elf heroes
class DemonHunter : public Elf {

};

class KeeperOfTheGrove : public Elf {

};

class PrincessOfTheMoon : public Elf {

};

class Warden : public Elf {

};

//Human heroes
class Paladin : public Human {

};

class Archmage : public Human {

};

class BloodMage : public Human {

};

class MountainKing : public Human {

};

//Undead heroes
class DeathKnight : public Undead {

};

class Lich : public Undead {

};

class DreadLord : public Undead {

};

class CryptLord : public Undead {

};

//Horde heroes
class Blademaster : public Horde {

};

class ShadowHunter : public Horde {

};

class FarSeer : public Horde {

};

class TaurenChieftain : public Horde {

};

//Tavern heroes
class Naga : public TavernHero {

};

class DarkRanger : public TavernHero {

};

class Brewmaster : public TavernHero {

};

class Beastmaster : public TavernHero {

};

class PitLord : public TavernHero {

};

class Tinker : public TavernHero {

};

class Firelord : public TavernHero {

};

class Alchemist : public TavernHero {

};