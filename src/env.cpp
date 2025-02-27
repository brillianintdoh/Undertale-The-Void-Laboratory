#include "env.h"

MainNode* sys = nullptr;
CanvasLayer* global = nullptr;
CanvasLayer* scene_changer = nullptr;
Node* audio_player = nullptr;
AudioStreamPlayer* music = nullptr;
int isEditor = true;