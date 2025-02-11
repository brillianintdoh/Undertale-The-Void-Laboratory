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

            void voidWall();
    };
}

#endif