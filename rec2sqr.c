#include <stdio.h>

struct rectangle {
    int hight;
    int width;
};

int rec2sqr(struct rectangle eRect);

int main() {
    struct rectangle rect = {7,10};
    rec2sqr(rect);
    return 0;
}

int rec2sqr(struct rectangle eRect) {
    struct rectangle temp = {eRect.hight, eRect.width};
    if (temp.hight == temp.width){
        printf("%d\n", temp.width);
        return 0;
    } else if (temp.hight > temp.width) {
        printf("%d\n", temp.width);
        temp.hight = temp.hight - temp.width;
    } else if (temp.width > temp.hight) {
        printf("%d\n", temp.hight);
        temp.width = temp.width - temp.hight;
    }
    return rec2sqr(temp);
}