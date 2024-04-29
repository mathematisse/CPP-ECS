/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base CoreComponentPools
*/

#include "Components/CoreComponentPools.hpp"

namespace ECS
{
    namespace Components
    {
        EntityPoolIdPool::EntityPoolIdPool()
            : AComponentPool<int8_t>("entity_pool_id")
        {
        }

        ChunkPosPool::ChunkPosPool()
            : AComponentPool2<int64_t>("chunk_pos")
        {
        }

        EntityStatusPool::EntityStatusPool()
            : AComponentPool<int8_t>("entity_status")
        {
        }
    }
}