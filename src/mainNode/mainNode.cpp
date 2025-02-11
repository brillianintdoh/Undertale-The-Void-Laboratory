#include "mainNode.h"
#include "../env.h"
#include<godot_cpp/classes/engine.hpp>
#include<godot_cpp/classes/resource_loader.hpp>

MainNode::MainNode() {}

MainNode::~MainNode() {}

void MainNode::_bind_methods() {
    ClassDB::bind_method(D_METHOD("ready"), &MainNode::ready);
}

void MainNode::ready() {
    ResourceLoader* loader = ResourceLoader::get_singleton();
    dialogues = loader->load("res://Resources/Dialogues/dialogues.gd");
    m = Object::cast_to<MainNode>(get_node_internal("."));
    global = Object::cast_to<CanvasLayer>(get_node_internal("/root/Global"));
    cout << global->get_name().to_utf8_buffer().get_string_from_utf8().utf8().get_data() << endl;
}

void MainNode::_process(double delta) {
    system(delta);
}

Variant MainNode::dia() {
    return dialogues->new_();
}