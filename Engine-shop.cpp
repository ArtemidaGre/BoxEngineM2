#include "BoxGameTwo.h"

namespace Engine {
    class ShopItem : Item {
    private:
        int costl;
    public:
        ShopItem(Item item) {
            
        }
    };
    class Shop {
    private:
        ShopItem shop[3];
        Player play;
    public:
        Shop(Item i1, Player player, Item i2 = NULL, Item i3 = NULL) {
            shop[0] = i1;
            play = player;
            shop[1] = i2;
            shop[2] = i3;
        }
    };
}