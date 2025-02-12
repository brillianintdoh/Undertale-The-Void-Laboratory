#ifndef CoreNode_H
#define CoreNode_H
#include<godot_cpp/classes/node2d.hpp>
namespace godot {
    class CoreNode : public Node2D {
        GDCLASS(CoreNode, Node2D);

        protected:
            static void _bind_methods();

        public:
            CoreNode();
            ~CoreNode();

            void init();
            void voidWall();
            void event1();
            void text_trigger1();
    };
}

#endif