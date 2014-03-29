#include "DiskerApp.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

DiskerApp::DiskerApp(PolycodeView *view) {
    core = new POLYCODE_CORE(view, SCREEN_WIDTH, SCREEN_HEIGHT, false, true, 0, 0, 90, 0, true);
	CoreServices::getInstance()->getResourceManager()->addArchive("../Resources/default.pak");
	CoreServices::getInstance()->getResourceManager()->addDirResource("default");
    
    scene = new PhysicsScene2D(0.1, 60);
    scene->setGravity(Vector2(0.0f,0.0f));
    scene->getActiveCamera()->setOrthoSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    
    player = new Player(scene);
    
    boundary = new Boundary(scene, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    inputHandler = new InputHandler(core->getInput(), player);
    core->getInput()->addEventListener(inputHandler, InputEvent::EVENT_KEYDOWN);
    core->getInput()->addEventListener(inputHandler, InputEvent::EVENT_KEYUP);
    
    collisionHandler = new CollisionHandler(scene, player);
    scene->addEventListener(collisionHandler, PhysicsScene2DEvent::EVENT_NEW_SHAPE_COLLISION);
}

bool DiskerApp::Update() {
    
    float timeElapsed = core->getElapsed();
    
    player->Update(timeElapsed);

    return core->updateAndRender();
}

DiskerApp::~DiskerApp() {
    delete inputHandler;
    delete collisionHandler;
    delete player;
    delete scene;
    delete core;
}