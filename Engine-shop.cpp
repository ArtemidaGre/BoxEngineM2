#include "BoxGameTwo.h"

#define SHOP_MAX 15

namespace Engine {
    class Shop {
    private:
        Item shop[SHOP_MAX];
        Player play;
    public:
        Shop(Player player, Item i1[]) {
            play = player;
            for (int i = 0; i < SHOP_MAX; i++) {
                shop[i] = i1[i];
            }
        }
        void BuySome(int number, Player player) {
            try {
                if (player.WorkWithCoins() <= shop[number].Cost) {
                    if (shop[number].GetType() != 'e' && shop[number].GetType() != 's') {
                        player.inventory.AddItem(shop[number]);
                        player.WorkWithCoins(true, -shop[number].Cost);
                    }
                }
            }
            catch (int e) {throw e;}
            }
        void SellSome(Item itemToSell, Player player) {
            player.WorkWithCoins(true, itemToSell.Cost);
            itemToSell.GetType();
            delete &itemToSell;
        };
    };
}