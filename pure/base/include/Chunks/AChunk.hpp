/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base AChunk
*/

#pragma once

#include "Chunks/IChunk.hpp"

namespace ECS
{
    namespace Chunks
    {
        template <typename T>
        class AChunk : public IChunk<T>
        {
        public:
            AChunk(ChunkType type, size_t elemCount) : _type(type), _elemCount{elemCount} {}
            ~AChunk() = default;
            T *operator[](size_t index) override
            {
                return _data + index;
            }
            const T *operator[](size_t index) const override
            {
                return _data + index;
            }
            size_t ElemCount() const override { return _elemCount; }
            T *GetData() override { return _data; }
            ChunkType GetType() const override { return _type; }

        protected:
            const ChunkType _type;
            const size_t _elemCount;
            T *_data;
        };

    }
}