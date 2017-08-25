#include <iostream>
#include <DefaultFactory.hpp>
#include <EntityManager.hpp>
#include <putils/go_to_bin_dir.hpp>
#include <common/systems/LuaSystem.hpp>

int main(int ac, char* av[])
{
    putils::goToBinDir(av[0]);

    DefaultFactory factory;
    kengine::EntityManager    em(std::move(std::make_unique<DefaultFactory>(factory)));

    // Loads sfml that has been build from cmake (PUTILS_BUILD_PSE)
    em.loadSystems<kengine::LuaSystem>(".");
    auto& go  = em.createEntity("Hellow", "First");

    em.registerTypes<
        kengine::LuaSystem,
        kengine::TransformComponent3d,
        putils::Point3d,
        putils::Rect3d
    >();

    std::cout << go << std::endl;

    while (em.running)
        em.execute();

    return 0;
}
