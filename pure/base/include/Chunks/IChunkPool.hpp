/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base ChunkPool
*/

#pragma once

#include "Chunks/IChunk.hpp"
#include "Chunks/ChunkPos.hpp"
#include <cstdint>

namespace ECS
{
    namespace Chunks
    {
        template <typename T>
        class IChunkPool
        {
        public:
            virtual ~IChunkPool() = default;
            virtual IChunk<T> *operator[](size_t index) = 0;
            virtual T *operator[](ChunkPos pos) = 0;
            virtual const IChunk<T> *operator[](size_t index) const = 0;
            virtual const T *operator[](ChunkPos pos) const = 0;
            virtual void addChunk(size_t elemCount) = 0;
            virtual uint64_t elemCount() const = 0;
            virtual uint64_t chunkCount() const = 0;
        };
    }
}
