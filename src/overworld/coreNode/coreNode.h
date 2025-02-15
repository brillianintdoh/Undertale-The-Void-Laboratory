#ifndef CoreNode_H
#define CoreNode_H
#include<godot_cpp/classes/node2d.hpp>
#include<godot_cpp/classes/camera2d.hpp>
namespace godot {
    class CoreNode : public Node2D {
        GDCLASS(CoreNode, Node2D);

        protected:
            static void _bind_methods();
        
        private:
            Camera2D* camera;

        public:
            CoreNode();
            ~CoreNode();

            void init();
            void initEvent();

            void voidWall();
            void event1();
            void event2();
            void text_trigger1();
    };
}

#endif