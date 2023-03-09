// BoxGameTwo.cpp: определяет точку входа для приложения.
//

#include "BoxGameTwo.h"

using namespace std;
using namespace Engine;

//define zone
#define print(text) cout << text
#define println(text) cout << text << endl

//global variables
Player player = Player();
string Buffer[10];

void Register() {
	print("write YOUR name\n>");
	cin >> Buffer[0];
	player = Player();
	player.Name = Buffer[0];
};

void TestMode() {
	Enemy en1 = Enemy(100, 9);
	if (player.SimpleBattle(en1)) { print("win"); }
	else { print("lose"); };
	println(player.inventory.GetItems());
	Item testItem; testItem.Weapon(10, "weapon", "wipon");
	player.inventory.AddItem(testItem, 1);
	println(player.inventory.GetItems());

}

int main()
{
	cout << "Hello Player" << endl;
	Register();
	if (player.Name == "TestEngine") { TestMode(); }
	
	print("enter something to close game: "); cin >> Buffer[0];
	return 0;
};