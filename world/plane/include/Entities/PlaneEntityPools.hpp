/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs world plane PlaneEntityPools
*/

#pragma once

#include "Entities/WorldEntityPools.hpp"
#include "Components/PlaneComponentPools.hpp"

namespace World
{
    namespace Objects
    {


        class ALocalizedEntityPool2D : virtual public ILocalizedEntityPool
        {
        public:
            ALocalizedEntityPool2D(const std::string &name);
            ~ALocalizedEntityPool2D();
            IPositionPool *getPositionPool() override;
        protected:
            PositionPool2D _positionPool;
        };

        class AStaticEntityPool2D : public ALocalizedEntityPool2D, public IStaticEntityPool
        {
        public:
            AStaticEntityPool2D(const std::string &name);
            ~AStaticEntityPool2D();
        protected:
        };

        class ADynamicEntityPool2D : public ALocalizedEntityPool2D, public IDynamicEntityPool
        {
        public:
            ADynamicEntityPool2D(const std::string &names);
            ~ADynamicEntityPool2D();
            IVelocityPool *getVelocityPool() override;
            IAccelerationPool *getAccelerationPool() override;
        protected:
            VelocityPool2D _velocityPool;
            AccelerationPool2D _accelerationPool;
        };
    }
}
