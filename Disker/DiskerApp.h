#include <Polycode.h>
#include "PolycodeView.h"
#include "Polycode2DPhysics.h"
#include "Player.h"
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
    
    // world objects
    Player *player;
    SceneSprite *image;
    
};