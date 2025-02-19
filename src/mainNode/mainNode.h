#ifndef MainNode_H
#define MainNode_H
#include<godot_cpp/classes/control.hpp>
#include<godot_cpp/classes/gd_script.hpp>
#include<functional>
using namespace std;
namespace godot {
    class MainNode : public Control {
        GDCLASS(MainNode, Control);

        protected:
            static void _bind_methods();

        private:
            Ref<GDScript> dialogues;
        
        public:
            MainNode();
            ~MainNode();

            void reset();
            void load_global();

            void ready();
            void _process(double delta) override;

            void system(double delta);
            void sleep(function<void()> fun, double cool);
            void loop(function<int(double delta)> fun);
            void sequence(function<int()> isFun, vector<function<void()>> funs);

            Variant dia();
            Dictionary flags();
            void set_flag(String name, Variant v);
    };
}

#endif