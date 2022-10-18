
#pragma once
#include "Creator.h"

 class CCircleCreator : public CCreator
{
 public:
	std::shared_ptr<CShapeDecorator> createShape(std::istream& /*args*/, CCanvas& /*canvas*/) const override;
};
