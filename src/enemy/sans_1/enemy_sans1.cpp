#include "enemy_sans1.h"
#include "../../env.h"

Enemy_SANS1::Enemy_SANS1() {}

Enemy_SANS1::~Enemy_SANS1() {}

void Enemy_SANS1::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_on_get_turn"), Enemy_SANS1::get_turn);
}

void Enemy_SANS1::_ready() {
    Main = Object::cast_to<Node2D>(get("Main"));
    Soul = Object::cast_to<CharacterBody2D>(get("Soul"));
    Attacks = Object::cast_to<BackBufferCopy>(get("Attacks"));
}

void Enemy_SANS1::get_turn() {
    Soul->call("red");
}