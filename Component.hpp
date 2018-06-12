#pragma once

#include <string>
#include "IComponent.hpp"

namespace kengine {
    template<typename CRTP, typename ...DataPackets>
    class Component : public IComponent {
    public:
        pmeta::type_index getType() const noexcept final { return pmeta::type<CRTP>::index; }
    };
}
