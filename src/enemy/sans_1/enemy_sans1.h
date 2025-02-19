#ifndef Enemy_SANS1_H
#define Enemy_SANS1_H
#include<godot_cpp/classes/character_body2d.hpp>
#include<godot_cpp/classes/back_buffer_copy.hpp>
namespace godot {
    class Enemy_SANS1 : public CharacterBody2D {
        GDCLASS(Enemy_SANS1, CharacterBody2D);

        protected:
            static void _bind_methods();

        private:
            Node2D* Main;
            CharacterBody2D* Soul;
            BackBufferCopy* Attacks;

        public:
            Enemy_SANS1();
            ~Enemy_SANS1();

            void get_turn();

            void _ready() override;
    };
}

#endif