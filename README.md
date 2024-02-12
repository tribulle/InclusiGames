
# InclusiGames

This code was created as part of a school project at Centrale Lille.


![Logo](https://www.mondedesgrandesecoles.fr/wp-content/uploads/capture-38.jpg)


## Authors

- [@tribulle](https://www.github.com/tribulle)
- [@liuh335](https://www.github.com/liuh335)

# The code structure follows the State Patern paradigm

## Usage/Examples
##### Create a new mechanism with its states
##### Please note that each mechanism and state has its own class.
#### In "include" folder you can find the declarations
##### M.h declares the mechanism class
##### state_M.h declares the states of the mechanism
##### M_setup.h declares the mechanism PINs
#### In "lib" folder you can find the libraries installed and adapted for our project
##### This is due to the use of librairies off platform( framework arduino)
#### In "src" folder you can find the definitions
##### Same logic for state_M.cpp and M_setup.cpp
```c++
#include "mecanisms/camera/camera.h"
#include "mecanisms/camera/camera_setup.h"
#include "mecanisms/camera/state_camera.h"

#include "mecanisms/stockage/stockage.h"
#include "mecanisms/stockage/stockage_setup.h"
#include "mecanisms/stockage/state_stockage.h"

    Stockage* stockage_mecanism = new Stockage(nullptr, "Stockage");
    Draw_state_stockage* stockage_state_draw = new Draw_state_stockage(nullptr,nullptr);
    Play_state_stockage* stockage_state_play = new Play_state_stockage(nullptr,nullptr);

    CameraMecanism* camera_mecanism = new CameraMecanism(nullptr, "Camera");
    Basic_state_camera* camera_state = new Basic_state_camera(nullptr,nullptr);
```
##### Run the usual Arduino Setup{} for a specific mechanism (in this case, the camera)
```c++
    camera_mecanism->Setup();
```
##### Run the usual Arduino Loop{} for a specific mechanism (in this case, the camera)
```c++
    camera_mecanism->LaunchMecanism();
```
##### Changes the state of the context (Mechanism) (here the camera)
Automatically launched with LaunchMecanism()
```c++
    camera_mecanism->TransitionTo(camera_state);
```
##### Declares state transitions after a mechanism has been launched
```c++
    chariot_state_push->Change_next_state_to(chariot_state_reset);
    chariot_state_reset->Change_next_state_to(chariot_state_push);
```
##### Launches mechanisms in sequence (Thread)
```c++
    threadlist_Play = new ThreadList();
    threadlist_Play->LaunchThread(chariot_mecanism);
```
##### Declares mechanism sequences after a mechanism has been launched (only if thread is used)
```c++
Mecanism* pusher_state_placement_helping_NEXTMEC[2] = {chariot_mecanism, permutation_mecanism};
pusher_state_placement_helping->Change_next_mecanism_to(pusher_state_placement_helping_NEXTMEC, 2);
```
