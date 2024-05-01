/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs world base WorldEntityPools
*/

#include "Entities/WorldEntityPools.hpp"

namespace World
{
    namespace Objects
    {
        AWorldChunkEntityPool::AWorldChunkEntityPool() : AEntityPool("worldChunk", 256), _headChunkPosPool()
        {
        }

        AWorldChunkEntityPool::~AWorldChunkEntityPool()
        {
        }

        EntityLocPool::EntityLocPool() : AEntityPool("entityLoc", 256), _chunkChunkPosPool(), _prevChunkPosPool(), _nextChunkPosPool()
        {
        }

        EntityLocPool::~EntityLocPool()
        {
        }

        ECS::Entities::IEntity *EntityLocPool::operator[](ECS::Chunks::ChunkPos cPos)
        {
            return nullptr;
        }

        std::vector<ECS::Components::IComponentPool *> EntityLocPool::getComponentPools()
        {
            return std::vector<ECS::Components::IComponentPool *>();
        }

        ILocalizedEntityPool::ILocalizedEntityPool(const std::string &name) : AEntityPool(name, 256)
        {
        }

        IStaticEntityPool::IStaticEntityPool(const std::string &name) : ILocalizedEntityPool(name)
        {
        }

        IDynamicEntityPool::IDynamicEntityPool(const std::string &name) : ILocalizedEntityPool(name)
        {
        }
    }
}