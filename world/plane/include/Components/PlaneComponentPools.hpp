/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs world plane PlaneComponentPools
*/

#pragma once

#include "Components/WorldComponentPools.hpp"
#include "Components/AComponentPools.hpp"

namespace World
{
    namespace Objects
    {
        // Represent a location
        class PositionPool2D : public ECS::Components::AComponentPool2<float>, public IPositionPool
        {
        public:
            PositionPool2D();
            ~PositionPool2D() = default;
        };
        // Represent a velocity vector
        class VelocityPool2D : public ECS::Components::AComponentPool2<float>, public IVelocityPool
        {
        public:
            VelocityPool2D();
            ~VelocityPool2D() = default;
        };
        // Represent an Acceleration vector
        class AccelerationPool2D : public ECS::Components::AComponentPool2<float>, public IAccelerationPool
        {
        public:
            AccelerationPool2D();
            ~AccelerationPool2D() = default;
        };
    }
}
