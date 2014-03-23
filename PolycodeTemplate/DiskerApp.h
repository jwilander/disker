//
// Polycode template. Write your code here.
//

#include <Polycode.h>
#include "PolycodeView.h"
#include "Polycode2DPhysics.h"

using namespace Polycode;

class DiskerApp {
public:
    DiskerApp(PolycodeView *view);
    ~DiskerApp();
    
    bool Update();
    
private:
    Core *core;
    PhysicsScene2D *scene;
};