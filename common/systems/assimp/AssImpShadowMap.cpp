#include "AssImpShadowMap.hpp"
#include "EntityManager.hpp"

#include "components/SkeletonComponent.hpp"
#include "components/ModelComponent.hpp"
#include "components/OpenGLModelComponent.hpp"

#include "helpers/LightHelper.hpp"
#include "common/systems/opengl/ShaderHelper.hpp"

#include "AssImpShaderSrc.hpp"
#include "AssImpHelper.hpp"

namespace kengine {
	void AssImpShadowMap::init(size_t firstTextureID) {
		initWithShaders<AssImpShadowMap>(putils::make_vector(
			ShaderDescription{ src::TexturedShader::vert, GL_VERTEX_SHADER }
		));

		_proj = glm::mat4(1.f);
	}

	void AssImpShadowMap::drawToTexture(GLuint texture, const glm::mat4 & lightSpaceMatrix) {
		_view = lightSpaceMatrix;

		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, texture, 0);

		AssImpHelper::Uniforms uniforms;
		uniforms.model = _model;
		uniforms.bones = _bones;

		for (const auto & [e, textured, graphics, transform, skeleton] : _em.getEntities<AssImpObjectComponent, GraphicsComponent, kengine::TransformComponent3f, SkeletonComponent>())
			AssImpHelper::drawModel(_em, graphics, transform, skeleton, false, uniforms);
	}
}
