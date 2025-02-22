#include "mainAttacks.h"
#include<godot_cpp/classes/packed_scene.hpp>

MainAttacks::MainAttacks() {}

MainAttacks::~MainAttacks() {}

void MainAttacks::_bind_methods() {
    ClassDB::bind_method(D_METHOD("start_attack"), &MainAttacks::start_attack);
    ADD_SIGNAL(MethodInfo("throws",
        PropertyInfo(Variant::VECTOR2, "direction"),
        PropertyInfo(Variant::INT, "power")
    ));
}

void MainAttacks::_ready() {
    if(isEditor) return;
    Main = Object::cast_to<Node2D>(get("Main"));
    Box = Object::cast_to<Node2D>(get("Box"));
    Soul = Object::cast_to<CharacterBody2D>(get("Soul"));
}

void MainAttacks::start_attack() {
    if(type == PartType::SANS_1)
        sans_1();
}

void MainAttacks::set_type(PartType type) {
    this->type = type;
}

CharacterBody2D* MainAttacks::create_bone(AttackMack mack) {
    Ref<PackedScene> bone = get("bone");
    CharacterBody2D* b = Object::cast_to<CharacterBody2D>(bone->instantiate());
    call("add_bullet", b, mack);
    return b;
}

CharacterBody2D* MainAttacks::create_blaster(AttackMack mack) {
    Ref<PackedScene> blaster = get("blaster");
    CharacterBody2D* b = Object::cast_to<CharacterBody2D>(blaster->instantiate());
    call("add_bullet", b, mack);
    return b;
}