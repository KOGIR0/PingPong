#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "Sprite.h"
#include "Text.h"
#include "PingPong.h"

#define SCREEN_HEIGHT 500
#define SCREEN_WIDTH 500

int main() {
    PingPong game({ SCREEN_WIDTH, SCREEN_HEIGHT });
    
    while (game.IsRunning())
    {
        game.ProcessEvents();
        game.UpdateWindow();
    }
	return 0;
}