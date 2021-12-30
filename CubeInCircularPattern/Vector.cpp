#include <iostream>
#include "Vector.h"
#include "Point.h"

void Vector::setVectorCoefficients(float &value)
{
	this->vectorCoefficients.push_back(value);
}
void Vector::rotateVector(Vector &userVector, Vector &normalToUserVector, float angle)
{
	float radians = (float)(angle*3.141592) / 180;
	Vector instance;

	float magnitude = sqrt(userVector.vectorCoefficients[0] * userVector.vectorCoefficients[0]
		+ userVector.vectorCoefficients[1] * userVector.vectorCoefficients[1]
		+ userVector.vectorCoefficients[2] * userVector.vectorCoefficients[2]);
	//magnitude = sqrt(magnitude);

	instance = Vector::crossProduct(normalToUserVector,userVector);

	instance.vectorCoefficients[0] = instance.vectorCoefficients[0] / magnitude;
	instance.vectorCoefficients[1] = instance.vectorCoefficients[1] / magnitude;
	instance.vectorCoefficients[2] = instance.vectorCoefficients[2] / magnitude;

	this->vectorCoefficients.push_back(cos(radians)*normalToUserVector.vectorCoefficients[0] +
		                          sin(radians)*instance.vectorCoefficients[0]);
	this->vectorCoefficients.push_back(cos(radians)*normalToUserVector.vectorCoefficients[1] +
		sin(radians)*instance.vectorCoefficients[1]);
	this->vectorCoefficients.push_back(cos(radians)*normalToUserVector.vectorCoefficients[2] +
		sin(radians)*instance.vectorCoefficients[2]);
}
void Vector::findUnitVector()
{
	float magnitude = sqrt(vectorCoefficients[0] * vectorCoefficients[0]
		               + vectorCoefficients[1] * vectorCoefficients[1]
		+ vectorCoefficients[2]* vectorCoefficients[2]);
	this->vectorCoefficients.push_back(vectorCoefficients[0] / magnitude);
	this->vectorCoefficients.push_back(vectorCoefficients[1] / magnitude);
	this->vectorCoefficients.push_back(vectorCoefficients[2] / magnitude);
}
Vector Vector::crossProduct(Vector& one,Vector &two)
{
	Vector result;
	result.vectorCoefficients.push_back(one.vectorCoefficients[1] * two.vectorCoefficients[2]
		                           - (two.vectorCoefficients[1] * one.vectorCoefficients[2]));
	result.vectorCoefficients.push_back(-1*(one.vectorCoefficients[0] * two.vectorCoefficients[2]
		- (two.vectorCoefficients[0] * one.vectorCoefficients[2])));
	result.vectorCoefficients.push_back(one.vectorCoefficients[0] * two.vectorCoefficients[1]
		- (two.vectorCoefficients[0] * one.vectorCoefficients[1]));
	return result;
}

Vector Vector ::operator*(float & radius)
{
	Vector newVector;
	for (int i = 0; i < 3; i++)
	{
		newVector.vectorCoefficients.push_back(this->vectorCoefficients[i] * radius);
	}
	return newVector;
}

Point Vector::operator +(Point &anyCorner)
{
	Point newPoint;
	newPoint.setX(anyCorner.getX() + this->vectorCoefficients[0]);
	newPoint.setY(anyCorner.getY() + this->vectorCoefficients[1]);
	newPoint.setZ(anyCorner.getZ() + this->vectorCoefficients[2]);
	return newPoint;
}
