/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base StandardChunks
*/

#pragma once

#include "Chunks/AChunk.hpp"

namespace ECS
{
    namespace Chunks
    {
        template <typename T>
        class StandardChunk : public AChunk<T>
        {
        public:
            StandardChunk(size_t elemCount)
                : AChunk<T>(STDCHUNK, elemCount)
            {
                this->_data = new T[elemCount];
            }
            ~StandardChunk()
            {
                delete this->_data;
            }
        };
    }
}