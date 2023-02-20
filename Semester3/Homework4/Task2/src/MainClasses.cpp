class IObject {
public:
    virtual void spawn() = 0;
    virtual void destroy() = 0;
    virtual ~IObject() = default;
};

class Object : public IObject {
public:
    void spawn() override {};
    void destroy() override{};
    ~Object() override {};
};
class Unit : public Object{
public:
    unsigned HP; //Healthpoints
    unsigned MP; //Manapoints
    unsigned DMG; //Damage
    unsigned AS; //Attack speed
    unsigned MS; //Move speed
    ~Unit() override {}
};