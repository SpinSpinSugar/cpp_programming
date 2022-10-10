class IObject {
public:
    void spawn() {};
    void destroy() {};
};

class Object : public IObject {
public:
    ~Object() {};
};
class Unit : public Object{
public:
    unsigned HP; //Healthpoints
    unsigned MP; //Manapoints
    unsigned DMG; //Damage
    unsigned AS; //Attack speed
    unsigned MS; //Move speed
    ~Unit() {}
};