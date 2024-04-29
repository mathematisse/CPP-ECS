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
        AEntity::AEntity(Components::Component2<uint64_t> *cPos)
            : _cPos(cPos)
        {
        }

        AEntity::~AEntity()
        {
            delete _cPos;
        }

        Chunks::ChunkPos AEntity::GetCPos() const
        {
            return {*_cPos->GetX(), *_cPos->GetY()};
        }
    }
}