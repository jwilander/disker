#include "DiskerApp.h"

DiskerApp::DiskerApp(PolycodeView *view) {
    core = new POLYCODE_CORE(view, 1280,720,false,true,0,0,90, 0, true);
	CoreServices::getInstance()->getResourceManager()->addArchive("../Resources/default.pak");
	CoreServices::getInstance()->getResourceManager()->addDirResource("default");
    
    scene = new PhysicsScene2D(0.1, 60);
    scene->setGravity(Vector2(0.0f,0.0f));
    scene->getActiveCamera()->setOrthoSize(1280, 720);
    
    player = new Player(scene);
    
    inputHandler = new InputHandler(core->getInput(), player);
    core->getInput()->addEventListener(inputHandler, InputEvent::EVENT_KEYDOWN);
    core->getInput()->addEventListener(inputHandler, InputEvent::EVENT_KEYUP);
}

bool DiskerApp::Update() {
    
    float timeElapsed = core->getElapsed();
    
    player->Update(timeElapsed);

    return core->updateAndRender();
}

DiskerApp::~DiskerApp() {
    delete inputHandler;
    delete player;
    delete scene;
    delete core;
}