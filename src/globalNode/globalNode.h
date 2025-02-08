#ifndef Global_H
#define Global_H
#include<godot_cpp/classes/canvas_layer.hpp>
namespace godot {
    class GlobalNode : public CanvasLayer {
        GDCLASS(GlobalNode, CanvasLayer);

        protected:
            static void _bind_methods();
        
        public:
            GlobalNode();
            ~GlobalNode();

            void _ready() override;
            void _process(double delta) override;
    };
}

#endif