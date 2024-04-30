/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure cuda CudaChunkPool
*/

#pragma once


#include "Chunks/AChunkPool.hpp"
#include "Chunks/CudaChunks.hpp"

namespace ECS
{
    namespace Chunks
    {

        template <typename T>
        class CudaChunkPool : public AChunkPool<T>
        {
        public:
            CudaChunkPool() : AChunkPool<T>()
            {
            }
            ~CudaChunkPool() = default;
            void AddChunk(size_t elemCount) override
            {
                this->_chunks.push_back(new CudaChunk<T>(elemCount));
            }
        };

        template <typename T>
        class CudaLinkChunkPool : public AChunkPool<T>
        {
        public:
            CudaLinkChunkPool() : AChunkPool<T>()
            {
            }
            ~CudaLinkChunkPool() = default;
            void AddChunk(size_t elemCount) override
            {
                this->_chunks.push_back(new CudaLinkChunk<T>(elemCount));
            }
        };
    }
}
