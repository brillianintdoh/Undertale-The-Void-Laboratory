#include "coreNode.h"
#include "../../env.h"

CoreNode::CoreNode() {}

CoreNode::~CoreNode() {}

void CoreNode::_bind_methods() {
    ClassDB::bind_method(D_METHOD("init"), &CoreNode::init);
    ClassDB::bind_method(D_METHOD("voidWall"), &CoreNode::voidWall);
    ClassDB::bind_method(D_METHOD("event1"), &CoreNode::event1);
    ClassDB::bind_method(D_METHOD("text_trigger1"), &CoreNode::text_trigger1);
}

void CoreNode::init() {
    int event1 = sys->flags()["event1"];
    String name = get("world_name");
    if(name == "core_9") {
        if(!event1) return;
        Node* text_trigger = get_node_internal("trigger/text_trigger");
        text_trigger->disconnect("dialogue_finished", Callable(this, "text_trigger1"));
        text_trigger->set("text", Array::make(
            String::utf8("* ( 화면은 더 이상 켜지지 않는다 )")
        ));
    }
}

void CoreNode::voidWall() {
    int is = sys->flags()["is"];
    if(is) {
        call("summontextbox").call("generic", sys->dia().call("from", 
            Array::make(
                String::utf8("* 여기도.. 안보이는 벽이 있는거 같다.."),
                String::utf8("* ( 또 다른 길을 찾아야 할거 같다.. )")
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
            String::utf8("I'M SORRY TO SANS, BUT I NEED TO LURE A HUMAN")
        )
    ));
    sys->loop([this](double delta) {
        if(!global->get("player_in_menu")) {
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
            return true;
        }else return false;
    });
}