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
            virtual uint8_t getStatus() const = 0;
            virtual Chunks::ChunkPos getChunkPos() const = 0;
            virtual void setStatus(uint8_t status) = 0;
            virtual void setChunkPos(Chunks::ChunkPos cPos) = 0;
        };
    }
}
