/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base ChunkPool
*/

#pragma once


#include "Chunks/AChunkPool.hpp"
#include "Chunks/StandardChunk.hpp"

namespace ECS
{
    namespace Chunks
    {

        template <typename T>
        class StandardChunkPool : public AChunkPool<T>
        {
        public:
            StandardChunkPool() 
            {
            }
            ~StandardChunkPool() = default;
            void AddChunk(size_t elemCount)
            {
                this->_chunks.push_back(new StandardChunk<T>(elemCount));
            }
        };
    }
}
