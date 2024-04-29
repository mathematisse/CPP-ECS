/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base CoreEntities
*/

#include "Entities/CoreEntities.hpp"

namespace ECS
{
    namespace Entities
    {
        EntityPtr::EntityPtr(Components::Component<uint8_t> *poolId, Components::Component2<uint64_t> *cPos)
            : AEntity(cPos), _poolId(poolId)
        {
        }

        EntityPtr::~EntityPtr()
        {
            delete _poolId;
        }

        uint8_t EntityPtr::GetPoolId() const
        {
            return *_poolId->GetX();
        }
    }
}
