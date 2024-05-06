/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base StandardChunkPool
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
            StandardChunkPool() : AChunkPool<T>()
            {
            }
            ~StandardChunkPool() = default;
            void addChunk(size_t elemCount) override
            {
                this->_chunks.push_back(new StandardChunk<T>(elemCount));
            }
        };
    }
}
