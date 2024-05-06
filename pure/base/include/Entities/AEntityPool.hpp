/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base AEntityPool
*/

#pragma once

#include "Entities/IEntityPool.hpp"
#include "Components/PureComponentPools.hpp"
#include <cstdint>

namespace ECS
{
    namespace Entities
    {
        class AEntityPool : public IEntityPool
        {
        public:
            AEntityPool(const std::string &entityName, size_t chunkSize);
            ~AEntityPool();
            const std::string &getEntityName() const override;
            std::list<Chunks::ChunkPos> &getFreePos() override;
            uint64_t getTotalSize() override;
            uint64_t getUsedSize() override;
            uint64_t getChunkCount() const override;
            void addChunk() override;
        protected:
            const std::string _entityName;
            const size_t _chunkSize;
    
            std::list<Chunks::ChunkPos> _freePos;
            Components::EntityStatusPool _entityStatusPool;
            Components::ChunkPosPool _chunkPosPool;
        };
    }
}
