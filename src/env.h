#ifndef ENV_H
#define ENV_H
#include "mainNode/mainNode.h"
#include<godot_cpp/classes/canvas_layer.hpp>
using namespace godot;
extern MainNode* sys;
extern CanvasLayer* global;
enum TextBox {
    DEFAULT,
    SANS,
    PAPYRUS,
    UNDYNE,
    UNDYNE_THE_UNDYING,
    ALPHYS,
    ASGORE,
    FLOWEY,
    FLOWEY_EVIL,
    GASTER,
    METTATON,
    TEMMIE,
    TORIEL,
};

#endif