#include <stdio.h>

#define equal 1
#define bigger 2
#define smaller 0.5
#define magic_number 50


enum effectiveness {
    water, fire, earth, air
};


struct pokemon {
    double attack;
    double defence;
    enum effectiveness effect;
};

int compare_pokemons(struct pokemon p1, struct pokemon p2);

double compare_effects(struct pokemon p1, struct pokemon p2);

int main() {
    struct pokemon p1 = {100, 100, fire};
    struct pokemon p2 = {100, 100, air};

    if (compare_pokemons(p1, p2) == 1)
        printf("pokemon 1 is stronger");
    else if (compare_pokemons(p1, p2) == 2)
        printf("pokemon 2 is stronger");
    else
        printf("pokemons are equal");
    return 0;
}

int compare_pokemons(struct pokemon p1, struct pokemon p2) {
    double p1_power = (p1.attack / p2.defence) * magic_number * compare_effects(p1, p2);
    double p2_power = (p2.attack / p1.defence) * magic_number * compare_effects(p2, p1);

    if (p1_power > p2_power)
        return 1;
    else if (p1_power < p2_power)
        return 2;
    else
        return 0;
}

double compare_effects(struct pokemon self, struct pokemon opponent) {
    if ((self.effect == water && opponent.effect == fire) || (self.effect == fire && opponent.effect == air) ||
        (self.effect == earth && opponent.effect == water) || (self.effect == air && opponent.effect == earth)
            ) {
        return bigger;
    } else if ((self.effect == fire && opponent.effect == water) || (self.effect == air && opponent.effect == fire) ||
               (self.effect == water && opponent.effect == earth) || (self.effect == earth && opponent.effect == air)
            ) {
        return smaller;
    } else {
        return equal;
    }
}