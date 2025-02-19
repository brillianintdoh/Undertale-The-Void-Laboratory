#include "mainNode.h"
#include "../env.h"
#include<godot_cpp/classes/engine.hpp>

MainNode::MainNode() {}

MainNode::~MainNode() {}

void MainNode::_bind_methods() {
    ClassDB::bind_method(D_METHOD("ready"), &MainNode::ready);
    ClassDB::bind_method(D_METHOD("load_global"), &MainNode::load_global);
    ClassDB::bind_method(D_METHOD("reset"), &MainNode::reset);
}

void MainNode::ready() {
    loader = ResourceLoader::get_singleton();
    isEditor = Engine::get_singleton()->is_editor_hint();
    dialogues = loader->load("res://Resources/Dialogues/dialogues.gd");
    sys = Object::cast_to<MainNode>(get_node_internal("."));
}

void MainNode::_process(double delta) {
    system(delta);
}

Variant MainNode::dia() {
    return dialogues->new_();
}

Dictionary MainNode::flags() {
    return global->get("flags");
}

void MainNode::set_flag(String name, Variant v) {
    global->call("set_flag", name, v);
    if(!global->get("first")) global->call("save_game", true);
}

void MainNode::load_battle(String path) {
    scene_changer->call("load_battle", scene_changer->get("DEFAULT_BATTLE"), loader->load(path));
}

void MainNode::load_global() {
    global = Object::cast_to<CanvasLayer>(get_node_internal("/root/Global"));
    scene_changer = Object::cast_to<CanvasLayer>(get_node_internal("/root/OverworldSceneChanger"));
    music = Object::cast_to<AudioStreamPlayer>(global->get("Music"));
}

void MainNode::reset() {
    global->call("resetgame");
	global->call("check_level_up");
    global->call_deferred("heal", global->get("player_max_hp"));
}