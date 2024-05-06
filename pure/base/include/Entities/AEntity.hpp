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
            AEntity(Components::Component<uint8_t> *status, Components::Component2<uint64_t> *cPos);
            ~AEntity();
            uint8_t getStatus() const override;
            Chunks::ChunkPos getChunkPos() const override;
            void setStatus(uint8_t status) override;
            void setChunkPos(Chunks::ChunkPos cPos) override;
        protected:
            Components::Component<uint8_t> *_status;
            Components::Component2<uint64_t> *_cPos;
        };
    }
}
