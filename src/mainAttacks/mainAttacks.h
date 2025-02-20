#ifndef MainAttacks_H
#define MainAttacks_H
#include<godot_cpp/classes/node.hpp>
#include<godot_cpp/classes/character_body2d.hpp>
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

            void start_attack();
            CharacterBody2D* create_bone(int mack);
    };
}

#endif