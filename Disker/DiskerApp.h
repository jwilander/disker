#include <Polycode.h>
#include "PolycodeView.h"
#include "Polycode2DPhysics.h"
#include "Player.h"
#include "Boundary.h"
#include "CollisionHandler.h"
#include "InputHandler.h"

using namespace Polycode;

class DiskerApp {
public:
    DiskerApp(PolycodeView *view);
    ~DiskerApp();
    
    bool Update();
    
private:
    // core objects
    Core *core;
    PhysicsScene2D *scene;
    
    // handlers and managers
    InputHandler *inputHandler;
    CollisionHandler *collisionHandler;
    
    // world objects
    Player *player;
    Boundary *boundary;
    SceneSprite *image;
    
};