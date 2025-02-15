#include "coreNode.h"
#include "../../env.h"
#include<godot_cpp/classes/character_body2d.hpp>
#include<godot_cpp/classes/reference_rect.hpp>

CoreNode::CoreNode() {}

CoreNode::~CoreNode() {}

void CoreNode::_bind_methods() {
    ClassDB::bind_method(D_METHOD("init"), &CoreNode::init);
    ClassDB::bind_method(D_METHOD("voidWall"), &CoreNode::voidWall);
    ClassDB::bind_method(D_METHOD("event1"), &CoreNode::event1);
    ClassDB::bind_method(D_METHOD("text_trigger1"), &CoreNode::text_trigger1);
}

void CoreNode::init() {
    String name = get_name();
    if(name == "core_9") {
        int event1 = sys->flags()["event1"];
        if(!event1) return;
        Node* text_trigger = get_node_internal("trigger/text_trigger");
        text_trigger->disconnect("dialogue_finished", Callable(this, "text_trigger1"));
        text_trigger->set("text", Array::make(
            String::utf8("* ( 화면은 더 이상 켜지지 않는다 )")
        ));
    }else if(name == "core_1") {
        int main1 = sys->flags()["main1"];
        ReferenceRect* room_lab = Object::cast_to<ReferenceRect>(get_node_internal("trigger/room_lab"));
        if(main1) {
            get_node_internal("trigger/voidwall")->queue_free();
            room_lab->set_position(Vector2(259, 322));
            return;
        }

        global->set("player_move", false);
        CharacterBody2D* sans = Object::cast_to<CharacterBody2D>(get_node_internal("sans"));
        call("summontextbox").call("generic", sys->dia().call("from",
            Array::make(
                String::utf8("* ...."),
                String::utf8("* ( 당신은 코어 구조부터 모든게 이상하다는것을 느낀다.. )")
            )
        ));
        sys->sequence([this]() { return !global->get("player_text_box"); },
        {[this, sans]() {
            global->set("player_text_box", true);
            sans->set_position(Vector2(321, 356));
            sans->call("start_walking", Vector2i(0, -1));
            sys->sleep([this]() { global->set("player_text_box", false); }, 1.3);
        },
        [this, sans]() {
            global->set("player_text_box", true);
            Vector2 player_pos = global->get("player_position");
            Vector2 sans_pos = sans->get_position();
            Vector2 diff = player_pos - sans_pos;
            Vector2i direction;
            
            if (abs(diff.x) > abs(diff.y)) {
                direction = Vector2i(diff.x > 0 ? 1 : -1, 0);
            } else {
                direction = Vector2i(0, diff.y > 0 ? 1 : -1);
            }  
            
            sans->call("start_walking", direction);
            sans->call("start_walking");
            sys->sleep([this]() { global->set("player_text_box", false); }, 1);
        },
        [this]() {
            call("summontextbox").call("character", TextBox::SANS, sys->dia().call("from",
                Array::make(
                    String::utf8("* 꼬마 여기 있었네.."),
                    String::utf8("* ..."),
                    String::utf8("* 날 찾고 있었다고?"),
                    String::utf8("* 흠...."),
                    String::utf8("* 뭐 어쩔수 없나.."),
                    String::utf8("* 너도 느꼈을거야 코어 주변이.. 아니 지하세계가 이상해지고 있는걸"),
                    String::utf8("* 미안해 내가 '그'를 불러 버렸어"),
                    String::utf8("* 일단 날 따라와 탈출할 방법을 찾아야겠어")
                )
            ).call("set_expressions", Array::make(6, 0, 4, 2, 3, 2, 9, 0)));
        },
        [this, sans]() {
            global->set("player_text_box", true);
            sans->call("start_walking", Vector2i(0, 1));
            sys->sleep([this, sans]() {
                sans->set_position(Vector2(321, 398));
                global->set("player_text_box", false);
            }, 1.3);
        },
        [this, room_lab]() {
            global->set("player_move", true);
            call("summontextbox").call("generic", sys->dia().call("from",
                Array::make(
                    String::utf8("* ...."),
                    String::utf8("* 무언가.. 느낌이 안 좋다..")
                )
            ));
            get_node_internal("trigger/voidwall")->queue_free();
            room_lab->set_position(Vector2(259, 322));
            sys->set_flag("main1", true);
        }});
    }
}

void CoreNode::voidWall() {
    int is = sys->flags()["is"];
    if(is) {
        call("summontextbox").call("generic", sys->dia().call("from", 
            Array::make(
                String::utf8("* 안보이는 벽이 있는거 같다.."),
                String::utf8("* ( 다른 길을 찾아야 할거 같다.. )")
            )
        ));
    }else {
        call("summontextbox").call("generic", sys->dia().call("from", 
            Array::make(
                String::utf8("* !?"), String::utf8("* 앞으로 갈수가 없다..?"),
                String::utf8("* 무언가 앞에 안보이는 벽이있는거 같다..?"),
                String::utf8("* ( 다른 길을 찾아야 할거 같다... )")
            )
        ));
        sys->set_flag("is", 1);
    }
    global->set("player_can_move", true);
}

void CoreNode::event1() {
    int is = sys->flags()["is"];
    if(is) {
        call("summontextbox").call("generic", sys->dia().call("from",
            Array::make(
                String::utf8("* 여기도 막혀있다..."), String::utf8("* 샌즈를 찾으면 탈출할수 있을지도.."),
                String::utf8("* 샌즈를 찾아야겠다")
            )
        ));
    }else {
        call("summontextbox").call("generic", sys->dia().call("from",
            Array::make(
                String::utf8("* !?"), String::utf8("* 앞으로 갈수가 없다..?"),
                String::utf8("* 무언가 앞에 안보이는 벽이있는거 같다..?"),
                String::utf8("* 샌즈를 찾아야겠다")
            )
        ));
        sys->set_flag("is", 1);
    }
    global->set("player_can_move", true);
}

void CoreNode::text_trigger1() {
    call("summontextbox").call("character", TextBox::GASTER, sys->dia().call("from",
        Array::make(
            String::utf8("WHEN TIME AND SPACE BECOME ONE..."),
            String::utf8("ALL SUFFERING WILL CEASE TO EXIST...")
        )
    ));
    sys->sequence([this]() { return !global->get("player_text_box"); },
    {[this]() {
        call("summontextbox").call("generic", sys->dia().call("from",
            Array::make(
                String::utf8("* ?"),
                String::utf8("* 이해 할수 없는 문양이다..")
            )
        ));

        Node* text_trigger = get_node_internal("trigger/text_trigger");
        text_trigger->disconnect("dialogue_finished", Callable(this, "text_trigger1"));
        text_trigger->set("text", Array::make(
            String::utf8("* ( 아까 문자는 뭐였을까..? )")
        ));
        sys->set_flag("event1", true);
    }});
}