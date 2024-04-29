/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base IChunk
*/

#pragma once

#include <cstddef>
namespace ECS
{
    namespace Chunks
    {
        // bitmask enum
        enum ChunkType {
            NONECHUNK = 0,
            STDCHUNK = 1,
            SSECHUNKI = 2,
            SSECHUNK = 4,
            SSECHUNKD = 8,
            AVXCHUNKI = 16,
            AVXCHUNK = 32,
            AVXCHUNKD = 64,
            GPUCHUNK = 128,
            GPULINKCHUNK = 256,
            SIMDCHUNK = SSECHUNKI | SSECHUNK | SSECHUNKD | AVXCHUNKI | AVXCHUNK | AVXCHUNKD,
            ANYGPUCHUNK = GPUCHUNK | GPULINKCHUNK
        };

        template <typename T>
        class IChunk
        {
        public:
            virtual ~IChunk() = default;
            virtual T *operator[](size_t idx) = 0;
            virtual const T *operator[](size_t idx) const = 0;
            virtual size_t ElemCount() const = 0;
            virtual T* GetData() = 0;
            virtual ChunkType GetType() const = 0;
        };

    }
}
