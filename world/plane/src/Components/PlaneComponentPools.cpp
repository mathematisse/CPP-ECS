/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs world plane PlaneComponentPools
*/

#include "Components/PlaneComponentPools.hpp"

namespace World
{
    namespace Objects
    {
        PositionPool2D::PositionPool2D() : AComponentPool2<float>("position2d")
        {
        }

        VelocityPool2D::VelocityPool2D() : AComponentPool2<float>("velocity2d")
        {
        }

        AccelerationPool2D::AccelerationPool2D() : AComponentPool2<float>("acceleration2d")
        {
        }
    }
}