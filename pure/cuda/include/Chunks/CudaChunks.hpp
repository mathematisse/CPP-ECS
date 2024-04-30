/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure cuda CudaChunks
*/

#pragma once

#include "Chunks/AChunk.hpp"
#include <cuda_runtime.h>

namespace ECS
{
    namespace Chunks
    {
        template <typename T>
        class CudaChunk : public AChunk<T>
        {
        public:
            CudaChunk(size_t elemCount)
                : AChunk<T>(CUDACHUNK, elemCount)
            {
                cudaMalloc(&_CudaData, elemCount * sizeof(T));
                this->_data = nullptr;
            }
            ~CudaChunk()
            {
                cudaFree(_CudaData);
            }
            T *operator[](size_t index) override
            {
                return nullptr;
            }
            const T *operator[](size_t index) const override
            {
                return nullptr;
            }
            T *GetData() override { return nullptr; }
            T *GetCudaData() { return _CudaData; }
        private:
            T *_CudaData;
        };

        template <typename T>
        class CudaLinkChunk : public AChunk<T>
        {
        public:
            CudaLinkChunk(size_t elemCount)
                : AChunk<T>(CUDALINKCHUNK, elemCount)
            {
                cudaMallocHost(&this->_data, elemCount * sizeof(T));
            }
            ~CudaLinkChunk()
            {
                cudaFreeHost(this->_data);
            }
        };

    }
}