#include <string>
#include "Expression.h"

#include <iostream>

// Create a new Expression
Expression::Expression(){
}

// Dynamic memory is dealt with in derived class destructors
Expression::~Expression(){
}

// Virtual function
int Expression::evaluate() const {
	return this->evaluate();
}

// Virtual function
std::string Expression::print() const {
	return this->print();
}

// Virtual function
std::string Expression::type() const {
	return this->type();
}

// Initialise the expressions that make up this BinaryExpression
BinaryExpression::BinaryExpression(Expression* subexp1, Expression* subexp2){
	exp1 = subexp1;
	exp2 = subexp2;
}

// Free dynamically allocated memory
BinaryExpression::~BinaryExpression(){
	delete exp1;
	delete exp2;
}

// Initialise the expression of this UnaryExpression
UnaryExpression::UnaryExpression(Expression* subexp){
	exp = subexp;
}

// Free dynamically allocated memory
UnaryExpression::~UnaryExpression(){
	delete exp;
}

// Create a Number which is an integer n
Number::Number(int n){
	num = n;
}

// Same as default destructor
Number::~Number(){
}

// Override virtual function
int Number::evaluate() const {
	return this->num;
}

// Override virtual function
std::string Number::print() const {
	return std::to_string(this->num);
}

// Override virtual function
std::string Number::type() const{
	return "Number";
}

// Create a new Multiplication Expression
// The two expressions making up this expression are init in creation of Binary Expression
Multiply::Multiply(Expression* subexp1, Expression* subexp2):BinaryExpression(subexp1, subexp2){
}

// Freeing of dynamic memory is dealt with in ~BinaryExpression()
Multiply::~Multiply(){
}

// Override virtual function
int Multiply::evaluate() const{
	int result = (this->exp1->evaluate()) * (this->exp2->evaluate());
	return result;
}

std::string Multiply::print() const {
	return "(" + exp1->print() + "*" + exp2->print() + ")"; 
}

std::string Multiply::type() const{
	return "Multiply";
}

// Create a new Addition Expression
// The two expressions making up this expression are init in creation of Binary Expression
Add::Add(Expression* subexp1, Expression* subexp2):BinaryExpression(subexp1, subexp2){
}

// Freeing of dynamic memory is dealt with in ~BinaryExpression()
Add::~Add(){
}

// Override virtual function
int Add::evaluate() const {
	int result = (this->exp1->evaluate()) + (this->exp2->evaluate());
	return result;
}

// Override virtual function
std::string Add::print() const {
	return "(" + exp1->print() + "+" + exp2->print() + ")";
}

// Override virtual function
std::string Add::type() const {
	return "Add";
}

// Create a new Absolute Expression
// The expression is init in creation of Unary Expression
Abs::Abs(Expression* subexp):UnaryExpression(subexp){
}

// Freeing of dynamic memory is done in ~UnaryExpression()
Abs::~Abs(){
}

// Override virtual function
int Abs::evaluate() const {
	int result = abs(this->exp->evaluate()); 
	return result;
}

// Override virtual function
std::string Abs::print() const {
	return "Abs(" + exp->print() + ")";
}

// Override virtual function
std::string Abs::type() const {
	return "Abs";
}

// Create a new Square Expression
// The expression is init in creation of Unary Expression
Square::Square(Expression* subexp):UnaryExpression(subexp){
}

// Freeing of dynamic memory is done in ~UnaryExpression()
Square::~Square(){
}

// Override virtual function
int Square::evaluate() const {
	int result = (this->exp->evaluate()) * (this->exp->evaluate());
	return result;
}

// Override virtual function
std::string Square::print() const {
	return "Square(" + exp->print() + ")";
}

// Override virtual function
std::string Square::type() const {
	return "Square";
}

