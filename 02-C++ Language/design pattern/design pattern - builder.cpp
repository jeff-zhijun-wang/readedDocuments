/*
 * Example of `builder' design pattern.
 * Copyright (C) 2011 Radek Pazdera
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */


#include <iostream>
#include <string>

/* Car parts */
class Wheel
{
    public:
        int size;
};

class Engine
{
    public:
        int horsepower;
};

class Body
{
    public:
        std::string shape;
};

/* Final product -- a car */
class Car
{
    public:
        Wheel*   wheels[4];
        Engine*  engine;
        Body* body;
    
        void specifications()
        {
            std::cout << "body:" << body->shape << std::endl;
            std::cout << "engine horsepower:" << engine->horsepower << std::endl;
            std::cout << "tire size:" << wheels[0]->size << "'" << std::endl;
        }
};

/* Builder is responsible for constructing the smaller parts */
class BuilderLine
{
    public:
        virtual Wheel* AddWheel() = 0;
        virtual Engine* AddEngine() = 0;
        virtual Body* AddBody() = 0;
};


/* Concrete Builder for Jeep SUV cars */
class JeepBuilderLine : public BuilderLine
{
    public:
        Wheel* AddWheel()
        {
            Wheel* wheel = new Wheel();
            wheel->size = 22;
            return wheel;
        }

        Engine* AddEngine()
        {
            Engine* engine = new Engine();
            engine->horsepower = 400;
            return engine;
        }

        Body* AddBody()
        {
            Body* body = new Body();
            body->shape = "SUV";
            return body;
        }
};

/* Concrete builder for Nissan family cars */
class NissanBuilderLine : public BuilderLine
{
    public:
        Wheel* AddWheel()
        {
            Wheel* wheel = new Wheel();
            wheel->size = 16;
            return wheel;
        }

        Engine* AddEngine()
        {
            Engine* engine = new Engine();
            engine->horsepower = 85;
            return engine;
        }

        Body* AddBody()
        {
            Body* body = new Body();
            body->shape = "hatchback";
            return body;
        }
};

/* Director is responsible for the whole process */
class Fabricator
{
    BuilderLine* builderLine;

    public:
        void setBuilderLine(BuilderLine* newBuilderLine)
        {
            builderLine = newBuilderLine;
        }

        Car* ProduceCar()
        {
            Car* car = new Car();

            car->body = builderLine->AddBody();

            car->engine = builderLine->AddEngine();

            car->wheels[0] = builderLine->AddWheel();
            car->wheels[1] = builderLine->AddWheel();
            car->wheels[2] = builderLine->AddWheel();
            car->wheels[3] = builderLine->AddWheel();

            return car;
        }
};


int main()
{
    Car* car; // Final product

    /* A director who controls the process */
    Fabricator fabricator;

    /* Concrete builders */
    JeepBuilderLine jeepBuilderLine;
    NissanBuilderLine nissanBuilderLine;

    /* Build a Jeep */
    std::cout << "Jeep" << std::endl;
    fabricator.setBuilderLine(&jeepBuilderLine); // using JeepBuilder instance
    car = fabricator.ProduceCar();
    car->specifications();

    std::cout << std::endl;

    /* Build a Nissan */
    std::cout << "Nissan" << std::endl;
    fabricator.setBuilderLine(&nissanBuilderLine); // using NissanBuilder instance
    car = fabricator.ProduceCar();
    car->specifications();

    return 0;
}