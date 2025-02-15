#ifndef LaboratoryNode_H
#define LaboratoryNode_H
#include<godot_cpp/classes/node2d.hpp>
#include<godot_cpp/classes/camera2d.hpp>
namespace godot {
    class LaboratoryNode : public Node2D {
        GDCLASS(LaboratoryNode, Node2D);
        
        protected:
            static void _bind_methods();

        private:
            Camera2D* camera;

        public:
            LaboratoryNode();
            ~LaboratoryNode();

            void init();
    };
}

#endif