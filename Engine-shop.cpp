#include "BoxGameTwo.h"

#define SHOP_MAX 15

namespace Engine {
    class Shop {
    private:
        Item shop[SHOP_MAX];
        Player play;
    public:
        Shop(Player player, Item i1[SHOP_MAX] = NULL) {
            play = player;
            for (int i = 0; i < SHOP_MAX; i++) {
                if (i1[i].GetType() == 'e') {
                    i1[i] = NULL;
                }
            }
        }
        void BuySome(int number, Player player) {
            if (player.WorkWithCoins() <= shop[number].Cost) {
                if (shop[number].GetType() != 'e' && shop[number].GetType() != 's') {
                    player.inventory.AddItem(shop[number]);
                    player.WorkWithCoins(true, -shop[number].Cost);
                }
                
            }
        }
        void SellSome(Item itemToSell, Player player) {
            player.WorkWithCoins(true, itemToSell.Cost);
        };
    };
}