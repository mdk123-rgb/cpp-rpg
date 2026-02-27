#include <iostream>
#include <string>
#include <random>
#include <ctime>


// klasa abstrakcyjna to klasa która nic w sobie nie ma ale jest wymagana w każdej innej sub-klasie
// np klasa zwierze ma abstrakcyjną funkjce dzwiek ktora jest pusta ale sub klasa kot/pies musi jej uzyc

using namespace std;

class Character {
public:
    Character(string name, int lvl) : Name(name), Level(lvl) {}
    string Name;
    virtual void setStats(int strength, int dexterity, int constitution, int intelligence, int max_hp, int armor_class) = 0;
    virtual void attack(Character* target) = 0;
    virtual void heal(Character* target) = 0;
    void setHP(int hp) { Current_HP = hp; }
    int getArmor() { return Armor_class; }
    int getCurrentHP() { return Current_HP; }
    int getMaxHP() {return Max_HP;}
protected:
    int Level = 1;
    int Max_HP = 0;
    int Current_HP = 0;
    int Strength = 0;
    int Dexterity = 0;
    int Constitution = 0;
    int Intelligence = 0;
    int Armor_class = 0;
};

class Warrior : public Character {
public:
    Warrior(string name, int lvl) : Character(name, lvl) {}
    void setStats(int strength, int dexterity, int constitution, int intelligence, int max_hp, int armor_class) override {
        if (strength < 1 || strength > 20) Strength = 1;
        else Strength = strength;
        if (dexterity < 1 || dexterity > 20) Dexterity = 1;
        else Dexterity = dexterity;
        if (constitution < 1 || constitution > 20) Constitution = 1;
        else Constitution = constitution;
        if (intelligence < 1 || intelligence > 20) Intelligence = 1;
        else Intelligence = intelligence;
        if (max_hp < 1) Max_HP = 1;
        else Max_HP = max_hp + (Constitution / 3) + Level;
        Armor_class = armor_class + (Strength / 3);
    }
    void attack(Character* target) override {
        int hitChance = rand() % 20 + 1;
        int a = rand() % 10 + 1;
        int damage = a + (Strength / 5);
        if (hitChance == 20) damage *= 1.5;
        if (hitChance > target->getArmor()){
            cout << "======" << endl;
            if(hitChance == 20) cout << "KRYTYCZNE TRAFIENIE!" << endl;
            cout << Name << " atakuje " << target-> Name << " mieczem, zadając: " << damage << endl;
            target->setHP(target->getCurrentHP() - damage);
            cout << target-> Name << " ma teraz: " << target->getCurrentHP() << " hp" << endl;
            cout << "======" << endl;
        }
        else{
            cout << "======" << endl;
            cout << "Nie trafiony" << endl;
            cout << "======" << endl;
        }
    }   

    void heal(Character* target) override {
        int roll = rand() % 6 + 1;
        int healAmount = roll + (Intelligence /5) + (Level * 1);
        int afterHeal = target->getCurrentHP() + healAmount;
        if (afterHeal > target->getMaxHP()){
            target->setHP(target->getMaxHP());
            cout << "======" << endl;
            cout << Name << " leczy " << target->Name << "do maks hp" << "(" << target->getMaxHP() << " maxhp)" << endl;
            cout << "======" << endl;
        }
        else {
            target->setHP(target->getCurrentHP() + healAmount);
            cout << "======" << endl;
            cout << Name << " leczy " << target->Name << " dodająć: " << healAmount << " hp" << endl;
            cout << "======" << endl;
        }
    }


};

