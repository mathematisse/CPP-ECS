/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base ChunkPool
*/

#pragma once


#include "Chunks/AChunkPool.hpp"
#include "Chunks/SimdChunks.hpp"

namespace ECS
{
    namespace Chunks
    {

        template <typename T1, typename T2>
        class SimdChunkPool : public AChunkPool<T1>
        {
        public:
            SimdChunkPool() : AChunkPool<T1>()
            {
            }
            ~SimdChunkPool() = default;
            void AddChunk(size_t elemCount)
            {
                this->_chunks.push_back(new SimdChunk<T1, T2>(elemCount));
            }
        };
    }
}
