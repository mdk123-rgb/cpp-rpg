#include <iostream>
#include <string>
#include <random>


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
    void setHP(int hp) { Current_HP = hp; } // to i reszta to gettery bo nie posłuchałem pana Adama i nie dałem wszystkiego do konstruktora
    int getArmor() { return Armor_class; }
    int getCurrentHP() { return Current_HP; }
    int getMaxHP() {return Max_HP;}
    bool isAlive() { return Current_HP > 0; } // takie wymuszone chyba nwm tak wsumie ale jest to check czy postac żyje w boolu (true, false)
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
    while(true){ // pętla
        int alive = 0;
        int lastAlive = 0;
        for (int i = 0; i < 3; i++) { // pętla która sprawdza każdą postać (z indeksu (0,1,2)) | i++ oznacza 
            if (postacie[i]->isAlive()) { // jeśli postać żyje to "i" sie zwiększa i sprawdza kolejną postać, jest to w pętli (while true wiec to ciągle chodzi)
                alive++;
                lastAlive = i; // zapamiętuje indeks ostatniej żywej postaci
            }
        }
    if (alive <= 1) { // jeśli została jedna postać albo nikt jest koniec gry, niby taki fail safe ale chyba useless bo wiadomość by sie zjebała 
        cout << "#############################KONIEC#############################" << endl;
        cout << postacie[lastAlive]->Name << " Został ostatni na polu bitwy, wygrał walkę!" << endl;
        break; // wychodzi z pętli while(true)
    }
        int attacker = rand() % 3; // % 3 losuje {0,1,2} czyli indeksy postaci  {warrior, mage, rouge}
        int target = rand() % 3;
        if (attacker != target && postacie[target]->isAlive()) { // poprostu check czy postac żyje | jeszcze && to jest poprostu AND
            if (postacie[attacker]->getCurrentHP() < postacie[attacker]->getMaxHP() * 0.2) { // jeśli postac ma mniej niż 20% hp to sie sama uleczy
        postacie[attacker]->heal(postacie[attacker]);
    } else { // jeśli postać ma więcej niż 20% hp to atakuje przeciwnika
        postacie[attacker]->attack(postacie[target]);
    }
        }
}
}