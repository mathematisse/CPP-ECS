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
        class EntityPoolIdPool : public Components::AComponentPool<int8_t>
        {
        public:
            EntityPoolIdPool();
            ~EntityPoolIdPool() = default;
        };
        // Serves multiple purposes, in entity ptrs or for known pool entities references
        class ChunkPosPool : public Components::AComponentPool2<int64_t>
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
    }
}