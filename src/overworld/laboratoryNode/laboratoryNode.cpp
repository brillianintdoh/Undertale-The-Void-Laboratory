#include "laboratoryNode.h"
#include "../../env.h"

LaboratoryNode::LaboratoryNode() {}

LaboratoryNode::~LaboratoryNode() {}

void LaboratoryNode::_bind_methods() {
    ClassDB::bind_method(D_METHOD("init"), &LaboratoryNode::init);
}

void LaboratoryNode::init() {
    if(isEditor) return;
    camera = Object::cast_to<Camera2D>(global->get("scene_container").get("Camera"));
}