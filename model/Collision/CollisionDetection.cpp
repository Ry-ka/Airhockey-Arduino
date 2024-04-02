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
    
    int newX = puckPos.getX() + puckVel.getDx();
    int newY = puckPos.getY() + puckVel.getDy();


    // Horizontal wall collision
    if (newX <= 0 || newX >= tableWidth) {
        puck.setVelocity(-puckVel.getDx(), puckVel.getDy());
        // Adjust position more accurately
        puck.setPosition(std::max(1, std::min(tableWidth - 1, newX)), newY);
    }

    // Vertical wall collision
    if (newY <= 0 || newY >= tableHeight) {
        puck.setVelocity(puckVel.getDx(), -puckVel.getDy());
        // Adjust position more accurately
        puck.setPosition(newX, std::max(1, std::min(tableHeight - 1, newY)));
    }

}
