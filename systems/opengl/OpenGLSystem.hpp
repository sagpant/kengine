#pragma once

#include "EntityCreator.hpp"

namespace kengine {

	// These are the textures used by the "default" shaders
	// If you want to use additional textures, you can either copy this struct or inherit from it,
	// so long as you are careful to declare the reflectible attributes in the same order
	// (as that order will define their GLSL locations)
	struct GBufferTextures {
		// This format is not optimized, as the entity id could fit in with the normal
		// However, this has not caused any performance issues so far, and this being a learning project
		// for me I'd rather keep things clear and simple.
		// If this is a no-no for you, please open an issue on github and I'll change things around

		float position[4]; // x, y, z, depth
		float normal[4]; // x, y, z, ignore
		float color[4]; // r, g, b, shouldIgnoreLighting
		float entityID[4]; // id, ignore, ignore, ignore

		putils_reflection_attributes(
			putils_reflection_attribute(&GBufferTextures::position),
			putils_reflection_attribute(&GBufferTextures::normal),
			putils_reflection_attribute(&GBufferTextures::color),
			putils_reflection_attribute(&GBufferTextures::entityID)
		);
	};

	class EntityManager;

	EntityCreator * OpenGLSystem(EntityManager & em);
}
