#ifndef MainNode_H
#define MainNode_H
#include<godot_cpp/classes/control.hpp>
namespace godot {
    class MainNode : public Control {
        GDCLASS(MainNode, Control);

        protected:
            static void _bind_methods();
        
        public:
            MainNode();
            ~MainNode();

            void _ready() override;
            void _process(double delta) override;
    };
}

#endif