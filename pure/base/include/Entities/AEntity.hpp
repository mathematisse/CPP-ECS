/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base AEntity
*/

#pragma once

#include "Components/Components.hpp"
#include "Entities/IEntity.hpp"
#include <cstdint>

namespace ECS
{
    namespace Entities
    {
        class AEntity : public IEntity
        {
        public:
            AEntity(Components::Component2<uint64_t> *cPos);
            ~AEntity();
            Chunks::ChunkPos GetCPos() const override;
        protected:
            Components::Component2<uint64_t> *_cPos;
        };
    }
}