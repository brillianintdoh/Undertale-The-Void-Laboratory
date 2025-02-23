#include "mainAttacks.h"

void MainAttacks::sans_1() {
    emit_signal("throws", Vector2(0, 1));

    double* time = new double(1.5);
    sys->time_loop([this, time](double delta) {
        if(*time >= 1.5) {
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
            *time = 0;
        }else *time += delta;
    }, 10);
    sys->sleep([this]() {
        Soul->call("set_mode", SoulMode::RED);
        Box->call("change_size", Vector2(200, 140));
        double* time = new double(1.5);
        sys->time_loop([this, time](double delta) {
            if(*time >= 1.5) {
                CharacterBody2D* bl = create_blaster(AttackMack::ABSOLUTE);
                Vector2 Sv = Soul->get_position();
                bl->set_position(Vector2(Sv.x, -100));
                bl->call("fire", Vector2(Sv.x, 100), 1.5, 0.3, 0.7);

                CharacterBody2D* b1 = create_bone(AttackMack::RELATIVE_BOX_CLIP);
                b1->set_rotation_degrees(-90);
                b1->set_position(Vector2(0, 0));
                b1->call("tween_height", 110, 0);
                Vector2 pos1 = b1->get_global_position();
                pos1.y += 200;
                b1->call("fire", pos1, Bullet::MOVEMENT_TWEEN, 85);

                CharacterBody2D* b2 = create_bone(AttackMack::RELATIVE_BOX_CLIP);
                b2->set_rotation_degrees(90);
                b2->set_position(Vector2(200, 140));
                b2->call("tween_height", 110, 0);
                Vector2 pos2 = b2->get_global_position();
                pos2.y -= 200;
                b2->call("fire", pos2, Bullet::MOVEMENT_TWEEN, 85);

                sys->sleep([this, b1, b2]() { b1->queue_free(); b2->queue_free(); }, 1.3);
                *time = 0;
            }else *time += delta;
        }, 10);
        sys->sleep([this]() {
            CharacterBody2D* b = create_bone(AttackMack::ABSOLUTE_CLIP);
            b->set_rotation_degrees(180);
            b->set_position(Vector2(120, 400));
            b->call("set_mode", AttackMode::MODE_BLUE);
            b->call("fire", Vector2(420, 400), Bullet::MOVEMENT_TWEEN, 160);
            b->call("tween_height", 150, 0);

            CharacterBody2D* b2 = create_bone(AttackMack::ABSOLUTE_CLIP);
            b2->set_rotation_degrees(180);
            b2->set_position(Vector2(520, 400));
            b2->call("set_mode", AttackMode::MODE_BLUE);
            b2->call("fire", Vector2(220, 400), Bullet::MOVEMENT_TWEEN, 160);
            b2->call("tween_height", 150, 0);
            sys->sleep([this, b, b2]() { b->queue_free(); b2->queue_free(); }, 1.8);
        }, 10.5);
    }, 10.1);
    sys->sleep([this]() {
        Box->call("change_size", Vector2(430, 210));
        double* time = new double(2.2);
        sys->time_loop([this, time](double delta) {
            if(*time >= 2.2) {
                for(int i = 0; i < 4; i++) {
                    CharacterBody2D* bl = create_blaster(AttackMack::ABSOLUTE);
                    float angle = i * (Math_PI / 4.0); 
                    Vector2 center = Soul->get_position();
                    
                    Vector2 pos = center + Vector2(cos(angle), sin(angle)) * 200;
                    bl->set_position(pos);
                    bl->set_rotation(angle + Math_PI);  
                    
                    bl->call("fire", center, 1.5, 0.5, 1.3);
                }
                *time = 0;
            }else *time += delta;
        }, 10);
    }, 24.5);
}