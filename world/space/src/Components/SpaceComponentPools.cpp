/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs world space CoreComponentPools
*/

#include "Components/SpaceComponentPools.hpp"

namespace World
{
    namespace Objects
    {
        PositionPool3D::PositionPool3D() : AComponentPool3<float>("position3d")
        {
        }

        VelocityPool3D::VelocityPool3D() : AComponentPool3<float>("velocity3d")
        {
        }

        AccelerationPool3D::AccelerationPool3D() : AComponentPool3<float>("acceleration3d")
        {
        }
    }
}
