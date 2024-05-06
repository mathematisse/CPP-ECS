/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base ISystem
*/

#pragma once

namespace ECS
{
    namespace Systems
    {
        class ISystem
        {
        public:
            virtual ~ISystem() = default;
            virtual void run() = 0;
        };
    }
}