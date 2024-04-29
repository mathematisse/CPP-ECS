/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base AComponentPool
*/

#pragma once

#include "Chunks/StandardChunkPool.hpp"
#include "Components/IComponentPool.hpp"
#include "Components/Components.hpp"

namespace ECS
{
    namespace Components
    {
        template <typename T>
        class AComponentPool : public IComponentPool
        {
        public:
            AComponentPool(const std::string &componentName) : _x(), _componentName(componentName) {}
            ~AComponentPool() = default;
            IComponent *operator[](Chunks::ChunkPos cPos) override
            {
                return new Components::Component<T>(this->_x[cPos]);
            }
            const IComponent *operator[](Chunks::ChunkPos cPos) const override
            {
                return new Components::Component<T>(*this->_x[cPos]);
            }
            uint64_t elemCount() const override { return this->_x.elemCount(); }
            const std::string &getComponentName() const override { return this->_componentName; }

        protected:
            Chunks::StandardChunkPool<T> _x;
            const std::string _componentName;
        };

        template <typename T>
        class AComponentPool2 : public AComponentPool<T>
        {
        public:
            AComponentPool2(const std::string &componentName) : AComponentPool<T>(componentName), _y() {}
            ~AComponentPool2() = default;
            IComponent *operator[](Chunks::ChunkPos cPos) override
            {
                return new Components::Component2<T>(this->_x[cPos], this->_y[cPos]);
            }
            const IComponent *operator[](Chunks::ChunkPos cPos) const override
            {
                return new Components::Component2<T>(*this->_x[cPos], *this->_y[cPos]);
            }

        protected:
            Chunks::StandardChunkPool<T> _y;
        };

        template <typename T>
        class AComponentPool3 : public AComponentPool2<T>
        {
        public:
            AComponentPool3(const std::string &componentName) : AComponentPool2<T>(componentName), _z() {}
            ~AComponentPool3() = default;
            IComponent *operator[](Chunks::ChunkPos cPos) override
            {
                return new Components::Component3<T>(this->_x[cPos], this->_y[cPos], this->_z[cPos]);
            }
            const IComponent *operator[](Chunks::ChunkPos cPos) const override
            {
                return new Components::Component3<T>(*this->_x[cPos], *this->_y[cPos], *this->_z[cPos]);
            }

        protected:
            Chunks::StandardChunkPool<T> _z;
        };

        template <typename T>
        class AComponentPool4 : public AComponentPool3<T>
        {
        public:
            AComponentPool4(const std::string &componentName) : AComponentPool3<T>(componentName), _w() {}
            ~AComponentPool4() = default;
            IComponent *operator[](Chunks::ChunkPos cPos) override
            {
                return new Components::Component4<T>(this->_x[cPos], this->_y[cPos], this->_z[cPos], _w[cPos]);
            }
            const IComponent *operator[](Chunks::ChunkPos cPos) const override
            {
                return new Components::Component4<T>(*this->_x[cPos], *this->_y[cPos], *this->_z[cPos], *_w[cPos]);
            }

        protected:
            Chunks::StandardChunkPool<T> _w;
        };
    }
}