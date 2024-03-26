#include "CollisionDetection.h"

bool CollisionDetection::checkPaddlePuckCollision(const Paddle& paddle, const Puck& puck) {
    Position paddlePos = paddle.getPosition();
    Position puckPos = puck.getPosition();
    
    int dx = puckPos.getX() - paddlePos.getX();
    int dy = puckPos.getY() - paddlePos.getY();
    int distanceSquared = dx * dx + dy * dy;
    
    int sumRadiiSquared = (paddle.getWidth() / 2 + 10) * (paddle.getWidth() / 2 + 10);
    
    return distanceSquared < sumRadiiSquared;
}

void CollisionDetection::respondToPaddlePuckCollision(Puck& puck, const Paddle& paddle) {
    if (!checkPaddlePuckCollision(paddle, puck)) {
        return;
    }
    
    Velocity puckVel = puck.getVelocity();
    puck.setVelocity(-puckVel.getDx(), -puckVel.getDy());
}

void CollisionDetection::checkAndRespondToWallCollisions(Puck& puck, int tableWidth, int tableHeight) {
    Position puckPos = puck.getPosition();
    Velocity puckVel = puck.getVelocity();
    
    // Horizontal wall collision
    if (puckPos.getX() <= 0) {
        puck.setVelocity(-puckVel.getDx(), puckVel.getDy());
        puck.setPosition(1, puckPos.getY()); // Adjust position slightly inside
    } else if (puckPos.getX() >= tableWidth) {
        puck.setVelocity(-puckVel.getDx(), puckVel.getDy());
        puck.setPosition(tableWidth - 1, puckPos.getY()); // Adjust position slightly inside
    }

    // Vertical wall collision
    if (puckPos.getY() <= 0) {
        puck.setVelocity(puckVel.getDx(), -puckVel.getDy());
        puck.setPosition(puckPos.getX(), 1); // Adjust position slightly inside
    } else if (puckPos.getY() >= tableHeight) {
        puck.setVelocity(puckVel.getDx(), -puckVel.getDy());
        puck.setPosition(puckPos.getX(), tableHeight - 1); // Adjust position slightly inside
    }

}
