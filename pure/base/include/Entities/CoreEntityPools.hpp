/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base IEntity
*/

#pragma once

#include "Components/CoreComponentPools.hpp"
#include "Entities/AEntityPool.hpp"

namespace ECS
{
    namespace Entities
    {
        class EntityPtrPool : public AEntityPool
        {
        public:
            EntityPtrPool();
            ~EntityPtrPool();
            IEntity *operator[](Chunks::ChunkPos cPos) override;
            std::vector<Components::IComponentPool *> getComponentPools() override;
        protected:
            Components::EntityPoolIdPool _entityPoolIdPool;
        };
    }
}
