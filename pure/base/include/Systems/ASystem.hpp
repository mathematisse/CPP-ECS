/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base ASystem
*/

#pragma once

#include "Components/IComponentPool.hpp"
#include "Entities/IEntityPool.hpp"
#include <vector>
#include <string>

namespace ECS
{
    namespace Systems
    {

        class ASystem
        {
        public:
            ASystem(const std::vector<std::string> &matches, bool matchesPools, bool isParallel);
            ~ASystem();
            const std::vector<std::string> &getMatches() const;
            bool getMatchesPools() const;
            bool getIsParallel() const;
            void addEntityPool(Entities::IEntityPool *entityPool);
            void addComponentPools(std::vector<Components::IComponentPool *> componentPools);
        protected:
            const std::vector<std::string> &_matches;
            const bool _matchesPools;
            const bool _isParallel;

            std::list<Entities::IEntityPool *> _entityPools;
            std::list<std::vector<Components::IComponentPool *>> _componentPools;
        };
    }
}