/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base AEntity
*/

#include "Entities/AEntity.hpp"

namespace ECS
{
    namespace Entities
    {
        AEntity::AEntity(Components::Component<uint8_t> *status, Components::Component2<uint64_t> *cPos)
            : _status(status), _cPos(cPos)
        {
        }

        AEntity::~AEntity()
        {
            
        }

        uint8_t AEntity::getStatus() const
        {
            return *_status->GetX();
        }

        Chunks::ChunkPos AEntity::getChunkPos() const
        {
            return {*_cPos->GetX(), *_cPos->GetY()};
        }

        void AEntity::setStatus(uint8_t status)
        {
            *_status->GetX() = status;
        }

        void AEntity::setChunkPos(Chunks::ChunkPos cPos)
        {
            *_cPos->GetX() = cPos.chunkIndex;
            *_cPos->GetY() = cPos.elemIndex;
        }
    }
}
