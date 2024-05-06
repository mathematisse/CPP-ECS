/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs world space CoreComponentPools
*/

#pragma once

#include "Components/WorldComponentPools.hpp"
#include "Components/AComponentPools.hpp"

namespace World
{
    namespace Objects
    {
        // Represent a location
        class PositionPool3D : public ECS::Components::AComponentPool3<float>, public IPositionPool
        {
        public:
            PositionPool3D();
            ~PositionPool3D() = default;
        };
        // Represent a velocity vector
        class VelocityPool3D : public ECS::Components::AComponentPool3<float>, public IVelocityPool
        {
        public:
            VelocityPool3D();
            ~VelocityPool3D() = default;
        };
        // Represent an Acceleration vector
        class AccelerationPool3D : public ECS::Components::AComponentPool3<float>, public IAccelerationPool
        {
        public:
            AccelerationPool3D();
            ~AccelerationPool3D() = default;
        };
    }
}
