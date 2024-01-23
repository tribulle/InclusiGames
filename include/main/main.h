#ifndef MAIN_H
#define MAIN_H
#include "base_class/state.h"
#include "synch_lib/thread.h"
#include "synch_lib/bluetooth.h"

#include "mecanisms/camera/camera.h"
#include "mecanisms/camera/state_camera.h"

#include "mecanisms/chariot/chariot.h"
#include "mecanisms/chariot/state_chariot.h"

#include "mecanisms/permutation/permutation.h"
#include "mecanisms/permutation/state_permutation.h"

#include "mecanisms/stock_pusher/pusher.h"
#include "mecanisms/stock_pusher/state_pusher.h"

#include "mecanisms/stockage/stockage.h"
#include "mecanisms/stockage/state_stockage.h"

#include "mecanisms/piston/piston.h"
#include "mecanisms/piston/state_piston.h"

#include<extender.h>


/*
extern Basic_state_camera* basic_state_camera;
extern Disabled_person_position_push* disabled_person_position_push;
extern Disabled_person_position_reset* disabled_person_position_reset;
extern Basic_state_permutation* basic_state_permutation;
extern State_distrib* state_distrib;
*/

#endif