/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base AComponentPool
*/

#pragma once

#include "Chunks/IChunkPool.hpp"
#include "Components/IComponentPool.hpp"
#include "Components/Components.hpp"
#include <cstddef>

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
                return new Components::Component<T>((*this->_x)[cPos]);
            }
            const IComponent *operator[](Chunks::ChunkPos cPos) const override
            {
                return new Components::Component<T>((*this->_x)[cPos]);
            }
            uint64_t elemCount() const override { return this->_x->elemCount(); }
            uint64_t chunkCount() const override { return this->_x->chunkCount(); }
            const std::string &getComponentName() const override { return this->_componentName; }
            void addChunk(size_t elemCount) override
            {
                this->_x->addChunk(elemCount);
            }

        protected:
            Chunks::IChunkPool<T> *_x;
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
                return new Components::Component2<T>((*this->_x)[cPos], (*this->_y)[cPos]);
            }
            const IComponent *operator[](Chunks::ChunkPos cPos) const override
            {
                return new Components::Component2<T>((*this->_x)[cPos], (*this->_y)[cPos]);
            }
            void addChunk(size_t elemCount) override
            {
                this->_x->addChunk(elemCount);
                this->_y->addChunk(elemCount);
            }

        protected:
            Chunks::IChunkPool<T> *_y;
        };

        template <typename T>
        class AComponentPool3 : public AComponentPool2<T>
        {
        public:
            AComponentPool3(const std::string &componentName) : AComponentPool2<T>(componentName), _z() {}
            ~AComponentPool3() = default;
            IComponent *operator[](Chunks::ChunkPos cPos) override
            {
                return new Components::Component3<T>((*this->_x)[cPos], (*this->_y)[cPos], (*this->_z)[cPos]);
            }
            const IComponent *operator[](Chunks::ChunkPos cPos) const override
            {
                return new Components::Component3<T>((*this->_x)[cPos], (*this->_y)[cPos], (*this->_z)[cPos]);
            }
            void addChunk(size_t elemCount) override
            {
                this->_x->addChunk(elemCount);
                this->_y.addChunk(elemCount);
                this->_z.addChunk(elemCount);
            }

        protected:
            Chunks::IChunkPool<T> *_z;
        };

        template <typename T>
        class AComponentPool4 : public AComponentPool3<T>
        {
        public:
            AComponentPool4(const std::string &componentName) : AComponentPool3<T>(componentName), _w() {}
            ~AComponentPool4() = default;
            IComponent *operator[](Chunks::ChunkPos cPos) override
            {
                return new Components::Component4<T>((*this->_x)[cPos], (*this->_y)[cPos], (*this->_z)[cPos], (*this->_w)[cPos]);
            }
            const IComponent *operator[](Chunks::ChunkPos cPos) const override
            {
                return new Components::Component4<T>((*this->_x)[cPos], (*this->_y)[cPos], (*this->_z)[cPos], (*this->_w)[cPos]);
            }
            void addChunk(size_t elemCount) override
            {
                this->_x->addChunk(elemCount);
                this->_y.addChunk(elemCount);
                this->_z.addChunk(elemCount);
                this->_w.addChunk(elemCount);
            }

        protected:
            Chunks::IChunkPool<T> *_w;
        };
    }
}
