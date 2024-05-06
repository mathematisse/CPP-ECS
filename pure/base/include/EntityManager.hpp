/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base EntityManager
*/

#pragma once

#include "Entities/PureEntityPools.hpp"
#include "Entities/PureEntities.hpp"
#include "Entities/IEntity.hpp"
#include "Entities/IEntityPool.hpp"
#include "Systems/SystemTree.hpp"
#include <vector>

namespace ECS
{
    class EntityManager
    {
    public:
        EntityManager();
        ~EntityManager();

        bool registerSystemGroup(int group, int neighbourGroup, bool addBefore = false, bool addInside = false);
        bool registerSystem(Systems::ISystem &system, int group, bool atStart = false);
        bool registerEntityPool(Entities::IEntityPool *entityPool);
        Entities::IEntity *operator[](const Entities::EntityPtr &entityPtr);
        Entities::EntityPtr *createEntity(const std::string &entityName);
        std::vector<Entities::EntityPtr *> createEntities(const std::string &entityName, size_t count = 0);
        void destroyEntity(Entities::EntityPtr *entity);
        void destroyEntities(std::vector<Entities::EntityPtr *> entities);
        
    private:
        std::vector<Entities::EntityPtr *> _createEntities(Entities::IEntityPool *entityPool, size_t count);

        Entities::EntityPtrPool _entityPtrPool;
        std::vector<Entities::IEntityPool *> _entityPools;
        Systems::SystemTree _systemTree;
    };
}
