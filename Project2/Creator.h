#pragma once
#include "Canvas.h"
#include "ShapeDecorator.h"

 class CCreator
{
 public:
	virtual std::shared_ptr<CShapeDecorator> createShape(std::istream& /*args*/, CCanvas& /*canvas*/) const {};
};
