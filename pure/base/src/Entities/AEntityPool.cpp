/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base AEntityPool
*/

#include "Entities/AEntityPool.hpp"

namespace ECS
{
    namespace Entities
    {
        AEntityPool::AEntityPool()
            : _freePos(), _entityStatusPool(), _chunkPosPool()
        {
        }

        AEntityPool::~AEntityPool()
        {
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
    }
}
