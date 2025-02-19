#include "enemy_sans1.h"
#include "../../env.h"
#include<godot_cpp/classes/property_tweener.hpp>
#include<godot_cpp/classes/tween.hpp>

Enemy_SANS1::Enemy_SANS1() {}

Enemy_SANS1::~Enemy_SANS1() {}

void Enemy_SANS1::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_on_get_turn"), Enemy_SANS1::get_turn);
}

void Enemy_SANS1::_ready() {
    if(isEditor) return;
    Main = Object::cast_to<Node2D>(get("Main"));
    Soul = Object::cast_to<CharacterBody2D>(get("Soul"));
    Attacks = Object::cast_to<BackBufferCopy>(get("Attacks"));
    backScene = Object::cast_to<TextureRect>(Main->get("backScene"));

    sprites = Object::cast_to<Node2D>(get_node_internal("Sprites"));
    body = Object::cast_to<AnimatedSprite2D>(get_node_internal("Sprites/Idle/body"));
    leg = Object::cast_to<AnimatedSprite2D>(get_node_internal("Sprites/Idle/leg"));
    head = Object::cast_to<AnimatedSprite2D>(get_node_internal("Sprites/Idle/body/head"));

    sprites->set_z_index(102);
    body->set_frame(8);
    head->set_frame(17);
    leg->set_frame(2);
    backScene->set_visible(true);
}

void Enemy_SANS1::get_turn() {
    int turnNumber = Main->get("TurnNumber");
    if(turnNumber == 0) {
        Node2D* friends = Object::cast_to<Node2D>(get_node_internal("friends"));
        sys->sleep([this, friends]() {
            friends->set_visible(true);
            friends->set_modulate(Color(1, 1, 1, 0)); 
            Tween* tween = Object::cast_to<Tween>(create_tween().ptr());
            tween->tween_property(friends, "modulate:a", 1.0, 8.0);
            sys->sleep([this, friends]() {
                Tween* tween = Object::cast_to<Tween>(create_tween().ptr());
                tween->tween_property(friends, "modulate:a", 0.0, 5.0);
                tween->connect("finished", Callable(friends, "queue_free"));
            }, 7);
        }, 3);
        sys->sleep([this]() {
            head->set_frame(18);
            sys->sleep([this]() {
                head->set_frame(19);
            }, 2);
        }, 17);
    }
}
