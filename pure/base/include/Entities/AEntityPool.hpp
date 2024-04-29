/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base AEntityPool
*/

#pragma once

#include "Entities/IEntityPool.hpp"
#include "Components/CoreComponentPools.hpp"

namespace ECS
{
    namespace Entities
    {
        class AEntityPool : public IEntityPool
        {
        public:
            AEntityPool();
            ~AEntityPool();
            std::list<Chunks::ChunkPos> &getFreePos() override;
            uint64_t getTotalSize() override;
            uint64_t getUsedSize() override;
        protected:
            std::list<Chunks::ChunkPos> _freePos;
            Components::EntityStatusPool _entityStatusPool;
            Components::ChunkPosPool _chunkPosPool;
        };
    }
}