/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base CoreEntityPools
*/

#include "Entities/CoreEntityPools.hpp"
#include "Entities/CoreEntities.hpp"

namespace ECS
{
    namespace Entities
    {

        EntityPtrPool::EntityPtrPool()
            : AEntityPool("entityPtr", 256), _entityPoolIdPool()
        {
        }

        EntityPtrPool::~EntityPtrPool()
        {
        }

        IEntity *EntityPtrPool::operator[](Chunks::ChunkPos cPos)
        {
            return new EntityPtr(
                (Components::Component<uint8_t> *)_entityStatusPool[cPos],
                (Components::Component2<uint64_t> *)_chunkPosPool[cPos],
                (Components::Component<uint8_t> *)_entityPoolIdPool[cPos]);
        }

        std::vector<Components::IComponentPool *> EntityPtrPool::getComponentPools()
        {
            return {&_entityStatusPool, &_chunkPosPool, &_entityPoolIdPool};
        }
    }
}
