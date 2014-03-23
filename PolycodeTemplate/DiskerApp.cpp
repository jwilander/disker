#include "DiskerApp.h"


DiskerApp::DiskerApp(PolycodeView *view) {
    core = new CocoaCore(view, 1280, 720, false, false, 0, 0, 60);
	CoreServices::getInstance()->getResourceManager()->addArchive("default.pak");
	CoreServices::getInstance()->getResourceManager()->addDirResource("default");

	// Write your code here!
}

DiskerApp::~DiskerApp() {
    
}

bool DiskerApp::Update() {
    return core->updateAndRender();
}