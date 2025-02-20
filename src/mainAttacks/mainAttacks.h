#ifndef MainAttacks_H
#define MainAttacks_H
#include<godot_cpp/classes/node.hpp>
#include<godot_cpp/classes/character_body2d.hpp>
#include "../env.h"
namespace godot {
    class MainAttacks : public Node {
        GDCLASS(MainAttacks, Node);

        protected:
            static void _bind_methods();

        private:
            Node2D* Main;
            Node2D* Box;
            CharacterBody2D* Soul;

        public:
            MainAttacks();
            ~MainAttacks();

            void _ready() override;

            void sans_1();

            CharacterBody2D* create_bone(AttackMack mack);
            CharacterBody2D* create_blaster(AttackMack mack);
    };
}

#endif