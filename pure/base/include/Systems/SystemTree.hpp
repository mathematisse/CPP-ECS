/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base SystemTree
*/

#pragma once

#include "Systems/ISystem.hpp"
#include <list>

namespace ECS
{
    namespace Systems
    {
        enum PureSystemGroups {
            NONESYSGROUP = 0,
            ROOTSYSGROUP = 1,
            SYNCSYSGROUP = 2,
        };

        class SystemTreeNode
        {
        public:
            SystemTreeNode(int group, std::list<ISystem *> startSystems = std::list<ISystem *>(), std::list<ISystem *> endSystems = std::list<ISystem *>(), std::list<SystemTreeNode> children = std::list<SystemTreeNode>());
            ~SystemTreeNode() = default;
            bool addSystemGroup(int group, int neighbourGroup, bool addBefore, bool addInside);
            bool addSystem(ISystem *system, int group, bool atStart);
            void runNode();
            int getGroup();
        private:
            int _group;

            std::list<ISystem *> _startSystems;
            std::list<SystemTreeNode> _children;
            std::list<ISystem *> _endSystems;
        };


        class SystemTree
        {
        public:
            SystemTree();
            ~SystemTree();
            bool addSystemGroup(int group, int neighbourGroup, bool addBefore, bool addInside);
            bool addSystem(ISystem *system, int group, bool atStart);
            void runTree();
        private:
            SystemTreeNode _root;
        };
    }
}