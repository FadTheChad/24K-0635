#include <iostream>

using namespace std;

class GraphicsEngine
{
public:
    void render()
    {
        cout << "Rendering graphics..." << endl;
    }
};

class InputHandler
{
public:
    void handleInput()
    {
        cout << "Handling input..." << endl;
    }
};

class PhysicsEngine
{
public:
    void updatePhysics()
    {
        cout << "Updating physics..." << endl;
    }
};

class GameEngine
{
private:
    GraphicsEngine graphics;
    InputHandler input;
    PhysicsEngine physics;

public:
    void start()
    {
        graphics.render();
        input.handleInput();
        physics.updatePhysics();
    }
};

int main()
{
    GameEngine engine;
    engine.start();
    return 0;
}
