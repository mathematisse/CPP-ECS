/*
** EPITECH PROJECT, 2024
** CPP-ECS
** File description:
** Ecs pure base Components
*/

#pragma once

#include "Components/IComponent.hpp"

namespace ECS
{
    namespace Components
    {
        template <typename T>
        class Component : public IComponent {
        public:
            Component(T *x) : _x(x), _dummyX(0) {}
            Component(T x) : _x(&_dummyX), _dummyX(x) {}
            virtual ~Component() = default;
            T *GetX() { return _x; }
            const T *GetX() const { return _x; }
            void SetX(T x) { *_x = x; }
        protected:
            T *_x;
            T _dummyX;
        };

        template <typename T>
        class Component2 : public Component<T> {
        public:
            Component2(T *x, T *y) : Component<T>(x), _y(y), _dummyY(0) {}
            Component2(T x, T y) : Component<T>(x), _y(&_dummyY), _dummyY(y) {}
            virtual ~Component2() = default;
            T *GetY() { return _y; }
            const T *GetY() const { return _y; }
            void SetY(T y) { *_y = y; }
        protected:
            T *_y;
            T _dummyY;
        };

        template <typename T>
        class Component3 : public Component2<T> {
        public:
            Component3(T *x, T *y, T *z) : Component2<T>(x, y), _z(z), _dummyZ(0) {}
            Component3(T x, T y, T z) : Component2<T>(x, y), _z(&_dummyZ), _dummyZ(z) {}
            virtual ~Component3() = default;
            T *GetZ() { return _z; }
            const T *GetZ() const { return _z; }
            void SetZ(T z) { *_z = z; }
        protected:
            T *_z;
            T _dummyZ;
        };

        template <typename T>
        class Component4 : public Component3<T> {
        public:
            Component4(T *x, T *y, T *z, T *w) : Component3<T>(x, y, z), _w(w), _dummyW(0) {}
            Component4(T x, T y, T z, T w) : Component3<T>(x, y, z), _w(&_dummyW), _dummyW(w) {}
            virtual ~Component4() = default;
            T *GetW() { return _w; }
            const T *GetW() const { return _w; }
            void SetW(T w) { *_w = w; }
        protected:
            T *_w;
            T _dummyW;
        };
    }
}