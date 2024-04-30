/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base SystemTree
*/

#include "Systems/SystemTree.hpp"
#include <iterator>

namespace ECS
{
    namespace Systems
    {
        SystemTreeNode::SystemTreeNode(int group, std::list<ISystem *> startSystems, std::list<ISystem *> endSystems, std::list<SystemTreeNode> children)
            : _group(group), _startSystems(startSystems), _children(children), _endSystems(endSystems)
        {
        }

        bool SystemTreeNode::addSystemGroup(int group, int neighbourGroup, bool addBefore, bool addInside)
        {
            if (group == _group && addInside) {
                if (addBefore) {
                    _children.push_front(SystemTreeNode(neighbourGroup));
                } else {
                    _children.push_back(SystemTreeNode(neighbourGroup));
                }
                return true;
            }
            for (auto it = _children.begin(); it != _children.end(); ++it) {
                auto &child = *it;
                if (child.getGroup() == group && !addInside) {
                    if (addBefore) {
                        _children.insert(it, SystemTreeNode(neighbourGroup));
                    } else {
                        _children.insert(std::next(it), SystemTreeNode(neighbourGroup));
                    }
                    return true;
                }
            }
            return false;
        }

        bool SystemTreeNode::addSystem(ISystem *system, int group, bool atStart)
        {
            if (group == _group) {
                if (atStart)
                    _startSystems.push_back(system);
                else
                    _endSystems.push_back(system);
                return true;
            }
            for (auto &child : _children) {
                if (child.addSystem(system, group, atStart))
                    return true;
            }
            return false;
        }

        void SystemTreeNode::runNode()
        {
            for (auto &startSystem : _startSystems) {
                startSystem->run();
            }
            for (auto &child : _children) {
                child.runNode();
            }
            for (auto &endSystem : _endSystems) {
                endSystem->run();
            }
        }

        SystemTree::SystemTree()
            : _root(ROOTSYSGROUP, std::list<ISystem *>(), std::list<ISystem *>(), std::list<SystemTreeNode>())
        {
        }

        bool SystemTree::addSystem(ISystem *system, int group, bool atStart)
        {
            return _root.addSystem(system, group, atStart);
        }

        void SystemTree::runTree()
        {
            _root.runNode();
        }
    }
}