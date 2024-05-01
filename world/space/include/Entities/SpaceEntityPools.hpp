/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs world space CoreEntityPools
*/

#pragma once

#include "Entities/WorldEntityPools.hpp"
#include "Components/SpaceComponentPools.hpp"

namespace World
{
    namespace Objects
    {


        class ALocalizedEntityPool3D : virtual public ILocalizedEntityPool
        {
        public:
            ALocalizedEntityPool3D(const std::string &name);
            ~ALocalizedEntityPool3D();
            IPositionPool *getPositionPool() override;
        protected:
            PositionPool3D _positionPool;
        };

        class AStaticEntityPool3D : public ALocalizedEntityPool3D, public IStaticEntityPool
        {
        public:
            AStaticEntityPool3D(const std::string &name);
            ~AStaticEntityPool3D();
        protected:
        };

        class ADynamicEntityPool3D : public ALocalizedEntityPool3D, public IDynamicEntityPool
        {
        public:
            ADynamicEntityPool3D(const std::string &names);
            ~ADynamicEntityPool3D();
            IVelocityPool *getVelocityPool() override;
            IAccelerationPool *getAccelerationPool() override;
        protected:
            VelocityPool3D _velocityPool;
            AccelerationPool3D _accelerationPool;
        };
    }
}
