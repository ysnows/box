//
//  MainLayer.cpp
//  box
//
//  Created by 咸光金 on 2016/12/12.
//
//

#include "MainLayer.h"


void MainLayer::initThings() {


}

void MainLayer::onCreateGameLayer(){
  _rootLayer=CSLoader::createNode("MainLayer.csb");
  if (_rootLayer==nullptr) {
       return;
   }

   addChild(_rootLayer);
   _rootLayout=static_cast<Layout *>(_rootLayer->getChildByName("Panel_Back"));


}


void MainLayer::onClick(Ref *sender){
  Button *view=dynamic_cast<Button *>(sender);

  if (view==nullptr) {
      return;
  }

  switch (view->getTag()) {
      case 1:


          break;

      default:
          break;
  }


}


bool MainLayer::init(){
    if (!Layer::init()) {
        return false;
    }
    director=Director::getInstance();
    visibleSize=director->getVisibleSize();
    visibleOrigin=director->getVisibleOrigin();
    _rootLayer=nullptr;
    _rootLayout=nullptr;
    initThings();

    return true;
}


Scene * MainLayer::createScene(){
    Scene *scene=Scene::create();
    auto layer=MainLayer::create();
    scene->addChild(layer);

    return scene;
}

void MainLayer::onEnter(){
  Layer::onEnter();
  onCreateGameLayer();
}

void MainLayer::onExit(){
  TextureCache::getInstance()->removeUnusedTextures();
  Layer::onExit();

}
