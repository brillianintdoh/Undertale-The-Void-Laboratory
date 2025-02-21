#ifndef Enemy_SANS1_H
#define Enemy_SANS1_H
#include<godot_cpp/classes/character_body2d.hpp>
#include<godot_cpp/classes/back_buffer_copy.hpp>
#include<godot_cpp/classes/texture_rect.hpp>
#include<godot_cpp/classes/animated_sprite2d.hpp>
#include<godot_cpp/classes/remote_transform2d.hpp>
#include<godot_cpp/classes/animation_node_state_machine_playback.hpp>
#include<godot_cpp/classes/timer.hpp>
namespace godot {
    class Enemy_SANS1 : public CharacterBody2D {
        GDCLASS(Enemy_SANS1, CharacterBody2D);

        protected:
            static void _bind_methods();

        private:
            int is;
            Node2D* Main;
            Node2D* Box;
            CharacterBody2D* Soul;
            BackBufferCopy* Attacks;
            Control* Dialogue;
            TextureRect* backScene;
            AnimationNodeStateMachinePlayback* AnimStates;

            Node2D* sprites;
            AnimatedSprite2D* body;
            AnimatedSprite2D* head;
            AnimatedSprite2D* leg;
            RemoteTransform2D* camera;

            AnimatedSprite2D* throw_head;
            Timer* throw_timer;

            Ref<Resource> mainAttack;

        public:
            Enemy_SANS1();
            ~Enemy_SANS1();

            void get_turn();

            void camera_pro(float time, String key="all", Variant value=true);
            void _on_throws(Vector2 dir=Vector2(0, 1), int power = 10);
            void end_throws();

            void _ready() override;
    };
}

#endif