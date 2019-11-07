#pragma once

#include "putils/opengl/Program.hpp"
#include "components/ShaderComponent.hpp"

namespace kengine {
	class EntityManager;
	struct PointLightComponent;
}

namespace kengine {
	class AssImpShadowCube : public ShadowCubeShader {
	public:
		AssImpShadowCube(kengine::EntityManager & em)
			: ShadowCubeShader(false, pmeta_nameof(AssImpShadowCube)),
			_em(em)
		{}

		void init(size_t firstTextureID, size_t screenWidth, size_t screenHeight, GLuint gBufferFBO) override;
		void run(kengine::Entity & e, PointLightComponent & light, const putils::Point3f & pos, float radius, const Parameters & params) override;
		void run(const Parameters & params) override {}

	private:
		kengine::EntityManager & _em;

	public:
		putils::gl::Uniform<glm::mat4> _proj;
		putils::gl::Uniform<glm::mat4> _view;
		putils::gl::Uniform<glm::mat4> _model;

		putils::gl::Uniform<glm::vec3> _lightPos;
		putils::gl::Uniform<float> _farPlane;

		GLint _bones;

		pmeta_get_attributes(
			pmeta_reflectible_attribute_private(&AssImpShadowCube::_proj),
			pmeta_reflectible_attribute_private(&AssImpShadowCube::_view),
			pmeta_reflectible_attribute_private(&AssImpShadowCube::_model),

			pmeta_reflectible_attribute_private(&AssImpShadowCube::_lightPos),
			pmeta_reflectible_attribute_private(&AssImpShadowCube::_farPlane),

			pmeta_reflectible_attribute_private(&AssImpShadowCube::_bones)
		);

	};
}