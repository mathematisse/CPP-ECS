/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs world base WorldEntityPools
*/

#pragma once

#include "Components/PureComponentPools.hpp"
#include "Entities/AEntityPool.hpp"
#include "Components/WorldComponentPools.hpp"

namespace World
{
    namespace Objects
    {
        class AWorldChunkEntityPool : public ECS::Entities::AEntityPool
        {
        public:
            AWorldChunkEntityPool();
            ~AWorldChunkEntityPool();
        protected:
            ECS::Components::ChunkPosPool _headChunkPosPool; // the chunk list head
        };

        class EntityLocPool : public ECS::Entities::AEntityPool
        {
        public:
            EntityLocPool();
            ~EntityLocPool();
            ECS::Entities::IEntity *operator[](ECS::Chunks::ChunkPos cPos) override;
            std::vector<ECS::Components::IComponentPool *> getComponentPools() override;
        protected:
            ECS::Components::ChunkPosPool _chunkChunkPosPool; // The WorldChunk Chunk Pos
            ECS::Components::ChunkPosPool _prevChunkPosPool; // Previous Entity 
            ECS::Components::ChunkPosPool _nextChunkPosPool;
        };

        class ILocalizedEntityPool : virtual public ECS::Entities::AEntityPool
        {
        public:
            ILocalizedEntityPool(const std::string &name);
            virtual IPositionPool *getPositionPool() = 0;
        };

        class IStaticEntityPool : virtual public ILocalizedEntityPool
        {
        public:
            IStaticEntityPool(const std::string &name);
        };

        class IDynamicEntityPool : virtual public ILocalizedEntityPool
        {
        public:
            IDynamicEntityPool(const std::string &name);
            virtual IVelocityPool *getVelocityPool() = 0;
            virtual IAccelerationPool *getAccelerationPool() = 0;
        };
    }
}
