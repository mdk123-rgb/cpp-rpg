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
        srand(time(0));
        int roll = rand() % 20 + 1;
        if (roll == 20){
            int isCritical = 1;
            if (isCritical == true){
                int crit_dmg = 1.5;
            }
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
    void attack(Character* target) override {}

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
    void attack(Character* target) override {}
};



int main(){
    srand(time(0));  // odpalenie randoma
    cout << "Zabawa ypieeeeee" << endl;
    return 0;
}