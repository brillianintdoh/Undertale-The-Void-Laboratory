#include "laboratoryNode.h"
#include "../../env.h"
#include<godot_cpp/classes/character_body2d.hpp>

LaboratoryNode::LaboratoryNode() {}

LaboratoryNode::~LaboratoryNode() {}

void LaboratoryNode::_bind_methods() {
    ClassDB::bind_method(D_METHOD("init"), &LaboratoryNode::init);
}

void LaboratoryNode::init() {
    if(isEditor) return;
    camera = Object::cast_to<Camera2D>(global->get("scene_container").get("Camera"));
    initEvent();
}

void LaboratoryNode::initEvent() {
    CharacterBody2D* sans = Object::cast_to<CharacterBody2D>(get_node_internal("sans"));
    CharacterBody2D* player = Object::cast_to<CharacterBody2D>(get_node_internal("player"));
    sans->call("start_walking", Vector2i(-1, 0));
    player->call("start_walking", Vector2i(-1, 0));
    camera->call("blind", 0.5, 0.6);
    sys->sleep([this, sans, player]() {
        sans->call("start_walking", Vector2i(0, 0));
        player->call("start_walking", Vector2i(0, 0));
        call("summontextbox").call("generic", sys->dia().call("from",
            Array::make(String::utf8("* (연구소는 평소와 다르게 음산하다...)"))
        ));
        sys->sequence([this]() { return !global->get("player_text_box"); },
        {[this]() {
            call("summontextbox").call("character", TextBox::SANS, sys->dia().call("from", 
                Array::make(String::utf8("* 여기까지 왔으니 이제 돌아가."))
            ).call("set_expressions", Array::make(4)));
        },
        [this, sans]() {
            sans->call("start_walking", Vector2i(0, -1));
            sans->call("start_walking", Vector2i(0, 0));
            call("summontextbox").call("character", TextBox::SANS, sys->dia().call("from", 
                Array::make(
                    String::utf8("* 연구소 정문으로 나갈수 있어 이만 나가 줘"),
                    String::utf8("* 넌 이미 충분히 많은 걸 해왔잖아?"),
                    String::utf8("* 다른 타임라인에서 네가 한 일들..."),
                    String::utf8("* 얼마나 많은 괴물들을 죽였지?"),
                    String::utf8("* 얼마나 많은 타임라인을 망쳐놨지?"),
                    String::utf8("* 나는 기억하고 있어 너가 수많은 리셋으로 이르킨 일들..")
                )
            ).call("set_expressions", Array::make(4, 19, 20, 5, 15, 17)));
        },
        [this]() {
            global->set("player_text_box", true);
            sys->sleep([this]() {
                camera->call("Void", 0.5, 5.5, 0.002);
                call("summontextbox").call("character", TextBox::SANS, sys->dia().call("from", 
                    Array::make(
                        String::utf8("* ...제길")
                    )
                ).call("set_expressions", Array::make(18)));
            }, 3);
        },
        [this]() {
            global->set("player_text_box", true);
            sys->sleep([this]() {
                call("summontextbox").call("character", TextBox::SANS, sys->dia().call("from", 
                    Array::make(
                        String::utf8("* ...하지만 지금은."),
                        String::utf8("* 더 큰 문제가 생긴거 같네..")
                    )
                ).call("set_expressions", Array::make(4, 21)));
            }, 2);
        }});
    }, 1.5);
}