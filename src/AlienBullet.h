#ifndef ALIENBULLET_H
#define ALIENBULLET_H

#include "Bullet.h"

class AlienBullet : public Bullet {
public:
    AlienBullet(float x, float y);
    void move() override;
};

#endif