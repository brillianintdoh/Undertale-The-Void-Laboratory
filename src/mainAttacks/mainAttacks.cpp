#include "mainAttacks.h"
#include "../env.h"
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
    emit_signal("throws", Vector2(0, 1));

    sys->time_loop([this](double delta) {
        static double time = 1.5;
        if(time >= 1.5) {
            CharacterBody2D* b = create_bone(AttackMack::ABSOLUTE);
            b->set_rotation_degrees(180);
            b->set_position(Vector2(120, 400));
            b->call("fire", Vector2(420, 400), Bullet::MOVEMENT_TWEEN, 160);
            b->call("tween_height", 70, 1.1);

            CharacterBody2D* b2 = create_bone(AttackMack::ABSOLUTE);
            b2->set_rotation_degrees(180);
            b2->set_position(Vector2(520, 400));
            b2->call("fire", Vector2(220, 400), Bullet::MOVEMENT_TWEEN, 160);
            b2->call("tween_height", 70, 1.1);
            sys->sleep([this, b, b2]() { b->queue_free(); b2->queue_free(); }, 1.8);
            time = 0;
        }else time += delta;
    }, 10);
}

CharacterBody2D* MainAttacks::create_bone(int mack) {
    Ref<PackedScene> bone = get("bone");
    CharacterBody2D* b = Object::cast_to<CharacterBody2D>(bone->instantiate());
    call("add_bullet", b, mack);
    return b;
}