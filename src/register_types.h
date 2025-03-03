#ifndef RegisterTYPE_H
#define RegisterTYPE_H
#include<godot_cpp/core/class_db.hpp>
#include "mainNode/mainNode.h"
#include "mainAttacks/mainAttacks.h"
#include "overworld/coreNode/coreNode.h"
#include "overworld/laboratoryNode/laboratoryNode.h"
#include "enemy/sans_1/enemy_sans1.h"
using namespace godot;

void register_types_init(ModuleInitializationLevel p_level);
void register_types_tem(ModuleInitializationLevel p_level);

#endif