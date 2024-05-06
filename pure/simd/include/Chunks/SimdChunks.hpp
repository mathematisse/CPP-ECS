/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure simd SimdChunk
*/

#pragma once

#include "Chunks/AChunk.hpp"
#include "Chunks/IChunk.hpp"
#include <cstdlib>
#include <immintrin.h>

namespace ECS
{
    namespace Chunks
    {

        template <typename T1, typename T2>
        class SimdChunk : public AChunk<T1>
        {
        public:
            SimdChunk(size_t elemCount)
                : AChunk<T1>(SIMDCHUNK, elemCount)
            {
                _simdData = aligned_alloc(sizeof(T2), elemCount * sizeof(T1));
                this->_data = reinterpret_cast<T1 *>(_simdData);
            }
            ~SimdChunk()
            {
                free(_simdData);
            }
            T2 *GetSimdData() { return _simdData; }

        private:
            T2 *_simdData;
        };

    }
}