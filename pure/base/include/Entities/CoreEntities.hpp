/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base CoreEntities
*/

#pragma once

#include "Entities/AEntity.hpp"

namespace ECS
{
    namespace Entities
    {
        class EntityPtr : public AEntity
        {
        public:
            EntityPtr(Components::Component<uint8_t> *status, Components::Component2<uint64_t> *cPos, Components::Component<uint8_t> *poolId);
            ~EntityPtr();
            uint8_t getPoolId() const;
        protected:
            const Components::Component<uint8_t> *_poolId;
        };
    }
}
