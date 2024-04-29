/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base ChunkPool
*/

#pragma once

#include "Chunks/IChunk.hpp"
#include "Chunks/ChunkPos.hpp"
#include "Chunks/IChunkPool.hpp"
#include <vector>

namespace ECS
{
    namespace Chunks
    {

        template <typename T>
        class AChunkPool : public IChunkPool<T>
        {
        public:
            AChunkPool() : _chunks{}
            {
            }
            ~AChunkPool()
            {
                for (size_t i = 0; i < _chunks.size(); i++) {
                    delete _chunks[i];
                }
            }
            IChunk<T> *operator[](size_t index) override
            {
                return _chunks[index];
            }
            T *operator[](ChunkPos pos) override
            {
                return (*_chunks[pos.chunkIndex])[pos.elemIndex];
            }
            const IChunk<T> *operator[](size_t index) const override
            {
                return _chunks[index];
            }
            const T *operator[](ChunkPos pos) const override
            {
                return (*_chunks[pos.chunkIndex])[pos.elemIndex];
            }
            uint64_t elemCount() const override
            {
                uint64_t size = 0;
                for (size_t i = 0; i < _chunks.size(); i++) {
                    size += _chunks[i]->ElemCount();
                }
                return size;
            }

        protected:
            std::vector<IChunk<T> *> _chunks;
        };
    }
}
