/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base CoreComponentPools
*/

#pragma once

#include "Components/AComponentPools.hpp"

namespace ECS
{
    namespace Components
    {
        // Identifies the entity pool in the core manager
        class EntityPoolIdPool : public Components::AComponentPool<uint8_t>
        {
        public:
            EntityPoolIdPool();
            ~EntityPoolIdPool() = default;
        };
        // Serves multiple purposes, in entity ptrs or for known pool entities references
        class ChunkPosPool : public Components::AComponentPool2<uint64_t>
        {
        public:
            ChunkPosPool();
            ~ChunkPosPool() = default;
        };
        // Attached to all entities (appart from entity ptrs) to tell the manager what to do
        class EntityStatusPool : public AComponentPool<int8_t>
        {
        public:
            EntityStatusPool();
            ~EntityStatusPool() = default;
        };
        enum EntityStatus {
            ENT_NONE = 0,
            ENT_NEEDS_INIT = 1,
            ENT_NEEDS_DESTROY = 2,
            ENT_ALIVE = 3,
        };
    }
}
