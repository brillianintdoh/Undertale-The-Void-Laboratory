#ifndef ENV_H
#define ENV_H
#include "mainNode/mainNode.h"
#include<godot_cpp/classes/canvas_layer.hpp>
#include<godot_cpp/classes/audio_stream_player.hpp>
using namespace godot;
extern MainNode* sys;
extern CanvasLayer* global;
extern CanvasLayer* scene_changer;
extern AudioStreamPlayer* music;
extern int isEditor;
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
enum Bullet {
	MOVEMENT_VELOCITY,
	MOVEMENT_TWEEN
};
enum AttackMack {
	ABSOLUTE_CLIP,
	ABSOLUTE,
	RELATIVE_BOX_CLIP,
	RELATIVE_BOX,
};

#endif