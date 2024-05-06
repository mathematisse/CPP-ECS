/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base AEntityPool
*/

#include "Entities/AEntityPool.hpp"
#include "Chunks/ChunkPos.hpp"

namespace ECS
{
    namespace Entities
    {
        AEntityPool::AEntityPool(const std::string &entityName, size_t chunkSize)
            : _entityName(entityName), _chunkSize(chunkSize), _freePos(), _entityStatusPool(), _chunkPosPool()
        {
        }

        AEntityPool::~AEntityPool()
        {
        }

        const std::string &AEntityPool::getEntityName() const
        {
            return _entityName;
        }

        std::list<Chunks::ChunkPos> &AEntityPool::getFreePos()
        {
            return _freePos;
        }

        uint64_t AEntityPool::getTotalSize()
        {
            return _entityStatusPool.elemCount();
        }

        uint64_t AEntityPool::getUsedSize()
        {
            return _entityStatusPool.elemCount() - _freePos.size();
        }

        uint64_t AEntityPool::getChunkCount() const
        {
            return _entityStatusPool.chunkCount();
        }

        void AEntityPool::addChunk()
        {
            Chunks::ChunkPos cPos = {getChunkCount(), 0};
            for (auto &componentPool : getComponentPools()) {
                componentPool->addChunk(_chunkSize);
            }
            // adds all the free positions of the new chunk
            for (size_t i = 0; i < _chunkSize; i++) {
                _freePos.push_back(cPos);
                cPos.elemIndex++;
            }
        }
    }
}
