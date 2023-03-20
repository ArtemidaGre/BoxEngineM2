#include <iostream>
#include <format>
#include "stdlib.h"

//using namespace std;

#define TYPES_COUNT 5

namespace Engine{
    class Enemy{
    public:
        int Hp, Damage;
        bool IsAlive(){if (Hp>0){return true;}else{return false;}};
        std::string Name;
        Enemy(int hp = 50, int damage = 10, std::string name = "enemy"){
            Hp = hp;
            Damage = damage;
            Name = name;
        };
    };
    class Item{
    private:
        char Type = 'e';
        //'w'-weapon  'f'-food  'a'-ability 's'-story unit 'e'-empty
        int Effect = 0;
        std::string Description = "empty";
        std::string Name = "empty";
    public:
        char ReadyTypes[TYPES_COUNT] = { 'w', 'f', 'a', 's', 'e' };
        int Cost;
        Item(char type = 'e', int effect = 0, std::string name = "empty", int cost = 0) {
            Type = type;
            Name = name;
            if (type != 's') {
                Effect = effect;
            }
            Cost = cost;
        }
        void Weapon(int effect, std::string name, std::string Des){
            Type = 'w';
            Effect = effect;
            Description = Des;
            Name = name;
        };
        void Food(int effect, std::string name, std::string Des){
            Type = 'f';
            Effect = effect;
            Description = Des;
            Name = name;
        };
        void HistoryItem(std::string name){
            Type = 's';
            Name = name;
        }
        std::string GetName(){return Name;};
        char GetType() { return Type; }; void SetType(char type) {
            for (int i = 0; i < TYPES_COUNT; i++) {
                
            }
        };
        int GetEffect() { return Effect; }
    };
    class Inventory{
    private:
        static const int MaxItems = 10;
        Item Inventory[MaxItems];
    public:
        std::string GetItems(){
            std::string Result = "Items: ";
            for (int i = 0; i < MaxItems; i++){
              Result += std::format("\n{}.{}", i, Inventory[i].GetName());
            }
            return Result;
        };
        Item checkItem(std::string Name = "WhyAreYouFindingThisItem,ItDoesn'tExsists"){
            int Buffer;
            Item NullableItem = Item();
            for (int i = 0; i < MaxItems; i++){
                if (Name != "WhyAreYouFindingThisItem,ItDoesn'tExsists!"){
                    if (Inventory[i].GetName() == Name){
                        Buffer = i;
                    }
                }
                else{
                    return NullableItem;
                    break;
                }
            }
            return Inventory[Buffer];
        };
        int AddItem(Item unit){
            for (int i = 0; i < MaxItems; i++) {
                if (Inventory[i].GetType() != 's') {
                    Inventory[i] = unit;
                    return i;
                }
            }
            return NULL;
        };
    };
    class Player{
    private:
        int Hp, Damage, Coins;
        float Defence, Accuracy;
    public:
        void AddDamage(int effect) { Damage += effect; }
        void AddHp(int effect) { Hp += effect; }
        std::string Name;
        Inventory inventory;
        Player (int hp = 100, int damage = 15, float defence = 0.9, float accuracy = 0.5, std::string name = "player", int coins = 100){
            Hp = hp;
            Damage = damage;
            Defence = defence;
            Accuracy = accuracy;
            Name = name;
            Coins = coins;
        }
        bool SimpleBattle(Enemy enemy){
            //int BattleBuffer = 99999999;
            //while(BattleBuffer >= 100){BattleBuffer = rand();};
            while (enemy.IsAlive() && IsAlive()){
                if (IsAlive()) {
                    enemy.Hp = enemy.Hp - Damage;
                    std::cout << std::format("Enemy hp: {}\n", enemy.Hp);
                }
                else { return false; };
                if (enemy.IsAlive()){
                    Hp = Hp - enemy.Damage;
                    std::cout << std::format("Your hp: {}\n", Hp);
                }
                else {
                    return true;
                }
            }
            if (IsAlive()) { return true; }
            else {}
        };
        bool IsAlive(){if (Hp>0){return true;}else{return false;}};
        int WorkWithCoins(bool IsSetter = false, int setter = 0) { if (!IsSetter) { return Coins; } else { Coins += setter; } }
        void UseItem(Item item, Player player) { if (item.GetType() != 's') { if (item.GetType() == 'w') { player.AddDamage(item.GetEffect()); } if (item.GetType() == 'f') { player.AddHp(item.GetEffect()); } } }
    };
};
