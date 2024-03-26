#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H

#include "../Puck/Puck.h"
#include "../Paddle/Paddle.h"

class CollisionDetection {
public:
    static bool checkPaddlePuckCollision(const Paddle& paddle, const Puck& puck);
    static void respondToPaddlePuckCollision(Puck& puck, const Paddle& paddle);
    static void checkAndRespondToWallCollisions(Puck& puck, int tableWidth, int tableHeight);
};

#endif // COLLISIONDETECTION_H
