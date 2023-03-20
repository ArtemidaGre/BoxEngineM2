#include "BoxGameTwo.h"

namespace Engine{
	class Unit {
	private:
		int HP, Damage;
	public:
		std::string Name;
		int WorkWithHp(bool Set = false, int set = 0) {
			if (!Set) {
				return HP;
			}
			else {
				HP += set;
			}
		}
		int WorkWithDamage(bool Set = false, int set = 0) {
			if (!Set) {
				return Damage;
			}
			else {
				Damage += set;
			}
		}
	};
}