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
        Current_HP = Max_HP;
        cout << "======" << endl;
        cout << "Stworzono nową postać:: Imie: " << Name << "z poziomem: " << Level << endl;
        cout << "HP: " << getCurrentHP() << endl;
        cout << "Statystyki ▼" << endl;
        cout << "Siła: " << Strength << endl;
        cout << "Zwinność: " << Dexterity << endl; 
        cout << "Konstytucja: " << Constitution << endl;
        cout << "Inteligencja: " << Intelligence << endl;
        

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
            
        }
        else{
            cout << "======" << endl;
            cout << "Nie trafiony" << endl;
            
        }
    }   

    void heal(Character* target) override {
        int roll = rand() % 6 + 1;
        int healAmount = roll + (Intelligence /5) + (Level * 1);
        int afterHeal = target->getCurrentHP() + healAmount;
        if (afterHeal > target->getMaxHP()){
            target->setHP(target->getMaxHP());
            cout << "======" << endl;
            cout << Name << " leczy " << target->Name << " do maks hp " << "(" << target->getMaxHP() << " maxhp )" << endl;
            
        }
        else {
            target->setHP(target->getCurrentHP() + healAmount);
            cout << "======" << endl;
            cout << Name << " leczy " << target->Name << " dodając: " << healAmount << " hp" << endl;
            
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
        Current_HP = Max_HP;
        cout << "======" << endl;
        cout << "Stworzono nową postać:: Imie: " << Name << "z poziomem: " << Level << endl;
        cout << "HP: " << getCurrentHP() << endl;
        cout << "Statystyki: ▼" << endl;
        cout << "Siła: " << Strength << endl;
        cout << "Zwinność: " << Dexterity << endl; 
        cout << "Konstytucja: " << Constitution << endl;
        cout << "Inteligencja: " << Intelligence << endl;
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
            
        }
    }
    void heal(Character* target) override {
        int roll = rand() % 6 + 1;
        int healAmount = roll + (Intelligence /5) + (Level * 1);
        int afterHeal = target->getCurrentHP() + healAmount;
        if (afterHeal > target->getMaxHP()){
            target->setHP(target->getMaxHP());
            cout << "======" << endl;
            cout << Name << " leczy " << target->Name << " do maks hp " << "(" << target->getMaxHP() << " maxhp )" << endl;
            
        }
        else {
            target->setHP(target->getCurrentHP() + healAmount);
            cout << "======" << endl;
            cout << Name << " leczy " << target->Name << " dodając: " << healAmount << " hp" << endl;
            
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
        Current_HP = Max_HP;
        cout << "======" << endl;
        cout << "Stworzono nową postać:: Imie: " << Name << "z poziomem: " << Level << endl;
        cout << "HP: " << getCurrentHP() << endl;
        cout << "Statystyki: ▼" << endl;
        cout << "Siła: " << Strength << endl;
        cout << "Zwinność: " << Dexterity << endl; 
        cout << "Konstytucja: " << Constitution << endl;
        cout << "Inteligencja: " << Intelligence << endl;
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
            
        }
        else{
            cout << "======" << endl;
            cout << "Nie trafiony" << endl;
            
        }
    }
    void heal(Character* target) override {
        int roll = rand() % 6 + 1;
        int healAmount = roll + (Intelligence /5) + (Level * 1);
        int afterHeal = target->getCurrentHP() + healAmount;
        if (afterHeal > target->getMaxHP()){
            target->setHP(target->getMaxHP());
            cout << "======" << endl;
            cout << Name << " leczy " << target->Name << " do maks hp " << "(" << target->getMaxHP() << " maxhp )" << endl;
            
        }
        else {
            target->setHP(target->getCurrentHP() + healAmount);
            cout << "======" << endl;
            cout << Name << " leczy " << target->Name << " dodając: " << healAmount << " hp" << endl;
            
        }
    }
};



int main(){
    srand(time(0));  // odpalenie randoma
    Character *warrior = new Warrior("Kratos", 12);
    Character *mage = new Mage("Magik", 9 );
    Character *rouge = new Rouge("Gabon_nie_gruby", 15);
    
    warrior->setStats(rand() % 20 + 1, rand() % 20 + 1, rand() % 20 + 1, rand() % 20 + 1, rand() % 100 + 1, rand() % 20 + 1);
    mage->setStats(rand() % 20 + 1, rand() % 20 + 1, rand() % 20 + 1, rand() % 20 + 1, rand() % 100 + 1, rand() % 20 + 1);
    rouge->setStats(rand() % 20 + 1, rand() % 20 + 1, rand() % 20 + 1, rand() % 20 + 1, rand() % 100 + 1, rand() % 20 + 1);
    

    Character* postacie[3] = {warrior, mage, rouge}; // postacie[3], trzeba napisać trzy ponieważ indeksy ({warrior, mage, rouge}) zaczynają sie op 0 ale elementy w tabeli od 1 dlatego rozmiar tabeli to 3 [3]
    for (int i = 0; i < 10; i++) { // i++ to skrót od i = i + 1 | ta pętla sie wykona 10 razy || na początku "i" ma wartość 0 potem "i" jest sprawdzane czy jest mniejsze niż 10, jeśli jest pętla sie wykona i dzięki "i++" i sie zwiekszy o 1 i potem jest znowu sprawdzane
        int attacker = rand() % 3; // % 3 losuje {0,1,2} czyli indeksy postaci  {warrior, mage, rouge}
        int target = rand() % 3;
        if (attacker != target) { // check aby postac nie biła sama siebie
            postacie[attacker]->attack(postacie[target]);
        }
}
}