class Mage : public Character {
public:
    Mage(string name, int lvl) : Character(name, lvl) {}
    void setStats(int strength, int dexterity, int constitution, int intelligence, int max_hp, int armor_class) override {
        if (strength < 1 || strength > 20) Strength = 1;
        else Strength = strength;
        if (dexterity < 1 || dexterity > 20) Dexterity = 1;
        else Dexterity = dexterity;
        if (constitution < 1 || constitution > 20) Constitution = 1;
        else Constitution = constitution;
        if (intelligence < 1 || intelligence > 20) Intelligence = 1;
        else Intelligence = intelligence;
        if (max_hp < 1) Max_HP = 1;
        else Max_HP = max_hp + (Constitution / 5) + Level;
        Armor_class = armor_class + (Intelligence / 3);
    }
    void attack(Character* target) override {
        int hitChance = rand() % 20 + 1;
        int a = rand() % 10 + 1;
        int damage = a + (Intelligence / 5);
        if (hitChance == 20) damage *= 2;
        if (hitChance > target->getArmor()){
            cout << "======" << endl;
            if(hitChance == 20) cout << "KRYTYCZNE TRAFIENIE!" << endl;
            target->setHP(target->getCurrentHP() - damage);
            cout << Name << " atakuje " << target-> Name << " zaklęciem, zadając: " << damage << endl;
            cout << target-> Name << " ma teraz: " << target->getCurrentHP() << " hp" << endl;
            cout << "======" << endl;
        }
        else{
            cout << "======" << endl;
            cout << "Nie trafiony" << endl;
            cout << "======" << endl;
        }
    }
    void heal(Character* target) override {
        int roll = rand() % 6 + 1;
        int healAmount = roll + (Intelligence /5) + (Level * 1);
        int afterHeal = target->getCurrentHP() + healAmount;
        if (afterHeal > target->getMaxHP()){
            target->setHP(target->getMaxHP());
            cout << "======" << endl;
            cout << Name << " leczy " << target->Name << "do maks hp" << "(" << target->getMaxHP() << " maxhp)" << endl;
            cout << "======" << endl;
        }
        else {
            target->setHP(target->getCurrentHP() + healAmount);
            cout << "======" << endl;
            cout << Name << " leczy " << target->Name << " dodająć: " << healAmount << " hp" << endl;
            cout << "======" << endl;
        }
    }

};

class Rouge : public Character{
public:
    Rouge(string name, int lvl) : Character(name, lvl) {}
    void setStats(int strength, int dexterity, int constitution, int intelligence, int max_hp, int armor_class) override {
        if (strength < 1 || strength > 20) Strength = 1;
        else Strength = strength;
        if (dexterity < 1 || dexterity > 20) Dexterity = 1;
        else Dexterity = dexterity;
        if (constitution < 1 || constitution > 20) Constitution = 1;
        else Constitution = constitution;
        if (intelligence < 1 || intelligence > 20) Intelligence = 1;
        else Intelligence = intelligence;
        if (max_hp < 1) Max_HP = 1;
        else Max_HP = max_hp + (Constitution / 4) + Level;
        Armor_class = armor_class + (Dexterity / 3);
    }
    void attack(Character* target) override {
        int hitChance = rand() % 20 + 1;
        int a = rand() % 10 + 1;
        int damage = a + (Dexterity / 5);
        if (hitChance == 20) damage *= 3;
        if (hitChance > target->getArmor()){
            cout << "======" << endl;
            if(hitChance == 20) cout << "KRYTYCZNE TRAFIENIE!" << endl;
            target->setHP(target->getCurrentHP() - damage);
            cout << Name << " atakuje " << target-> Name << " kuszą, zadając: " << damage << endl;
            cout << target-> Name << " ma teraz: " << target->getCurrentHP() << " hp" << endl;
            cout << "======" << endl;
        }
        else{
            cout << "======" << endl;
            cout << "Nie trafiony" << endl;
            cout << "======" << endl;
        }
    }
    void heal(Character* target) override {
        int roll = rand() % 6 + 1;
        int healAmount = roll + (Intelligence /5) + (Level * 1);
        int afterHeal = target->getCurrentHP() + healAmount;
        if (afterHeal > target->getMaxHP()){
            target->setHP(target->getMaxHP());
            cout << "======" << endl;
            cout << Name << " leczy " << target->Name << "do maks hp" << "(" << target->getMaxHP() << " maxhp)" << endl;
            cout << "======" << endl;
        }
        else {
            target->setHP(target->getCurrentHP() + healAmount);
            cout << "======" << endl;
            cout << Name << " leczy " << target->Name << " dodająć: " << healAmount << " hp" << endl;
            cout << "======" << endl;
        }
    }
};



int main(){
    srand(time(0));  // odpalenie randoma
    Character *warrior = new Warrior("Kratos", 12);
    Character *mage = new Mage("Magik", 9 );
    Character *rouge = new Rouge("Gabon_nie_gruby", 15);
    warrior->attack(mage);
    rouge->attack(warrior);
    mage->attack(rouge);
    mage->attack(warrior);
    warrior->attack(rouge);
    rouge->attack(mage);
    rouge->heal(mage);
    warrior->heal(rouge);
    mage->heal(warrior);
}