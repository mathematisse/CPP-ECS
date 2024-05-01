/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs world base WorldComponentPools
*/

#pragma once

#include "Components/IComponentPool.hpp"

namespace World
{
    namespace Objects
    {
        // Represent a location
        class IPositionPool : virtual public ECS::Components::IComponentPool
        {
        public:
        };
        // Represent a velocity vector
        class IVelocityPool : virtual public ECS::Components::IComponentPool
        {
        public:
        };
        // Represent an Acceleration vector
        class IAccelerationPool : virtual public ECS::Components::IComponentPool
        {
        public:
        };
    }
}