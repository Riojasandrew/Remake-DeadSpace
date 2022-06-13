// Remake DeadSpace.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;
using std::string;

int determineAttacker() {
    int test = rand() % 10;
    return (test > 4) ? 1 : 0;
}


class Necromorph {
private:
    string Name;
    string Health;
    string Weakness;
    int DamageType = 26;
    int LoseHealth = 30;
public:
    // Setters for names
    void setName(string name) {
        Name = name;
    }
    // Getters for value
    string getName() {
        return Name;
    }
    void getHealth(string health) {
        Health = health;
    }
    string getHealth() {
        return Health;
    }
    void getWeakness(string weakness) {
        Weakness = weakness;
    }
    string getWeakness() {
        return Weakness;
    }
    void getDamageType(int damagetype) {
        DamageType = damagetype;
    }
    int getDamageType() {
        return DamageType;
    }
    void NecromorphAi() {
        cout << "Type: " << Name << endl;
        cout << "Health: " << Health << endl;
        cout << "Damage: " << DamageType << endl;
        cout << "Weakness: " << Weakness << endl;
    }
    Necromorph(string name, string health, int damagetype, string weakness) {
        Name = name;
        Health = health;
        DamageType = damagetype;
        Weakness = weakness;
    }
    void getLoseHealth(int losehealth) {
        LoseHealth = losehealth;
    }
    int loseHealth() {
        return LoseHealth;
    }

};

class People {
private:
    string Name;
    string Death;
    string Location;
public:
    // Setters for names
    void setName(string name) {
        Name = name;
    }
    // Getters for value
    string getName() {
        return Name;
    }
    void setDeath(string death) {
        Death = death;
    }
    string getDeath() {
        return Death;
    }
    void setLocation(string location) {
        Location = location;
    }
    string getLocation() {
        return Location;
    }
    void aiPeople() {
        cout << "Name: " << Name << endl;
        cout << "Death: " << Death << endl;
        cout << "Location:: " << Location << endl;
    }
    void aiPeople(string name, string death, string location) {
        Name = name;
        Death = death;
        Location = location;
    }
};

void choice1() {
    string playerName;
    int m = 1;
    string enemy = "Necromorphs";
    // int m1;
    while (m == 1) {
        cout << "Press 1 to search bodies or Press 2 to look in rooms: ";
        cin >> m;

        switch (m)
        {
        case 1:
            // loop
            cout << "You being searching bodies and found nothing\n";
            break;
            // proceed+  
        case 2:
            cout << "*You searched the desk and found a crowbar allowing you to pry the door open*" << endl;
            cout << "*You begin prying the door open than you hear noises amoung \nthe dark* *GROANING* A disfigured"
                " creature appears before you." << endl;
            cout << playerName << ": What the h*ck are you! *You grip the crowbar and get ready to fight the creature*" << endl;
            
            break;
        default:
            // Death
            cout << "*You try entering a dark room and don't see anything.\n You grab a lighter from your pocket and start"
                " trying to turn it on. \nWith each flick the shadows of the undead start to fill around you* *Door closes "
                "and distance scream fill the room*" << endl;
            break;
        }
    }
}

int main()
{
    fstream myProgram;
    // name
    string playerName;
    cout << "\t\t\t\t\t\t\tDead Space" << endl;
    // Describtion of the Game
    cout << "Welcome player for checking out my designer program. In this game"
        "you are a survivor on the ship of Ishimura.\nIncounter challenge along the way and making sure you"
        "manage to escape the horror!" << endl;
    cout << "Now what is your name before we begin the program?\n Name: ";
    cin >> playerName;
    
    cout << "Alrigty " << playerName << " lets get started!" << endl;
    cout << "Press Enter to open your eyes..";
    cin.get();
    // Player waking up
    cout << "\nYou slowly open your eyes and find nothing but bodies around you. You quickly"
        " get up and think to yourself. \nAlright " << playerName << " you were going to go get your daughter"
        " from daycare and than everyone start running and screaming. \nNow I'm here and have to go find my daughter..!"
        " *You begin walking and soon find yourself by a locked door \n noises and crawling is being heard around you* \n"
        "How would you like to procceed?"<<endl;

    // Switch Stament search area
    choice1();
    // Constructor for Enemy and player
    Necromorph enemy1 = Necromorph("Infector", "25", 26, "Limbs");
    enemy1.NecromorphAi();
    Necromorph enemy2 = Necromorph("Player", "100", 55, "Unknown");
    enemy2.NecromorphAi();
    cout << playerName << " health is " << enemy2.getHealth() << " and did " <<
        enemy2.getDamageType() << "!" << endl;
    cout << "Creature" << " health is " << enemy1.getHealth() << " and did " <<
        enemy1.getDamageType() << "!" << endl;
    int round = 2;
    while (true)
    {
        cout << "Turns " << round << ", battle" << endl;
        if (determineAttacker()) {
            cout << enemy1.getName() << " is attacking first" << endl;
            enemy1.getLoseHealth(enemy2.getDamageType());
            enemy2.getLoseHealth(enemy1.getDamageType());
     }
        else {
            cout << enemy2.getName() << " is attacking first" << endl;
            enemy2.getLoseHealth(enemy1.getDamageType());
            enemy1.getLoseHealth(enemy2.getDamageType());
            cout << enemy2.getName() << "'s health is now " << enemy2.getHealth() << endl;
            cout << enemy1.getName() << "'s health is now " << enemy1.getHealth() << endl;
            cout << " You manage to kill the creature and worked your way into the daycare to \n find your daughter" << endl;
            cout << "Demo termaniting in ";

            cout << " You have reached the end of the demo for now.. If you have any ideas about the game let me know\n"
                "by writing in the comments on my github. Github is located in file." << endl;
            
            myProgram.open("deadspace.txt", ios::out); // write in file
            if (myProgram.is_open()) {
                cout << "Riojasandrew" << endl;
                myProgram.close();
            }
            myProgram.open("myHorror", ios::out|ios::in|ios::app);
            if (myProgram.is_open()) {
                myProgram << "Thank you for checking out my program!\n";
                myProgram.close();
            }
        }
        break;
    }
    
    

}
