/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure cuda CudaChunks
*/

#pragma once

#include "Chunks/AChunk.hpp"
#ifdef NVCC_EXISTS
    #include <cuda_runtime.h>
#endif

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
                #ifdef NVCC_EXISTS
                    cudaMalloc(&_cudaData, elemCount * sizeof(T));
                #endif
                this->_data = nullptr;
            }
            ~CudaChunk()
            {
                cudaFree(_cudaData);
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
            T *GetCudaData() { return _cudaData; }
        private:
            T *_cudaData;
        };

        template <typename T>
        class CudaLinkChunk : public AChunk<T>
        {
        public:
            CudaLinkChunk(size_t elemCount)
                : AChunk<T>(CUDALINKCHUNK, elemCount)
            {
                #ifdef NVCC_EXISTS
                    cudaMallocHost(&this->_data, elemCount * sizeof(T));
                #endif
            }
            ~CudaLinkChunk()
            {
                #ifdef NVCC_EXISTS
                    cudaFreeHost(this->_data);
                #endif
            }
        };

    }
}