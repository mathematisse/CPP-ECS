/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs world plane CoreEntityPools
*/

#include "Entities/PlaneEntityPools.hpp"

namespace World
{
    namespace Objects
    {
        ALocalizedEntityPool2D::ALocalizedEntityPool2D(const std::string &name) : ILocalizedEntityPool(name), _positionPool()
        {
        }

        ALocalizedEntityPool2D::~ALocalizedEntityPool2D()
        {
        }

        IPositionPool *ALocalizedEntityPool2D::getPositionPool()
        {
            return &_positionPool;
        }

        AStaticEntityPool2D::AStaticEntityPool2D(const std::string &name) : ALocalizedEntityPool2D(name), IStaticEntityPool(name)
        {
        }

        ADynamicEntityPool2D::ADynamicEntityPool2D(const std::string &name) : ALocalizedEntityPool2D(name), IDynamicEntityPool(name), _velocityPool(), _accelerationPool()
        {
        }

        IVelocityPool *ADynamicEntityPool2D::getVelocityPool()
        {
            return &_velocityPool;
        }

        IAccelerationPool *ADynamicEntityPool2D::getAccelerationPool()
        {
            return &_accelerationPool;
        }
    }
}