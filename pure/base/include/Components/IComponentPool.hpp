/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base IComponentPool
*/

#pragma once

#include "Components/IComponent.hpp"
#include "Chunks/ChunkPos.hpp"
#include <cstddef>
#include <string>

namespace ECS
{
    namespace Components
    {
        class IComponentPool
        {
        public:
            virtual ~IComponentPool() = default;
            virtual const std::string &getComponentName() const = 0;
            virtual IComponent *operator[](Chunks::ChunkPos cPos) = 0;
            virtual const IComponent *operator[](Chunks::ChunkPos cPos) const = 0;
            virtual size_t elemCount() const = 0;
        };
    }
}