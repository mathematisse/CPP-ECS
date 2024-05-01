/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs world space CoreEntityPools
*/

#include "Entities/SpaceEntityPools.hpp"

namespace World
{
    namespace Objects
    {
        ALocalizedEntityPool3D::ALocalizedEntityPool3D(const std::string &name) : ILocalizedEntityPool(name), _positionPool()
        {
        }

        ALocalizedEntityPool3D::~ALocalizedEntityPool3D()
        {
        }

        IPositionPool *ALocalizedEntityPool3D::getPositionPool()
        {
            return &_positionPool;
        }

        AStaticEntityPool3D::AStaticEntityPool3D(const std::string &name) : ALocalizedEntityPool3D(name), IStaticEntityPool(name)
        {
        }

        ADynamicEntityPool3D::ADynamicEntityPool3D(const std::string &name) : ALocalizedEntityPool3D(name), IDynamicEntityPool(name), _velocityPool(), _accelerationPool()
        {
        }

        IVelocityPool *ADynamicEntityPool3D::getVelocityPool()
        {
            return &_velocityPool;
        }

        IAccelerationPool *ADynamicEntityPool3D::getAccelerationPool()
        {
            return &_accelerationPool;
        }
    }
}
