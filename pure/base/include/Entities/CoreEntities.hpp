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
            EntityPtr(Components::Component<uint8_t> *poolId, Components::Component2<uint64_t> *cPos);
            ~EntityPtr();
            uint8_t GetPoolId() const;
        protected:
            const Components::Component<uint8_t> *_poolId;
        };
    }
}