#include "coreNode.h"
#include "../../env.h"

CoreNode::CoreNode() {}

CoreNode::~CoreNode() {}

void CoreNode::_bind_methods() {
    ClassDB::bind_method(D_METHOD("voidWall"), &CoreNode::voidWall);
}

void CoreNode::voidWall() {
    call("summontextbox").call("generic", m->dia().call("from", 
        Array::make(String::utf8("와 샌즈"))
    ));
    global->set("player_can_move", true);
}