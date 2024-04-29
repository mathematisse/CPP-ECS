/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base IEntity
*/

#pragma once

#include "Chunks/ChunkPos.hpp"

namespace ECS
{
    namespace Entities
    {
        class IEntity
        {
        public:
            virtual ~IEntity() = default;
            virtual Chunks::ChunkPos GetCPos() const = 0;
        };
    }
}
