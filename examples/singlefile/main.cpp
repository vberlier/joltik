#include <goomy.h>
#include <iostream>

class Settings;
class FooSystem;
class BarSystem;

using Engine = goomy::Engine<goomy::Mount<Settings, FooSystem, BarSystem>>;

enum class Difficulty { easy, hard };

class Settings {
  public:
    Difficulty difficulty = Difficulty::easy;
};

class FooSystem {
  public:
    void init();
    void update(Engine &engine);
};

class BarSystem {
  public:
    void postupdate(Engine &engine);
};

void FooSystem::init() {
    std::cout << "Init foo" << std::endl;
}

void FooSystem::update(Engine &engine) {
    if (engine.get<Settings>().difficulty == Difficulty::easy) {
        std::cout << "Do something easy" << std::endl;
    } else {
        std::cout << "Do something hard" << std::endl;
    }
}

void BarSystem::postupdate(Engine &engine) {
    std::cout << "Shutting down" << std::endl;
    engine.shutdown();
}

int main() {
    Engine().loop();
    return 0;
}