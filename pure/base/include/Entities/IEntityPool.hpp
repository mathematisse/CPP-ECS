/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base IEntityPool
*/

#pragma once

#include "Entities/IEntity.hpp"
#include "Components/IComponentPool.hpp"
#include <list>
#include <vector>


namespace ECS
{
    namespace Entities
    {
        class IEntityPool
        {
        public:
            virtual ~IEntityPool() = default;
            virtual IEntity *operator[](Chunks::ChunkPos cPos) = 0;
            virtual std::list<Chunks::ChunkPos> &getFreePos() = 0;
            virtual uint64_t getTotalSize() = 0;
            virtual uint64_t getUsedSize() = 0;
            virtual std::vector<Components::IComponentPool *> getComponentPools() = 0;
        };
    }
}
